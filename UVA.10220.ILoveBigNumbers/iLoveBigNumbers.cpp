#include <cstdio>

int main(){
    int arr[1001];
    arr[0]=arr[1]=1;
    arr[2]=2;arr[3]=6;arr[4]=6;arr[5]=3;arr[6]=9;arr[7]=9;arr[8]=9;arr[9]=27;arr[10]=27;arr[11]=36;arr[12]=27;arr[13]=27;arr[14]=45;arr[15]=45;arr[16]=63;arr[17]=63;arr[18]=54;arr[19]=45;arr[20]=54;arr[21]=63;arr[22]=72;arr[23]=99;arr[24]=81;arr[25]=72;arr[26]=81;arr[27]=108;arr[28]=90;arr[29]=126;arr[30]=117;arr[31]=135;arr[32]=108;arr[33]=144;arr[34]=144;arr[35]=144;arr[36]=171;arr[37]=153;arr[38]=108;arr[39]=189;arr[40]=189;arr[41]=144;arr[42]=189;arr[43]=180;arr[44]=216;arr[45]=207;arr[46]=216;arr[47]=225;arr[48]=234;arr[49]=225;arr[50]=216;arr[51]=198;arr[52]=279;arr[53]=279;arr[54]=261;arr[55]=279;arr[56]=333;arr[57]=270;arr[58]=288;arr[59]=324;arr[60]=288;arr[61]=315;arr[62]=306;arr[63]=333;arr[64]=324;arr[65]=351;arr[66]=351;arr[67]=369;arr[68]=342;arr[69]=351;arr[70]=459;arr[71]=423;arr[72]=432;arr[73]=315;arr[74]=378;arr[75]=432;arr[76]=441;arr[77]=432;arr[78]=423;arr[79]=441;arr[80]=450;arr[81]=486;arr[82]=477;arr[83]=486;arr[84]=477;arr[85]=414;arr[86]=495;arr[87]=495;arr[88]=531;arr[89]=549;arr[90]=585;arr[91]=594;arr[92]=540;arr[93]=513;arr[94]=549;arr[95]=585;arr[96]=648;arr[97]=648;arr[98]=639;arr[99]=648;arr[100]=648;arr[101]=639;arr[102]=630;arr[103]=621;arr[104]=702;arr[105]=648;arr[106]=639;arr[107]=594;arr[108]=666;arr[109]=657;arr[110]=657;arr[111]=693;arr[112]=765;arr[113]=666;arr[114]=648;arr[115]=648;arr[116]=729;arr[117]=738;arr[118]=756;arr[119]=774;arr[120]=783;arr[121]=774;arr[122]=738;arr[123]=765;arr[124]=747;arr[125]=855;arr[126]=801;arr[127]=873;arr[128]=828;arr[129]=819;arr[130]=864;arr[131]=927;arr[132]=873;arr[133]=846;arr[134]=846;arr[135]=819;arr[136]=864;arr[137]=927;arr[138]=954;arr[139]=981;arr[140]=954;arr[141]=963;arr[142]=1026;arr[143]=936;arr[144]=1017;arr[145]=972;arr[146]=1017;arr[147]=954;arr[148]=1008;arr[149]=1107;arr[150]=1053;arr[151]=990;arr[152]=990;arr[153]=999;arr[154]=1062;arr[155]=1053;arr[156]=1098;arr[157]=1125;arr[158]=1134;arr[159]=1089;arr[160]=1107;arr[161]=1134;arr[162]=1125;arr[163]=1134;arr[164]=1098;arr[165]=1116;arr[166]=1188;arr[167]=1089;arr[168]=1188;arr[169]=1188;arr[170]=1179;arr[171]=1242;arr[172]=1215;arr[173]=1206;arr[174]=1215;arr[175]=1233;arr[176]=1215;arr[177]=1278;arr[178]=1368;arr[179]=1260;arr[180]=1305;arr[181]=1323;arr[182]=1287;arr[183]=1314;arr[184]=1323;arr[185]=1260;arr[186]=1296;arr[187]=1377;arr[188]=1422;arr[189]=1386;arr[190]=1350;arr[191]=1422;arr[192]=1404;arr[193]=1458;arr[194]=1395;arr[195]=1413;arr[196]=1422;arr[197]=1512;arr[198]=1395;arr[199]=1413;arr[200]=1404;arr[201]=1350;arr[202]=1404;arr[203]=1476;arr[204]=1494;arr[205]=1530;arr[206]=1584;arr[207]=1647;arr[208]=1602;arr[209]=1530;arr[210]=1548;arr[211]=1512;arr[212]=1593;arr[213]=1530;arr[214]=1674;arr[215]=1674;arr[216]=1575;arr[217]=1638;arr[218]=1665;arr[219]=1575;arr[220]=1701;arr[221]=1692;arr[222]=1665;arr[223]=1701;arr[224]=1773;arr[225]=1728;arr[226]=1728;arr[227]=1656;arr[228]=1638;arr[229]=1701;arr[230]=1746;arr[231]=1665;arr[232]=1809;arr[233]=1728;arr[234]=1872;arr[235]=1746;arr[236]=1755;arr[237]=1890;arr[238]=1818;arr[239]=1818;arr[240]=1926;arr[241]=1890;arr[242]=1971;arr[243]=1980;arr[244]=1863;arr[245]=1944;arr[246]=1827;arr[247]=1872;arr[248]=1935;arr[249]=1881;arr[250]=1953;arr[251]=1926;arr[252]=1917;arr[253]=2025;arr[254]=1926;arr[255]=1899;arr[256]=1989;arr[257]=1953;arr[258]=1863;arr[259]=1971;arr[260]=1962;arr[261]=2079;arr[262]=2088;arr[263]=2061;arr[264]=1953;arr[265]=2106;arr[266]=2124;arr[267]=2043;arr[268]=2133;arr[269]=2106;arr[270]=2151;arr[271]=2169;arr[272]=2133;arr[273]=1980;arr[274]=2088;arr[275]=2187;arr[276]=2043;arr[277]=2313;arr[278]=2367;arr[279]=2223;arr[280]=2241;arr[281]=2367;arr[282]=2340;arr[283]=2349;arr[284]=2241;arr[285]=2304;arr[286]=2313;arr[287]=2385;arr[288]=2322;arr[289]=2385;arr[290]=2313;arr[291]=2331;arr[292]=2412;arr[293]=2385;arr[294]=2358;arr[295]=2511;arr[296]=2484;arr[297]=2394;arr[298]=2376;arr[299]=2448;arr[300]=2466;arr[301]=2376;arr[302]=2511;arr[303]=2493;arr[304]=2394;arr[305]=2529;arr[306]=2457;arr[307]=2466;arr[308]=2430;arr[309]=2412;arr[310]=2646;arr[311]=2556;arr[312]=2565;arr[313]=2502;arr[314]=2601;arr[315]=2556;arr[316]=2637;arr[317]=2574;arr[318]=2655;arr[319]=2583;arr[320]=2700;arr[321]=2628;arr[322]=2808;arr[323]=2637;arr[324]=2610;arr[325]=2700;arr[326]=2727;arr[327]=2682;arr[328]=2718;arr[329]=2754;arr[330]=2655;arr[331]=2772;arr[332]=2853;arr[333]=2862;arr[334]=2835;arr[335]=2790;arr[336]=2907;arr[337]=2817;arr[338]=2925;arr[339]=2817;arr[340]=2754;arr[341]=2961;arr[342]=2835;arr[343]=2844;arr[344]=2844;arr[345]=2916;arr[346]=2808;arr[347]=2844;arr[348]=2970;arr[349]=2934;arr[350]=2952;arr[351]=2862;arr[352]=3123;arr[353]=2844;arr[354]=2925;arr[355]=3069;arr[356]=2952;arr[357]=2979;arr[358]=2979;arr[359]=3087;arr[360]=3024;arr[361]=2997;arr[362]=3060;arr[363]=3060;arr[364]=3087;arr[365]=3114;arr[366]=3024;arr[367]=3033;arr[368]=3132;arr[369]=3204;arr[370]=3186;arr[371]=3213;arr[372]=3195;arr[373]=3258;arr[374]=3186;arr[375]=3159;arr[376]=3249;arr[377]=3186;arr[378]=3132;arr[379]=3312;arr[380]=3240;arr[381]=3195;arr[382]=3204;arr[383]=3357;arr[384]=3339;arr[385]=3375;arr[386]=3366;arr[387]=3204;arr[388]=3348;arr[389]=3366;arr[390]=3321;arr[391]=3384;arr[392]=3474;arr[393]=3312;arr[394]=3348;arr[395]=3312;arr[396]=3582;arr[397]=3429;arr[398]=3528;arr[399]=3627;arr[400]=3402;arr[401]=3339;arr[402]=3366;arr[403]=3483;arr[404]=3474;arr[405]=3600;arr[406]=3528;arr[407]=3609;arr[408]=3465;arr[409]=3483;arr[410]=3447;arr[411]=3573;arr[412]=3672;arr[413]=3600;arr[414]=3654;arr[415]=3708;arr[416]=3618;arr[417]=3726;arr[418]=3708;arr[419]=3564;arr[420]=3672;arr[421]=3807;arr[422]=3690;arr[423]=3627;arr[424]=3636;arr[425]=3780;arr[426]=3618;arr[427]=3753;arr[428]=3636;arr[429]=3762;arr[430]=3807;arr[431]=3798;arr[432]=3897;arr[433]=3771;arr[434]=3834;arr[435]=3879;arr[436]=3780;arr[437]=3780;arr[438]=4059;arr[439]=3807;arr[440]=3726;arr[441]=3852;arr[442]=3861;arr[443]=3753;arr[444]=4041;arr[445]=3969;arr[446]=3825;arr[447]=3978;arr[448]=4023;arr[449]=4185;arr[450]=3825;arr[451]=3888;arr[452]=4059;arr[453]=4203;arr[454]=4140;arr[455]=4059;arr[456]=4176;arr[457]=4176;arr[458]=4149;arr[459]=3969;arr[460]=4077;arr[461]=4131;arr[462]=4158;arr[463]=4221;arr[464]=4041;arr[465]=4194;arr[466]=4275;arr[467]=4140;arr[468]=4257;arr[469]=4140;arr[470]=4275;arr[471]=4338;arr[472]=4284;arr[473]=4266;arr[474]=4419;arr[475]=4428;arr[476]=4383;arr[477]=4194;arr[478]=4356;arr[479]=4365;arr[480]=4356;arr[481]=4059;arr[482]=4320;arr[483]=4266;arr[484]=4302;arr[485]=4383;arr[486]=4329;arr[487]=4536;arr[488]=4509;arr[489]=4419;arr[490]=4284;arr[491]=4410;arr[492]=4608;arr[493]=4302;arr[494]=4455;arr[495]=4464;arr[496]=4374;arr[497]=4644;arr[498]=4527;arr[499]=4608;arr[500]=4599;arr[501]=4446;arr[502]=4518;arr[503]=4536;arr[504]=4671;arr[505]=4644;arr[506]=4527;arr[507]=4581;arr[508]=4671;arr[509]=4707;arr[510]=4644;arr[511]=4554;arr[512]=4635;arr[513]=4761;arr[514]=4563;arr[515]=4716;arr[516]=4698;arr[517]=4779;arr[518]=4860;arr[519]=4752;arr[520]=4761;arr[521]=4680;arr[522]=4698;arr[523]=4842;arr[524]=4815;arr[525]=4860;arr[526]=4761;arr[527]=4968;arr[528]=4986;arr[529]=4941;arr[530]=4977;arr[531]=4950;arr[532]=4923;arr[533]=4896;arr[534]=4932;arr[535]=4851;arr[536]=4977;arr[537]=4797;arr[538]=4986;arr[539]=4869;arr[540]=5202;arr[541]=5067;arr[542]=5085;arr[543]=4941;arr[544]=4968;arr[545]=5076;arr[546]=5112;arr[547]=5274;arr[548]=5121;arr[549]=4923;arr[550]=5139;arr[551]=4860;arr[552]=5337;arr[553]=4950;arr[554]=5067;arr[555]=5193;arr[556]=5409;arr[557]=5166;arr[558]=5247;arr[559]=5346;arr[560]=5139;arr[561]=5274;arr[562]=5202;arr[563]=5373;arr[564]=5265;arr[565]=5391;arr[566]=5301;arr[567]=5337;arr[568]=5472;arr[569]=5319;arr[570]=5265;arr[571]=5427;arr[572]=5400;arr[573]=5427;arr[574]=5364;arr[575]=5346;arr[576]=5337;arr[577]=5454;arr[578]=5265;arr[579]=5400;arr[580]=5373;arr[581]=5499;arr[582]=5562;arr[583]=5382;arr[584]=5427;arr[585]=5292;arr[586]=5706;arr[587]=5562;arr[588]=5499;arr[589]=5526;arr[590]=5562;arr[591]=5652;arr[592]=5562;arr[593]=5679;arr[594]=5328;arr[595]=5616;arr[596]=5724;arr[597]=5787;arr[598]=5697;arr[599]=5634;arr[600]=5715;arr[601]=5634;arr[602]=5760;arr[603]=5787;arr[604]=5589;arr[605]=5742;arr[606]=5661;arr[607]=5499;arr[608]=5823;arr[609]=5931;arr[610]=5823;arr[611]=5877;arr[612]=5823;arr[613]=5787;arr[614]=5832;arr[615]=5841;arr[616]=5850;arr[617]=5886;arr[618]=5778;arr[619]=5841;arr[620]=5922;arr[621]=6039;arr[622]=5859;arr[623]=6003;arr[624]=5931;arr[625]=5958;arr[626]=6120;arr[627]=5895;arr[628]=5904;arr[629]=5904;arr[630]=6057;arr[631]=6012;arr[632]=5931;arr[633]=5967;arr[634]=6147;arr[635]=5859;arr[636]=5859;arr[637]=6237;arr[638]=6210;arr[639]=6336;arr[640]=6057;arr[641]=6291;arr[642]=6021;arr[643]=6291;arr[644]=6021;arr[645]=6219;arr[646]=6156;arr[647]=6282;arr[648]=6012;arr[649]=6372;arr[650]=6300;arr[651]=6399;arr[652]=6372;arr[653]=6282;arr[654]=6246;arr[655]=6291;arr[656]=6318;arr[657]=6219;arr[658]=6453;arr[659]=6192;arr[660]=6516;arr[661]=6408;arr[662]=6444;arr[663]=6147;arr[664]=6417;arr[665]=6381;arr[666]=6327;arr[667]=6498;arr[668]=6462;arr[669]=6453;arr[670]=6363;arr[671]=6489;arr[672]=6417;arr[673]=6480;arr[674]=6615;arr[675]=6453;arr[676]=6561;arr[677]=6831;arr[678]=6444;arr[679]=6444;arr[680]=6444;arr[681]=6417;arr[682]=6534;arr[683]=6687;arr[684]=6786;arr[685]=6651;arr[686]=6687;arr[687]=6615;arr[688]=6777;arr[689]=6795;arr[690]=6876;arr[691]=6966;arr[692]=6957;arr[693]=6669;arr[694]=6822;arr[695]=6831;arr[696]=6696;arr[697]=6741;arr[698]=6957;arr[699]=6885;arr[700]=6723;arr[701]=6777;arr[702]=6741;arr[703]=6849;arr[704]=6840;arr[705]=6678;arr[706]=6849;arr[707]=6831;arr[708]=6957;arr[709]=7065;arr[710]=7056;arr[711]=7092;arr[712]=6966;arr[713]=6876;arr[714]=7083;arr[715]=6912;arr[716]=7191;arr[717]=7101;arr[718]=7020;arr[719]=7191;arr[720]=7164;arr[721]=6957;arr[722]=7110;arr[723]=7047;arr[724]=7092;arr[725]=6957;arr[726]=7083;arr[727]=7182;arr[728]=7407;arr[729]=7065;arr[730]=7254;arr[731]=7137;arr[732]=7254;arr[733]=7155;arr[734]=7155;arr[735]=7128;arr[736]=7515;arr[737]=7317;arr[738]=7029;arr[739]=7461;arr[740]=7263;arr[741]=7218;arr[742]=7425;arr[743]=7317;arr[744]=7326;arr[745]=7362;arr[746]=7641;arr[747]=7452;arr[748]=7263;arr[749]=7380;arr[750]=7416;arr[751]=7263;arr[752]=7398;arr[753]=7524;arr[754]=7533;arr[755]=7308;arr[756]=7524;arr[757]=7452;arr[758]=7488;arr[759]=7434;arr[760]=7461;arr[761]=7488;arr[762]=7353;arr[763]=7731;arr[764]=7470;arr[765]=7641;arr[766]=7461;arr[767]=7272;arr[768]=7542;arr[769]=7569;arr[770]=7713;arr[771]=7704;arr[772]=7767;arr[773]=7551;arr[774]=7776;arr[775]=7596;arr[776]=7722;arr[777]=7875;arr[778]=7659;arr[779]=7686;arr[780]=7659;arr[781]=7677;arr[782]=7776;arr[783]=7686;arr[784]=7983;arr[785]=7857;arr[786]=7938;arr[787]=8001;arr[788]=7839;arr[789]=7965;arr[790]=7929;arr[791]=8109;arr[792]=7812;arr[793]=7938;arr[794]=8001;arr[795]=8001;arr[796]=8091;arr[797]=8100;arr[798]=7884;arr[799]=8001;arr[800]=7929;arr[801]=7965;arr[802]=7947;arr[803]=8127;arr[804]=7947;arr[805]=7965;arr[806]=7812;arr[807]=8028;arr[808]=8217;arr[809]=8208;arr[810]=8181;arr[811]=8280;arr[812]=8028;arr[813]=8037;arr[814]=8298;arr[815]=8172;arr[816]=8424;arr[817]=8127;arr[818]=8235;arr[819]=8001;arr[820]=8163;arr[821]=8307;arr[822]=8496;arr[823]=8181;arr[824]=8172;arr[825]=8415;arr[826]=8343;arr[827]=8424;arr[828]=8217;arr[829]=8361;arr[830]=8397;arr[831]=8433;arr[832]=8307;arr[833]=8649;arr[834]=8352;arr[835]=8370;arr[836]=8514;arr[837]=8514;arr[838]=8082;arr[839]=8568;arr[840]=8316;arr[841]=8370;arr[842]=8478;arr[843]=8649;arr[844]=8658;arr[845]=8541;arr[846]=8550;arr[847]=8388;arr[848]=8622;arr[849]=8586;arr[850]=8586;arr[851]=8595;arr[852]=8649;arr[853]=8550;arr[854]=8694;arr[855]=8685;arr[856]=8694;arr[857]=8676;arr[858]=8685;arr[859]=8793;arr[860]=8667;arr[861]=8802;arr[862]=8757;arr[863]=8901;arr[864]=8937;arr[865]=8694;arr[866]=8946;arr[867]=8820;arr[868]=8829;arr[869]=9000;arr[870]=9009;arr[871]=9009;arr[872]=8955;arr[873]=8811;arr[874]=8883;arr[875]=8928;arr[876]=8928;arr[877]=8982;arr[878]=8757;arr[879]=8901;arr[880]=9090;arr[881]=8973;arr[882]=9117;arr[883]=8946;arr[884]=8838;arr[885]=9099;arr[886]=9189;arr[887]=9099;arr[888]=9072;arr[889]=8811;arr[890]=9054;arr[891]=9054;arr[892]=8865;arr[893]=9063;arr[894]=9126;arr[895]=9189;arr[896]=9135;arr[897]=9045;arr[898]=9216;arr[899]=9090;arr[900]=9324;arr[901]=9162;arr[902]=9324;arr[903]=9081;arr[904]=9045;arr[905]=9414;arr[906]=9153;arr[907]=9369;arr[908]=9333;arr[909]=9486;arr[910]=9126;arr[911]=9081;arr[912]=9477;arr[913]=9198;arr[914]=9468;arr[915]=9504;arr[916]=9603;arr[917]=9360;arr[918]=9396;arr[919]=9477;arr[920]=9423;arr[921]=9522;arr[922]=9450;arr[923]=9702;arr[924]=9432;arr[925]=9594;arr[926]=9558;arr[927]=9630;arr[928]=9549;arr[929]=9477;arr[930]=9675;arr[931]=9549;arr[932]=9702;arr[933]=9540;arr[934]=9738;arr[935]=9666;arr[936]=9729;arr[937]=9801;arr[938]=9657;arr[939]=9810;arr[940]=9729;arr[941]=9513;arr[942]=9612;arr[943]=9774;arr[944]=9684;arr[945]=9702;arr[946]=9675;arr[947]=9504;arr[948]=9792;arr[949]=9684;arr[950]=9639;arr[951]=10035;arr[952]=9855;arr[953]=9774;arr[954]=9783;arr[955]=9990;arr[956]=9999;arr[957]=9954;arr[958]=9945;arr[959]=9981;arr[960]=9954;arr[961]=9999;arr[962]=9900;arr[963]=10071;arr[964]=10125;arr[965]=10080;arr[966]=9828;arr[967]=10116;arr[968]=10143;arr[969]=10089;arr[970]=10134;arr[971]=9711;arr[972]=10053;arr[973]=10314;arr[974]=10035;arr[975]=10278;arr[976]=9990;arr[977]=10053;arr[978]=10179;arr[979]=10413;arr[980]=10134;arr[981]=10341;arr[982]=10458;arr[983]=9990;arr[984]=10296;arr[985]=10053;arr[986]=10296;arr[987]=10206;arr[988]=10287;arr[989]=10332;arr[990]=10467;arr[991]=10287;arr[992]=10296;arr[993]=10251;arr[994]=10584;arr[995]=10395;arr[996]=10233;arr[997]=10368;arr[998]=10287;arr[999]=10539;arr[1000]=10539;
    int n;
    while(scanf("%d",&n)==1){
        printf("%d\n",arr[n]);
    }

    return 0;
}
