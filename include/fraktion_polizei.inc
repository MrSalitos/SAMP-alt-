/* ********************************************************* */
/* Autor: MrSalitos                                          */
/* ********************************************************* */

/* *************************  COLOR   ********************** */


/* *************************   NAVI   ********************** */
#define CP_LSPD 1536.0,-1675.0,13.5
#define CP_SFPD -1607.0,724.0,12.0
#define CP_LVPD 2306.0,2417.5,10.5
#define CP_SHERIFF_DILLIMORE 637.5,-571.5,16.5
#define CP_SHERIFF_ANGELPINE -2165.0,-2390.0,30.5
#define CP_SHERIFF_ELQUEDBRADOS -1400.0,2640.0,55.5
#define CP_SHERIFF_FORTCARSON -226.0,999.0,19.5

/* *************************   MISC   ********************** */
#define PLAYER_IS_COP playerdata[playerid][2] == 4 
#define PLAYERCAR_IS_COP GetVehicleModel(GetPlayerVehicleID(playerid)) == 497 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 523 ||GetVehicleModel(GetPlayerVehicleID(playerid)) == 596 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 597 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 598 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 599
#define PLAYERCAR_BLITZER GetPlayerVehicleID(playerid)) == lspd_car[13] || GetPlayerVehicleID(playerid)) == lspd_car[14] || GetPlayerVehicleID(playerid)) == lspd_car[15]
new lspd_car[16];
new sfpd_car[16];
new lvpd_car[16];
new sheriff_car[4][5];
new mitsubishibus[9];
new bool:CarTrackActive;
new bool:CopOnDuty[MAX_PLAYERS];
new bool:BlitzerStatus[MAX_PLAYERS] = false;


forward LSPD();
forward SFPD();
forward LVPD();
forward Sheriff();
forward CarTrack(playerid);
forward CarTrackDialog(playerid, dialogid, response, listitem);
forward BlitzerDialog(playerid, dialogid, response, listitem);
forward CheckPlayerWantedLevel(playerid);
forward PlayerInPrison(playerid);
forward SetBlitzer(playerid, blitzerid, Float:bX, Float:bY, Float:bZ);
/* *************************   LSPD   ********************** */
public LSPD()
{ 
	lspd_car[0] = CreateVehicleEx(497, 1567.50, -1707.5, 28.50, 90, 0, 26, 300);			//Helikopter
	lspd_car[1] = CreateVehicleEx(596, 1545.00, -1651.00, 6.00, 90, 0, 26, 300);			//Streife 1	
	lspd_car[2] = CreateVehicleEx(596, 1545.00, -1655.00, 6.00, 90, 0, 26, 300);			//Streife 2
	lspd_car[3] = CreateVehicleEx(596, 1545.00, -1659.00, 6.00, 90, 0, 26, 300);			//Streife 3
	lspd_car[4] = CreateVehicleEx(596, 1545.00, -1663.00, 6.00, 90, 0, 26, 300);			//Streife 4
	lspd_car[5] = CreateVehicleEx(596, 1545.00, -1668.00, 6.00, 90, 0, 26, 300);			//Streife 5
	lspd_car[6] = CreateVehicleEx(596, 1545.00, -1672.00, 6.00, 90, 0, 26, 300);			//Streife 6
	lspd_car[7] = CreateVehicleEx(596, 1545.00, -1676.00, 6.00, 90, 0, 26, 300);			//Streife 7
	lspd_car[8] = CreateVehicleEx(596, 1545.00, -1680.00, 6.00, 90, 0, 26, 300);			//Streife 8
	lspd_car[9] = CreateVehicleEx(523, 1540.00, -1645.00, 6.00, 180, 0, 26, 300);			//Motorrad 1
	lspd_car[10] = CreateVehicleEx(523, 1537.50, -1645.00, 6.00, 180, 0, 26, 300);			//Motorrad 2
	lspd_car[11] = CreateVehicleEx(523, 1535.00, -1645.00, 6.00, 180, 0, 26, 300);			//Motorrad 3
	lspd_car[12] = CreateVehicleEx(523, 1532.50, -1645.00, 6.00, 180, 0, 26, 300);			//Motorrad 4
	mitsubishibus[0] = CreateVehicleEx(418, 1530.00, -1645.00, 6.00, 180, 0, 26, 300);	//Blitzer 1
	mitsubishibus[1] = CreateVehicleEx(418, 1526.00, -1645.00, 6.00, 180, 0, 26, 300);	//Blitzer 2
	mitsubishibus[2] = CreateVehicleEx(418, 1522.00, -1645.00, 6.00, 180, 0, 26, 300);	//Blitzer 3
}
/* *************************   SFPD   ********************** */
public SFPD()
{ 
	sfpd_car[0] = CreateVehicleEx(497, -1680.25,  706.00,  30.60, 90, 79, 26, 300);			//Helikopter
	sfpd_car[1] = CreateVehicleEx(597, -1573.50,  706.00,  -5.15, 90, 26, 79, 300);			//Streife 1	
	sfpd_car[2] = CreateVehicleEx(597, -1573.50,  710.00,  -5.15, 90, 26, 79, 300);			//Streife 2
	sfpd_car[3] = CreateVehicleEx(597, -1573.50,  714.25,  -5.15, 90, 26, 79, 300);			//Streife 3
	sfpd_car[4] = CreateVehicleEx(597, -1573.50,  718.25,  -5.15, 90, 26, 79, 300);			//Streife 4
	sfpd_car[5] = CreateVehicleEx(597, -1573.50,  722.25,  -5.15, 90, 26, 79, 300);			//Streife 5
	sfpd_car[6] = CreateVehicleEx(597, -1573.50,  726.25,  -5.15, 90, 26, 79, 300);			//Streife 6
	sfpd_car[7] = CreateVehicleEx(597, -1573.50,  730.25,  -5.15, 90, 26, 79, 300);			//Streife 7
	sfpd_car[8] = CreateVehicleEx(597, -1573.50,  734.25,  -5.15, 90, 26, 79, 300);			//Streife 8
	sfpd_car[9] = CreateVehicleEx(523, -1573.50,  737.50,  -5.65, 90, 26, 79, 300);			//Motorrad 1
	sfpd_car[10] = CreateVehicleEx(523, -1573.50,  739.25,  -5.65, 90, 26, 79, 300);		//Motorrad 2
	sfpd_car[11] = CreateVehicleEx(523, -1573.50,  742.00,  -5.65, 90, 26, 79, 300);		//Motorrad 3
	sfpd_car[12] = CreateVehicleEx(523, -1573.50,  743.75,  -5.65, 90, 26, 79, 300);		//Motorrad 4
	mitsubishibus[3] = 0;//CreateVehicleEx(418, 1530.00, -1645.00, 6.00, 180, 0, 26, 300);	//Blitzer 1
	mitsubishibus[4] = 0;//CreateVehicleEx(418, 1526.00, -1645.00, 6.00, 180, 0, 26, 300);	//Blitzer 2
	mitsubishibus[5] = 0;//CreateVehicleEx(418, 1522.00, -1645.00, 6.00, 180, 0, 26, 300);	//Blitzer 3
}
/* *************************   LVPD   ********************** */
public LVPD()
{ 
	lvpd_car[0] = CreateVehicleEx(497, 2283.00, 2447.00, 74.0, 180, 0, 26, 300);			//Helikopter
	lvpd_car[1] = CreateVehicleEx(598, 2246.25, 2430.00, 3.27, 0, 0, 26, 300);				//Streife 1
	lvpd_car[2] = CreateVehicleEx(598, 2251.50, 2430.00, 3.27, 0, 0, 26, 300);				//Streife 2
	lvpd_car[3] = CreateVehicleEx(598, 2255.75, 2430.00, 3.27, 0, 0, 26, 300);				//Streife 3
	lvpd_car[4] = CreateVehicleEx(598, 2260.00, 2430.00, 3.27, 0, 0, 26, 300);				//Streife 4
	lvpd_car[5] = CreateVehicleEx(598, 2264.25, 2430.00, 3.27, 0, 0, 26, 300);				//Streife 5
	lvpd_car[6] = CreateVehicleEx(598, 2268.50, 2430.00, 3.27, 0, 0, 26, 300);				//Streife 6
	lvpd_car[7] = CreateVehicleEx(598, 2272.75, 2430.00, 3.27, 0, 0, 26, 300);				//Streife 7
	lvpd_car[8] = CreateVehicleEx(598, 2277.00, 2430.00, 3.27, 0, 0, 26, 300);				//Streife 8
	lvpd_car[9] = CreateVehicleEx(523, 2285.00, 2430.00, 3.27, 0, 26, 79, 300);				//Motorrad 1
	lvpd_car[10] = CreateVehicleEx(523, 2287.00, 2430.00, 3.27, 0, 26, 79, 300);			//Motorrad 2
	lvpd_car[11] = CreateVehicleEx(523, 2289.00, 2430.00, 3.27, 0, 26, 79, 300);			//Motorrad 3
	lvpd_car[12] = CreateVehicleEx(523, 2291.00, 2430.00, 3.27, 0, 26, 79, 300);			//Motorrad 4
	mitsubishibus[6] = 0;//CreateVehicleEx(418, 1530.00, -1645.00, 6.00, 180, 0, 26, 300);	//Blitzer 1
	mitsubishibus[7] = 0;//CreateVehicleEx(418, 1526.00, -1645.00, 6.00, 180, 0, 26, 300);	//Blitzer 2
	mitsubishibus[8] = 0;//CreateVehicleEx(418, 1522.00, -1645.00, 6.00, 180, 0, 26, 300);	//Blitzer 3
}
/* ************************* Sheriff  ********************** */
public Sheriff()
{ 
	//Dillimore Sheriff
	sheriff_car[0][0] = CreateVehicleEx(596, 615.00, -597.25, 16.95, 270, 26, 114, 300);	//Sheriff	
	sheriff_car[0][1] = CreateVehicleEx(599, 615.00, -601.50, 17.45, 270, 26, 114, 300);	//Streife 1	
	sheriff_car[0][2] = CreateVehicleEx(599, 620.00, -606.00, 17.45, 270, 26, 114, 300);	//Streife 2
	sheriff_car[0][3] = CreateVehicleEx(599, 620.00, -610.50, 17.45, 270, 26, 114, 300);	//Streife 3
	
	//Angel Pine Sheriff
	sheriff_car[1][0] = CreateVehicleEx(596, -2179.18,  -2369.54,  30.34, 58, 26, 114, 300);//Sheriff	
	sheriff_car[1][1] = CreateVehicleEx(599, -2172.90,  -2362.15,  30.82, 49, 26, 114, 300);//Streife 1	
	sheriff_car[1][2] = CreateVehicleEx(599, -2170.45,  -2359.30,  30.82, 49, 26, 114, 300);//Streife 2
	//sheriff_car[1][3] = CreateVehicleEx(599, -210.00, 990.00, 19.75, 90, 26, 123, 300);	//Streife 3

	//El Quedbrados Sheriff
	sheriff_car[2][0] = CreateVehicleEx(596, -1400.0, 2630.5, 56.5, 90, 26, 123, 300);		//Sheriff	
	sheriff_car[2][1] = CreateVehicleEx(599, -1406.5, 2626.0, 57.5, 00, 26, 123, 300);		//Streife 1	
	sheriff_car[2][2] = CreateVehicleEx(599, -1410.5, 2626.0, 57.5, 00, 26, 123, 300);		//Streife 2
	//sheriff_car[2][3] = CreateVehicleEx(599, -1400.0, 2644.0, 56.0, 90, 26, 123, 300);	//Streife 3

	//Fort Carson Sheriff
	sheriff_car[3][0] = CreateVehicleEx(596, -228.50, 983.50, 19.75, 0, 26, 123, 300);		//Sheriff	
	sheriff_car[3][1] = CreateVehicleEx(599, -210.00, 1000.0, 19.75, 90, 26, 123, 300);		//Streife 1	
	sheriff_car[3][2] = CreateVehicleEx(599, -210.00, 995.00, 19.75, 90, 26, 123, 300);		//Streife 2
	sheriff_car[3][3] = CreateVehicleEx(599, -210.00, 990.00, 19.75, 90, 26, 123, 300);		//Streife 3

}
/* ************************* CarTrack ********************** */
public CarTrack(playerid)
{ 
	if(CarTrackActive == true)
	{
		SendClientMessage(playerid, COLOR_COP, "*** Tracking ist bereits aktiv. Bitte warten... ***");
	}
	else ShowPlayerDialog(playerid, 2100, DIALOG_STYLE_LIST, "CarTrack 1.0", "LSPD - Autos\nSFPD - Autos\nLVPD - Autos\nSheriff - Autos", "Auswahl", "Beenden");
} 
public CarTrackDialog(playerid, dialogid, response, listitem)
{ 
	if(dialogid == 2100)
    { 
        if(response)
        { 
            if(listitem == 0)
			{ 
             	ShowPlayerDialog(playerid, 2101, DIALOG_STYLE_LIST, "CarTrack 1.0 - LSPD", "Helikopter\nWagen 1\nWagen 2\nWagen 3\nWagen 4\nWagen 5\nWagen 6\nWagen 7\nWagen 8\nMotorrad 1\nMotorrad 2\nMotorrad 3\nMotorrad 4", "Auswahl", "zurück");
            }
            else if(listitem == 1)
            { 
                ShowPlayerDialog(playerid, 2102, DIALOG_STYLE_LIST, "CarTrack 1.0 - SFPD", "Helikopter\nWagen 1\nWagen 2\nWagen 3\nWagen 4\nWagen 5\nWagen 6\nWagen 7\nWagen 8\nMotorrad 1\nMotorrad 2\nMotorrad 3\nMotorrad 4", "Auswahl", "zurück");
            }
            else if(listitem == 2)
            { 	
				ShowPlayerDialog(playerid, 2103, DIALOG_STYLE_LIST, "CarTrack 1.0 - LVPD", "Helikopter\nWagen 1\nWagen 2\nWagen 3\nWagen 4\nWagen 5\nWagen 6\nWagen 7\nWagen 8\nMotorrad 1\nMotorrad 2\nMotorrad 3\nMotorrad 4", "Auswahl", "zurück");
			}
			 else if(listitem == 3)
            { 	
				ShowPlayerDialog(playerid, 2104, DIALOG_STYLE_LIST, "CarTrack 1.0 - Sheriff", "Dillimore Sheriff\nAngel Pine Sheriff\nEl Quedbrados Sheriff\n Fort Carson Sheriff", "Auswahl", "zurück");		
            }
			return 1;
        }
    }
	if(dialogid == 2101)
	{ 
		new Float:x, Float:y, Float:z;
		if(response)
		{ 
		  GetVehiclePos(lspd_car[listitem],x,y,z);
          SetPlayerCheckpoint(playerid,x,y,z,6);
          CarTrackActive = true;
          //trackerid = playerid;
		}
	}
	if(dialogid == 2102)
	{ 
		new Float:x, Float:y, Float:z;
		if(response)
		{ 
		  GetVehiclePos(sfpd_car[listitem],x,y,z);
          SetPlayerCheckpoint(playerid,x,y,z,6);
          CarTrackActive = true;
          //trackerid = playerid;
		}
	}
	if(dialogid == 2103)
	{ 
		new Float:x, Float:y, Float:z;
		if(response)
		{ 
		  GetVehiclePos(lvpd_car[listitem],x,y,z);
          SetPlayerCheckpoint(playerid,x,y,z,6);
          CarTrackActive = true;
          //trackerid = playerid;
		}
	}
	if(dialogid == 2104)
	{ 
		if(response)
		{ 
			if(listitem == 0) { ShowPlayerDialog(playerid, 2110, DIALOG_STYLE_LIST, "CarTrack 1.0 - Dillimore", "Wagen 1\nRanger 1\nRanger 2\nRanger3", "Auswahl", "zurück"); }
			if(listitem == 1) { ShowPlayerDialog(playerid, 2111, DIALOG_STYLE_LIST, "CarTrack 1.0 - Angel Pine", "Wagen 1\nRanger 1\nRanger 2", "Auswahl", "zurück"); }
			if(listitem == 2) { ShowPlayerDialog(playerid, 2112, DIALOG_STYLE_LIST, "CarTrack 1.0 - El Quedbrados", "Wagen 1\nRanger 1\nRanger 2", "Auswahl", "zurück"); }
			if(listitem == 3) { ShowPlayerDialog(playerid, 2113, DIALOG_STYLE_LIST, "CarTrack 1.0 - Fort Carson", "Wagen 1\nRanger 1\nRanger 2\nRanger3", "Auswahl", "zurück"); }
		}
	}
	if(dialogid == 2110)
	{ 		
		new Float:x, Float:y, Float:z;
		if(response)
		{ 
		  GetVehiclePos(sheriff_car[0][listitem],x,y,z);
          SetPlayerCheckpoint(playerid,x,y,z,6);
          CarTrackActive = true;
          //trackerid = playerid;
		}
	}
	if(dialogid == 2111)
	{ 		
		new Float:x, Float:y, Float:z;
		if(response)
		{ 
		  GetVehiclePos(sheriff_car[1][listitem],x,y,z);
          SetPlayerCheckpoint(playerid,x,y,z,6);
          CarTrackActive = true;
          //trackerid = playerid;
		}
		
	}
	if(dialogid == 2112)
	{ 		
		new Float:x, Float:y, Float:z;
		if(response)
		{ 
		  GetVehiclePos(sheriff_car[2][listitem],x,y,z);
          SetPlayerCheckpoint(playerid,x,y,z,6);
          CarTrackActive = true;
          //trackerid = playerid;
		}
		
	}
	if(dialogid == 2110)
	{ 		
		new Float:x, Float:y, Float:z;
		if(response)
		{ 
		  GetVehiclePos(sheriff_car[3][listitem],x,y,z);
          SetPlayerCheckpoint(playerid,x,y,z,6);
          CarTrackActive = true;
          //trackerid = playerid;
		}
		
	}
	return 1;
}
/* ******************** Wantedlevel-Prüfung **************** */
public CheckPlayerWantedLevel(playerid)
{
	for(new i = 0; i < MAX_PLAYERS ; i++)
	{
		if(IsPlayerConnected(i))
		{
			switch(playerdata[i][35])
			{
				case 4:
				{
					SetPlayerMarkerForPlayer(playerid, i, COLOR_GREEN);
				}
				case 5:
				{
					SetPlayerMarkerForPlayer(playerid, i, COLOR_YELLOW);
				}
				case 6:
				{
					SetPlayerMarkerForPlayer(playerid, i, COLOR_RED);
				}
				default:
				{
					SetPlayerMarkerForPlayer(playerid, i, COLOR_INVISIBLE);
				}
			}
		}
	}
}
/* *********************** Gefängniszeit ******************* */
public PlayerInPrison(playerid)
{
	printf("Player %i ist jetzt im Gefängnis", playerid);
	if(playerdata[playerid][35] > 0)
	{
		SetPlayerInterior(playerid, 6);
		printf("%i", GetPlayerInterior(playerid));
		SetPlayerPos(playerid, 264.0, 78.0, 1001.5);
		playerdata[playerid][55] = 1;
		playerdata[playerid][11] = 0;
		playerdata[playerid][12] = 0;
		playerdata[playerid][13] = 0;
		playerdata[playerid][14] = 0;
		playerdata[playerid][15] = 0;
		playerdata[playerid][16] = 0;
		return 1;
	}
	else
		return 0;
}

public BlitzerDialog(playerid, dialogid, response, listitem)
{ 
	new Float:pcX, Float:pcY, Float:pcZ;
	GetPlayerPos(playerid, pcX, pcY, pcZ);
	if(dialogid == 2200)
	{ 
		new vid = GetPlayerVehicleID(playerid);
		if(response)
		{ 
			if(listitem == 0)
			{ 
				for(new i = 0; i < 10; i++)
				{
					if(vid == mitsubishibus[i])
					{
						Blitzer[i][3] = 70;
						Blitzer[i][4] = 1;
						SendClientMessage(playerid, COLOR_COP, "*** Blitzer aufgestellt ***");
						SetPlayerCameraPos(playerid, pcX, pcY, pcZ + 100);
						SetPlayerCameraLookAt(playerid, pcX, pcY, pcZ);
						SetVehicleParamsEx(GetPlayerVehicleID(playerid), 0, 0, 0, 1, 0, 0, 0);
					}
				}
			}
			else if(listitem == 1)
			{ 
				for(new i = 0; i < 10; i++)
				{
					if(vid == mitsubishibus[i])
					{
						Blitzer[i][3] = 100;
						Blitzer[i][4] = 2;
						SendClientMessage(playerid, COLOR_COP, "*** Blitzer aufgestellt ***");
						SetPlayerCameraPos(playerid, pcX, pcY, pcZ + 100);
						SetPlayerCameraLookAt(playerid, pcX, pcY, pcZ);
						SetVehicleParamsEx(GetPlayerVehicleID(playerid), 0, 0, 0, 1, 0, 0, 0);
					}
				}
			}
		}
		else
		{
			BlitzerStatus[playerid] = false;
			TogglePlayerControllable(playerid, 1);
			SetCameraBehindPlayer(playerid);
			SendClientMessage(playerid, COLOR_COP, "*** Aktion abgebrochen ***");
			SetVehicleParamsEx(GetPlayerVehicleID(playerid), 0, 0, 0, 0, 0, 0, 0);
		}
	}
}

public SetBlitzer(playerid, blitzerid, Float:bX, Float:bY, Float:bZ)
{
	ShowPlayerDialog(playerid, 2200, DIALOG_STYLE_LIST, "Blitzer", "Innerorts\nAußerorts", "Auswahl", "Beenden");
	BlitzerStatus[playerid] = true;
	TogglePlayerControllable(playerid, 0);
	return 1;
}