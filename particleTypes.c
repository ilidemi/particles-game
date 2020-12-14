#pragma once
#include "raylib.h"

#define PARTICLE_TYPE_COUNT 12

typedef struct
{
    float force[PARTICLE_TYPE_COUNT];
    float radius[PARTICLE_TYPE_COUNT];
    float steps;
    Color color;
} ParticleType;

void initParticleTypes(ParticleType *particleTypes)
{
    particleTypes[0].color = (Color){200, 30, 30, 255};
    particleTypes[1].color = (Color){200, 150, 30, 255};
    particleTypes[2].color = (Color){200, 200, 30, 255};
    particleTypes[3].color = (Color){30, 190, 30, 255};
    particleTypes[4].color = (Color){70, 70, 210, 255};
    particleTypes[5].color = (Color){130, 40, 170, 255};
    particleTypes[6].color = (Color){110, 30, 30, 255};
    particleTypes[7].color = (Color){110, 80, 30, 255};
    particleTypes[8].color = (Color){120, 120, 50, 255};
    particleTypes[9].color = (Color){30, 100, 30, 255};
    particleTypes[10].color = (Color){30, 30, 160, 255};
    particleTypes[11].color = (Color){100, 30, 130, 255};

    particleTypes[0].force[0] = 1.301252300661762;
    particleTypes[0].radius[0] = 68.91413348891803;
    particleTypes[0].force[1] = -2.230152907846133;
    particleTypes[0].radius[1] = 19.281494768946192;
    particleTypes[0].force[2] = 0.025212746508003647;
    particleTypes[0].radius[2] = 50.20624742108828;
    particleTypes[0].force[3] = -3.600271341394796;
    particleTypes[0].radius[3] = 34.85721850355756;
    particleTypes[0].force[4] = -1.061633091334187;
    particleTypes[0].radius[4] = 14.04677509180996;
    particleTypes[0].force[5] = 2.2695255146242133;
    particleTypes[0].radius[5] = 14.637383485166543;
    particleTypes[0].force[6] = -0.5998725570640531;
    particleTypes[0].radius[6] = 39.7986966119487;
    particleTypes[0].force[7] = 2.7600834166481185;
    particleTypes[0].radius[7] = 57.476982699257505;
    particleTypes[0].force[8] = 3.9165354481056998;
    particleTypes[0].radius[8] = 45.9771871484167;
    particleTypes[0].force[9] = -3.731315996097976;
    particleTypes[0].radius[9] = 8.560944028117882;
    particleTypes[0].force[10] = 2.074666274923258;
    particleTypes[0].radius[10] = 24.232277191010564;
    particleTypes[0].force[11] = 1.0173633142136023;
    particleTypes[0].radius[11] = 48.25235879938472;
    particleTypes[0].steps = 0;
    particleTypes[1].force[0] = -0.878552550489685;
    particleTypes[1].radius[0] = 73.1395658125685;
    particleTypes[1].force[1] = 3.4426561966786657;
    particleTypes[1].radius[1] = 53.44378619860082;
    particleTypes[1].force[2] = 1.8347969868641716;
    particleTypes[1].radius[2] = 9.923088760356242;
    particleTypes[1].force[3] = -2.869507890058424;
    particleTypes[1].radius[3] = 71.45572896784721;
    particleTypes[1].force[4] = -3.4834539888722613;
    particleTypes[1].radius[4] = 54.691385476793464;
    particleTypes[1].force[5] = 3.3162109977108116;
    particleTypes[1].radius[5] = 59.767429038243705;
    particleTypes[1].force[6] = -3.3464992002107916;
    particleTypes[1].radius[6] = 33.11372959126176;
    particleTypes[1].force[7] = -0.3215693389859542;
    particleTypes[1].radius[7] = 10.038893532909533;
    particleTypes[1].force[8] = -0.41840903396395746;
    particleTypes[1].radius[8] = 21.7770068521151;
    particleTypes[1].force[9] = -2.039441505305959;
    particleTypes[1].radius[9] = 66.29471233318375;
    particleTypes[1].force[10] = -3.953137560526528;
    particleTypes[1].radius[10] = 63.99666358353694;
    particleTypes[1].force[11] = -0.8487458409824082;
    particleTypes[1].radius[11] = 44.142402696874775;
    particleTypes[1].steps = 3;
    particleTypes[2].force[0] = 2.7908707226164324;
    particleTypes[2].radius[0] = 15.006860119121885;
    particleTypes[2].force[1] = -2.302292926531038;
    particleTypes[2].radius[1] = 30.24471514095326;
    particleTypes[2].force[2] = 0.3003748691634218;
    particleTypes[2].radius[2] = 15.565204617111014;
    particleTypes[2].force[3] = 1.8138447445137942;
    particleTypes[2].radius[3] = 11.406602732102792;
    particleTypes[2].force[4] = 2.791729664710756;
    particleTypes[2].radius[4] = 14.30944425512956;
    particleTypes[2].force[5] = -3.6070134541564745;
    particleTypes[2].radius[5] = 30.037839738124323;
    particleTypes[2].force[6] = -2.266641735094261;
    particleTypes[2].radius[6] = 41.81347096013967;
    particleTypes[2].force[7] = -0.6991280942869658;
    particleTypes[2].radius[7] = 15.293417440430732;
    particleTypes[2].force[8] = -0.3042128156770456;
    particleTypes[2].radius[8] = 6.656558170421874;
    particleTypes[2].force[9] = -3.3558678366719903;
    particleTypes[2].radius[9] = 73.04306350850467;
    particleTypes[2].force[10] = -3.307835757445231;
    particleTypes[2].radius[10] = 24.125867234594402;
    particleTypes[2].force[11] = 1.8482586070142322;
    particleTypes[2].radius[11] = 12.446222888936877;
    particleTypes[2].steps = 1;
    particleTypes[3].force[0] = -1.8891097143695923;
    particleTypes[3].radius[0] = 31.83274218524956;
    particleTypes[3].force[1] = 3.261176823902879;
    particleTypes[3].radius[1] = 58.82597659710637;
    particleTypes[3].force[2] = 0.8057206751389643;
    particleTypes[3].radius[2] = 10.33016114551994;
    particleTypes[3].force[3] = -0.8682907675914784;
    particleTypes[3].radius[3] = 71.22823268411284;
    particleTypes[3].force[4] = 1.7173051510730062;
    particleTypes[3].radius[4] = 56.24430448075387;
    particleTypes[3].force[5] = 3.4909563757143296;
    particleTypes[3].radius[5] = 59.449049389308776;
    particleTypes[3].force[6] = -2.0293306233665973;
    particleTypes[3].radius[6] = 14.812189618807356;
    particleTypes[3].force[7] = -1.0078304146888453;
    particleTypes[3].radius[7] = 66.02389292925285;
    particleTypes[3].force[8] = -3.7531740814148886;
    particleTypes[3].radius[8] = 50.16542510939933;
    particleTypes[3].force[9] = 2.445249775696258;
    particleTypes[3].radius[9] = 20.436319859519344;
    particleTypes[3].force[10] = -3.343349605076938;
    particleTypes[3].radius[10] = 57.980543972121986;
    particleTypes[3].force[11] = -0.6482264100225787;
    particleTypes[3].radius[11] = 12.595172221111563;
    particleTypes[3].steps = 1;
    particleTypes[4].force[0] = 1.5247906685993087;
    particleTypes[4].radius[0] = 50.84299555372993;
    particleTypes[4].force[1] = 3.8324193942817217;
    particleTypes[4].radius[1] = 21.215726331693567;
    particleTypes[4].force[2] = 2.0960926860649227;
    particleTypes[4].radius[2] = 34.96692963551149;
    particleTypes[4].force[3] = 0.9891089739076921;
    particleTypes[4].radius[3] = 17.047756420354553;
    particleTypes[4].force[4] = -3.9807374985053947;
    particleTypes[4].radius[4] = 27.66793840739101;
    particleTypes[4].force[5] = -0.534576263593955;
    particleTypes[4].radius[5] = 50.330916124957135;
    particleTypes[4].force[6] = 2.0132157003199325;
    particleTypes[4].radius[6] = 68.12098983638967;
    particleTypes[4].force[7] = -3.689865926907501;
    particleTypes[4].radius[7] = 50.87508777579631;
    particleTypes[4].force[8] = -0.8523962616990737;
    particleTypes[4].radius[8] = 27.3777298130807;
    particleTypes[4].force[9] = 1.816515708536647;
    particleTypes[4].radius[9] = 65.54701826373172;
    particleTypes[4].force[10] = 0.03632035506255882;
    particleTypes[4].radius[10] = 46.24378529911964;
    particleTypes[4].force[11] = 3.7143076904334382;
    particleTypes[4].radius[11] = 19.206151550814663;
    particleTypes[4].steps = 2;
    particleTypes[5].force[0] = 3.7417528729970826;
    particleTypes[5].radius[0] = 18.085066621465696;
    particleTypes[5].force[1] = -3.882267125691259;
    particleTypes[5].radius[1] = 65.19133973357555;
    particleTypes[5].force[2] = -1.3366205540443268;
    particleTypes[5].radius[2] = 40.887140021918945;
    particleTypes[5].force[3] = -1.414634828987328;
    particleTypes[5].radius[3] = 15.693310048063701;
    particleTypes[5].force[4] = -3.7340456640909157;
    particleTypes[5].radius[4] = 39.1724475973607;
    particleTypes[5].force[5] = -2.1228845472275815;
    particleTypes[5].radius[5] = 29.28317398734494;
    particleTypes[5].force[6] = 1.4171645108196174;
    particleTypes[5].radius[6] = 43.547155378705995;
    particleTypes[5].force[7] = 1.4786718768546994;
    particleTypes[5].radius[7] = 14.257070666883868;
    particleTypes[5].force[8] = 2.2236719538502125;
    particleTypes[5].radius[8] = 21.715934427479596;
    particleTypes[5].force[9] = 3.2273831963086295;
    particleTypes[5].radius[9] = 33.662117235940826;
    particleTypes[5].force[10] = -2.1497283179778197;
    particleTypes[5].radius[10] = 55.50955865972704;
    particleTypes[5].force[11] = -2.176975451442974;
    particleTypes[5].radius[11] = 5.03230716568692;
    particleTypes[5].steps = 1;
    particleTypes[6].force[0] = -1.4962612968150513;
    particleTypes[6].radius[0] = 67.01409119109898;
    particleTypes[6].force[1] = 0.8314027602409304;
    particleTypes[6].radius[1] = 12.619103089469384;
    particleTypes[6].force[2] = -3.700335013635998;
    particleTypes[6].radius[2] = 48.198346564538454;
    particleTypes[6].force[3] = 3.0494201358091235;
    particleTypes[6].radius[3] = 14.968120263872137;
    particleTypes[6].force[4] = 0.8469212598098306;
    particleTypes[6].radius[4] = 70.47744659254101;
    particleTypes[6].force[5] = 1.8460392025046346;
    particleTypes[6].radius[5] = 72.76057432407893;
    particleTypes[6].force[6] = -2.9496249058035655;
    particleTypes[6].radius[6] = 69.67476166673089;
    particleTypes[6].force[7] = 1.166603371002779;
    particleTypes[6].radius[7] = 54.982843224775785;
    particleTypes[6].force[8] = -1.0737530820036163;
    particleTypes[6].radius[8] = 27.813970762827335;
    particleTypes[6].force[9] = 2.493034446581616;
    particleTypes[6].radius[9] = 25.280644989562386;
    particleTypes[6].force[10] = -2.7361943079695497;
    particleTypes[6].radius[10] = 4.806918605555558;
    particleTypes[6].force[11] = -0.47338255101352367;
    particleTypes[6].radius[11] = 39.03865562678257;
    particleTypes[6].steps = 3;
    particleTypes[7].force[0] = -3.6097174443282167;
    particleTypes[7].radius[0] = 15.515706747676012;
    particleTypes[7].force[1] = -2.079151526042054;
    particleTypes[7].radius[1] = 53.823367578827224;
    particleTypes[7].force[2] = -0.9688800146765129;
    particleTypes[7].radius[2] = 71.04928842085236;
    particleTypes[7].force[3] = 1.9432877464855718;
    particleTypes[7].radius[3] = 50.130661700389616;
    particleTypes[7].force[4] = -3.9596580575773057;
    particleTypes[7].radius[4] = 10.504576799202908;
    particleTypes[7].force[5] = 3.446095283963553;
    particleTypes[7].radius[5] = 39.86429439275851;
    particleTypes[7].force[6] = 0.7215452088733869;
    particleTypes[7].radius[6] = 10.845386814135477;
    particleTypes[7].force[7] = 1.34024507566226;
    particleTypes[7].radius[7] = 6.521026205380776;
    particleTypes[7].force[8] = 3.167896724392387;
    particleTypes[7].radius[8] = 10.675387382172172;
    particleTypes[7].force[9] = -3.7149247395354497;
    particleTypes[7].radius[9] = 52.52842748558024;
    particleTypes[7].force[10] = 1.337207780616108;
    particleTypes[7].radius[10] = 21.47134090835949;
    particleTypes[7].force[11] = -3.1284337488453247;
    particleTypes[7].radius[11] = 53.83813581818488;
    particleTypes[7].steps = 2;
    particleTypes[8].force[0] = -3.49877566761044;
    particleTypes[8].radius[0] = 22.3844721653881;
    particleTypes[8].force[1] = -0.7380530354176944;
    particleTypes[8].radius[1] = 22.89905177986136;
    particleTypes[8].force[2] = -3.7032591582510612;
    particleTypes[8].radius[2] = 6.613545419732471;
    particleTypes[8].force[3] = 1.8863546832098343;
    particleTypes[8].radius[3] = 17.97034326003615;
    particleTypes[8].force[4] = -1.4139065702788365;
    particleTypes[8].radius[4] = 65.35657881883068;
    particleTypes[8].force[5] = 3.877140837617972;
    particleTypes[8].radius[5] = 68.86019146529489;
    particleTypes[8].force[6] = -3.573767884241663;
    particleTypes[8].radius[6] = 48.437748318180226;
    particleTypes[8].force[7] = 3.2007688858021;
    particleTypes[8].radius[7] = 24.64146314940889;
    particleTypes[8].force[8] = -0.8355112432959739;
    particleTypes[8].radius[8] = 62.79873488472607;
    particleTypes[8].force[9] = 3.034799946358582;
    particleTypes[8].radius[9] = 16.75794989832559;
    particleTypes[8].force[10] = -1.7382049201149794;
    particleTypes[8].radius[10] = 10.57434402653907;
    particleTypes[8].force[11] = 1.1486423971288886;
    particleTypes[8].radius[11] = 49.824041804832476;
    particleTypes[8].steps = 1;
    particleTypes[9].force[0] = 1.0731478206883196;
    particleTypes[9].radius[0] = 68.72895103833746;
    particleTypes[9].force[1] = 0.26222636066114546;
    particleTypes[9].radius[1] = 19.069343142340895;
    particleTypes[9].force[2] = 0.3887251224968171;
    particleTypes[9].radius[2] = 73.3672224548934;
    particleTypes[9].force[3] = 3.4141507473220596;
    particleTypes[9].radius[3] = 9.725116253049109;
    particleTypes[9].force[4] = -3.884097223556296;
    particleTypes[9].radius[4] = 37.642440612263044;
    particleTypes[9].force[5] = 3.1487584745735138;
    particleTypes[9].radius[5] = 16.80003162878174;
    particleTypes[9].force[6] = 0.6106993245984516;
    particleTypes[9].radius[6] = 61.187397942396814;
    particleTypes[9].force[7] = 2.792852498337794;
    particleTypes[9].radius[7] = 5.793493766075878;
    particleTypes[9].force[8] = 0.126081191868046;
    particleTypes[9].radius[8] = 67.34340521187343;
    particleTypes[9].force[9] = -2.551352233904712;
    particleTypes[9].radius[9] = 63.90960946733686;
    particleTypes[9].force[10] = -2.4499659573121626;
    particleTypes[9].radius[10] = 6.06151277816798;
    particleTypes[9].force[11] = 2.578560806664809;
    particleTypes[9].radius[11] = 26.81689264117286;
    particleTypes[9].steps = 1;
    particleTypes[10].force[0] = 0.5438641693915862;
    particleTypes[10].radius[0] = 40.647161374893386;
    particleTypes[10].force[1] = -1.5572945268240233;
    particleTypes[10].radius[1] = 4.003731264303133;
    particleTypes[10].force[2] = -0.9295880157507632;
    particleTypes[10].radius[2] = 9.290083947389116;
    particleTypes[10].force[3] = 3.3684327168682255;
    particleTypes[10].radius[3] = 56.97394542026792;
    particleTypes[10].force[4] = 3.375160315076899;
    particleTypes[10].radius[4] = 67.52586543345585;
    particleTypes[10].force[5] = 2.3755512897504563;
    particleTypes[10].radius[5] = 53.33423717366148;
    particleTypes[10].force[6] = -3.0800779009693358;
    particleTypes[10].radius[6] = 31.38705343304113;
    particleTypes[10].force[7] = -0.8826845940951689;
    particleTypes[10].radius[7] = 44.10305389149001;
    particleTypes[10].force[8] = 0.5903061653438062;
    particleTypes[10].radius[8] = 47.65573962231717;
    particleTypes[10].force[9] = -1.495346297502568;
    particleTypes[10].radius[9] = 28.143102381592566;
    particleTypes[10].force[10] = 1.2944811157500613;
    particleTypes[10].radius[10] = 30.14403497049999;
    particleTypes[10].force[11] = 1.6273288764500418;
    particleTypes[10].radius[11] = 5.624491160462101;
    particleTypes[10].steps = 3;
    particleTypes[11].force[0] = -3.6908515823735932;
    particleTypes[11].radius[0] = 19.958674522537557;
    particleTypes[11].force[1] = -2.9414271483860333;
    particleTypes[11].radius[1] = 8.768831395133722;
    particleTypes[11].force[2] = 0.7358203740090055;
    particleTypes[11].radius[2] = 46.17011082255885;
    particleTypes[11].force[3] = -1.0382200711699987;
    particleTypes[11].radius[3] = 23.830468222492748;
    particleTypes[11].force[4] = -3.461169836080698;
    particleTypes[11].radius[4] = 33.74219201877762;
    particleTypes[11].force[5] = 0.6023675325651059;
    particleTypes[11].radius[5] = 28.39065406028318;
    particleTypes[11].force[6] = -0.3085846283162841;
    particleTypes[11].radius[6] = 42.29495147131925;
    particleTypes[11].force[7] = -2.0352051651272447;
    particleTypes[11].radius[7] = 65.96143732109421;
    particleTypes[11].force[8] = -2.5940385028695108;
    particleTypes[11].radius[8] = 61.0815637031235;
    particleTypes[11].force[9] = 3.9320609739073262;
    particleTypes[11].radius[9] = 29.57446030145812;
    particleTypes[11].force[10] = -0.3984974136625308;
    particleTypes[11].radius[10] = 58.427003216269476;
    particleTypes[11].force[11] = 1.163025105974958;
    particleTypes[11].radius[11] = 47.192640992350405;
    particleTypes[11].steps = 0;
}