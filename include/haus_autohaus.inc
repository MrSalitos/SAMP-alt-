forward autohaus();
forward stellegebautos();
forward auto_statechange(playerid, newstate, oldstate);
forward show_automsg(playerid,kind,vid,km,price);
forward auto_response(playerid, dialogid, response, listitem, inputtext[]);
forward loadplayercars();
forward loadplayercarsforplayer(accid);
forward auto_pickup(playerid,pickupid);
forward create_autopickupnew(model, type, Float:X, Float:Y, Float:Z, Virtualworld, &pickupid);

new gebautos[20][5],mitautos[20][5],sportautos[50][5],spezial[25][5]; // 0 ID, 1 => Preis, 2 KM, 3 Color1 ,4 color2
new gebverpick,mittverpick,bootsverpick,airverpick,autoversls,autoverslv,autoverssf,versexit,autovers,autozulpick;
new autoverplayerin[MAX_PLAYERS],userchangeschild[MAX_PLAYERS];

public autohaus()
{
  stellegebautos();
  loadplayercars();
}

public stellegebautos()
{
  new Float:mitautopos[][4] =
  {
    {-1666.31, 1207.75, 13.67, 302.53},
    {-1664.92, 1222.39, 13.67, 233.59},
    {-1649.98, 1209.58, 13.67, 65.98},
    {-1667.64, 1205.08, 21.15, 294.69},
    {-1663.31, 1220.84, 21.15, 208.21},
    {-1649.23, 1206.02, 21.14, 52.51},
    {-1662.47, 1214.05, 7.25, 256.49}
  };
  new Float:gebautopos[][4] =
  {
    {2135.08, -1132.04, 25.46, 33.5},
    {2135.36, -1127.41, 25.33, 33.5},
    {2136.03, -1137.85, 25.32, 33.5},
    {2135.35, -1142.77, 24.77, 33.5},
    {2117.02, -1125.81, 25.09, 0.0},
    {2117.24, -1132.95, 24.98, 0.0},
    {2117.75, -1146.34, 24.29, 0.0},
    {2123.27, -1142.54, 24.21, 0.0},
    {2129.87, -1147.64, 24.18, 0.0}
  };
  new gebautosids[][2] =
  {
    {401,3500},
    {604,1500},
    {474,2500},
    {466,3500},
    {580,3500},
    {542,3000},
    {404,4000},
    {462,1500},
    {586,2000},
    {471,3500},
    {605,1500},
    {478,1500},
    {439,2500},
    {440,3100},
    {518,2500},
    {517,3750},
    {526,3250},
    {527,3450},
    {536,4000},
    {566,3750},
    {567,3850},
    {575,2750},
    {576,2950},
    {600,3750}
  };
  new mitautosids[][2] =
  {
    {400,10000},
    {410,10000},
    {412,8000},
    {413,12000},
    {419,15000},
    {418,12500},
    {421,13500},
    {422,9500},
    {458,13500},
    {467,14500},
    {479,12500},
    {482,11750},
    {483,13250},
    {489,14500},
    {491,11750},
    {492,10250},
    {500,12150},
    {504,13650},
    {516,11750},
    {529,9750},
    {533,11450},
    {534,13459},
    {535,11459},
    {535,12500},
    {540,12500},
    {546,13000},
    {550,14600},
    {551,13500},
    {554,12540},
    {561,11750},
    {579,13500},
    {585,12590},
    {508,13500},
    {483,12500}
  };
  new Float:mitautopos1[][4] =
  {
    {-1955.63, 258.49, 41.04, 231.40},
    {-1955.05, 266.61, 41.04, 231.40},
    {-1956.05, 273.17, 41.04, 243.00},
    {-1944.55, 274.95, 41.04, 184.40},
    {-1955.18, 303.35, 35.46, 125.81},
    {-1956.18, 292.73, 35.46, 129.25},
    {-1956.23, 281.51, 35.46, 127.69},
    {-1957.26, 268.98, 35.46, 122.99},
    {-1946.04, 272.89, 35.47, 128.02},
    {-1946.92, 262.24, 35.46, 122.70}
  };
  new Float:gebautopos1[][4] =
  {
    {1078.05, -1754.85, 13.29, 90.0},
    {1077.48, -1760.80, 13.27, 90.00},
    {1077.43, -1766.81, 13.25, 90.0},
    {1077.50, -1772.77, 13.24, 90.0},
    {1062.76, -1772.44, 13.25, 270.0},
    {1062.84, -1766.84, 13.27, 270.0},
    {1062.60, -1761.03, 13.29, 270.0},
    {1062.46, -1754.94, 13.32, 270.0}
  };
  new sportautoids[][2] =
  {
    {402,35000},
    {411,45000},
    {415,55000},
    {424,25000},
    {429,47800},
    {434,65000},
    {444,75000},
    {451,51000},
    {470,33000},
    {475,27500},
    {477,46500},
    {480,31000},
    {494,77000},
    {495,71000},
    {496,36750},
    {502,77000},
    {503,77000},
    {506,75000},
    {541,65000},
    {559,53000},
    {565,37800},
    {589,32500},
    {602,48900},
    {603,54900}
  };
  new Float:sportautopos[][4] =
  {
    {1950.0, 1783.2, 12.39, 230.0},
    {1943.0, 1783.2, 12.39, 230.0},
    {1936.0, 1783.2, 12.39, 230.0},
    {1929.0, 1783.2, 12.39, 230.0},
    {1922.0, 1783.2, 12.39, 230.0},
    {1950.0, 1762.0, 12.46,320.0},
    {1943.0, 1762.0, 12.46,320.0},
    {1936.0, 1762.0, 12.47,320.0},
    {1929.0, 1762.0, 12.46,320.0},
    {1922.0, 1762.0, 12.46,320.0},
    {1972.0, 1751.0, 12.44,150.0},
    {1979.0, 1751.0, 12.44,150.0},
    {1986.0, 1751.0, 12.45,150.0},
    {1993.0, 1751.0, 12.45,150.0},
    {2000.0, 1751.0, 12.44,150.0}
  };
  new Float:bikespos[][4] =
  {
    {1920.90, 1772.79, 12.55,270.0},
    {1929.58, 1772.65, 12.55,270.0},
    {1938.45, 1772.51, 12.55,270.0},
    {1943.50, 1772.52, 12.55,270.0},
    {1951.64, 1772.52, 12.55,270.0}
  };
  new bikeids[][2] =
  {
    {522,25000},
    {461,18500},
    {521,17500},
    {463,15000},
    {468,10000}
  };
  new Float:bootpos[][4] =
  {
    {2292.0, 514.0, 0.2,180.0},
    {2297.0, 514.0, 0.2,180.0},
    {2351.5, 514.0, 0.2,180.0},
    {2359.5, 514.0, 0.2,180.0},
    {2367.7, 514.0, 0.2,180.0}
  };
  new bootids[][2] =
  {
    {473,17500},
    {493,145000},
    {595,185000},
    {484,235000},
    {452,275000},
    {539,25000},
    {460,125000}
  };
  new Float:airpos[][4] =
  {
    {2096.0, -2640.0, 13.5,0.0},
    {2064.0, -2640.0, 13.5,0.0},
    {2032.0, -2640.0, 13.5,0.0},
    {2000.0, -2640.0, 13.5,0.0},
    {1968.0, -2640.0, 13.5,0.0},
    {1564.0, -2640.0, 13.5,0.0},
    {1532.0, -2640.0, 13.5,0.0},
    {1500.0, -2640.0, 13.5,0.0},
    {1468.0, -2640.0, 13.5,0.0},
    {1436.0, -2640.0, 13.5,0.0},
    {1404.0, -2640.0, 13.5,0.0}
  };
  new airids[][2] =
  {
    {512,175000},
    {593,180000},
    {519,250000},
    {513,195000},
    {487,150000}
  };
  
  new v,color1,color2;
  //Gebrauchtwagen stellen
  for(new i = 0;i < sizeof(gebautopos);i++)
  {
    if(gebautos[i][0] == 0)
    {
      color1 = random(120);
      color2 = random(120);
      v = random(sizeof(gebautosids));
      gebautos[i][0] = CreateVehicleEx(gebautosids[v][0],gebautopos[i][0], gebautopos[i][1], gebautopos[i][2], gebautopos[i][3], color1,color2, -1,0,100000 + (10000 * random(4)),"");
      gebautos[i][1] = gebautosids[v][1];
      gebautos[i][3] = color1;
      gebautos[i][4] = color2;
    }
	else
	{
	  new Float:vehx, Float:vehy, Float:vehz;
      GetVehiclePos(gebautos[i][0], vehx, vehy, vehz);
	  if(floatround(vehx) != floatround(gebautopos[i][0]) || floatround(vehy) != floatround(gebautopos[i][1]))
		SetVehicleToRespawn(gebautos[i][0]);
	}
  }
  //Gebrauchtwagen 1
  for(new i = sizeof(gebautopos);i < (sizeof(gebautopos) + sizeof(gebautopos1)) ;i++)
  {
    if(gebautos[i][0] == 0)
    {
      color1 = random(120);
      color2 = random(120);
      v = random(sizeof(gebautosids));
      gebautos[i][0] = CreateVehicleEx(gebautosids[v][0],gebautopos1[(i-sizeof(gebautopos))][0], gebautopos1[(i-sizeof(gebautopos))][1], gebautopos1[(i-sizeof(gebautopos))][2], gebautopos1[(i-sizeof(gebautopos))][3], color1,color2, -1,0,100000 + (10000 * random(4)),"");
      gebautos[i][1] = gebautosids[v][1];
      gebautos[i][3] = color1;
      gebautos[i][4] = color2;
    }
	else
	{
	  new Float:vehx, Float:vehy, Float:vehz;
      GetVehiclePos(gebautos[i][0], vehx, vehy, vehz);
	  if(floatround(vehx) != floatround(gebautopos1[(i-sizeof(gebautopos))][0]) || floatround(vehy) != floatround(gebautopos1[(i-sizeof(gebautopos))][1]))
		SetVehicleToRespawn(gebautos[i][0]);
	}
  }
  //Mittelklasse
  for(new i = 0;i < sizeof(mitautopos);i++)
  {
    if(mitautos[i][0] == 0)
    {
      color1 = random(120);
      color2 = random(120);
      v = random(sizeof(mitautosids));
      mitautos[i][0] = CreateVehicleEx(mitautosids[v][0],mitautopos[i][0], mitautopos[i][1], mitautopos[i][2], mitautopos[i][3], color1,color2, -1,0,50000 + (2500 * random(4)),"");
      mitautos[i][1] = mitautosids[v][1];
      mitautos[i][3] = color1;
      mitautos[i][4] = color2;
    }
	else
	{
	  new Float:vehx, Float:vehy, Float:vehz;
      GetVehiclePos(mitautos[i][0], vehx, vehy, vehz);
	  if(floatround(vehx) != floatround(mitautopos[i][0]) || floatround(vehy) != floatround(mitautopos[i][1]))
		SetVehicleToRespawn(mitautos[i][0]);
	}
  }
  //Mittelklasse 2 
  for(new i = sizeof(mitautopos);i < (sizeof(mitautopos1) + sizeof(mitautopos));i++)
  {
    if(mitautos[i][0] == 0)
    {
      color1 = random(120);
      color2 = random(120);
      v = random(sizeof(mitautosids));
      mitautos[i][0] = CreateVehicleEx(mitautosids[v][0],mitautopos1[(i-sizeof(mitautopos))][0], mitautopos1[(i-sizeof(mitautopos))][1], mitautopos1[(i-sizeof(mitautopos))][2], mitautopos1[(i-sizeof(mitautopos))][3], color1,color2, -1,0,50000 + (2500 * random(4)),"");
      mitautos[i][1] = mitautosids[v][1];
      mitautos[i][3] = color1;
      mitautos[i][4] = color2;
    }
	else
	{
	  new Float:vehx, Float:vehy, Float:vehz;
      GetVehiclePos(mitautos[i][0], vehx, vehy, vehz);
	  if(floatround(vehx) != floatround(mitautopos1[(i-sizeof(mitautopos))][0]) || floatround(vehy) != floatround(mitautopos1[(i-sizeof(mitautopos))][1]))
		SetVehicleToRespawn(mitautos[i][0]);
	}
  }
  //Sportautos
  for(new i = 0;i < sizeof(sportautopos);i++)
  {
    if(sportautos[i][0] == 0)
    {
      color1 = random(120);
      color2 = random(120);
      v = random(sizeof(sportautoids));
      sportautos[i][0] = CreateVehicleEx(sportautoids[v][0],sportautopos[i][0], sportautopos[i][1], sportautopos[i][2], sportautopos[i][3], color1,color2, -1,0,0 + (50 * random(4)),"");
      sportautos[i][1] = sportautoids[v][1];
      sportautos[i][3] = color1;
      sportautos[i][4] = color2;
    }
	else
	{
	  new Float:vehx, Float:vehy, Float:vehz;
      GetVehiclePos(sportautos[i][0], vehx, vehy, vehz);
	  if(floatround(vehx) != floatround(sportautopos[i][0]) || floatround(vehy) != floatround(sportautopos[i][1]))
		SetVehicleToRespawn(sportautos[i][0]);
	}
  }
  //Bikes
  for(new i= sizeof(sportautopos); i < (sizeof(sportautopos) + sizeof(bikespos));i++)
  {
    if(sportautos[i][0] == 0)
    {
      color1 = random(120);
      color2 = random(120);
      v = random(sizeof(bikeids));
      sportautos[i][0] = CreateVehicleEx(bikeids[v][0],bikespos[(i-sizeof(sportautopos))][0], bikespos[(i-sizeof(sportautopos))][1], bikespos[(i-sizeof(sportautopos))][2], bikespos[(i-sizeof(sportautopos))][3], color1,color2, -1,0,(50 * random(4)),"");
      sportautos[i][1] = bikeids[v][1];
      sportautos[i][3] = color1;
      sportautos[i][4] = color2;
    }
	else
	{
	  new Float:vehx, Float:vehy, Float:vehz;
      GetVehiclePos(sportautos[i][0], vehx, vehy, vehz);
	  if(floatround(vehx) != floatround(bikespos[(i-sizeof(sportautopos))][0]) || floatround(vehy) != floatround(bikespos[(i-sizeof(sportautopos))][1]))
		SetVehicleToRespawn(sportautos[i][0]);
	}
  }
  //Boote
  for(new i = 0;i < sizeof(bootpos);i++)
  {
    if(spezial[i][0] == 0)
    {
      color1 = random(120);
      color2 = random(120);
      v = random(sizeof(bootids));
      spezial[i][0] = CreateVehicleEx(bootids[v][0],bootpos[i][0], bootpos[i][1], bootpos[i][2], bootpos[i][3], color1,color2, -1,0,0 + (50 * random(4)),"");
      spezial[i][1] = bootids[v][1];
      spezial[i][3] = color1;
      spezial[i][4] = color2;
    }
	else
	{
	  new Float:vehx, Float:vehy, Float:vehz;
      GetVehiclePos(spezial[i][0], vehx, vehy, vehz);
	  if(floatround(vehx) != floatround(bootpos[i][0]) || floatround(vehy) != floatround(bootpos[i][1]))
		SetVehicleToRespawn(spezial[i][0]);
	}
  }
  //Air
  for(new i = sizeof(bootpos);i < (sizeof(bootpos) + sizeof(airpos));i++)
  {
    if(spezial[i][0] == 0)
    {
      color1 = random(120);
      color2 = random(120);
      v = random(sizeof(airids));
      spezial[i][0] = CreateVehicleEx(airids[v][0],airpos[(i-sizeof(bootpos))][0], airpos[(i-sizeof(bootpos))][1], airpos[(i-sizeof(bootpos))][2], airpos[(i-sizeof(bootpos))][3], color1,color2, -1,0,0 + (50 * random(4)),"");
      spezial[i][1] = airids[v][1];
      spezial[i][3] = color1;
      spezial[i][4] = color2;
    }
	else
	{
	  new Float:vehx, Float:vehy, Float:vehz;
      GetVehiclePos(spezial[i][0], vehx, vehy, vehz);
	  if(floatround(vehx) != floatround(airpos[(i-sizeof(bootpos))][0]) || floatround(vehy) != floatround(airpos[(i-sizeof(bootpos))][1]))
		SetVehicleToRespawn(spezial[i][0]);
	}
  }

  //Verkaufspickup für Wagen
  gebverpick = CreatePickup(1274 , 14, 2126.56, -1138.36, 25.3, -1);
  Create3DTextLabel("Fahrzeug Verkaufen",COLOR_WHITE,2126.56, -1138.36, 26,15,0);

  mittverpick = CreatePickup(1274 , 14, -1986.12, 303.16, 35.5, -1);
  Create3DTextLabel("Fahrzeug Verkaufen",COLOR_WHITE,-1986.12, 303.16, 35.9,15,0);
  
  bootsverpick = CreatePickup(1274 , 14, 2374.39, 525.25, 1, -1);
  Create3DTextLabel("Boot Verkaufen",COLOR_WHITE,2374.39, 525.25, 1.5,15,0);
  
  airverpick = CreatePickup(1274 , 14, 1935.92, -2637.98, 13.5, -1);
  Create3DTextLabel("Flugzeug Verkaufen",COLOR_WHITE,1935.92, -2637.98, 13.9,15,0);
  
  autoversls = CreatePickup(1559 , 1, 1110.65, -1795.96, 16.6, -1);
  Create3DTextLabel("LS Versicherungen\nbetreten",COLOR_WHITE,1110.65, -1795.96, 16.9,15,0);
  
  autoverssf = CreatePickup(1559 , 1, -2664.78, -9.99, 6.0, -1);
  Create3DTextLabel("SF Versicherungen\nbetreten",COLOR_WHITE,-2664.78, -9.99, 6.3,15,0);
  
  autoverslv = CreatePickup(1559 , 1, 1841.92, 2155.90, 11.3, -1);
  Create3DTextLabel("LV Versicherungen\nbetreten",COLOR_WHITE,1841.92, 2155.90, 11.5,15,0);
  
  versexit = CreatePickup(1559 , 1, 390.60, 173.83, 1008.38, -1);
  Create3DTextLabel("Gebäude verlassen",COLOR_WHITE,390.60, 173.83, 1008.5,15,1,false);
  Create3DTextLabel("Gebäude verlassen",COLOR_WHITE,390.60, 173.83, 1008.5,15,2,false);
  Create3DTextLabel("Gebäude verlassen",COLOR_WHITE,390.60, 173.83, 1008.5,15,3,false);
  
  CreatePickup(1239 , 1, 364.06, 173.65, 1008.38, -1);
  Create3DTextLabel("{FF0000}Autoversichung:\n{FFFFFF} bitte rechts durch die Tür\n\n{FF0000}Zulassungstelle:\n{FFFFFF} 1. OG \n\n",COLOR_WHITE,364.06, 173.65, 1008.5,10,1,false);
  Create3DTextLabel("{FF0000}Autoversichung:\n{FFFFFF} bitte rechts durch die Tür\n\n{FF0000}Zulassungstelle:\n{FFFFFF} 1. OG \n\n",COLOR_WHITE,364.06, 173.65, 1008.5,10,2,false);
  Create3DTextLabel("{FF0000}Autoversichung:\n{FFFFFF} bitte rechts durch die Tür\n\n{FF0000}Zulassungstelle:\n{FFFFFF} 1. OG \n\n",COLOR_WHITE,364.06, 173.65, 1008.5,10,3,false);
  
  CreatePickup(1239 , 1, 364.80, 173.14, 1014.18, -1);
  Create3DTextLabel("{FF0000}Zulassungsstelle:\n{FFFFFF} rechts durch die Tür \n\n",COLOR_WHITE,364.80, 173.14, 1014.5,10,1,false);
  Create3DTextLabel("{FF0000}Zulassungsstelle:\n{FFFFFF} rechts durch die Tür \n\n",COLOR_WHITE,364.80, 173.14, 1014.5,10,2,false);
  Create3DTextLabel("{FF0000}Zulassungsstelle:\n{FFFFFF} rechts durch die Tür \n\n",COLOR_WHITE,364.80, 173.14, 1014.5,10,3,false);
  
  autozulpick = CreatePickup(1239 , 1, 374.36, 185.95, 1014.18, -1);
  Create3DTextLabel("Zulassungsstelle",COLOR_WHITE,374.36, 185.95, 1014.5,10,1,false);
  Create3DTextLabel("Zulassungsstelle",COLOR_WHITE,374.36, 185.95, 1014.5,10,2,false);
  Create3DTextLabel("Zulassungsstelle",COLOR_WHITE,374.36, 185.95, 1014.5,10,3,false);

  autovers = CreatePickup(1239 , 1, 361.18, 205.07, 1008.5, -1);
  Create3DTextLabel("Auto Versicherung",COLOR_WHITE,361.18, 205.07, 1008.8,10,1,false);
  Create3DTextLabel("Auto Versicherung",COLOR_WHITE,361.18, 205.07, 1008.8,10,2,false);
  Create3DTextLabel("Auto Versicherung",COLOR_WHITE,361.18, 205.07, 1008.8,10,3,false);
  
  CreateDynamicMapIcon(2126.56, -1138.36, 25.3, 55, -1,-1, -1, -1, 500);
  CreateDynamicMapIcon(1077.50, -1772.77, 13.24, 55, -1,-1, -1, -1, 500);
  CreateDynamicMapIcon(-1956.18, 292.73, 35.46, 55, -1,-1, -1, -1, 500);
  CreateDynamicMapIcon(-1662.47, 1214.05, 7.25, 55, -1,-1, -1, -1, 500);
  CreateDynamicMapIcon(1938.45, 1772.51, 12.55, 55, -1,-1, -1, -1, 500);
  CreateDynamicMapIcon(2351.5, 514.0, 0.2, 9, -1,-1, -1, -1, 500);
  CreateDynamicMapIcon(1968.0, -2640.0, 13.5, 5, -1,-1, -1, -1, 500);
}

public auto_statechange(playerid, newstate, oldstate)
{
  if(PLAYER_STATE:newstate == PLAYER_STATE_DRIVER)
  {
    for(new i;i < sizeof(gebautos);i++)
    {
      if(gebautos[i][0] == GetPlayerVehicleID(playerid))
        show_automsg(playerid,0,GetPlayerVehicleID(playerid),gebautos[i][2],gebautos[i][1]);
    }
    for(new i;i < sizeof(mitautos);i++)
    {
      if(mitautos[i][0] == GetPlayerVehicleID(playerid))
        show_automsg(playerid,1,GetPlayerVehicleID(playerid),mitautos[i][2],mitautos[i][1]);
    }
    for(new i;i < sizeof(sportautos);i++)
    {
      if(sportautos[i][0] == GetPlayerVehicleID(playerid))
        show_automsg(playerid,2,GetPlayerVehicleID(playerid),sportautos[i][2],sportautos[i][1]);
    }
    for(new i;i < sizeof(spezial);i++)
    {
      if(spezial[i][0] == GetPlayerVehicleID(playerid))
        show_automsg(playerid,3,GetPlayerVehicleID(playerid),spezial[i][2],spezial[i][1]);
    }
  }
}

public show_automsg(playerid,kind,vid,km,price)
{
  new headline[100],output[250],string[100],id ;
  if(kind == 0)
  {
    format(headline,100,"Autokauf");
    strcat(output,"Autodaten:                                      \n");
    format(string,100,"    Preis: %i $\n",price);
    strcat(output,string);
    format(string,100,"    KM-Stand: %.0f\n",Fahrzeuge[vid][4]);
    strcat(output,string);
    if(Fahrzeugdaten[GetVehicleModel(vid)-400][3] == 0)
      strcat(output,"    Kraftstoff: Diesel\n");
    else if(Fahrzeugdaten[GetVehicleModel(vid)-400][3] == 1)
      strcat(output,"    Kraftstoff: Benzin\n");
    else
      strcat(output,"    Kraftstoff: Super\n");
    format(string,100,"    Verbrauch: %i l\n",Fahrzeugdaten[GetVehicleModel(vid)-400][1]);
    strcat(output,string);
    format(string,100,"    Tank: %i l\n",floatround(Fahrzeugdaten[GetVehicleModel(vid)-400][0]));
    strcat(output,string);
    id = 76;
  }
  else if(kind == 1)
  {
    format(headline,100,"Autokauf");
    strcat(output,"Autodaten:                                      \n");
    format(string,100,"    Preis: %i $\n",price);
    strcat(output,string);
    format(string,100,"    KM-Stand: %.0f\n",Fahrzeuge[vid][4]);
    strcat(output,string);
    if(Fahrzeugdaten[GetVehicleModel(vid)-400][3] == 0)
      strcat(output,"    Kraftstoff: Diesel\n");
    else if(Fahrzeugdaten[GetVehicleModel(vid)-400][3] == 1)
      strcat(output,"    Kraftstoff: Benzin\n");
    else
      strcat(output,"    Kraftstoff: Super\n");
    format(string,100,"    Verbrauch: %i l\n",Fahrzeugdaten[GetVehicleModel(vid)-400][1]);
    strcat(output,string);
    format(string,100,"    Tank: %i l\n",floatround(Fahrzeugdaten[GetVehicleModel(vid)-400][0]));
    strcat(output,string);
    id = 77;
  }
  else if(kind == 2)
  {
    format(headline,100,"Autokauf");
    strcat(output,"Autodaten:                                      \n");
    format(string,100,"    Preis: %i $\n",price);
    strcat(output,string);
    format(string,100,"    KM-Stand: %.0f\n",Fahrzeuge[vid][4]);
    strcat(output,string);
    if(Fahrzeugdaten[GetVehicleModel(vid)-400][3] == 0)
      strcat(output,"    Kraftstoff: Diesel\n");
    else if(Fahrzeugdaten[GetVehicleModel(vid)-400][3] == 1)
      strcat(output,"    Kraftstoff: Benzin\n");
    else
      strcat(output,"    Kraftstoff: Super\n");
    format(string,100,"    Verbrauch: %i l\n",Fahrzeugdaten[GetVehicleModel(vid)-400][1]);
    strcat(output,string);
    format(string,100,"    Tank: %i l\n",floatround(Fahrzeugdaten[GetVehicleModel(vid)-400][0]));
    strcat(output,string);
    id = 78;
  }
  else if(kind == 3)
  {
    format(headline,100,"Fahrzeugkauf");
    strcat(output,"Autodaten:                                      \n");
    format(string,100,"    Preis: %i $\n",price);
    strcat(output,string);
    format(string,100,"    KM-Stand: %.0f\n",Fahrzeuge[vid][4]);
    strcat(output,string);
    if(Fahrzeugdaten[GetVehicleModel(vid)-400][3] == 0)
      strcat(output,"    Kraftstoff: Diesel\n");
    else if(Fahrzeugdaten[GetVehicleModel(vid)-400][3] == 1)
      strcat(output,"    Kraftstoff: Benzin\n");
    else
      strcat(output,"    Kraftstoff: Super\n");
    format(string,100,"    Verbrauch: %i l\n",Fahrzeugdaten[GetVehicleModel(vid)-400][1]);
    strcat(output,string);
    format(string,100,"    Tank: %i l\n",floatround(Fahrzeugdaten[GetVehicleModel(vid)-400][0]));
    strcat(output,string);
    id = 79;
  }
  
  format(string,100,"SELECT COUNT(*) as anz FROM user_vehicles WHERE accid=%i",playerdata[playerid][0]);
  mysql_query(string);
  mysql_store_result();
  mysql_fetch_field("anz",string);
  mysql_free_result();
  
  if(playerdata[playerid][56] == 0 && strval(string) < 3 && kind < 3)
    ShowPlayerDialog(playerid, id,DIALOG_STYLE_MSGBOX,headline,output,"Kaufen","Aussteigen");
  else if(playerdata[playerid][56] == 1 && strval(string) < 5)
    ShowPlayerDialog(playerid, id,DIALOG_STYLE_MSGBOX,headline,output,"Kaufen","Aussteigen");
  else
    ShowPlayerDialog(playerid, 89,DIALOG_STYLE_MSGBOX,headline,output,"Aussteigen","");
}

public auto_response(playerid, dialogid, response, listitem, inputtext[])
{
  if(dialogid == 76)
  {
    if(response)
    {
      for(new i;i < sizeof(gebautos);i++)
      {
        if(gebautos[i][0] == GetPlayerVehicleID(playerid))
        {
          if(giveusermoney(playerid,-1 * gebautos[i][1]))
          {
            Fahrzeuge[GetPlayerVehicleID(playerid)][3] = playerdata[playerid][0];
            gebautos[i][0] = 0;
            SetTimer("stellegebautos",10000,false);
            insert_playervehicle(playerid,GetPlayerVehicleID(playerid),GetVehicleModel(GetPlayerVehicleID(playerid)),Fahrzeuge[GetPlayerVehicleID(playerid)][4],Fahrzeuge[GetPlayerVehicleID(playerid)][1],Fahrzeugdaten[GetVehicleModel(GetPlayerVehicleID(playerid))-400][0],gebautos[i][3],gebautos[i][4]);
            i = sizeof(gebautos);
          }
          else
          {
            RemovePlayerFromVehicle(playerid);
            GameTextForPlayer(playerid,"~r~Sie haben nicht genug Geld.",3000,3);
          }
        }
      }
    }
    else
      RemovePlayerFromVehicle(playerid);
  }
  if(dialogid == 77)
  {
    if(response)
    {
      for(new i;i < sizeof(mitautos);i++)
      {
        if(mitautos[i][0] == GetPlayerVehicleID(playerid))
        {
          if(giveusermoney(playerid,-1 * mitautos[i][1]))
          {
            new v = GetPlayerVehicleID(playerid);
            Fahrzeuge[v][3] = playerdata[playerid][0];
            mitautos[i][0] = 0;
            if(i < 7)
            {
              SetVehiclePos(v, -1639.18, 1211.20, 7.17);
              SetVehicleZAngle(v, 224.53);
              PutPlayerInVehicle(playerid,v,0);
            }
            else
            {
              SetVehiclePos(v, -1978.70, 258.21, 35.17);
              SetVehicleZAngle(v, 352.81);
              PutPlayerInVehicle(playerid,v,0);
            }
            SetTimer("stellegebautos",10000,false);
            GameTextForPlayer(playerid,"~w~Ihr Auto!",3000,3);
            insert_playervehicle(playerid,v,GetVehicleModel(v),Fahrzeuge[v][4],Fahrzeuge[v][1],Fahrzeugdaten[GetVehicleModel(v)-400][0],mitautos[i][3],mitautos[i][4]);
            i = sizeof(mitautos);
          }
          else
          {
            RemovePlayerFromVehicle(playerid);
            GameTextForPlayer(playerid,"~r~Sie haben nicht genug Geld.",3000,3);
          }
        }
      }
    }
    else
      RemovePlayerFromVehicle(playerid);
  }
  if(dialogid == 78)
  {
    if(response)
    {
      for(new i;i < sizeof(sportautos);i++)
      {
        if(sportautos[i][0] == GetPlayerVehicleID(playerid))
        {
          if(giveusermoney(playerid,-1 * sportautos[i][1]))
          {
            new v = GetPlayerVehicleID(playerid);
            Fahrzeuge[v][3] = playerdata[playerid][0];
            sportautos[i][0] = 0;
            SetTimer("stellegebautos",10000,false);
            GameTextForPlayer(playerid,"~w~Ihr Auto!",3000,3);
            insert_playervehicle(playerid,v,GetVehicleModel(v),Fahrzeuge[v][4],Fahrzeuge[v][1],Fahrzeugdaten[GetVehicleModel(v)-400][0],sportautos[i][3],sportautos[i][4]);
            i = sizeof(sportautos);
          }
          else
          {
            RemovePlayerFromVehicle(playerid);
            GameTextForPlayer(playerid,"~r~Sie haben nicht genug Geld.",3000,3);
          }
        }
      }
    }
    else
      RemovePlayerFromVehicle(playerid);
  }
  if(dialogid == 79)
  {
    if(response)
    {
      for(new i;i < sizeof(spezial);i++)
      {
        if(spezial[i][0] == GetPlayerVehicleID(playerid))
        {
          if(giveusermoney(playerid,-1 * spezial[i][1]))
          {
            new v = GetPlayerVehicleID(playerid);
            Fahrzeuge[v][3] = playerdata[playerid][0];
            spezial[i][0] = 0;
            SetTimer("stellegebautos",10000,false);
            GameTextForPlayer(playerid,"~w~Ihr Fahrzeug!",3000,3);
            insert_playervehicle(playerid,v,GetVehicleModel(v),Fahrzeuge[v][4],Fahrzeuge[v][1],Fahrzeugdaten[GetVehicleModel(v)-400][0],spezial[i][3],spezial[i][4]);
            i = sizeof(spezial);
          }
          else
          {
            RemovePlayerFromVehicle(playerid);
            GameTextForPlayer(playerid,"~r~Sie haben nicht genug Geld.",3000,3);
          }
        }
      }
    }
    else
      RemovePlayerFromVehicle(playerid);
  }
  if(dialogid == 85 && response)
  {
    new output[250],price;
    if(Fahrzeuge[GetPlayerVehicleID(playerid)][4] < 25000) price = 7500;
    else if(Fahrzeuge[GetPlayerVehicleID(playerid)][4] < 50000) price = 5000;
    else if(Fahrzeuge[GetPlayerVehicleID(playerid)][4] < 75000) price = 4000;
    else if(Fahrzeuge[GetPlayerVehicleID(playerid)][4] < 100000) price = 2500;
    else if(Fahrzeuge[GetPlayerVehicleID(playerid)][4] < 125000) price = 1500;
    else price = 1500;
    price = floatround(price - (1000-Fahrzeuge[GetPlayerVehicleID(playerid)][1]));
    giveusermoney(playerid,price);
    format(output,250,"DELETE FROM `user_vehicles` WHERE vid=%i AND accid=%i",GetPlayerVehicleID(playerid),playerdata[playerid][0]);
    mysql_query(output);
    DestroyVehicle(GetPlayerVehicleID(playerid));
    GameTextForPlayer(playerid,"~w~Auto wurde verkauft.",3000,3);
  }
  if(dialogid == 86 && response)
  {
    new output[250],price;
    if(Fahrzeuge[GetPlayerVehicleID(playerid)][4] < 25000) price = 13000;
    else if(Fahrzeuge[GetPlayerVehicleID(playerid)][4] < 50000) price = 10000;
    else if(Fahrzeuge[GetPlayerVehicleID(playerid)][4] < 75000) price = 7500;
    else price = 0;
    price = floatround(price - (1000-Fahrzeuge[GetPlayerVehicleID(playerid)][1]));
    giveusermoney(playerid,price);
    format(output,250,"DELETE FROM `user_vehicles` WHERE vid=%i AND accid=%i",GetPlayerVehicleID(playerid),playerdata[playerid][0]);
    mysql_query(output);
    DestroyVehicle(GetPlayerVehicleID(playerid));
    GameTextForPlayer(playerid,"~w~Auto wurde verkauft.",3000,3);
  }
  if(dialogid == 87 && response)
  {
    new output[250],price;
    new mid = GetVehicleModel(GetPlayerVehicleID(playerid));
    if(mid == 493 || mid == 595 || mid == 484 || mid == 452 || mid == 460)
      price = 100000;
    else if(mid == 473 || mid == 539)
      price = 10000;
    else
      price = 0;
    price = floatround(price - (1000-Fahrzeuge[GetPlayerVehicleID(playerid)][1]));
    giveusermoney(playerid,price);
    format(output,250,"DELETE FROM `user_vehicles` WHERE vid=%i AND accid=%i",GetPlayerVehicleID(playerid),playerdata[playerid][0]);
    mysql_query(output);
    DestroyVehicle(GetPlayerVehicleID(playerid));
    GameTextForPlayer(playerid,"~w~Boot wurde verkauft.",3000,3);
  }
  if(dialogid == 80 && response)
  {
    new output[250],query[150],data[150],string[150],id = 84;
    if(listitem == 0)
    {
      format(query,150,"SELECT modelid,buyat FROM user_vehicles WHERE destroy != 2 AND vers = 0 AND accid = %i ORDER BY id",playerdata[playerid][0]);
      mysql_query(query);
      mysql_store_result();
      
      while(mysql_fetch_row(data))
      {
        mysql_fetch_field("modelid",data);
        format(string,150,"%s gekauft am: ",Fahrzeugname[strval(data)-400]);
        strcat(output,string);
        mysql_fetch_field("buyat",data);
        format(string,150,"%s \n",data);
        strcat(output,string);
        id = 81;
      }
      if(strlen(output) < 3) output = "Sie haben kein Fahrzeug zum Versichern";
      ShowPlayerDialog(playerid, id, DIALOG_STYLE_LIST, "Autoversicherung beantragen", output, "Versichern", "Abbrechen");
      mysql_free_result();
    }
    else if(listitem == 1)
    {
      format(query,150,"SELECT modelid,buyat,vers FROM user_vehicles WHERE destroy != 0 AND accid = %i ORDER BY id",playerdata[playerid][0]);
      mysql_query(query);
      mysql_store_result();
      
      while(mysql_fetch_row(data))
      {
        mysql_fetch_field("modelid",data);
        format(string,150,"%s gekauft am: ",Fahrzeugname[strval(data)-400]);
        strcat(output,string);
        mysql_fetch_field("buyat",data);
        format(string,150,"%s ",data);
        strcat(output,string);
        mysql_fetch_field("vers",data);
        if(strval(data) == 1)
          format(string,150,"(versichtert Kosten: 500 $)\n",data);
        else
          format(string,150,"(nicht versichtert Kosten: 5000 $)\n",data);
        strcat(output,string);
        id = 82;
      }
      if(strlen(output) < 3) output = "Sie haben kein Fahrzeug was bei der Versicherung steht.";
      ShowPlayerDialog(playerid, id, DIALOG_STYLE_LIST, "Autoversicherung in Anspruch nehmen", output, "Bezahlen", "Abbrechen");
      mysql_free_result();
    }
    else
    {
      format(query,150,"SELECT modelid,buyat FROM user_vehicles WHERE vers = 1 AND accid = %i ORDER BY id",playerdata[playerid][0]);
      mysql_query(query);
      mysql_store_result();
      while(mysql_fetch_row(data))
      {
        mysql_fetch_field("modelid",data);
        format(string,150,"%s gekauft am: ",Fahrzeugname[strval(data)-400]);
        strcat(output,string);
        mysql_fetch_field("buyat",data);
        format(string,150,"%s \n",data);
        strcat(output,string);
        id = 83;
      }
      if(strlen(output) < 3) output = "Sie haben kein Fahrzeug versichert.";
      ShowPlayerDialog(playerid, id, DIALOG_STYLE_LIST, "Autoversicherung kündigen", output, "Kündigen", "Abbrechen");
      mysql_free_result();
    }
  }
  if(dialogid == 81)
  {
    new query[150];
    if(response)
    {
      new data[25];
      format(query,150,"SELECT id FROM user_vehicles WHERE accid = %i ORDER BY id LIMIT %i,1",playerdata[playerid][0],listitem);
      mysql_query(query);
      mysql_store_result();
      mysql_fetch_field("id",data);
      mysql_free_result();
      format(query,150,"UPDATE user_vehicles SET vers = 1 WHERE id = %i ORDER BY id",strval(data));
      mysql_query(query);
      GameTextForPlayer(playerid, "~w~Sie haben ihr Auto versichert.", 3000, 3);
    }
    else
      auto_pickup(playerid,autovers);
  }
  if(dialogid == 82)
  {
    new money,ok = 0,modelid,color1,color2,km,schild[32],i,vid;
    new Float:verspos1[][4] =
    {
      {1083.16, -1754.92, 13.38, 280.0},
      {1083.47, -1760.52, 13.37, 280.0},
      {1083.68, -1766.59, 13.36, 280.0},
      {1084.28, -1773.14, 13.34, 280.0}
    };
    new Float:verspos2[][4] =
    {
      {-2663.20, -33.83, 4.33, 180.0},
      {-2669.57, -33.73, 4.33, 180.0},
      {-2669.71, -56.90, 4.33, 0.0},
      {-2676.11, -55.71, 4.33, 0.0}
    };
    new Float:verspos3[][4] =
    {
      {1914.28, 2158.71, 10.82, 90.0},
      {1913.20, 2148.10, 10.82, 90.0},
      {1881.63, 2140.95, 10.82, 280.0},
      {1882.65, 2129.21, 10.82, 280.0}
    };
    new Float:versairpos[][4] =
	{
	  {1547.91, -2442.03, 13.55, 180.0},
	  {1591.96, -2447.65, 13.55, 180.0},
	  {1625.95, -2449.60, 13.55, 180.0},
	  {1675.02, -2449.74, 13.55, 180.0}
	};
	new Float:verswaterpos[][4] =
	{
	  {1632.38, 566.14, -0.56, 180.0},
	  {1628.04, 566.93, -0.56, 180.0},
	  {1623.11, 564.29, -0.30, 180.0}
	};
	
    if(response)
    {
      new data[150],query[150],Float:posX,Float:posY,Float:posZ,Float:angle;
      format(query,150,"SELECT * FROM user_vehicles WHERE destroy != 0 AND accid = %i ORDER BY id LIMIT %i,1",playerdata[playerid][0],listitem);
      mysql_query(query);
      mysql_store_result();
      if(mysql_fetch_row(data))
      {
        mysql_fetch_field("vers",data);
        if(strval(data) == 1) money = -500;
        else money = -5000;
        if(giveusermoney(playerid,money))
        {
          ok = 1;
		  mysql_fetch_field("modelid",data);
          modelid = strval(data);
		  if(modelid == 512 || modelid == 593 || modelid == 519 || modelid == 513 || modelid == 487)
		  {
			i = random(sizeof(versairpos));
			posX = versairpos[i][0];
			posY = versairpos[i][1];
			posZ = versairpos[i][2];
			angle = versairpos[i][3];
			GameTextForPlayer(playerid,"~g~Ihr Flugzeug/Helicopter steht auf dem ~n~ LS Flughafen.",3000,3);
		  }
		  else if(modelid == 473 || modelid == 493 || modelid == 595 || modelid == 484 || modelid == 452 || modelid == 539 || modelid == 460)
		  {
			i = random(sizeof(verswaterpos));
			posX = verswaterpos[i][0];
			posY = verswaterpos[i][1];
			posZ = verswaterpos[i][2];
			angle = verswaterpos[i][3];
			GameTextForPlayer(playerid,"~g~Ihr Boot steht rechts vom Boothändler.",3000,3);
		  }
          else if(autoverplayerin[playerid] == 1)
          {
			i = random(sizeof(verspos1));
			posX = verspos1[i][0];
			posY = verspos1[i][1];
			posZ = verspos1[i][2];
			angle = verspos1[i][3];
			GameTextForPlayer(playerid,"~g~Ihr Auto steht vor der Versicherung.",3000,3);
		  }
		  else if(autoverplayerin[playerid] == 2)
          {
			i = random(sizeof(verspos2));
			posX = verspos2[i][0];
			posY = verspos2[i][1];
			posZ = verspos2[i][2];
			angle = verspos2[i][3];
			GameTextForPlayer(playerid,"~g~Ihr Auto steht vor der Versicherung.",3000,3);
		  }
		  else if(autoverplayerin[playerid] == 3)
          {
			i = random(sizeof(verspos3));
			posX = verspos3[i][0];
			posY = verspos3[i][1];
			posZ = verspos3[i][2];
			angle = verspos3[i][3];
			GameTextForPlayer(playerid,"~g~Ihr Auto steht vor der Versicherung.",3000,3);
		  }
          mysql_fetch_field("color1",data);
          color1 = strval(data);
          mysql_fetch_field("color2",data);
          color2 = strval(data);
          mysql_fetch_field("km",data);
          km = strval(data);
          mysql_fetch_field("schild",data);
          format(schild,32,"%s",data);
          vid = CreateVehicleEx(modelid, posX,posY,posZ,angle, color1, color2, -1,playerdata[playerid][0],km,schild);
          mysql_fetch_field("tank",data);   
          Fahrzeuge[vid][0] = floatstr(data);
          mysql_fetch_field("health",data);
          Fahrzeuge[vid][1] = floatstr(data);
          mysql_fetch_field("id",data);
          Fahrzeuge[vid][5] = strval(data);
		  
          format(query,150,"UPDATE user_vehicles SET destroy = 0,vid = %i WHERE id = %i",vid,strval(data));

        }
        else GameTextForPlayer(playerid,"~r~Sie haben nicht genug Geld.",3000,3);
      }
      mysql_free_result();
      if(ok == 1) mysql_query(query);
    }
    else
      auto_pickup(playerid,autovers);
  }
  if(dialogid == 83)
  {
    if(response)
    {
      new query2[150],data2[150];
      format(query2,150,"SELECT id FROM user_vehicles WHERE accid = %i ORDER BY id LIMIT %i,1",playerdata[playerid][0],listitem);
      mysql_query(query2);
      mysql_store_result();
      mysql_fetch_field("id",data2);
      mysql_free_result();
      format(query2,150,"UPDATE user_vehicles SET vers = 0 WHERE id = %i ORDER BY id",strval(data2));
      mysql_query(query2);
      GameTextForPlayer(playerid, "~w~Sie haben keine Autoversicherung mehr.", 3000, 3);
    }
    else
      auto_pickup(playerid,autovers);
  }
  if(dialogid == 88 && response)
  {
    new output[250],price;
    new mid = GetVehicleModel(GetPlayerVehicleID(playerid));
    if(mid == 512 || mid == 593 || mid == 519 || mid == 513 || mid == 487)
      price = 100000;
    else
      price = 0;
    price = floatround(price - (1000-Fahrzeuge[GetPlayerVehicleID(playerid)][1]));
    giveusermoney(playerid,price);
    format(output,250,"DELETE FROM `user_vehicles` WHERE vid=%i AND accid=%i",GetPlayerVehicleID(playerid),playerdata[playerid][0]);
    mysql_query(output);
    DestroyVehicle(GetPlayerVehicleID(playerid));
    GameTextForPlayer(playerid,"~w~Flugzeug wurde verkauft.",3000,3);
  }
  if(dialogid == 89) RemovePlayerFromVehicle(playerid);
  if(dialogid == 90 && response)
  {
    new query[150],data[32],output[250];
    format(query,150,"SELECT vid,schild FROM user_vehicles WHERE destroy = 0 AND accid = %i ORDER BY id LIMIT %i,1",playerdata[playerid][0],listitem);
    mysql_query(query);
    mysql_store_result();
	mysql_fetch_field("vid",data);
	userchangeschild[playerid] = strval(data);
    mysql_fetch_field("schild",data);
    mysql_free_result();
	format(output,250,"Sie können das Schild ihres Wagens beliebig verändern. \nBedenken Sie die maximal Länge von 10 Zeichen!\nDas Aktuelle lautet: %s\n Eine Änderung kostet sie 50 $!",data);
	ShowPlayerDialog(playerid, 91, DIALOG_STYLE_INPUT, "Kennzeichen verändern von", output, "Ändern", "Abbrechen");
  }
  if(dialogid == 91)
  {
	if(response)
	{
	  if(giveusermoney(playerid,-50))
	  {
		new schild2[10],query[150];
		format(schild2,10,"%s",inputtext);
		mysql_real_escape_string(schild2,schild2);
		format(query,150,"UPDATE user_vehicles SET schild='%s' WHERE vid = %i ORDER BY id",schild2,userchangeschild[playerid]);
		mysql_query(query);
		new Float:vehx, Float:vehy, Float:vehz;
		GetVehiclePos(userchangeschild[playerid], vehx, vehy, vehz);
		SetVehicleNumberPlate(userchangeschild[playerid],schild2);
		SetVehicleToRespawn(userchangeschild[playerid]);
		SetVehiclePos(userchangeschild[playerid], vehx, vehy, vehz);
		GameTextForPlayer(playerid, "~w~Sie haben ein neues Kennzeichen.", 3000, 3);
	  }
	  else
		GameTextForPlayer(playerid, "~w~Sie haben nicht genug Geld.", 3000, 3);
	}
	userchangeschild[playerid] = -1;
  }
}

stock insert_playervehicle(playerid,vid,modelid,Float:km,Float:health,Float:tank,color1,color2)
{
  new string[250],query[750]="INSERT INTO user_vehicles (`vid`, `accid`, `modelid`, `health`, `tank`, `km`, `buyat`, `color1`, `color2`) VALUES ";
  format(string,500,"(%i,%i,%i,%.2f,%.2f,%i,NOW(),%i,%i)",vid,playerdata[playerid][0],modelid,health,tank,floatround(km),color1,color2);
  strcat(query,string);
  mysql_query(query);
  new Float:posX,Float:posY,Float:posZ,Float:face;
  GetVehiclePos(vid, posX, posY, posZ);
  GetVehicleZAngle(vid, face);
  format(query,500,"UPDATE `user_vehicles` SET posX=%.2f, posY=%.2f, posZ=%.2f,face=%.2f,km=%i,tank=%.2f,health=%.2f WHERE vid=%i",posX,posY,posZ,face,floatround(Fahrzeuge[vid][4]),Fahrzeuge[vid][0],Fahrzeuge[vid][1],vid);
  mysql_query(query);
}

public loadplayercars()
{
  new data[100],query[100],vid;
  new modelid, Float:x, Float:y, Float:z, Float:angle, color1, color2,owner = 0,km = 0,schild[32] = "";
  mysql_query("UPDATE `user_vehicles` SET vid=0");
  query = "SELECT * FROM `user_vehicles` WHERE destroy = 0";
  mysql_query(query);
  mysql_store_result();
  new i = 0;
  while(mysql_fetch_row(data))
  {
    mysql_fetch_field("modelid",data);   modelid = strval(data);
    mysql_fetch_field("posX",data);      x = floatstr(data);
    mysql_fetch_field("posY",data);      y = floatstr(data);
    mysql_fetch_field("posZ",data);      z = floatstr(data);
    mysql_fetch_field("face",data);      angle = floatstr(data);
    mysql_fetch_field("color1",data);    color1 = strval(data);
    mysql_fetch_field("color2",data);    color2 = strval(data);
    mysql_fetch_field("accid",data);     owner = strval(data);
    mysql_fetch_field("km",data);        km = strval(data);
    mysql_fetch_field("schild",data);    format(schild,32,"%s",data);
    vid = CreateVehicleEx(modelid, x, y, z, angle, color1, color2, -1,owner,km,schild);
    mysql_fetch_field("tank",data);   
    Fahrzeuge[vid][0] = floatstr(data);
    mysql_fetch_field("health",data);
    Fahrzeuge[vid][1] = floatstr(data);
    mysql_fetch_field("id",data);
    Fahrzeuge[vid][5] = strval(data);
    i++;
  }
  new k = 0;
  for(new j = 0; k < i; j++)
  {
    if(floatround(Fahrzeuge[j][3]) != 0 && floatround(Fahrzeuge[j][5]) != 0)
    {
      format(query,150,"UPDATE user_vehicles SET vid = %i WHERE id = %i",j,floatround(Fahrzeuge[j][5]));
      mysql_query(query);
      k++;
      Fahrzeuge[j][5] = 0;
    }
  }
  mysql_free_result();
  return 1;
}

public loadplayercarsforplayer(accid)
{
  new data[100],query[100],vid;
  new modelid, Float:x, Float:y, Float:z, Float:angle, color1, color2,owner = 0,km = 0,schild[32] = "";
  format(query,100,"SELECT * FROM `user_vehicles` WHERE destroy = 1 AND accid=%i",accid);
  mysql_query(query);
  mysql_store_result();
  new i = 0;
  while(mysql_fetch_row(data))
  {
    mysql_fetch_field("modelid",data);   modelid = strval(data);
    mysql_fetch_field("posX",data);      x = floatstr(data);
    mysql_fetch_field("posY",data);      y = floatstr(data);
    mysql_fetch_field("posZ",data);      z = floatstr(data);
    mysql_fetch_field("face",data);      angle = floatstr(data);
    mysql_fetch_field("color1",data);    color1 = strval(data);
    mysql_fetch_field("color2",data);    color2 = strval(data);
    mysql_fetch_field("accid",data);     owner = strval(data);
    mysql_fetch_field("km",data);        km = strval(data);
    mysql_fetch_field("schild",data);    format(schild,32,"%s",data);
    vid = CreateVehicleEx(modelid, x, y, z, angle, color1, color2, -1,owner,km,schild);
    mysql_fetch_field("tank",data);   
    Fahrzeuge[vid][0] = floatstr(data);
    mysql_fetch_field("health",data);
    Fahrzeuge[vid][1] = floatstr(data);
    mysql_fetch_field("id",data);

    Fahrzeuge[vid][5] = strval(data);
    i++;
  }
  new k = 0;
  for(new j = 0; k < i; j++)
  {
    if(floatround(Fahrzeuge[j][3]) == accid && floatround(Fahrzeuge[j][5]) != 0)
    {
      format(query,150,"UPDATE user_vehicles SET vid = %i,destroy = 0 WHERE id = %i AND accid=%i",j,floatround(Fahrzeuge[j][5]),accid);
      mysql_query(query);
      k++;
      Fahrzeuge[j][5] = 0;
    }
  }
  mysql_free_result();
  return 1;
}

public auto_pickup(playerid,pickupid)
{
  if(pickupid == gebverpick)
  {
    if(Fahrzeuge[GetPlayerVehicleID(playerid)][3] > 0 && playerdata[playerid][0] == Fahrzeuge[GetPlayerVehicleID(playerid)][3])
    {
      new output[250],string[100],price;
      if(Fahrzeuge[GetPlayerVehicleID(playerid)][4] < 25000) price = 7500;
      else if(Fahrzeuge[GetPlayerVehicleID(playerid)][4] < 50000) price = 5000;
      else if(Fahrzeuge[GetPlayerVehicleID(playerid)][4] < 75000) price = 4000;
      else if(Fahrzeuge[GetPlayerVehicleID(playerid)][4] < 100000) price = 2500;
      else if(Fahrzeuge[GetPlayerVehicleID(playerid)][4] < 125000) price = 1500;
      else price = 1500;
      strcat(output,"Autodaten:                                      \n");
      format(string,100,"    KM-Stand: %.0f\n",Fahrzeuge[GetPlayerVehicleID(playerid)][4]);
      strcat(output,string);
      format(string,100,"    Schaden: %.0f%\n",((((Fahrzeuge[GetPlayerVehicleID(playerid)][1] - 250) / 750) -1) *-100));
      strcat(output,string);
      format(string,100,"    Preis für das Auto: %i $\n",floatround(price - (1000-Fahrzeuge[GetPlayerVehicleID(playerid)][1])));
      strcat(output,string);
      ShowPlayerDialog(playerid, 85,DIALOG_STYLE_MSGBOX,"Autoverkauf",output,"Verkaufen","Doch nicht");
    }
    else GameTextForPlayer(playerid,"~r~Das Auto kann nicht verkauft werden!",3000,3);
    DestroyPickup(gebverpick);
    SetTimerEx("create_autopickupnew",10000,false,"iifffii",1274 , 14, 2126.56, -1138.36, 25.3, -1,gebverpick);
  }
  if(pickupid == mittverpick)
  {
    if(Fahrzeuge[GetPlayerVehicleID(playerid)][3] > 0 && playerdata[playerid][0] == Fahrzeuge[GetPlayerVehicleID(playerid)][3])
    {
      new output[250],string[100],price;
      if(Fahrzeuge[GetPlayerVehicleID(playerid)][4] < 25000) price = 13000;
      else if(Fahrzeuge[GetPlayerVehicleID(playerid)][4] < 50000) price = 10000;
      else if(Fahrzeuge[GetPlayerVehicleID(playerid)][4] < 75000) price = 7500;
      else price = 0;
      if(price > 0)
      {
        strcat(output,"Autodaten:                                      \n");
        format(string,100,"    KM-Stand: %.0f\n",Fahrzeuge[GetPlayerVehicleID(playerid)][4]);
        strcat(output,string);
        format(string,100,"    Schaden: %.0f%\n",((((Fahrzeuge[GetPlayerVehicleID(playerid)][1] - 250) / 750) -1) *-100));
        strcat(output,string);
        format(string,100,"    Preis für das Auto: %i $\n",floatround(price - (1000-Fahrzeuge[GetPlayerVehicleID(playerid)][1])));
        strcat(output,string);
        ShowPlayerDialog(playerid, 86,DIALOG_STYLE_MSGBOX,"Autoverkauf",output,"Verkaufen","Doch nicht");
      }
      else
      {
        ShowPlayerDialog(playerid, 84,DIALOG_STYLE_MSGBOX,"Autoverkauf","Der Händler möchte dein Auto nicht kaufen. \n Versuche es beim Gebrauchtwagenhändler.","Doch nicht","");
      }
    }
    else GameTextForPlayer(playerid,"~r~Das Auto kann nicht verkauft werden!",3000,3);
    DestroyPickup(mittverpick);
    SetTimerEx("create_autopickupnew",10000,false,"iifffii",1274 , 14,-1986.12, 303.16, 35.5, -1,mittverpick);
  }
  if(pickupid == bootsverpick)
  {
    if(Fahrzeuge[GetPlayerVehicleID(playerid)][3] > 0 && playerdata[playerid][0] == Fahrzeuge[GetPlayerVehicleID(playerid)][3])
    {
      new output[250],string[100],price;
      new mid = GetVehicleModel(GetPlayerVehicleID(playerid));
      if(mid == 493 || mid == 595 || mid == 484 || mid == 452 || mid == 460)
        price = 100000;
      else if(mid == 473 || mid == 539)
        price = 10000;
      else
        price = 0;
      if(price > 0)
      {
        strcat(output,"Bootdaten:                                      \n");
        format(string,100,"    KM-Stand: %.0f\n",Fahrzeuge[GetPlayerVehicleID(playerid)][4]);
        strcat(output,string);
        format(string,100,"    Schaden: %.0f%\n",((((Fahrzeuge[GetPlayerVehicleID(playerid)][1] - 250) / 750) -1) *-100));
        strcat(output,string);
        format(string,100,"    Preis für das Boot: %i $\n",floatround(price - (1000-Fahrzeuge[GetPlayerVehicleID(playerid)][1])));
        strcat(output,string);
        ShowPlayerDialog(playerid, 87,DIALOG_STYLE_MSGBOX,"Bootverkauf",output,"Verkaufen","Doch nicht");
      }
      else
      {
        ShowPlayerDialog(playerid, 84,DIALOG_STYLE_MSGBOX,"Bootverkauf","Kein Boot.","Doch nicht","");
      }
    }
    else GameTextForPlayer(playerid,"~r~Das Fahrzeug kann nicht verkauft werden!",3000,3);
    DestroyPickup(bootsverpick);
    SetTimerEx("create_autopickupnew",10000,false,"iifffii",1274 , 2374.39, 525.25, 1, 13.5, -1,bootsverpick);
  }
  if(pickupid == airverpick)
  {
    if(Fahrzeuge[GetPlayerVehicleID(playerid)][3] > 0 && playerdata[playerid][0] == Fahrzeuge[GetPlayerVehicleID(playerid)][3])
    {
      new output[250],string[100],price,mid;
      mid = GetVehicleModel(GetPlayerVehicleID(playerid));
      if(mid == 512 || mid == 593 || mid == 519 || mid == 513 || mid == 487)
        price = 100000;
      else
        price = 0;
      if(price > 0)
      {
        strcat(output,"Flugzeugdaten:                                      \n");
        format(string,100,"    KM-Stand: %.0f\n",Fahrzeuge[GetPlayerVehicleID(playerid)][4]);
        strcat(output,string);
        format(string,100,"    Schaden: %.0f%\n",((((Fahrzeuge[GetPlayerVehicleID(playerid)][1] - 250) / 750) -1) *-100));
        strcat(output,string);
        format(string,100,"    Preis für das Flugzeug: %i $\n",floatround(price - (1000-Fahrzeuge[GetPlayerVehicleID(playerid)][1])));
        strcat(output,string);
        ShowPlayerDialog(playerid, 88,DIALOG_STYLE_MSGBOX,"Flugzeugverkauf",output,"Verkaufen","Doch nicht");
      }
      else
      {
        ShowPlayerDialog(playerid, 84,DIALOG_STYLE_MSGBOX,"Flugzeugverkauf","Kein Flugzeug","Doch nicht","");
      }
    }
    else GameTextForPlayer(playerid,"~r~Das Fahrzeug kann nicht verkauft werden!",3000,3);
    DestroyPickup(airverpick);
    SetTimerEx("create_autopickupnew",10000,false,"iifffii",1274 , 14,1935.92, -2637.98, 13.5, -1,airverpick);
  }
  if(pickupid == autoversls || pickupid == autoverslv || pickupid == autoverssf)
  {
    SetPlayerInterior(playerid, 3);
    SetPlayerPos(playerid,384.81,173.81,1008.30);
    if(pickupid == autoversls)autoverplayerin[playerid] = 1;
    else if(pickupid == autoverssf){ autoverplayerin[playerid] = 2;}
    else autoverplayerin[playerid] = 3;
	SetPlayerVirtualWorld(playerid,autoverplayerin[playerid]);
  }
  if(pickupid == versexit)
  {
    SetPlayerInterior(playerid, 0);
    if(autoverplayerin[playerid] == 1) SetPlayerPos(playerid,1105.88, -1796.28, 16.39);
    else if(autoverplayerin[playerid] == 2) SetPlayerPos(playerid,-2669.32, -9.94, 6.13);
    else SetPlayerPos(playerid,1842.17, 2162.11, 10.82);
    autoverplayerin[playerid] = 0;
	SetPlayerVirtualWorld(playerid,0);
  }
  if(pickupid == autovers)
  {
    ShowPlayerDialog(playerid, 80, DIALOG_STYLE_LIST, "Autoversicherung", "Autoversicherung beantragen\nVersicherung in Anspruch nehmen\nVersicherung kündigen", "Weiter", "Abbrechen");
    SetPlayerPos(playerid,357.10, 208.34, 1008.38);
  }
  if(pickupid == autozulpick)
  {
	new query[150],id = 84,data[150],string[150],output[250];
	format(query,150,"SELECT modelid,buyat FROM user_vehicles WHERE destroy = 0 AND accid = %i ORDER BY id",playerdata[playerid][0]);
    mysql_query(query);
    mysql_store_result();
    while(mysql_fetch_row(data))
    {
      mysql_fetch_field("modelid",data);
      format(string,150,"%s gekauft am: ",Fahrzeugname[strval(data)-400]);
      strcat(output,string);
      mysql_fetch_field("buyat",data);
      format(string,150,"%s \n",data);
      strcat(output,string);
	  id = 90;
    }
    if(strlen(output) < 3) output = "Sie haben kein Fahrzeug zum ändern des Kennzeichens";
    ShowPlayerDialog(playerid, id, DIALOG_STYLE_LIST, "Kennzeichen verändern von", output, "Ändern", "Abbrechen");
    mysql_free_result();
	SetPlayerPos(playerid,376.36, 187.95, 1014.18);
  }
}

public create_autopickupnew(model, type, Float:X, Float:Y, Float:Z, Virtualworld, &pickupid)
{
  pickupid = CreatePickup(model, type, X, Y, Z, Virtualworld);
}