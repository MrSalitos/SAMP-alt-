new MySQL:g_sql;
#include <open.mp>
#include <a_mysql>
#include <streamer>
#include <define_color>
#include <user>
// #include <haus>
#include <haus_freiewirtschaft>
#include <haus_autohaus>
#include <job>
#include <fraktion>
#include <user_hilfe>
#include <user_navi>


new timer1[MAX_PLAYERS],timer3[MAX_PLAYERS];

#define	SQL_HOSTNAME	"127.0.0.1";
#define	SQL_USERNAME	"";
#define	SQL_PASSWORD	"";
#define	SQL_DATABASE	"gtaserver3366"


main()
{
	print("\n----------------------------------");
	print(" Mein Server Version: 1 alpha 0.1");
	print("----------------------------------\n");
}

public OnGameModeInit()
{
  SetGameModeText("German Roleplay Server");
  ShowPlayerMarkers(PLAYER_MARKERS_MODE:1);
  LimitGlobalChatRadius(10.0);
  ManualVehicleEngineAndLights();
  ShowNameTags(true);
  SetNameTagDrawDistance(50.0);
  UsePlayerPedAnims();
  EnableStuntBonusForAll(false);
  AllowInteriorWeapons(false);
  DisableInteriorEnterExits();
  
  connectdb();
  if(load_cars())
  {
	erstellehaeuser();
	erstelleberufe();
	erstellefraktionen();
	mysql_query("UPDATE `user_list` SET online=0 WHERE online = 1");
  }
  
  return 1;
}

public OnGameModeExit()
{
	// Close mysql connection.
    mysql_close(g_sql);
    return 1;
}

stock connectdb()
{

	g_sql = mysql_connect(SQL_HOSTNAME, SQL_USERNAME, SQL_PASSWORD, SQL_DATABASE); // AUTO_RECONNECT is enabled for this connection handle only
	if (g_SQL == MYSQL_INVALID_HANDLE || mysql_errno(g_SQL) != 0)
	{
		print("MySQL connection failed. Server is shutting down.");
		SendRconCommand("exit"); // close the server if there is no connection
		return 1;
	}

	print("MySQL connection is successful.");

  return 1;
}

public OnPlayerConnect(playerid)
{
  new data[256], query[128], pname[MAX_PLAYER_NAME];
  TogglePlayerSpectating(playerid, 1);
  //Noch Spam schutz
  //DoppelIP check mit doppelip erlaubnis
  GetPlayerName(playerid, pname, MAX_PLAYER_NAME);
  mysql_real_escape_string(pname,pname);
  format(query, sizeof(query), "SELECT online,COUNT(*) as anz FROM `accounts` WHERE `accname`='%s'", pname);
  mysql_query(query);
  mysql_store_result(MySQL:g_sql)();
  mysql_fetch_row(data);
  mysql_fetch_field("anz",data);
  if(strval(data) > 0)
  {
	mysql_fetch_field("online",data);
	if(strval(data) == 1)
	  Kick(playerid);
	else if(strval(data) == 0)
	  ShowPlayerDialog(playerid, 3,DIALOG_STYLE_PASSWORD , "Willkommen:", "Auf unserem deutschen Roleplay Server.Dein Account ist bereits registriert.\n Gebe dein Passwort ein:", "Bestätigen", "Abbrechen");
  }
  else
    ShowPlayerDialog(playerid, 1,DIALOG_STYLE_MSGBOX , "Willkommen:", "Auf unserem deutschen Roleplay Server.\nDein Account ist nicht registriert, um einen Account anzulegen klicke auf Registrieren.", "Registrieren", "Abbrechen");
  ;
  SetPlayerColor(playerid,COLOR_WHITE);
  return 1;
}

public OnPlayerText(playerid, text[])
{
  if(anrufender[playerid] >= 0)
  {
	new string[150] = "{A8A8A8}(Handy) ";
	strcat(string,text);
	SendPlayerMessageToPlayer(anrufender[playerid], playerid, string);
  }
  return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
  if(!strcmp(cmdtext, "/pos", true))
  {
    new Float:x, Float:y, Float:z, Float:r, data[144];
    GetPlayerPos(playerid, x, y, z);
	GetPlayerFacingAngle(playerid, r);
    format(data,sizeof data,"SERVER: Deine Position ist xyz: %.2f, %.2f, %.2f, %.2f",x,y,z, r);
    SendClientMessage(playerid, COLOR_WHITE, data);
    print(data);
  }
  else if(!strcmp(strget(cmdtext, 0), "/navi"))
  {
	navi(playerid,strget(cmdtext, 1));
  }
  else if(!strcmp(strget(cmdtext, 0), "/hilfe"))
  {
	hilfe(playerid,strget(cmdtext, 1));
  }
  else if(!strcmp(cmdtext,"/bike",true) && playerdata[playerid][33] >= 2)
  {
	new Float:x, Float:y, Float:z;
	GetPlayerPos(playerid, x, y, z);
	CreateVehicleEx(522, x+1.0, y+1.0, z, 0, 0, 0, 600);
  }
  else if(!strcmp(strget(cmdtext, 0), "/fan") && playerdata[playerid][2] == 3)
  {
	fahrschule_annahmestunde(playerid,strval(strget(cmdtext, 1)));
  }
  else if(!strcmp(strget(cmdtext, 0), "/f") && playerdata[playerid][2] == 3 && fahrschueler[playerid] >= 0)
  {
	SendPlayerMessageToPlayer(fahrschueler[playerid], playerid,strget(cmdtext, 1));
  }
  else if(!strcmp(cmdtext,"/cartrack",true) && PLAYER_IS_COP)
  {
	CarTrack(playerid);
  }
  else if(!strcmp(strget(cmdtext, 0),"/dienst",true))																// Dienst beginnen/beenden
  {
		if(CopOnDuty[playerid] == false && playerdata[playerid][2] == 4)
		{ 
			CopOnDuty[playerid] = true;
			SendClientMessage(playerid, COLOR_COP, "*** Sie sind jetzt im Dienst. ***");
			CheckPlayerWantedLevel(playerid);
			if(!strcmp(strget(cmdtext, 1), "zivil", true))
				SetPlayerSkin(playerid, playerdata[playerid][1]);
			else
				SetPlayerSkin(playerid,280);
			
		}
		else if(CopOnDuty[playerid] == true && playerdata[playerid][2] == 4)
		{ 
			CopOnDuty[playerid] = false;
			SetPlayerSkin(playerid, playerdata[playerid][1]);
			SendClientMessage(playerid, COLOR_COP, "*** Sie sind jetzt nicht mehr im Dienst. ***");
			for(new i = 0; i < MAX_PLAYERS ; i++)
			{
				SetPlayerMarkerForPlayer(playerid, i, COLOR_INVISIBLE);
			}
		}
  }
  else if(!strcmp(strget(cmdtext, 0), "/wanted") && CopOnDuty[playerid] == true && playerdata[playerid][2] == 4)													// Fahndungslevel setzen
  { 
		new Float:pX, Float:pY, Float:pZ;
		GetPlayerPos(strval(strget(cmdtext, 1)), pX, pY, pZ);
		printf("%.2f, %.2f, %.2f", pX, pY, pZ);
		if(IsPlayerInRangeOfPoint(playerid, 100, pX, pY, pZ))
		{ 
			new output[128];
			SetPlayerWantedLevel(strval(strget(cmdtext, 1)), strval(strget(cmdtext, 2)));
			playerdata[strval(strget(cmdtext, 1))][35] = strval(strget(cmdtext, 2));
			format(output, sizeof(output), "*** Aktueller Fahndungslevel: %i ***", playerdata[strval(strget(cmdtext, 1))][35]);
			SendClientMessage(strval(strget(cmdtext, 1)),COLOR_COP, output);		
		}
		else 
			SendClientMessage(playerid, COLOR_COP, "*** Sie sind nicht in Reichweite ***");
  }
  else if(!strcmp(strget(cmdtext, 0), "/schock") && CopOnDuty[playerid] == true && playerdata[playerid][2] == 4)													// Macht das Ziel für 7 Sekunden bewegungsunfähig
  {
		new Float:pX, Float:pY, Float:pZ;
		GetPlayerPos(strval(strget(cmdtext, 1)), pX, pY, pZ);
		if(IsPlayerInRangeOfPoint(playerid, 15, pX, pY, pZ))
		{
			ApplyAnimation(strval(strget(cmdtext, 1)),"PED","WALK_DRUNK",4.1,0,1,1,0,7000,1);
		}
  }
  else if(!strcmp(strget(cmdtext, 0), "/ergeben"))			// Nimmt die Hände hoch
  {
		new bool:handsup = false;
		if(handsup == false)
		{
			SetPlayerSpecialAction(strval(strget(cmdtext, 1)), SPECIAL_ACTION_HANDSUP);
			handsup = true;
		}
		else if(handsup == true)
		{
			SetPlayerSpecialAction(strval(strget(cmdtext, 1)), SPECIAL_ACTION_NONE);
			handsup = false;
		}
  }
  else if(!strcmp(strget(cmdtext, 0), "/handschellen") && CopOnDuty[playerid] == true && playerdata[playerid][2] == 4)	// Legt dem Ziel Handschellen an
  {
		new Float:pX, Float:pY, Float:pZ;
		GetPlayerPos(strval(strget(cmdtext, 1)), pX, pY, pZ);
		if(IsPlayerInRangeOfPoint(playerid, 10, pX, pY, pZ))
		{
			SetPlayerSpecialAction(strval(strget(cmdtext, 1)), SPECIAL_ACTION_CUFFED);
		}
  }
  else if(!strcmp(cmdtext, "/blitzer", true) && CopOnDuty[playerid] == true && playerdata[playerid][2] == 4)	// Aktiviert den Blitzer
  {
		new vid = GetPlayerVehicleID(playerid);
		new output[128];
		if(BlitzerStatus[playerid] == false && vid !=0)
		{
			for(new i = 0; i < 9; i++)
			{
				if(vid == mitsubishibus[i])
				{
						GetVehiclePos(GetPlayerVehicleID(playerid), Blitzer[i][0],  Blitzer[i][1],  Blitzer[i][2]);
						SetBlitzer(playerid, i, Blitzer[i][0], Blitzer[i][1], Blitzer[i][2]);
						format(output, sizeof(output), "Position X: %.2f, Y: %.2f, Z %.2f", Blitzer[i][0], Blitzer[i][1], Blitzer[i][2]);
						SendClientMessage(playerid, COLOR_COP, output);
				}
			}
		}
		else if(BlitzerStatus[playerid] == true && vid !=0)
		{
			for(new i = 0; i < 9; i++)
			{
				if(vid == mitsubishibus[i])
				{
					Blitzer[i][0] = 0.0;
					Blitzer[i][1] = 0.0;
					Blitzer[i][2] = -100.0;
				}
			}
			BlitzerStatus[playerid] = false;
			TogglePlayerControllable(playerid, 1);
			SetCameraBehindPlayer(playerid);
			SendClientMessage(playerid, COLOR_COP, "*** Blitzer abgebaut ***");
			SetVehicleParamsEx(GetPlayerVehicleID(playerid), 0, 0, 0, 0, 0, 0, 0);
		}
		return 1;
  }
  else if(!strcmp(strget(cmdtext, 0), "/verhaften") && CopOnDuty[playerid] == true && playerdata[playerid][2] == 4)	// Bringt den Verdächtigen ins Gefängnis	{
  {
		new Float:pX, Float:pY, Float:pZ;
		GetPlayerPos(strval(strget(cmdtext, 1)), pX, pY, pZ);
		if(IsPlayerInRangeOfPoint(playerid, 25, pX, pY, pZ))
		{	
			if(playerdata[strval(strget(cmdtext, 1))][35] > 0)
			{
				PlayerInPrison(strval(strget(cmdtext, 1)));
			}
		}
  }
  else
	SendClientMessage(playerid, COLOR_GREY, "Unbekannter Befehl!");
  return 1;
}

public OnPlayerSpawn(playerid)
{
  SetPlayerSkin(playerid, playerdata[playerid][1]);
  SetCameraBehindPlayer(playerid);
  ResetPlayerWeapons(playerid);
  RemovePlayerAttachedObject(playerid,1);
  GivePlayerWeapon(playerid,playerdata[playerid][11],playerdata[playerid][12]);
  GivePlayerWeapon(playerid,playerdata[playerid][13],playerdata[playerid][14]);
  GivePlayerWeapon(playerid,playerdata[playerid][15],playerdata[playerid][16]);
  SetPlayerArmedWeapon(playerid,0);
  SetPlayerWantedLevel(playerid, playerdata[playerid][35]);
  TextDrawShowForPlayer(playerid,zeitanzeigen);
  TextDrawShowForPlayer(playerid,paydaydraw1[playerid]);
  TextDrawShowForPlayer(playerid,paydaydraw2[playerid]);
  TextDrawShowForPlayer(playerid,zahltag);
  TextDrawShowForPlayer(playerid,userlevel);
  TextDrawShowForPlayer(playerid,userleveldraw1[playerid]);
  TextDrawShowForPlayer(playerid,userleveldraw2[playerid]);
  TextDrawShowForPlayer(playerid,berufserf);
  TextDrawShowForPlayer(playerid,berufserf1[playerid]);
  TextDrawShowForPlayer(playerid,berufserf2[playerid]);
  if(playerinhouse[playerid] >= 0)
  {
	new inter = -1;
	if(playerinhouse[playerid] == playerdata[playerid][58]) inter = playerdata[playerid][59];
    else if(playerinhouse[playerid] == playerdata[playerid][60]) inter = playerdata[playerid][61];
    else if(playerinhouse[playerid] == playerdata[playerid][62]) inter = playerdata[playerid][63];
    else if(playerinhouse[playerid] == playerdata[playerid][64]) inter = playerdata[playerid][65];
    else if(playerinhouse[playerid] == playerdata[playerid][66]) inter = playerdata[playerid][67];
	
	if(inter >= 0)
	{
	  wohnungsintor[inter][1] = wohnungsintor[inter][1] + 1.0;
	  SetPlayerVirtualWorld(playerid,floatround(wohnungsintor[inter][1]));
	}
  }
  if(waehlekleidung[playerid] == 1)
  {
	freiw_skinchange(playerid);
  }
  return 1;
}

public OnPlayerDeath(playerid,killerid,WEAPON:reason)
{
  if(waehlekleidung[playerid] != 1)
  {
	playerdata[playerid][17] = 100;
	playerdata[playerid][18] = playerdata[playerid][18] + 1;
	hidetacho(playerid);
	if(killerid != INVALID_PLAYER_ID)
	{
	  if(playerdata[killerid][35] < 5)
		playerdata[killerid][35] = playerdata[killerid][35] + 2;
	  else
		playerdata[killerid][35] = 6;
	  SetPlayerWantedLevel(killerid, playerdata[killerid][35]);
	  playerdata[killerid][71]++;
	}
	SetTimerEx("wait_kh",3000,false,"i",playerid);
	if(playerdata[playerid][2] == 3) fahrschule_lehrerdisconnect(playerid);
	if(fahrstunde[playerid] > 0) fahrschule_stundenendeschueler(playerid);
	if(pilots[playerid] > 0) abbruch_pilot(playerid);
	SetPlayerInterior(playerid, 0);
	SetPlayerVirtualWorld(playerid, 0);
	if(limof[playerid] > 0) abbruchlimo(playerid);
	if(taxidriver[playerid] > 0) abbruch_taxi(playerid,0);
	if(taxiguest[playerid] > 0) finddriverbyexit(playerid);
  }
  TextDrawHideForPlayer(playerid,paydaydraw1[playerid]);
  TextDrawHideForPlayer(playerid,paydaydraw2[playerid]);
  TextDrawHideForPlayer(playerid,zahltag);
  TextDrawHideForPlayer(playerid,userlevel);
  TextDrawHideForPlayer(playerid,userleveldraw1[playerid]);
  TextDrawHideForPlayer(playerid,userleveldraw2[playerid]);
  TextDrawHideForPlayer(playerid,berufserf);
  TextDrawHideForPlayer(playerid,berufserf1[playerid]);
  TextDrawHideForPlayer(playerid,berufserf2[playerid]);
  return 1;
}

public OnDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
  /*
   * ALLGEMEINE DIALOGE ------ ID(0) kein Ergebnis
   */
  //   Registrierung und Login ID(1, 2, 3, 4, 97,1011-1020)
  login_response(playerid, dialogid, response, listitem, inputtext);
  //   Navigation ID(50-59)
  navi_response(playerid, dialogid, response, listitem, inputtext);
  //   Hilfe ID(40-49)
  hilfe_response(playerid, dialogid, response, listitem, inputtext);
  //   ATM ID(70-75)
  bank_response(playerid, dialogid, response, listitem, inputtext);
  //   Mietwagen ID(2300 - 2399)
  MietwagenDialogResponse(playerid, dialogid, response, listitem, inputtext);
  
  /*
   * GEBÄUDE DIALOGE ---------
   */
  //   Postgebäude ID(100)
  post_response(playerid, dialogid, response, listitem, inputtext);
  //   Berufsschule ID(60-69)
  berufs_response(playerid, dialogid, response, listitem, inputtext);
  //   Freie Wirtschaft ID(1001-1010)
  freiew_response(playerid, dialogid, response, listitem, inputtext);
  //    Rathaus ID 9
  rathaus_response(playerid, dialogid, response, listitem, inputtext);
  //    Autohaus ID(76-94)
  auto_response(playerid, dialogid, response, listitem, inputtext);
  //    Userhaus ID(95-96)
  userhaus_response(playerid, dialogid, response, listitem, inputtext);
  
  /*
   * JOB DIALOGE -------------
   */
  //   Postbote ID(10)
  pbote_response(playerid, dialogid, response, listitem, inputtext);
  //   Pilot ID(11)
  pilot_response(playerid, dialogid, response, listitem, inputtext);
  //   Fahrlehrer(12 - 26)
  fahrschule_response(playerid, dialogid, response, listitem, inputtext);
  //   Fahrradkurier ID(1000)
  fkurier_response(playerid, dialogid, response, listitem, inputtext);
  //   Trucker-Dialoge ID()
  TruckerDialoge(playerid, dialogid, response, listitem);
  //   Polizei-Dialoge ID()
  CarTrackDialog(playerid, dialogid, response, listitem);
  //   Blitzer
  BlitzerDialog(playerid, dialogid, response, listitem);
  //Limofahrer ID (101)
  limodialogr(playerid, dialogid, response, listitem);
  //Taxifahrer ID (102-105)
  taxidialogr(playerid, dialogid, response, listitem,inputtext);
  return 1;
}

public OnPlayerRequestClass(playerid,classid)
{
  if(waehlekleidung[playerid] == 1)
  {
	freiew_waehleskin(playerid,classid);
  }
  return 0;
}

public OnPlayerRequestSpawn(playerid)
{
  if(waehlekleidung[playerid] == 1)
  {
	return 1;
  }
  return 0;
}

public OnVehicleDeath(vehicleid)
{
  Fahrzeuge[vehicleid][1] = 1000.0;
  if(Fahrzeuge[vehicleid][3] != 0)
  {
	new query[500];
	format(query,500,"UPDATE `user_vehicles` SET health=%.2f,destroy=1 WHERE vid=%i",Fahrzeuge[vehicleid][1],vehicleid);
	mysql_query(query);
	DestroyVehicle(vehicleid);
  }
  return 1;
}

public OnPlayerPickUpPickup(playerid, pickupid)
{
  /*
   *  ALLGEMEINE PICKUPS
   */
  
  /*
   *  GEBÄUDE PICKUPS
   */
  //     Rathaus
  rath_pickups(playerid,pickupid);
  //    POST
  post_pickups(playerid,pickupid);
  //    Freie Wirtschaft
  freiew_pickups(playerid,pickupid);
  //    Tankstellen
  ts_pickups(playerid, pickupid);
  //    Berufschule
  berufs_pickup(playerid,pickupid);
  //    Autohaus
  auto_pickup(playerid,pickupid);
  //    User Häuser
  userhaus_pickup(playerid,pickupid);
  
  /*
   *  JOB PICKUPS
   */
  //     Pilot
  pilot_pickups(playerid,pickupid);
  fahrschule_pickups(playerid,pickupid);
  
  return 1;
}

public OnPlayerEnterCheckpoint(playerid)
{
	if(fkur[playerid] > 0)
	{
	    fk_route(playerid);
 	}
 	else if(fkurm[playerid] > 0)
	{
	    fk_route_mittel(playerid);
 	}
 	else if(fkurl[playerid] > 0)
	{
	    fk_route_lang(playerid);
 	}
	else if(navivar[playerid] == 1)
	{
		DisablePlayerCheckpoint(playerid);
	    navivar[playerid] = 0;
	    SendClientMessage(playerid,COLOR_YELLOW,"Sie haben ihr Ziel erreicht.");
	}
	else if(pbote[playerid] > 0)
	{
	    pbroute(playerid);
 	}
 	else if (CarTrackActive)
	{
		DisablePlayerCheckpoint(playerid);
		SendClientMessage(playerid, COLOR_COP, "*** Fahrzeug gefunden. Tracking beendet. ***");
		CarTrackActive = false;
	}
	else if(pilots[playerid] > 0)
	{
	  DisablePlayerCheckpoint(playerid);
	  pilotstart(playerid);
	}
	else if(fahrstunde[playerid] == 27 || fahrstunde[playerid] == 28)
	{
	  DisablePlayerCheckpoint(playerid);
	  fahrschule_startlandeabwarten(playerid);
	}
	else if(PRODCAR_LS || PRODCAR_SF || PRODCAR_LV)
	{
		ProdfahrerCheckpoints(playerid);
	}
	else if(ts_mission_id[playerid] > 0)
	{
		StartTSMission(playerid);
	}
	else if(fahrstunde[playerid] == 20)
	{
	  DisablePlayerCheckpoint(playerid);
	  rollerf(playerid);
	}
	else if(limof[playerid] > 0) limo(playerid);
	else if(taxidriver[playerid] > 0 && taxistats[playerid][2] >= 0) taxiguestbeenden(taxistats[playerid][2],1,playerid);
	else if(taxidriver[playerid] > 0) abbruch_taxi(playerid,1);
 	return 1;
}

public OnPlayerEnterRaceCheckpoint(playerid)
{
  DisablePlayerRaceCheckpoint(playerid);
  if(pilots[playerid] > 0)
  {
	pilotstart(playerid);
  }
  else if(fahrstunde[playerid] == 27 || fahrstunde[playerid] == 28)
  {
	fahrschule_startlandeabwarten(playerid);
  }
  else if(fahrstunde[playerid] == 20)
  {
	rollerf(playerid);
  }
  return 1;
}

public OnPlayerClickMap(playerid, Float:fX, Float:fY, Float:fZ)
{
  if(taxiguest[playerid] > 0)
  {
	taxigivedrivercheckpoint(playerid,fX,fY,fZ);
  }
  else if(playerdata[playerid][33] >= 2 && GetPlayerInterior(playerid) == 0)
	SetPlayerPosFindZ(playerid, fX, fY, fZ);
  return 1;
}

public OnPlayerExitedMenu(playerid)
{
  TogglePlayerControllable(playerid,1);
  return 1;
}

public OnPlayerSelectedMenuRow(playerid, row)
{
    if(GetPlayerMenu(playerid) == einwamtmenu)
    {
        switch(row)
        {
            case 0: perso(playerid);
            case 1: gewerbe(playerid);
        }
    }
    else if(GetPlayerMenu(playerid) == aamtmenu)
    {
        switch(row)
        {
            case 0:{HideMenuForPlayer(aamtmenu,playerid);jobmenu(playerid);}
            case 1:{HideMenuForPlayer(aamtmenu,playerid);ShowMenuForPlayer(njobmenu,playerid);}
            case 2: deljob(playerid);
        }
    }
    else if(GetPlayerMenu(playerid) == njobmenu)
    {
    	switch(row)
     	{
     		case 0: {navi(playerid,"fkurier");TogglePlayerControllable(playerid,1);}
   			case 1: {HideMenuForPlayer(njobmenu,playerid);ShowMenuForPlayer(aamtmenu,playerid);}
   		}
    }
  	else if(GetPlayerMenu(playerid) == postmenu)
    {
		sendpost(playerid,row);
  	}
	return 1;
}

stock strget(strx[], pos, search = ' ')
{
  new arg, ret[128], idxx;
  for (new i = 0; i < strlen(strx); i++)
  {
    if(strx[i] == search || i == strlen(strx) || strx[i + 1] == 10)
	{
      arg++;
      if (arg == pos + 1)
	  {
    	ret[i-idxx] = EOS;
    	return ret;
      }
	  else if (arg == pos)
    	idxx= i+1;
    }
    else if (arg == pos)
      ret[i - idxx] = strx[i];
  }
  return ret;
}

public OnPlayerDisconnect(playerid, reason)
{
  if(fkur[playerid] > 0 || fkurm[playerid] > 0 || fkurl[playerid] > 0) abbruch_kurier(playerid); 	// Abbruch FKurier
  if(pilots[playerid] > 0) abbruch_pilot(playerid); 												// Abbruch Pilot
  if(pbote[playerid] > 0) abbruch_pbote(playerid,-1); 												// Abbruch Postbote
  if(MissionActive[playerid] > 0) CancelTsMission(playerid); 											// Abbruch Trucker
  if(playerdata[playerid][2] == 3) fahrschule_lehrerdisconnect(playerid);							// Abbruch Fahrlehrer
  if(fahrstunde[playerid] > 0) fahrschule_stundenendeschueler(playerid);							// Abbruch Fahrschule
  if(limof[playerid] > 0) abbruchlimo(playerid);
  if(taxiguest[playerid] > 0) finddriverbyexit(playerid);
  if(taxidriver[playerid] > 0) abbruch_taxi(playerid,0);
  KillTimer(paydaytimer[playerid]); 	// Payday stoppen
  KillTimer(toroeffner[playerid]); 		// Türtimer stoppen
  dologout(playerid); 					// Alle Daten in DB schreiben
  if(playerinhouse[playerid] >= 0)
  {
	new inter = -1;
	if(playerinhouse[playerid] == playerdata[playerid][58]) inter = playerdata[playerid][59];
    else if(playerinhouse[playerid] == playerdata[playerid][60]) inter = playerdata[playerid][61];
    else if(playerinhouse[playerid] == playerdata[playerid][62]) inter = playerdata[playerid][63];
    else if(playerinhouse[playerid] == playerdata[playerid][64]) inter = playerdata[playerid][65];
    else if(playerinhouse[playerid] == playerdata[playerid][66]) inter = playerdata[playerid][67];
	
	if(inter >= 0) wohnungsintor[inter][1] = wohnungsintor[inter][1] - 1.0;
  }
  if(GetPlayerVehicleID(playerid))
  {
	new vehicleid = GetPlayerVehicleID(playerid);
	if(Fahrzeuge[vehicleid][3] == playerdata[playerid][0])
	{
	  new query[500],Float:posX,Float:posY,Float:posZ,Float:face;
	  GetVehiclePos(vehicleid, posX, posY, posZ);
	  GetVehicleZAngle(vehicleid, face);
	  format(query,500,"UPDATE `user_vehicles` SET posX=%.2f, posY=%.2f, posZ=%.2f,face=%.2f,km=%i,tank=%.2f,health=%.2f WHERE vid=%i",posX,posY,posZ,face,floatround(Fahrzeuge[vehicleid][4]),Fahrzeuge[vehicleid][0],Fahrzeuge[vehicleid][1],vehicleid);
	  mysql_query(query);
	}
  }
}

public OnPlayerTakeDamage(playerid, issuerid, Float:amount, WEAPON:weaponid)
{
  playerdata[playerid][17] = floatround(playerdata[playerid][17]-amount); // Gesundheit des Spielers updaten
}

public OnPlayerStateChange(playerid, PLAYER_STATE:newstate, PLAYER_STATE:oldstate)
{
  if(newstate == PLAYER_STATE_ONFOOT) //Spieler ist aus dem Auto gestiegen
  {
    hidetacho(playerid);
	if(fkur[playerid] > 0 || fkurm[playerid] > 0 || fkurl[playerid] > 0) timer1[playerid] = SetTimerEx("abbruch_kurier", 30000, false, "i", playerid);
	if(taxidriver[playerid] > 0) taxitimer[playerid] = SetTimerEx("abbruch_taxi",45000,false,"iI",playerid,0);
	if(taxiguest[playerid] > 0) finddriverbyexit(playerid);
  }
  
  //---------- Adminfahrzeuge ----------------
  admin_statechange(playerid, newstate, oldstate);
  //---------- POSTBOTE ----------------------
  pbote_statechange(playerid, newstate, oldstate);
  //---------- Fahrlehrer --------------------
  fahrschule_statechange(playerid, newstate, oldstate);
  //---------- Autohaus ----------------------
  auto_statechange(playerid, newstate, oldstate);
  
  if(newstate == PLAYER_STATE_PASSENGER)
  {
	//----------TaxiGast-------------------
	if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 420)
	{
	  taxistartefahrt(playerid);
	}
  }
  if(newstate == PLAYER_STATE_DRIVER)		// Spieler steigt als Fahrer in ein Fahrzeug
  {
	//Zeige Tacho für alle Fahrzeuge ausser Fahrräder
	if(GetVehicleModel(GetPlayerVehicleID(playerid)) != 509 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 510 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 481)
	{
      if(showtacho(playerid))
	  {
		//---------- Pilot
		if(GetPlayerVehicleID(playerid) == sftankid1 || GetPlayerVehicleID(playerid) == sftankid2 || GetPlayerVehicleID(playerid) == sftankid3)
		{
		  AttachTrailerToVehicle((GetPlayerVehicleID(playerid)+1), GetPlayerVehicleID(playerid));
		}
		//---------- MIETWAGEN ----------------
		for(new i = 0; i < sizeof(mietwagen); i++)
		{
		  if(GetPlayerVehicleID(playerid) == mietwagen[i][0])
		  {
			if(mietwagen[i][8] == 0)
			{
			  MietwagenDialog(playerid);
			}
			else if(mietwagen[i][8] == playerid)
			{
			  new output[128];
			  format(output, sizeof(output), "*** Die Restliche Mietdauer beträgt %i Minuten ***", floatround(mietwagen[i][10]));
			  SendClientMessage(playerid, COLOR_YELLOW, output);
			}
		  }
		}
		//---------- TRUCKER ----------------
		if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 403 || GetVehicleModel(GetPlayerVehicleID(playerid)) == 514)
		{
		  format(tls,50,"Ladung: ~p~%i", TrailerLoad[playerid]);
		  TextDrawSetString(KM[playerid],tls);
		  TextDrawShowForPlayer(playerid,KM[playerid]);
		  KillTimer(timer3[playerid]);
		  if(playerdata[playerid][2] == 1)
			  TruckerStartWork(playerid);
		  else
		  {
			  RemovePlayerFromVehicle(playerid);
			  new string[30];
			  format(string, sizeof(string), "~w~Du bist kein~n~~y~Trucker");
			  GameTextForPlayer(playerid, string, 3000, 1);
			  SendClientMessage(playerid, COLOR_TRUCKER, "*** Nur Trucker dürfen dieses Fahrzeug benutzen ***");
		  }
		}
		//----------Limofahrer-------------------
		else if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 409)
		{
		  limodialog(playerid);
		}
		//----------Taxifahrer-------------------
		else if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 420)
		{
		  if(playerdata[playerid][2] == 7)
		  {
			taxidialog(playerid);
			KillTimer(taxitimer[playerid]);
		  }
		  else
		  {
			RemovePlayerFromVehicle(playerid);
			new string[40];
			format(string, sizeof(string), "~w~Du bist kein~n~~y~Taxifahrer");
			GameTextForPlayer(playerid, string, 3000, 1);
			SendClientMessage(playerid, COLOR_TRUCKER, "*** Nur Taxifahrer dürfen dieses Fahrzeug benutzen ***");
		  }
		}
		//---------- POLIZIST ----------------
		if(PLAYERCAR_IS_COP)
		{
				if(PLAYER_IS_COP)
				{
				  SendClientMessage(playerid, COLOR_COP, "*** Willkommen zum Streifendienst ***");
				}
				else
				{
					RemovePlayerFromVehicle(playerid);
					new string[30];
					format(string, sizeof(string), "~w~Du bist kein~n~~y~Polizist");
					GameTextForPlayer(playerid, string, 3000, 1);
					SendClientMessage(playerid, COLOR_COP, "*** Nur Polizeibeamte dürfen dieses Fahrzeug benutzen ***");
				}
		}
		if(PRODCAR_LS)
		{
		  if(playerdata[playerid][2] == 6)
		  {
			GetProdMission(playerid, "LS");
		  }
		  else
		  {
			RemovePlayerFromVehicle(playerid);
			new string[32];
			format(string, sizeof(string), "~w~Du bist kein~n~~y~Lieferant");
			GameTextForPlayer(playerid, string, 3000, 1);
			SendClientMessage(playerid, COLOR_TRUCKER, "*** Nur Lieferanten dürfen dieses Fahrzeug benutzen ***");
		  }
		}
		if(PRODCAR_SF)
		{
		  if(playerdata[playerid][2] == 6)
		  {
			GetProdMission(playerid, "SF");
		  }
		  else
		  {
			RemovePlayerFromVehicle(playerid);
			new string[32];
			format(string, sizeof(string), "~w~Du bist kein~n~~y~Lieferant");
			GameTextForPlayer(playerid, string, 3000, 1);
			SendClientMessage(playerid, COLOR_TRUCKER, "*** Nur Lieferanten dürfen dieses Fahrzeug benutzen ***");
		  }
		}
		if(PRODCAR_LV)
		{
		if(playerdata[playerid][2] == 6)
		{
		  GetProdMission(playerid, "LV");
		}
		else
		{
		  RemovePlayerFromVehicle(playerid);
		  new string[32];
		  format(string, sizeof(string), "~w~Du bist kein~n~~y~Lieferant");
		  GameTextForPlayer(playerid, string, 3000, 1);
		  SendClientMessage(playerid, COLOR_TRUCKER, "*** Nur Lieferanten dürfen dieses Fahrzeug benutzen ***");
		}
		}
	  }
	}
	//----------FKURIER-------------------
	else if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 509)
	{
	  if(fkur[playerid] == 0 && fkurm[playerid] == 0 && fkurl[playerid] == 0) fk(playerid);
	  KillTimer(timer1[playerid]);
	}
  }
  return 1;
}

public OnPlayerKeyStateChange(playerid, KEY:newkeys, KEY:oldkeys)
{
  if(GetPlayerVehicleID(playerid) != 0 && GetPlayerVehicleSeat(playerid) == 0 && showtacho(playerid))
  {
    if (newkeys & KEY_YES && GetVehicleModel(GetPlayerVehicleID(playerid)) != 509 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 510 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 481)
    {
	  new engine, lights, alarm, doors, bonnet, boot, objective;
	  GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, doors, bonnet, boot, objective);
	  if(engine == 1)
		SetVehicleParamsEx(GetPlayerVehicleID(playerid),0,lights, alarm, doors, bonnet, boot, objective);
	  else
		SetVehicleParamsEx(GetPlayerVehicleID(playerid),1,lights, alarm, doors, bonnet, boot, objective);
    }
  }
  if(GetPlayerVehicleID(playerid) == 0 && newkeys & KEY_YES)
  {
	if(!bank_activate(playerid))
	{
	  //nächste möglichkeit!
	}
  }
  
  if(newkeys & KEY_NO)
  {
	actionmenu(playerid);
  }
  if(newkeys & KEY_SUBMISSION)
  {
	jobaction(playerid);
  }
  
  return 1;
}

public OnPlayerUpdate(playerid)
{
  if(GetPlayerVehicleID(playerid) != 0 && GetPlayerVehicleSeat(playerid) == 0 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 509 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 510 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 481)
  {
    gesch(playerid);
  }
  return 1;
}

public OnPlayerExitVehicle(playerid, vehicleid)
{
  new mid = GetVehicleModel(vehicleid);
  if(playerdata[playerid][2] == 3 && (mid == 511 || mid == 553 || mid == 469 || mid == 548 || mid == 454 || mid == 446 || mid == 457))
  {
    new ok = 0;
    for(new i=0;i < 5;i++)
    {
      if(fahrlehrer_on[i] == playerid)
      {
        ok = 1;
      }
    }
    if(ok == 1)
    {
	  Fahrzeuge[vehicleid][0] = float(Fahrzeugdaten[GetVehicleModel(vehicleid)-400][0]);
	  Fahrzeuge[vehicleid][1] = 1000.0;
	}
  }
  if(Fahrzeuge[vehicleid][3] == playerdata[playerid][0])
  {
	new query[500],Float:posX,Float:posY,Float:posZ,Float:face,money;
	GetVehiclePos(vehicleid, posX, posY, posZ);
	GetVehicleZAngle(vehicleid, face);
	if(mid == 512 || mid == 593 || mid == 519 || mid == 513 || mid == 487 || mid == 473 || mid == 493 ||
	   mid == 595 || mid == 484 || mid == 452 || mid == 539 || mid == 460)
	{
	  //Volltanken von Booten und Flugzeugen beim Aussteigen!
	  money = floatround((float(Fahrzeugdaten[mid-400][0]) - Fahrzeuge[vehicleid][0])*1.31);
	  playerdata[playerid][4] = playerdata[playerid][4] - money; 
	  GivePlayerMoney(playerid,money);
	  GameTextForPlayer(playerid, "~w~Ihr Fahrzeug wurde betankt.", 3000, 1);
	  Fahrzeuge[vehicleid][0] = float(Fahrzeugdaten[mid-400][0]);
	}
	format(query,500,"UPDATE `user_vehicles` SET posX=%.2f, posY=%.2f, posZ=%.2f,face=%.2f,km=%i,tank=%.2f,health=%.2f WHERE vid=%i",posX,posY,posZ,face,floatround(Fahrzeuge[vehicleid][4]),Fahrzeuge[vehicleid][0],Fahrzeuge[vehicleid][1],vehicleid);
	mysql_query(query);
  }
  if(MissionActive[playerid] > 0)
  {
	for(new i = 0; i < sizeof(trucker_car[]); i++)
	{
	  if(vehicleid == trucker_car[1][i])
	  {
		new Float:vhealth;
		GameTextForPlayer(playerid, "~y~Die Mission wird in ~n~ 5 Minutenabgebrochen!",10, 1);
		timer3[playerid] = SetTimerEx("CancelTsMission", 300000, false, "i", playerid);
		GetVehicleHealth(GetVehicleTrailer(GetPlayerVehicleID(playerid)), Float:vhealth);
		if(vhealth == 0)
		{
		  CancelTsMission(playerid);
		  GameTextForPlayer(playerid, "~r~Mission felgeschlagen!~n~Ihr Fahrzeug wurde zerstört.", 3000, 3);
		}
	  }
	}
  }
}
