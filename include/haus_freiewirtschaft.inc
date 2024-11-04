forward burgershot();
forward speisekarte(playerid);
forward essen(playerid, listitem, bsID);
forward freiew_response(playerid, dialogid, response, listitem, inputtext[]);
forward freiew_pickups(playerid,pickupid);
forward giveshop(bsID,bestand,price);
forward playereat(playerid,Float:health,kind,time);
forward freiew_waehleskin(playerid,classid);
forward freiw_skinchange(playerid);

new Float:shopsinter[][11]=
/*
 [0] => interid
 [1] => posX pickup
 [2] => posY pickup
 [3] => posZ pickup
 [4] => posX exit
 [5] => posY exit
 [6] => posZ exit
 [7] => posY enterplayer
 [8] => posY enterplayer
 [9] => posY enterplayer
 [10] => facing player
*/
{ 
  {10.0,376.0,-68.0,1002.0,363.6,-74.8,1001.5,367.76, -73.53, 1001.50, 302.03}, //BS Interrior
  {9.0,371.31, -6.21, 1001.85,364.70, -11.59, 1001.85,366.36, -8.64, 1001.85, 285.0}, //CB Interior
  {5.0,375.91, -119.62, 1001.49,372.31, -133.52, 1001.49,370.75, -129.42, 1001.49, 350.0}, //PH
  {17.0,499.87, -18.75, 1000.67,493.49, -24.96, 1000.67,489.86, -22.91, 1000.67, 318.34}, //Club
  {11.0,490.43, -74.22, 998.75,502.03, -67.56, 998.75,501.63, -72.19, 998.75, 170.0}, //Bar
  {1.0,443.57, -7.73, 1000.73,453.41, -18.06, 1001.13,451.99, -13.07, 1000.73,0.0}, //Restaurant
  {1.0,678.09, -451.80, -25.41,681.45, -451.16, -25.61,677.76, -463.53, -25.61, 360.0}, // Welcome Pump
  {4.0, 450.41, -83.65, 999.55,460.44, -89.00, 999.55,453.81, -90.74, 999.55, 52.03}, // Jays Diner
  {18.0,-225.03, 1404.20, 27.77,-229.29, 1401.05, 27.76,-226.00, 1410.31, 27.77, 187.35}, //Lil Probe Inn
  {17.0,379.32, -190.44, 1000.63,377.01, -193.30, 1000.63, 376.04, -178.73, 1000.63, 209.95}, //Donat Lдden
  {15.0,217.74, -98.32, 1005.25,207.65, -111.26, 1005.13, 205.64, -105.54, 1005.13,300.0}, //Binco
  { 3.0,200.24,-131.29, 1003.50,207.46, -140.37, 1003.50, 206.46, -137.03, 1002.87,356.26}, //Prolaps
  {18.0,181.35, -87.83, 1002.02,161.25,  -97.11, 1001.80, 161.39,  -93.16, 1001.81,300.0}, //zip
  { 1.0,214.21, -41.63, 1002.02,203.79,  -50.66, 1001.80, 203.05,  -46.78, 1001.80, 348.40}, //Suburban
  { 5.0,209.45,  -7.94, 1005.21,227.35,   -8.32, 1002.21, 222.88,   -8.72, 1002.21, 90.0}, //Victim
  {14.0,216.01,-155.70, 1000.52,204.21, -168.86, 1000.52, 204.17, -164.48, 1000.52,  0.0},  //DiederSachs
  {17.0,-13.65,-170.57, 1003.54,-26.19, -188.20, 1003.54, -21.45, -185.41, 1003.54,  0.0},  //24-7 1
  {10.0, -0.12,  -3.27, 1003.54,  6.19,  -31.42, 1003.54,   8.20,  -28.65, 1003.54, 26.70}, //24-7 2
  {18.0,-24.65, -74.70, 1003.54,-30.96,  -92.00, 1003.54, -33.57,  -90.80, 1003.54,  0.0},  //24-7 3
  {16.0,-24.82,-123.40, 1003.54,-25.90, -141.55, 1003.54, -29.55, -139.81, 1003.54,336.16}, //24-7 4
  { 4.0,-29.09,  -2.80, 1003.55,-27.25,  -31.76, 1003.55, -31.33,  -28.40, 1003.55,357.49}, //24-7 5
  { 6.0,-23.50, -55.63, 1003.54,-27.06,  -58.26, 1003.54, -29.96,  -56.73, 1003.54,304.82},  //24-7 6
  { 3.0,-104.47, -10.83, 1000.71,-100.33, -25.03, 1000.71,-107.50, -22.05, 1000.71,  0.0},  //Sexshop
  {	2.0,1211.21, -12.23, 1000.92,1204.97, -13.80, 1000.92,1204.89, -9.31, 1000.92, 177.63},  // Stripclub
  { 3.0,1212.07, -33.74, 1000.95,1211.87, -25.87, 1000.95,1213.84, -28.69, 1000.95, 151.92}, // Big spread ranch
  { 3.0,-2655.13, 1404.76, 906.27,-2636.99, 1402.28, 906.46,-2635.82, 1406.51, 906.46, 6.60}, // VIP Club Pleasure domes
  { 1.0, 296.79, -38.51, 1001.51,285.50, -41.80, 1001.51, 285.48, -37.47, 1001.51, 290.75}, // Ammunation 1 gross
  { 4.0, 295.91, -80.80, 1001.51,285.89, -86.78, 1001.52,285.99, -81.45, 1001.51, 312.05}, //Ammunation 2 gross
  { 6.0, 288.36, -106.77, 1001.51,296.65, -112.06, 1001.51,298.12, -108.57, 1001.51, 78.38}, //Ammunation 3 klein 
  { 7.0, 307.38, -141.46, 999.60, 315.45, -143.66, 999.60,314.88, -139.15, 999.60, 74.64}, //Ammunation 4 super gross
  { 6.0, 312.20, -165.50, 999.60,316.21, -169.87, 999.60,318.27, -163.91, 999.60, 93.08} //Ammunation 5 klein
};

new Float:shopsenter[][9]=
/*
 [0] => dbid
 [1] => posX entry
 [2] => posY entry
 [3] => posZ entry
 [4] => interior
 [5] => posX exit
 [6] => posY exit
 [7] => posZ exit
*/
{
  {1.0, 1199.0, -918.00,43.00, 0.0, 1199.0, -922.0,44.0,1.0}, // BS anfang
  {2.0,  810.8,-1616.18,13.50, 0.0,  813.8,-1616.0,13.5,2.0}, 
  {3.0,-2335.9, -166.93,35.55, 0.0,-2334.1, -168.9,35.3,3.0}, 
  {4.0,-1911.9,  828.47,35.18, 0.0,-1909.54,830.82,35.17,4.0},
  {5.0,-2356.8, 1008.01,51.00, 0.0,-2357.18,1004.58,50.9,5.0},
  {6.0, 1139.5, 2080.94,11.10, 0.0,1138.55,2083.74,11.1,6.0},
  {7.0, 2170.0, 2795.54,10.82, 0.0,2173.07,2795.54,10.82,7.0},
  {8.0, 1873.3, 2071.65,11.10, 0.0,1876.8,2071.65,11.1,8.0},
  {9.0, 2366.3, 2071.03,10.82, 0.0,2366.35,2066.43,10.82,9.0},
  {10.0,2471.8, 2034.24,11.10, 0.0,2468.9,2034.24,10.82,10.0}, // BS ende
  {11.0,2398.1,-1899.01,13.54, 1.0,2397.99, -1895.45, 13.38,1.0}, //CB anfang
  {12.0,2420.3,-1509.94,24.00, 1.0,2423.24, -1509.71, 23.99,2.0},
  {13.0,-2154.8,-2460.4,30.8,  1.0,-2152.78, -2462.53, 30.84,3.0},
  {14.0,-2671.13,257.9, 4.6 ,  1.0,-2671.58, 262.46, 4.63,4.0},
  {15.0,-1817.19,618.59,35.17, 1.0,-1816.25, 614.99, 35.17,5.0},
  {16.0,-1213.64, 1830.17,41.9,1.0,-1210.47, 1833.09, 41.92,6.0},
  {17.0,172.78, 1177.32, 14.75,1.0,171.56, 1174.19, 14.75,7.0},
  {18.0,2638.38, 1671.96,11.02,1.0,2634.41, 1672.72, 11.02,8.0},
  {19.0,2393.10, 2042.04,10.82,1.0,2393.19, 2045.46, 10.82,9.0},
  {20.0,2102.35, 2228.56, 11.02,1.0,2084.37, 2220.84, 10.82,10.0},
  {21.0,2837.98, 2407.47, 11.06,1.0,2106.97, 2228.93, 11.02,11.0}, // CB ende
  {22.0,2105.42, -1806.41, 13.55,2.0,2100.71, -1806.57, 13.55,1.0}, //PH anfang
  {23.0,2332.40, 75.04, 26.62,2.0,2334.73, 74.75, 26.48,2.0},
  {24.0,1367.58, 248.10, 19.56,2.0,1364.44, 249.82, 19.56,3.0},
  {25.0,202.98, -202.49, 1.57,2.0,200.98, -202.49, 1.57,4.0},
  {26.0,-1808.62, 945.56, 24.89,2.0,-1806.54, 943.46, 24.89,5.0},
  {27.0,-1721.41, 1359.24, 7.18,2.0,-1723.75, 1358.66, 7.18,6.0},
  {28.0,2638.78, 1849.93, 11.02,2.0,2635.55, 1850.15, 11.02,7.0},
  {29.0,2083.60, 2224.55, 11.02,2.0,2082.73, 2222.56, 10.82,8.0},
  {30.0,2351.50, 2533.62, 10.82,2.0,2351.37, 2530.63, 10.82,9.0},
  {31.0,2756.93, 2477.15, 11.06,2.0,2755.66, 2475.20, 11.06,10.0}, //PH ende
  {32.0,1837.03, -1682.17, 13.32,3.0,1830.72, -1683.94, 13.54,1.0}, // Club Alhambra LS
  {33.0,2310.02, -1643.54, 14.82,4.0,2309.94, -1647.32, 14.82,1.0}, // Bar Ten Green Bottles LS
  {34.0,2851.12, -1532.35, 11.09,3.0,2855.12, -1532.35, 11.09,2.0}, //Club East Beach
  {35.0,386.62, -1817.91, 7.84,3.0,383.40, -1817.41, 7.83,3.0}, //Club Santa Maria Beach
  {36.0,574.34, -1386.05, 14.35,5.0,574.62, -1388.68, 14.32,1.0}, // Restaurant Rodeo
  {37.0,681.13, -473.34, 16.53,6.0,681.55, -476.46, 16.33,1.0}, // Bar Welcome Pump
  {38.0,293.33, -195.54, 1.77, 5.0 ,287.37, -194.67, 1.42,2.0}, // restaurant Blueberry
  {39.0,-2242.32, -87.64, 35.32,4.0,-2246.41, -87.89, 35.32,2.0}, //Bar Mistys
  {40.0,-2463.58, 131.87, 35.17,5.0,-2458.25, 135.23, 35.17,3.0}, // Restaurant Hotel
  {41.0,-2550.71, 193.67, 6.22,3.0,-2553.23, 192.56, 6.12,4.0}, //Club Gaydor Station
  {42.0,-2524.49, 1216.15, 37.66,4.0,-2519.95, 1216.24, 37.42,3.0}, //Diner Jumper Hollow
  {43.0,-1941.12, 2379.05, 49.69,7.0,-1938.23, 2381.04, 49.49,1.0}, //Jays Diner
  {44.0,-857.73, 1535.51, 22.58,5.0,-857.73, 1537.51, 22.58,4.0}, //Steakhouse Beef Grill
  {45.0,-89.59, 1378.16, 10.46,8.0,-85.99, 1378.59, 10.27,1.0}, //Lil Probe Inn
  {46.0,-53.96, 1188.74, 19.35,5.0,-53.29, 1190.93, 19.35,5.0}, //Restaurant Fort Carson
  {47.0,2507.51, 1242.41, 10.82,3.0,2507.42, 1246.05, 10.82,5.0},//Club Come-a-lot
  {48.0,2369.19, 1984.28, 10.82,5.0,2366.51, 1981.83, 10.81,6.0},//Venturas Steakhouse
  {49.0,2441.13, 2065.48, 10.82,4.0,2442.03, 2061.15, 10.82,4.0},//Bar The Craw
  {50.0,2490.04, 2065.25, 10.82,5.0,2489.77, 2063.00, 10.82,7.0},//Restaurant Vice
  {51.0,1694.30, 2208.92, 11.06,5.0,1695.23, 2205.73, 10.82,8.0},//Steakhouse Venturas Strip
  {52.0,1376.83, 2328.03, 10.82,5.0,1379.97, 2328.56, 10.82,9.0}, // Restaurant Red Sands
  {53.0,1038.30, -1340.73, 13.74,9.0,1038.46, -1336.40, 13.55,1.0}, // Donut Jins Sticky Ring LS
  {54.0,-144.01, 1224.39, 19.89,9.0,-144.73, 1220.96, 19.73,2.0}, // Donut King Ring LV
  {55.0,2244.56, -1665.61, 15.47,10.0,2244.96, -1662.39, 15.46,1.0}, // Binco LS
  {56.0,-2374.32, 910.51, 45.44,10.0,-2377.55, 909.44, 45.44,2.0}, //Binco SF
  {57.0,1657.03, 1733.43, 10.82,10.0,1653.16, 1733.57, 10.82,3.0}, // Binco LV Airport
  {58.0,2102.05, 2257.05, 11.02,10.0,2106.14, 2257.68, 11.02,4.0}, // Binco LV Strip
  {59.0,499.38, -1360.57, 16.36,11.0,501.56, -1356.89, 16.13,1.0}, //Prolaps LS
  {60.0,2826.06, 2407.58, 11.06,11.0,2823.14, 2406.78, 11.06,2.0}, //Prolaps LV
  {61.0,1456.32, -1137.73, 23.94,12.0,1460.15, -1141.95, 24.39,1.0}, //Zip LS
  {62.0,-1882.33, 866.57, 35.17,12.0,-1887.57, 862.52, 35.16,2.0}, //Zip SF
  {63.0,2572.05, 1904.94, 11.02,12.0,2572.67, 1900.67, 11.02,3.0}, //Zip LV
  {64.0,2090.97, 2224.41, 11.02,12.0,2091.10, 2217.83, 10.82,4.0},  //Zip LV strip
  {65.0,2112.70, -1211.45, 23.96,13.0,2113.06, -1215.01, 23.96,1.0}, //Suburban LS
  {66.0,-2490.21, -29.04, 25.61,13.0,-2494.41, -29.90, 25.76,2.0}, //Suburban SF
  {67.0,2779.75, 2453.76, 11.06,13.0,2776.05, 2452.01, 11.06,3.0},  //Suburban LV
  {68.0,461.70, -1500.80, 31.04,14.0,457.70, -1501.96, 31.03,1.0},  //Victim LS
  {69.0,-1694.48, 951.82, 24.89,14.0,-1698.22, 947.36, 24.89,2.0},  //Victim SF
  {70.0,2802.89, 2430.75, 11.06,14.0,2799.65, 2428.96, 11.06,3.0},   //Victim LV
  {71.0,454.23, -1478.07, 30.81,15.0,451.33, -1479.09, 30.81,1.0}, //Didersachs
  {72.0,-1562.20, -2733.45, 48.74,16.0,-1560.20, -2735.57, 48.74,1.0}, //24-7 Whetstone SF
  {73.0,1000.59, -919.93, 42.32,17.0,998.57, -919.81, 42.17,1.0}, // 24-7 Temple LS
  {74.0,1315.74, -897.68, 39.57,17.0,1315.15, -900.97, 39.57,2.0}, // 24-7 Mulholland LS
  {75.0,1352.24, -1759.25, 13.50,18.0,1351.22, -1755.30, 13.35,1.0}, // 24-7 Commerce LS
  {76.0,1833.77, -1842.60, 13.57,18.0,1828.70, -1841.69, 13.57,2.0}, //24-7 Idlewood LS
  {77.0,-180.73, 1035.00, 19.74,19.0,-185.04, 1034.30, 19.74,1.0}, // 24-7 Fort Carson LV
  {78.0,1937.70, 2307.15, 10.82,19.0,1932.52, 2307.27, 10.82,2.0}, // 24-7 Redsands East LV
  {79.0,2097.61, 2224.70, 11.02,20.0,2097.92, 2222.58, 10.82,1.0}, // 24-7 Emerals Isle LV 
  {80.0,2247.93, 2396.33, 10.82,20.0,2247.54, 2399.47, 10.82,2.0}, // 24-7 Roca Escalante LV 
  {81.0,2194.94, 1991.01, 12.29,20.0,2191.33, 1989.65, 11.69,3.0}, // 24-7 Starfish Casino LV 
  {82.0,2452.55, 2064.89, 10.82,21.0,2453.10, 2059.83, 10.82,1.0}, // 24-7 Old Venturas Strip LV 
  {83.0,2547.03, 1972.14, 10.82,21.0,2545.96, 1963.85, 10.82,2.0}, // 24-7 Julius Thruway LV 
  {84.0,2884.38, 2453.67, 11.06,21.0,2888.95, 2451.26, 10.82,3.0},  // 24-7 Creek LV
  {85.0,2085.11, 2074.25, 11.05,22.0,2088.53, 2074.89, 10.82,4.0}, //Sex shop LV
  {86.0,2421.49, -1219.39, 25.55,23.0,2421.49, -1222.65, 25.34,1.0}, // Strip Club LS The Pig Pen
  {87.0,2543.10,  1024.89, 10.82,23.0,2543.36,  1021.00, 10.82,2.0}, // Strip Club LV Nude Strippers Daily
  {88.0,2506.91, 2120.28, 10.83,23.0,2507.09, 2125.54, 10.82,3.0}, // Strip Club LV Live Nude Girls
  {89.0,693.64, 1967.68, 5.53,24.0,693.98, 1964.06, 5.53,1.0}, //Big Spread Ranch
  {90.0,-2624.82, 1412.72, 7.09,25.0,-2623.37, 1409.19, 7.10,1.0}, // VIP Club Pleasure domes
  {91.0,-2626.10, 208.23, 4.81,26.0,-2626.48, 212.11, 4.60,1.0}, //Ammunation Ocean Flats SF
  {92.0,-2093.66, -2464.94, 30.62,28.0,-2092.64, -2461.94, 30.62,1.0},//Ammunation Angelpine SF
  {93.0,243.29, -178.62, 1.58,27.0,240.02, -178.56, 1.57,1.0},//Ammunation Blueberry LS
  {94.0,2333.08, 61.48, 26.70,30.0,2336.72, 61.59, 26.48,1.0},//Ammunation Palomino LS
  {95.0,1368.96, -1279.75, 13.54,29.0,1364.20, -1279.70, 13.54,1.0}, //Ammunation Downtown LS
  {96.0,2400.65, -1981.99, 13.54,28.0,2400.15, -1978.87, 13.54,2.0},//Ammunation Willowfield LS
  {97.0,2159.54, 943.49, 10.82,26.0,2154.69, 943.47, 10.82,2.0},//Ammunation come-a-lot LV
  {98.0,2539.54, 2084.01, 10.82,27.0,2534.45, 2083.80, 10.82,2.0},//Ammunation Old Venturas Strip LV
  {99.0,776.72, 1871.49, 4.90,28.0,781.13, 1871.71, 4.88,3.0},//Ammunation Bone County LV
  {100.0,-316.16, 829.82, 14.24,30.0,-312.25, 830.91, 14.24,2.0},//Ammunation Fort Carson LV
  {101.0,-1508.98, 2610.70, 55.83,30.0,-1509.68, 2607.64, 55.83,3.0} //Ammunation el quebrados SF
};

new shopenterpick[sizeof(shopsenter)];
new shopsleavingpick[sizeof(shopsinter)];
new shopssellingpick[sizeof(shopsinter)];
new waehlekleidung[MAX_PLAYERS];
new playerwaehltskin[MAX_PLAYERS];

public burgershot()
{
  new data[150],label[150];
  new Cache:cache = mysql_query(g_sql, "SELECT name FROM burgershot ORDER BY shopID");
  for(new i= 0; i < sizeof(shopsenter);i++)
  {
    if(cache_get_row_count(data))
    {
      cache_get_value_index("name",data);
      if(i < 10)
	  {
        format(label,150,"Burgershot \n %s \n betreten",data);
		CreateDynamicMapIcon(shopsenter[i][1], shopsenter[i][2], shopsenter[i][3], 10, -1,-1, -1, -1, 500);
	  }
      else if(i < 21)
	  {
        format(label,150,"Cluckin' bell \n %s \n betreten",data);
		CreateDynamicMapIcon(shopsenter[i][1], shopsenter[i][2], shopsenter[i][3], 14, -1,-1, -1, -1, 500);
	  }
      else if(i < 31)
	  {
        format(label,150,"Well stacked pizza \n %s \n betreten",data);
		CreateDynamicMapIcon(shopsenter[i][1], shopsenter[i][2], shopsenter[i][3], 29, -1,-1, -1, -1, 500);
	  }
	  else if(i >= 85 && i <= 88)
	  {
        format(label,150,"Strip Club \n %s \n betreten",data);
		CreateDynamicMapIcon(shopsenter[i][1], shopsenter[i][2], shopsenter[i][3], 21, -1,-1, -1, -1, 500);
	  }
	  else if(i >= 90 && i <= 100)
	  {
        format(label,150,"Ammu-Nation \n %s \n betreten",data);
		CreateDynamicMapIcon(shopsenter[i][1], shopsenter[i][2], shopsenter[i][3], 6, -1,-1, -1, -1, 500);
	  }
      else
	  {
		format(label,5,"%s",data);
		if(!strcmp(label,"Club",true)) CreateDynamicMapIcon(shopsenter[i][1], shopsenter[i][2], shopsenter[i][3], 48, -1,-1, -1, -1, 500);
		format(label,4,"%s",data);
		if(!strcmp(label,"Bar",true)) CreateDynamicMapIcon(shopsenter[i][1], shopsenter[i][2], shopsenter[i][3], 49, -1,-1, -1, -1, 500);
		format(label,11,"%s",data);
		if(!strcmp(label,"Restaurant",true)) CreateDynamicMapIcon(shopsenter[i][1], shopsenter[i][2], shopsenter[i][3], 50, -1,-1, -1, -1, 500);
		if(!strcmp(label,"Steakhouse",true)) CreateDynamicMapIcon(shopsenter[i][1], shopsenter[i][2], shopsenter[i][3], 50, -1,-1, -1, -1, 500);
		format(label,7,"%s",data);
		if(!strcmp(label,"Donuts",true)) CreateDynamicMapIcon(shopsenter[i][1], shopsenter[i][2], shopsenter[i][3], 17, -1,-1, -1, -1, 500);
		format(label,7,"%s",data);
		if(i >= 54 && i <= 70)  CreateDynamicMapIcon(shopsenter[i][1], shopsenter[i][2], shopsenter[i][3], 45, -1,-1, -1, -1, 500);
        if(i >= 71 && i <= 83)  CreateDynamicMapIcon(shopsenter[i][1], shopsenter[i][2], shopsenter[i][3], 50, -1,-1, -1, -1, 500);
		if(i == 84)  CreateDynamicMapIcon(shopsenter[i][1], shopsenter[i][2], shopsenter[i][3], 21, -1,-1, -1, -1, 500);
		if(i == 89)  CreateDynamicMapIcon(shopsenter[i][1], shopsenter[i][2], shopsenter[i][3], 23, -1,-1, -1, -1, 500);
        format(label,150,"%s \nbetreten",data);
	  }
      Create3DTextLabel(label, COLOR_WHITE,  shopsenter[i][1], shopsenter[i][2], shopsenter[i][3]+0.5, 10, 0, false);
    }
    shopenterpick[i] = CreatePickup(1559,1,shopsenter[i][1], shopsenter[i][2], shopsenter[i][3],-1);
  }
  for(new i = 0; i < sizeof(shopsinter);i++)
  {
    shopsleavingpick[i] = CreatePickup(1559,1,shopsinter[i][4], shopsinter[i][5], shopsinter[i][6],-1);
    shopssellingpick[i] = CreatePickup(1239,1,shopsinter[i][1], shopsinter[i][2], shopsinter[i][3],-1);
  }
}

public essen(playerid, listitem, bsID)
{
  new data[20],price[50],query[150];
  format(query, sizeof(query), "SELECT preis1,preis2,preis3,bestand FROM burgershot WHERE shopID = %i",bsID);
  new Cache:cache = mysql_query(g_sql, query);
  cache_get_value_index("bestand",data);
  if(bsID < 11)
  {
    if(listitem == 0)
    {
      if(strval(data) >= 1)
      {
        cache_get_value_index("preis1",price);
        if(giveusermoney(playerid,-1 * strval(price)))
        {
          playereat(playerid,20.0,0,1000);
          giveshop(bsID,1,strval(price));
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~Kinderburger ausverkauft!", 3000, 1);
    }
    if(listitem == 1)
    {
      if(strval(data) >= 2)
      {
        cache_get_value_index("preis2",price);
        if(giveusermoney(playerid,-1 * strval(price)))
        {
          playereat(playerid,35.0,0,3000);
          giveshop(bsID,2,strval(price));
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~Chessburger ausverkauft!", 3000, 1);
    }
    if(listitem == 2)
    {
      if(strval(data) >= 4)
      {
        cache_get_value_index("preis3",price);
        if(giveusermoney(playerid,-1 * strval(price)))
        {
          playereat(playerid,65.0,0,5000);
          giveshop(bsID,4,strval(price));
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~XXX-Burger ausverkauft!", 3000, 1);
    }
  }
  else if(bsID < 22)
  {
    if(listitem == 0)
    {
      if(strval(data) >= 1)
      {
        cache_get_value_index("preis1",price);
        if(giveusermoney(playerid,-1 * strval(price)))
        {
          playereat(playerid,20.0,1,1000);
          giveshop(bsID,1,strval(price));
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~kleine Chickenwings Box ausverkauft!", 3000, 1);
    }
    if(listitem == 1)
    {
      if(strval(data) >= 2)
      {
        cache_get_value_index("preis2",price);
        if(giveusermoney(playerid,-1 * strval(price)))
        {
          playereat(playerid,35.0,1,3000);
          giveshop(bsID,2,strval(price));
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~mittlere Chickenwings Box ausverkauft!", 3000, 1);
    }
    if(listitem == 2)
    {
      if(strval(data) >= 4)
      {
        cache_get_value_index("preis3",price);
        if(giveusermoney(playerid,-1 * strval(price)))
        {
          playereat(playerid,65.0,1,5000);
          giveshop(bsID,4,strval(price));
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~grosse Chickenwings Box ausverkauft!", 3000, 1);
    }
  }
  else if(bsID < 32)
  {
    if(listitem == 0)
    {
      if(strval(data) >= 1)
      {
        cache_get_value_index("preis1",price);
        if(giveusermoney(playerid,-1 * strval(price)))
        {
          playereat(playerid,20.0,2,1000);
          giveshop(bsID,1,strval(price));
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~Pizza ausverkauft!", 3000, 1);
    }
    if(listitem == 1)
    {
      if(strval(data) >= 2)
      {
        cache_get_value_index("preis2",price);
        if(giveusermoney(playerid,-1 * strval(price)))
        {
          playereat(playerid,35.0,2,3000);
          giveshop(bsID,2,strval(price));
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~Pizza ausverkauft!", 3000, 1);
    }
    if(listitem == 2)
    {
      if(strval(data) >= 4)
      {
        cache_get_value_index("preis3",price);
        if(giveusermoney(playerid,-1 * strval(price)))
        {
          playereat(playerid,65.0,2,5000);
          giveshop(bsID,4,strval(price));
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~Pizza ausverkauft!", 3000, 1);
    }
  }
  else if(bsID == 32 || bsID == 34 || bsID == 35 || bsID == 41 || bsID == 47)
  {
    if(listitem == 0)
    {
      if(strval(data) >= 1)
      {
        cache_get_value_index("preis1",price);
        if(giveusermoney(playerid,-1 * strval(price)))
        {
          playereat(playerid,5.0,3,1000);
          giveshop(bsID,1,strval(price));
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~Bier ausverkauft!", 3000, 1);
    }
    if(listitem == 1)
    {
      if(strval(data) >= 2)
      {
        cache_get_value_index("preis2",price);
        if(giveusermoney(playerid,-1 * strval(price)))
        {
          playereat(playerid,7.0,3,3000);
          giveshop(bsID,2,strval(price));
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~Mix-Getraenk ausverkauft!", 3000, 1);
    }
    if(listitem == 2)
    {
      if(strval(data) >= 4)
      {
        cache_get_value_index("preis3",price);
        if(giveusermoney(playerid,-1 * strval(price)))
        {
          playereat(playerid,10.0,3,5000);
          giveshop(bsID,4,strval(price));
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~Cocktails ausverkauft!", 3000, 1);
    }
  }
  else if(bsID == 33 || bsID == 37 || bsID == 39 || bsID == 45 || bsID == 49 || bsID == 42)
  {
    if(listitem == 0)
    {
      if(strval(data) >= 1)
      {
        cache_get_value_index("preis1",price);
        if(giveusermoney(playerid,-1 * strval(price)))
        {
          playereat(playerid,5.0,3,1000);
          giveshop(bsID,1,strval(price));
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~Bier ausverkauft!", 3000, 1);
    }
    if(listitem == 1)
    {
      if(strval(data) >= 2)
      {
        cache_get_value_index("preis2",price);
        if(giveusermoney(playerid,-1 * strval(price)))
        {
          playereat(playerid,7.0,3,3000);
          giveshop(bsID,2,strval(price));
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~Likoer ausverkauft!", 3000, 1);
    }
    if(listitem == 2)
    {
      if(strval(data) >= 4)
      {
        cache_get_value_index("preis3",price);
        if(giveusermoney(playerid,-1 * strval(price)))
        {
          playereat(playerid,10.0,3,5000);
          giveshop(bsID,4,strval(price));
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~Schnaps ausverkauft!", 3000, 1);
    }
  }
  else if(bsID == 36 || bsID == 38 || bsID == 40 || bsID == 43 || bsID == 44 || bsID == 46 || bsID == 48 || bsID == 50 || bsID == 51 || bsID == 52)
  {
    if(listitem == 0)
    {
      if(strval(data) >= 2)
      {
        cache_get_value_index("preis1",price);
        if(giveusermoney(playerid,-1 * strval(price)))
        {
          playereat(playerid,25.0,4,3000);
          giveshop(bsID,2,strval(price));
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~Gericht ausverkauft!", 3000, 1);
    }
    if(listitem == 1)
    {
      if(strval(data) >= 4)
      {
        cache_get_value_index("preis2",price);
        if(giveusermoney(playerid,-1 * strval(price)))
        {
          playereat(playerid,37.0,4,7000);
          giveshop(bsID,4,strval(price));
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~Gericht ausverkauft!", 3000, 1);
    }
    if(listitem == 2)
    {
      if(strval(data) >= 6)
      {
        cache_get_value_index("preis3",price);
        if(giveusermoney(playerid,-1 * strval(price)))
        {
          playereat(playerid,75.0,4,10000);
          giveshop(bsID,6,strval(price));
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~Gericht ausverkauft!", 3000, 1);
    }
  }
  else if(bsID == 53 || bsID == 54)
  {
    if(listitem == 0)
    {
      if(strval(data) >= 1)
      {
        cache_get_value_index("preis1",price);
        if(giveusermoney(playerid,-1 * strval(price)))
        {
          playereat(playerid,5.0,2,3000);
          giveshop(bsID,1,strval(price));
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~Donut ausverkauft!", 3000, 1);
    }
    if(listitem == 1)
    {
      if(strval(data) >= 2)
      {
        cache_get_value_index("preis2",price);
        if(giveusermoney(playerid,-1 * strval(price)))
        {
          playereat(playerid,7.0,2,7000);
          giveshop(bsID,2,strval(price));
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~Donut ausverkauft!", 3000, 1);
    }
    if(listitem == 2)
    {
      if(strval(data) >= 4)
      {
        cache_get_value_index("preis3",price);
        if(giveusermoney(playerid,-1 * strval(price)))
        {
          playereat(playerid,15.0,2,10000);
          giveshop(bsID,4,strval(price));
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~Donut ausverkauft!", 3000, 1);
    }
  }
  else if(bsID >= 55 && bsID <= 58)
  {
    if(listitem == 0)
    {
      if(strval(data) >= 50 && playerdata[playerid][6] > 0 &&(playerdata[playerid][70] < 5 || playerdata[playerid][56] == 1))
      {
		waehlekleidung[playerid] = 1;
		SetPlayerHealth(playerid,0.0);
      }
      else if( playerdata[playerid][6] == 0)
        GameTextForPlayer(playerid, "~r~Erst ab Level 1 erlaubt!", 3000, 1);
	  else if(playerdata[playerid][70] >= 3 || (playerdata[playerid][70] >= 5 && playerdata[playerid][56] == 1))
		GameTextForPlayer(playerid, "~r~Kleidungswechsel nicht erlaubt!", 3000, 1);
      else GameTextForPlayer(playerid, "~r~Geschaeft ausverkauft!", 3000, 1);
    }
  }
  else if(bsID >= 59 && bsID <= 60)
  {
    if(listitem == 0)
    {
      if(strval(data) >= 50 && playerdata[playerid][6] > 1 &&(playerdata[playerid][70] < 5 || playerdata[playerid][56] == 1))
      {
		waehlekleidung[playerid] = 1;
		SetPlayerHealth(playerid,0.0);
      }
      else if( playerdata[playerid][6] <= 1)
        GameTextForPlayer(playerid, "~r~Erst ab Level 2 erlaubt!", 3000, 1);
	  else if(playerdata[playerid][70] >= 3 || (playerdata[playerid][70] >= 5 && playerdata[playerid][56] == 1))
		GameTextForPlayer(playerid, "~r~Kleidungswechsel nicht erlaubt!", 3000, 1);
      else GameTextForPlayer(playerid, "~r~Geschaeft ausverkauft!", 3000, 1);
    }
  }
  else if(bsID >= 61 && bsID <= 64)
  {
    if(listitem == 0)
    {
      if(strval(data) >= 50 && playerdata[playerid][6] > 1 &&(playerdata[playerid][70] < 5 || playerdata[playerid][56] == 1))
      {
		waehlekleidung[playerid] = 1;
		SetPlayerHealth(playerid,0.0);
      }
      else if( playerdata[playerid][6] <= 1)
        GameTextForPlayer(playerid, "~r~Erst ab Level 2 erlaubt!", 3000, 1);
	  else if(playerdata[playerid][70] >= 3 || (playerdata[playerid][70] >= 5 && playerdata[playerid][56] == 1))
		GameTextForPlayer(playerid, "~r~Kleidungswechsel nicht erlaubt!", 3000, 1);
      else GameTextForPlayer(playerid, "~r~Geschaeft ausverkauft!", 3000, 1);
    }
  }
  else if(bsID >= 65 && bsID <= 67)
  {
    if(listitem == 0)
    {
      if(strval(data) >= 50 && playerdata[playerid][6] > 0 &&(playerdata[playerid][70] < 5 || playerdata[playerid][56] == 1))
      {
		waehlekleidung[playerid] = 1;
		SetPlayerHealth(playerid,0.0);
      }
      else if( playerdata[playerid][6] == 0)
        GameTextForPlayer(playerid, "~r~Erst ab Level 1 erlaubt!", 3000, 1);
	  else if(playerdata[playerid][70] >= 3 || (playerdata[playerid][70] >= 5 && playerdata[playerid][56] == 1))
		GameTextForPlayer(playerid, "~r~Kleidungswechsel nicht erlaubt!", 3000, 1);
      else GameTextForPlayer(playerid, "~r~Geschдft ausverkauft!", 3000, 1);
    }
  }
  else if(bsID >= 68 && bsID <= 70)
  {
    if(listitem == 0)
    {
      if(strval(data) >= 50 && playerdata[playerid][6] > 2 &&(playerdata[playerid][70] < 5 || playerdata[playerid][56] == 1))
      {
		waehlekleidung[playerid] = 1;
		SetPlayerHealth(playerid,0.0);
      }
      else if( playerdata[playerid][6] <= 2)
        GameTextForPlayer(playerid, "~r~Erst ab Level 3 erlaubt!", 3000, 1);
	  else if(playerdata[playerid][70] >= 3 || (playerdata[playerid][70] >= 5 && playerdata[playerid][56] == 1))
		GameTextForPlayer(playerid, "~r~Kleidungswechsel nicht erlaubt!", 3000, 1);
      else GameTextForPlayer(playerid, "~r~Geschaeft ausverkauft!", 3000, 1);
    }
  }
  else if(bsID == 71)
  {
    if(listitem == 0)
    {
      if(strval(data) >= 50 && playerdata[playerid][6] > 2 &&(playerdata[playerid][70] < 5 || playerdata[playerid][56] == 1))
      {
		waehlekleidung[playerid] = 1;
		SetPlayerHealth(playerid,0.0);
      }
      else if( playerdata[playerid][6] <= 2)
        GameTextForPlayer(playerid, "~r~Erst ab Level 3 erlaubt!", 3000, 1);
	  else if(playerdata[playerid][70] >= 3 || (playerdata[playerid][70] >= 5 && playerdata[playerid][56] == 1))
		GameTextForPlayer(playerid, "~r~Kleidungswechsel nicht erlaubt!", 3000, 1);
      else GameTextForPlayer(playerid, "~r~Geschaeft ausverkauft!", 3000, 1);
    }
  }
  else if(bsID >= 72 && bsID <= 84)
  {
    if(listitem == 0)
    {
      if(strval(data) >= 5 && playerdata[playerid][72] < 3)
      {
        cache_get_value_index("preis1",price);
        if(giveusermoney(playerid,-1*strval(price)))
        {
          playerdata[playerid][72]++;
          GameTextForPlayer(playerid, "~w~Sie haben eine kleine Dose gekauft!", 3000, 1);
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else if(playerdata[playerid][72] >= 3)
        GameTextForPlayer(playerid, "~r~Sie haben bereits eine kleine Dose!", 3000, 1);
      else GameTextForPlayer(playerid, "~r~Dose ausverkauft!", 3000, 1);
    }
    if(listitem == 1)
    {
      if(strval(data) >= 10 && playerdata[playerid][72] < 2)
      {
        cache_get_value_index("preis2",price);
        if(giveusermoney(playerid,-1*strval(price)))
        {
          playerdata[playerid][72]++;
          GameTextForPlayer(playerid, "~w~Sie haben eine grosse Dose gekauft!", 3000, 1);
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else if(playerdata[playerid][72] >= 2)
        GameTextForPlayer(playerid, "~r~Sie haben bereits eine grosse Dose!", 3000, 1);
      else GameTextForPlayer(playerid, "~r~Dose ausverkauft!", 3000, 1);
    }
    if(listitem == 2)
    {
      if(strval(data) >= 50 && playerdata[playerid][10] == 0)
      {
        cache_get_value_index("preis3",price);
        if(giveusermoney(playerid,-1*strval(price)))
        {
          playerdata[playerid][10] = 1;
          GameTextForPlayer(playerid, "~w~Sie haben ein Handy gekauft!", 3000, 1);
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else if(playerdata[playerid][10] == 0)
        GameTextForPlayer(playerid, "~r~Sie haben bereits ein Handy!", 3000, 1);
      else GameTextForPlayer(playerid, "~r~Handy ausverkauft!", 3000, 1);
    }
  }
  else if(bsID == 85)
  {
    if(listitem == 0)
    {
      if(strval(data) >= 25)
      {
		cache_get_value_index("preis1",price);
        if(giveusermoney(playerid,-1 * strval(price)))
        {
          GivePlayerWeapon(playerid, WEAPON:11, 0);
          playerdata[playerid][11] = 11;
          playerdata[playerid][12] = 0;
          giveshop(bsID,25,strval(price));
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~Geschaeft ausverkauft!", 3000, 1);
    }
    if(listitem == 1)
    {
      if(strval(data) >= 35)
      {
		cache_get_value_index("preis2",price);
        if(giveusermoney(playerid,-1 * strval(price)))
        {
          GivePlayerWeapon(playerid, WEAPON:13, 0);
          playerdata[playerid][11] = 13;
          playerdata[playerid][12] = 0;
          giveshop(bsID,35,strval(price));
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~Geschaeft ausverkauft!", 3000, 1);
    }
    if(listitem == 2)
    {
      if(strval(data) >= 50)
      {
		cache_get_value_index("preis3",price);
        if(giveusermoney(playerid,-1 * strval(price)))
        {
          GivePlayerWeapon(playerid, WEAPON:10, 0);
          playerdata[playerid][11] = 10;
          playerdata[playerid][12] = 0;
          giveshop(bsID,50,strval(price));
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~Geschaeft ausverkauft!", 3000, 1);
    }
  }
  else if(bsID >= 86 && bsID <= 90)
  {
    if(listitem == 0)
    {
      if(strval(data) >= 10)
      {
        cache_get_value_index("preis1",price);
        if(giveusermoney(playerid,-1 * strval(price)))
        {
          playereat(playerid,1.0,3,3000);
          giveshop(bsID,10,strval(price));
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~Bier ausverkauft!", 3000, 1);
    }
    if(listitem == 1)
    {
      if(strval(data) >= 20)
      {
        cache_get_value_index("preis2",price);
        if(giveusermoney(playerid,-1 * strval(price)))
        {
          playereat(playerid,2.0,3,7000);
          giveshop(bsID,20,strval(price));
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~Cocktail ausverkauft!", 3000, 1);
    }
    if(listitem == 2)
    {
      if(strval(data) >= 30)
      {
        cache_get_value_index("preis3",price);
        if(giveusermoney(playerid,-1 * strval(price)))
        {
          playereat(playerid,5.0,3,10000);
          giveshop(bsID,30,strval(price));
        }
        else GameTextForPlayer(playerid, "~r~Sie habe nicht genug Geld dabei.", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~Champagner ausverkauft!", 3000, 1);
    }
  }
  
  ;
}

public freiew_response(playerid, dialogid, response, listitem, inputtext[])
{
  if(dialogid == 1001 && response)
  {
    if(playerinshop[playerid] >= 0)
      essen(playerid,listitem,(playerinshop[playerid]+1));
  }
  if(dialogid == 1002)
  {
    if(response)
    {
      new query[250],data[250];
      format(query, sizeof(query), "SELECT preis1,bestand FROM burgershot WHERE shopID = %i",(playerinshop[playerid]+1));
      mysql_query(query);
      mysql_store_result(g_sql);
      cache_get_value_index("bestand",data);
      if(strval(data) >= 50)
      {
        cache_get_value_index("preis1",data);
        if(giveusermoney(playerid,-1*strval(data)))
        {
          GameTextForPlayer(playerid, "~g~ Kleidung gekauft!", 3000, 1);
          giveshop((playerinshop[playerid]+1),50,strval(data));
          playerdata[playerid][1] = playerwaehltskin[playerid];
          playerdata[playerid][70]++;
        }
      }
      ;
    }
    SetPlayerSkin(playerid, playerdata[playerid][1]);
    playerwaehltskin[playerid] = -1;
  }
  if(dialogid == 1003 && response)
  {
    new query[150],data[150],data2[150],data3[50],weapon;
    format(query,150,"SELECT * FROM ammunation WHERE shopid=%i",(playerinshop[playerid]+1));
    mysql_query(query);
    mysql_store_result(g_sql);
    
    if(listitem == 0)
    {
      cache_get_value_index("preis_9mm",data);
	  cache_get_value_index("bestand_9mm",data2);
      data3 = "bestand_9mm";
      weapon = 22;
    }
    else if(listitem == 1)
    {
      cache_get_value_index("preis_silenced9mm",data);
	  cache_get_value_index("bestand_silenced9mm",data2);
      data3 = "bestand_silenced9mm";
      weapon = 23;
    }
    else if(listitem == 2)
    {
      cache_get_value_index("preis_deserteagle",data);
	  cache_get_value_index("bestand_deserteagle",data2);
      data3 = "bestand_deserteagle";
      weapon = 24;
    }
    else if(listitem == 3)
    {
      cache_get_value_index("preis_nightstick",data);
	  cache_get_value_index("bestand_nightstick",data2);
      data3 = "bestand_nightstick";
      weapon = 3;
    }
    else if(listitem == 4)
    {
      cache_get_value_index("preis_knife",data);
	  cache_get_value_index("bestand_knife",data2);
      data3 = "bestand_knife";
      weapon = 4;
    }
    else if(listitem == 5)
    {
      cache_get_value_index("preis_katana",data);
	  cache_get_value_index("bestand_katana",data2);
      data3 = "bestand_katana";
      weapon = 8;
    }
    else if(listitem == 6)
    {
      cache_get_value_index("preis_mun",data);
	  cache_get_value_index("bestand_mun",data2);
      data3 = "bestand_mun";
    }
    else if(listitem == 7)
    {
      cache_get_value_index("preis_lowarmor",data);
	  cache_get_value_index("bestand_lowarmor",data2);
      data3 = "bestand_lowarmor";
    }
    else if(listitem == 8)
    {
      cache_get_value_index("preis_normalarmor",data);
	  cache_get_value_index("bestand_normalarmor",data2);
      data3 = "bestand_normalarmor";
    }
    else if(listitem == 9)
    {
      cache_get_value_index("preis_bigarmor",data);
	  cache_get_value_index("bestand_bigarmor",data2);
      data3 = "bestand_bigarmor";
    }
    ;
    
    
    if(strval(data2) > 0 && listitem < 6)
    {
      if(playerdata[playerid][31] == 1 || listitem > 2)
      {
        if(giveusermoney(playerid,-1*strval(data)))
        {
          if(listitem == 0 || listitem == 1 || listitem == 2) playerdata[playerid][13] = weapon;
          if(listitem == 3 || listitem == 4 || listitem == 5){ playerdata[playerid][11] = weapon;playerdata[playerid][12] = 0; }
          ResetPlayerWeapons(playerid);
          GivePlayerWeapon(playerid,WEAPON:playerdata[playerid][11],playerdata[playerid][12]);
          GivePlayerWeapon(playerid,WEAPON:playerdata[playerid][13],playerdata[playerid][14]);
          GivePlayerWeapon(playerid,WEAPON:playerdata[playerid][15],playerdata[playerid][16]);
          SetPlayerArmedWeapon(playerid,WEAPON:0);
          format(query,150,"UPDATE ammunation SET %s = %s - 1 WHERE shopid=%i",data3,data3,(playerinshop[playerid]+1));
          mysql_query(query);
          format(query,150,"UPDATE burgershot SET kontostand = kontostand + %i WHERE shopid=%i",strval(data),(playerinshop[playerid]+1));
          mysql_query(query);
          GameTextForPlayer(playerid, "~g~ Waffe gekauft!", 3000, 1);
        }
        else GameTextForPlayer(playerid, "~r~ Nicht genug Geld dabei!", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~ Kein Waffenschein!", 3000, 1);
    }
    else if(listitem < 6) GameTextForPlayer(playerid, "~r~ Waffe ausverkauft!", 3000, 1);

    if(strval(data2) > 10 && listitem == 6)
    {
      if(giveusermoney(playerid,-1*strval(data)*10))
      {
        new ammo;
        GetPlayerWeaponData(playerid, WEAPON_SLOT:2, WEAPON:weapon, ammo);
        if(weapon >= 22 && weapon <= 24)
        {
          format(query,150,"UPDATE ammunation SET %s = %s - 10 WHERE shopid=%i",data3,data3,(playerinshop[playerid]+1));
          mysql_query(query);
          format(query,150,"UPDATE burgershot SET kontostand = kontostand + %i WHERE shopid=%i",strval(data)*10,(playerinshop[playerid]+1));
          mysql_query(query);
          playerdata[playerid][14] = playerdata[playerid][14] + 10;
          ResetPlayerWeapons(playerid);
          GivePlayerWeapon(playerid,WEAPON:playerdata[playerid][11],playerdata[playerid][12]);
          GivePlayerWeapon(playerid,WEAPON:playerdata[playerid][13],playerdata[playerid][14]);
          GivePlayerWeapon(playerid,WEAPON:playerdata[playerid][15],playerdata[playerid][16]);
          SetPlayerArmedWeapon(playerid,WEAPON:0);
          GameTextForPlayer(playerid, "~g~ Munition gekauft!", 3000, 1);
        }
        else GameTextForPlayer(playerid, "~r~ Nur Pistolen Munition!", 3000, 1);
      }
      else GameTextForPlayer(playerid, "~r~ Nicht genug Geld dabei!", 3000, 1);
    }
    else if(listitem == 6) GameTextForPlayer(playerid, "~r~ Keine Munition im Lager!", 3000, 1);
    
    if(strval(data2) > 0 && (listitem == 7 || listitem == 8 || listitem == 9))
    {
      if(giveusermoney(playerid,-1*strval(data)))
      {
        format(query,150,"UPDATE ammunation SET %s = %s - 10 WHERE shopid=%i",data3,data3,(playerinshop[playerid]+1));
        mysql_query(query);
        format(query,150,"UPDATE burgershot SET kontostand = kontostand + %i WHERE shopid=%i",strval(data),(playerinshop[playerid]+1));
        mysql_query(query);
        GameTextForPlayer(playerid, "~g~ Schutzweste gekauft!", 3000, 1);
        if(listitem == 7) SetPlayerArmour(playerid,25.0);
        if(listitem == 8) SetPlayerArmour(playerid,50.0);
        if(listitem == 9) SetPlayerArmour(playerid,100.0);
      }
      else GameTextForPlayer(playerid, "~r~ Nicht genug Geld dabei!", 3000, 1);
    }
    else if(listitem == 7 || listitem == 8 || listitem == 9) GameTextForPlayer(playerid, "~r~ Keine Schutzweste im Lager!", 3000, 1);
  }
}

public playereat(playerid,Float:health,kind,time)
{
  new Float:healths,nh;
  if(kind == 0)
  {
    ApplyAnimation(playerid,"FOOD","EAT_Burger",4.1,true,false,true,true,time,FORCE_SYNC:1);
  }
  if(kind == 1)
  {
    ApplyAnimation(playerid,"FOOD","EAT_Chicken",4.1,true,false,true,true,time,FORCE_SYNC:1);
  }
  if(kind == 2)
  {
    ApplyAnimation(playerid,"FOOD","EAT_Pizza",4.1,true,false,true,true,time,FORCE_SYNC:1);
  }
  if(kind == 3)
  {
    ApplyAnimation(playerid,"VENDING","VEND_Drink_P",4.1,true,false,true,true,time,FORCE_SYNC:1);
  }
  if(kind == 4)
  {
    ApplyAnimation(playerid,"VENDING","VEND_Drink_P",4.1,true,false,true,true,time,FORCE_SYNC:1);
  }
  GetPlayerHealth(playerid,healths);
  nh = floatround((healths+health),floatround_ceil);
  if(nh > 100) nh = 100;
  playerdata[playerid][17] = nh;
  SetPlayerHealth(playerid,nh);
}

public giveshop(bsID,bestand,price)
{
  new query[150];
  format(query, sizeof(query), "UPDATE burgershot SET kontostand = kontostand + %i, bestand = bestand - %i WHERE shopID = %i",price,bestand,bsID);
  mysql_query(query);
}

public freiew_pickups(playerid,pickupid)
{
  for(new i = 0; i < sizeof(shopsenter);i++)
  {
    if(pickupid == shopenterpick[i])
    {
	  if((i == 89 && playerdata[playerid][56] == 1) || i < 89)
	  {
		SetPlayerInterior(playerid, floatround(shopsinter[floatround(shopsenter[i][4])][0]));
		SetPlayerPos(playerid,shopsinter[floatround(shopsenter[i][4])][7], shopsinter[floatround(shopsenter[i][4])][8],shopsinter[floatround(shopsenter[i][4])][9]);
		SetPlayerFacingAngle(playerid,shopsinter[floatround(shopsenter[i][4])][10]);
        SetPlayerVirtualWorld(playerid,floatround(shopsenter[i][8]));
		playerinshop[playerid] = i;
	  }
      else if(i > 89 && playerdata[playerid][6] > 4)
      {
        SetPlayerInterior(playerid, floatround(shopsinter[floatround(shopsenter[i][4])][0]));
		SetPlayerPos(playerid,shopsinter[floatround(shopsenter[i][4])][7], shopsinter[floatround(shopsenter[i][4])][8],shopsinter[floatround(shopsenter[i][4])][9]);
		SetPlayerFacingAngle(playerid,shopsinter[floatround(shopsenter[i][4])][10]);
        SetPlayerVirtualWorld(playerid,floatround(shopsenter[i][8]));
		playerinshop[playerid] = i;
      }
      else if(i > 89 && playerdata[playerid][6] <= 4)
        GameTextForPlayer(playerid, "~r~Erst ab Level 5 erlaubt!", 3000, 1);
	  else GameTextForPlayer(playerid, "~r~Nur VIPs erlaubt!", 3000, 1);
    }
  }
  for(new i = 0; i < sizeof(shopsinter);i++)
  {
    if(pickupid == shopsleavingpick[i])
    {
      if(playerinshop[playerid] < 0) playerinshop[playerid] = 0;
      SetPlayerInterior(playerid, 0);
      SetPlayerPos(playerid, shopsenter[playerinshop[playerid]][5],shopsenter[playerinshop[playerid]][6],shopsenter[playerinshop[playerid]][7]);
      playerinshop[playerid] = -1;
      SetPlayerVirtualWorld(playerid,0);
      ClearAnimations(playerid);
    }
    if(pickupid == shopssellingpick[i] && i < 26)
    {
      SetPlayerPos(playerid, shopsinter[i][1]-1.5,shopsinter[i][2]-1.5,shopsinter[i][3]);
      new query[150],data[150],output[250],headline[50],string[150],bestand,preis1,preis2,preis3;
      format(query,150,"SELECT preis1,preis2,preis3,bestand FROM burgershot WHERE shopid=%i",(playerinshop[playerid]+1));
      mysql_query(query);
      mysql_store_result(g_sql);
      cache_get_row_count(data);
      cache_get_value_index("bestand",data);
      bestand = strval(data);
      cache_get_value_index("preis1",data);
      preis1 = strval(data);
      cache_get_value_index("preis2",data);
      preis2 = strval(data);
      cache_get_value_index("preis3",data);
      preis3 = strval(data);
      
      if(bestand >= 1 && i < 1)
        format(string,150,"Kinderburger (%i $) \n",preis1);
      else if(i < 1)
        format(string,150,"{FF0000}Kinderburger ausverkauft \n");
      else if(bestand >= 1 && i < 2)
        format(string,150,"kleine Chickenwings Box (%i $) \n",preis1);
      else if(i < 2)
        format(string,150,"{FF0000}kleine Chickenwings Box ausverkauft \n");
      else if(bestand >= 1 && i < 3)
        format(string,150,"Pizza 15 cm (%i $) \n",preis1);
      else if(i < 3)
        format(string,150,"{FF0000}die Pizza ist ausverkauft \n");
      else if(bestand >= 1 && i < 4)
        format(string,150,"Bier (%i $) \n",preis1);
      else if(i < 4)
        format(string,150,"{FF0000}Bier ist nicht mehr im Lager.\n");
      else if(bestand >= 1 && i < 5)
        format(string,150,"Bier (%i $) \n",preis1);
      else if(i < 5)
        format(string,150,"{FF0000}Bier ist nicht mehr im Lager.\n");
      else if(bestand >= 2 && i < 6)
        format(string,150,"Wasser und kleiner Salat (%i $) \n",preis1);
      else if(i < 6)
        format(string,150,"{FF0000}Gericht nicht im Lager.\n");
      else if(bestand >= 1 && i < 7)
        format(string,150,"Bier (%i $) \n",preis1);
      else if(i < 7)
        format(string,150,"{FF0000}Bier ist nicht mehr im Lager.\n");
      else if(bestand >= 2 && i < 8)
        format(string,150,"Wasser und kleiner Salat (%i $) \n",preis1);
      else if(i < 8)
        format(string,150,"{FF0000}Gericht nicht im Lager.\n");
      else if(bestand >= 1 && i < 9)
        format(string,150,"Bier (%i $) \n",preis1);
      else if(i < 9)
        format(string,150,"{FF0000}Bier ist nicht mehr im Lager.\n");
      else if(bestand >= 1 && i < 10)
        format(string,150,"Donut ohne alles (%i $) \n",preis1);
      else if(i < 10)
        format(string,150,"{FF0000}Donut ausverkauft.\n");
      else if(bestand >= 5 && i >= 16 && i <= 21 && playerdata[playerid][72] < 3)
        format(string,150,"Kleine Dose Nahrung kaufen (%i $) \n",preis1);
	  else if(i >= 16 && i <= 21)
        format(string,150,"{FF0000}Kleine Dosen ausverkauft.\n",preis1);
      else if(bestand >= 25 && i == 22)
        format(string,150,"Dildo kaufen (%i $) \n",preis1);
      else if(i == 22)
        format(string,150,"{FF0000}Dildo ausverkauft\n");
	  else if(bestand >= 10 && i >= 23 && i <= 25)
        format(string,150,"Bier bestellen (%i $) \n",preis1);
	  else if(i >= 23 && i <= 25)
        format(string,150,"Bier ausverkauft \n");
      
      strcat(output,string);
      
      if(bestand >= 2 && i < 1)
        format(string,150,"Chessburger (%i $) \n",preis2);
      else if(i < 1)
        format(string,150,"{FF0000}Chessburger ausverkauft\n");
      else if(bestand >= 2 && i < 2)
        format(string,150,"mittlere Chickenwings Box (%i $) \n",preis2);
      else if(i < 2)
        format(string,150,"{FF0000}mittlere Chickenwings Box ausverkauft \n");
      else if(bestand >= 2 && i < 3)
        format(string,150,"Pizza 20 cm (%i $) \n",preis2);
      else if(i < 3)
        format(string,150,"{FF0000}die Pizza ist ausverkauft \n");
      else if(bestand >= 2 && i < 4)
        format(string,150,"Wodka-Cola (%i $) \n",preis2);
      else if(i < 4)
        format(string,150,"{FF0000}Kein Wodka im Lager.\n");
      else if(bestand >= 2 && i < 5)
        format(string,150,"Likцr (%i $) \n",preis2);
      else if(i < 5)
        format(string,150,"{FF0000}Kein Likцr im Lager.\n");
      else if(bestand >= 4 && i < 6)
        format(string,150,"Bier und ein Putenbrustfilet(%i $) \n",preis2);
      else if(i < 6)
        format(string,150,"{FF0000}Das Gericht ist nicht im Lager. \n");
      else if(bestand >= 2 && i < 7)
        format(string,150,"Likцr (%i $) \n",preis2);
      else if(i < 7)
        format(string,150,"{FF0000}Kein Likцr im Lager.\n");
      else if(bestand >= 4 && i < 8)
        format(string,150,"Bier und ein Putenbrustfilet(%i $) \n",preis2);
      else if(i < 8)
        format(string,150,"{FF0000}Das Gericht ist nicht im Lager.\n");
      else if(bestand >= 2 && i < 9)
        format(string,150,"Likцr (%i $) \n",preis2);
      else if(i < 9)
        format(string,150,"{FF0000}Kein Likцr im Lager.\n");
      else if(bestand >= 2 && i < 10)
        format(string,150,"Donut mit Schokolade (%i $) \n",preis2);
      else if(i < 10)
        format(string,150,"{FF0000}Donut ausverkauft.\n");
      else if(bestand >= 10 && i >= 16 && i <= 21 && playerdata[playerid][72] < 2)
        format(string,150,"Grosse Dose Wurst kaufen (%i $) \n",preis2);
	  else if(i >= 16 && i <= 21)
        format(string,150,"{FF0000}Grosse Dosen ausverkauft.\n",preis2);
      else if(bestand >= 35 && i == 22)
        format(string,150,"Silber Vibrator kaufen (%i $) \n",preis2);
      else if(i == 22)
        format(string,150,"{FF0000}Silber Vibrator ausverkauft\n");
	  else if(bestand >= 20 && i >= 23 && i <= 25)
        format(string,150,"Cocktail bestellen (%i $) \n",preis2);
	  else if(i >= 23 && i <= 25)
        format(string,150,"Cocktail ausverkauft \n");
      strcat(output,string);
	  
      
      if(bestand >= 4 && i == 0)
        format(string,150,"XXL-Burger (%i $)",preis3);
      else if(i == 0)
        format(string,150,"{FF0000}XXL-Burger ausverkauft");
      else if(bestand >= 4 && i == 1)
        format(string,150,"grosse Chickenwings Box (%i $) \n",preis3);
      else if(i == 1)
        format(string,150,"{FF0000}grosse Chickenwings Box ausverkauft \n");
      else if(bestand >= 4 && i == 2)
        format(string,150,"Pizza 30 cm (%i $) \n",preis3);
      else if(i == 2)
        format(string,150,"{FF0000}die Pizza ist ausverkauft \n");
      else if(bestand >= 4 && i == 3)
        format(string,150,"Cocktail (%i $) \n",preis3);
      else if(i == 3)
        format(string,150,"{FF0000}Das Getrдnk ist nicht vorrдtig.\n");
      else if(bestand >= 4 && i == 4)
        format(string,150,"Whisky (%i $) \n",preis3);
      else if(i == 4)
        format(string,150,"{FF0000}Kein Whisky im Lager.\n");
      else if(bestand >= 6 && i == 5)
        format(string,150,"Wein und ein 3 Gдnge Menь(%i $) \n",preis3);
      else if(i == 5)
        format(string,150,"{FF0000}Das Gericht steht nicht zur Wahl.\n");
      else if(bestand >= 4 && i == 6)
        format(string,150,"Whisky (%i $) \n",preis3);
      else if(i == 6)
        format(string,150,"{FF0000}Whisky ist nicht im Lager.\n");
      else if(bestand >= 4 && i == 7)
        format(string,150,"Wein und 3 Gдnge Menь (%i $) \n",preis3);
      else if(i == 7)
        format(string,150,"{FF0000}Das Gericht steht nicht zur Wahl.\n");
      else if(bestand >= 4 && i == 8)
        format(string,150,"Wodka (%i $) \n",preis3);
      else if(i == 8)
        format(string,150,"{FF0000}Kein Wodka im Lager\n");
      else if(bestand >= 4 && i == 9)
        format(string,150,"Donut mit Likцrfьllung (%i $) \n",preis3);
      else if(i == 9)
        format(string,150,"{FF0000}Donut ausverkauft.\n");
	  else if(bestand >= 50 && i >= 10 && i <= 15 && (playerdata[playerid][70] < 5 || (playerdata[playerid][70] < 8 && playerdata[playerid][56] == 1)))
        format(string,150,"Neue Kleidung kaufen (%i $) \n",preis1);
	  else if(i >= 10 && i <= 15 && (playerdata[playerid][70] >= 5 || (playerdata[playerid][70] >= 8 && playerdata[playerid][56] == 1)))
        format(string,150,"{FF0000}Sie dьrfen nicht so oft ihre Kleidung wechseln.\n",preis1);
      else if(bestand >= 50 && i >= 16 && i <= 21 && playerdata[playerid][10] == 0)
        format(string,150,"Smartphone kaufen (%i $) \n",preis3);
	  else if(i >= 16 && i <= 21)
        format(string,150,"{FF0000}Sie kцnnen kein Smartphone kaufen.\n",preis3);
      else if(bestand >= 50 && i == 22)
        format(string,150,"Doppel-Dildo kaufen (%i $) \n",preis1);
      else if(i == 22)
        format(string,150,"{FF0000}Doppel-Dildo ausverkauft\n");
	  else if(bestand >= 30 && i >= 23 && i <= 25)
        format(string,150,"Flasche Champagner bestellen (%i $) \n",preis3);
	  else if(i >= 23 && i <= 25)
        format(string,150,"Flasche Champagner ausverkauft \n");
      else
        format(string,150,"{FF0000}Geschдft ausverkauft.\n");
      strcat(output,string);
      
      ;
      
      if(i < 1) headline = "Burgershot Speisekarte";
      else if(i < 2) headline = "Cluckin' bell Speisekarte";
      else if(i < 3) headline = "Well stacked pizza Speisekarte";
      else if(i < 10) headline = "Bestellung aufgeben";
	  else if(i < 16) headline = "Kleidung kaufen";
      else if(i < 22) headline = "24-7 einkaufen";
      else if(i < 23) headline = "Sex Shop einkaufen";
	  else if(i < 26) headline = "Strip Club Getrдnkekarte";
      ShowPlayerDialog(playerid,1001,DIALOG_STYLE_LIST , headline, output, "Bestellen", "Abbrechen");
    }
	else if(pickupid == shopssellingpick[i] && i >= 26)
    {
      SetPlayerPos(playerid, shopsinter[i][1]-1.5,shopsinter[i][2]-1.5,shopsinter[i][3]);
      new query[150],data[150],data2[150],output[500],string[150];
      format(query,150,"SELECT * FROM ammunation WHERE shopid=%i",(playerinshop[playerid]+1));
      mysql_query(query);
      mysql_store_result(g_sql);
	  
	  cache_get_value_index("preis_9mm",data);
	  cache_get_value_index("bestand_9mm",data2);
	  if(strval(data2) > 0) data2 = "vorrдtig"; else data2 = "ausverkauft";
	  format(string,150,"Pistole: 9mm (%i $) (%s) \n",strval(data),data2);
	  strcat(output,string);
	  
	  cache_get_value_index("preis_silenced9mm",data);
	  cache_get_value_index("bestand_silenced9mm",data2);
	  if(strval(data2) > 0) data2 = "vorrдtig"; else data2 = "ausverkauft";
	  format(string,150,"Pistole: 9mm schallgedдmpft (%i $) (%s) \n",strval(data),data2);
	  strcat(output,string);
	  
	  cache_get_value_index("preis_deserteagle",data);
	  cache_get_value_index("bestand_deserteagle",data2);
	  if(strval(data2) > 0) data2 = "vorrдtig"; else data2 = "ausverkauft";
	  format(string,150,"Pistole: Desert Eagle (%i $) (%s) \n",strval(data),data2);
	  strcat(output,string);
	  
	  cache_get_value_index("preis_nightstick",data);
	  cache_get_value_index("bestand_nightstick",data2);
	  if(strval(data2) > 0) data2 = "vorrдtig"; else data2 = "ausverkauft";
	  format(string,150,"Nahkampf: Schlagstock (%i $) (%s) \n",strval(data),data2);
	  strcat(output,string);
	  
	  cache_get_value_index("preis_knife",data);
	  cache_get_value_index("bestand_knife",data2);
	  if(strval(data2) > 0) data2 = "vorrдtig"; else data2 = "ausverkauft";
	  format(string,150,"Nahkampf: Messer (%i $) (%s) \n",strval(data),data2);
	  strcat(output,string);
	  
	  cache_get_value_index("preis_katana",data);
	  cache_get_value_index("bestand_katana",data2);
	  if(strval(data2) > 0) data2 = "vorrдtig"; else data2 = "ausverkauft";
	  format(string,150,"Nahkampf: Samuraischwert (%i $) (%s) \n",strval(data),data2);
	  strcat(output,string);
	  
	  cache_get_value_index("preis_mun",data);
	  cache_get_value_index("bestand_mun",data2);
	  if(strval(data2) > 10) data2 = "vorrдtig"; else data2 = "ausverkauft";
	  format(string,150,"Munition fьr Pistolen 10 Stьck (%i $) (%s) \n",strval(data),data2);
	  strcat(output,string);
	  
	  cache_get_value_index("preis_lowarmor",data);
	  cache_get_value_index("bestand_lowarmor",data2);
	  if(strval(data2) > 0) data2 = "vorrдtig"; else data2 = "ausverkauft";
	  format(string,150,"Schutzweste: leicht (%i $) (%s) \n",strval(data),data2);
	  strcat(output,string);
	  
	  cache_get_value_index("preis_normalarmor",data);
	  cache_get_value_index("bestand_normalarmor",data2);
	  if(strval(data2) > 0) data2 = "vorrдtig"; else data2 = "ausverkauft";
	  format(string,150,"Schutzweste: mittel (%i $) (%s) \n",strval(data),data2);
	  strcat(output,string);
	  
	  cache_get_value_index("preis_bigarmor",data);
	  cache_get_value_index("bestand_bigarmor",data2);
	  if(strval(data2) > 0) data2 = "vorrдtig"; else data2 = "ausverkauft";
	  format(string,150,"Schutzweste: schwer (%i $) (%s) \n",strval(data),data2);
	  strcat(output,string);
	  
	  ;
      ShowPlayerDialog(playerid,1003,DIALOG_STYLE_LIST , "Ammu-Nation Aushang", output, "Kaufen", "Abbrechen");
    }
  }
}

public freiew_waehleskin(playerid,classid)
{
  new sizeofarray[100];
  SetPlayerPos(playerid,-2701.30, 376.08, 4.97);
  SetPlayerFacingAngle(playerid,266);
  SetPlayerCameraPos(playerid, -2697.47, 376.39, 4.37);
  SetPlayerCameraLookAt(playerid, -2701.30, 376.08, 4.97);
  new binco[] = {1,3,4,5,10,30,31,38,39,53,54,77,78,79,88,89,95,129,134,135,136,137,158,159,160,161,162,168,196,197,198,199,200,205,210,212,213,218,230,231,232,239,252,}; //billig
  new suburban[] = {2,6,14,16,27,33,35,36,37,44,45,48,50,51,52,62,66,67,72,73,96,97,101,143,155,167,179,182,183,184,201,202,207,209,220,221,225,234,235,236,242,243,245,253,254,262,264,292,293};//gehobenes billiges
  new prolaps[] = {7,8,13,15,18,22,24,25,28,29,34,46,47,49,56,58,60,63,64,68,69,85,87,100,127,128,131,133,138,139,140,151,152,154,156,157,180,181,185,188,195,206,217,222,229,244,250,251,258,259,260,260,272,291}; //mittelklasse
  new zip[] = {19,20,21,23,41,59,70,82,83,84,92,93,99,142,170,178,191,192,193,215,223,224,226,237,238,241,246,247,248,256,257,263,290,297,298,299}; // gehobene mittelklasse
  new victim[] = {9,43,55,57,76,91,98,153,169,186,189,190,211,214,227,233,240,255,294}; //untere teuer
  new didiersachs[] = {11,12,17,40,61,141,147,148,150,187,194,216,219,228,249,295,296}; //teuer
  if(playerinshop[playerid] >= 54 && playerinshop[playerid] <= 57)
  {
    format(sizeofarray,100,"~w~ Skin: %i von %i",classid+1,sizeof(binco));
    if(classid >= sizeof(binco)) classid = sizeof(binco)-1;
    SetPlayerSkin(playerid,binco[classid]);
    playerwaehltskin[playerid] = binco[classid];
    GameTextForPlayer(playerid, sizeofarray,1000, 1);
  }
  else if(playerinshop[playerid] >= 58 && playerinshop[playerid] <= 59)
  {
    format(sizeofarray,100,"~w~ Skin: %i von %i",classid+1,sizeof(prolaps));
    if(classid >= sizeof(prolaps)) classid = sizeof(prolaps)-1;
    SetPlayerSkin(playerid,prolaps[classid]);
    playerwaehltskin[playerid] = prolaps[classid];
    GameTextForPlayer(playerid, sizeofarray, 1000, 1);
  }
  else if(playerinshop[playerid] >= 60 && playerinshop[playerid] <= 63)
  {
    format(sizeofarray,100,"~w~ Skin: %i von %i",classid+1,sizeof(zip));
    if(classid >= sizeof(zip)) classid = sizeof(zip)-1;
    SetPlayerSkin(playerid,zip[classid]);
    playerwaehltskin[playerid] = zip[classid];
    GameTextForPlayer(playerid, sizeofarray, 1000, 1);
  }
  else if(playerinshop[playerid] >= 64 && playerinshop[playerid] <= 66)
  {
    format(sizeofarray,100,"~w~ Skin: %i von %i",classid + 1,sizeof(suburban));
    if(classid >= sizeof(suburban)) classid = sizeof(suburban)-1;
    SetPlayerSkin(playerid,suburban[classid]);
    playerwaehltskin[playerid] = suburban[classid];
    GameTextForPlayer(playerid, sizeofarray, 1000, 1);
  }
  else if(playerinshop[playerid] >= 67 && playerinshop[playerid] <= 69)
  {
    format(sizeofarray,100,"~w~ Skin: %i von %i",classid+1,sizeof(victim));
    if(classid >= sizeof(victim)) classid = sizeof(victim)-1;
    SetPlayerSkin(playerid,victim[classid]);
    playerwaehltskin[playerid] = victim[classid];
    GameTextForPlayer(playerid, sizeofarray, 1000, 1);
  }
  else if(playerinshop[playerid] == 70)
  {
    format(sizeofarray,100,"~w~ Skin: %i von %i",classid+1,sizeof(didiersachs));
    if(classid >= sizeof(didiersachs)) classid = sizeof(didiersachs)-1;
    SetPlayerSkin(playerid,didiersachs[classid]);
    playerwaehltskin[playerid] = didiersachs[classid];
    GameTextForPlayer(playerid, sizeofarray, 1000, 1);
  }
}

public freiw_skinchange(playerid)
{
  SetPlayerInterior(playerid, floatround(shopsinter[floatround(shopsenter[playerinshop[playerid]][4])][0]));
  SetPlayerPos(playerid,shopsinter[floatround(shopsenter[playerinshop[playerid]][4])][7], shopsinter[floatround(shopsenter[playerinshop[playerid]][4])][8],shopsinter[floatround(shopsenter[playerinshop[playerid]][4])][9]);
  SetPlayerFacingAngle(playerid,shopsinter[floatround(shopsenter[playerinshop[playerid]][4])][10]); 
  SetPlayerHealth(playerid,playerdata[playerid][7]);
  waehlekleidung[playerid] = 0;
  if(playerinshop[playerid] >= 54 && playerinshop[playerid] <= 57)
  {
    SetPlayerSkin(playerid,playerwaehltskin[playerid]);
  }
  ShowPlayerDialog(playerid,1002,DIALOG_STYLE_MSGBOX , "Skinwechsel", "Mцchten Sie diese Kleidung behalten?", "Ja, Kaufen", "Nein");
}
