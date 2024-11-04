forward giveusermoney(playerid,money);
forward giveusermoneyonbank(playerid,money);
forward setuserjob(playerid,jobid);
forward setuserlizens(playerid,lizens,senderid);
forward textonenterbuilding(playerid,txt[]);
forward payday(playerid);
forward sendmessagetoallplayer(msg[],senderid,style,werbeid);
forward getweaponslot(weaponid);
forward dologin(playerid,inputtext[]);
forward dologout(playerid);
forward spawn_player(playerid,death,Float:posX,Float:posY,Float:posZ,Float:winkel);
forward wait_kh(playerid);
forward login_response(playerid, dialogid, response, listitem, inputtext[]);
forward actionmenu(playerid);
forward user_stats(playerid);
forward usertextdrawupdate(playerid);
forward skilllevelcheck(playerid,jobid);
forward jobaction(playerid);
forward handyauflegen(playerid,i,kind);

new Float:hospital_spawn[8][4] = {
	{ 1173.68, -1323.58, 15.19, 270.0 },
	{ 2030.63, -1410.82, 16.99, 135.0 },
	{ 1225.52, 309.34, 19.75, 135.0 },
	{ -2202.56, -2310.86, 30.62, 315.0 },
	{ -2658.40, 637.79, 14.45, 180.0 },
	{ -1513.90, 2525.07, 55.78, 0.0 },
	{ -322.72, 1054.99, 19.74, 0.0 },
	{ 1580.57, 1766.35, 10.82, 90.0 }
};
new Float:hospital_cam[8][6] = {
	{ 1174.0, -1324.0, 15.5, 1214.0, -1324.0, 25.5 },
	{ 2030.0, -1410.0, 17.0, 1998.0, -1450.0, 27.0 },
	{ 1225.0, 310.0, 20.0, 1210.0, 275.5, 29.5 },
	{ -2202.5, -2310.5, 30.5, -2188.0, -2316.5,  40.5 },
	{ -2658.5, 638.0, 14.5, -2666.0, 562.0, 24.5 },
	{ -1514.0, 2525.0, 56.0, -1515.0, 2558.5, 66.0 },
	{ -322.5, 1055.0, 20.0, -300.0, 1082.5, 30.0 },
	{ 1580.5, 1766.5, 11.0, 1545.5, 1768.5, 21.0 }
};
new Float:mietwagen[][11] = {
	/* *********************** */
	/*  0 => VehicleID (Server)*/
	/*  1 => ModelID           */
	/*  2 => Position X        */
	/*  3 => Position Y        */
	/*  4 => Position Z        */
	/*  5 => Ausrichtung       */
	/*  6 => Farbe 1           */
	/*  7 => Farbe 2           */
	/*  8 => Besitzer          */
	/*  9 => Preis pro Minute  */
	/* 10 => Mietdauer         */
	/* *********************** */
	{ 0.0, 405.0, 1805.00,-1932.00, 13.50,	 0.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//Los Santos Bahnhof
	{ 0.0, 405.0, 1801.00,-1932.00, 13.50,	 0.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//Los Santos Bahnhof
	{ 0.0, 405.0, 1797.00,-1932.00, 13.50,	 0.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//Los Santos Bahnhof
	{ 0.0, 405.0, 1793.00,-1932.00, 13.50,	 0.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//Los Santos Bahnhof
	{ 0.0, 405.0, 1789.00,-1932.00, 13.50, 	 0.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//Los Santos Bahnhof
	{ 0.0, 405.0, 1560.50,-2264.00, 13.50,  90.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//Los Santos Flughafen
	{ 0.0, 405.0, 1560.50,-2260.75, 13.50,  90.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//Los Santos Flughafen
	{ 0.0, 405.0, 1560.50,-2257.50, 13.50,  90.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//Los Santos Flughafen
	{ 0.0, 405.0, 1560.50,-2254.25, 13.50,  90.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//Los Santos Flughafen
	{ 0.0, 405.0, 1560.50,-2251.00, 13.50,  90.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//Los Santos Flughafen
	{ 0.0, 405.0,-1976.00,	105.00, 27.75,  90.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//San Fierro Bahnhof
	{ 0.0, 405.0,-1976.00,	101.00, 27.75,  90.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//San Fierro Bahnhof
	{ 0.0, 405.0,-1976.00,	 97.00, 27.75,  90.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//San Fierro Bahnhof
	{ 0.0, 405.0,-1976.00,	 93.00, 27.75,  90.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//San Fierro Bahnhof
	{ 0.0, 405.0,-1976.00,	 89.00, 27.75,  90.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//San Fierro Bahnhof
	{ 0.0, 405.0,-1388.50, -247.25,  6.00,	 0.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//San Fierro Flughafen
	{ 0.0, 405.0,-1384.50, -247.25,  6.00,	 0.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//San Fierro Flughafen
	{ 0.0, 405.0,-1380.50, -247.25,  6.00,	 0.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//San Fierro Flughafen
	{ 0.0, 405.0,-1376.50, -247.25,  6.00,	 0.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//San Fierro Flughafen
	{ 0.0, 405.0,-1372.50, -247.25,  6.00,	 0.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//San Fierro Flughafen
	{ 0.0, 405.0, 1374.50, 2645.50, 10.50,	 0.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//Las Venturas Bahnhof
	{ 0.0, 405.0, 1369.00, 2645.50, 10.50,	 0.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//Las Venturas Bahnhof
	{ 0.0, 405.0, 1362.50, 2645.50, 10.50,	 0.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//Las Venturas Bahnhof
	{ 0.0, 405.0, 1357.00, 2645.50, 10.50,	 0.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//Las Venturas Bahnhof
	{ 0.0, 405.0, 1361.50, 2645.50, 10.50,	 0.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//Las Venturas Bahnhof
	{ 0.0, 405.0, 1708.25, 1316.25, 11.00, 180.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//Las Venturas Flughafen
	{ 0.0, 405.0, 1705.00, 1316.25, 11.00, 180.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//Las Venturas Flughafen
	{ 0.0, 405.0, 1701.75, 1316.25, 11.00, 180.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//Las Venturas Flughafen
	{ 0.0, 405.0, 1698.50, 1316.25, 11.00, 180.0, 8.0, 8.0, 0.0, 15.0, 0.0 },		//Las Venturas Flughafen
	{ 0.0, 405.0, 1695.25, 1316.25, 11.00, 180.0, 8.0, 8.0, 0.0, 15.0, 0.0 }		//Las Venturas Flughafen
};
new bool:mietwagen_alive[][1] = { { false } };

//new MAX_PLAYERS = GetMaxPlayers();

new playerinhouse[MAX_PLAYERS];
new navivar[MAX_PLAYERS];
new playerdata[MAX_PLAYERS][80];
/*
0 => accid			10 => handy			20 => lizens_roller	    30 => lizens_angel          
1 => skinid			11 => weapon1		21 => lizens_a		  	31 => lizens_waffe
2 => jobid			12 => ammo1			22 => lizens_b		  	32 => perso
3 => skilllevel		13 => weapon2		23 => lizens_c		  	33 => adminlevel
4 => geld_bar		14 => ammo2			24 => lizens_ce		   	34 => interior
5 => geld_bank		15 => weapon3		25 => lizens_boot       35 => Fahndungslevel
6 => userlevel		16 => ammo3			26 => lizens_fischer    36 => Geschlecht
7 => playtime		17 => health		27 => lizens_flugklein  37 => Fahndungslevelcount
8 => skillcount		18 => tode			28 => lizens_fluggross  38 => bs_Fahrlehrer
9 => paydaycount	19 => gehalt		29 => lizens_heli       39 => bs_Pilot

40 => bs_Polizei	50 => bs_Taxif			60 => house2		  70 => skinchanges
41 => bs_Pbote		51 => bs_san			61 => inter2          71 => kills
42 => bs_Pfahrer	52 => bs_muell			62 => house3          72 => Essensinventar
43 => bs_Trucker	53 => bs_auftra			63 => inter3
44 => leer			54 => bs_touri			64 => house4
45 => bs_Bauer      55 => Gefдngnistimer	65 => inter4
46 => bs_Waffenh    56 => Premium			66 => house5
47 => bs_Fischer    57 => Fahrverbot		67 => inter5
48 => bs_Drogend	58 => house1			68 => Miete(gesamt)
49 => bs_Mechanic   59 => inter1			69 => Versicherungen

11 => Nahkampf / Wurfsachen
13 => Pistolen / SMPGS
15 => AK / Sniper

*/

new aufstiegsarray[][6] =
/*
* [0] => jobid             [1] => Levelup nach 1   [2] => Levelup nach 2
* [3] => Levelup nach 3    [4] => Levelup nach 4   [5] => Levelup nach 5 
*/
{
	{2,50,75,100,125,200},  //Postbote
	{5,5,7,10,12,20},       //Pilot
	{1,5,10,15,20,25},      //Trucker
	{7,10,20,30,40,50}      //Taxifahrer
};

new anrufender[MAX_PLAYERS];
new angerufener[MAX_PLAYERS];
new taxiguest[MAX_PLAYERS]; 	// Inhalt Anzahl Kilometer gefahren fьr Gast

new paydaytimer[MAX_PLAYERS],toroeffner[MAX_PLAYERS],handytimer[MAX_PLAYERS];
new playerinshop[MAX_PLAYERS];
new Text:paydaydraw1[MAX_PLAYERS],Text:paydaydraw2[MAX_PLAYERS],Text:zahltag,Text:berufserf;
new Text:berufserf1[MAX_PLAYERS],Text:berufserf2[MAX_PLAYERS],Text:userleveldraw1[MAX_PLAYERS],Text:userleveldraw2[MAX_PLAYERS],Text:userlevel;

public wait_kh(playerid)
{	
	TogglePlayerSpectating(playerid, true);
	new i;
	new Float:dist, dist2[2];
	dist2[0] = 6666;
	
	for(new a = 0; a < 8; a++)
	{
		dist = GetPlayerDistanceFromPoint(playerid, hospital_spawn[a][0], hospital_spawn[a][1], hospital_spawn[a][2]);
		if(dist < dist2[0]) {dist2[0] = floatround(dist); dist2[1] = a;}
	}
	i = dist2[1];
	SetTimerEx("spawn_player",54000,false,"iiffff",playerid,1,hospital_spawn[i][0],hospital_spawn[i][1],hospital_spawn[i][2],hospital_spawn[i][3]);
	GameTextForPlayer(playerid,"~r~Du bist im Krankenhaus~n~~w~Deine Behandlung dauert ~r~60 ~w~Sekunden",60000,3);
	InterpolateCameraPos(playerid,hospital_cam[i][0],hospital_cam[i][1],hospital_cam[i][2],hospital_cam[i][3],hospital_cam[i][4],hospital_cam[i][5], 2000, CAMERA_MOVE);
	InterpolateCameraLookAt(playerid, hospital_cam[i][0], hospital_cam[i][1], hospital_cam[i][2], hospital_cam[i][3], hospital_cam[i][4], hospital_cam[i][5], 500, CAMERA_MOVE);
}

public login_response(playerid, dialogid, response, listitem, inputtext[])
{
	if(dialogid == 1)
	{
		if(response)
		ShowPlayerDialog(playerid, 2,DIALOG_STYLE_PASSWORD , "Spielerregistrierung:", "Geben Sie ihr gewьnschtes Passwort ein:\n(Mind. 6 Zeichen)", "Registrieren", "Abbrechen");
		else
		Kick(playerid);
	}
	if(dialogid == 2)
	{
		if(response)
		{
			new query[128], pname[MAX_PLAYER_NAME],data[11];
			GetPlayerName(playerid, pname, MAX_PLAYER_NAME);
			if(strcmp("123456", inputtext) != 0 && strlen(inputtext) > 5)
			{
				// mysql_escape_string(pname,pname);
				// mysql_escape_string(inputtext,inputtext);
				mysql_format(MySQL:g_sql, query, sizeof(query), "INSERT INTO `user_list` (accname,password) VALUES ('%s',MD5('%s'))", pname,inputtext);
				mysql_tquery(MySQL:g_sql, query);
				mysql_tquery(MySQL:g_sql, "SELECT LAST_INSERT_ID() as userid FROM user_list");
				// mysql_store_result(g_sql);
				// cache_get_row_count(data);
				// cache_get_value_index("userid",data);
				mysql_format(MySQL:g_sql, query, sizeof(query), "INSERT INTO `user_licence` (accid) VALUES ('%i')", strval(data));
				mysql_tquery(MySQL:g_sql, query);
				mysql_format(MySQL:g_sql, query, sizeof(query), "INSERT INTO `user_weapons` (accid) VALUES ('%i')", strval(data));
				mysql_tquery(MySQL:g_sql, query);
				ShowPlayerDialog(playerid, 4,DIALOG_STYLE_MSGBOX, "Spielerregistrierung:", "Die Registrierung war erfolgreich, um fortzufahren\n wдhlen Sie bitte ein Geschlecht:", "Mдnnlich", "Weiblich");
			}
			else
			ShowPlayerDialog(playerid, 2,DIALOG_STYLE_PASSWORD , "Spielerregistrierung:", "Geben Sie ihr gewьnschtes Passwort ein:\n(Mind. 6 Zeichen)", "Registrieren", "Abbrechen");
		}
		else
		ShowPlayerDialog(playerid, 2,DIALOG_STYLE_PASSWORD , "Spielerregistrierung:", "Geben Sie ihr gewьnschtes Passwort ein:\n(Mind. 6 Zeichen)", "Registrieren", "Abbrechen");
	}
	if(dialogid == 3)
	{
		if(response)
		dologin(playerid,inputtext);
		else
		Kick(playerid);
	}
	if(dialogid == 4)
	{
		new query[128], pname[MAX_PLAYER_NAME];
		GetPlayerName(playerid, pname, MAX_PLAYER_NAME);
		mysql_escape_string(pname,pname);
		if(response)
		mysql_format(MySQL:g_sql, query, sizeof(query), "UPDATE user_list SET `geschlecht`=0,`skinid`=26 WHERE `accname`='%s'", pname);
		else
		mysql_format(MySQL:g_sql, query, sizeof(query), "UPDATE user_list SET `geschlecht`=1,`skinid`=131 WHERE `accname`='%s'", pname);
		mysql_tquery(MySQL:g_sql, query);
		ShowPlayerDialog(playerid, 3,DIALOG_STYLE_PASSWORD , "Login:", "Geben Sie ihr Passwort ein:", "Bestдtigen", "Abbrechen");
	}
	if(dialogid == 97 && response)
	{
		if(listitem == 0 && playerdata[playerid][10] == 1)
		{
			if(angerufener[playerid] >= 0)
			{
				anrufender[playerid] = angerufener[playerid];
				angerufener[playerid] = -1;
				KillTimer(handytimer[playerid]);
				SendClientMessage(playerid, COLOR_YELLOW, "Sie haben den Anruf entgegengenommen.");
				SendClientMessage(anrufender[playerid], COLOR_YELLOW, "Ihr Anruf wurde entgegengenommen.");
			}
			else if(anrufender[playerid] < 0)
			ShowPlayerDialog(playerid,1015,DIALOG_STYLE_INPUT, "Jemanden anrufen", "Geben Sie die Nummer des Spielers ein, welchen Sie anrufen mцchten.", "Anrufen", "Abbrechen");
			else
			{
				handyauflegen(playerid,anrufender[playerid],0);
			}
		}
		else if(listitem == 0 && playerdata[playerid][10] == 0)
		{
			GameTextForPlayer(playerid, "~r~Sie haben kein Handy zum Telefonieren!", 3000, 1);
		}
		else if(listitem == 1 && playerdata[playerid][72] >= 2)
		{
			playereat(playerid,15.0,0,5000);
			GameTextForPlayer(playerid, "~w~Sie haben etwas gegessen!", 3000, 1);
			playerdata[playerid][72]--;
			playerdata[playerid][72]--;
		}
		else if(listitem == 1 && playerdata[playerid][72] == 1)
		{
			GameTextForPlayer(playerid, "~w~Sie haben etwas gegessen!", 3000, 1);
			playereat(playerid,5.0,0,5000);
			playerdata[playerid][72]--;
		}
		else if(listitem == 1 && playerdata[playerid][72] == 0)
		{
			GameTextForPlayer(playerid, "~r~Sie haben nichts zu Essen dabei!", 3000, 1);
		}
		else if(listitem == 2)
		user_stats(playerid);
		else if(listitem == 3)
		hilfe_box(playerid);
		else if(listitem == 4)
		navibox(playerid);
		else if(listitem == 5)
		{
			new output[100];
			if(taxiguest[playerid] == 0) format(output,100,"Taxi rufen \n");
			else format(output,100,"Taxi abbestellen \n");
			ShowPlayerDialog(playerid,105,DIALOG_STYLE_LIST , "Aktion", output, "Auswдhlen", "Abbrechen");
		}
		else if(listitem == 6 && GetPlayerVehicleID(playerid) != 0 && GetPlayerVehicleSeat(playerid) == 0 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 509 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 510 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 481)
		{
			new bool:engine, bool:lights, bool:alarm, bool:doors, bool:bonnet, bool:boot, bool:objective;
			GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, doors, bonnet, boot, objective);
			if(lights == true)
			SetVehicleParamsEx(GetPlayerVehicleID(playerid),VEHICLE_PARAMS_ON,false, alarm, doors, bonnet, boot, objective);
			else
			SetVehicleParamsEx(GetPlayerVehicleID(playerid),VEHICLE_PARAMS_ON,true, alarm, doors, bonnet, boot, objective);
		}
		else if(listitem == 7 && GetPlayerVehicleID(playerid) != 0 && GetPlayerVehicleSeat(playerid) == 0 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 509 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 510 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 481)
		{
			new bool:engine, bool:lights, bool:alarm, bool:doors, bool:bonnet, bool:boot, bool:objective;
			GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, doors, bonnet, boot, objective);
			if(boot == true)
			SetVehicleParamsEx(GetPlayerVehicleID(playerid),VEHICLE_PARAMS_ON,lights, alarm, doors, bonnet, false, objective);
			else
			SetVehicleParamsEx(GetPlayerVehicleID(playerid),VEHICLE_PARAMS_ON,lights, alarm, doors, bonnet, true, objective);
		}
		else if(listitem == 8 && GetPlayerVehicleID(playerid) != 0 && GetPlayerVehicleSeat(playerid) == 0 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 509 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 510 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 481)
		{
			new bool:engine, bool:lights, bool:alarm, bool:doors, bool:bonnet, bool:boot, bool:objective;
			GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, doors, bonnet, boot, objective);
			if(bonnet == true)
			SetVehicleParamsEx(GetPlayerVehicleID(playerid),VEHICLE_PARAMS_ON,lights, alarm, doors, false, boot, objective);
			else
			SetVehicleParamsEx(GetPlayerVehicleID(playerid),VEHICLE_PARAMS_ON,lights, alarm, doors, true, boot, objective);
		}
	}
	if(dialogid == 1011 && response)
	{
		if(playerdata[playerid][2] == 3)
		{
			if(listitem == 0) fahrschule_stundenendelehrer(playerid);
			else if(listitem == 1) fahrschule_stundenende(playerid,1);
			else if(listitem == 2) fahrschule_stundenende(playerid,0);
			else if(listitem == 3) fahrschule_startbeantragen(playerid);
			else if(listitem == 4) fahrschule_landungbeantragen(playerid);
		}
		else if(playerdata[playerid][2] == 7)
		{
			if(listitem == 0) taxichangepreis(playerid);
			else if(listitem == 1) taxistreckebeenden(playerid);
			else if(listitem == 2) taxibeenden(playerid);
		}
	}
	if(dialogid == 1015 && response)
	{
		new ok = -1;
		for(new i = 0;i < MAX_PLAYERS;i++)
		{
			if(IsPlayerConnected(i) && strval(inputtext) == playerdata[i][0] && playerdata[i][10] == 1)
			{
				ok = i;
				i = MAX_PLAYERS;
			}
		}
		if(ok >= 0)
		{
			GameTextForPlayer(playerid, "~w~ Es klingelt...", 10000, 1);
			GameTextForPlayer(ok, "~w~ Ihr Handy klingelt.", 10000, 1);
			anrufender[playerid] = ok;
			angerufener[ok] = playerid;
			handytimer[ok] = SetTimerEx("handyauflegen",10000,false,"iii",playerid,ok,1);
		}
		else
		{
			GameTextForPlayer(playerid, "~r~ Besetzt.", 3000, 1);
		}
	}
}

public dologin(playerid,inputtext[])
{
	new data[600],Float:data2,Float:data3,Float:data4,query[500], pname[MAX_PLAYER_NAME];
	GetPlayerName(playerid, pname, MAX_PLAYER_NAME);
	// mysql_escape_string(pname,pname);
	// mysql_escape_string(inputtext,inputtext);
	mysql_format(MySQL:g_sql, query, sizeof(query), "SELECT COUNT(*) as anz FROM `accounts` JOIN `jobs` WHERE `accname`='%s' AND password=MD5('%s') AND accounts.jobid=jobs.jobid", pname,inputtext);
	mysql_tquery(MySQL:g_sql, query);
	// mysql_store_result(g_sql);
	// cache_get_value_index("anz",data);
	if(strval(data) == 1)
	{
		mysql_format(MySQL:g_sql, query, sizeof(query), "SELECT * FROM `accounts` JOIN `jobs` WHERE `accname`='%s' AND password=MD5('%s') AND accounts.jobid=jobs.jobid", pname,inputtext);
		mysql_tquery(MySQL:g_sql, query);
		// mysql_store_result(g_sql);
		// cache_get_row_count(data);
		// cache_get_value_index("accid",data);			playerdata[playerid][0] = strval(data);
		// cache_get_value_index("player_pos_x", data);	data2 = floatstr(data);
		// cache_get_value_index("player_pos_y", data);    data3 = floatstr(data);
		// cache_get_value_index("player_pos_z", data);    data4 = floatstr(data);
		// cache_get_value_index("skinid", data);			playerdata[playerid][1] = strval(data);
		// cache_get_value_index("jobid", data);			playerdata[playerid][2] = strval(data);
		// cache_get_value_index("skilllevel", data);      playerdata[playerid][3] = strval(data);
		// cache_get_value_index("geld_bar", data);		playerdata[playerid][4] = strval(data);
		// cache_get_value_index("geld_bank", data);		playerdata[playerid][5] = strval(data);
		// cache_get_value_index("userlevel", data);		playerdata[playerid][6] = strval(data);
		// cache_get_value_index("playtime", data);		playerdata[playerid][7] = strval(data);
		// cache_get_value_index("skillcount", data);		playerdata[playerid][8] = strval(data);
		// cache_get_value_index("paydaycount", data);		playerdata[playerid][9] = strval(data);
		// cache_get_value_index("handy", data);			playerdata[playerid][10] = strval(data);
		// cache_get_value_index("weapon1",data);			playerdata[playerid][11] = strval(data);
		// cache_get_value_index("ammo1",data);	        playerdata[playerid][12] = strval(data);
		// cache_get_value_index("weapon2",data);          playerdata[playerid][13] = strval(data);
		// cache_get_value_index("ammo2",data);	        playerdata[playerid][14] = strval(data);
		// cache_get_value_index("weapon3",data);		    playerdata[playerid][15] = strval(data);
		// cache_get_value_index("ammo3",data);	        playerdata[playerid][16] = strval(data);
		// cache_get_value_index("health",data);			playerdata[playerid][17] = strval(data);
		// cache_get_value_index("tode",data);				playerdata[playerid][18] = strval(data);
		// cache_get_value_index("gehalt",data);			playerdata[playerid][19] = strval(data);
		// cache_get_value_index("lizens_roller",data);	playerdata[playerid][20] = strval(data);
		// cache_get_value_index("lizens_a",data);			playerdata[playerid][21] = strval(data);
		// cache_get_value_index("lizens_b",data);			playerdata[playerid][22] = strval(data);
		// cache_get_value_index("lizens_c",data);			playerdata[playerid][23] = strval(data);
		// cache_get_value_index("lizens_ce",data);		playerdata[playerid][24] = strval(data);
		// cache_get_value_index("lizens_boot",data);		playerdata[playerid][25] = strval(data);
		// cache_get_value_index("lizens_fischer",data);	playerdata[playerid][26] = strval(data);
		// cache_get_value_index("lizens_flugklein",data);	playerdata[playerid][27] = strval(data);
		// cache_get_value_index("lizens_fluggross",data);	playerdata[playerid][28] = strval(data);
		// cache_get_value_index("lizens_heli",data);		playerdata[playerid][29] = strval(data);
		// cache_get_value_index("lizens_angel",data);		playerdata[playerid][30] = strval(data);
		// cache_get_value_index("lizens_waffe",data);		playerdata[playerid][31] = strval(data);
		// cache_get_value_index("perso",data);			playerdata[playerid][32] = strval(data);	
		// cache_get_value_index("adminlevel",data);		playerdata[playerid][33] = strval(data);
		// cache_get_value_index("interior",data);			playerdata[playerid][34] = strval(data);
		// cache_get_value_index("fahndung",data);			playerdata[playerid][35] = strval(data);
		// cache_get_value_index("geschlecht",data);	    playerdata[playerid][36] = strval(data);
		// //37 ist leer
		// cache_get_value_index("bs_fahrl",data);	        playerdata[playerid][38] = strval(data);
		// cache_get_value_index("bs_pilot",data);	        playerdata[playerid][39] = strval(data);
		// cache_get_value_index("bs_poliz",data);	        playerdata[playerid][40] = strval(data);
		// cache_get_value_index("bs_pbote",data);	        playerdata[playerid][41] = strval(data);
		// cache_get_value_index("bs_prodf",data);	        playerdata[playerid][42] = strval(data);
		// cache_get_value_index("bs_truck",data);	        playerdata[playerid][43] = strval(data);
		// cache_get_value_index("bs_bauer",data);	        playerdata[playerid][45] = strval(data);
		// cache_get_value_index("bs_waffe",data);	        playerdata[playerid][46] = strval(data);
		// cache_get_value_index("bs_fische",data);	    playerdata[playerid][47] = strval(data);
		// cache_get_value_index("bs_droge",data);	        playerdata[playerid][48] = strval(data);
		// cache_get_value_index("bs_mecha",data);	        playerdata[playerid][49] = strval(data);
		// cache_get_value_index("bs_taxif",data);	        playerdata[playerid][50] = strval(data);
		// cache_get_value_index("bs_sanit",data);	        playerdata[playerid][51] = strval(data);
		// cache_get_value_index("bs_muell",data);	        playerdata[playerid][52] = strval(data);
		// cache_get_value_index("bs_autra",data);	        playerdata[playerid][53] = strval(data);
		// cache_get_value_index("bs_touri",data);	        playerdata[playerid][54] = strval(data);
		// // 55
		// cache_get_value_index("premium",data);	        playerdata[playerid][56] = strval(data);
		// cache_get_value_index("fahrverbot",data);	    playerdata[playerid][57] = strval(data);
		// cache_get_value_index("skinchanges",data);	    playerdata[playerid][70] = strval(data);
		// cache_get_value_index("kills",data);	        playerdata[playerid][71] = strval(data);
		// cache_get_value_index("essensinventar",data);   playerdata[playerid][72] = strval(data);
		// cache_get_value_index("houseid",data);	    	playerinhouse[playerid] = strval(data);
		
		spawn_player(playerid,0,data2,data3,data4,0.0);
		paydaytimer[playerid] = SetTimerEx("payday", 60000, true, "i", playerid);
		SendClientMessage(playerid,COLOR_GREEN,"*** Erfolgreich eingeloggt. ***");
		toroeffner[playerid] = SetTimerEx("toropener",500,true,"i",playerid);
		
		mysql_format(MySQL:g_sql, query, sizeof(query), "UPDATE `user_list` SET online = 1 WHERE accid = %i", playerdata[playerid][0]);
		mysql_tquery(MySQL:g_sql, query);
		
		mysql_format(MySQL:g_sql, query, sizeof(query), "SELECT * FROM `user_house` WHERE accid = %i", playerdata[playerid][0]);
		new Cache:cache = mysql_query(g_sql, query);
		
		new i = 0,miete = 0;
		playerdata[playerid][58] = playerdata[playerid][59] = -1;
		playerdata[playerid][60] = playerdata[playerid][61] = -1;
		playerdata[playerid][62] = playerdata[playerid][63] = -1;
		playerdata[playerid][64] = playerdata[playerid][65] = -1;
		playerdata[playerid][66] = playerdata[playerid][67] = -1;
		
		while(cache_get_row_count(data))
		{
			cache_get_value_index("houseid",data);
			playerdata[playerid][(58+i)] = strval(data);
			i++;
			cache_get_value_index("interid",data);
			playerdata[playerid][(58+i)] = strval(data);
			cache_get_value_index("price",data);
			miete = miete + strval(data);
		}
		playerdata[playerid][68] = miete;
		
		mysql_format(MySQL:g_sql, query,100,"SELECT COUNT(*) as anz FROM `user_vehicles` WHERE vers = 1 AND accid=%i",playerdata[playerid][0]);
		new Cache:cache = mysql_query(g_sql, query);
		cache_get_row_count(data);
		cache_get_value_index("anz",data);
		playerdata[playerid][69] = 50 * strval(data);
		
		loadplayercarsforplayer(playerdata[playerid][0]);
		playerinshop[playerid] = -1;
		angerufener[playerid] = -1;
		anrufender[playerid] = -1;
		
		SetPlayerColor(playerid,COLOR_INVISIBLE);
		
		usertextdrawupdate(playerid);
	}
	else
	{
		ShowPlayerDialog(playerid, 3,DIALOG_STYLE_PASSWORD , "Login:", "Passwort falsch. Gebe dein Passwort erneut ein:", "Bestдtigen", "Abbrechen");
	}
}

public spawn_player(playerid,death,Float:posX,Float:posY,Float:posZ,Float:winkel)
{
	if(death == 0)
	{
		SetSpawnInfo(playerid, NO_TEAM, playerdata[playerid][1], posX,posY,posZ,0.0,WEAPON_FIST,0);
	}
	else
	{
		SetSpawnInfo(playerid, 0, playerdata[playerid][1], posX,posY,posZ,winkel,WEAPON_FIST,0); 
	}
	if(playerdata[playerid][34] != 0) SetPlayerInterior(playerid, playerdata[playerid][34]);
	TogglePlayerSpectating(playerid,false);
	SetPlayerHealth(playerid,playerdata[playerid][17]);
	ResetPlayerMoney(playerid);
	GivePlayerMoney(playerid,playerdata[playerid][4]);
	SpawnPlayer(playerid);
}

public dologout(playerid)
{
	new string[750],update[100],weaponslot,weaponid,ammo,Float:x, Float:y, Float:z;
	
	weaponslot = getweaponslot(playerdata[playerid][11]);
	GetPlayerWeaponData(playerid,WEAPON_SLOT:weaponslot,WEAPON:weaponid,ammo);
	if(ammo < playerdata[playerid][12])playerdata[playerid][12] = ammo;
	weaponslot = getweaponslot(playerdata[playerid][13]);
	GetPlayerWeaponData(playerid,WEAPON_SLOT:weaponslot,WEAPON:weaponid,ammo);
	if(ammo < playerdata[playerid][14])playerdata[playerid][14] = ammo;
	weaponslot = getweaponslot(playerdata[playerid][15]);
	GetPlayerWeaponData(playerid,WEAPON_SLOT:weaponslot,WEAPON:weaponid,ammo);
	if(ammo < playerdata[playerid][16]) playerdata[playerid][16] = ammo;
	
	//Bargeld ьberprьfen
	if(GetPlayerMoney(playerid) > playerdata[playerid][4]) {ResetPlayerMoney(playerid);GivePlayerMoney(playerid,playerdata[playerid][4]);}
	else if(GetPlayerMoney(playerid) < playerdata[playerid][4]){playerdata[playerid][4] = GetPlayerMoney(playerid);}
	
	//Query erstellen
	string ="UPDATE `user_list` SET ";
	format(update,100,"skinid=%i,jobid=%i,skilllevel=%i,",playerdata[playerid][1],playerdata[playerid][2],playerdata[playerid][3]);
	strcat(string,update);
	
	format(update,100,"geld_bar=%i,geld_bank=%i,userlevel=%i,kills=%i,essensinventar=%i,",playerdata[playerid][4],playerdata[playerid][5],playerdata[playerid][6],playerdata[playerid][71],playerdata[playerid][72]);
	strcat(string,update);
	
	format(update,100,"playtime=%i,skillcount=%i,paydaycount=%i,fahndung=%i,skinchanges=%i,",playerdata[playerid][7],playerdata[playerid][8],playerdata[playerid][9],playerdata[playerid][35],playerdata[playerid][70]);
	strcat(string,update);
	
	GetPlayerPos(playerid, x, y, z);
	format(update,100,"player_pos_x=%.2f,player_pos_y=%.2f,player_pos_z=%.2f,interior=%i,handy=%i,fahrverbot=%i,",x,y,z,GetPlayerInterior(playerid),playerdata[playerid][10],playerdata[playerid][57]);
	strcat(string,update);
	
	format(update,100,"health=%i,tode=%i,last_action=NOW(),online = 0,houseid = %i WHERE `accid`=%i",playerdata[playerid][17],playerdata[playerid][18],playerinhouse[playerid],playerdata[playerid][0]);
	strcat(string,update);
	mysql_tquery(string);
	
	string = "UPDATE `user_weapons` SET ";
	format(update,100,"weapon1=%i,ammo1=%i,",playerdata[playerid][11],playerdata[playerid][12]);
	strcat(string,update);
	
	format(update,100,"weapon2=%i,ammo2=%i,weapon3=%i,ammo3=%i ",playerdata[playerid][13],playerdata[playerid][14],playerdata[playerid][15],playerdata[playerid][16]);
	strcat(string,update);
	
	format(update,100,"WHERE `accid`=%i",playerdata[playerid][0]);
	strcat(string,update);
	mysql_tquery(string);
	
	string = "UPDATE `user_licence` SET ";
	format(update,100,"lizens_roller=%i,lizens_a=%i,lizens_b=%i,lizens_c=%i,",playerdata[playerid][20],playerdata[playerid][21],playerdata[playerid][22],playerdata[playerid][23]);
	strcat(string,update);
	
	format(update,100,"lizens_ce=%i,lizens_boot=%i,lizens_fischer=%i,lizens_flugklein=%i,",playerdata[playerid][24],playerdata[playerid][25],playerdata[playerid][26],playerdata[playerid][27]);
	strcat(string,update);
	
	format(update,100,"lizens_fluggross=%i,lizens_heli=%i,lizens_angel=%i,lizens_waffe=%i,perso=%i,",playerdata[playerid][28],playerdata[playerid][29],playerdata[playerid][30],playerdata[playerid][31],playerdata[playerid][32]);
	strcat(string,update);
	
	format(update,100,"bs_fahrl=%i,bs_pilot=%i,bs_poliz=%i,bs_pbote=%i,bs_prodf=%i,",playerdata[playerid][38],playerdata[playerid][39],playerdata[playerid][40],playerdata[playerid][41],playerdata[playerid][42]);
	strcat(string,update);
	
	format(update,100,"bs_truck=%i,bs_bauer=%i,bs_waffe=%i,bs_fische=%i,",playerdata[playerid][43],playerdata[playerid][45],playerdata[playerid][46],playerdata[playerid][47]);
	strcat(string,update);
	
	format(update,100,"bs_droge=%i,bs_mecha=%i,bs_taxif=%i,bs_sanit=%i,bs_muell=%i,",playerdata[playerid][48],playerdata[playerid][49],playerdata[playerid][50],playerdata[playerid][51],playerdata[playerid][52]);
	strcat(string,update);
	
	format(update,100,"bs_autra=%i,bs_touri=%i ",playerdata[playerid][53],playerdata[playerid][54]);
	strcat(string,update);
	
	format(update,100,"WHERE `accid`=%i",playerdata[playerid][0]);
	strcat(string,update);
	mysql_tquery(string);
	
	format(string,250,"UPDATE `user_vehicles` SET destroy = 2 WHERE destroy = 1 AND accid=%i",playerdata[playerid][0]);
	mysql_tquery(string);
}

public textonenterbuilding(playerid,txt[])
{
	format(txt,100,"~w~%s",txt);
	GameTextForPlayer(playerid, txt, 3000, 1);
}

public setuserlizens(playerid,lizens,senderid)
{
	new pname[MAX_PLAYER_NAME],pname2[MAX_PLAYER_NAME],output[100],data[50];
	GetPlayerName(playerid, pname, MAX_PLAYER_NAME);
	GetPlayerName(senderid, pname2, MAX_PLAYER_NAME);
	switch(lizens)
	{
		case 20:{ playerdata[playerid][20] = 1; data = "Rollerschein";}
		case 21:{ playerdata[playerid][21] = 1; data = "Motorradschein";}
		case 22:{ playerdata[playerid][22] = 1; data = "PKWschein";}
		case 23:{ playerdata[playerid][23] = 1; data = "Kleinlasterschein";}
		case 24:{ playerdata[playerid][24] = 1; data = "LKWschein";}
		case 25:{ playerdata[playerid][25] = 1; data = "Sportbootschein";}
		case 26:{ playerdata[playerid][26] = 1; data = "Fischerschein";}
		case 27:{ playerdata[playerid][27] = 1; data = "Kleinflugzeugschein";}
		case 28:{ playerdata[playerid][28] = 1; data = "Airbusschein";}
		case 29:{ playerdata[playerid][29] = 1; data = "Helicopterschein";}
		case 30:{ playerdata[playerid][30] = 1; data = "Angelschein";}
		case 31:{ playerdata[playerid][31] = 1; data = "Waffenschein";}
	}
	format(output,sizeof(output)," Du hast von %s den %s erhalten.",pname2,data);
	SendClientMessage(playerid,COLOR_BERUF,output);
	format(output,sizeof(output)," %s erhдlt den %s.",pname,data);
	SendClientMessage(senderid,COLOR_BERUF,output);
}

public giveusermoney(playerid,money)
{
	if(money < 0 && playerdata[playerid][4] >= (money*-1))
	{
		playerdata[playerid][4] = playerdata[playerid][4] + money; 
		GivePlayerMoney(playerid,money);
		return 1;
	}
	else if(money >= 0)
	{
		playerdata[playerid][4] = playerdata[playerid][4] + money; 
		GivePlayerMoney(playerid,money);
		return 1;
	}
	return 0;
}

public setuserjob(playerid,jobid)
{
	new query[128],data[25];
	format(query, sizeof(query), "UPDATE `accounts` SET `jobtime`=NOW() WHERE `accid`=%i",playerdata[playerid][0]);
	mysql_tquery(query);
	playerdata[playerid][2] = jobid;
	playerdata[playerid][3] = playerdata[playerid][8] = playerdata[playerid][9] = 0;
	if(jobid == 0)
	playerdata[playerid][19] = 0;
	else
	{
		format(query, sizeof(query), "SELECT gehalt FROM jobs WHERE jobid=%i",playerdata[playerid][2]);
		new Cache:cache = mysql_query(g_sql, query);
		cache_get_row_count(data);
		cache_get_value_index("gehalt",data);
		playerdata[playerid][19] = strval(data);
	}
	return 1;
}

public payday(playerid)
{
    //userlevel erhцhung , Skill erhцhung, Gehaltszahlung, Ьberprьfung Gesundheit und Waffen
    new string[100],Float:j,weaponid,ammo,weaponslot,reset = 0,slots[] = {0,0,0,0,0,0,0,0,0};
	
    //userlevel erhцhung nach 300 Spielminuten jeweils
    if((playerdata[playerid][7]+1) % 300 == 0)
    {
		playerdata[playerid][6]++;
		format(string,100,"Stufenaufstieg! Sie haben Userlevel %i erreicht.",playerdata[playerid][6]);
		SendClientMessage(playerid, COLOR_PAYDAY, string);
	}
    
    //Skilllevel je nach Job erhцhen
    new aufstieg = skilllevelcheck(playerid,playerdata[playerid][2]);
	
    if(aufstieg > 0)
    {
		format(string,100,"Berufserfahrung erhцht! Sie haben Stufe %i erreicht.",aufstieg);
		SendClientMessage(playerid, COLOR_PAYDAY, string);
	}
    
    //Zahltag fьr alle jobs wenn paydaycount einen bestimmten Wert erreicht + Zinsen nur wenn gearbeitet 1,8 %
    if((playerdata[playerid][7]+1) % 60 == 0)
    {
		aufstieg = 0;
		if(playerdata[playerid][2] == 2) //Job Postbote
		{
			if(playerdata[playerid][9] > 4)
			{
				playerdata[playerid][9] = 0;
				playerdata[playerid][5] = playerdata[playerid][5] + playerdata[playerid][19];
				aufstieg = 1;
			}
		}
		if(playerdata[playerid][2] == 5) //Job Pilot
		{
			if(playerdata[playerid][9] > 0)
			{
				playerdata[playerid][9] = 0;
				playerdata[playerid][5] = playerdata[playerid][5] + playerdata[playerid][19];
				aufstieg = 1;
			}
		}
		if(playerdata[playerid][2] == 1) //Job Trucker
		{
			if(playerdata[playerid][9] > 4)
			{
				playerdata[playerid][9] = 0;
				playerdata[playerid][5] = playerdata[playerid][5] + playerdata[playerid][19];
				aufstieg = 1;
			}
		}
		
		GameTextForPlayer(playerid, "~w~Zahltag!", 3000, 1);
		SendClientMessage(playerid, COLOR_PAYDAY,"~~~~~ ZAHLTAG ~~~~~");
		if(aufstieg)
		{
			format(string,100,"Alter Kontostand: %i",playerdata[playerid][5] - playerdata[playerid][19]);
			SendClientMessage(playerid, COLOR_PAYDAY, string);
			
			if(playerdata[playerid][56] == 1) playerdata[playerid][5] = floatround(playerdata[playerid][5] * 1.025);
			else playerdata[playerid][5] = floatround(playerdata[playerid][5] * 1.018);
			
			format(string,100,"%i$ + Zinsen wurden auf dein Konto ьberwiesen",playerdata[playerid][19]);
			SendClientMessage(playerid, COLOR_PAYDAY, string);
			
			if(playerdata[playerid][68] > 0)
			{
				format(string,100,"Miete fьr den nдchsten Monat wurde ьberwiesen. (-%i) ",playerdata[playerid][68]);
				playerdata[playerid][5] = playerdata[playerid][5] - playerdata[playerid][68];
				SendClientMessage(playerid, COLOR_PAYDAY, string);
			}
			
			if(playerdata[playerid][69] > 0)
			{
				format(string,100,"Versicherungsbeitrдge wurden ьberwiesen. (-%i) ",playerdata[playerid][69]);
				playerdata[playerid][5] = playerdata[playerid][5] - playerdata[playerid][69];
				SendClientMessage(playerid, COLOR_PAYDAY, string);
			}
			
			format(string,100,"Neuer Kontostand: %i",playerdata[playerid][5]);
			SendClientMessage(playerid, COLOR_PAYDAY, string);
		}
		else
		{
			format(string,100,"Alter Kontostand: %i",playerdata[playerid][5]);
			SendClientMessage(playerid, COLOR_PAYDAY, string);
			
			if(playerdata[playerid][56] == 1) playerdata[playerid][5] = floatround(playerdata[playerid][5] * 1.015);
			else playerdata[playerid][5] = floatround(playerdata[playerid][5] * 1.008);
			
			format(string,100,"100$ + Zinsen wurden auf dein Konto ьberwiesen");
			SendClientMessage(playerid, COLOR_PAYDAY, string);
			
			if(playerdata[playerid][68] > 0)
			{
				format(string,100,"Miete fьr den nдchsten Monat wurde ьberwiesen. (-%i) ",playerdata[playerid][68]);
				playerdata[playerid][5] = playerdata[playerid][5] - playerdata[playerid][68];
				SendClientMessage(playerid, COLOR_PAYDAY, string);
			}
			
			if(playerdata[playerid][69] > 0)
			{
				format(string,100,"Versicherungsbeitrдge wurden ьberwiesen. (-%i) ",playerdata[playerid][69]);
				playerdata[playerid][5] = playerdata[playerid][5] - playerdata[playerid][69];
				SendClientMessage(playerid, COLOR_PAYDAY, string);
			}
			
			format(string,100,"Neuer Kontostand: %i",playerdata[playerid][5]+100);
			SendClientMessage(playerid, COLOR_PAYDAY, string);
			
			playerdata[playerid][5] = playerdata[playerid][5] + 100;
		}
	}
    
    //Bargeld ьberprьfen
    if(GetPlayerMoney(playerid) > playerdata[playerid][4]) {ResetPlayerMoney(playerid);GivePlayerMoney(playerid,playerdata[playerid][4]);}
    else if(GetPlayerMoney(playerid) < playerdata[playerid][4]){playerdata[playerid][4] = GetPlayerMoney(playerid);}
    
    //Gesundheit ьberprьfen und verlieren 7% (max 5 min 2)
    j = (playerdata[playerid][17]/100 * 7);
    if(j > 5) j = 5; else if(j < 2) j = 2;
    SetPlayerHealth(playerid, (playerdata[playerid][17]-j));
    playerdata[playerid][17] = floatround(playerdata[playerid][17]-j);
    
    //WaffenSlotsьberprьfen
    weaponslot = getweaponslot(playerdata[playerid][11]);
    GetPlayerWeaponData(playerid,WEAPON_SLOT:weaponslot,WEAPON:weaponid,ammo);
    if(weaponid != playerdata[playerid][11]) reset = 1;
    if(ammo < playerdata[playerid][12]){playerdata[playerid][12] = ammo;} else if(ammo > playerdata[playerid][12])  reset = 1;
    slots[weaponslot] = 1;
	
    weaponslot = getweaponslot(playerdata[playerid][13]);
    GetPlayerWeaponData(playerid,WEAPON_SLOT:weaponslot,WEAPON:weaponid,ammo);
    if(weaponid != playerdata[playerid][13]) reset = 1;
    if(ammo < playerdata[playerid][14]){playerdata[playerid][14] = ammo;} else if(ammo > playerdata[playerid][14]) reset = 1;
    slots[weaponslot] = 1;
	
    weaponslot = getweaponslot(playerdata[playerid][15]);
    GetPlayerWeaponData(playerid,WEAPON_SLOT:weaponslot,WEAPON:weaponid,ammo);
    if(weaponid != playerdata[playerid][15]) reset = 1;
    if(ammo < playerdata[playerid][16]){playerdata[playerid][16] = ammo;} else if(ammo > playerdata[playerid][16]) reset = 1;
    slots[weaponslot] = 1;
	
	new weapon = 0;
	weapon = GetPlayerWeapon(playerid);
	
    for(new i=1;i < 9;i++)
    {
        if(slots[i] == 0)
        {
            GetPlayerWeaponData(playerid,WEAPON_SLOT:i,WEAPON:weaponid,ammo);
            if(weaponid > 1) reset = 1;
		}
	}
    if(reset == 1)
    {
        ResetPlayerWeapons(playerid);
        GivePlayerWeapon(playerid,WEAPON:playerdata[playerid][11],playerdata[playerid][12]);
        GivePlayerWeapon(playerid,WEAPON:playerdata[playerid][13],playerdata[playerid][14]);
        GivePlayerWeapon(playerid,WEAPON:playerdata[playerid][15],playerdata[playerid][16]);
	}
	SetPlayerArmedWeapon(playerid,WEAPON:weapon);
    
    //Fahndungslevel
    if(playerdata[playerid][35] > 0)
    {
		if(!playerdata[playerid][37]) playerdata[playerid][37] =  1;
		playerdata[playerid][37]++;
	}
    else
	playerdata[playerid][37] = 0;
    if(playerdata[playerid][37] == 10)
    {
		playerdata[playerid][35]--;
		playerdata[playerid][37] = 0;
		SetPlayerWantedLevel(playerid, playerdata[playerid][35]);
	}
    
	//Gefдngnistimer
	if(playerdata[playerid][35] == 0 && playerdata[playerid][55] == 1)
	{
		SetPlayerInterior(playerid, 0);
		SetPlayerPos(playerid, 268.0, 78.0, 15.5);
		playerdata[playerid][55] = 0;
	}
	
	//Fahrverbot
	if(playerdata[playerid][57] > 0)
	{
		if(GetPlayerState(playerid) != 2)
		playerdata[playerid][57]--;
	}
	//Mietwagen
    for(new i = 0; i < sizeof(mietwagen); i++)
	{
		if(floatround(mietwagen[i][0]) == GetPlayerVehicleID(playerid) && mietwagen[i][10] > 0)
		{
			mietwagen[i][10] = mietwagen[i][10] - 1.0;
			new output[128];
			if(mietwagen[i][10] < 6)
			{
				format(output, sizeof(output), "*** Ihr Mietvertrag lдuft in %i Minuten ab. ***", floatround(mietwagen[i][10]));
				SendClientMessage(playerid, COLOR_YELLOW, output);
			}
		}
		else if(mietwagen[i][0] == GetPlayerVehicleID(playerid) && mietwagen[i][10] == 0)
		{
			SendClientMessage(playerid, COLOR_YELLOW, "*************************************");
			SendClientMessage(playerid, COLOR_YELLOW, "**** Ihr Mietvertrag ist beendet ****");
			SendClientMessage(playerid, COLOR_YELLOW, "*************************************");
			SendClientMessage(playerid, COLOR_YELLOW, "*** Ihr Fahrzeug wurde aufgetankt ***");
			SendClientMessage(playerid, COLOR_YELLOW, "*** und auf Ihre Kosten repariert ***");
			SendClientMessage(playerid, COLOR_YELLOW, "*************************************");
			RemovePlayerFromVehicle(playerid);
			SetVehicleToRespawn(floatround(mietwagen[i][0]));
			mietwagen[i][8] = 0;
			if(mietwagen_alive[i][0] == true)
			{
				giveusermoney(playerid, 500);
				SendClientMessage(playerid, COLOR_YELLOW, "*** Die Kaution wurde Ihnen zurьckerstattet ***");
				mietwagen_alive[i][0] = false;
			}
		}
	}
	
    //playtime um eine Minute erhцhen
    playerdata[playerid][7]++;
    
    //Textdraws updaten
    usertextdrawupdate(playerid);
	return 1;
}

public skilllevelcheck(playerid,jobid)
{
	new aufstieg = 0;
	for(new i = 0;i < sizeof(aufstiegsarray);i++)
	{
		if(playerdata[playerid][2] == aufstiegsarray[i][0]) 
		{
			switch(playerdata[playerid][3])
			{
				case 0:{if(playerdata[playerid][8] >= aufstiegsarray[i][1]){ playerdata[playerid][8] = playerdata[playerid][8] - aufstiegsarray[i][1]; playerdata[playerid][3] = 1; aufstieg = 1;}}
				case 1:{if(playerdata[playerid][8] >= aufstiegsarray[i][2]){ playerdata[playerid][8] = playerdata[playerid][8] - aufstiegsarray[i][2]; playerdata[playerid][3] = 2;aufstieg = 2;}}
				case 2:{if(playerdata[playerid][8] >= aufstiegsarray[i][3]){ playerdata[playerid][8] = playerdata[playerid][8] - aufstiegsarray[i][3]; playerdata[playerid][3] = 3;aufstieg = 3;}}
				case 3:{if(playerdata[playerid][8] >= aufstiegsarray[i][4]){ playerdata[playerid][8] = playerdata[playerid][8] - aufstiegsarray[i][4]; playerdata[playerid][3] = 4;aufstieg = 4;}}
				case 4:{if(playerdata[playerid][8] >= aufstiegsarray[i][5]){ playerdata[playerid][8] = playerdata[playerid][8] - aufstiegsarray[i][5]; playerdata[playerid][3] = 5;aufstieg = 5;}}
			}
		}
	}
	return aufstieg;
}

public getweaponslot(weaponid)
{
    if(weaponid > 1 && weaponid < 10) return 1;
    else if(weaponid > 21 && weaponid < 25) return 2;
    else if(weaponid > 24 && weaponid < 28) return 3;
    else if(weaponid == 28 || weaponid == 29 || weaponid == 32) return 4;
    else if(weaponid == 31 || weaponid == 30) return 5;
    else if(weaponid == 33 || weaponid == 34) return 6;
    else if(weaponid > 34 && weaponid < 39) return 7;
    else if(weaponid > 15 && weaponid < 19) return 8;
    return 0;
}

public sendmessagetoallplayer(msg[],senderid,style,werbeid)
{
    /*
    * style: 0 => Werbung
    * x => Adminnachricht?
    */
    if(style == 0)
    {
		new query[128],data[125],output[250]= "Werbung: ";
		format(query, sizeof(query), "SELECT `accname`,`playerid`,`msg` FROM `accounts` JOIN `werbung` WHERE werbung.playerid=accounts.accid AND werbungid=%i", werbeid);
		new Cache:cache = mysql_query(g_sql, query);
		cache_get_row_count(data);
		cache_get_value_index("msg",data);
		strcat(output,data);
		strcat(output," (Abs: ");
		cache_get_value_index("accname",data);
		strcat(output,data);
		strcat(output," Tel: ");
		cache_get_value_index("playerid",data);
		strcat(output,data);
		strcat(output,")");
		SendClientMessageToAll(0x009C00FF, output);
	}
}

public actionmenu(playerid)
{
	new output[250];
	if(playerdata[playerid][10] == 0) strcat(output,"Sie haben kein Handy\n");
	else if(angerufener[playerid] >= 0) strcat(output,"Anruf annehmen.\n");
	else if(anrufender[playerid] >= 0) strcat(output,"Auflegen.\n");
	else strcat(output,"Anrufen\n");
	if(playerdata[playerid][72] > 0) strcat(output,"Etwas essen\n");
	else strcat(output,"Sie haben nichts zu essen dabei\n");
	strcat(output,"Statistik aufrufen\n");
	strcat(output,"Hilfe aufrufen\n");
	strcat(output,"Navigation aufrufen\n");
	strcat(output,"Service aufrufen\n");
	if(GetPlayerVehicleID(playerid) != 0 && GetPlayerVehicleSeat(playerid) == 0 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 509 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 510 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 481)
	{
		strcat(output,"Licht an / ausschlalten\n");
		strcat(output,"Kofferraum auf / zu \n");
		strcat(output,"Motorhaube auf / zu \n");
	}
	
	ShowPlayerDialog(playerid,97,DIALOG_STYLE_LIST , "Aktion", output, "Auswдhlen", "Abbrechen");
}

public jobaction(playerid)
{
	new output[250];
	if(playerdata[playerid][2] == 3)
	{
		strcat(output,"Fahrstunde abbrechen\n");
		strcat(output,"Fahrstunde bestanden\n");
		strcat(output,"Fahrstunde nicht bestanden\n");
		strcat(output,"Starterlaubis beantragen\n");
		strcat(output,"Landeerlaubis beantragen\n");
		ShowPlayerDialog(playerid,1011,DIALOG_STYLE_LIST , "Aktion", output, "Auswдhlen", "Abbrechen");
	}
	if(playerdata[playerid][2] == 7)
	{
		strcat(output,"Fahrpreis дndern (Bei KEINEM Fahrgast im Auto!)\n");
		strcat(output,"Job abbrechen (Bei Fahrgast im Auto)\n");
		strcat(output,"Job beenden (Auto zurьckbringen)\n");
		ShowPlayerDialog(playerid,1011,DIALOG_STYLE_LIST , "Aktion", output, "Auswдhlen", "Abbrechen");
	}
}

public user_stats(playerid)
{
	new pname[32],jName[128], gehalt, caption[64], info[2048], infozeile[256], mysqli[128], playtime[128], fekl[256], update[32];
	new d = 0, h = 0, m = playerdata[playerid][7];
	// Spielzeit 
	while(m > 59)
	{
		h++;
		m = m - 60;
	}
	while(h > 23)
	{
		d++;
		h = h - 24;
	}
	if(d > 0)
	{
		if(d == 1)
		format(update, sizeof(update), "{FFFFFF}%i{FFB400} Tag, ", d);
		else
		format(update, sizeof(update), "{FFFFFF}%i{FFB400} Tage, ", d);
		strcat(playtime, update);
		if(h == 1)
		format(update, sizeof(update), "{FFFFFF}%i{FFB400} Stunde, ", h);
		else
		format(update, sizeof(update), "{FFFFFF}%i{FFB400} Stunden, ", h);
		strcat(playtime, update);
		if(m == 1)
		format(update, sizeof(update), "{FFFFFF}%i{FFB400} Minute", m);
		else
		format(update, sizeof(update), "{FFFFFF}%i{FFB400} Minuten", m);
		strcat(playtime, update);
	}
	else if(h > 0)
	{
		if(h == 1)
		format(update, sizeof(update), "{FFFFFF}%i{FFB400} Stunde \t", h);
		else
		format(update, sizeof(update), "{FFFFFF}%i{FFB400} Stunden\t", h);
		strcat(playtime, update);
		if(m == 1)
		format(update, sizeof(update), "{FFFFFF}%i{FFB400} Minute \t", m);
		else
		format(update, sizeof(update), "{FFFFFF}%i{FFB400} Minuten\t", m);
		strcat(playtime, update);
	}
	else
	{
		if(m == 1)
		format(update, sizeof(update), "{FFFFFF}%i{FFB400} Minute \t", m);
		else
		format(update, sizeof(update), "{FFFFFF}%i{FFB400} Minuten\t", m);
		strcat(playtime, update, sizeof(playtime));
	}
	// Fьhrerscheinklassen
	if(playerdata[playerid][21] == 1) strcat(fekl,"- Motorrad\n");
	if(playerdata[playerid][22] == 1) strcat(fekl,"- PKW\n");
	if(playerdata[playerid][23] == 1) strcat(fekl,"- LKW (C)\n");
	if(playerdata[playerid][24] == 1) strcat(fekl,"- LKW (CE)\n");
	if(playerdata[playerid][27] == 1) strcat(fekl,"- Kleinflugzeug\n");
	if(playerdata[playerid][28] == 1) strcat(fekl,"- Fracht- und Passagierflugzeuge\n");
	if(playerdata[playerid][29] == 1) strcat(fekl,"- Helikopter\n");
	if(playerdata[playerid][25] == 1) strcat(fekl,"- Sportboote\n");
	if(playerdata[playerid][26] == 1) strcat(fekl,"- Fischerboote\n");
	GetPlayerName(playerid, pname, sizeof(pname));
	// Beruf
	format(mysqli, sizeof(mysqli), "SELECT jName, gehalt FROM jobs WHERE jobid = %i", playerdata[playerid][2]);
	new Cache:cache = mysql_query(g_sql, mysqli);
	cache_get_row_count(mysqli);
	cache_get_value_index("jName",mysqli);
	jName = mysqli;
	cache_get_value_index("gehalt", mysqli);
	gehalt = strval(mysqli);
	// Finanzen
	// Ausgabe	
	format(caption, sizeof(caption), "{FFFFFF}Statistik von %s{FFFFFF}", pname);
	format(infozeile, sizeof(infozeile), "{FF6E00}Allgemein\n");
	strcat(info, infozeile, sizeof(info));
	format(infozeile, sizeof(infozeile), "{FFB400}Level: {FFFFFF}%i{FFB400}\nHandynr: {FFFFFF}%i{FFB400}\n\n",playerdata[playerid][6], playerdata[playerid][0]);
	strcat(info, infozeile, sizeof(info));
	format(infozeile, sizeof(infozeile), "{FF6E00}Finanzen\n");
	strcat(info, infozeile, sizeof(info));
	format(infozeile, sizeof(infozeile), "{FFB400}Konto:{FFFFFF} %i $\n\n", playerdata[playerid][5]);
	strcat(info, infozeile, sizeof(info));
	format(infozeile, sizeof(infozeile), "{FF6E00}Spielzeit\n");
	strcat(info, infozeile, sizeof(info));
	format(infozeile, sizeof(infozeile), "{FFB400}%s\n\n", playtime);
	strcat(info, infozeile, sizeof(info));
	format(infozeile, sizeof(infozeile), "{FF6E00}Spieler gegen Spieler\n");
	strcat(info, infozeile, sizeof(info));
	format(infozeile, sizeof(infozeile), "{FFB400}Morde: {FFFFFF}%i{FFB400}\n{FFB400}Tode: {FFFFFF}%i{FFB400}\t\n\n", playerdata[playerid][71], playerdata[playerid][18]);
	strcat(info, infozeile, sizeof(info));
	format(infozeile, sizeof(infozeile), "{FF6E00}Beruf\n");
	strcat(info, infozeile, sizeof(info));
	format(infozeile, sizeof(infozeile), "{FFB400}Beruf: {FFFFFF}%s{FFB400}\nGrundgehalt: {FFFFFF}%i{FFB400}\nErfahrung: {FFFFFF}%i{FFB400}\n\n", jName, gehalt, playerdata[playerid][3]);
	strcat(info, infozeile, sizeof(info));
	format(infozeile, sizeof(infozeile), "{FF6E00}Fьhrerscheine\n");
	strcat(info, infozeile, sizeof(info));
	format(infozeile, sizeof(infozeile), "{FFB400}%s{FFFFFF}", fekl);
	strcat(info, infozeile, sizeof(info));
	ShowPlayerDialog(playerid, 0, DIALOG_STYLE_MSGBOX, caption, info, "Beenden", "");
	
}

public usertextdrawupdate(playerid)
{
	new a = floatround(playerdata[playerid][7] / 60);
	new b = playerdata[playerid][7] - a * 60;
	b = floatround(b / 3);
	new string[100] = "";
	
	for(new k = 0; k <= b;k++)
	{
		strcat(string,"I");
	}
	TextDrawSetString(paydaydraw1[playerid],string);
	
	if(b == 0) a = 0;
	else if(b == 1 || b == 2) a = 1;
	else if(b == 3) a = 2; else if(b == 5 || b == 4) a = 3; else if(b == 6) a = 4;
	else if(b == 7) a = 5;
	else if(b == 9 || b == 8) a = 6; else if(b == 10) a = 7; else if(b == 11) a = 8;
	else if(b == 12 || b == 13) a = 9;
	else if(b == 14) a = 10; else if(b == 15 || b == 16) a = 11;
	else if(b == 17) a = 12; else if(b == 18) a = 13;
	else a = 14;
	
	string = "";
	for(new k = 0;k < 20;k++)
	{
		if(k <= a) strcat(string," ");
		else if(k - b > 0) strcat(string,"I");
	}
	TextDrawSetString(paydaydraw2[playerid],string);
	
	a = floatround(playerdata[playerid][7] / 300);
	b = playerdata[playerid][7] - a * 300;
	b = floatround(b / 15);
	string = "";
	
	for(new k = 0; k <= b;k++)
	{
		strcat(string,"I");
	}
	TextDrawSetString(userleveldraw1[playerid],string);
	
	if(b == 0) a = 0;
	else if(b == 1 || b == 2) a = 1;
	else if(b == 3) a = 2; else if(b == 5 || b == 4) a = 3; else if(b == 6) a = 4;
	else if(b == 7) a = 5;
	else if(b == 9 || b == 8) a = 6; else if(b == 10) a = 7; else if(b == 11) a = 8;
	else if(b == 12 || b == 13) a = 9;
	else if(b == 14) a = 10; else if(b == 15 || b == 16) a = 11;
	else if(b == 17) a = 12; else if(b == 18) a = 13;
	else a = 14;
	
	string = "";
	for(new k = 0;k < 20;k++)
	{
		if(k <= a) strcat(string," ");
		else if(k - b > 0) strcat(string,"I");
	}
	TextDrawSetString(userleveldraw2[playerid],string);
	
	a = 0;
	for(new i = 0;i < sizeof(aufstiegsarray);i++)
	{
		if(playerdata[playerid][2] == aufstiegsarray[i][0]) 
		{
			switch(playerdata[playerid][3])
			{
				case 0: a = aufstiegsarray[i][1];
				case 1: a = aufstiegsarray[i][2];
				case 2: a = aufstiegsarray[i][3];
				case 3: a = aufstiegsarray[i][4];
				case 4: a = aufstiegsarray[i][5];
			}
		}
	}
	if(a > 0)
	{
		b = a - (a - playerdata[playerid][8]);
		string = "";
		b = floatround(b * (20/a));
		
		for(new k = 0; k <= b;k++)
		{
			strcat(string,"I");
		}
		TextDrawSetString(berufserf1[playerid],string);
		
		if(b == 0) a = 0;
		else if(b == 1 || b == 2) a = 1;
		else if(b == 3) a = 2; else if(b == 5 || b == 4) a = 3; else if(b == 6) a = 4;
		else if(b == 7) a = 5;
		else if(b == 9 || b == 8) a = 6; else if(b == 10) a = 7; else if(b == 11) a = 8;
		else if(b == 12 || b == 13) a = 9;
		else if(b == 14) a = 10; else if(b == 15 || b == 16) a = 11;
		else if(b == 17) a = 12; else if(b == 18) a = 13;
		else a = 14;
		
		string = "";
		for(new k = 0;k < 20;k++)
		{
			if(k <= a) strcat(string," ");
			else if(k - b > 0) strcat(string,"I");
		}
		TextDrawSetString(berufserf2[playerid],string);
	}
	else
	{
		TextDrawSetString(berufserf1[playerid]," ");
		TextDrawSetString(berufserf2[playerid],"~w~arbeitslos");
	}
}

public handyauflegen(playerid,i,kind)
{
	anrufender[i] = -1;
	angerufener[i] = -1;
	angerufener[playerid] = -1;
	anrufender[playerid] = -1;
	if(kind == 1)
	{
		GameTextForPlayer(playerid, "~r~Es wurde nicht abgenommen", 3000, 1);
	}
	else
	{
		GameTextForPlayer(playerid, "~w~ Aufgelegt", 3000, 1);
		GameTextForPlayer(i, "~w~ Aufgelegt", 3000, 1);
	}
}
