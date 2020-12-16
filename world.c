#pragma once
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "config.c"
#include "particle.c"
#include "particleGrid.c"
#include "particleTypes.c"

#define PARTICLE_COUNT 500

typedef struct
{
    Config config;
    ParticleType particleTypes[PARTICLE_TYPE_COUNT];
    Particle particles[PARTICLE_COUNT];
    ParticleGrid particleGrid;
    float playerAngle;
} World;

#define MAX_PARTICLE_RADIUS 1

void worldInit(World *world, float scaleFactor, int width, int sidebarWidth, int height)
{
    configInit(&world->config, scaleFactor, width, sidebarWidth, height);

    initParticleTypes(world->particleTypes);
    float maxInteractionRadius = 0;
    for (int i = 0; i < PARTICLE_TYPE_COUNT; i++)
    {
        for (int j = 0; j < PARTICLE_TYPE_COUNT; j++)
        {
            float radius = world->particleTypes[i].radius[j] * MAX_PARTICLE_RADIUS;
            if (radius > maxInteractionRadius)
            {
                maxInteractionRadius = radius;
            }
        }
    }

    particleInit(world->particles, 0, width / 2, height / 2, 4);

    srand(time(0));
    for (int i = 1; i < PARTICLE_COUNT; i++)
    {
        int particleType = 1;
        float x = (float)(rand()) / RAND_MAX * width;
        float y = (float)(rand()) / RAND_MAX * height;
        float size = 1 + powf((float)(rand()) / RAND_MAX, 5) * (MAX_PARTICLE_RADIUS - 1);
        particleInit(world->particles + i, particleType, x, y, size);
    }

    particleGridInit(
        &world->particleGrid, width, height, ceilf(maxInteractionRadius), world->particles,
        PARTICLE_COUNT);

    world->playerAngle = PI / 2;
}

void worldMovePlayer(World *world, int throttleDelta, int angleDelta)
{
    world->playerAngle = fmodf(world->playerAngle + angleDelta * world->config.playerTurnAmount, PI * 2);
    float throttle = throttleDelta * world->config.playerThrottleAmount;
    world->particles[0].xv = cosf(world->playerAngle) * throttle;
    world->particles[0].yv = -sinf(world->playerAngle) * throttle;
}

void updateParticleInteractions(World *world, ParticleType *particleType, int particleIndex)
{
    Particle *particles = world->particles;
    Config *config = &world->config;
    Particle *particle = particles + particleIndex;

    float sumXf = 0;
    float sumYf = 0;
    int interactionCount = 0;

    int cellIndices[9];
    int cellCount = particleGridGetNeighborhoodIndices(&world->particleGrid, particle, cellIndices);
    for (int i = 0; i < cellCount; i++)
    {
        ParticleCell *particleCell = world->particleGrid.particleCells + cellIndices[i];
        for (int j = 0; j < particleCell->count; j++)
        {
            Particle *otherParticle = particleCell->particles[j];
            if (otherParticle == particle)
            {
                continue;
            }

            float deltaX = otherParticle->x - particle->x;
            float deltaY = otherParticle->y - particle->y;
            float distanceSquared = deltaX * deltaX + deltaY * deltaY;
            if (distanceSquared == 0)
            {
                printf("Warning: particles occupy exactly same spot\n");
                continue;
            }

            float repelDistance = config->baseRepelDistance * (particle->radius + otherParticle->radius);
            if (distanceSquared < repelDistance * repelDistance)
            {

                float distance = sqrtf(distanceSquared);
                float repelX = deltaX / distance;
                float repelY = deltaY / distance;
                float repelAmount = 1.0 - distance / repelDistance;
                particle->xv -= repelX * repelAmount;
                particle->yv -= repelY * repelAmount;
            }

            float interactionRadius = particleType->radius[otherParticle->type];
            if (distanceSquared < interactionRadius * interactionRadius)
            {
                float distance = sqrtf(distanceSquared);
                float interactionForce = particleType->force[otherParticle->type];
                sumXf += deltaX / distance * interactionForce;
                sumYf += deltaY / distance * interactionForce;
                interactionCount++;
            }
        }
    }

    int lastStepIndex = particleType->steps;
    if (interactionCount > 0)
    {
        particle->xa[lastStepIndex] = sumXf / interactionCount / particle->mass;
        particle->ya[lastStepIndex] = sumYf / interactionCount / particle->mass;
    }
    else
    {
        particle->xa[lastStepIndex] = 0;
        particle->ya[lastStepIndex] = 0;
    }
}

void updateWallCollisions(Particle *particle, Config *config)
{
    float wallOffset = config->baseParticleRadius * particle->radius;
    if (particle->x < wallOffset)
    {
        particle->x = wallOffset;
        if (particle->xv < 0)
        {
            particle->xv *= -1;
        }
    }
    else if (particle->x > config->width - wallOffset)
    {
        particle->x = config->width - wallOffset;
        if (particle->xv > 0)
        {
            particle->xv *= -1;
        }
    }

    if (particle->y < wallOffset)
    {
        particle->y = wallOffset;
        if (particle->yv < 0)
        {
            particle->yv *= -1;
        }
    }
    else if (particle->y > config->height - wallOffset)
    {
        particle->y = config->height - wallOffset;
        if (particle->yv > 0)
        {
            particle->yv *= -1;
        }
    }
}

int compareInts(const void *a, const void *b)
{
    return *(int *)(a) - *(int *)(b);
}

void worldUpdate(World *world, bool isPlayerAttractive)
{
    Particle *particles = world->particles;
    ParticleType *particleTypes = world->particleTypes;
    Config *config = &world->config;
    ParticleGrid *particleGrid = &world->particleGrid;    

    for (int i = 0; i < PARTICLE_COUNT; i++)
    {
        Particle *particle = particles + i;
        particle->xv *= (1.0 - config->friction);
        particle->yv *= (1.0 - config->friction);

        int oldCellIndex = particleGridFindCellIndex(particleGrid, particle);
        if (oldCellIndex != particle->cellIndex)
        {
            abortWithMessage("Did particle move???");
        }
        particle->x += particle->xv;
        particle->y += particle->yv;

        ParticleType *particleType = particleTypes + particle->type;
        updateParticleInteractions(world, particleType, i);
        for (int j = 0; j < particleType->steps; j++)
        {
            particle->xa[j] = particle->xa[j + 1];
            particle->ya[j] = particle->ya[j + 1];
        }
        particle->xv += particle->xa[0];
        particle->yv += particle->ya[0];
        updateWallCollisions(&particles[i], config);
        particleGridUpdateCell(particleGrid, particle, i, oldCellIndex);
    }

    int totalParticlesInCells = 0;
    int particlePositions[PARTICLE_COUNT];
    for (int i = 0; i < world->particleGrid.rowCount * world->particleGrid.columnCount; i++)
    {
        totalParticlesInCells += world->particleGrid.particleCells[i].count;
        for (int j = 0; j < world->particleGrid.particleCells[i].count; j++)
        {
            particlePositions[j] = world->particleGrid.particleCells[i].particles[j]->posWithinCell;
        }
        qsort(particlePositions, world->particleGrid.particleCells[i].count, sizeof(int), compareInts);
        for (int j = 0; j < world->particleGrid.particleCells[i].count - 1; j++)
        {
            if (particlePositions[j + 1] - particlePositions[j] != 1)
            {
                abortWithMessage("Particle positions inconsistent");
            }
        }
    }
    if (totalParticlesInCells != PARTICLE_COUNT)
    {
        abortWithMessage("Particle count inconsistent");
    }
}

void worldRender(World *world)
{
    float scaleFactor = world->config.scaleFactor;

    DrawRectangle(
        0, 0,
        world->config.width * scaleFactor,
        world->config.height * scaleFactor,
        world->config.backgroundColor);
    for (int i = 0; i < PARTICLE_COUNT; i++)
    {
        Particle *particle = world->particles + i;
        DrawCircle(
            particle->x * scaleFactor,
            particle->y * scaleFactor,
            particle->radius * world->config.baseParticleRadius * scaleFactor,
            world->particleTypes[particle->type].color);
    }
    
    DrawLineEx(
        (Vector2){
            (world->particles[0].x + cos(world->playerAngle) * 10) * scaleFactor,
            (world->particles[0].y - sin(world->playerAngle) * 10) * scaleFactor},
        (Vector2){
            (world->particles[0].x) * scaleFactor,
            (world->particles[0].y) * scaleFactor},
        2 * scaleFactor,
        WHITE);

    int cellWidth = world->config.sidebarWidth / PARTICLE_TYPE_COUNT * 2;
    int cellHeight = world->config.sidebarWidth / PARTICLE_TYPE_COUNT / 2;
    char stepsStr[2];
    int stepsFontSize = 10;
    int stepsOffset = 5;
    for (int i = 0; i < PARTICLE_TYPE_COUNT; i++)
    {
        int cellX = world->config.width + (i / 2) * cellWidth;
        int steps = world->particleTypes[i].steps;
        snprintf(stepsStr, 2, "%i", steps);
        for (int j = 0; j < PARTICLE_TYPE_COUNT; j++)
        {
            int cellY = (i % 2 * PARTICLE_TYPE_COUNT + j) * cellHeight;
            float interactionRadius = world->particleTypes[i].radius[j];
            float force = world->particleTypes[i].force[j] * 10;
            DrawCircle(
                (cellX + cellWidth / 2) * scaleFactor,
                (cellY + cellHeight / 2) * scaleFactor,
                world->config.baseParticleRadius * scaleFactor,
                world->particleTypes[i].color);
            DrawCircle(
                (cellX + cellWidth / 2 + interactionRadius) * scaleFactor,
                (cellY + cellHeight / 2) * scaleFactor,
                world->config.baseParticleRadius * scaleFactor,
                world->particleTypes[j].color);
            DrawLineEx(
                (Vector2){
                    (cellX + cellWidth / 2) * scaleFactor,
                    (cellY + cellHeight / 2) * scaleFactor},
                (Vector2){
                    (cellX + cellWidth / 2 + force) * scaleFactor,
                    (cellY + cellHeight / 2) * scaleFactor},
                scaleFactor,
                GRAY);
            DrawLineEx(
                (Vector2){
                    (cellX + cellWidth / 2 + force * 0.9) * scaleFactor,
                    (cellY + cellHeight / 2 - force * 0.05) * scaleFactor},
                (Vector2){
                    (cellX + cellWidth / 2 + force) * scaleFactor,
                    (cellY + cellHeight / 2) * scaleFactor},
                scaleFactor,
                GRAY);
            DrawLineEx(
                (Vector2){
                    (cellX + cellWidth / 2 + force * 0.9) * scaleFactor,
                    (cellY + cellHeight / 2 + force * 0.05) * scaleFactor},
                (Vector2){
                    (cellX + cellWidth / 2 + force) * scaleFactor,
                    (cellY + cellHeight / 2) * scaleFactor},
                scaleFactor,
                GRAY);
            DrawText(
                stepsStr,
                (cellX + cellWidth / 2 + force * 0.5 - stepsFontSize / 2) * scaleFactor,
                (cellY + cellHeight / 2 - stepsFontSize - stepsOffset) * scaleFactor,
                stepsFontSize * scaleFactor,
                GRAY);
        }
    }
}