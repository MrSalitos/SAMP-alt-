/* *********************************************************   Tanstellen-Variablen  ********************************************************* */
new pu_alh_01 = 0;
new pu_alh_02 = 0;
new pu_bsn_01 = 0;
new pu_bsn_02 = 0;
new pu_rsh_01 = 0;
new pu_rsh_02 = 0;
new pu_dil_01 = 0;
new pu_dil_02 = 0;
new pu_mon_01 = 0;
new pu_mon_02 = 0;
new pu_ang_01 = 0;
new pu_ang_02 = 0;
new pu_whe_01 = 0;
new pu_whe_02 = 0;
new pu_doh_01 = 0;
new pu_doh_02 = 0;
new pu_eas_01 = 0;
new pu_eas_02 = 0;
new pu_jun_01 = 0;
new pu_jun_02 = 0;
new pu_tie_01 = 0;
new pu_tie_02 = 0;
new pu_elq_01 = 0;
new pu_elq_02 = 0;
new pu_bon_01 = 0;
new pu_bon_02 = 0;
new pu_for_01 = 0;
new pu_for_02 = 0;
new pu_com_01 = 0;
new pu_com_02 = 0;
new pu_xxx_01 = 0;
new pu_xxx_02 = 0;
new pu_red_01 = 0;
new pu_red_02 = 0;
new pu_eme_01 = 0;
new pu_eme_02 = 0;
new pu_spi_01 = 0;
new pu_spi_02 = 0;
new pu_fsf_01 = 0;
new TsTimer[MAX_PLAYERS];
/* *********************************************************  Funktionsdeklarationen  ********************************************************* */	
forward CreateTankstellenMapIcons();
forward GetCurrentGasStationInfo();
forward CreateTsPickups();
forward TsBezahlen(playerid, ts_id);
forward Tanken(playerid, &pickupid, Float:PosX, Float:PosY, Float:PosZ);
forward NewTsPickup(&pickupid,Float:PosX, Float:PosY, Float:PosZ);
forward ts_pickups(playerid, pickupid);
/* *********************************************************  Funktionsdefinitionen   ********************************************************* */
public CreateTankstellenMapIcons() //MapIcons setzen
{
	CreateDynamicMapIcon(1930.3215, -1776.1310, 13.5469, 42, -1, -1, -1, -1, 500);		// Alhambra Petrol Station
	CreateDynamicMapIcon(997.5215, -921.0881, 42.1797, 42, -1, -1, -1, -1, 500);		// Burger Shot North Petrol Station
	CreateDynamicMapIcon(-79.5565, -1169.7639, 2.1629, 42, -1, -1, -1, -1, 500);		// RS Haul Petrol Station
	CreateDynamicMapIcon(660.7679, -573.5139, 16.3359, 42, -1, -1, -1, -1, 500);		// Dillimore Petrol Station
	CreateDynamicMapIcon(1382.7303, 464.6540, 20.2040, 42, -1, -1, -1, -1, 500);		// Montgomery Petrol Station
	CreateDynamicMapIcon(-2232.0854, -2557.9436, 31.9219, 42, -1, -1, -1, -1, 500);		// Angel Pine Petrol Station
	CreateDynamicMapIcon(-1623.9540, -2693.8535, 48.7427, 42, -1, -1, -1, -1, 500);		// Whetstone Petrol Station
	CreateDynamicMapIcon(-2032.1000, 161.4818, 29.0461, 42, -1, -1, -1, -1, 500);		// Doherty Petrol Station
	CreateDynamicMapIcon(-1675.8939, 431.8836, 7.1797, 42, -1, -1, -1, -1, 500);		// Easter Basin Petrol Station
	CreateDynamicMapIcon(-2418.7725, 970.0265, 45.2969, 42, -1, -1, -1, -1, 500);		// Juniper Hill Petrol Station
	CreateDynamicMapIcon(-1465.5171, 1872.7550, 32.6328, 42, -1, -1, -1, -1, 500);		// Tierra Robada Petrol Station
	CreateDynamicMapIcon(-1266.0439, 2715.7612, 50.2663, 42, -1, -1, -1, -1, 500);		// El Quebrados Petrol Station
	CreateDynamicMapIcon(637.8962, 1684.6371, 6.9922, 42, -1, -1, -1, -1, 500);			// Bone Country Petrol Station
	CreateDynamicMapIcon(60.6089, 1225.8971, 18.8654, 42, -1, -1, -1, -1, 500);			// Fort Carson Petrol Station
	CreateDynamicMapIcon(2117.4829, 898.0604, 11.1797, 42, -1, -1, -1, -1, 500);		// Come a lot Petrol Station
	CreateDynamicMapIcon(2637.2520, 1128.6094, 11.1797, 42, -1, -1, -1, -1, 500);		// xxx Petrol Station
	CreateDynamicMapIcon(1600.0146, 2220.7227, 11.0625, 42, -1, -1, -1, -1, 500);		// Redsands West Petrol Station
	CreateDynamicMapIcon(2189.4131, 2469.6494, 11.2422, 42, -1, -1, -1, -1, 500);		// Emerald Petrol Station
	CreateDynamicMapIcon(2150.9675, 2735.3318, 11.1763, 42, -1, -1, -1, -1, 500);		// Spinybed Petrol Station
	CreateTsPickups();
	return 1;
}
/* **********************************************  Aktuelle Informationen aus Datenbank holen  ************************************************ */
public GetCurrentGasStationInfo()
{
	new query[512], data[128];
	new i = 0;
	for(new a = 0; i < 20; a++)
	{
		format(query, sizeof(query), "SELECT ts_name, vk_diesel, vk_normal, vk_super FROM tankstellen WHERE ts_id = '%d'", i);
		mysql_query(query);
		mysql_store_result();
		mysql_fetch_row(data);
		
	
		i++;
	}	  
}
public CreateTsPickups()
{
	pu_alh_01 = CreatePickup(1239, 14, 1944, -1772, 13, 0);
	pu_alh_02 = CreatePickup(1239, 14, 1939, -1772, 13, 0);
	pu_bsn_01 = CreatePickup(1239, 14, 1005, -940, 42, 0);
	pu_bsn_02 = CreatePickup(1239, 14, 1003, -933, 42, 0);
	pu_rsh_01 = CreatePickup(1239, 14, -87, -1170, 2, 0);
	pu_rsh_02 = CreatePickup(1239, 14, -93, -1167, 2, 0);
	pu_dil_01 = CreatePickup(1239, 14, 656, -570, 16, 0);
	pu_dil_02 = CreatePickup(1239, 14, 656, -559, 16, 0);
	pu_mon_01 = CreatePickup(1239, 14, 1382, 461, 20, 0);
	pu_mon_02 = CreatePickup(1239, 14, 1381, 456, 19, 0);
	pu_ang_01 = CreatePickup(1239, 14, -2244, -2561, 31, 0);
	pu_ang_02 = CreatePickup(1239, 14, -2252, -2565, 31, 0);
	pu_whe_01 = CreatePickup(1239, 14, -1609, -2717, 48, 0);
	pu_whe_02 = CreatePickup(1239, 14, -1607, -2713, 48, 0);
	pu_doh_01 = CreatePickup(1239, 14, -2028, 156, 28, 0);
	pu_doh_02 = CreatePickup(1239, 14, -2023, 156, 28, 0);
	pu_eas_01 = CreatePickup(1239, 14, -1675, 412, 7, 0);
	pu_eas_02 = CreatePickup(1239, 14, -1682, 419, 7, 0);
	pu_jun_01 = CreatePickup(1239, 14, -2407, 976, 45, 0);
	pu_jun_02 = CreatePickup(1239, 14, -2413, 976, 45, 0);
	pu_tie_01 = CreatePickup(1239, 14, -1466, 1868, 32, 0);
	pu_tie_02 = CreatePickup(1239, 14, -1466, 1860, 32, 0);
	pu_elq_01 = CreatePickup(1239, 14, -1327, 2682, 50, 0);
	pu_elq_02 = CreatePickup(1239, 14, -1328, 2677, 50, 0);
	pu_bon_01 = CreatePickup(1239, 14, 622, 1680, 6, 0);
	pu_bon_02 = CreatePickup(1239, 14, 618, 1685, 6, 0);
	pu_for_01 = CreatePickup(1239, 14, 0, 0, 0, 0);
	pu_for_02 = CreatePickup(1239, 14, 0, 0, 0, 0);
	pu_red_01 = CreatePickup(1239, 14,1596, 2190, 10, 0);
	pu_red_02 = CreatePickup(1239, 14,1595, 2199, 10, 0);
	pu_eme_01 = CreatePickup(1239, 14, 2210, 2473, 10, 0);
	pu_eme_02 = CreatePickup(1239, 14, 2202, 2474, 10, 0);
	pu_spi_01 = CreatePickup(1239, 14, 2148, 2751, 10, 0);
	pu_spi_02 = CreatePickup(1239, 14, 2147, 2744, 10, 0);
	pu_fsf_01 = CreatePickup(1239, 14, -1148, -172, 14, 0);
	
}
public Tanken(playerid, &pickupid, Float:PosX, Float:PosY, Float:PosZ)
{	
	if(Fahrzeuge[GetPlayerVehicleID(playerid)][0] < (Fahrzeugdaten[GetVehicleModel(GetPlayerVehicleID(playerid))-400][0] - 5))
	{
		DestroyPickup(pickupid);
		TogglePlayerControllable(playerid, false);
		Fahrzeuge[GetPlayerVehicleID(playerid)][0] = Fahrzeuge[GetPlayerVehicleID(playerid)][0] + 5;
		//TsTimer[playerid] = SetTimerEx("Tanken", 1000, true, "iifff", playerid, pickupid, PosX, PosY, PosZ);
		pickupid = CreatePickup(1239, 14, PosX, PosY, PosZ, 0);
	}
	else 
	{
		pickupid = CreatePickup(1239, 14, PosX, PosY, PosZ, 0);
		DestroyPickup(pickupid);
		Fahrzeuge[GetPlayerVehicleID(playerid)][0] = Fahrzeugdaten[GetVehicleModel(GetPlayerVehicleID(playerid))-400][0];
		TogglePlayerControllable(playerid, true);
		SetTimerEx("NewTsPickup", 10000, false, "ifff", pickupid, PosX, PosY, PosZ);
		KillTimer(TsTimer[playerid]);
	}
}
public NewTsPickup(&pickupid,Float:PosX, Float:PosY, Float:PosZ)
{
	pickupid = CreatePickup(1239, 14, PosX, PosY, PosZ, 0);
}
public TsBezahlen(playerid, ts_id)
{
	new Float:menge = (Fahrzeugdaten[GetVehicleModel(GetPlayerVehicleID(playerid))-400][0]) - Fahrzeuge[GetPlayerVehicleID(playerid)][0];
	new query[128], data[128];
	new cur_diesel, Float:vk_preis;
	format(query, sizeof(query), "SELECT cur_diesel, vk_diesel, vk_normal, vk_super FROM tankstellen WHERE ts_id = %i", ts_id);
	mysql_query(query);
	mysql_store_result();
	mysql_fetch_row(data);
	mysql_fetch_field("cur_diesel", data);
	cur_diesel = strval(data);
	if(Fahrzeugdaten[GetVehicleModel(GetPlayerVehicleID(playerid))-400][3] == 0)
	{
		mysql_fetch_field("vk_diesel", data);
		vk_preis = floatstr(data);
	}
	else if(Fahrzeugdaten[GetVehicleModel(GetPlayerVehicleID(playerid))-400][3] == 1)
	{
		mysql_fetch_field("vk_normal", data);
		vk_preis = floatstr(data);
	}
	else if(Fahrzeugdaten[GetVehicleModel(GetPlayerVehicleID(playerid))-400][3] == 2)
	{
		mysql_fetch_field("vk_super", data);
		vk_preis = floatstr(data);
	}

	if(!giveusermoney(playerid, (floatround(vk_preis * menge)*-1)) && GetPlayerState(playerid) == PLAYER_STATE_DRIVER)
	{
		GameTextForPlayer(playerid, "~r~Zu wenig ~w~Geld zum Tanken", 3000, 3);
		TogglePlayerControllable(playerid, true);
		return 0;
	}
	if(cur_diesel < menge)
	{
		GameTextForPlayer(playerid, "~w~Diese Tankstelle hat~n~~r~Zu wenig ~w~~n~Kraftstoff", 3000, 3);
		TogglePlayerControllable(playerid, true);
		return 0;
	}
	format(query, sizeof(query), "UPDATE tankstellen SET cur_cash = cur_cash + %i WHERE ts_id = %i", floatround(vk_preis * menge), ts_id);
	mysql_query(query);
	return 1;
}
public ts_pickups(playerid, pickupid)
{
	if(pickupid == pu_alh_01)
	{
		if(TsBezahlen(playerid, 0))
			Tanken(playerid, pu_alh_01, 1944, -1772, 13);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_alh_01, 1944, -1772, 13);
	}
	if(pickupid == pu_alh_02)
	{
		if(TsBezahlen(playerid, 0))
			Tanken(playerid, pu_alh_02, 1939, -1772, 13);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_alh_02, 1939, -1772, 13);
	}
	if(pickupid == pu_bsn_01)
	{
		if(TsBezahlen(playerid, 1))
			Tanken(playerid, pu_bsn_01, 1005, -940, 42);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_bsn_01, 1005, -940, 42);
	}
	if(pickupid == pu_bsn_02)
	{
		if(TsBezahlen(playerid, 1))
			Tanken(playerid, pu_bsn_02, 1003, -933, 42);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_bsn_02, 1003, -933, 42);
	}
	if(pickupid == pu_rsh_01)
	{
		if(TsBezahlen(playerid, 2))
			Tanken(playerid, pu_rsh_01, -87, -1170, 2);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_rsh_01, -87, -1170, 2);
	}
	if(pickupid == pu_rsh_02)
	{
		if(TsBezahlen(playerid, 2))
			Tanken(playerid, pu_rsh_02, -93, -1167, 2);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_rsh_02, -93, -1167, 2);
	}
	if(pickupid == pu_dil_01)
	{
		if(TsBezahlen(playerid, 3))
			Tanken(playerid, pu_dil_01, 656, -570, 16);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_dil_01, 656, -570, 16);
	}
	if(pickupid == pu_dil_02)
	{
		if(TsBezahlen(playerid, 3))
			Tanken(playerid, pu_dil_02, 656, -559, 16);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_dil_02, 656, -559, 16);
	}
	if(pickupid == pu_mon_01)
	{
		if(TsBezahlen(playerid, 4))
			Tanken(playerid, pu_mon_01, 1382, 461, 20);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_mon_01, 1382, 461, 20);
	}
	if(pickupid == pu_mon_02)
	{
		if(TsBezahlen(playerid, 4))
			Tanken(playerid, pu_mon_02, 1381, 456, 19);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_mon_02, 1381, 456, 19);
	}
	if(pickupid == pu_ang_01)
	{
		if(TsBezahlen(playerid, 5))
			Tanken(playerid, pu_ang_01, -2244, -2561, 31);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_ang_01, -2244, -2561, 31);
	}
	if(pickupid == pu_ang_02)
	{
		if(TsBezahlen(playerid, 5))
			Tanken(playerid, pu_ang_02, -2252, -2565, 31);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_ang_02, -2252, -2565, 31);
	}
	if(pickupid == pu_whe_01)
	{
		if(TsBezahlen(playerid, 6))
			Tanken(playerid, pu_whe_01, -1609, -2717, 48);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_whe_01, -1609, -2717, 48);
	}
	if(pickupid == pu_whe_02)
	{
		if(TsBezahlen(playerid, 6))
			Tanken(playerid, pu_whe_02, -1607, -2713, 48);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_whe_02, -1607, -2713, 48);
	}
	if(pickupid == pu_doh_01)
	{
		if(TsBezahlen(playerid, 7))
			Tanken(playerid, pu_doh_01, -2028, 156, 28);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_doh_01, -2028, 156, 28);
	}
	if(pickupid == pu_doh_02)
	{
		if(TsBezahlen(playerid, 7))
			Tanken(playerid, pu_doh_02, -2023, 156, 28);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_doh_02, -2023, 156, 28);
	}
	if(pickupid == pu_eas_01)
	{
		if(TsBezahlen(playerid, 8))
			Tanken(playerid, pu_eas_01, -1675, 412, 7);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_eas_01, -1675, 412, 7);
	}
	if(pickupid == pu_eas_02)
	{
		if(TsBezahlen(playerid, 8))
			Tanken(playerid, pu_eas_02, -1682, 419, 7);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_eas_02, -1682, 419, 7);
	}
	if(pickupid == pu_jun_01)
	{
		if(TsBezahlen(playerid, 9))
			Tanken(playerid, pu_jun_01, -2407, 976, 45);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_jun_01, -2407, 976, 45);
	}
	if(pickupid == pu_jun_02)
	{
		if(TsBezahlen(playerid, 9))
			Tanken(playerid, pu_jun_02, -2413, 976, 45);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_jun_02, -2413, 976, 45);
	}
	if(pickupid == pu_tie_01)
	{
		if(TsBezahlen(playerid, 10))
			Tanken(playerid, pu_tie_01, -1466, 1868, 32);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_tie_01, -1466, 1868, 32);
	}
	if(pickupid == pu_tie_02)
	{
		if(TsBezahlen(playerid, 10))
			Tanken(playerid, pu_tie_02, -1466, 1860, 32);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_tie_02, -1466, 1860, 32);
	}
	if(pickupid == pu_elq_01)
	{
		if(TsBezahlen(playerid, 11))
			Tanken(playerid, pu_elq_01, -1327, 2682, 50);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_elq_01, -1327, 2682, 50);
	}
	if(pickupid == pu_elq_02)
	{
		if(TsBezahlen(playerid, 11))
			Tanken(playerid, pu_elq_02, -1328, 2677, 50);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_elq_02, -1328, 2677, 50);
	}
	if(pickupid == pu_bon_01)
	{
		if(TsBezahlen(playerid, 12))
			Tanken(playerid, pu_bon_01, 622, 1680, 6);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_bon_01, 622, 1680, 6);
	}
	if(pickupid == pu_bon_02)
	{
		if(TsBezahlen(playerid, 12))
			Tanken(playerid, pu_bon_02, 618, 1685, 6);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_bon_02, 618, 1685, 6);
	}
	if(pickupid == pu_for_01)
	{
		if(TsBezahlen(playerid, 13))
			Tanken(playerid, pu_for_01, 0, 0, 0);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_for_01, 0, 0, 0);
	}
	if(pickupid == pu_for_02)
	{
		if(TsBezahlen(playerid, 13))
			Tanken(playerid, pu_for_02, 0, 0, 0);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_for_02, 0, 0, 0);
	}
	if(pickupid == pu_com_01)
	{
		if(TsBezahlen(playerid, 14))
			Tanken(playerid, pu_com_01, 2115, 923, 10);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_com_01, 2115, 923, 10);
	}
	if(pickupid == pu_com_02)
	{
		if(TsBezahlen(playerid, 14))
			Tanken(playerid, pu_com_02, 2114, 917, 10);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_com_02, 2114, 917, 10);
	}
	if(pickupid == pu_xxx_01)
	{
		if(TsBezahlen(playerid, 15))
			Tanken(playerid, pu_xxx_01,2638, 1113, 10);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_xxx_01,2638, 1113, 10);
	}
	if(pickupid == pu_xxx_02)
	{
		if(TsBezahlen(playerid, 15))
			Tanken(playerid, pu_xxx_02,2639, 1103, 10);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_xxx_02,2639, 1103, 10);
	}
	if(pickupid == pu_red_01)
	{
		if(TsBezahlen(playerid, 16))
			Tanken(playerid, pu_red_01,1596, 2190, 10);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_red_01,1596, 2190, 10);
	}
	if(pickupid == pu_red_02)
	{
		if(TsBezahlen(playerid, 16))
			Tanken(playerid, pu_red_02,1595, 2199, 10);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_red_02,1595, 2199, 10);
	}
	if(pickupid == pu_eme_01)
	{
		if(TsBezahlen(playerid, 17))
			Tanken(playerid, pu_eme_01, 2210, 2473, 10);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_eme_01, 2210, 2473, 10);
	}
	if(pickupid == pu_eme_02)
	{
		if(TsBezahlen(playerid, 17))
			Tanken(playerid, pu_eme_02, 2202, 2474, 10);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_eme_02, 2202, 2474, 10);
	}
	if(pickupid == pu_spi_01)
	{
		if(TsBezahlen(playerid, 18))
			Tanken(playerid, pu_spi_01, 2148, 2751, 10);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_spi_01, 2148, 2751, 10);
	}
	if(pickupid == pu_spi_02)
	{
		if(TsBezahlen(playerid, 18))
			Tanken(playerid, pu_spi_02, 2147, 2744, 10);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_spi_02, 2147, 2744, 10);
	}
	if(pickupid == pu_fsf_01)
	{
		if(TsBezahlen(playerid, 19))
			Tanken(playerid, pu_fsf_01, -1148, -172, 14);
		else SetTimerEx("NewTsPickup", 10000, false, "ifff", pu_fsf_01, -1148, -172, 14);
	}
}