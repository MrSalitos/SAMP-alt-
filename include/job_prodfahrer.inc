#define COLOR_PRODFAHRER 0xFFB400FF
#define PRODCAR_LS GetPlayerVehicleID(playerid) == prod_car[0][0] || GetPlayerVehicleID(playerid) == prod_car[0][1] || GetPlayerVehicleID(playerid) == prod_car[0][2]
#define PRODCAR_SF GetPlayerVehicleID(playerid) == prod_car[1][0] || GetPlayerVehicleID(playerid) == prod_car[1][1] || GetPlayerVehicleID(playerid) == prod_car[1][2]
#define PRODCAR_LV GetPlayerVehicleID(playerid) == prod_car[2][0] || GetPlayerVehicleID(playerid) == prod_car[2][1] || GetPlayerVehicleID(playerid) == prod_car[2][2]
/* ****************** Laderampen  ****************** */
#define LOAD_LS_01 1123.5, -1330.0, 13.5
#define LOAD_LS_02 1110.5, -1330.0, 13.5
#define LOAD_LS_03 1097.5, -1330.0, 13.5
#define LOAD_SF_01 -1885.0, -200.0, 16.5
#define LOAD_LV_01 2825.0, 969.0, 11.0
#define LOAD_LV_02 2805.0, 969.0, 11.0
#define LOAD_LV_03 2843.5, 974.0, 11.0
/* ****************** Anlieferungspunkte ****************** */
new Float:ProdCheckpoints[][3] = {
	{ 1178.50, -901.72, 43.32 },
	{ 788.48, -1622.71, 13.39 },
	{ -2319.20, -152.73, 35.55 },
	{ -1905.62, 822.56, 35.01 },
	{ -2348.52, 991.75, 50.70 },
	{ 1139.81, 2071.94, 11.06 },
	{ 2156.51, 2799.13, 10.82 },
	{ 1888.84, 2087.54, 11.06 },
	{ 2360.96, 2076.01, 10.67 },
	{ 2456.17, 2017.54, 11.06 },
	{ 2391.50, -1896.00, 13.38 },
	{ 2422.08, -1498.71, 23.99 },
	{ -2160.13, -2461.67, 30.63 },
	{ -2664.89, 267.17, 4.33 },
	{ -1812.24, 614.57, 35.17 },
	{ -1209.25, 1830.02, 41.71 },
	{ 178.43, 1171.61, 14.75 },
	{ 2631.35, 1677.97, 10.82 },
	{ 2398.55, 2045.68, 10.82 },
	{ 2105.89, 2227.05, 11.02 },
	{ 2839.96, 2399.99, 10.82 },
	{ 2099.89, -1809.15, 13.55 },
	{ 2337.39, 75.04, 26.47 },
	{ 1361.85, 252.35, 19.56 },
	{ 203.01, -206.77, 1.57 },
	{ -1812.06, 937.26, 24.74 },
	{ -1720.86, 1354.42, 7.17 },
	{ 2631.50, 1848.95, 10.82 },
	{ 2079.24, 2221.89, 10.82 },
	{ 2345.56, 2529.26, 10.82 },
	{ 2755.38, 2471.35, 10.82 },
	{ 1834.10, -1690.17, 13.44 },
	{ 2305.32, -1643.32, 14.48 },
	{ 2852.83, -1528.75, 11.09 },
	{ 377.44, -1827.42, 7.83 },
	{ 568.76, -1389.97, 14.60 },
	{ 680.95, -443.32, 16.33 },
	{ 290.41, -186.30, 1.57 },
	{ -2245.44, -90.55, 35.32 },
	{ -2454.90, 129.97, 35.17 },
	{ -2554.68, 190.37, 6.01 },
	{ -2520.15, 1216.92, 37.42 },
	{ -1936.11, 2380.10, 49.49 },
	{ -853.21, 1534.17, 22.40 },
	{ -85.59, 1380.11, 10.27 },
	{ -50.04, 1191.42, 19.35 },
	{ 2492.98, 1219.07, 10.82 },
	{ 2360.36, 1987.33, 10.67 },
	{ 2437.11, 2060.91, 10.82 },
	{ 2486.75, 2061.13, 10.82 },
	{ 1689.53, 2205.01, 10.82 },
	{ 1380.86, 2323.61, 10.82 },
	{ 1033.97, -1335.21, 13.54 },
 	{ -148.21, 1220.06, 19.74 },
	{ 2247.62, -1662.89, 15.46 },
	{ -2378.05, 907.84, 45.44 },
	{ 1654.20, 1738.05, 10.82 },
	{ 2106.15, 2256.97, 11.02 },
	{ 503.34, -1358.93, 16.12 },
	{ 2822.55, 2403.53, 10.82 },
	{ 1458.19, -1139.89, 24.06 },
	{ -1889.06, 866.80, 35.16 },
	{ 2573.28, 1898.11, 10.82 },
	{ 2090.69, 2221.07, 10.82 },
	{ 2110.11, -1213.86, 23.96 },
	{ -2493.64, -27.21, 25.76 },
	{ 2775.07, 2450.86, 10.82 },
	{ 457.11, -1497.89, 31.06 },
	{ -1697.67, 947.70, 24.89 },
	{ 2799.14, 2425.41, 10.82 },
	{ 451.36, -1475.15, 30.70 },
	{ -1564.09, -2735.88, 48.54 },
	{ 998.13, -917.90, 42.17 },
	{ 1313.48, -909.62, 38.37 },
	{ 1352.56, -1755.14, 13.35 },
	{ 1829.72, -1840.52, 13.57 },
	{ -183.04, 1038.05, 19.74 },
	{ 1934.71, 2310.00, 10.82 },
	{ 2097.73, 2222.10, 10.82 },
	{ 2235.71, 2398.55, 10.82 },
	{ 2187.13, 1991.76, 10.82 },
	{ 2455.67, 2060.66, 10.82 },
	{ 2545.49, 1969.45, 10.82 },
	{ 2888.95, 2449.83, 10.82 }
};

forward prodfahrer();
forward CheckProdCar(playerid);
forward GetProdMission(playerid, zone[]);
forward ProdfahrerSF(playerid);
forward ProdfahrerLV(playerid);
forward ProdfahrerCheckpoints(playerid);

new prod_car[3][3];
new prod_mission_id[MAX_PLAYERS];
new Float:prod_ekpreis[MAX_PLAYERS];
new ProdMission[MAX_PLAYERS][2];
new shopID[MAX_PLAYERS];
public prodfahrer()
{
	// Los Santos
	Create3DTextLabel("Anlieferung", COLOR_WHITE, CP_PROD_LS, 35.0, 0);
	prod_car[0][2] = CreateVehicleEx(456, 1097.5, -1326.0, 13.5, 0.0, 105, 0, 300);
	prod_car[0][1] = CreateVehicleEx(456, 1110.5, -1326.0, 13.5, 0.0, 105, 0, 300);
	prod_car[0][0] = CreateVehicleEx(456, 1123.5, -1326.0, 13.5, 0.0, 105, 0, 300);
	// San Fierro
	Create3DTextLabel("Anlieferung", COLOR_WHITE, CP_PROD_SF, 35.0, 0);
	prod_car[1][0] = CreateVehicleEx(456, -1850.0, -195.0, 18.5, 180.0, 105, 0, 300);
	prod_car[1][1] = CreateVehicleEx(456, -1855.0, -195.0, 18.5, 180.0, 105, 0, 300);
	prod_car[1][2] = CreateVehicleEx(456, -1875.0, -190.0, 18.5, 200.0, 105, 0, 300);
	// Las Venturas
	Create3DTextLabel("Anlieferung", COLOR_WHITE, CP_PROD_LV, 35.0, 0);
	prod_car[2][0] = CreateVehicleEx(456, 2810.0, 969.0, 11.0, 180.0, 105, 0, 300);
	prod_car[2][1] = CreateVehicleEx(456, 2805.0, 969.0, 11.0, 180.0, 105, 0, 300);
	prod_car[2][2] = CreateVehicleEx(456, 2843.5, 974.0, 11.0,  90.0, 105, 0, 300);
	
} 
public CheckProdCar(playerid)
{
	
	if(GetPlayerVehicleID(playerid) == prod_car[0][0] || GetPlayerVehicleID(playerid) == prod_car[0][1] || GetPlayerVehicleID(playerid) == prod_car[0][2])
		return 1;
	if(GetPlayerVehicleID(playerid) == prod_car[1][0] || GetPlayerVehicleID(playerid) == prod_car[1][1] || GetPlayerVehicleID(playerid) == prod_car[1][2])
		return 2;
	if(GetPlayerVehicleID(playerid) == prod_car[2][0] || GetPlayerVehicleID(playerid) == prod_car[2][1] || GetPlayerVehicleID(playerid) == prod_car[2][2])
		return 3;
	return 0;
}
public GetProdMission(playerid, zone[])
{
	new query[256], data[128], bestand = 0;
	format(query, sizeof(query), "SELECT bestand, shopID, preis_ek FROM burgershot WHERE Zone LIKE '' AND bestand < 150 AND shopID < 91 ORDER BY bestand ASC LIMIT 0,1;",zone);
	if(!strcmp(zone, "LS", true))
  {
		strins(query, "LS", 66);
	}
	if(!strcmp(zone, "SF", true))
  {
		strins(query, "SF", 66);
	}
	if(!strcmp(zone, "LV", true))
  {
		strins(query, "LV", 66);
	}
	mysql_query(query);
	mysql_store_result();
	mysql_fetch_row(data);
	mysql_fetch_field("bestand", data);
	bestand = strval(data);
	mysql_fetch_field("shopID", data);
	shopID[playerid] = strval(data);
	mysql_fetch_field("preis_ek", data);
	prod_ekpreis[playerid] = floatstr(data);

	printf("prod_ekpreis: %.2f", prod_ekpreis[playerid]);
	if(bestand < 150 && prod_ekpreis[playerid] >= 0.5)
	{
		GameTextForPlayer(playerid, "~w~Fahren Sie ~y~rueckwaerts~n~~w~an die Laderampe", 10000, 1);
		prod_mission_id[playerid] = shopID[playerid];
		for(new i = 0; i < sizeof(prod_car); i++)
		{
			if(GetPlayerVehicleID(playerid) == prod_car[0][i])
				SetPlayerCheckpoint(playerid, LOAD_LS_01, 5);	
			if(GetPlayerVehicleID(playerid) == prod_car[1][i])
				SetPlayerCheckpoint(playerid, LOAD_SF_01, 5);	
			if(GetPlayerVehicleID(playerid) == prod_car[2][i])
				SetPlayerCheckpoint(playerid, LOAD_LV_01, 5);	
		}
		format(query, sizeof(query), "UPDATE burgershot SET bestand = bestand + 150 WHERE shopID = '%i'", prod_mission_id[playerid]);
		mysql_query(query);
		ProdMission[playerid][0] = 150;
		ProdMission[playerid][1] = ProdMission[playerid][0] * floatround(prod_ekpreis[playerid]);
	}
	else
	{	
		SendClientMessage(playerid, COLOR_PRODFAHRER, "Zurzeit werden keine Produkte benötigt");
		RemovePlayerFromVehicle(playerid);
	}
}
public ProdfahrerCheckpoints(playerid)
{
	switch(MissionActive[playerid])
	{ 	
		case 0:
		{ 
			new Float:z;
			GetVehicleZAngle(GetPlayerVehicleID(playerid), z);
			if(CheckProdCar(playerid) == 1 && (z <= 10.0 && z >= 0.0) || (z <= 359.9 && z >= 350.0))
			{
				DisablePlayerCheckpoint(playerid);
				SetPlayerCheckpoint(playerid, ProdCheckpoints[shopID[playerid]-1][0], ProdCheckpoints[shopID[playerid]-1][1], ProdCheckpoints[shopID[playerid]-1][2], 6);
				TrailerLoad[playerid] = 150;
				MissionActive[playerid] = true;
			}
			if(CheckProdCar(playerid) == 2 && z < 280.0 && z > 260.0)
			{
				DisablePlayerCheckpoint(playerid);
				SetPlayerCheckpoint(playerid, ProdCheckpoints[shopID[playerid]-1][0], ProdCheckpoints[shopID[playerid]-1][1], ProdCheckpoints[shopID[playerid]-1][2], 6);
				TrailerLoad[playerid] = 150;
				MissionActive[playerid] = true;
			}
			if(CheckProdCar(playerid) == 3 && z < 190.0 && z > 170.0)
			{
				DisablePlayerCheckpoint(playerid);
				SetPlayerCheckpoint(playerid, ProdCheckpoints[shopID[playerid]-1][0], ProdCheckpoints[shopID[playerid]-1][1], ProdCheckpoints[shopID[playerid]-1][2], 6);
				TrailerLoad[playerid] = 150;
				MissionActive[playerid] = true;
			}
			else GameTextForPlayer(playerid, "~w~Fahren Sie ~y~rueckwaerts~n~~w~an die Laderampe", 5000, 1);
			SendClientMessage(playerid, COLOR_PRODFAHRER, "*** Fahren Sie zum Punkt auf der Karte. ***");
		}
		case 1:
		{
			new output[128];
			DisablePlayerCheckpoint(playerid);
			format(output, sizeof(output), "UPDATE accounts SET paydaycount = paydaycount + 1, skillcount = skillcount + 2 WHERE accid = '%i'", playerdata[playerid][0]);
			mysql_query(output);
			new query[256];
			format(query, sizeof(query), "UPDATE burgershot SET kontostand = (kontostand - %f) WHERE shopID = '%i';", mission_cash[playerid], shopID[playerid]);
			mysql_query(query);
			if(CheckProdCar(playerid) == 1)
			{
				format(query, sizeof(query), "UPDATE trucker_biz SET biz_cash = (biz_cash + %f) WHERE biz_id = '8';", ProdMission[playerid][1]);
				mysql_query(query);
				GetProdMission(playerid, "LS");
				print("Fehler LS!");
			}
			if(CheckProdCar(playerid) == 2)
			{
				format(query, sizeof(query), "UPDATE trucker_biz SET biz_cash = (biz_cash + %f) WHERE biz_id = '10';", ProdMission[playerid][1]);
				mysql_query(query);
				GetProdMission(playerid, "SF");
				print("Fehler SF!");
			}
			if(CheckProdCar(playerid) == 3)
			{
				format(query, sizeof(query), "UPDATE trucker_biz SET biz_cash = (biz_cash + %f) WHERE biz_id = '12';", ProdMission[playerid][1]);
				mysql_query(query);
				GetProdMission(playerid, "LV");
				print("Fehler LV!");
			}
			GameTextForPlayer(playerid, "~w~PayDay-Punkt~n~erhalten!",3, 1);
			format(output, sizeof(output), "*** Sie haben %i $ Provision erhalten ***", floatround(ProdMission[playerid][1] / 10));
			giveusermoney(playerid, floatround(ProdMission[playerid][1] / 10));
			SendClientMessage(playerid, COLOR_PRODFAHRER, output);
			TrailerLoad[playerid] = 0;
			MissionActive[playerid] = false;
		}
	}
}
