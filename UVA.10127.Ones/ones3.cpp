#include <cstdio>
int main(){
int a[]={0,1,0,3,0,0,0,6,0,9,0,2,0,6,0,0,0,16,0,18,0,6,0,22,0,0,0,27,0,28,0,15,0,6,0,0,0,3,0,6,0,5,0,21,0,0,0,46,0,42,0,48,0,13,0,0,0,18,0,58,0,60,0,18,0,0,0,33,0,66,0,35,0,8,0,0,0,6,0,13,0,81,0,41,0,0,0,84,0,44,0,6,0,15,0,0,0,96,0,18,0,4,0,34,0,0,0,53,0,108,0,3,0,112,0,0,0,18,0,48,0,22,0,15,0,0,0,42,0,21,0,130,0,18,0,0,0,8,0,46,0,138,0,6,0,0,0,42,0,148,0,75,0,144,0,0,0,78,0,39,0,66,0,81,0,0,0,166,0,78,0,18,0,43,0,0,0,174,0,178,0,180,0,60,0,0,0,16,0,54,0,95,0,192,0,0,0,98,0,99,0,33,0,84,0,0,0,198,0,18,0,30,0,105,0,0,0,30,0,24,0,48,0,222,0,0,0,113,0,228,0,6,0,232,0,0,0,39,0,7,0,30,0,243,0,0,0,18,0,123,0,50,0,22,0,0,0,256,0,6,0,252,0,262,0,0,0,132,0,268,0,5,0,6,0,0,0,69,0,45,0,28,0,141,0,0,0,30,0,272,0,96,0,146,0,0,0,54,0,66,0,42,0,12,0,0,0,153,0,102,0,155,0,312,0,0,0,79,0,28,0,159,0,144,0,0,0,108,0,138,0,110,0,9,0,0,0,336,0,336,0,30,0,294,0,0,0,173,0,116,0,54,0,32,0,0,0,48,0,179,0,342,0,66,0,0,0,366,0,45,0,78,0,186,0,0,0,84,0,378,0,42,0,382,0,0,0,63,0,388,0,176,0,390,0,0,0,99,0,18,0,200,0,30,0,0,0,6,0,204,0,24,0,174,0,0,0,138,0,418,0,140,0,414,0,0,0,60,0,6,0,215,0,432,0,0,0,198,0,219,0,126,0,221,0,0,0,444,0,32,0,10,0,75,0,0,0,152,0,432,0,460,0,154,0,0,0,233,0,66,0,78,0,42,0,0,0,117,0,239,0,6,0,66,0,0,0,486,0,81,0,490,0,112,0,0,0,210,0,498,0,498,0,502,0,0,0,78,0,508,0,24,0,54,0,0,0,46,0,129,0,52,0,261,0,0,0,240,0,506,0,522,0,30,0,0,0,534,0,42,0,540,0,180,0,0,0,91,0,180,0,252,0,78,0,0,0,278,0,42,0,48,0,281,0,0,0,162,0,284,0,570,0,285,0,0,0,576,0,192,0,246,0,26,0,0,0,293,0,90,0,294,0,592,0,0,0,99,0,299,0,300,0,99,0,0,0,202,0,84,0,138,0,51,0,0,0,88,0,618,0,594,0,132,0,0,0,18,0,48,0,315,0,30,0,0,0,42,0,315,0,32,0,107,0,0,0,646,0,58,0,30,0,326,0,0,0,72,0,658,0,220,0,48,0,0,0,308,0,222,0,60,0,224,0,0,0,338,0,96,0,339,0,341,0,0,0,228,0,78,0,230,0,18,0,0,0,80,0,696,0,700,0,18,0,0,0,12,0,708,0,117,0,330,0,0,0,21,0,359,0,102,0,30,0,0,0,726,0,729,0,336,0,61,0,0,0,66,0,246,0,18,0,742,0,0,0,369,0,318,0,125,0,150,0,0,0,27,0,66,0,380,0,108,0,0,0,174,0,192,0,768,0,193,0,0,0,6,0,90,0,70,0,756,0,0,0,393,0,786,0,336,0,60,0,0,0,199,0,368,0,396,0,8,0,0,0,804,0,202,0,810,0,15,0,0,0,126,0,18,0,820,0,822,0,0,0,413,0,276,0,69,0,336,0,0,0,135,0,419,0,812,0,84,0,0,0,66,0,141,0,66,0,213,0,0,0,856,0,26,0,30,0,862,0,0,0,816,0,26,0,66,0,288,0,0,0,438,0,438,0,440,0,441,0,0,0,886,0,42,0,162,0,414,0,0,0,66,0,420,0,208,0,42,0,0,0,151,0,36,0,455,0,82,0,0,0,390,0,459,0,153,0,210,0,0,0,306,0,464,0,126,0,465,0,0,0,936,0,312,0,940,0,110,0,0,0,473,0,24,0,237,0,952,0,0,0,84,0,24,0,465,0,477,0,0,0,322,0,144,0,970,0,138,0,0,0,976,0,44,0,108,0,982,0,0,0,138,0,462,0,495,0,330,0,0,0,166,0,27,0,6,0,464,0,0,0,234,0,252,0,336,0,253,0,0,0,1008,0,1018,0,1020,0,30,0,0,0,78,0,294,0,103,0,1032,0,0,0,240,0,519,0,519,0,444,0,0,0,348,0,524,0,1050,0,162,0,0,0,150,0,96,0,212,0,1062,0,0,0,96,0,1068,0,144,0,84,0,0,0,537,0,246,0,506,0,342,0,0,0,1086,0,198,0,1090,0,273,0,0,0,1096,0,78,0,366,0,1102,0,0,0,135,0,1108,0,4,0,78,0,0,0,558,0,186,0,522,0,561,0,0,0,462,0,564,0,84,0,34,0,0,0,378,0,528,0,162,0,126,0,0,0,15,0,1146,0,575,0,1152,0,0,0,132,0,180,0,189,0,581,0,0,0,1164,0,498,0,1170,0,528,0,0,0,106,0,1170,0,1180,0,78,0,0,0,593,0,140,0,99,0,1192,0,0,0,18,0,108,0,200,0,600,0,0,0,560,0,30,0,258,0,202,0,0,0,1216,0,286,0,6,0,1222,0,0,0,204,0,1228,0,41,0,72,0,0,0,206,0,174,0,16,0,112,0,0,0,84,0,208,0,414,0,534,0,0,0,1254,0,1258,0,96,0,420,0,0,0,180,0,1242,0,15,0,198,0,0,0,638,0,639,0,60,0,641,0,0,0,18,0,92,0,1290,0,645,0,0,0,1296,0,432,0,1300,0,1302,0,0,0,653,0,48,0,198,0,12,0,0,0,219,0,659,0,55,0,378,0,0,0,1326,0,663,0,242,0,105,0,0,0,570,0,102,0,1332,0,208,0,0,0,96,0,630,0,192,0,30,0,0,0,638,0,225,0,680,0,644,0,0,0,1366,0,111,0,456,0,686,0,0,0,1296,0,294,0,1380,0,1380,0,0,0,72,0,462,0,318,0,198,0,0,0,42,0,699,0,699,0,660,0,0,0,66,0,32,0,656,0,234,0,0,0,108,0,42,0,84,0,158,0,0,0,713,0,1428,0,351,0,1432,0,0,0,717,0,719,0,130,0,6,0,0,0,1446,0,198,0,290,0,726,0,0,0,690,0,162,0,486,0,18,0,0,0,81,0,336,0,735,0,1470,0,0,0,30,0,336,0,740,0,247,0,0,0,1486,0,248,0,210,0,373,0,0,0,498,0,214,0,234,0,1494,0,0,0,8,0,1506,0,755,0,176,0,0,0,15,0,210,0,234,0,761,0,0,0,1524,0,46,0,1530,0,24,0,0,0,364,0,162,0,66,0,1542,0,0,0,48,0,1548,0,138,0,1552,0,0,0,387,0,779,0,222,0,156,0,0,0,1566,0,261,0,1570,0,66,0,0,0,738,0,1578,0,240,0,1582,0,0,0,1518,0,678,0,21,0,1566,0,0,0,133,0,30,0,200,0,228,0,0,0,1606,0,201,0,1602,0,403,0,0,0,42,0,1618,0,1620,0,540,0,0,0,271,0,180,0,696,0,770,0,0,0,409,0,148,0,273,0,195,0,0,0,540,0,96,0,42,0,252,0,0,0,552,0,78,0,150,0,1662,0,0,0,833,0,556,0,834,0,42,0,0,0,42,0,88,0,205,0,144,0,0,0,30,0,843,0,396,0,423,0,0,0,1696,0,566,0,486,0,390,0,0,0,852,0,1708,0,812,0,570,0,0,0,16,0,855,0,430,0,287,0,0,0,78,0,18,0,576,0,866,0,0,0,576,0,138,0,1740,0,246,0,0,0,291,0,78,0,272,0,584,0,0,0,150,0,879,0,879,0,105,0,0,0,90,0,420,0,66,0,882,0,0,0,1776,0,1776,0,24,0,1782,0,0,0,893,0,1788,0,99,0,162,0,0,0,897,0,768,0,900,0,300,0,0,0,138,0,297,0,1810,0,42,0,0,0,286,0,848,0,606,0,1822,0,0,0,252,0,870,0,305,0,138,0,0,0,166,0,51,0,786,0,288,0,0,0,1846,0,903,0,264,0,432,0,0,0,618,0,78,0,1860,0,1782,0,0,0,933,0,132,0,935,0,1872,0,0,0,938,0,313,0,18,0,804,0,0,0,48,0,118,0,60,0,315,0,0,0,30,0,90,0,380,0,86,0,0,0,953,0,902,0,42,0,1912,0,0,0,945,0,36,0,112,0,96,0,0,0,230,0,321,0,386,0,21,0,0,0,444,0,138,0,1938,0,924,0,0,0,174,0,1948,0,195,0,90,0,0,0,306,0,978,0,39,0,150,0,0,0,84,0,178,0,216,0,986,0,0,0,1974,0,1978,0,282,0,660,0,0,0,331,0,144,0,180,0,664,0,0,0,998,0,999,0,924,0,1001,0,0,0,666,0,210,0,670,0,60,0,0,0,2016,0,672,0,966,0,816,0,0,0,1013,0,2028,0,1014,0,954,0,0,0,96,0,1019,0,78,0,1017,0,0,0,44,0,1023,0,438,0,342,0,0,0,176,0,140,0,684,0,2062,0,0,0,78,0,2068,0,108,0,690,0,0,0,165,0,54,0,1040,0,1041,0,0,0,298,0,1044,0,240,0,66,0,0,0,2088,0,2098,0,190,0,2100,0,0,0,42,0,18,0,1055,0,2112,0,0,0,56,0,162,0,12,0,192,0,0,0,708,0,532,0,710,0,351,0,0,0,2136,0,330,0,2140,0,2142,0,0,0,1008,0,306,0,63,0,2152,0,0,0,1077,0,336,0,30,0,102,0,0,0,98,0,90,0,498,0,65,0,0,0,930,0,2178,0,726,0,174,0,0,0,2187,0,198,0,312,0,336,0,0,0,1014,0,183,0,105,0,1101,0,0,0,2206,0,2162,0,66,0,553,0,0,0,246,0,474,0,2220,0,18,0,0,0,1040,0,2226,0,1056,0,84,0,0,0,1118,0,1119,0,1107,0,1121,0,0,0,318,0,258,0,2250,0,375,0,0,0,60,0,450,0,144,0,120,0,0,0,1133,0,2268,0,27,0,2272,0,0,0,198,0,273,0,228,0,1140,0,0,0,762,0,108,0,364,0,1146,0,0,0,2296,0,198,0,174,0,966,0,0,0,192,0,2308,0,231,0,2304,0,0,0,330,0,579,0,30,0,44,0,0,0,534,0,16,0,18,0,583,0,0,0,90,0,2338,0,2340,0,210,0,0,0,1173,0,2268,0,1175,0,180,0,0,0,1178,0,336,0,393,0,368,0,0,0,2358,0,374,0,2370,0,336,0,0,0,264,0,60,0,476,0,2382,0,0,0,30,0,2388,0,597,0,184,0,0,0,1104,0,1199,0,2058,0,1188,0,0,0,1148,0,24,0,2410,0,126,0,0,0,2416,0,290,0,2412,0,2422,0,0,0,606,0,1038,0,48,0,810,0,0,0,1218,0,45,0,305,0,348,0,0,0,2446,0,195,0,126,0,222,0,0,0,54,0,2458,0,1166,0,2460,0,0,0,137,0,822,0,96,0,2472,0,0,0,619,0,33,0,1239,0,570,0,0,0,276,0,1170,0,598,0,207,0,0,0,226,0,336,0,60,0,278,0,0,0,1188,0,192,0,405,0,1074,0,0,0,1257,0,228,0,630,0,2436,0,0,0,342,0,252,0,46,0,592,0,0,0,1218,0,2538,0,66,0,2542,0,0,0,423,0,2548,0,425,0,66,0,0,0,639,0,213,0,294,0,232,0,0,0,1200,0,366,0,2568,0,615,0,0,0,78,0,2578,0,308,0,90,0,0,0,198,0,2586,0,259,0,2592,0,0,0,546,0,1232,0,2448,0,72,0,0,0,78,0,1304,0,186,0,66,0,0,0,2616,0,864,0,2620,0,420,0,0,0,105,0,14,0,438,0,2632,0,0,0,1314,0,84,0,414,0,1320,0,0,0,882,0,441,0,30,0,378,0,0,0,2656,0,886,0,2658,0,2662,0,0,0,42,0,624,0,1335,0,486,0,0,0,223,0,414,0,1146,0,447,0,0,0,2686,0,42,0,198,0,1346,0,0,0,420,0,2698,0,24,0,624,0,0,0,1353,0,126,0,1355,0,2712,0,0,0,18,0,1359,0,453,0,1164,0,0,0,108,0,682,0,2730,0,1365,0,0,0,528,0,246,0,2740,0,30,0,0,0,165,0,916,0,390,0,2752,0,0,0,459,0,660,0,50,0,153,0,0,0,2766,0,210,0,1296,0,1334,0,0,0,2776,0,198,0,918,0,22,0,0,0,1392,0,2788,0,31,0,126,0,0,0,699,0,1395,0,1400,0,1401,0,0,0,600,0,689,0,936,0,672,0,0,0,936,0,2818,0,30,0,2820,0,0,0,256,0,330,0,1332,0,2832,0,0,0,709,0,1328,0,1419,0,1421,0,0,0,24,0,6,0,2850,0,711,0,0,0,408,0,2856,0,2860,0,204,0,0,0,1380,0,450,0,252,0,624,0,0,0,24,0,1439,0,231,0,465,0,0,0,2886,0,1431,0,1218,0,262,0,0,0,2896,0,222,0,966,0,2902,0,0,0,144,0,2908,0,35,0,2910,0,0,0,1458,0,138,0,462,0,39,0,0,0,2926,0,28,0,2928,0,1254,0,0,0,132,0,2938,0,688,0,108,0,0,0,420,0,2946,0,678,0,984,0,0,0,1478,0,268,0,414,0,1481,0,0,0,462,0,371,0,2970,0,495,0,0,0,228,0,990,0,10,0,234,0,0,0,476,0,420,0,498,0,40,0,0,0,81,0,1499,0,1500,0,6,0,0,0,480,0,1392,0,3010,0,1430,0,0,0,1290,0,3018,0,234,0,3022,0,0,0,252,0,696,0,432,0,1008,0,0,0,253,0,759,0,380,0,1424,0,0,0,138,0,508,0,3024,0,105,0,0,0,3054,0,198,0,204,0,1020,0,0,0,1533,0,90,0,123,0,438,0,0,0,720,0,1539,0,78,0,1541,0,0,0,882,0,1544,0,28,0,309,0,0,0,162,0,1032,0,1326,0,1484,0,0,0,42,0,148,0,240,0,282,0,0,0,519,0,1559,0,156,0,1557,0,0,0,754,0,444,0,60,0,30,0,0,0,3136,0,168,0,1044,0,96,0,0,0,1572,0,1518,0,88,0,1050,0,0,0,30,0,486,0,756,0,1581,0,0,0,3166,0,72,0,150,0,1494,0,0,0,288,0,272,0,636,0,636,0,0,0,177,0,1062,0,29,0,510,0,0,0,506,0,456,0,96,0,1601,0,0,0,1068,0,1604,0,234,0,432,0,0,0,1072,0,84,0,3220,0,146,0,0,0,1380,0,1076,0,1611,0,780,0,0,0,246,0,65,0,462,0,1518,0,0,0,1520,0,342,0,3250,0,542,0,0,0,3256,0,3258,0,1086,0,150,0,0,0,594,0,1398,0,1635,0,3270,0,0,0,112,0,273,0,192,0,462,0,0,0,774,0,66,0,3288,0,132,0,0,0,78,0,3298,0,3300,0,1098,0,0,0,1653,0,3306,0,42,0,3312,0,0,0,795,0,553,0,405,0,1661,0,0,0,3324,0,832,0,3330,0,12,0,0,0,1610,0,234,0,768,0,3342,0,0,0,1673,0,784,0,558,0,1434,0,0,0,558,0,1679,0,1680,0,522,0,0,0,6,0,561,0,3370,0,843,0,0,0,306,0,540,0,462,0,1584,0,0,0,564,0,3388,0,1695,0,252,0,0,0,273,0,102,0,1602,0,205,0,0,0,3406,0,486,0,378,0,1706,0,0,0,528,0,786,0,310,0,162,0,0,0,1628,0,378,0,184,0,3432,0,0,0,1470,0,180,0,15,0,312,0,0,0,3438,0,431,0,336,0,1725,0,0,0,384,0,1152,0,3460,0,3462,0,0,0,1733,0,3468,0,132,0,1650,0,0,0,180,0,210,0,3422,0,567,0,0,0,158,0,1743,0,698,0,498,0,0,0,804,0,318,0,3492,0,1680,0,0,0,498,0,308,0,1755,0,1170,0,0,0,879,0,1584,0,1506,0,30,0,0,0,3526,0,1764,0,318,0,1766,0,0,0,3510,0,3538,0,20,0,3540,0,0,0,1773,0,78,0,429,0,144,0,0,0,254,0,1779,0,1779,0,1524,0,0,0,420,0,861,0,3570,0,99,0,0,0,168,0,3576,0,3580,0,1194,0,0,0,240,0,96,0,54,0,3592,0,0,0,108,0,1740,0,138,0,600,0,0,0,3606,0,1800,0,858,0,602,0,0,0,3616,0,138,0,1680,0,3622,0,0,0,90,0,1710,0,1815,0,258,0,0,0,909,0,606,0,110,0,1821,0,0,0,156,0,220,0,3648,0,84,0,0,0,858,0,3658,0,522,0,18,0,0,0,576,0,3666,0,367,0,3672,0,0,0,1838,0,282,0,612,0,84,0,0,0,3684,0,240,0,1230,0,123,0,0,0,1232,0,216,0,3700,0,1518,0,0,0,336,0,3708,0,618,0,598,0,0,0,522,0,1859,0,3660,0,48,0,0,0,3726,0,336,0,30,0,933,0,0,0,12,0,1246,0,84,0,882,0,0,0,624,0,1782,0,330,0,1242,0,0,0,816,0,534,0,1880,0,455,0,0,0,3766,0,1884,0,3762,0,294,0,0,0,3774,0,3778,0,198,0,96,0,0,0,540,0,1260,0,1776,0,1264,0,0,0,949,0,1820,0,180,0,1901,0,0,0,3726,0,438,0,102,0,15,0,0,0,346,0,198,0,3820,0,1274,0,0,0,924,0,546,0,1914,0,3832,0,0,0,639,0,116,0,1826,0,180,0,0,0,3846,0,1923,0,770,0,963,0,0,0,252,0,1808,0,54,0,3862,0,0,0,276,0,104,0,546,0,1290,0,0,0,969,0,1935,0,1940,0,32,0,0,0,858,0,1944,0,1296,0,912,0,0,0,432,0,834,0,1886,0,3900,0,0,0,1953,0,1302,0,1955,0,42,0,0,0,1958,0,653,0,1959,0,1961,0,0,0,48,0,491,0,1310,0,198,0,0,0,210,0,12,0,1686,0,3942,0,0,0,1973,0,358,0,657,0,1914,0,0,0,1977,0,159,0,464,0,165,0,0,0,3966,0,1134,0,342,0,56,0,0,0,480,0,946,0,1326,0,852,0,0,0,1989,0,3988,0,306,0,726,0,0,0,570,0,105,0,500,0,87,0,0,0,4006,0,90,0,570,0,34,0,0,0,102,0,4018,0,268,0,3996,0,0,0,2013,0,624,0,644,0,108,0,0,0,366,0,576,0,288,0,930,0,0,0,630,0,2024,0,4050,0,192,0,0,0,4056,0,90,0,390,0,112,0,0,0,1722,0,312,0,1914,0,4072,0,0,0,675,0,2039,0,78,0,2040,0,0,0,660,0,1932,0,4090,0,22,0,0,0,240,0,4098,0,4098,0,186,0,0,0,111,0,1758,0,2055,0,1368,0,0,0,1958,0,2058,0,474,0,90,0,0,0,4126,0,2064,0,3888,0,1033,0,0,0,294,0,4138,0,20,0,1380,0,0,0,84,0,4140,0,1776,0,4152,0,0,0,2078,0,693,0,72,0,1980,0,0,0,1386,0,378,0,672,0,318,0,0,0,4176,0,198,0,336,0,1012,0,0,0,13,0,2030,0,42,0,1794,0,0,0,699,0,144,0,75,0,2097,0,0,0,300,0,660,0,4210,0,382,0,0,0,4216,0,4218,0,198,0,170,0,0,0,96,0,4228,0,2115,0,1968,0,0,0,666,0,702,0,1060,0,2121,0,0,0,120,0,606,0,108,0,1063,0,0,0,126,0,4258,0,4260,0,84,0,0,0,400,0,474,0,2135,0,1424,0,0,0,138,0,388,0,2139,0,2141,0,0,0,1428,0,2144,0,102,0,1053,0,0,0,1432,0,4296,0,176,0,330,0,0,0,232,0,690,0,2151,0,2034,0,0,0,2157,0,264,0,1036,0,390,0,0,0,4326,0,18,0,420,0,618,0,0,0,4336,0,4338,0,1446,0,84,0,0,0,594,0,4348,0,684,0,870,0,0,0,242,0,726,0,924,0,2181,0,0,0,198,0,256,0,690,0,1093,0,0,0,162,0,2100,0,336,0,486,0,0,0,265,0,18,0,2195,0,2090,0,0,0,314,0,533,0,81,0,48,0,0,0,336,0,551,0,200,0,735,0,0,0,630,0,4410,0,4420,0,4422,0,0,0,2088,0,714,0,30,0,30,0,0,0,1008,0,2112,0,2220,0,2220,0,0,0,4446,0,741,0,4450,0,120,0,0,0,4456,0,294,0,4458,0,4462,0,0,0,744,0,540,0,2096,0,630,0,0,0,66,0,1119,0,2240,0,249,0,0,0,96,0,2211,0,1494,0,1123,0,0,0,642,0,204,0,642,0,234,0,0,0,751,0,4482,0,1038,0,1504,0,0,0,2258,0,753,0,24,0,2261,0,0,0,4518,0,1938,0,1078,0,2265,0,0,0,348,0,528,0,126,0,174,0,0,0,2273,0,1516,0,15,0,1092,0,0,0,210,0,2208,0,2280,0,702,0,0,0,4566,0,2283,0,978,0,1072,0,0,0,198,0,90,0,4572,0,4582,0,0,0,138,0,96,0,2295,0,1530,0,0,0,2298,0,72,0,1113,0,2301,0,0,0,80,0,418,0,1092,0,1974,0,0,0,486,0,2220,0,924,0,66,0,0,0,660,0,1542,0,140,0,560,0,0,0,61,0,2319,0,48,0,2321,0,0,0,1548,0,7,0,4650,0,414,0,0,0,1552,0,4656,0,754,0,222,0,0,0,1074,0,924,0,1161,0,4672,0,0,0,2337,0,2339,0,75,0,222,0,0,0,756,0,468,0,4690,0,342,0,0,0,60,0,42,0,1566,0,4702,0,0,0,261,0,1104,0,672,0,4710,0,0,0,572,0,66,0,2360,0,2361,0,0,0,2268,0,1182,0,738,0,1183,0,0,0,1578,0,1014,0,430,0,720,0,0,0,92,0,4746,0,2375,0,672,0,0,0,1155,0,2379,0,4554,0,432,0,0,0,678,0,450,0,366,0,21,0,0,0,112,0,4698,0,2046,0,4782,0,0,0,2393,0,228,0,399,0,4792,0,0,0,90,0,2399,0,800,0,600,0,0,0,198,0,228,0,2256,0,802,0,0,0,4816,0,780,0,4818,0,78,0,0,0,201,0,438,0,805,0,4806,0,0,0,690,0,1209,0,782,0,2324,0,0,0,390,0,186,0,126,0,330,0,0,0,4854,0,336,0,972,0,1620,0,0,0,390,0,540,0,2435,0,442,0,0,0,1219,0,240,0,813,0,2304,0,0,0,540,0,2444,0,264,0,696,0,0,0,2378,0,2310,0,1092,0,1634,0,0,0,2100,0,1636,0,1227,0,4624,0,0,0,444,0,2459,0,18,0,819,0,0,0,378,0,195,0,4930,0,2466,0,0,0,4936,0,32,0,1620,0,4942,0,0,0,96,0,84,0,2475,0,42,0,0,0,413,0,252,0,110,0,708,0,0,0,4966,0,828,0,552,0,226,0,0,0,234,0,1146,0,1168,0,150,0,0,0,2493,0,1662,0,330,0,1664,0,0,0,2358,0,357,0,2499,0,2501,0,0,0,1668,0,626,0,1670,0,2502,0,0,0,1204,0,42,0,5020,0,1674,0,0,0,152,0,2438,0,126,0,2154,0,0,0,264,0,2519,0,2485,0,615,0,0,0,714,0,432,0,50,0,405,0,0,0,1164,0,5058,0,30,0,2460,0,0,0,2529,0,24,0,460,0,396,0,0,0,2538,0,423,0,1270,0,528,0,0,0,5086,0,726,0,5088,0,154,0,0,0,1698,0,5098,0,1700,0,1458,0,0,0,2553,0,390,0,2412,0,1704,0,0,0,336,0,853,0,2556,0,2484,0,0,0,5124,0,2442,0,366,0,2436,0,0,0,466,0,1710,0,1248,0,138,0,0,0,2573,0,90,0,48,0,5152,0,0,0,2565,0,66,0,198,0,1290,0,0,0,5166,0,861,0,110,0,246,0,0,0,2490,0,5178,0,78,0,280,0,0,0,18,0,5188,0,2492,0,576,0,0,0,433,0,2598,0,2226,0,462,0,0,0,210,0,372,0,1728,0,600,0,0,0,138,0,2448,0,2486,0,1740,0,0,0,2613,0,738,0,2615,0,5232,0,0,0,77,0,390,0,291,0,2226,0,0,0,234,0,1260,0,1276,0,816,0,0,0,750,0,1752,0,1052,0,414,0,0,0,2508,0,478,0,150,0,5272,0,0,0,879,0,2639,0,2640,0,2637,0,0,0,2480,0,105,0,6,0,429,0,0,0,5296,0,54,0,90,0,5302,0,0,0,420,0,5308,0,2576,0,66,0,0,0,204,0,2646,0,624,0,2661,0,0,0,1140,0,584,0,1776,0,1333,0,0,0,5328,0,252,0,756,0,24,0,0,0,2673,0,1782,0,2675,0,52,0,0,0,486,0,2552,0,2679,0,645,0,0,0,1788,0,174,0,130,0,297,0,0,0,846,0,162,0,5380,0,192,0,0,0,2693,0,1264,0,2691,0,5392,0,0,0,768,0,2699,0,490,0,900,0,0,0,1802,0,900,0,1158,0,2706,0,0,0,5416,0,5418,0,138,0,112,0,0,0,891,0,660,0,2715,0,5430,0,0,0,1359,0,42,0,2720,0,907,0,0,0,1254,0,2724,0,858,0,90,0,0,0,2544,0,442,0,42,0,1818,0,0,0,210,0,5466,0,547,0,420,0,0,0,1369,0,2739,0,756,0,2741,0,0,0,870,0,498,0,2448,0,915,0,0,0,154,0,414,0,5500,0,5502,0,0,0,2753,0,786,0,498,0,444,0,0,0,153,0,2759,0,345,0,786,0,0,0,5526,0,288,0,5530,0,502,0,0,0,336,0,2660,0,5538,0,330,0,0,0,903,0,2670,0,60,0,792,0,0,0,926,0,432,0,1353,0,2781,0,0,0,1314,0,1392,0,1854,0,2786,0,0,0,78,0,1194,0,5580,0,1860,0,0,0,75,0,5346,0,2795,0,1104,0,0,0,1344,0,508,0,933,0,1290,0,0,0,396,0,455,0,180,0,2805,0,0,0,40,0,1872,0,24,0,5622,0,0,0,880,0,432,0,2814,0,2730,0,0,0,939,0,2819,0,470,0,54,0,0,0,1882,0,804,0,5650,0,2826,0,0,0,5656,0,5658,0,144,0,606,0,0,0,354,0,5668,0,689,0,60,0,0,0,810,0,315,0,198,0,2841,0,0,0,506,0,316,0,30,0,1423,0,0,0,270,0,230,0,5700,0,1140,0,0,0,438,0,258,0,571,0,196,0,0,0,1429,0,126,0,2859,0,2784,0,0,0,2706,0,336,0,52,0,126,0,0,0,5736,0,5736,0,5740,0,5742,0,0,0,2460,0,5748,0,2835,0,522,0,0,0,36,0,1326,0,822,0,336,0,0,0,104,0,288,0,2772,0,550,0,0,0,1404,0,5778,0,690,0,5782,0,0,0,963,0,2478,0,965,0,1158,0,0,0,240,0,21,0,1450,0,276,0,0,0,5806,0,78,0,444,0,2906,0,0,0,138,0,506,0,5820,0,5814,0,0,0,2913,0,924,0,2352,0,306,0,0,0,96,0,2919,0,522,0,2921,0,0,0,5844,0,1462,0,1950,0,195,0,0,0,5856,0,270,0,5860,0,30,0,0,0,2933,0,5868,0,306,0,2514,0,0,0,2934,0,2939,0,2940,0,39,0,0,0,2436,0,150,0,168,0,1435,0,0,0,5896,0,2768,0,84,0,5902,0,0,0,534,0,2790,0,2816,0,648,0,0,0,480,0,2958,0,285,0,2961,0,0,0,5926,0,462,0,5922,0,464,0,0,0,5934,0,5938,0,456,0,282,0,0,0,936,0,1980,0,540,0,1984,0,0,0,66,0,116,0,993,0,132,0,0,0,432,0,966,0,426,0,180,0,0,0,966,0,1992,0,5980,0,960,0,0,0,2993,0,1456,0,2994,0,1380,0,0,0,999,0,2568,0,32,0,2772,0,0,0,858,0,3003,0,6010,0,78,0,0,0,182,0,462,0,1998,0,1422,0,0,0,210,0,6028,0,81,0,2010,0,0,0,3018,0,180,0,2586,0,3021,0,0,0,6046,0,2882,0,2016,0,3026,0,0,0,2016,0,328,0,252,0,966,0,0,0,3033,0,816,0,1398,0,6072,0,0,0,986,0,1013,0,3039,0,78,0,0,0,2028,0,761,0,2030,0,3042,0,0,0,66,0,954,0,1220,0,2864,0,0,0,1470,0,740,0,288,0,6112,0,0,0,3057,0,420,0,3060,0,78,0,0,0,278,0,3051,0,6130,0,1533,0,0,0,2736,0,438,0,132,0,6142,0,0,0,3069,0,42,0,1025,0,438,0,0,0,2990,0,342,0,60,0,79,0,0,0,1320,0,495,0,528,0,3086,0,0,0,420,0,498,0,882,0,2052,0,0,0,2948,0,6186,0,75,0,562,0,0,0,3098,0,3099,0,234,0,443,0,0,0,6204,0,2658,0,6210,0,108,0,0,0,6216,0,2070,0,6220,0,42,0,0,0,1434,0,2076,0,165,0,110,0,0,0,162,0,2928,0,1027,0,3120,0,0,0,6246,0,1041,0,414,0,78,0,0,0,6256,0,284,0,894,0,6262,0,0,0,1044,0,6268,0,1045,0,720,0,0,0,1569,0,66,0,570,0,1020,0,0,0,6286,0,990,0,6264,0,420,0,0,0,6294,0,94,0,6300,0,570,0,0,0,624,0,6300,0,3155,0,3074,0,0,0,3158,0,1540,0,42,0,3161,0,0,0,18,0,3164,0,486,0,3165,0,0,0,6336,0,2112,0,1488,0,6342,0,0,0,576,0,906,0,168,0,6352,0,0,0,162,0,3179,0,1590,0,36,0,0,0,6366,0,192,0,1518,0,1062,0,0,0,2730,0,2126,0,2124,0,1470,0,0,0,1596,0,6388,0,246,0,2130,0,0,0,78,0,1053,0,129,0,1008,0,0,0,3108,0,336,0,2136,0,286,0,0,0,990,0,2730,0,2140,0,6420,0,0,0,1071,0,2142,0,3132,0,918,0,0,0,390,0,184,0,1008,0,3024,0,0,0,306,0,1612,0,2150,0,189,0,0,0,586,0,6456,0,210,0,308,0,0,0,3108,0,924,0,3231,0,6472,0,0,0,336,0,90,0,270,0,30,0,0,0,498,0,306,0,1298,0,525,0,0,0,88,0,1056,0,294,0,1392,0,0,0,270,0,3102,0,3056,0,498,0,0,0,882,0,195,0,815,0,592,0,0,0,3180,0,1088,0,930,0,46,0,0,0,2178,0,1506,0,30,0,2178,0,0,0,1091,0,174,0,3275,0,6552,0,0,0,533,0,936,0,6561,0,3281,0,0,0,198,0,1642,0,6570,0,312,0,0,0,2192,0,1008,0,1316,0,3164,0,0,0,2820,0,598,0,1014,0,3114,0,0,0,549,0,3299,0,330,0,105,0,0,0,2202,0,1101,0,300,0,1552,0,0,0,1524,0,6618,0,6618,0,534,0,0,0,6486,0,2838,0,1044,0,198,0,0,0,474,0,1659,0,1596,0,24,0,0,0,2992,0,540,0,738,0,3326,0,0,0,474,0,6658,0,6660,0,2220,0,0,0,3248,0,54,0,2856,0,6672,0,0,0,202,0,3339,0,3120,0,405,0,0,0,6678,0,1672,0,6690,0,1056,0,0,0,180,0,84,0,6700,0,6702,0,0,0,288,0,6708,0,3354,0,168,0,0,0,1119,0,3359,0,138,0,3321,0,0,0,930,0,3363,0,546,0,3366,0,0,0,6736,0,1606,0,954,0,102,0,0,0,258,0,1584,0,546,0,2250,0,0,0,1624,0,1125,0,1690,0,161,0,0,0,132,0,966,0,60,0,156,0,0,0,1350,0,6778,0,1356,0,144,0,0,0,88,0,120,0,679,0,6792,0,0,0,2910,0,522,0,3399,0,3401,0,0,0,2268,0,618,0,966,0,27,0,0,0,400,0,6816,0,3222,0,6822,0,0,0,3413,0,6828,0,594,0,6832,0,0,0,273,0,2928,0,855,0,228,0,0,0,830,0,3420,0,240,0,132,0,0,0,6856,0,6498,0,762,0,6862,0,0,0,108,0,6868,0,3435,0,1092,0,0,0,1518,0,1146,0,2946,0,3441,0,0,0,3360,0,3403,0,6888,0,1680,0,0,0,198,0,6898,0,1122,0,522,0,0,0,1151,0,966,0,3455,0,1110,0,0,0,3458,0,48,0,576,0,462,0,0,0,6924,0,390,0,28,0,231,0,0,0,990,0,6912,0,630,0,130,0,0,0,3473,0,6948,0,330,0,816,0,0,0,1737,0,3479,0,3480,0,30,0,0,0,6966,0,132,0,6970,0,1098,0,0,0,6976,0,498,0,534,0,6982,0,0,0,48,0,420,0,3495,0,54,0,0,0,1749,0,1749,0,1750,0,3404,0,0,0,42,0,567,0,90,0,3506,0,0,0,7014,0,7018,0,1392,0,2340,0,0,0,1171,0,630,0,572,0,540,0,0,0,1695,0,391,0,1173,0,503,0,0,0,6804,0,234,0,32,0,3525,0,0,0,7056,0,180,0,3366,0,252,0,0,0,285,0,7068,0,3534,0,214,0,0,0,336,0,3539,0,96,0,1179,0,0,0,558,0,1104,0,1518,0,215,0,0,0,3450,0,1140,0,7074,0,7102,0,0,0,1122,0,7108,0,546,0,2370,0,0,0,646,0,1008,0,3560,0,3344,0,0,0,1018,0,594,0,264,0,3054,0,0,0,180,0,638,0,192,0,1428,0,0,0,1020,0,2382,0,275,0,3410,0,0,0,560,0,3579,0,30,0,252,0,0,0,2388,0,1749,0,140,0,1791,0,0,0,7176,0,552,0,3486,0,326,0,0,0,3593,0,78,0,3312,0,7192,0,0,0,3597,0,3432,0,378,0,2058,0,0,0,7206,0,3564,0,1030,0,1803,0,0,0,618,0,7218,0,3444,0,3480,0,0,0,72,0,7228,0,1032,0,7230,0,0,0,402,0,126,0,834,0,3621,0,0,0,7246,0,658,0,7248,0,74,0,0,0,870,0,240,0,104,0,7236,0,0,0,546,0,7266,0,220,0,1038,0,0,0,3438,0,700,0,1818,0,3641,0,0,0,1038,0,294,0,1738,0,48,0,0,0,2432,0,810,0,3108,0,1188,0,0,0,3653,0,7308,0,1218,0,1190,0,0,0,135,0,1686,0,3660,0,915,0,0,0,3440,0,348,0,1466,0,611,0,0,0,308,0,890,0,7338,0,1572,0,0,0,195,0,7348,0,1225,0,126,0,0,0,1050,0,222,0,432,0,99,0,0,0,598,0,1842,0,162,0,8,0,0,0,7374,0,1794,0,660,0,3498,0,0,0,1804,0,7380,0,3492,0,7392,0,0,0,852,0,1050,0,411,0,224,0,0,0,2466,0,105,0,7410,0,96,0,0,0,2472,0,2472,0,180,0,570,0,0,0,636,0,1584,0,1857,0,7432,0,0,0,33,0,903,0,1062,0,3717,0,0,0,338,0,570,0,7450,0,1792,0,0,0,7456,0,7458,0,828,0,3504,0,0,0,1170,0,96,0,30,0,1794,0,0,0,3738,0,621,0,748,0,1068,0,0,0,7486,0,1872,0,678,0,1218,0,0,0,1008,0,7498,0,576,0,60,0,0,0,3753,0,834,0,84,0,682,0,0,0,3758,0,136,0,1188,0,3761,0,0,0,192,0,1882,0,3536,0,1215,0,0,0,2512,0,1074,0,7540,0,198,0,0,0,3773,0,2516,0,3771,0,246,0,0,0,228,0,3779,0,1890,0,630,0,0,0,1518,0,7308,0,3696,0,631,0,0,0,7576,0,78,0,342,0,7582,0,0,0,756,0,1084,0,3795,0,138,0,0,0,1855,0,1776,0,230,0,1267,0,0,0,7606,0,1086,0,1218,0,110,0,0,0,2538,0,1800,0,508,0,198,0,0,0,3668,0,7626,0,1758,0,32,0,0,0,3270,0,3819,0,1269,0,3821,0,0,0,7644,0,1912,0,546,0,1275,0,0,0,90,0,198,0,3726,0,1248,0,0,0,80,0,284,0,639,0,7672,0,0,0,639,0,3288,0,1920,0,294,0,0,0,7686,0,696,0,7690,0,546,0,0,0,3738,0,7698,0,1200,0,7702,0,0,0,366,0,1776,0,700,0,7704,0,0,0,1929,0,615,0,3306,0,1287,0,0,0,7726,0,3770,0,234,0,18,0,0,0,7734,0,3780,0,860,0,924,0,0,0,420,0,270,0,3696,0,7752,0,0,0,1939,0,3879,0,198,0,3324,0,0,0,7758,0,304,0,612,0,777,0,0,0,12,0,2592,0,150,0,1260,0,0,0,1794,0,2596,0,546,0,7792,0,0,0,3696,0,708,0,1876,0,7344,0,0,0,30,0,72,0,424,0,300,0,0,0,7816,0,558,0,234,0,7822,0,0,0,3912,0,7828,0,95,0,186,0,0,0,1840,0,198,0,56,0,330,0,0,0,522,0,3818,0,2616,0,3926,0,0,0,2592,0,140,0,1122,0,7860,0,0,0,3933,0,420,0,1232,0,7872,0,0,0,3938,0,3939,0,105,0,3941,0,0,0,42,0,3234,0,606,0,1314,0,0,0,1924,0,7896,0,7900,0,564,0,0,0,3953,0,718,0,3942,0,960,0,0,0,84,0,3959,0,3916,0,414,0,0,0,7926,0,3960,0,102,0,3966,0,0,0,7936,0,3728,0,882,0,1794,0,0,0,441,0,7948,0,3975,0,30,0,0,0,216,0,378,0,3762,0,3981,0,0,0,3840,0,102,0,7968,0,528,0,0,0,2658,0,52,0,3806,0,7974,0,0,0,1134,0,7986,0,780,0,2664,0,0,0,726,0,1260,0,126,0,975,0,0,0,624,0,2002,0,2670,0,1335,0,0,0,8016,0,1458,0,264,0,560,0,0,0,1276,0,30,0,669,0,1932,0,0,0,414,0,4019,0,336,0,1146,0,0,0,618,0,447,0,3936,0,4026,0,0,0,3450,0,8058,0,8058,0,122,0,0,0,42,0,8068,0,1152,0,594,0,0,0,490,0,4038,0,2020,0,232,0,0,0,8086,0,1348,0,1260,0,4046,0,0,0,8094,0,132,0,1620,0,24,0,0,0,66,0,1872,0,811,0,180,0,0,0,2029,0,352,0,1353,0,4061,0,0,0,378,0,246,0,1978,0,4065,0,0,0,442,0,2712,0,3486,0,3824,0,0,0,4073,0,28,0,18,0,3930,0,0,0,1359,0,495,0,1020,0,1359,0,0,0,2722,0,1164,0,8170,0,742,0,0,0,48,0,8178,0,324,0,3486,0,0,0,2046,0,3870,0,1365,0,2730,0,0,0,1170,0,4095,0,1334,0,630,0,0,0,3948,0,4104,0,528,0,1995,0,0,0,738,0,8218,0,2740,0,8220,0,0,0,432,0,30,0,4115,0,8232,0,0,0,4118,0,318,0,165,0,4121,0,0,0,2748,0,112,0,222,0,1170,0,0,0,3938,0,8256,0,250,0,8262,0,0,0,3540,0,8268,0,459,0,8272,0,0,0,660,0,3888,0,546,0,150,0,0,0,8286,0,459,0,8290,0,2073,0,0,0,8296,0,1344,0,2766,0,3762,0,0,0,630,0,3558,0,4155,0,1296,0,0,0,462,0,4002,0,78,0,420,0,0,0,54,0,1041,0,8328,0,96,0,0,0,198,0,4020,0,1314,0,2754,0,0,0,3920,0,66,0,3576,0,8352,0,0,0,120,0,642,0,4176,0,4181,0,0,0,8364,0,4184,0,380,0,93,0,0,0,8376,0,126,0,1904,0,164,0,0,0,599,0,8388,0,699,0,108,0,0,0,4185,0,339,0,15,0,4200,0,0,0,600,0,1401,0,1938,0,4094,0,0,0,3978,0,2806,0,600,0,8422,0,0,0,2067,0,8428,0,4215,0,936,0,0,0,174,0,672,0,4026,0,4221,0,0,0,8446,0,1680,0,2808,0,689,0,0,0,8454,0,192,0,2820,0,30,0,0,0,4233,0,8460,0,294,0,228,0,0,0,1806,0,1380,0,768,0,3984,0,0,0,990,0,978,0,606,0,1332,0,0,0,2044,0,2832,0,8500,0,386,0,0,0,4140,0,462,0,2127,0,8512,0,0,0,3984,0,3648,0,710,0,4257,0,0,0,2842,0,4263,0,288,0,858,0,0,0,8536,0,2846,0,72,0,8542,0,0,0,6,0,1394,0,4016,0,2850,0,0,0,693,0,2133,0,3666,0,4281,0,0,0,1974,0,90,0,408,0,4286,0,0,0,8568,0,2046,0,2860,0,8580,0,0,0,345,0,204,0,770,0,660,0,0,0,2149,0,1433,0,1380,0,3684,0,0,0,450,0,1076,0,1404,0,756,0,0,0,246,0,624,0,696,0,8622,0,0,0,4313,0,2876,0,72,0,1056,0,0,0,4317,0,1053,0,4320,0,231,0,0,0,8646,0,1395,0,30,0,2032,0,0,0,786,0,618,0,2886,0,8662,0,0,0,4293,0,8668,0,924,0,1218,0,0,0,723,0,786,0,868,0,1368,0,0,0,48,0,2172,0,8688,0,4346,0,0,0,222,0,8698,0,336,0,2898,0,0,0,4353,0,8706,0,420,0,8712,0,0,0,4158,0,4359,0,432,0,60,0,0,0,8724,0,84,0,8730,0,105,0,0,0,2912,0,8730,0,8740,0,624,0,0,0,4373,0,672,0,1458,0,8752,0,0,0,414,0,4140,0,876,0,462,0,0,0,398,0,39,0,3738,0,705,0,0,0,4290,0,22,0,8778,0,8782,0,0,0,84,0,368,0,4292,0,8784,0,0,0,1386,0,1254,0,1014,0,1467,0,0,0,8806,0,4202,0,396,0,3774,0,0,0,8814,0,8818,0,8820,0,2064,0,0,0,96,0,324,0,4415,0,88,0,0,0,4418,0,4419,0,420,0,21,0,0,0,8838,0,553,0,2158,0,678,0,0,0,208,0,984,0,8860,0,8862,0,0,0,4433,0,1260,0,4434,0,4194,0,0,0,804,0,2046,0,2173,0,1242,0,0,0,8886,0,4443,0,4176,0,2223,0,0,0,30,0,202,0,1386,0,4284,0,0,0,1113,0,4350,0,198,0,2970,0,0,0,30,0,495,0,810,0,1487,0,0,0,1456,0,144,0,228,0,2233,0,0,0,2970,0,1914,0,2980,0,30,0,0,0,4268,0,234,0,4475,0,1278,0,0,0,78,0,4080,0,1428,0,4481,0,0,0,420,0,4484,0,8970,0,1494,0,0,0,4370,0,120,0,3846,0,690,0,0,0,126,0,44,0,243,0,4048,0,0,0,4497,0,4499,0,1125,0,1500,0,0,0,3002,0,18,0,9010,0,2253,0,0,0,210,0,4340,0,480,0,276,0,0,0,4176,0,9028,0,820,0,9030,0,0,0,1290,0,4290,0,1130,0,4521,0,0,0,4428,0,4524,0,1290,0,822,0,0,0,3018,0,9058,0,240,0,234,0,0,0,4533,0,9066,0,4416,0,210,0,0,0,2184,0,1296,0,252,0,2190,0,0,0,696,0,2220,0,10,0,432,0,0,0,826,0,3024,0,4302,0,9102,0,0,0,3900,0,9108,0,759,0,2100,0,0,0,2277,0,276,0,1302,0,1140,0,0,0,3042,0,4272,0,198,0,1522,0,0,0,9136,0,18,0,138,0,1110,0,0,0,1524,0,3918,0,1525,0,9072,0,0,0,4578,0,105,0,229,0,336,0,0,0,748,0,559,0,9162,0,4586,0,0,0,198,0,264,0,3060,0,204,0,0,0,4593,0,3060,0,12,0,2212,0,0,0,2160,0,4599,0,1533,0,4601,0,0,0,270,0,2302,0,300,0,123,0,0,0,708,0,438,0,9220,0,2200,0,0,0,4613,0,838,0,720,0,3954,0,0,0,1539,0,4619,0,4620,0,234,0,0,0,330,0,4623,0,812,0,486,0,0,0,9256,0,2254,0,2646,0,2262,0,0,0,4632,0,330,0,168,0,84,0,0,0,4638,0,927,0,928,0,1547,0,0,0,150,0,1326,0,162,0,2323,0,0,0,3096,0,1456,0,910,0,1326,0,0,0,565,0,4452,0,4655,0,1518,0,0,0,726,0,4659,0,42,0,4661,0,0,0,444,0,4410,0,210,0,720,0,0,0,3112,0,282,0,9340,0,9342,0,0,0,2154,0,3116,0,1557,0,4554,0,0,0,4677,0,3990,0,66,0,156,0,0,0,1008,0,4671,0,9370,0,102,0,0,0,9376,0,4592,0,2262,0,426,0,0,0,1332,0,1140,0,4695,0,60,0,0,0,81,0,30,0,624,0,1567,0,0,0,2244,0,9312,0,9408,0,4706,0,0,0,168,0,554,0,9420,0,3132,0,0,0,856,0,96,0,4715,0,1048,0,0,0,4718,0,1573,0,4716,0,630,0,0,0,1518,0,26,0,726,0,264,0,0,0,1344,0,3150,0,9460,0,3154,0,0,0,4733,0,2224,0,30,0,9472,0,0,0,1458,0,4739,0,1494,0,756,0,0,0,2314,0,1581,0,9490,0,862,0,0,0,9496,0,1914,0,9498,0,336,0,0,0,72,0,768,0,1585,0,450,0,0,0,765,0,1494,0,595,0,2332,0,0,0,2040,0,366,0,864,0,2383,0,0,0,816,0,9538,0,1932,0,636,0,0,0,4773,0,1908,0,955,0,1160,0,0,0,4518,0,286,0,177,0,520,0,0,0,1062,0,4098,0,4496,0,87,0,0,0,780,0,510,0,66,0,222,0,0,0,4793,0,1554,0,1518,0,2340,0,0,0,456,0,1540,0,4800,0,288,0,0,0,246,0,4803,0,2058,0,267,0,0,0,4698,0,3206,0,3204,0,9622,0,0,0,4812,0,9628,0,4815,0,234,0,0,0,418,0,1296,0,465,0,4821,0,0,0,438,0,603,0,3216,0,294,0,0,0,252,0,2226,0,1380,0,9660,0,0,0,1380,0,438,0,4572,0,1136,0,0,0,2419,0,1613,0,1380,0,1540,0,0,0,3228,0,346,0,440,0,4833,0,0,0,9696,0,780,0,1188,0,1560,0,0,0,4560,0,72,0,738,0,882,0,0,0,195,0,4859,0,4860,0,462,0,0,0,280,0,4554,0,786,0,2433,0,0,0,318,0,9738,0,4560,0,9742,0,0,0,1026,0,9748,0,1386,0,9750,0,0,0,886,0,1626,0,2373,0,750,0,0,0,9766,0,4884,0,9768,0,336,0,0,0,3258,0,42,0,9780,0,3258,0,0,0,4893,0,150,0,4895,0,1398,0,0,0,96,0,35,0,1782,0,4901,0,0,0,1398,0,576,0,9810,0,1635,0,0,0,9816,0,9810,0,660,0,414,0,0,0,1185,0,9828,0,336,0,9832,0,0,0,819,0,4919,0,54,0,192,0,0,0,1596,0,462,0,9850,0,4814,0,0,0,9856,0,3286,0,774,0,96,0,0,0,66,0,1610,0,4935,0,9864,0,0,0,1968,0,132,0,30,0,4941,0,0,0,9886,0,420,0,234,0,1140,0,0,0,9894,0,468,0,12,0,3300,0,0,0,4953,0,3294,0,208,0,4730,0,0,0,690,0,108,0,1653,0,4961,0,0,0,9918,0,1241,0,9930,0,42,0,0,0,522,0,3312,0,1988,0,1620,0,0,0,588,0,9948,0,795,0,804,0,0,0,1659,0,4752,0,474,0,1215,0,0,0,9966,0,4983,0,2262,0,554,0,0,0,302,0,4688,0,9972,0,4884,0,0,0,2496,0,4278,0,1632,0,3330,0,0,0,192,0,36};
int n;
while(scanf("%d",&n)==1){
    printf("%d\n",a[n]);
}
}
