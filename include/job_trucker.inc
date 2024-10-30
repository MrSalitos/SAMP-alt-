/* ******************************************************************** */
/* Autor: MrSalitos                                   			        */
/* ******************************************************************** */
/* *************************** Farbdefinitionen *********************** */
#define COLOR_TRUCKER	0xFFAA00FF				//Trucker - Systemnachricht
/* ****************************  Checkpoints  ************************* */
#define CP_RAFFINERIE -1035.0, -650.0, 32.0
#define CP_OILFIELD 115.5, 1407.0, 11.5
#define CP_LSHAFEN 2272.0, -2410.5, 13.5
#define CP_LVDEPOT 1613.5, 2333.5, 13.0
#define CP_BAYSIDE -2278.0, 2325.0, 6.0
#define CP_SFFISCH -1826.5, 42.0, 17.0
#define CP_AIRPORT_LS 2070.0,  -2222.0,  13.5
#define CP_AIRPORT_SF -1245.0,  15.0,  14.5
#define CP_AIRPORT_LV 1645.5,  1609.0,  14.0
#define CP_PROD_LS 1135.5, -1339.0, 14.0
#define CP_PROD_SF -1880.0, -210.0, 18.5
#define CP_PROD_LV 2833.0, 976.0, 11.0
/* ****************************  Tankstellen  ************************* */
#define Alhambra_Station 1950.00, -1765.00, 13.50
#define BSN_Station 980.51, -926.79, 41.50
#define RSHaul_Station -98.08, -1158.50, 2.06
#define Dillimore_Station 660.60, -553.57, 16.33
#define Montgomery_Station 1411.90, 454.35, 20.21
#define AngelPine_Station -2252.91, -2565.98, 31.92
#define Whetstone_Station -1589.40, 2710.17, 48.53
#define Doherty_Station -2034.55, 139.14, 28.83
#define EasterBasin_Station -1644.01, 443.45, 7.17
#define JuniperHill_Station -2412.04, 995.32, 45.29
#define TierraRobada_Station -1493.83, 1858.35, 32.24
#define ElQuebrados_Station 0.00, 0.00, 0.00
#define BoneCountry_Station 627.98, 1662.15, 6.99
#define FortCarson_Station 0.00, 0.00, 0.00
#define ComeALot_Station 2099.48, 934.63, 10.82
#define xxx 2655.51, 1091.34, 10.82
#define RedsandsWest_Station 1599.17, 2215.76, 10.82
#define Emerald_Station 2191.95, 2467.34, 10.82
#define Spinybed_Station 2151.60, 2758.33, 10.82
#define Flughafen_SF -1148.5, -172.5, 14.5
/* ****************************  Konstanten  ************************** */
#define PROVISION floatround(mission_cash[playerid] / 10)

new TrailerLoad[MAX_PLAYERS];
new ts_mission_id[MAX_PLAYERS];
new max_amount[MAX_PLAYERS];
new Float:mission_cash[MAX_PLAYERS];
new Float:ts_ekpreis[MAX_PLAYERS];
new Float:ek_einzel[MAX_PLAYERS];
new lager[MAX_PLAYERS];
new MissionActive[MAX_PLAYERS];
new CurrentTrailer[MAX_PLAYERS];
new trucker_car[2][10];
new tls[64];
// new Text:TrailerLoadText[MAX_PLAYERS];

forward trucker();
forward PickupTimer(pickups);
forward TruckerStartWork(playerid);
forward TruckerStopWork(playerid);
forward TruckerDialoge(playerid, dialogid, response, listitem);
forward OnTruckerSelectedMenuRow(playerid, row);
forward DetachTrailer(playerid);
forward GetRaffinerieMission(playerid);	
forward GetImportMission(playerid);
forward GetFischMission(playerid);
forward GetProdLSMission(playerid);
forward GetProdSFMission(playerid);
forward GetProdLVMission(playerid);
forward GetTsMission(playerid);
forward StartTSMission(playerid);
forward CancelTsMission(playerid);
forward CheckTruckerVehicles(playerid);
forward trucker_biz_timer();
	
public trucker()
{ 		
	/* *************************  MrSalitos Spawnpunkte  ********************** */
	CreateVehicleEx(522, -691.75, 961.0, 12.0, 45, 79, 0, 3600);
	CreateVehicleEx(556, -675.0, 962.0, 12.5, 90, 0, 0, 3600);
	CreateVehicleEx(453, -2198.74, 2417.89, -0.38, 320, 0, 26, 3600);
	// CreateVehicleEx(435, -59.80, -1130.11, 1.07, 45.0, 0, 26, 3600);
	// CreateVehicleEx(403, -60.80, -1130.11, 1.07, 45.0, 0, 26, 3600);
	/* *************************   Trailer Spawnpunkte   ********************** */
	trucker_car[0][0] = CreateVehicleEx(584, -0.000000, -374.000000, 5.500000, 0, 79, 0, 300);		//Tankauflieger 1
	trucker_car[0][1] = CreateVehicleEx(584, -4.000000, -374.00000, 5.500000, 0, 79, 0, 300);			//Tankauflieger 2
	trucker_car[0][2] = CreateVehicleEx(584, -8.000000, -374.000000, 5.500000, 0, 79, 0, 300);		//Tankauflieger 3
	trucker_car[0][3] = CreateVehicleEx(591, -12.000000, -374.000000, 5.500000, 0, 79, 0, 300);		//Containerauflieger 1
	trucker_car[0][4] = CreateVehicleEx(591, -16.000000, -374.000000, 5.500000, 0, 79, 0, 300);		//Containerauflieger 2
	trucker_car[0][5] = CreateVehicleEx(591, -20.000000, -374.000000, 5.500000, 0, 79, 0, 300);		//Containerauflieger 3
	trucker_car[0][6] = CreateVehicleEx(435, -24.000000, -374.000000, 5.500000, 0, 79, 0, 300);		//Kofferauflieger 1
	trucker_car[0][7] = CreateVehicleEx(435, -28.000000, -374.000000, 5.500000, 0, 79, 0, 300);		//Kofferauflieger 2
	trucker_car[0][8] = CreateVehicleEx(435, -32.000000, -374.000000, 5.500000, 0, 79, 0, 300);		//Kofferauflieger 3
	trucker_car[0][9] = CreateVehicleEx(450, -36.000000, -374.000000, 5.500000, 0, 79, 0, 300);		//Schüttgutauflieger 1
	/* *************************   Truck Spawnpunkte   ************************ */
	trucker_car[1][0] = CreateVehicleEx(403, 11.000000, -220.000000, 5.500000, 90, 79, 0, 300);		//Linerunner 1
	trucker_car[1][1] = CreateVehicleEx(403, 11.000000, -225.000000, 5.500000, 90, 79, 0, 300);		//Linerunner 2
	trucker_car[1][2] = CreateVehicleEx(403, 11.000000, -230.000000, 5.500000, 90, 79, 0, 300);		//Linerunner 3
	trucker_car[1][3] = CreateVehicleEx(403, 11.000000, -235.000000, 5.500000, 90, 79, 0, 300);		//Linerunner 4
	trucker_car[1][4] = CreateVehicleEx(514, 11.000000, -240.000000, 5.500000, 90, 79, 0, 300);		//Tanker 1
	trucker_car[1][5] = CreateVehicleEx(514, 11.000000, -245.000000, 5.500000, 90, 79, 0, 300);		//Tanker 2
	trucker_car[1][6] = CreateVehicleEx(514, 11.000000, -250.000000, 5.500000, 90, 79, 0, 300);		//Tanker 3
	trucker_car[1][7] = CreateVehicleEx(515, -13.000000, -230.000000, 6.000000, 270, 79, 0, 300);	//Roadtrain 1
	trucker_car[1][8] = CreateVehicleEx(515, -13.000000, -225.000000, 6.000000, 270, 79, 0, 300);	//Roadtrain 2
	trucker_car[1][9] = CreateVehicleEx(515, -13.000000, -220.000000, 6.000000, 270, 79, 0, 300);	//Roadtrain 3
}
public TruckerStartWork(playerid)
{ 
	if(!MissionActive[playerid])
		ShowPlayerDialog(playerid, 2000, DIALOG_STYLE_LIST, "Trucker", "Rohöl\nImport\nFisch\nProds LS\nProds SF\nProds LV\nTankstellen", "Auswahl", "Abbrechen");
}
public TruckerStopWork(playerid)
{ 
	if(IsTrailerAttachedToVehicle(GetPlayerVehicleID(playerid)))
	{ 
		ts_mission_id[playerid] = 999;
		SendClientMessage(playerid, COLOR_TRUCKER, "*** Bitte bringen Sie Ihren Trailer zurück ***");
		SetPlayerCheckpoint(playerid, -0.0, -350.0, 5.5, 7);
	} 
	if(!IsTrailerAttachedToVehicle(GetPlayerVehicleID(playerid)))
	{ 
		ts_mission_id[playerid] = 1000;
		SendClientMessage(playerid, COLOR_TRUCKER, "*** Bitte bringen Sie Ihren Truck zurück***");
		SetPlayerCheckpoint(playerid, 11.0, -260.0, 6.0, 7);
	} 
} 
public TruckerDialoge(playerid, dialogid, response, listitem)
{ 
	if(dialogid == 2000)
	{ 
		if(response)
		{ 
			if(listitem == 0)
			{ 
			GetRaffinerieMission(playerid);
			}
			else if(listitem == 1)
			{ 
				GetImportMission(playerid);
			}
			else if(listitem == 2)
			{ 	
				GetFischMission(playerid);
			}
			else if(listitem == 3)
      { 	
				GetProdLSMission(playerid);
			}
			else if(listitem == 4)
			{ 	
				GetProdSFMission(playerid);
			}
			else if(listitem == 5)
      { 	
				GetProdLVMission(playerid);
			}
			else if(listitem == 6)
      { 	
				GetTsMission(playerid);				
      }
		}
		else
		{
			TruckerStopWork(playerid);
		}
		TogglePlayerControllable(playerid, true);
	}
	
	return 1;
}
public DetachTrailer(playerid)
{ 
    if(IsPlayerConnected(playerid))
    { 
        new tmpcar = GetPlayerVehicleID(playerid);
        if(IsTrailerAttachedToVehicle(tmpcar))
        { 
                DetachTrailerFromVehicle(tmpcar);
                return 1;
        }
        else
        { 
                SendClientMessage(playerid, COLOR_TRUCKER, "   You're not having any Trailer attached to your Truck.");
                return 1;
        }
    }
    return 1;
}
public GetRaffinerieMission(playerid)
{ 	
	new query[256], output[128], data[128], name[128];
	format(query, sizeof(query), "SELECT biz_name, ek_einzel, max_amount, max_amount - cur_amount AS lager FROM `trucker_biz` WHERE biz_id = 2;");
	mysql_query(query);
	mysql_store_result();
	mysql_fetch_row(data);
	mysql_fetch_field("biz_name", data);
	name = data;
	mysql_fetch_field("ek_einzel", data);
	ek_einzel[playerid] = floatstr(data);
	mysql_fetch_field("max_amount", data);
	max_amount[playerid] = strval(data);
	mysql_fetch_field("lager", data);
	lager[playerid] = strval(data);
	mysql_free_result();
	ts_mission_id[playerid] = 70;
	if(max_amount[playerid] > 99000)
	{ 
		format(output, sizeof(output),"*** Fahre zur den Ölfeldern um Rohöl zu laden ***", name, lager);
		SetPlayerCheckpoint(playerid, CP_OILFIELD, 6);
		format(query, sizeof(query), "UPDATE trucker_biz SET cur_amount = (cur_amount + 1000) WHERE biz_id = 1;");
		mysql_query(query);
		MissionActive[playerid] = 1;
	}
	else
	{ 
		format(output, sizeof(output),"*** Zurzeit wird kein Rohöl benötigt. ***");
	}
	SendClientMessage(playerid, COLOR_TRUCKER, output);
	return 1;
}
public GetImportMission(playerid)
{ 	
	new query[256], output[128], data[128], name[128];
	format(query, sizeof(query), "SELECT biz_name, ek_einzel, max_amount, max_amount - cur_amount AS lager FROM `trucker_biz` WHERE biz_id = 4;");
	mysql_query(query);
	mysql_store_result();
	mysql_fetch_row(data);
	mysql_fetch_field("biz_name", data);
	name = data;
	mysql_fetch_field("ek_einzel", data);
	ek_einzel[playerid] = floatstr(data);
	mysql_fetch_field("max_amount", data);
	max_amount[playerid] = strval(data);
	mysql_fetch_field("lager", data);
	lager[playerid] = strval(data);
	mysql_free_result();
	ts_mission_id[playerid] = 80;
	if(max_amount[playerid] > 99000)
	{ 
		format(output, sizeof(output),"*** Fahre zum Containerhafen in Los Santos um Importwaren zu laden ***", name, lager);
		SetPlayerCheckpoint(playerid, CP_LSHAFEN, 6);
		format(query, sizeof(query), "UPDATE trucker_biz SET cur_amount = (cur_amount - 1000) WHERE biz_id = 1;");
		mysql_query(query);
		MissionActive[playerid] = true;
	}
	else
	{ 
		format(output, sizeof(output),"*** Zurzeit werden keine Importwaren benötigt. ***");
	}
	SendClientMessage(playerid, COLOR_TRUCKER, output);
	return 1;
}
public GetFischMission(playerid)
{ 			
	new query[256], output[128], data[128], name[128];
	format(query, sizeof(query), "SELECT biz_name, ek_einzel, max_amount, max_amount - cur_amount AS lager FROM `trucker_biz` WHERE biz_id = 6;");
	mysql_query(query);
	mysql_store_result();
	mysql_fetch_row(data);
	mysql_fetch_field("biz_name", data);
	name = data;
	mysql_fetch_field("ek_einzel", data);
	ek_einzel[playerid] = floatstr(data);
	mysql_fetch_field("max_amount", data);
	max_amount[playerid] = strval(data);
	mysql_fetch_field("lager", data);
	lager[playerid] = strval(data);
	mysql_free_result();
	ts_mission_id[playerid] = 90;
	if(max_amount[playerid] > 99000)
	{ 
		format(output, sizeof(output),"*** Fahre zum Fischereihafen in Bayside um Fisch zu laden ***", name, lager);
		SetPlayerCheckpoint(playerid, CP_BAYSIDE, 6);
		format(query, sizeof(query), "UPDATE trucker_biz SET cur_amount = (cur_amount - 1000) WHERE biz_id = 1;");
		mysql_query(query);
		MissionActive[playerid] = true;
	}
	else
	{ 
		format(output, sizeof(output),"*** Zurzeit wird kein Fisch benötigt. ***");
	}
	SendClientMessage(playerid, COLOR_TRUCKER, output);
	return 1;
}
public GetProdLSMission(playerid)
{ 			
	new query[256], output[128], data[128], name[128];
	format(query, sizeof(query), "SELECT biz_name, ek_einzel, max_amount, max_amount - cur_amount AS lager FROM `trucker_biz` WHERE biz_id = 8;");
	mysql_query(query);
	mysql_store_result();
	mysql_fetch_row(data);
	mysql_fetch_field("biz_name", data);
	name = data;
	mysql_fetch_field("ek_einzel", data);
	ek_einzel[playerid] = floatstr(data);
	mysql_fetch_field("max_amount", data);
	max_amount[playerid] = strval(data);
	mysql_fetch_field("lager", data);
	lager[playerid] = strval(data);
	mysql_free_result();
	ts_mission_id[playerid] = 90;
	if(max_amount[playerid] > 99000)
	{ 
		format(output, sizeof(output),"*** Fahre zum Flughafen in Los Santos um Produkte zu laden ***", name, lager);
		SetPlayerCheckpoint(playerid, CP_AIRPORT_LS, 6);
		format(query, sizeof(query), "UPDATE trucker_biz SET cur_amount = (cur_amount + 1000) WHERE biz_id = 8;");
		mysql_query(query);
		MissionActive[playerid] = true;
	}
	else
	{ 
		format(output, sizeof(output),"*** Es werden derzeit keine Produkte in Los Santos benötigt. ***");
	}
	SendClientMessage(playerid, COLOR_TRUCKER, output);
	return 1;
}
public GetProdSFMission(playerid)
{ 			
	new query[256], output[128], data[128], name[128];
	format(query, sizeof(query), "SELECT biz_name, ek_einzel, max_amount, max_amount - cur_amount AS lager FROM `trucker_biz` WHERE biz_id = 10;");
	mysql_query(query);
	mysql_store_result();
	mysql_fetch_row(data);
	mysql_fetch_field("biz_name", data);
	name = data;
	mysql_fetch_field("ek_einzel", data);
	ek_einzel[playerid] = floatstr(data);
	mysql_fetch_field("max_amount", data);
	max_amount[playerid] = strval(data);
	mysql_fetch_field("lager", data);
	lager[playerid] = strval(data);
	mysql_free_result();
	ts_mission_id[playerid] = 90;
	if(max_amount[playerid] > 99000)
	{ 
		format(output, sizeof(output),"*** Fahre zum Flughafen in San Fierro um Produkte zu laden ***", name, lager);
		SetPlayerCheckpoint(playerid, CP_AIRPORT_SF, 6);
		format(query, sizeof(query), "UPDATE trucker_biz SET cur_amount = (cur_amount + 1000) WHERE biz_id = 10;");
		mysql_query(query);
		MissionActive[playerid] = true;
	}
	else
	{ 
		format(output, sizeof(output),"*** Es werden derzeit keine Produkte in San Fierro benötigt. ***");
	}
	SendClientMessage(playerid, COLOR_TRUCKER, output);
	return 1;
}
public GetProdLVMission(playerid)
{ 			
	new query[256], output[128], data[128], name[128];
	format(query, sizeof(query), "SELECT biz_name, ek_einzel, max_amount, max_amount - cur_amount AS lager FROM `trucker_biz` WHERE biz_id = 12;");
	mysql_query(query);
	mysql_store_result();
	mysql_fetch_row(data);
	mysql_fetch_field("biz_name", data);
	name = data;
	mysql_fetch_field("ek_einzel", data);
	ek_einzel[playerid] = floatstr(data);
	mysql_fetch_field("max_amount", data);
	max_amount[playerid] = strval(data);
	mysql_fetch_field("lager", data);
	lager[playerid] = strval(data);
	mysql_free_result();
	ts_mission_id[playerid] = 90;
	if(max_amount[playerid] > 99000)
	{ 
		format(output, sizeof(output),"*** Fahre zum Flughafen in Las Venturas um Produkte zu laden ***", name, lager);
		SetPlayerCheckpoint(playerid, CP_AIRPORT_LV, 6);
		format(query, sizeof(query), "UPDATE trucker_biz SET cur_amount = (cur_amount + 1000) WHERE biz_id = 12;");
		mysql_query(query);
		MissionActive[playerid] = true;
	}
	else
	{ 
		format(output, sizeof(output),"*** Es werden derzeit keine Produkte in Las Venturas benötigt. ***");
	}
	SendClientMessage(playerid, COLOR_TRUCKER, output);
	return 1;
}
public GetTsMission(playerid)
{ 
	if( MissionActive[playerid] == 0)
	{
		new query[256], output[64], ts_name[25], ts_bedarf, data[128];
		format(query, sizeof(query), "SELECT ts_id, ts_name, ek_diesel, max_diesel - cur_diesel AS bedarf FROM `tankstellen` ORDER BY bedarf DESC;");
		mysql_query(query);
		mysql_store_result();
		mysql_fetch_field("ts_name",ts_name);
		mysql_fetch_field("ek_diesel", data);
		ts_ekpreis[playerid] = floatstr(data);
		mysql_fetch_field("bedarf",data);
		ts_bedarf = strval(data);
		mysql_fetch_field("ts_id", data);
		ts_mission_id[playerid] = strval(data);
		mysql_free_result();
		if(ts_bedarf > 2000)
		{ 
			format(output,100,"*** %s benötigt %i Liter Kraftstoff. ***", ts_name, ts_bedarf);
			SetPlayerCheckpoint(playerid, CP_RAFFINERIE, 6);
			format(query, sizeof(query), "UPDATE tankstellen SET cur_diesel = (cur_diesel + 1000) WHERE `ts_id`='%i';", ts_mission_id[playerid]);
			mysql_query(query);
			MissionActive[playerid] = true;
			ts_bedarf = ts_bedarf - 1000;
		}
		else
		{ 
			format(output,100,"*** Zurzeit wird kein Kraftstoff benötigt");
		}
		SendClientMessage(playerid, COLOR_TRUCKER, output);
		return 1;
	}
	else
	{
		SendClientMessage(playerid, COLOR_TRUCKER, "*** Es ist bereits eine Mission aktiv. ***");
		return 0;
	}
}
public StartTSMission(playerid)
{
	if(ts_mission_id[playerid] < 999)
	{ 
		switch(MissionActive[playerid])
		{ 	
			case 1:
				{ 
				DisablePlayerCheckpoint(playerid);
				CurrentTrailer[playerid] = GetVehicleTrailer(GetPlayerVehicleID(playerid));
				TogglePlayerControllable(playerid, false);
				GameTextForPlayer(playerid, "Fahrzeug wird beladen", 3000, 3);
				while(TrailerLoad[playerid] < 1000)
				{
					TrailerLoad[playerid]++;
					format(tls,50,"Ladung: ~p~%i",TrailerLoad[playerid]);
					TextDrawSetString(KM[playerid],tls);
					TextDrawShowForPlayer(playerid,KM[playerid]);
				}
				switch(ts_mission_id[playerid])
				{ 
					
					case 0:	{ 
										if(GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(playerid))) == 584)
											SetPlayerCheckpoint(playerid, Alhambra_Station,6);
										else
											SendClientMessage(playerid, COLOR_TRUCKER, "*** Sie haben den falschen Anhänger ***");
									}
					case 1: { 
										if(GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(playerid))) == 584)
											SetPlayerCheckpoint(playerid, BSN_Station,6);}
					case 2: { 
										if(GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(playerid))) == 584)
											SetPlayerCheckpoint(playerid, RSHaul_Station,6);
										else
											SendClientMessage(playerid, COLOR_TRUCKER, "*** Sie haben den falschen Anhänger ***");
									}
					case 3: { 
										if(GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(playerid))) == 584)
											SetPlayerCheckpoint(playerid, Dillimore_Station,6);
										else
											SendClientMessage(playerid, COLOR_TRUCKER, "*** Sie haben den falschen Anhänger ***");
									}
					case 4: { 
										if(GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(playerid))) == 584)
											SetPlayerCheckpoint(playerid, Montgomery_Station,6);
										else
											SendClientMessage(playerid, COLOR_TRUCKER, "*** Sie haben den falschen Anhänger ***");
									}
					case 5: { 
										if(GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(playerid))) == 584)
											SetPlayerCheckpoint(playerid, AngelPine_Station,6);
										else
											SendClientMessage(playerid, COLOR_TRUCKER, "*** Sie haben den falschen Anhänger ***");
									}
					case 6: { 
										if(GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(playerid))) == 584)
											SetPlayerCheckpoint(playerid, Whetstone_Station,6);
										else
											SendClientMessage(playerid, COLOR_TRUCKER, "*** Sie haben den falschen Anhänger ***");
									}
					case 7: { 
										if(GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(playerid))) == 584)
											SetPlayerCheckpoint(playerid, Doherty_Station,6);
										else
											SendClientMessage(playerid, COLOR_TRUCKER, "*** Sie haben den falschen Anhänger ***");
									}
					case 8: { 
										if(GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(playerid))) == 584)
											SetPlayerCheckpoint(playerid, EasterBasin_Station,6);
										else
											SendClientMessage(playerid, COLOR_TRUCKER, "*** Sie haben den falschen Anhänger ***");
									}
					case 9: { 
										if(GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(playerid))) == 584)
											SetPlayerCheckpoint(playerid, JuniperHill_Station,6);
										else
											SendClientMessage(playerid, COLOR_TRUCKER, "*** Sie haben den falschen Anhänger ***");
									}
					case 10: { 
											if(GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(playerid))) == 584)
												SetPlayerCheckpoint(playerid, TierraRobada_Station,6);
											else
												SendClientMessage(playerid, COLOR_TRUCKER, "*** Sie haben den falschen Anhänger ***");
										}
					case 11: { 
											if(GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(playerid))) == 584)
												SetPlayerCheckpoint(playerid, ElQuebrados_Station,6);
											else
												SendClientMessage(playerid, COLOR_TRUCKER, "*** Sie haben den falschen Anhänger ***");
										}
					case 12: { 
											if(GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(playerid))) == 584)
												SetPlayerCheckpoint(playerid, BoneCountry_Station,6);
											else
												SendClientMessage(playerid, COLOR_TRUCKER, "*** Sie haben den falschen Anhänger ***");
										}
					case 13: { 
											if(GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(playerid))) == 584)
												SetPlayerCheckpoint(playerid, FortCarson_Station,6);
											else
												SendClientMessage(playerid, COLOR_TRUCKER, "*** Sie haben den falschen Anhänger ***");
									}
					case 14: { 
											if(GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(playerid))) == 584)
												SetPlayerCheckpoint(playerid, ComeALot_Station,6);
											else
												SendClientMessage(playerid, COLOR_TRUCKER, "*** Sie haben den falschen Anhänger ***");
									}
					case 15: { 
											if(GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(playerid))) == 584)
												SetPlayerCheckpoint(playerid, xxx,6);
											else
												SendClientMessage(playerid, COLOR_TRUCKER, "*** Sie haben den falschen Anhänger ***");
									}
					case 16: { 
											if(GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(playerid))) == 584)
												SetPlayerCheckpoint(playerid, RedsandsWest_Station,6);
											else
												SendClientMessage(playerid, COLOR_TRUCKER, "*** Sie haben den falschen Anhänger ***");
										}
					case 17: { 
											if(GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(playerid))) == 584)
												SetPlayerCheckpoint(playerid, Emerald_Station,6);
											else
												SendClientMessage(playerid, COLOR_TRUCKER, "*** Sie haben den falschen Anhänger ***");
										}
					case 18: { 
											if(GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(playerid))) == 584)
												SetPlayerCheckpoint(playerid, Spinybed_Station,6);
											else
												SendClientMessage(playerid, COLOR_TRUCKER, "*** Sie haben den falschen Anhänger ***");
										}
					case 19: { 
											if(GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(playerid))) == 584)
												SetPlayerCheckpoint(playerid, Flughafen_SF,6);
											else
												SendClientMessage(playerid, COLOR_TRUCKER, "*** Sie haben den falschen Anhänger ***");
										}
					case 40: { 
											if(GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(playerid))) == 435)
												SetPlayerCheckpoint(playerid, CP_PROD_LS,6);
											else
												SendClientMessage(playerid, COLOR_TRUCKER, "*** Sie haben den falschen Anhänger ***");
										}
					case 50: { 
											if(GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(playerid))) == 435)
												SetPlayerCheckpoint(playerid, CP_PROD_SF,6);
											else
												SendClientMessage(playerid, COLOR_TRUCKER, "*** Sie haben den falschen Anhänger ***");
										}
					case 60: { 
											if(GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(playerid))) == 435)
												SetPlayerCheckpoint(playerid, CP_PROD_LV,6);
											else
												SendClientMessage(playerid, COLOR_TRUCKER, "*** Sie haben den falschen Anhänger ***");
									 }
					case 70: { 
											if(GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(playerid))) == 584)
												SetPlayerCheckpoint(playerid, CP_RAFFINERIE,6);
											else
												SendClientMessage(playerid, COLOR_TRUCKER, "*** Sie haben den falschen Anhänger ***");
										}
					case 80: { 
											if(GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(playerid))) == 435)
												SetPlayerCheckpoint(playerid, CP_LVDEPOT,6);
											else
												SendClientMessage(playerid, COLOR_TRUCKER, "*** Sie haben den falschen Anhänger ***");
										}
					case 90: { 
											if(GetVehicleModel(GetVehicleTrailer(GetPlayerVehicleID(playerid))) == 591)
												SetPlayerCheckpoint(playerid, CP_SFFISCH,6);
											else
												SendClientMessage(playerid, COLOR_TRUCKER, "*** Sie haben den falschen Anhänger ***");
										}
				}
				MissionActive[playerid] = 2;
				TogglePlayerControllable(playerid, true);
			}
			
			case 2:
			{ 		
				if(GetVehicleTrailer(GetPlayerVehicleID(playerid)) > 0)
				{
					new query[256], query2[256];
					GameTextForPlayer(playerid, "~w~PayDay-Punkt~n~erhalten!",3, 1);
					playerdata[playerid][9]++;
					TogglePlayerControllable(playerid, false);
					while(TrailerLoad[playerid] > 0)
					{
						TrailerLoad[playerid] = TrailerLoad[playerid] - 1;
						format(tls,50,"Ladung: ~p~%i",TrailerLoad[playerid]);
						TextDrawSetString(KM[playerid],tls);
						TextDrawShowForPlayer(playerid,KM[playerid]);
					}
					GameTextForPlayer(playerid, "Fahrzeug wird entladen", 3000, 3);
					switch(ts_mission_id[playerid])
					{ 
						case 0: { mission_cash[playerid] = ts_ekpreis[playerid] * TrailerLoad[playerid]; playerdata[playerid][8] = playerdata[playerid][8] + 2;}
						case 1: { mission_cash[playerid] = ts_ekpreis[playerid] * TrailerLoad[playerid]; playerdata[playerid][8] = playerdata[playerid][8] + 2;}
						case 2: { mission_cash[playerid] = ts_ekpreis[playerid] * TrailerLoad[playerid]; playerdata[playerid][8] = playerdata[playerid][8] + 2;}
						case 3: { mission_cash[playerid] = ts_ekpreis[playerid] * TrailerLoad[playerid]; playerdata[playerid][8] = playerdata[playerid][8] + 2;}
						case 4: { mission_cash[playerid] = ts_ekpreis[playerid] * TrailerLoad[playerid]; playerdata[playerid][8] = playerdata[playerid][8] + 2;}
						case 5: { mission_cash[playerid] = ts_ekpreis[playerid] * TrailerLoad[playerid]; playerdata[playerid][8] = playerdata[playerid][8] + 2;}
						case 6: { mission_cash[playerid] = ts_ekpreis[playerid] * TrailerLoad[playerid]; playerdata[playerid][8] = playerdata[playerid][8] + 2;}
						case 7: { mission_cash[playerid] = ts_ekpreis[playerid] * TrailerLoad[playerid]; playerdata[playerid][8] = playerdata[playerid][8] + 2;}
						case 8: { mission_cash[playerid] = ts_ekpreis[playerid] * TrailerLoad[playerid]; playerdata[playerid][8] = playerdata[playerid][8] + 2;}
						case 9: { mission_cash[playerid] = ts_ekpreis[playerid] * TrailerLoad[playerid]; playerdata[playerid][8] = playerdata[playerid][8] + 2;}
						case 10: { mission_cash[playerid] = ts_ekpreis[playerid] * TrailerLoad[playerid]; playerdata[playerid][8] = playerdata[playerid][8] + 2;}
						case 11: { mission_cash[playerid] = ts_ekpreis[playerid] * TrailerLoad[playerid]; playerdata[playerid][8] = playerdata[playerid][8] + 2;}
						case 12: { mission_cash[playerid] = ts_ekpreis[playerid] * TrailerLoad[playerid]; playerdata[playerid][8] = playerdata[playerid][8] + 2;}
						case 13: { mission_cash[playerid] = ts_ekpreis[playerid] * TrailerLoad[playerid]; playerdata[playerid][8] = playerdata[playerid][8] + 2;}
						case 14: { mission_cash[playerid] = ts_ekpreis[playerid] * TrailerLoad[playerid]; playerdata[playerid][8] = playerdata[playerid][8] + 2;}
						case 15: { mission_cash[playerid] = ts_ekpreis[playerid] * TrailerLoad[playerid]; playerdata[playerid][8] = playerdata[playerid][8] + 2;}
						case 16: { mission_cash[playerid] = ts_ekpreis[playerid] * TrailerLoad[playerid]; playerdata[playerid][8] = playerdata[playerid][8] + 2;}
						case 17: { mission_cash[playerid] = ts_ekpreis[playerid] * TrailerLoad[playerid]; playerdata[playerid][8] = playerdata[playerid][8] + 2;}
						case 18: { mission_cash[playerid] = ts_ekpreis[playerid] * TrailerLoad[playerid]; playerdata[playerid][8] = playerdata[playerid][8] + 2;}
						case 19: { mission_cash[playerid] = ts_ekpreis[playerid] * TrailerLoad[playerid]; playerdata[playerid][8] = playerdata[playerid][8] + 2;}
						case 20: { mission_cash[playerid] = ts_ekpreis[playerid] * TrailerLoad[playerid]; playerdata[playerid][8] = playerdata[playerid][8] + 4;}
						case 40: { mission_cash[playerid] = ts_ekpreis[playerid] * TrailerLoad[playerid]; playerdata[playerid][8] = playerdata[playerid][8] + 3;}
						case 50: { mission_cash[playerid] = ts_ekpreis[playerid] * TrailerLoad[playerid]; playerdata[playerid][8] = playerdata[playerid][8] + 3;}
						case 60: { mission_cash[playerid] = ts_ekpreis[playerid] * TrailerLoad[playerid]; playerdata[playerid][8] = playerdata[playerid][8] + 3;}
						case 70: { mission_cash[playerid] = ek_einzel[playerid] * TrailerLoad[playerid]; playerdata[playerid][8] = playerdata[playerid][8] + 3;}
						case 80: { mission_cash[playerid] = ek_einzel[playerid] * TrailerLoad[playerid]; playerdata[playerid][8] = playerdata[playerid][8] + 3;}
						case 90: { mission_cash[playerid] = ek_einzel[playerid] * TrailerLoad[playerid]; playerdata[playerid][8] = playerdata[playerid][8] + 3;}
					}
					DisablePlayerCheckpoint(playerid);
					GivePlayerMoney(playerid,PROVISION);
					if(ts_mission_id[playerid] > 0 && ts_mission_id[playerid] < 39)
					{ 
						format(query, sizeof(query), "UPDATE tankstellen SET cur_cash = (cur_cash - %f) WHERE `ts_id`='%i';", mission_cash[playerid], ts_mission_id[playerid]);
						format(query2, sizeof(query2), "UPDATE trucker_biz SET biz_cash = (biz_cash + %f) WHERE `biz_id`='1';", mission_cash[playerid], ts_mission_id[playerid]);
					}
					else if(ts_mission_id[playerid] > 39 && ts_mission_id[playerid] < 49)
					{ 
						format(query, sizeof(query), "UPDATE trucker_biz SET biz_cash = (biz_cash - %f) WHERE `biz_id`= 8;", mission_cash[playerid]);
						format(query2, sizeof(query2), "UPDATE trucker_biz SET biz_cash = (biz_cash + (%f - %i)) WHERE `biz_id`= 7;", mission_cash[playerid], PROVISION);
					}
					else if(ts_mission_id[playerid] > 49 && ts_mission_id[playerid] < 59)
					{ 
						format(query, sizeof(query), "UPDATE trucker_biz SET biz_cash = (biz_cash - %f) WHERE `biz_id`= 10;", mission_cash[playerid]);
						format(query2, sizeof(query2), "UPDATE trucker_biz SET biz_cash = (biz_cash + (%f - %i)) WHERE `biz_id`= 9;", mission_cash[playerid], PROVISION);
					}
					else if(ts_mission_id[playerid] > 59 && ts_mission_id[playerid] < 69)
					{ 
						format(query, sizeof(query), "UPDATE trucker_biz SET biz_cash = (biz_cash - %f) WHERE `biz_id`= 12;", mission_cash[playerid]);
						format(query2, sizeof(query2), "UPDATE trucker_biz SET biz_cash = (biz_cash + (%f - %i)) WHERE `biz_id`= 11;", mission_cash[playerid], PROVISION);
					}
					else if(ts_mission_id[playerid] > 69 && ts_mission_id[playerid] < 79)
					{ 
						format(query, sizeof(query), "UPDATE trucker_biz SET biz_cash = (biz_cash - %f) WHERE `biz_id`= 1;", mission_cash[playerid]);
						format(query2, sizeof(query2), "UPDATE trucker_biz SET biz_cash = (biz_cash + (%f - %i)) WHERE `biz_id`= 2;", mission_cash[playerid], PROVISION);
					}
					else if(ts_mission_id[playerid] > 79 && ts_mission_id[playerid] < 89)
					{ 
						format(query, sizeof(query), "UPDATE trucker_biz SET biz_cash = (biz_cash - %f) WHERE `biz_id`= 4;", mission_cash[playerid]);
						format(query2, sizeof(query2), "UPDATE trucker_biz SET biz_cash = (biz_cash + (%f - %i)) WHERE `biz_id`= 3;", mission_cash[playerid], PROVISION);
					}
					else if(ts_mission_id[playerid] > 89 && ts_mission_id[playerid] < 99)
					{ 
						format(query, sizeof(query), "UPDATE trucker_biz SET biz_cash = (biz_cash - %f) WHERE `biz_id`= 6;", mission_cash[playerid]);
						format(query2, sizeof(query2), "UPDATE trucker_biz SET biz_cash = (biz_cash + (%f - %i)) WHERE `biz_id`= 5;", mission_cash[playerid], PROVISION);
					}
					mysql_query(query);
					mysql_query(query2);
					format(query, sizeof(query),"*** Provision erhalten: %i EUR ***", PROVISION);
					SendClientMessage(playerid, COLOR_TRUCKER, query);
					TrailerLoad[playerid] = 0;
					ts_mission_id[playerid] = 0;
					MissionActive[playerid] = 0;
					TruckerStartWork(playerid);
				}
				else
					SendClientMessage(playerid, COLOR_TRUCKER, "Den Anhänger solltest du schon mitnehmen, Trottel!");
			}
		}
	}
	else if(!IsTrailerAttachedToVehicle(GetPlayerVehicleID(playerid))&& ts_mission_id[playerid] < 999)
	{ 
		SendClientMessage(playerid, COLOR_TRUCKER, "*** Kein Anhänger! ***");
	}
	else if(ts_mission_id[playerid] == 999)
	{ 
		printf("%i", IsTrailerAttachedToVehicle(GetPlayerVehicleID(playerid)));
		DisablePlayerCheckpoint(playerid);
		print("Anhänger abkuppeln...");
		SetVehicleToRespawn(GetVehicleTrailer(GetPlayerVehicleID(playerid)));
		ts_mission_id[playerid] = 1000;
		TruckerStopWork(playerid);
	}
	else if(ts_mission_id[playerid] == 1000)
	{
		DisablePlayerCheckpoint(playerid);
		print("Truck auftanken...");
		new string[128];
		new tr_tanken, tr_rep = 0;
		
		format(string, sizeof(string),"%i", GetPlayerVehicleID(playerid));
		print(string);
		tr_tanken = Fahrzeugdaten[GetVehicleModel(GetPlayerVehicleID(playerid)) - 400][0] - floatround(Fahrzeuge[GetPlayerVehicleID(playerid)][0]);
		Fahrzeuge[GetPlayerVehicleID(playerid)][0] = float(Fahrzeugdaten[GetVehicleModel(GetPlayerVehicleID(playerid)) - 400][0]);
		format(string, sizeof(string), "*** Ihr Fahrzeug wurde mit %i Litern aufgetankt ***", tr_tanken);
		SendClientMessage(playerid, COLOR_TRUCKER, string);
		
		print("Truck reparieren...");
		tr_rep = 1000 - floatround(Fahrzeuge[GetPlayerVehicleID(playerid)][1]);
		tr_rep = tr_rep * (-1);
		Fahrzeuge[GetPlayerVehicleID(playerid)][1] = 1000.0;
		giveusermoney(playerid, tr_rep);
		format(string, sizeof(string), "*** Ihr Fahrzeug wurde auf Ihre Kosten repariert ***");
		SendClientMessage(playerid, COLOR_TRUCKER, string);
		
		print("Truck zurücksetzen...");
		SetVehicleToRespawn(GetPlayerVehicleID(playerid)); 
	}
	else
	{ 
		SendClientMessage(playerid, COLOR_TRUCKER, "*** Falscher Anhänger! ***");
	}
	
}
public CancelTsMission(playerid)
{ 
	new query[256];
	DisablePlayerCheckpoint(playerid);
	SendClientMessage(playerid, COLOR_TRUCKER, "*** Der Auftrag wurde zurückgesetzt ***");
	MissionActive[playerid] = 0;
	if(ts_mission_id[playerid] > 0 && ts_mission_id[playerid] < 70)
	{ 
		format(query, sizeof(query), "UPDATE tankstellen SET cur_diesel = (cur_diesel - 1000) WHERE `ts_id`='%i';", ts_mission_id[playerid]);
	}
	else if(ts_mission_id[playerid] > 69 && ts_mission_id[playerid] < 79)
	{ 
		format(query, sizeof(query), "UPDATE trucker_biz SET cur_amount = (cur_amount - 1000) WHERE biz_id = 1;");
	}
	else if(ts_mission_id[playerid] > 79 && ts_mission_id[playerid] < 89)
	{ 
		format(query, sizeof(query), "UPDATE trucker_biz SET cur_amount = (cur_amount - 1000) WHERE biz_id = 4;");
	}
	else if(ts_mission_id[playerid] > 89 && ts_mission_id[playerid] < 99)
	{ 
		format(query, sizeof(query), "UPDATE trucker_biz SET cur_amount = (cur_amount - 1000) WHERE biz_id = 6;");
	}
	else if(ts_mission_id[playerid] > 39 && ts_mission_id[playerid] < 49)
	{ 
		format(query, sizeof(query), "UPDATE trucker_biz SET cur_amount = (cur_amount - 1000) WHERE biz_id = 8;");
	}
	else if(ts_mission_id[playerid] > 49 && ts_mission_id[playerid] < 59)
	{ 
		format(query, sizeof(query), "UPDATE trucker_biz SET cur_amount = (cur_amount - 1000) WHERE biz_id = 10;");
	}
	else if(ts_mission_id[playerid] > 59 && ts_mission_id[playerid] < 69)
	{ 
		format(query, sizeof(query), "UPDATE trucker_biz SET cur_amount = (cur_amount - 1000) WHERE biz_id = 12;");
	}
	mysql_query(query);
}
public trucker_biz_timer()
{ 
	print("*** Automatischer Verkauf ***.");
	new query[512];
	format(query, sizeof(query), "UPDATE trucker_biz SET cur_amount = (cur_amount + 1000), biz_cash = biz_cash - 1000 * ek_einzel WHERE cur_amount < max_amount AND biz_id = 2;");
	mysql_query(query);
	format(query, sizeof(query), "UPDATE trucker_biz SET cur_amount = (cur_amount + 1000), biz_cash = biz_cash - 1000 * ek_einzel WHERE cur_amount < max_amount AND biz_id = 3;");
	mysql_query(query);
	format(query, sizeof(query), "UPDATE trucker_biz SET cur_amount = (cur_amount + 1000), biz_cash = biz_cash - 1000 * ek_einzel WHERE cur_amount < max_amount AND biz_id = 5;");
	mysql_query(query);
	format(query, sizeof(query), "UPDATE tankstellen SET `cur_diesel` = `cur_diesel` -500,`cur_cash`=`cur_cash`+(500*((`vk_super`+`vk_normal`+`vk_diesel`)/3)) WHERE cur_diesel > 1500 AND ts_id != 19 ORDER BY cur_diesel DESC LIMIT 5");
	mysql_query(query);
	format(query, sizeof(query), "UPDATE burgershot SET `bestand` = `bestand`-20,`kontostand`=`kontostand`+(2*(`preis3`+`preis2`+`preis1`)) WHERE `bestand` > 150 ORDER BY `bestand` DESC LIMIT 3");
	mysql_query(query);
} 