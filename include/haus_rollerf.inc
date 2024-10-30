forward roller();
forward rollerf(playerid);
forward rollerende(playerid);

new fahrschuleroller_pick,rollerfahr[MAX_PLAYERS],rollerstraf[MAX_PLAYERS],timer_roller[MAX_PLAYERS];

public roller()
{
  CreateVehicleEx(448,1362.8, -1660.0, 13.38,270,144,1,60); // Roller
  CreateVehicleEx(448,1362.8, -1656.0, 13.38,270,144,1,60); // Roller
  CreateVehicleEx(448,1362.8, -1652.0, 13.38,270,144,1,60); // Roller
  CreateVehicleEx(448,1362.8, -1648.0, 13.38,270,144,1,60); // Roller
  CreateVehicleEx(448,1362.8, -1644.0, 13.38,270,144,1,60); // Roller
  
  fahrschuleroller_pick = CreatePickup(1239,1,1411.3, -1700.0, 13.5,-1);
  Create3DTextLabel("Roller - Fahrschule",COLOR_WHITE,1411.3, -1700.0, 14.5,25,0);
  CreateDynamicMapIcon(1411.3, -1700.0, 13.5, 36, -1,-1, -1, -1, 500);
}

public rollerf(playerid)
{
  new Float:rollercheck[][3] =
  {
	{1362.8, -1652.0, 13.38},
	{1397.56, -1648.36, 12.97},
	{1419.88, -1648.81, 12.97},
	{1435.26, -1557.84, 12.95},
	{1458.36, -1444.03, 12.98},
	{1471.75, -1433.72, 13.14}, 
	{1474.50, -1413.53, 11.47}, 
	{1470.46, -1391.57, 11.47}, 
	{1475.05, -1371.29, 11.48}, 
	{1471.00, -1351.23, 11.47}, 
	{1459.24, -1327.70, 13.03}, 
	{1494.15, -1305.94, 13.44}, 
	{1590.25, -1304.82, 16.92}, 
	{1600.68, -1415.94, 13.19}, 
	{1653.33, -1445.60, 12.98}, 
	{1648.34, -1533.02, 13.14}, 
	{1652.09, -1546.89, 13.14}, 
	{1648.85, -1560.49, 13.14}, 
	{1652.54, -1571.92, 13.14}, 
	{1648.42, -1584.82, 13.13}, 
	{1607.69, -1706.64, 13.14}, 
	{1476.59, -1730.52, 12.97}, 
	{1428.95, -1708.75, 12.98}, 
	{1404.58, -1649.01, 12.97}
  };
  navivar[playerid] = 2;
  if(rollerfahr[playerid] == 0)
  {
	SetPlayerCheckpoint(playerid,rollercheck[rollerfahr[playerid]][0],rollercheck[rollerfahr[playerid]][1],rollercheck[rollerfahr[playerid]][2],5);
  }
  if(rollerfahr[playerid] == 1)
  {
	GameTextForPlayer(playerid, "~w~Starten Sie den Motor. ~n~Folgen Sie der Route.", 3000, 3);
  }
  if(rollerfahr[playerid] == 23 && GetVehicleModel(GetPlayerVehicleID(playerid)) == 448)
  {
	SetPlayerCheckpoint(playerid,rollercheck[rollerfahr[playerid]][0],rollercheck[rollerfahr[playerid]][1],rollercheck[rollerfahr[playerid]][2],5);
  }
  else if(rollerfahr[playerid] == 1)
  {
	SetPlayerRaceCheckpoint(playerid,CP_TYPE:0,rollercheck[rollerfahr[playerid]][0],rollercheck[rollerfahr[playerid]][1],rollercheck[rollerfahr[playerid]][2],rollercheck[rollerfahr[playerid]+1][0],rollercheck[rollerfahr[playerid]+1][1],rollercheck[rollerfahr[playerid]+1][2],2);
  }
  else if(rollerfahr[playerid] > 1 && rollerfahr[playerid] < 23 && GetVehicleModel(GetPlayerVehicleID(playerid)) == 448)
  {
	SetPlayerRaceCheckpoint(playerid,CP_TYPE:0,rollercheck[rollerfahr[playerid]][0],rollercheck[rollerfahr[playerid]][1],rollercheck[rollerfahr[playerid]][2],rollercheck[rollerfahr[playerid]+1][0],rollercheck[rollerfahr[playerid]+1][1],rollercheck[rollerfahr[playerid]+1][2],2);
  }
  
  if(rollerfahr[playerid] > 1 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 448)
  {
	rollerfahr[playerid]--;
	rollerstraf[playerid]++;
  }
  
  if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 448) //Strafpunkte bei mehr als 3 oder mehr als 10% Schaden durchgefallen
  {
	new Float:Velocity[3];
	GetVehicleVelocity(GetPlayerVehicleID(playerid), Velocity[0], Velocity[1], Velocity[2]);
	new geschw = floatround(floatsqroot(Velocity[0]*Velocity[0]+Velocity[1]*Velocity[1]+Velocity[2]*Velocity[2])*100*1.5,floatround_ceil);
	if(geschw > 70)
	{
	  rollerstraf[playerid]++;
	  SendClientMessage(playerid, COLOR_RED, "Strafpunkt erhalten Sie sind zu schnell gefahren.");
	}
	new bool:engine, bool:lights, bool:alarm, bool:doors, bool:bonnet, bool:boot, bool:objective;
	GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, doors, bonnet, boot, objective);
	if(lights == false)
	{
	  rollerstraf[playerid]++;
	  SendClientMessage(playerid, COLOR_RED, "Strafpunkt erhalten kein Licht an.");
	}
	new schad = floatround(((((Fahrzeuge[GetPlayerVehicleID(playerid)][1] - 250) / 750) -1) *-100),floatround_ceil);
	if(schad > 10)
	{
	  rollerstraf[playerid] = 4;
	  SendClientMessage(playerid, COLOR_RED, "4 Strafpunkte erhalten Roller zu sehr beschädigt.");
	}
  }
  
  if(rollerstraf[playerid] < 4 && rollerfahr[playerid] == 24)
  {
	GameTextForPlayer(playerid, "~g~Fahrstunde beendet. ~n~~w~Sie haben bestanden!", 3000, 3);
	fahrstunde[playerid] = 0;
	Fahrzeuge[GetPlayerVehicleID(playerid)][0] = float(Fahrzeugdaten[GetVehicleModel(GetPlayerVehicleID(playerid))-400][0]);
	Fahrzeuge[GetPlayerVehicleID(playerid)][1] = 1000.0;
	SetVehicleParamsEx(GetPlayerVehicleID(playerid), false, false, false, false, false, false, false);
	SetVehicleToRespawn(GetPlayerVehicleID(playerid));
	playerdata[playerid][20] = 1;
    navivar[playerid] = 0;
	SendClientMessage(playerid,COLOR_BERUF,"Sie haben den Rollerschein erhalten.");
	RemovePlayerFromVehicle(playerid);
  }
  
  //Timer Killen und neu Setzen auf 60 Sekunden zu jedem checkpoint
  KillTimer(timer_roller[playerid]);
  if(rollerstraf[playerid] < 4 && fahrstunde[playerid] == 20)
	timer_roller[playerid] = SetTimerEx("rollerende",60000,false,"i",playerid);
  else if(fahrstunde[playerid] == 20)
  {
	rollerende(playerid);
    navivar[playerid] = 0;
	SendClientMessage(playerid, COLOR_RED, "Zuviele Strafpunkte erhalten. Fahrstunde beendet.");
  }
  rollerfahr[playerid]++;
}

public rollerende(playerid)
{
  fahrstunde[playerid] = 0;
  navivar[playerid] = 0;
  GameTextForPlayer(playerid, "~r~Fahrstunde beendet. ~n~~w~Sie sind durchgefallen!", 3000, 3);
  DisablePlayerRaceCheckpoint(playerid);
  DisablePlayerCheckpoint(playerid);
  if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 448)
  {
	SetVehicleToRespawn(GetPlayerVehicleID(playerid));
	RemovePlayerFromVehicle(playerid);
  }
}