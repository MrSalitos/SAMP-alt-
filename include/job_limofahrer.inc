forward limofahrer();
forward limodialog(playerid);
forward limo(playerid);
forward limodialogr(playerid, dialogid, response, listitem);
forward limofwait(playerid,kind);
forward abbruchlimo(playerid);

new limof[MAX_PLAYERS];
new limofahrzeuge[8];

public limofahrer()
{
  CreateDynamicObject(5837,2327.12,1459.86,43.3, 0.0, 0.0, 0.0);
  
  Create3DTextLabel("Job Limousinenfahrer\n Steig in eine Limousine ein ",COLOR_WHITE,2327.12,1459.86,42.82,25,0);
    
  limofahrzeuge[0] = CreateVehicleEx(409,2353.85,  1405.0,  42.39,90,0,0,60,0,0,"Limo-Service");
  limofahrzeuge[1] = CreateVehicleEx(409,2353.85,  1408.5,  42.39,90,0,0,60,0,0,"Limo-Service");
  limofahrzeuge[2] = CreateVehicleEx(409,2353.85,  1412.0,  42.39,90,0,0,60,0,0,"Limo-Service");
  limofahrzeuge[3] = CreateVehicleEx(409,2353.85,  1415.5,  42.39,90,0,0,60,0,0,"Limo-Service");
  limofahrzeuge[4] = CreateVehicleEx(409,2353.85,  1419.0,  42.39,90,0,0,60,0,0,"Limo-Service");
  limofahrzeuge[5] = CreateVehicleEx(409,2353.85,  1422.5,  42.39,90,0,0,60,0,0,"Limo-Service");
  limofahrzeuge[6] = CreateVehicleEx(409,2353.85,  1426.0,  42.39,90,0,0,60,0,0,"Limo-Service");
  limofahrzeuge[7] = CreateVehicleEx(409,2353.85,  1429.5,  42.39,90,0,0,60,0,0,"Limo-Service");
  
  CreateDynamicMapIcon(2353.85,  1419.0,  42.39, 51, -1,-1, -1, -1, 500);
}

public limodialog(playerid)
{
  if(limof[playerid] == 0)
    ShowPlayerDialog(playerid, 101, DIALOG_STYLE_LIST, "Limousinenfahrer", "Starte einen Job als Limousinenfahrer(150 $)" , "Starten", "Abbrechen");
}

public limodialogr(playerid, dialogid, response, listitem)
{
  if(dialogid == 101 && response)
  {
    limof[playerid] = 1;
    limo(playerid);
  }
}

public limo(playerid)
{
  new Float:starts[][4] =
  {
    {2627.19, 1825.78, 11.02, 0.0},
    {2490.12, 1535.16, 10.67, 225.0},
    {2459.26, 1427.22, 10.82, 90.34},
    {2831.38, 1293.04, 10.77, 0.00},
    {2359.73, 2375.38, 10.82, 0.0},
    {2430.98, 2375.79, 10.67, 0.0}
  };
  
  new Float:destination[][4] =
  {
    {2232.23, 1287.58, 10.54, 90.0},
    {2230.65, 1288.26, 10.67, 0.0},
    {2028.00, 1343.45, 10.82, 180.0},
    {2019.75, 1176.91, 10.82, 130.0},
    {2031.36, 1009.71, 10.82, 183.0},
    {2171.98, 1120.48, 12.56, 330.0},
    {2140.84, 1487.46, 10.82, 4.58},
    {2174.91, 1681.19, 10.82, 0.0},
    {2217.89, 1840.15, 10.82, 0.0},
    {2505.70, 2133.68, 10.67, 265.0},
    {2026.58, 1915.79, 12.12, 265.0},
    {2031.63, 1621.89, 12.06, 180.0},
    {1941.61, 1343.20, 9.25, 0.0}
  };
  
  new Float:fahrzeuge[][3] =
  {
    {2353.85,  1405.0,  42.39},
    {2353.85,  1408.5,  42.39},
    {2353.85,  1412.0,  42.39},
    {2353.85,  1415.5,  42.39},
    {2353.85,  1419.0,  42.39},
    {2353.85,  1422.5,  42.39},
    {2353.85,  1426.0,  42.39},
    {2353.85,  1429.5,  42.39}
  };
  
  if(limof[playerid] == 1)
  {
    new r = random(sizeof(starts));
    SetPlayerCheckpoint(playerid, starts[r][0],  starts[r][1], starts[r][2], 5);
    playerdata[playerid][4] = playerdata[playerid][4] - 500;
    GivePlayerMoney(playerid,-500);
    SendClientMessage(playerid, COLOR_YELLOW, "Kaution fürs Fahrzeug erhoben (500$).");
    GameTextForPlayer(playerid, "~w~Fahre deinen Gast abholen!", 3000, 1);
    navivar[playerid] = 2;
    limof[playerid]++;
  }
  else if(limof[playerid] == 2)
  {
    for(new i = 0; i < sizeof(starts); i++)
    {
      if(IsPlayerInRangeOfPoint(playerid, 5, starts[i][0], starts[i][1], starts[i][2]))
      {
        new Float:zangle;
        GetVehicleZAngle(GetPlayerVehicleID(playerid),zangle);
        if(starts[i][3] == 0.0)
        {
          if((zangle >= 350.0 && zangle < 360.0) ||(zangle >= 0.0 && zangle <= 10.0))
          {
            DisablePlayerCheckpoint(playerid);
            limof[playerid]++;
            new r = random(sizeof(destination));
            SetPlayerCheckpoint(playerid, destination[r][0],  destination[r][1], destination[r][2], 5);
            TogglePlayerControllable(playerid,0);
            GameTextForPlayer(playerid, "~w~ Warten Sie auf Ihren Gast!", 3000, 1);
            SetTimerEx("limofwait",10000,false,"ii",playerid,0);
          }
          else
          {
            GameTextForPlayer(playerid, "~r~Fahre Parallel zur Strasse an das Ziel!", 3000, 1);
          }
        }
        else
        {
          if(zangle >= (starts[i][3]-10.0) && zangle >= (starts[i][3]+10.0))
          {
            DisablePlayerCheckpoint(playerid);
            limof[playerid]++;
            new r = random(sizeof(destination));
            SetPlayerCheckpoint(playerid, destination[r][0],  destination[r][1], destination[r][2], 5);
            TogglePlayerControllable(playerid,0);
            GameTextForPlayer(playerid, "~w~ Warten Sie auf Ihren Gast!", 3000, 1);
            SetTimerEx("limofwait",10000,false,"ii",playerid,0);
          }
          else
          {
            GameTextForPlayer(playerid, "~r~Fahre Parallel zur Strasse an das Ziel!", 3000, 1);
          }
        }
      }
    }
  }
  else if(limof[playerid] == 3)
  {
    for(new i = 0; i < sizeof(destination); i++)
    {
      if(IsPlayerInRangeOfPoint(playerid, 5, destination[i][0], destination[i][1], destination[i][2]))
      {
        new Float:zangle;
        GetVehicleZAngle(GetPlayerVehicleID(playerid),zangle);
        if(destination[i][3] == 0.0)
        {
          if((zangle >= 350.0 && zangle < 360.0) ||(zangle >= 0.0 && zangle <= 10.0))
          {
            DisablePlayerCheckpoint(playerid);
            limof[playerid]++;
            for(new j; j < sizeof(limofahrzeuge); j++)
            {
              if(limofahrzeuge[j] == GetPlayerVehicleID(playerid))
              {
                SetPlayerCheckpoint(playerid, fahrzeuge[j][0],  fahrzeuge[j][1], fahrzeuge[j][2], 5);
              }
            }
            TogglePlayerControllable(playerid,0);
            GameTextForPlayer(playerid, "~w~ Warten Sie bis Ihr Gast ausgestiegen ist!", 3000, 1);
            SetTimerEx("limofwait",10000,false,"ii",playerid,1);
          }
          else
          {
            GameTextForPlayer(playerid, "~r~Fahre Parallel zur Strasse an das Ziel!", 3000, 1);
          }
        }
        else
        {
          if(zangle >= (destination[i][3]-10.0) && zangle >= (destination[i][3]+10.0))
          {
            DisablePlayerCheckpoint(playerid);
            limof[playerid]++;
            for(new j; j < sizeof(limofahrzeuge); j++)
            {
              if(limofahrzeuge[j] == GetPlayerVehicleID(playerid))
              {
                SetPlayerCheckpoint(playerid, fahrzeuge[j][0],  fahrzeuge[j][1], fahrzeuge[j][2], 8);
              }
            }
            TogglePlayerControllable(playerid,0);
            GameTextForPlayer(playerid, "~w~ Warten Sie bis Ihr Gast ausgestiegen ist!", 3000, 1);
            SetTimerEx("limofwait",10000,false,"ii",playerid,1);
          }
          else
          {
            GameTextForPlayer(playerid, "~r~Fahre Parallel zur Strasse an das Ziel!", 3000, 1);
          }
        }
      }
    }
  }
  else if(limof[playerid] == 4)
  {
    new Float:zangle,Float:health;
    GetVehicleZAngle(GetPlayerVehicleID(playerid),zangle);
    GetVehicleHealth(GetPlayerVehicleID(playerid),health);
    if(zangle >= 85.0 && zangle <= 95.0 && health >= 900.0)
    {
      DisablePlayerCheckpoint(playerid);
      limof[playerid] = 0;
      SetVehicleToRespawn(GetPlayerVehicleID(playerid));
      RemovePlayerFromVehicle(playerid);
      SendClientMessage(playerid, COLOR_YELLOW, "Kaution fürs Fahrzeug zurückgegeben.");
      playerdata[playerid][4] = playerdata[playerid][4] + 650;
      GivePlayerMoney(playerid,650);
      GameTextForPlayer(playerid, "~g~Auftrag beendet!~n~Praemie erhalten", 3000, 1);
    }
    else if(health < 900.0)
    {
      GameTextForPlayer(playerid, "~r~Reparieren sie das Fahrzeug!", 3000, 1);
    }
    else
    {
      GameTextForPlayer(playerid, "~r~Parken sie rueckwaerts!", 3000, 1);
    }
  }
}

public limofwait(playerid,kind)
{
  TogglePlayerControllable(playerid,1);
  if(kind == 0)
    GameTextForPlayer(playerid, "~w~Fahre deinen Gast zum Ziel!", 3000, 1);
  else
    GameTextForPlayer(playerid, "~w~Bringen Sie das Auto repariert zum Depot!", 3000, 1);
}

public abbruchlimo(playerid)
{
  for(new i; i < sizeof(limofahrzeuge);i++)
  {
    if(GetPlayerVehicleID(playerid) == limofahrzeuge[i])
    {
      SetVehicleToRespawn(limofahrzeuge[i]);
      RemovePlayerFromVehicle(playerid);
    }
  }
  limof[playerid] = 0;
}
