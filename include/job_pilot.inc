forward pilot();
forward pilotstart(playerid);
forward pilotdia(playerid);
forward tankpilot(playerid,count,vid);
forward erlaubnislandbahn(bahn);
forward erlaubnislandebahnabwarten(playerid,bahn,kind);
forward abbruch_pilot(playerid);
forward pilot_response(playerid, dialogid, response, listitem, inputtext[]);
forward pilot_pickups(playerid,pickupid);
forward ptanken(vid);

new pilotpickstart,pilots[MAX_PLAYERS],pilotmission[MAX_PLAYERS], pilottimer[MAX_PLAYERS];
new sfpassid1,sfpassid2,sffrachtid1,sftankid1,sftankid2,sftankid3,sffrachtid2,sffrachtheli1,sffrachtheli2;
new ftrans[2][2];

public pilot()
{
  sfpassid1 = CreateVehicleEx(577, -1336.45,  -222.44,  14, 135, 53, 1, 1800); //SF Passagier 1
  sfpassid2 = CreateVehicleEx(577, -1256.75,  -367.83,  14, 90, 53, 1, 1800);  //SF Passagier 2
  SetVehicleParamsEx(sfpassid1,0,0, 0, 1, 0, 0, 0);
  SetVehicleParamsEx(sfpassid2,0,0, 0, 1, 0, 0, 0);
  sffrachtid1 = CreateVehicleEx(592, -1313.10,  24.68,  15, 135, 53, 1, 1800);  //SF Frachter 1
  SetVehicleParamsEx(sffrachtid1,0,0, 0, 1, 0, 0, 0);
  sffrachtid2 = CreateVehicleEx(592, -1271.70,  -14.25,  15, 135, 53, 1, 1800);  //SF Frachter 2
  SetVehicleParamsEx(sffrachtid2,0,0, 0, 1, 0, 0, 0);
  sftankid1 = CreateVehicleEx(583, -1126.59,  -176.72,  13.68, 135, 53, 1, 1800);  //SF Tankfahrzeuge
  CreateVehicleEx(611, -1123.82,  -173.59,  13.68, 135, 53, 1, 1800);
  sftankid2 = CreateVehicleEx(583, -1123.87,  -179.74,  14.14, 135, 53, 1, 1800);
  CreateVehicleEx(611, -1121.12,  -177.50,  14.14, 135, 53, 1, 1800);
  sftankid3 = CreateVehicleEx(583, -1121.19,  -182.84,  14.14, 135, 53, 1, 1800);

  CreateVehicleEx(611, -1118.27,  -180.02,  14.14, 135, 53, 1, 1800);
  SetVehicleParamsEx(sftankid1,0,0, 0, 1, 0, 0, 0);
  SetVehicleParamsEx(sftankid2,0,0, 0, 1, 0, 0, 0);
  SetVehicleParamsEx(sftankid3,0,0, 0, 1, 0, 0, 0);
  sffrachtheli1 = CreateVehicleEx(417, -1184.80, 25.76, 14.14, 47, 53, 1, 1800); //  Frachtheli 1
  sffrachtheli2 = CreateVehicleEx(417, -1224.13, -11.19, 14.14, 47, 53, 1, 1800); //  Frachtheil 2
  SetVehicleParamsEx(sffrachtheli1,0,0, 0, 1, 0, 0, 0);
  SetVehicleParamsEx(sffrachtheli2,0,0, 0, 1, 0, 0, 0);
  
  CreateDynamicObject(11472, -1280,  -371,  12, 0,0,90); //Einstieghilfe 2
  CreateDynamicObject(11472, -1350,  -240,  12, 0,0,135); //Einstieghilfe 1
  
  CreateDynamicObject(2611, -1327.89,  -396.5,  14.5, 0,0,0);
  CreateDynamicObject(2765, -1329,  -396,  14, 0,0,0);
  CreateDynamicObject(2611, -1507.55,  -217.26,  14.8, 0,0,0);
  
  CreateDynamicObject(1297, -1328.85,  -396.3,  14.5, 0,0,0);
  pilotpickstart = CreatePickup(1239, 1, -1328.01,  -397.49,  14.14, 0);
  
  CreateDynamicMapIcon(-1328.01,  -397.49,  14.14, 51, -1,-1, -1, -1, 500);
}

public pilotdia(playerid)
{
  if(pilots[playerid] < 1)
    ShowPlayerDialog(playerid, 11,DIALOG_STYLE_LIST, "Pilotenaufträge", "Passagierflug nach Los Santos\nPassagierflug nach Las Venturas\nHelicopter-Frachtflug 1\nHelicopter-Frachtflug 2\nFrachtflug 1\nFrachtflug 2", "Bestätigen", "Abbrechen");
  else
    SendClientMessage(playerid,COLOR_RED,"Sie haben bereits einen Auftrag!");
}

public pilotstart(playerid)
{
  new Float:passflug[2][50][3] =
  {
    {
      {-1121.18,  -182.83,  13.73},//0
      {-1259.93,  -380.97,  13.68},//1
      {-1121.18,  -182.83,  13.73},//2
      {-1274.08,  -375.75,  14.14},//3
      {-1211.76,  -397.29,  14.06},//4
      {-1186.96,  -286.84,  14.06},//5
      {-1352.52,  -66.49,  14.07},//6
      {-1594.41,  -212.05,  14.06},//7 Starterlaubnis
      {-1681.95,  -192.29,  14.06},//8
      {-997.23,  494.91,  39.16},//9
      {-508.44,  1354.22,  172.00},//10
      {-209.83,  2080.87,  236.61},//11
      {-244.16,  2799.00,  238.83},//12
      {580.43,  2720.51,  205.13},//13
      {1342.90,  2661.39,  127.31},//14 Landeerlaubis
      {1483.60,  1280.34,  10.73},//15
      {1376.11,  1339.63,  10.74},//16
      {1513.92,  1477.91,  10.78},//17
      {1562.34,  1415.22,  10.76},//18
      {1531.70,  1290.76,  10.73},//19 Starterlaubnis
      {1477.32,  1239.90,  10.74},//20
      {1475.72,  1883.81,  60.15},//21
      {1599.69,  2476.44,  118.13},//22
      {2056.54,  1507.04,  193.01},//23
      {2725.62,  640.16,  270.42},//24
      {3020.35,  -475.17,  210.25},//25
      {3282.86,  -2193.30,  180.40},//26
      {2456.07,  -2435.62,  92.85},//27 Landeerlaubis
      {1516.13,  -2494.51,  13.47},//28
      {1640.75,  -2596.69,  13.51},//29
      {1978.04,  -2591.81,  13.50},//30
      {2072.26,  -2496.56,  13.46},//31
      {1900.65,  -2389.08,  13.45},//32
      {1959.04,  -2339.41,  13.46},//33
      {1957.70,  -2445.05,  13.45},//34 Starterlaubnis
      {1941.98,  -2495.73,  13.45},//35
      {1415.75,  -2496.19,  59.74},//36
      {887.30,  -2254.04,  90.37},//37
      {857.69,  -1380.97,  154.75},//38
      {852.45,  -768.51,  177.57},//39
      {1014.93,  -0.89,  192.82},//40
      {729.50,  375.73,  165.24},//41
      {-390.01,  505.41,  101.36},//42 Landeerlaubis
      {-1612.81,  -120.19,  14.08},//43
      {-1599.26,  -214.60,  14.08},//44
      {-1362.17,  -59.78,  14.06},//45
      {-1186.06,  -271.77,  14.07},//46
      {-1259.14,  -365.29,  14.06},//47
      {-1211.76,  -397.29,  14.06},//48
      {-1320.01,  -390.49,  14.14} //49 Ende
    },
    {
      {-1121.18,  -182.83,  13.73}, // 0
      {-1326.73, -231.86, 14.14}, // 1
      {-1121.18,  -182.83,  13.73}, // 2
      {-1341.90, -238.97, 14.14}, // 3
      {-1237.34, -173.71, 14.06}, // 5
      {-1585.04, -202.71, 14.06}, // 6 starterlaubnis
      {-1681.95,  -192.29,  14.06}, // 7
      {-1077.26, 423.34, 53.62}, // 8 Freigabe SF
      {-322.84, 105.14, 190.38}, //9
      {17.78, -936.88, 264.81}, //10
      {63.63, -2161.51, 242.04}, //11
      {873.62, -2589.59, 150.60},//12 Landeerlaubnis LS
      {2064.37, -2591.85, 13.49}, // 13 Freigabe
      {1900.92, -2392.45, 13.45}, //14
      {1958.85, -2442.74, 13.46}, // 15 Starterlaubnis LS
      {1934.89, -2490.88, 13.45}, //16 
      {1342.56, -2491.25, 68.25}, //17 Freigabe LS
      {901.34, -1892.17, 148.82}, //18 
      {1055.75, -1076.58, 220.17}, // 19
      {1599.39, -424.41, 216.97}, //20
      {1674.35, 454.60, 89.37}, //21 Landerlaubnis LV
      {1477.33, 1661.86, 10.76}, // 22 Freigabe
      {1388.05, 1608.08, 10.75}, //23 
      {1561.07, 1412.74, 10.76}, // 24 
      {1535.38, 1269.87, 10.72}, //25 Startfreigabe LV
      {1471.88, 2085.16, 117.88}, //26 freigabe LV
      {1353.92, 2645.22, 150.02}, //27
      {662.80, 2878.64, 187.65}, //28
      {-530.10, 2299.36, 244.68}, //29
      {-777.77, 1218.57, 178.24}, //30
      {-849.37, 912.91, 146.12}, //31 Landeerlaubnis SF
      {-1602.10, -110.30, 14.08},//32 Freigabe SF
      {-1492.01, -110.96, 14.13}, //33
      {-1337.87, -223.49, 14.06}, //34 Rest auffüllen!!!
      {0.0, 0.0, 0.0},{0.0, 0.0, 0.0},{0.0, 0.0, 0.0},{0.0, 0.0, 0.0},{0.0, 0.0, 0.0},{0.0, 0.0, 0.0},
      {0.0, 0.0, 0.0},{0.0, 0.0, 0.0},{0.0, 0.0, 0.0},{0.0, 0.0, 0.0},{0.0, 0.0, 0.0},
      {0.0, 0.0, 0.0},{0.0, 0.0, 0.0},{0.0, 0.0, 0.0},{0.0, 0.0, 0.0},{0.0, 0.0, 0.0} 
    }
  };
  
  new Float:frachtsflug[9][3] =
  {
    {-1636.87, 1419.87, 7.26},
    {-2314.16, 1543.87, 18.86},
    {-2226.65, 2326.96, 7.59},
    {-2090.25, 2312.01, 25.99},
    {-295.79, 1324.53, 55.41},
    {2618.51, 2720.54, 36.59},
    {1087.15, 1070.32, 10.90},
    {970.27, 1732.88, 8.68},
    {365.54, 2536.17, 16.74}
  };
  
  if(pilots[playerid] == 1) //PILOTPASSAGIERMISSION 1
  {
    new pid = pilots[playerid];
    pid--;
    new con = 1;
    new cid = pilotmission[playerid];
    switch(cid)
    {
      case 0:
        GameTextForPlayer(playerid,"~w~Betanken Sie ihr ~n~~g~Flugzeug",3000,3);
      case 1:
      {
        SetVehicleParamsForPlayer(sftankid1,playerid,0,0);
        SetVehicleParamsForPlayer(sftankid2,playerid,0,0);
        SetVehicleParamsForPlayer(sftankid3,playerid,0,0);
        GameTextForPlayer(playerid,"~w~Steigen Sie in ein~n~~g~Fahrzeug",3000,3);
      }
      case 2:
      {
        if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 583)
        {
          GameTextForPlayer(playerid,"~w~Betankung. Bitte warten....",5000,3);
          TogglePlayerControllable(playerid,0);
          SetTimerEx("tankpilot",10000,false,"iii",playerid,0,sfpassid1);
        }
        else
        {
          GameTextForPlayer(playerid,"~w~Sie sollten mit dem Tankfahrzeug betanken",3000,3);
          pilotmission[playerid]--;
          cid--;
        }
      }
      case 3:
      {
        if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 583)
        {
          GameTextForPlayer(playerid,"~w~Steigen Sie in ihr~n~~g~Flugzeug",3000,3);
          ptanken(GetPlayerVehicleID(playerid));
          if(sftankid1 == GetPlayerVehicleID(playerid)){ SetVehicleToRespawn(GetPlayerVehicleID(playerid));SetVehicleToRespawn(GetPlayerVehicleID(playerid)+1);}
          if(sftankid2 == GetPlayerVehicleID(playerid)){ SetVehicleToRespawn(GetPlayerVehicleID(playerid));SetVehicleToRespawn(GetPlayerVehicleID(playerid)+1);}
          if(sftankid3 == GetPlayerVehicleID(playerid)){ SetVehicleToRespawn(GetPlayerVehicleID(playerid));SetVehicleToRespawn(GetPlayerVehicleID(playerid)+1);}
          RemovePlayerFromVehicle(playerid);
          SetVehicleParamsForPlayer(sfpassid2,playerid,0,0);
          SetVehicleParamsForPlayer(sftankid1,playerid,0,1);
          SetVehicleParamsForPlayer(sftankid2,playerid,0,1);
          SetVehicleParamsForPlayer(sftankid3,playerid,0,1);
        }
        else
        {
          GameTextForPlayer(playerid,"~w~Bringen Sie das Tankfahrzeug ~n~zum Ausgangspunkt",3000,3);
          pilotmission[playerid]--;
          cid--;
        }
      }
      case 4:
        GameTextForPlayer(playerid,"~w~Steigen Sie ein~n~~w~Starten Sie den Motor",3000,3);
      case 5:
        GameTextForPlayer(playerid,"~w~Fahren Sie zur Startbahn",3000,3);
      case 8:
      {
        if(erlaubnislandbahn(1))
        {
          GameTextForPlayer(playerid,"~w~Sie haben Starterlaubnis bekommen",3000,3);
          landebahnsf = 1;
        }
        else
        {
          con = 0;
          GameTextForPlayer(playerid,"~r~keine~w~Starterlaubnis~n~warten Sie!",5000,3);
          SetTimerEx("erlaubnislandebahnabwarten",5000,false,"iii",playerid,1,0);
        }
      }
      case 10:
        landebahnsf = 0;
      case 15:
      {
        if(erlaubnislandbahn(2))
        {
          GameTextForPlayer(playerid,"~w~Sie haben Landeerlaubnis bekommen",3000,3);
          landebahnlv = 1;
        }
        else
        {
          con = 0;
          GameTextForPlayer(playerid,"~r~keine~w~Landeerlaubnis~n~fliegen Sie eine Schleife!",5000,3);
          SetTimerEx("erlaubnislandebahnabwarten",5000,false,"iii",playerid,2,1);
        }
      }
      case 16:
        landebahnlv = 0;
      case 18:
        GameTextForPlayer(playerid,"~w~Willkommen in Las Venturas~n~Fahren Sie an das Gate!",3000,3);
      case 19:
      {
        GameTextForPlayer(playerid,"~w~Bording gestartet! Warten Sie",3000,3);
        SetTimerEx("tankpilot",25000,false,"ii",playerid,1);
        TogglePlayerControllable(playerid,0);
      }
      case 20:
      {
        if(erlaubnislandbahn(2))
        {
          GameTextForPlayer(playerid,"~w~Sie haben Starterlaubnis bekommen",3000,3);
          landebahnlv = 1;
        }
        else
        {
          con = 0;
          GameTextForPlayer(playerid,"~r~keine~w~Starterlaubnis~n~warten Sie",5000,3);
          SetTimerEx("erlaubnislandebahnabwarten",5000,false,"iii",playerid,2,0);
        }
      }
      case 21:
        landebahnlv = 0;
      case 28:
      {
        if(erlaubnislandbahn(0))
        {
          GameTextForPlayer(playerid,"~w~Sie haben Landeerlaubnis bekommen",3000,3);
          landebahnls = 1;
        }
        else
        {
          con = 0;
          GameTextForPlayer(playerid,"~r~keine~w~Landeerlaubnis~n~fliegen Sie eine Schleife!",5000,3);
          SetTimerEx("erlaubnislandebahnabwarten",5000,false,"iii",playerid,0,1);
        }
      }
      case 29:
        landebahnls = 0;
      case 32:
        GameTextForPlayer(playerid,"~w~Willkommen in Los Santos~n~Fahren Sie an die Treppe",3000,3);
      case 33:
      {
        GameTextForPlayer(playerid,"~w~Bording gestartet! Warten Sie",3000,3);
        SetTimerEx("tankpilot",25000,false,"ii",playerid,1);
        TogglePlayerControllable(playerid,0);
      }
      case 35:
      {
        if(erlaubnislandbahn(0))
        {
          GameTextForPlayer(playerid,"~w~Sie haben Starterlaubnis bekommen",3000,3);
          landebahnls = 1;
        }
        else
        {
          con = 0;
          GameTextForPlayer(playerid,"~r~keine~w~Starterlaubnis~n~warten Sie",5000,3);
          SetTimerEx("erlaubnislandebahnabwarten",5000,false,"iii",playerid,0,0);
        }
      }
      case 36:
        landebahnls = 0;
      case 43:
      {
        if(erlaubnislandbahn(1))
        {
          GameTextForPlayer(playerid,"~w~Sie haben Landeerlaubnis bekommen",3000,3);
          landebahnsf = 1;
        }
        else
        {
          con = 0;
          GameTextForPlayer(playerid,"~r~keine~w~Landeerlaubnis~n~fliegen Sie eine Schleife!",5000,3);
          SetTimerEx("erlaubnislandebahnabwarten",5000,false,"iii",playerid,1,1);
        }
      }
      case 44:
        landebahnsf = 0;
      case 47:
        GameTextForPlayer(playerid,"~w~Willkommen in San Fierro~n~Fahren Sie bis zur Rampe",3000,1);
      case 49:
      {
        con = 0;
        new Float:h,output[150];
        GetVehicleHealth(sfpassid2,h);
        GameTextForPlayer(playerid,"~w~Auftrag abgeschlossen",3000,3);
        giveusermoney(playerid,1000-(1000-floatround(h))+(200*playerdata[playerid][3]));
        format(output,150,"Auftrag abgeschlossen! 1000$, - %i$ wegen dem Schaden des Fahrzeuges und durch Skill + %i$",1000-floatround(h),(200*playerdata[playerid][3]));
        SendClientMessage(playerid, COLOR_PBOTE, output);
        Fahrzeuge[sfpassid2][1] = 1000.0;
        pilots[playerid] = 0;
        pilotmission[playerid] = 0;
        playerdata[playerid][9]++;
        playerdata[playerid][8]++;
        navivar[playerid] = 0;
        SetTimerEx("SetVehicleToRespawn",5000,false,"i",sfpassid2);
        SetVehicleParamsForPlayer(sfpassid2,playerid,0,1);
        SetVehicleParamsEx(sfpassid2,0,0, 0, 1, 0, 0, 0);
        RemovePlayerFromVehicle(playerid);
      }
    }
    
    if(con)
    {
      if(GetPlayerVehicleID(playerid) == sfpassid2 || cid < 5)
      {
        //Punkte setzen zum Betanken und einsteigen
        if(cid >= 0 && cid < 4 && cid != 2 || cid == 48 || cid == 32 || cid == 18)
          SetPlayerCheckpoint(playerid, passflug[pid][cid][0], passflug[pid][cid][1], passflug[pid][cid][2], 5);
        //Tankfahrzeug zurückbringen
        else if(cid == 2)
        {
          if(GetPlayerVehicleID(playerid) == sftankid1) SetPlayerCheckpoint(playerid, -1126.59,  -176.72,  13.68, 5);
          if(GetPlayerVehicleID(playerid) == sftankid2) SetPlayerCheckpoint(playerid, -1123.87,  -179.74,  14.14, 5);
          if(GetPlayerVehicleID(playerid) == sftankid3) SetPlayerCheckpoint(playerid, -1121.19,  -182.84,  14.14, 5);
        }
        //Bodenpunkte
        else if((cid > 3 && cid < 9) || (cid > 14 && cid < 21) || (cid > 27 && cid < 36) || (cid > 42 && cid < 48))
          SetPlayerRaceCheckpoint(playerid, 0, passflug[pid][cid][0], passflug[pid][cid][1], passflug[pid][cid][2], passflug[pid][(cid+1)][0], passflug[pid][(cid+1)][1], passflug[pid][(cid+1)][2], 30);
        //Luftpunkte
        else if((cid > 8 && cid < 15) || (cid > 20 && cid < 28) || (cid > 35 && cid < 43))
          SetPlayerRaceCheckpoint(playerid, 3, passflug[pid][cid][0], passflug[pid][cid][1], passflug[pid][cid][2], passflug[pid][(cid+1)][0], passflug[pid][(cid+1)][1], passflug[pid][(cid+1)][2], 30);
        pilotmission[playerid]++;
      }
    }
  }
  if(pilots[playerid] == 2) //PILOTPASSAGIERMISSION 2
  {
    new pid = pilots[playerid];
    pid--;
    new con = 1;
    new cid = pilotmission[playerid];
    switch(cid)
    {
      case 0:
      {
        SetVehicleParamsForPlayer(sftankid1,playerid,0,0);
        SetVehicleParamsForPlayer(sftankid2,playerid,0,0);
        SetVehicleParamsForPlayer(sftankid3,playerid,0,0);
        GameTextForPlayer(playerid,"~w~Betanken Sie ihr ~n~~g~Flugzeug",3000,3);
      }
      case 1:
        GameTextForPlayer(playerid,"~w~Steigen Sie in ein~n~~g~Fahrzeug",3000,3);
      case 2:
      {
        if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 583)
        {
          GameTextForPlayer(playerid,"~w~Betankung. Bitte warten....",5000,3);
          TogglePlayerControllable(playerid,0);
          SetTimerEx("tankpilot",10000,false,"iii",playerid,0,sfpassid1);
        }
        else
        {
          GameTextForPlayer(playerid,"~w~Sie sollten mit dem Tankfahrzeug betanken",3000,3);
          pilotmission[playerid]--;
          cid--;
        }
      }
      case 3:
      {
        if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 583)
        {
          GameTextForPlayer(playerid,"~w~Steigen Sie in ihr~n~~g~Flugzeug",3000,3);
          if(sftankid1 == GetPlayerVehicleID(playerid)){ SetVehicleToRespawn(GetPlayerVehicleID(playerid));SetVehicleToRespawn(GetPlayerVehicleID(playerid)+1);}
          if(sftankid2 == GetPlayerVehicleID(playerid)){ SetVehicleToRespawn(GetPlayerVehicleID(playerid));SetVehicleToRespawn(GetPlayerVehicleID(playerid)+1);}
          if(sftankid3 == GetPlayerVehicleID(playerid)){ SetVehicleToRespawn(GetPlayerVehicleID(playerid));SetVehicleToRespawn(GetPlayerVehicleID(playerid)+1);}
          RemovePlayerFromVehicle(playerid);
          SetVehicleParamsForPlayer(sftankid1,playerid,0,1);
          SetVehicleParamsForPlayer(sftankid2,playerid,0,1);
          SetVehicleParamsForPlayer(sftankid3,playerid,0,1);
          SetVehicleParamsForPlayer(sfpassid1,playerid,0,0);
        }
        else
        {
          GameTextForPlayer(playerid,"~w~Bringen Sie das Tankfahrzeug ~n~zum Ausgangspunkt",3000,3);
          pilotmission[playerid]--;
          cid--;
        }
      }
      case 4:
        GameTextForPlayer(playerid,"~w~Steigen Sie ein~n~~w~Starten Sie den Motor",3000,3);
      case 5:
        GameTextForPlayer(playerid,"~w~Fahren Sie zur Startbahn",3000,3);
      case 6:
      {
        if(erlaubnislandbahn(1))
        {
          GameTextForPlayer(playerid,"~w~Sie haben Starterlaubnis bekommen",3000,3);
          landebahnsf = 1;
        }
        else
        {
          con = 0;
          GameTextForPlayer(playerid,"~r~keine~w~Starterlaubnis~n~warten Sie!",5000,3);
          SetTimerEx("erlaubnislandebahnabwarten",5000,false,"iii",playerid,1,0);
        }
      }
      case 8:
        landebahnsf = 0;
      case 12:
      {
        if(erlaubnislandbahn(0))
        {
          GameTextForPlayer(playerid,"~w~Sie haben Landeerlaubnis bekommen",3000,3);
          landebahnls = 1;
        }
        else
        {
          con = 0;
          GameTextForPlayer(playerid,"~r~keine~w~Landeerlaubnis~n~fliegen Sie eine Schleife!",5000,3);
          SetTimerEx("erlaubnislandebahnabwarten",5000,false,"iii",playerid,0,1);
        }
      }
      case 13:
      {
        landebahnls = 0;
        GameTextForPlayer(playerid,"~w~Willkommen in Los Santos~n~Fahren Sie an das Gate!",3000,3);
      }
      case 14:
      {
        GameTextForPlayer(playerid,"~w~Bording gestartet! Warten Sie",3000,3);
        SetTimerEx("tankpilot",25000,false,"ii",playerid,1);
        TogglePlayerControllable(playerid,0);
      }
      case 15:
      {
        if(erlaubnislandbahn(0))
        {
          GameTextForPlayer(playerid,"~w~Sie haben Starterlaubnis bekommen",3000,3);
          landebahnls = 1;
        }
        else
        {
          con = 0;
          GameTextForPlayer(playerid,"~r~keine~w~Starterlaubnis~n~warten Sie",5000,3);
          SetTimerEx("erlaubnislandebahnabwarten",5000,false,"iii",playerid,0,0);
        }
      }
      case 17:
        landebahnls = 0;
      case 21:
      {
        if(erlaubnislandbahn(2))
        {
          GameTextForPlayer(playerid,"~w~Sie haben Landeerlaubnis bekommen",3000,3);
          landebahnlv = 1;
        }
        else
        {
          con = 0;
          GameTextForPlayer(playerid,"~r~keine~w~Landeerlaubnis~n~fliegen Sie eine Schleife!",5000,3);
          SetTimerEx("erlaubnislandebahnabwarten",5000,false,"iii",playerid,2,1);
        }
      }
      case 22:
        landebahnlv = 0;
      case 23:
        GameTextForPlayer(playerid,"~w~Willkommen in Las Venturas~n~Fahren Sie an das Gate!",3000,3);
      case 24:
      {
        GameTextForPlayer(playerid,"~w~Bording gestartet! Warten Sie",3000,3);
        SetTimerEx("tankpilot",25000,false,"ii",playerid,1);
        TogglePlayerControllable(playerid,0);
      }
      case 25:
      {
        if(erlaubnislandbahn(2))
        {
          GameTextForPlayer(playerid,"~w~Sie haben Starterlaubnis bekommen",3000,3);
          landebahnlv = 1;
        }
        else
        {
          con = 0;
          GameTextForPlayer(playerid,"~r~keine~w~Starterlaubnis~n~warten Sie",5000,3);
          SetTimerEx("erlaubnislandebahnabwarten",5000,false,"iii",playerid,2,0);
        }
      }
      case 26:
        landebahnlv = 0;
      case 31:
      {
        if(erlaubnislandbahn(1))
        {
          GameTextForPlayer(playerid,"~w~Sie haben Landeerlaubnis bekommen",3000,3);
          landebahnsf = 1;
        }
        else
        {
          con = 0;
          GameTextForPlayer(playerid,"~r~keine~w~Landeerlaubnis~n~fliegen Sie eine Schleife!",5000,3);
          SetTimerEx("erlaubnislandebahnabwarten",5000,false,"iii",playerid,1,1);
        }
      }
      case 32:
        landebahnsf = 0;
      case 33:
        GameTextForPlayer(playerid,"~w~Willkommen in San Fierro~n~Fahren Sie bis zur Rampe",3000,1);
      case 34:
      {
        con = 0;
        new Float:h,output[150];
        GetVehicleHealth(sfpassid1,h);
        GameTextForPlayer(playerid,"~w~Auftrag abgeschlossen",3000,3);
        giveusermoney(playerid,1000-(1000-floatround(h))+(200*playerdata[playerid][3]));
        format(output,150,"Auftrag abgeschlossen! 1000$, - %i$ wegen dem Schaden des Fahrzeuges und durch Skill + %i$",1000-floatround(h),(200*playerdata[playerid][3]));
        SendClientMessage(playerid, COLOR_PBOTE, output);
        Fahrzeuge[sfpassid1][1] = 1000.0;
        pilots[playerid] = 0;
        pilotmission[playerid] = 0;
        playerdata[playerid][9]++;
        playerdata[playerid][8]++;
        navivar[playerid] = 0;
        SetVehicleParamsForPlayer(sfpassid1,playerid,0,1);
        SetTimerEx("SetVehicleToRespawn",5000,false,"i",sfpassid1);
        RemovePlayerFromVehicle(playerid);
        SetVehicleParamsEx(sfpassid1,0,0, 0, 1, 0, 0, 0);
      }
    }
    if(con)
    {
      if(GetPlayerVehicleID(playerid) == sfpassid1 || cid < 5)
      {
        //Punkte setzen zum Betanken und einsteigen
        if((cid >= 0 && cid <= 3 && cid != 2) || cid == 34 || cid == 24 || cid == 14)
          SetPlayerCheckpoint(playerid, passflug[pid][cid][0], passflug[pid][cid][1], passflug[pid][cid][2], 5);
        //Tankfahrzeug zurückbringen
        else if(cid == 2)
        {
          if(GetPlayerVehicleID(playerid) == sftankid1) SetPlayerCheckpoint(playerid, -1126.59,  -176.72,  13.68, 5);
          if(GetPlayerVehicleID(playerid) == sftankid2) SetPlayerCheckpoint(playerid, -1123.87,  -179.74,  14.14, 5);
          if(GetPlayerVehicleID(playerid) == sftankid3) SetPlayerCheckpoint(playerid, -1121.19,  -182.84,  14.14, 5);
        }
        //Bodenpunkte
        else if((cid >= 4 && cid <= 7) || (cid >= 13 && cid <= 16) || (cid >= 22 && cid <= 25) || (cid >= 32 && cid <= 33))
          SetPlayerRaceCheckpoint(playerid, 0, passflug[pid][cid][0], passflug[pid][cid][1], passflug[pid][cid][2], passflug[pid][(cid+1)][0], passflug[pid][(cid+1)][1], passflug[pid][(cid+1)][2], 20);
        //Luftpunkte
        else if((cid >= 8 && cid <= 12) || (cid >= 17 && cid <= 21) || (cid >= 26 && cid <= 31))
          SetPlayerRaceCheckpoint(playerid, 3, passflug[pid][cid][0], passflug[pid][cid][1], passflug[pid][cid][2], passflug[pid][(cid+1)][0], passflug[pid][(cid+1)][1], passflug[pid][(cid+1)][2], 30);
        pilotmission[playerid]++;
      }
    }
  }
  if(pilots[playerid] == 3 || pilots[playerid] == 4) //PILOTFRACHTMISSIONEN zufälliger Endpunkt
  {
    new heli;
    if(pilots[playerid] == 4) heli = sffrachtheli2; else heli = sffrachtheli1;
    new con = 1;
    new cid = pilotmission[playerid];
    switch(cid)
    {
      case 0:
      {
        SetVehicleParamsForPlayer(sftankid1,playerid,0,0);
        SetVehicleParamsForPlayer(sftankid2,playerid,0,0);
        SetVehicleParamsForPlayer(sftankid3,playerid,0,0);
        GameTextForPlayer(playerid,"~w~Betanken Sie ihren ~n~~g~Helicopter",3000,3);
      }
      case 1:
        GameTextForPlayer(playerid,"~w~Steigen Sie in ein~n~~g~Fahrzeug",3000,3);
      case 2:
      {
        if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 583)
        {
          GameTextForPlayer(playerid,"~w~Betankung. Bitte warten....",5000,3);
          TogglePlayerControllable(playerid,0);
          SetTimerEx("tankpilot",10000,false,"iii",playerid,0,heli);
        }
        else
        {
          GameTextForPlayer(playerid,"~w~Sie sollten mit dem Tankfahrzeug betanken",3000,3);
          pilotmission[playerid]--;
          cid--;
        }
      }
      case 3:
      {
        if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 583)
        {
          GameTextForPlayer(playerid,"~w~Steigen Sie in ihren~n~~g~Helicopter",3000,3);
          if(sftankid1 == GetPlayerVehicleID(playerid)){ SetVehicleToRespawn(GetPlayerVehicleID(playerid));SetVehicleToRespawn(GetPlayerVehicleID(playerid)+1);}
          if(sftankid2 == GetPlayerVehicleID(playerid)){ SetVehicleToRespawn(GetPlayerVehicleID(playerid));SetVehicleToRespawn(GetPlayerVehicleID(playerid)+1);}
          if(sftankid3 == GetPlayerVehicleID(playerid)){ SetVehicleToRespawn(GetPlayerVehicleID(playerid));SetVehicleToRespawn(GetPlayerVehicleID(playerid)+1);}
          RemovePlayerFromVehicle(playerid);
          SetVehicleParamsForPlayer(sftankid1,playerid,0,1);
          SetVehicleParamsForPlayer(sftankid2,playerid,0,1);
          SetVehicleParamsForPlayer(sftankid3,playerid,0,1);
          SetVehicleParamsForPlayer(heli,playerid,0,0);
        }
        else
        {
          GameTextForPlayer(playerid,"~w~Bringen Sie das Tankfahrzeug ~n~zum Ausgangspunkt",3000,3);
          pilotmission[playerid]--;
          cid--;
        }
      }
      case 4:
        GameTextForPlayer(playerid,"~w~Steigen Sie ein, starten Sie den Motor ~n~fliegen Sie zum Ziel",3000,3);
      case 5:
        GameTextForPlayer(playerid,"~w~Paket abgeliefert~n~~w~Fliegen Sie zum Flughafen",3000,3);
      case 6:
      {
        con = 0;
        new Float:h,output[150];
        GetVehicleHealth(heli,h);
        GameTextForPlayer(playerid,"~w~Auftrag abgeschlossen",3000,3);
        giveusermoney(playerid,800-(1000-floatround(h))+(200*playerdata[playerid][3]));
        format(output,150,"Auftrag abgeschlossen! 800$, - %i$ wegen dem Schaden des Fahrzeuges und durch Skill + %i$",1000-floatround(h),(200*playerdata[playerid][3]));
        SendClientMessage(playerid, COLOR_PBOTE, output);
        Fahrzeuge[heli][1] = 1000.0;
        pilots[playerid] = 0;
        pilotmission[playerid] = 0;
        playerdata[playerid][9]++;
        playerdata[playerid][8]++;
        SetVehicleParamsForPlayer(heli,playerid,0,1);
        SetTimerEx("SetVehicleToRespawn",5000,false,"i",heli);
        RemovePlayerFromVehicle(playerid);
        navivar[playerid] = 0;
        SetVehicleParamsEx(heli,0,0, 0, 1, 0, 0, 0);
      }
    }
    if(con)
    {
      if(GetPlayerVehicleID(playerid) == heli || cid < 5)
      {
        //Punkte setzen zum Betanken und einsteigen
        if(cid == 0)
          SetPlayerCheckpoint(playerid, -1121.18,  -182.83,  13.73, 5);
        else if(cid == 1 || cid == 3)
        {
          if(heli == sffrachtheli1)
            SetPlayerCheckpoint(playerid, -1182.80, 27.76, 14.14, 5);
          else
            SetPlayerCheckpoint(playerid, -1226.13, -13.19, 14.14, 5);
        }
        //Tankfahrzeug zurückbringen
        else if(cid == 2)
        {
          if(GetPlayerVehicleID(playerid) == sftankid1) SetPlayerCheckpoint(playerid, -1126.59,  -176.72,  13.68, 5);
          if(GetPlayerVehicleID(playerid) == sftankid2) SetPlayerCheckpoint(playerid, -1123.87,  -179.74,  14.14, 5);
          if(GetPlayerVehicleID(playerid) == sftankid3) SetPlayerCheckpoint(playerid, -1121.19,  -182.84,  14.14, 5);
        }
        //Zielpunkt
        else if(cid == 4)
        {
          new rand = random(9);
          SetPlayerCheckpoint(playerid, frachtsflug[rand][0], frachtsflug[rand][1], frachtsflug[rand][2], 5);
        }
        //Bodenpunkte
        else if(cid == 5)
        {
          if(heli == sffrachtheli1)
            SetPlayerCheckpoint(playerid, -1182.80, 27.76, 14.14, 5);
          else
            SetPlayerCheckpoint(playerid, -1226.13, -13.19, 14.14, 5);
        }
        pilotmission[playerid]++;
      }
    }
  }
  if(pilots[playerid] == 5 || pilots[playerid] == 6) //Frachtverteilung
  {
    //start und ziel 0 = LS Airp;1= SF Airp; 2= LV Airp
    new frachter,data[50],data2[50],start,ziel,query[125];
    new con = 1;
    new cid = pilotmission[playerid];
    if(pilots[playerid] == 5) frachter = sffrachtid2; else frachter = sffrachtid1;
    
    if(cid == 0)
    {
      mysql_query("SELECT * FROM `fprods` WHERE destination1 >= 1000 OR destination2 >= 1000 LIMIT 1");
      mysql_store_result();
      mysql_fetch_row(data); 
      mysql_fetch_field("name",data); // Startflughafen
      if(strcmp(data," ",true))
      {
        if(!strcmp(data,"LS Airport",true)) start = 0; else if(!strcmp(data,"SF Airport",true)) start = 1; else start = 2;
        mysql_fetch_field("destination1",data); // Zielflughafen
        mysql_fetch_field("destination2",data2); // Zielflughafen
        if(strval(data) > strval(data2) && start == 0) ziel = 1; else if(start == 0) ziel = 2;
        if(strval(data) > strval(data2) && start == 1) ziel = 0; else if(start == 1) ziel = 2;
        if(strval(data) > strval(data2) && start == 2) ziel = 0; else if(start == 2) ziel = 1;
        ftrans[(pilots[playerid]-5)][0] = start;
        ftrans[(pilots[playerid]-5)][1] = ziel;
        ;
        if(strval(data) > strval(data2) && start == 0)
          query = "UPDATE fprods SET destination1 = destination1 - 1000 WHERE pID=1";
        else if(start == 0)
          query = "UPDATE fprods SET destination2 = destination2 - 1000 WHERE pID=1";
        if(strval(data) > strval(data2) && start == 1)
          query = "UPDATE fprods SET destination1 = destination1 - 1000 WHERE pID=0";
        else if(start == 1)
          query = "UPDATE fprods SET destination2 = destination2 - 1000 WHERE pID=0";
        if(strval(data) > strval(data2) && start == 2)
          query = "UPDATE fprods SET destination1 = destination1 - 1000 WHERE pID=2";
        else if(start == 2)
          query = "UPDATE fprods SET destination2 = destination2 - 1000 WHERE pID=2";
        mysql_query(query);
      }
      else
      {
        con = 0;
        GameTextForPlayer(playerid,"~w~ Nicht genug Pakete zum liefern!",3000,3);
        pilots[playerid] = 0;
        ;
      }
    }
    
    switch(cid)
    {
      case 0:
      {
        if(con == 1)
        {
          SetVehicleParamsForPlayer(sftankid1,playerid,0,0);
          SetVehicleParamsForPlayer(sftankid2,playerid,0,0);
          SetVehicleParamsForPlayer(sftankid3,playerid,0,0);
          GameTextForPlayer(playerid,"~w~Betanken Sie ihr ~n~~g~Flugzeug",3000,3);
        }
        else
          GameTextForPlayer(playerid,"~r~Nicht genügend Gueter da",3000,3);
      }
      case 1:
        GameTextForPlayer(playerid,"~w~Steigen Sie in ein~n~~g~Fahrzeug",3000,3);
      case 2:
      {
        if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 583)
        {
          GameTextForPlayer(playerid,"~w~Betankung. Bitte warten....",5000,3);
          TogglePlayerControllable(playerid,0);
          Fahrzeuge[frachter][0] = 2000;
          SetTimerEx("tankpilot",10000,false,"iii",playerid,0,frachter);
        }
        else
        {
          GameTextForPlayer(playerid,"~w~Sie sollten mit dem Tankfahrzeug betanken",3000,3);
          pilotmission[playerid]--;
          cid--;
        }
      }
      case 3:
      {
        if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 583)
        {
          SetVehicleParamsForPlayer(sftankid1,playerid,0,1);
          SetVehicleParamsForPlayer(sftankid2,playerid,0,1);
          SetVehicleParamsForPlayer(sftankid3,playerid,0,1);
          if(sftankid1 == GetPlayerVehicleID(playerid)){ SetVehicleToRespawn(GetPlayerVehicleID(playerid));SetVehicleToRespawn(GetPlayerVehicleID(playerid)+1);}
          if(sftankid2 == GetPlayerVehicleID(playerid)){ SetVehicleToRespawn(GetPlayerVehicleID(playerid));SetVehicleToRespawn(GetPlayerVehicleID(playerid)+1);}
          if(sftankid3 == GetPlayerVehicleID(playerid)){ SetVehicleToRespawn(GetPlayerVehicleID(playerid));SetVehicleToRespawn(GetPlayerVehicleID(playerid)+1);}
          GameTextForPlayer(playerid,"~w~Steigen Sie in ihr~n~~g~Flugzeug",3000,3);
          RemovePlayerFromVehicle(playerid);
          SetVehicleParamsForPlayer(frachter,playerid,0,0);
        }
        else
        {
          GameTextForPlayer(playerid,"~w~Bringen Sie das Tankfahrzeug ~n~zum Ausgangspunkt",3000,3);
          pilotmission[playerid]--;
        }
      }
      case 4:
        GameTextForPlayer(playerid,"~w~Steigen Sie ein~n~~w~Starten Sie den Motor",3000,3);
      case 5:
      {
        if(erlaubnislandbahn(1))
        {
          GameTextForPlayer(playerid,"~w~Sie haben Starterlaubnis bekommen",3000,3);
          landebahnsf = 1;
        }
        else
        {
          con = 0;
          GameTextForPlayer(playerid,"~r~keine~w~Starterlaubnis~n~warten Sie!",5000,3);
          SetTimerEx("erlaubnislandebahnabwarten",5000,false,"iii",playerid,1,0);
        }
      }
      case 7:
      {
        landebahnsf = 0;
      }
      case 8: //Landen LV
      {
        if(erlaubnislandbahn(2))
        {
          GameTextForPlayer(playerid,"~w~Sie haben Landeerlaubnis bekommen",3000,3);
          landebahnlv = 1;
        }
        else
        {
          con = 0;
          GameTextForPlayer(playerid,"~r~keine~w~Landeerlaubnis~n~fliegen Sie eine Schleife!",5000,3);
          SetTimerEx("erlaubnislandebahnabwarten",5000,false,"iii",playerid,2,1);
        }
      }
      case 9:
        landebahnlv = 0;
      case 10:
        GameTextForPlayer(playerid,"~w~Willkommen in Las Venturas~n~Fahren Sie zur Beladerampe!",3000,3);
      case 11:
      {
        GameTextForPlayer(playerid,"~w~Be/Entladen gestartet! Warten Sie",3000,3);
        SetTimerEx("tankpilot",25000,false,"ii",playerid,2);
        TogglePlayerControllable(playerid,0);
      }
      case 13: // Starten LV
      {
        if(erlaubnislandbahn(2))
        {
          GameTextForPlayer(playerid,"~w~Sie haben Starterlaubnis bekommen",3000,3);
          landebahnlv = 1;
        }
        else
        {
          con = 0;
          GameTextForPlayer(playerid,"~r~keine~w~Starterlaubnis~n~warten Sie",5000,3);
          SetTimerEx("erlaubnislandebahnabwarten",5000,false,"iii",playerid,2,0);
        }
      }
      case 14:
        landebahnlv = 0;
      case 15: //Landen LS
      {
        if(erlaubnislandbahn(0))
        {
          GameTextForPlayer(playerid,"~w~Sie haben Landeerlaubnis bekommen",3000,3);
          landebahnls = 1;
        }
        else
        {
          con = 0;
          GameTextForPlayer(playerid,"~r~keine~w~Landeerlaubnis~n~fliegen Sie eine Schleife!",5000,3);
          SetTimerEx("erlaubnislandebahnabwarten",5000,false,"iii",playerid,0,1);
        }
      }
      case 16:
        landebahnls = 0;
      case 17:
        GameTextForPlayer(playerid,"~w~Willkommen in Los Santos~n~Fahren Sie zur Beladerampe",3000,3);
      case 18:
      {
        GameTextForPlayer(playerid,"~w~Be/Entladen gestartet! Warten Sie",3000,3);
        SetTimerEx("tankpilot",25000,false,"ii",playerid,2);
        TogglePlayerControllable(playerid,0);
      }
      case 19: //Starten LS
      {
        if(erlaubnislandbahn(0))
        {
          GameTextForPlayer(playerid,"~w~Sie haben Starterlaubnis bekommen",3000,3);
          landebahnls = 1;
        }
        else
        {
          con = 0;
          GameTextForPlayer(playerid,"~r~keine~w~Starterlaubnis~n~warten Sie",5000,3);
          SetTimerEx("erlaubnislandebahnabwarten",5000,false,"iii",playerid,0,0);
        }
      }
      case 20:
        landebahnls = 0;
      case 21: //Landen SF
      {
        if(erlaubnislandbahn(1))
        {
          GameTextForPlayer(playerid,"~w~Sie haben Landeerlaubnis bekommen",3000,3);
          landebahnsf = 1;
        }
        else
        {
          con = 0;
          GameTextForPlayer(playerid,"~r~keine~w~Landeerlaubnis~n~fliegen Sie eine Schleife!",5000,3);
          SetTimerEx("erlaubnislandebahnabwarten",5000,false,"iii",playerid,1,1);
        }
      }
      case 22:
        landebahnsf = 0;
      case 23:
        GameTextForPlayer(playerid,"~w~Stellen Sie das Flugzeug ab. Richtung SO",3000,3);
      case 24:
      {
        con = 0;
        new Float:h,output[150];
        GetVehicleHealth(frachter,h);
        GameTextForPlayer(playerid,"~w~Auftrag abgeschlossen",3000,3);
        giveusermoney(playerid,1200-(1000-floatround(h))+(200*playerdata[playerid][3]));
        format(output,150,"Auftrag abgeschlossen! 1200$, - %i$ wegen dem Schaden des Fahrzeuges und durch Skill + %i$",1000-floatround(h),(200*playerdata[playerid][3]));
        SendClientMessage(playerid, COLOR_PBOTE, output);
        Fahrzeuge[frachter][1] = 1000.0;
        pilots[playerid] = 0;
        pilotmission[playerid] = 0;
        playerdata[playerid][9]++;
        playerdata[playerid][8]++;
        navivar[playerid] = 0;
        SetVehicleParamsForPlayer(frachter,playerid,0,1);
        SetTimerEx("SetVehicleToRespawn",5000,false,"i",frachter);
        RemovePlayerFromVehicle(playerid);
        SetVehicleParamsEx(frachter,0,0, 0, 1, 0, 0, 0);
        if(ftrans[(pilots[playerid]-5)][1] == 0)
          query = "UPDATE `trucker_biz` SET cur_amount = cur_amount + 1000 WHERE biz_id=7";
        if(ftrans[(pilots[playerid]-5)][1] == 1)
          query = "UPDATE `trucker_biz` SET cur_amount = cur_amount + 1000 WHERE biz_id=9";
        if(ftrans[(pilots[playerid]-5)][1] == 2)
          query = "UPDATE `trucker_biz` SET cur_amount = cur_amount + 1000 WHERE biz_id=11";
        mysql_query(query);
      }
      case 25:
      {
        GameTextForPlayer(playerid,"~w~Be/Entladen gestartet! Warten Sie",3000,3);
        SetTimerEx("tankpilot",25000,false,"ii",playerid,2);
        TogglePlayerControllable(playerid,0);
      }
    }
    
    if(cid == 4)
    {
      if(ftrans[(pilots[playerid]-5)][0] == 1) pilotmission[playerid] = 24;
    }
    else if(cid == 7)
    {
      if(ftrans[(pilots[playerid]-5)][0] == 1)
      {
        if(ftrans[(pilots[playerid]-5)][1] == 0) pilotmission[playerid] = 14;
      }
      else if(ftrans[(pilots[playerid]-5)][0] == 0)
        pilotmission[playerid] = 14;
    }
    else if(cid == 14)
    {
      if(ftrans[(pilots[playerid]-5)][1] == 2) pilotmission[playerid] = 20;
    }
    else if(cid == 20)
    {
      if(ftrans[(pilots[playerid]-5)][1] == 2) pilotmission[playerid] = 7;
    }
    else if(cid == 22)
    {
      if(ftrans[(pilots[playerid]-5)][1] == 1) pilotmission[playerid] = 24;
    }
    else if(cid == 25)
    {
      if(ftrans[(pilots[playerid]-5)][0] == 1) pilotmission[playerid] = 4;
      if(ftrans[(pilots[playerid]-5)][1] == 1) pilotmission[playerid] = 22;
    }
    
    cid = pilotmission[playerid];
    
    if(con)
    {
      if(GetPlayerVehicleID(playerid) == frachter || cid < 5 || cid == 24)
      {
        //Punkte setzen zum Betanken und einsteigen
        if(cid == 0)
          SetPlayerCheckpoint(playerid, -1121.18,  -182.83,  13.73, 5);
        else if(cid == 1)
        {
          if(frachter == sffrachtid1) SetPlayerCheckpoint(playerid, -1305.54, 17.26, 14.14, 5);
          else SetPlayerCheckpoint(playerid, -1264.58, -22.31, 14.14, 5);
        }
        //Tankfahrzeug zurückbringen
        else if(cid == 2)
        {
          if(GetPlayerVehicleID(playerid) == sftankid1) SetPlayerCheckpoint(playerid, -1126.59,  -176.72,  13.68, 5);
          if(GetPlayerVehicleID(playerid) == sftankid2) SetPlayerCheckpoint(playerid, -1123.87,  -179.74,  14.14, 5);
          if(GetPlayerVehicleID(playerid) == sftankid3) SetPlayerCheckpoint(playerid, -1121.19,  -182.84,  14.14, 5);
        }
        else if(cid == 3)
        {
          if(frachter == sffrachtid2) SetPlayerCheckpoint(playerid, -1276.63, -23.06, 14.14, 5);
          else SetPlayerCheckpoint(playerid, -1316.46, 14.27, 14.14, 5);
        }
        else if(cid == 4)
          SetPlayerRaceCheckpoint(playerid, 0, -1594.41,  -212.05,  14.06, -1681.95,  -192.29,  14.06, 30);
        else if(cid == 5)
          SetPlayerRaceCheckpoint(playerid, 0, -1681.95,  -192.29,  14.06, -997.23,  494.91,  39.16, 30);
        else if(cid == 6)
          SetPlayerRaceCheckpoint(playerid, 3, -997.23,  494.91,  39.16, -997.23,  494.91,  39.16, 30);
        else if(cid == 7)
          SetPlayerRaceCheckpoint(playerid, 3, 1674.35, 454.60, 89.37, 1477.33, 1661.86, 10.76, 30);
        else if(cid == 8)
          SetPlayerRaceCheckpoint(playerid, 0, 1477.33, 1661.86, 10.76, 1579.14, 1623.21, 12.01, 30);
        else if(cid == 9)
          SetPlayerRaceCheckpoint(playerid, 0, 1477.33, 1661.86, 10.76, 1579.14, 1623.21, 12.01, 30);
        else if(cid == 10)
          SetPlayerCheckpoint(playerid, 1579.14, 1623.21, 12.01, 5);
        else if(cid == 11)
          SetPlayerRaceCheckpoint(playerid, 0, 1562.34,  1415.22,  10.76, 1531.70,  1290.76,  10.73, 30);
        else if(cid == 12)
          SetPlayerRaceCheckpoint(playerid, 0, 1531.70,  1290.76,  10.73, 1475.72,  1883.81,  60.15, 30);
        else if(cid == 13)
          SetPlayerRaceCheckpoint(playerid, 3, 1475.72,  1883.81,  60.15, 1475.72,  1883.81,  60.15, 30);
        else if(cid == 14)
          SetPlayerRaceCheckpoint(playerid, 3,2456.07,  -2435.62,  92.85, 1516.13,  -2494.51,  13.47, 30);
        else if(cid == 15)
          SetPlayerRaceCheckpoint(playerid, 0,1516.13,  -2494.51,  13.47, 1978.04,  -2591.81,  13.50, 30);
        else if(cid == 16)
          SetPlayerRaceCheckpoint(playerid, 0, 1978.04,  -2591.81,  13.50, 1924.21, -2252.77, 14.74, 30);
        else if(cid == 17)
          SetPlayerCheckpoint(playerid, 1924.21, -2252.77, 14.74, 5);
        else if(cid == 18)
          SetPlayerRaceCheckpoint(playerid, 0, 1957.70,  -2445.05,  13.45, 1415.75,  -2496.19,  59.74, 30);
        else if(cid == 19)
          SetPlayerRaceCheckpoint(playerid, 3, 1415.75,  -2496.19,  59.74, 1415.75,  -2496.19,  59.74, 30);
        else if(cid == 20)
          SetPlayerRaceCheckpoint(playerid, 3, -390.01,  505.41,  101.36, -1612.81,  -120.19,  14.08, 30);
        else if(cid == 21)
          SetPlayerRaceCheckpoint(playerid, 0, -1612.81,  -120.19,  14.08, -1599.26,  -214.60,  14.08, 30);
        else if(cid == 22 && frachter == sffrachtid1)
          SetPlayerRaceCheckpoint(playerid, 0, -1599.26,  -214.60,  14.08, -1313.10,  24.68,  15, 30);
        else if(cid == 22 && frachter == sffrachtid2)
          SetPlayerRaceCheckpoint(playerid, 0, -1599.26,  -214.60,  14.08, -1271.70,  -14.25,  15, 30);
        else if(cid == 23 && frachter == sffrachtid1)
          SetPlayerCheckpoint(playerid, -1313.10,  24.68,  15, 5);
        else if(cid == 23 && frachter == sffrachtid2)
          SetPlayerCheckpoint(playerid, -1271.70, -14.25,  15, 5);
        else if(cid == 24)
          SetPlayerCheckpoint(playerid, -1317.50, -608.85, 14.2, 5);
        pilotmission[playerid]++;
      }
    }
  }
  
  //Abbruch timer nach 3 MIN ohne checkpoint
  KillTimer(pilottimer[playerid]);
  if(pilots[playerid] > 0 && pilots[playerid] < 5 && pilots[playerid] != 3) pilottimer[playerid] = SetTimerEx("abbruch_pilot",180000,false,"i",playerid);
  else if(pilots[playerid] == 3 && pilots[playerid] > 4) pilottimer[playerid] = SetTimerEx("abbruch_pilot",180000,false,"i",playerid);
}

public ptanken(vid)
{
  SetVehicleParamsEx(vid,0,0, 0, 1, 0, 0, 0);
  new query[250];
  format(query,250,"UPDATE tankstellen SET cur_cash = cur_cash + (%f*vk_diesel) ,cur_diesel = cur_diesel - %f WHERE ts_id = 19",(float(Fahrzeugdaten[GetVehicleModel(vid)-400][0])-Fahrzeuge[vid][0]),(float(Fahrzeugdaten[GetVehicleModel(vid)-400][0])-Fahrzeuge[vid][0]));
  mysql_query(query);
  Fahrzeuge[vid][0] = float(Fahrzeugdaten[GetVehicleModel(vid)-400][0]);
  Fahrzeuge[vid][1] = 1000.0;
}

public tankpilot(playerid,count,vid)
{
  new query[250];
  TogglePlayerControllable(playerid,1);
  if(count == 0)
    GameTextForPlayer(playerid,"~w~Betankung abgeschlossen",3000,3);
  else if(count == 1)
    GameTextForPlayer(playerid,"~w~Bording abgeschlossen",3000,3);
  else if(count == 2)
    GameTextForPlayer(playerid,"~w~Beladung abgeschlossen",3000,3);
  format(query,250,"UPDATE tankstellen SET cur_cash = cur_cash + (%f*vk_diesel) ,cur_diesel = cur_diesel - %f WHERE ts_id = 19",(float(Fahrzeugdaten[GetVehicleModel(vid)-400][0])-Fahrzeuge[vid][0]),(float(Fahrzeugdaten[GetVehicleModel(vid)-400][0])-Fahrzeuge[vid][0]));
  mysql_query(query);
  Fahrzeuge[vid][0] = float(Fahrzeugdaten[GetVehicleModel(vid)-400][0]);
}

public erlaubnislandbahn(bahn)
{
  if(bahn == 0 && landebahnls == 0) //LS
    return 1;
  else if(bahn == 1 && landebahnsf == 0) //SF
    return 1;
  else if(bahn == 2 && landebahnlv == 0) //LV
    return 1;
  else
    return 0;
}

public erlaubnislandebahnabwarten(playerid,bahn,kind)
{
  if(erlaubnislandbahn(bahn))
    pilotstart(playerid);
  else
  {
    if(kind == 0)
      GameTextForPlayer(playerid,"~r~keine~w~Starterlaubnis~n~warten Sie!",5000,3);
    if(kind == 1)
      GameTextForPlayer(playerid,"~r~keine~w~Landeerlaubnis~n~fliegen Sie eine Schleife!",5000,3);
    if(IsPlayerConnected(playerid))
      SetTimerEx("erlaubnislandebahnabwarten",5000,false,"iii",playerid,bahn,kind);
  }
}

public abbruch_pilot(playerid)
{
  giveusermoney(playerid,-5000);
  SendClientMessage(playerid, COLOR_PBOTE, "Auftrag abgebrochen! 5000$ Strafe bezahlt.");
  if((pilots[playerid] == 1 || pilots[playerid] == 2) && (pilotmission[playerid] == 8 || pilotmission[playerid] == 43))
    landebahnsf = 0;
  if((pilots[playerid] == 1 || pilots[playerid] == 2) && (pilotmission[playerid]== 20|| pilotmission[playerid] == 15))
    landebahnlv = 0;
  if((pilots[playerid] == 1 || pilots[playerid] == 2) && (pilotmission[playerid] == 35 ||pilotmission[playerid] == 28))
    landebahnls = 0;
  if(pilots[playerid] == 5 || pilots[playerid] == 6)
  {
    new query[125];
    if(ftrans[(pilots[playerid]-5)][0] == 0 && ftrans[(pilots[playerid]-5)][1] == 1)
      query = "UPDATE fprods SET destination1 = destination1 + 1000 WHERE pID=1";
    else if(ftrans[(pilots[playerid]-5)][0] == 0 && ftrans[(pilots[playerid]-5)][1] == 2)
      query = "UPDATE fprods SET destination2 = destination2 + 1000 WHERE pID=1";
    else if(ftrans[(pilots[playerid]-5)][0] == 1 && ftrans[(pilots[playerid]-5)][1] == 0)
      query = "UPDATE fprods SET destination1 = destination1 + 1000 WHERE pID=0";
    else if(ftrans[(pilots[playerid]-5)][0] == 1 && ftrans[(pilots[playerid]-5)][1] == 2)
      query = "UPDATE fprods SET destination2 = destination2 + 1000 WHERE pID=0";
    else if(ftrans[(pilots[playerid]-5)][0] == 2 && ftrans[(pilots[playerid]-5)][1] == 0)
      query = "UPDATE fprods SET destination1 = destination1 + 1000 WHERE pID=2";
    else if(ftrans[(pilots[playerid]-5)][0] == 2 && ftrans[(pilots[playerid]-5)][1] == 1)
      query = "UPDATE fprods SET destination2 = destination2 + 1000 WHERE pID=2";
    mysql_query(query);
  }
  pilots[playerid] = 0;
  DisablePlayerCheckpoint(playerid);
  DisablePlayerRaceCheckpoint(playerid);
  pilotmission[playerid] = 0;
  navivar[playerid] = 0;
}

public pilot_response(playerid, dialogid, response, listitem, inputtext[])
{
  if(dialogid == 11 && response && pilots[playerid] == 0) 
  {
    new con = 1;
    for(new i = 0; i < MAX_PLAYERS;i++)
    {
      if((listitem+1) == pilots[i])
      {
        con = 0;
        break;
      }
    }
    mysql_query("SELECT cur_diesel FROM tankstellen WHERE ts_id = 19");
    new data[10];
    mysql_store_result();
    mysql_fetch_row(data);
    mysql_fetch_field("cur_diesel",data);
    ;
    
    if(strval(data) < 3000 && (listitem == 0 || listitem == 1)) con = 2;
    else if(strval(data) < 800 && (listitem == 2 || listitem == 3)) con = 2;
    else if(strval(data) < 2500 && (listitem == 4 || listitem == 5)) con = 2;
    
    if(con && con != 2)
    {
      if(listitem == 0)
        pilots[playerid] = 1;
      if(listitem == 1)
        pilots[playerid] = 2;
      if(listitem == 2)
        pilots[playerid] = 3;
      if(listitem == 3)
        pilots[playerid] = 4;
      if(listitem == 4)
        pilots[playerid] = 5;
      if(listitem == 5)
        pilots[playerid] = 6;
      pilotmission[playerid] = 0;
      pilotstart(playerid);
      navivar[playerid] = 2;
    }
    else if(con == 2)
      SendClientMessage(playerid, COLOR_RED, "Nicht genügend Treibstoff für Flugzeuge vorhanden.");
    else
      SendClientMessage(playerid, COLOR_RED, "Auftrag bereits vergeben.");
  }
}

public pilot_pickups(playerid,pickupid)
{
  if(pickupid == pilotpickstart && playerdata[playerid][2] == 5)
  {
	pilotdia(playerid);
	SetPlayerPos(playerid,-1328.01,  -395.49,  14.14);
  }
}