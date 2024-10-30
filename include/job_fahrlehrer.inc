forward fahrzeuge_fahrschule();
forward fahrschule_pickups(playerid,pickupid);
forward fahrschule_response(playerid, dialogid, response, listitem, inputtext[]);
forward fahrschule_pruefe(lizenz);
forward fahrschule_auswahl(playerid,lizenz);
forward fahrschule_startefahrstunde(playerid,lizenz,lizenzname[]);
forward fahrschule_abbruchfahrstunde(playerid);
forward fahrschule_stundenende(lehrerid,kind);
forward fahrschule_stundenendeschueler(schuelerid);
forward fahrschule_stundenendelehrer(lehrerid);
forward fahrschule_annahmestunde(lehrerid,schuelerid);
forward fahrschule_lehrerdisconnect(lehrerid);
forward fahrschule_theorie(playerid);
forward fahrschule_fragen(playerid,anz,input[]);
forward gebuehren(lizenz);
forward fahrschule_startbeantragen(playerid);
forward fahrschule_landungbeantragen(playerid);
forward fahrschule_startlandeabwarten(playerid);
forward fahrschule_statechange(playerid, newstate, oldstate);
forward admin_statechange(playerid, newstate, oldstate);

new fahrschule_lehrerpick,fahrschule_schuelerpick;
new fahrlehrer_on[] = {-1,-1,-1,-1,-1};
new fahrschueler[MAX_PLAYERS];
new timer_fahrschueler[MAX_PLAYERS];
new fstart[MAX_PLAYERS];
new landebahnsf = 0, landebahnls = 0, landebahnlv = 0;


public fahrzeuge_fahrschule()
{
  new fahrschultrailer1,fahrschultrailer4;
  new fahrschultrailer2,fahrschultrailer3;
  CreateVehicleEx(511,-1642.93,-344.80,14.14,45,144,1,60);  //Fahrschulflugzeug - Beagle
  CreateVehicleEx(511,-1626.83,-328.36,14.14,45,144,1,60);  //Fahrschulflugzeug - Beagle
  CreateVehicleEx(553,-1609.77,-310.94,15.5,45,144,1,60);  //Fahrschulflugzeug - Nevada
  CreateVehicleEx(553,-1593.17,-293.27,15.5,45,144,1,60);  //Fahrschulflugzeug - Nevada
  
  CreateVehicleEx(520,-1206.36,-145.24,14.14,135,144,1,60); //Adminflugzeug - Hydra
  CreateVehicleEx(520,-1225.36,-125.24,14.14,135,144,1,60); //Adminflugzeug - Hydra
  CreateVehicleEx(520,-1243.36,-105.24,14.14,135,144,1,60); //Adminflugzeug - Hydra
  CreateVehicleEx(520,-1258.36,-85.24,14.14,135,144,1,60); //Adminflugzeug - Hydra
  
  CreateVehicleEx(581,-1367.6,-520.3,14.17,295,144,1,60);  //Fahrschulmotorrad - BF-400
  CreateVehicleEx(581,-1369.6,-515.3,14.17,295,144,1,60);  //Fahrschulmotorrad - BF-400
  CreateVehicleEx(581,-1371.6,-510.3,14.17,295,144,1,60);  //Fahrschulmotorrad - BF-400
  CreateVehicleEx(581,-1373.6,-505.3,14.17,295,144,1,60);  //Fahrschulmotorrad - BF-400
  
  CreateVehicleEx(507,-1378.63,-498.0,14.17,295,144,1,60);  //Fahrschulauto - Elegant
  CreateVehicleEx(507,-1381.63,-492.0,14.17,295,144,1,60);  //Fahrschulauto - Elegant
  CreateVehicleEx(507,-1384.63,-486.0,14.17,295,144,1,60);  //Fahrschulauto - Elegant
  CreateVehicleEx(507,-1387.63,-480.0,14.17,295,144,1,60);  //Fahrschulauto - Elegant
  
  CreateVehicleEx(578,-1338.5,-505.5,14.17,115,144,1,60);  //Fahrschulauto - DFT-30
  CreateVehicleEx(578,-1341.5,-500.5,14.17,115,144,1,60);  //Fahrschulauto - DFT-30
  CreateVehicleEx(578,-1344.5,-495.5,14.17,115,144,1,60);  //Fahrschulauto - DFT-30
  CreateVehicleEx(578,-1347.5,-490.5,14.17,115,144,1,60);  //Fahrschulauto - DFT-30
  
  CreateVehicleEx(515,-1350.5,-485.5,14.17,115,144,1,60);  //Fahrschulauto - Roadtrain
  CreateVehicleEx(515,-1353.5,-480.5,14.17,115,144,1,60);  //Fahrschulauto - Roadtrain
  CreateVehicleEx(515,-1356.5,-475.5,14.17,115,144,1,60);  //Fahrschulauto - Roadtrain
  CreateVehicleEx(515,-1359.5,-470.5,14.17,115,144,1,60);  //Fahrschulauto - Roadtrain
  
  fahrschultrailer1 = CreateVehicleEx(515,-1443.04, -536.12, 15.17, 215,144,1,60);  //Fahrschulauto - Roadtrain+Trailer
  fahrschultrailer3 = CreateVehicleEx(435,-1437.01, -520.84, 15.19, 215,144,1,60);
  AttachTrailerToVehicle(fahrschultrailer3, fahrschultrailer1);
  fahrschultrailer2 = CreateVehicleEx(515,-1431.62, -528.96, 15.18, 215,144,1,60);  //Fahrschulauto - Roadtrain+Trailer
  fahrschultrailer4 = CreateVehicleEx(450,-1448.32, -527.94, 15.19, 215,144,1,60);
  AttachTrailerToVehicle(fahrschultrailer4, fahrschultrailer2);
  
  CreateVehicleEx(457,-1535.58,-445.25,6.03,295,0,1,60);  //Fahrlehrer - Caddy
  CreateVehicleEx(457,-1529.16,-452.44,6.05,295,0,1,60);  //Fahrlehrer - Caddy
  CreateVehicleEx(457,-1212.16,-106.64,14.14,115,0,1,60); //Fahrlehrer - Caddy
  CreateVehicleEx(457,-1582.01,-281.58,14.14,45,0,1,60);  //Fahrlehrer - Caddy
  
  CreateVehicleEx(457,-1376.30,-468.69,13.65,205,0,1,60);  //Fahrlehrer - Caddy
  CreateVehicleEx(457,-1599.67,-568.78,13.62,205,0,1,60);  //Fahrlehrer - Caddy
  CreateVehicleEx(457,-1634.38,-590.68,14.14,205,0,1,60);  //Fahrlehrer - Caddy
  
  CreateVehicleEx(469,-1565.16,-575.91,14.14,205,144,1,60);  //Fahrschulhelikopter - Heli
  CreateVehicleEx(469,-1581.59,-592.18,14.14,205,144,1,60);  //Fahrschulhelikopter - Heli
  CreateVehicleEx(469,-1598.82,-608.96,14.14,205,144,1,60);  //Fahrschulhelikopter - Heli
  CreateVehicleEx(469,-1615.43,-625.51,14.14,205,144,1,60);  //Fahrschulhelikopter - Heli
  
  CreateVehicleEx(548,-1578.83,-646.59,15.71,205,144,1,60);  //Fahrschulhelikopter - Heli groß
  CreateVehicleEx(548,-1554.93,-619.98,15.71,205,144,1,60);  //Fahrschulhelikopter - Heli groß
  
  CreateVehicleEx(454,-1475.82, 492, 0,9,144,1,60);  //Fahrschulboot Fischer
  CreateVehicleEx(454,-1480.93, 492, 0,9,144,1,60);  //Fahrschulboot Fischer
  
  CreateVehicleEx(446,-1290.13, 490, 0,270,144,1,60);  //Fahrschulboot Sport
  CreateVehicleEx(446,-1281.93, 484, 0,270,144,1,60);  //Fahrschulboot Sport
  
  fahrschule_schuelerpick = CreatePickup(1239,1,-1545.91,-442.25,6.00,-1);
  Create3DTextLabel("Fahrschule",COLOR_WHITE,-1545.91,-442.25,7.00,25,0);
  
  fahrschule_lehrerpick = CreatePickup(1239,1,-1544.90,-447.67,6.00,-1);
  
  CreateDynamicMapIcon(-1545.91,-442.25,6.00, 36, -1,-1, -1, -1, 500);
}

public fahrschule_pickups(playerid,pickupid)
{
  if(pickupid == fahrschule_lehrerpick && playerdata[playerid][2] == 3)
  {
	if(fahrlehrer_on[0] != playerid && fahrlehrer_on[1] != playerid && fahrlehrer_on[2] != playerid && fahrlehrer_on[3] != playerid && fahrlehrer_on[4] != playerid)
	{
	  for(new i=0;i < 5;i++) if(fahrlehrer_on[i] < 0){ fahrlehrer_on[i] = playerid; i = 5;}
	  if(playerdata[playerid][36] == 1) SetPlayerSkin(playerid,172); else SetPlayerSkin(playerid,171);
	  GameTextForPlayer(playerid, "~w~Sie arbeiten jetzt als~n~~y~Fahrlehrer", 3000, 1);
	  fahrschueler[playerid] = -1;
	}
	else
	{
	  for(new i=0;i < 5;i++) if(fahrlehrer_on[i] == playerid) fahrlehrer_on[i] = -1;
	  SetPlayerSkin(playerid,playerdata[playerid][1]);
	  GameTextForPlayer(playerid, "~w~Ihre Arbeit ist beendet", 3000, 1);
	  fahrschueler[playerid] = -1;
	}
  }
  if(pickupid == fahrschule_schuelerpick && fahrstunde[playerid] == 0)
  {
	SetPlayerPos(playerid,-1543.91,-437,6.00);
	if(fahrlehrer_on[0] != -1 || fahrlehrer_on[1] != -1 || fahrlehrer_on[2] != -1 || fahrlehrer_on[3] != -1 || fahrlehrer_on[4] != -1)
	{
	  ShowPlayerDialog(playerid, 12,DIALOG_STYLE_LIST, "Fahrschule:", "Motorrad Führerschein\nPKW Führerschein\nLKW Führerschein\nLKW mit Anhänger Führerschein\nSportboot Führerschein\nFischerboot Führerschein\nKleinflugzeug Führerschein\nFracht-& Passagierflugzeuge Führerschein\nHelicopter Führerschein", "Weiter", "Schliessen");
	}
	else
	{
	  SendClientMessage(playerid, COLOR_RED, "Es ist im Moment kein Fahrlehrer im Dienst!");
	}
  }
  if(pickupid == fahrschuleroller_pick && fahrstunde[playerid] == 0 && playerdata[playerid][20] == 0)
  {
	fahrschule_auswahl(playerid,20);
  }
}

public fahrschule_response(playerid, dialogid, response, listitem, inputtext[])
{
  if(dialogid == 12 && response)
  {
	switch(listitem)
	{
	  case 0: if(fahrschule_pruefe(21) && playerdata[playerid][4] >= gebuehren(21)) fahrschule_auswahl(playerid,21); else SendClientMessage(playerid, COLOR_RED, "Es ist im Moment kein Fahrlehrer für diese Lizenz im Dienst!");
	  case 1: if(fahrschule_pruefe(22) && playerdata[playerid][4] >= gebuehren(22)) fahrschule_auswahl(playerid,22); else SendClientMessage(playerid, COLOR_RED, "Es ist im Moment kein Fahrlehrer für diese Lizenz im Dienst!");
	  case 2: if(fahrschule_pruefe(23) && playerdata[playerid][4] >= gebuehren(23)) fahrschule_auswahl(playerid,23); else SendClientMessage(playerid, COLOR_RED, "Es ist im Moment kein Fahrlehrer für diese Lizenz im Dienst!");
	  case 3: if(fahrschule_pruefe(24) && playerdata[playerid][4] >= gebuehren(24)) fahrschule_auswahl(playerid,24); else SendClientMessage(playerid, COLOR_RED, "Es ist im Moment kein Fahrlehrer für diese Lizenz im Dienst!");
	  case 4: if(fahrschule_pruefe(25) && playerdata[playerid][4] >= gebuehren(25)) fahrschule_auswahl(playerid,25); else SendClientMessage(playerid, COLOR_RED, "Es ist im Moment kein Fahrlehrer für diese Lizenz im Dienst!");
	  case 5: if(fahrschule_pruefe(26) && playerdata[playerid][4] >= gebuehren(26)) fahrschule_auswahl(playerid,26); else SendClientMessage(playerid, COLOR_RED, "Es ist im Moment kein Fahrlehrer für diese Lizenz im Dienst!");
      case 6: if(fahrschule_pruefe(27) && playerdata[playerid][4] >= gebuehren(27)) fahrschule_auswahl(playerid,27); else SendClientMessage(playerid, COLOR_RED, "Es ist im Moment kein Fahrlehrer für diese Lizenz im Dienst!");
	  case 7: if(fahrschule_pruefe(28) && playerdata[playerid][4] >= gebuehren(28)) fahrschule_auswahl(playerid,28); else SendClientMessage(playerid, COLOR_RED, "Es ist im Moment kein Fahrlehrer für diese Lizenz im Dienst!");
	  case 8: if(fahrschule_pruefe(29) && playerdata[playerid][4] >= gebuehren(29)) fahrschule_auswahl(playerid,29); else SendClientMessage(playerid, COLOR_RED, "Es ist im Moment kein Fahrlehrer für diese Lizenz im Dienst!");
	}
  }
  if(dialogid == 13)
  {
	if(response && playerdata[playerid][21] == 0)
	{
	  fahrstunde[playerid] = 21;
	  timer_fahrschueler[playerid] = SetTimerEx("fahrschule_abbruchfahrstunde",15000,false,"i",playerid);
	  fahrschule_startefahrstunde(playerid,21,"Motorrad");
	  SendClientMessage(playerid, COLOR_RED, "Prüfe auf verfügbare Fahrlehrer ...");
	}
	else if(response && playerdata[playerid][21] == 1)
	  SendClientMessage(playerid, COLOR_RED, "Sie haben diese Lizens bereits.");
	else
	  ShowPlayerDialog(playerid, 12,DIALOG_STYLE_LIST, "Fahrschule:", "Motorrad Führerschein\nPKW Führerschein\nLKW Führerschein\nLKW mit Anhänger Führerschein\nSportboot Führerschein\nFischerboot Führerschein\nKleinflugzeug Führerschein\nFracht-& Passagierflugzeuge Führerschein\nHelicopter Führerschein", "Weiter", "Schliessen");
  }
  if(dialogid == 14)
  {
	if(response && playerdata[playerid][22] == 0)
	{
	  fahrstunde[playerid] = 22;
	  timer_fahrschueler[playerid] = SetTimerEx("fahrschule_abbruchfahrstunde",15000,false,"i",playerid);
	  fahrschule_startefahrstunde(playerid,22,"PKW");
	  SendClientMessage(playerid, COLOR_RED, "Prüfe auf verfügbare Fahrlehrer ...");
	}
	else if(response && playerdata[playerid][22] == 1)
	  SendClientMessage(playerid, COLOR_RED, "Sie haben diese Lizens bereits.");
	else
	  ShowPlayerDialog(playerid, 12,DIALOG_STYLE_LIST, "Fahrschule:", "Motorrad Führerschein\nPKW Führerschein\nLKW Führerschein\nLKW mit Anhänger Führerschein\nSportboot Führerschein\nFischerboot Führerschein\nKleinflugzeug Führerschein\nFracht-& Passagierflugzeuge Führerschein\nHelicopter Führerschein", "Weiter", "Schliessen");
  }
  if(dialogid == 15)
  {
	if(response && playerdata[playerid][23] == 0)
	{
	  fahrstunde[playerid] = 23;
	  timer_fahrschueler[playerid] = SetTimerEx("fahrschule_abbruchfahrstunde",15000,false,"i",playerid);
	  fahrschule_startefahrstunde(playerid,23,"LKW");
	  SendClientMessage(playerid, COLOR_RED, "Prüfe auf verfügbare Fahrlehrer ...");
	}
	else if(response && playerdata[playerid][23] == 1)
	  SendClientMessage(playerid, COLOR_RED, "Sie haben diese Lizens bereits.");
	else
	  ShowPlayerDialog(playerid, 12,DIALOG_STYLE_LIST, "Fahrschule:", "Motorrad Führerschein\nPKW Führerschein\nLKW Führerschein\nLKW mit Anhänger Führerschein\nSportboot Führerschein\nFischerboot Führerschein\nKleinflugzeug Führerschein\nFracht-& Passagierflugzeuge Führerschein\nHelicopter Führerschein", "Weiter", "Schliessen");
  }
  if(dialogid == 16)
  {
	if(response && playerdata[playerid][24] == 0)
	{
	  fahrstunde[playerid] = 24;
	  timer_fahrschueler[playerid] = SetTimerEx("fahrschule_abbruchfahrstunde",15000,false,"i",playerid);
	  fahrschule_startefahrstunde(playerid,24,"LKW mit Anhänger");
	  SendClientMessage(playerid, COLOR_RED, "Prüfe auf verfügbare Fahrlehrer ...");
	}
	else if(response && playerdata[playerid][24] == 1)
	  SendClientMessage(playerid, COLOR_RED, "Sie haben diese Lizens bereits.");
	else
	  ShowPlayerDialog(playerid, 12,DIALOG_STYLE_LIST, "Fahrschule:", "Motorrad Führerschein\nPKW Führerschein\nLKW Führerschein\nLKW mit Anhänger Führerschein\nSportboot Führerschein\nFischerboot Führerschein\nKleinflugzeug Führerschein\nFracht-& Passagierflugzeuge Führerschein\nHelicopter Führerschein", "Weiter", "Schliessen");
  }
  if(dialogid == 17)
  {
	if(response && playerdata[playerid][27] == 0)
	{
	  fahrstunde[playerid] = 27;
	  timer_fahrschueler[playerid] = SetTimerEx("fahrschule_abbruchfahrstunde",15000,false,"i",playerid);
	  fahrschule_startefahrstunde(playerid,27,"Kleinflugzeug");
	  SendClientMessage(playerid, COLOR_RED, "Prüfe auf verfügbare Fahrlehrer ...");
	}
	else if(response && playerdata[playerid][27] == 1)
	  SendClientMessage(playerid, COLOR_RED, "Sie haben diese Lizens bereits.");
	else
	  ShowPlayerDialog(playerid, 12,DIALOG_STYLE_LIST, "Fahrschule:", "Motorrad Führerschein\nPKW Führerschein\nLKW Führerschein\nLKW mit Anhänger Führerschein\nSportboot Führerschein\nFischerboot Führerschein\nKleinflugzeug Führerschein\nFracht-& Passagierflugzeuge Führerschein\nHelicopter Führerschein", "Weiter", "Schliessen");
  }
  if(dialogid == 18)
  {
	if(response && playerdata[playerid][28] == 0)
	{
	  fahrstunde[playerid] = 28;
	  timer_fahrschueler[playerid] = SetTimerEx("fahrschule_abbruchfahrstunde",15000,false,"i",playerid);
	  fahrschule_startefahrstunde(playerid,28,"Airbus");
	  SendClientMessage(playerid, COLOR_RED, "Prüfe auf verfügbare Fahrlehrer ...");
	}
	else if(response && playerdata[playerid][28] == 1)
	  SendClientMessage(playerid, COLOR_RED, "Sie haben diese Lizens bereits.");
	else
	  ShowPlayerDialog(playerid, 12,DIALOG_STYLE_LIST, "Fahrschule:", "Motorrad Führerschein\nPKW Führerschein\nLKW Führerschein\nLKW mit Anhänger Führerschein\nSportboot Führerschein\nFischerboot Führerschein\nKleinflugzeug Führerschein\nFracht-& Passagierflugzeuge Führerschein\nHelicopter Führerschein", "Weiter", "Schliessen");
  }
  if(dialogid == 19)
  {
	if(response && playerdata[playerid][29] == 0)
	{
	  fahrstunde[playerid] = 29;
	  timer_fahrschueler[playerid] = SetTimerEx("fahrschule_abbruchfahrstunde",15000,false,"i",playerid);
	  fahrschule_startefahrstunde(playerid,29,"Helicopter");
	  SendClientMessage(playerid, COLOR_RED, "Prüfe auf verfügbare Fahrlehrer ...");
	}
	else if(response && playerdata[playerid][29] == 1)
	  SendClientMessage(playerid, COLOR_RED, "Sie haben diese Lizens bereits.");
	else
	  ShowPlayerDialog(playerid, 12,DIALOG_STYLE_LIST, "Fahrschule:", "Motorrad Führerschein\nPKW Führerschein\nLKW Führerschein\nLKW mit Anhänger Führerschein\nSportboot Führerschein\nFischerboot Führerschein\nKleinflugzeug Führerschein\nFracht-& Passagierflugzeuge Führerschein\nHelicopter Führerschein", "Weiter", "Schliessen");
  }
  if(dialogid == 20)
  {
	fahrschule_fragen(playerid,1,inputtext);
  }
  if(dialogid == 21)
  {
	fahrschule_fragen(playerid,2,inputtext);
  }
  if(dialogid == 22)
  {
	fahrschule_fragen(playerid,3,inputtext);
  }
  if(dialogid == 23)
  {
	fahrschule_fragen(playerid,4,inputtext);
  }
  if(dialogid == 24)
  {
    if(response && playerdata[playerid][25] == 0)
	{
	  fahrstunde[playerid] = 28;
	  timer_fahrschueler[playerid] = SetTimerEx("fahrschule_abbruchfahrstunde",15000,false,"i",playerid);
	  fahrschule_startefahrstunde(playerid,28,"Sportboot");
	  SendClientMessage(playerid, COLOR_RED, "Prüfe auf verfügbare Fahrlehrer ...");
	}
	else if(response && playerdata[playerid][25] == 1)
	  SendClientMessage(playerid, COLOR_RED, "Sie haben diese Lizens bereits.");
	else
	  ShowPlayerDialog(playerid, 12,DIALOG_STYLE_LIST, "Fahrschule:", "Motorrad Führerschein\nPKW Führerschein\nLKW Führerschein\nLKW mit Anhänger Führerschein\nSportboot Führerschein\nFischerboot Führerschein\nKleinflugzeug Führerschein\nFracht-& Passagierflugzeuge Führerschein\nHelicopter Führerschein", "Weiter", "Schliessen");
  }
  if(dialogid == 25)
  {
    if(response && playerdata[playerid][26] == 0)
	{
	  fahrstunde[playerid] = 28;
	  timer_fahrschueler[playerid] = SetTimerEx("fahrschule_abbruchfahrstunde",15000,false,"i",playerid);
	  fahrschule_startefahrstunde(playerid,28,"Fischerboot");
	  SendClientMessage(playerid, COLOR_RED, "Prüfe auf verfügbare Fahrlehrer ...");
	}
	else if(response && playerdata[playerid][26] == 1)
	  SendClientMessage(playerid, COLOR_RED, "Sie haben diese Lizens bereits.");
	else
	  ShowPlayerDialog(playerid, 12,DIALOG_STYLE_LIST, "Fahrschule:", "Motorrad Führerschein\nPKW Führerschein\nLKW Führerschein\nLKW mit Anhänger Führerschein\nSportboot Führerschein\nFischerboot Führerschein\nKleinflugzeug Führerschein\nFracht-& Passagierflugzeuge Führerschein\nHelicopter Führerschein", "Weiter", "Schliessen");
  }
  if(dialogid == 26)
  {
    if(response && playerdata[playerid][20] == 0)
	{
	  if(giveusermoney(playerid,-1 * gebuehren(20)))
	  {
		fahrstunde[playerid] = 20;
		fahrschule_theorie(playerid);
	  }
	  else
		SendClientMessage(playerid, COLOR_RED, "Sie haben nicht genug Geld.");
	}
	else if(playerdata[playerid][20] == 1)
	  SendClientMessage(playerid, COLOR_RED, "Sie haben diese Lizens bereits.");
  }
}

public fahrschule_pruefe(lizenz)
{
  for(new i=0;i<5;i++)
  {
	if(playerdata[fahrlehrer_on[i]][lizenz] == 1 && fahrschueler[fahrlehrer_on[i]] == -1)
	  return 1;
  }
  return 0;
}

public fahrschule_auswahl(playerid,lizenz)
{
  new output[750],string[100];
  if(lizenz == 20)
  {
	strcat(output,"Allgemein:\n     Wird benötigt um alle kleinen Roller zu fahren!\n");
	strcat(output,"Vorraussetzungen: \n     keine");
	format(string,100,"Kosten:     %i\n",gebuehren(20));
	strcat(output,string);
	strcat(output,"Ablauf:\n     Zuerst musst du eine kurze Theorie Stunde ablegen und die theoretische Prüfung bestehen.\n");
	strcat(output,"     Danach wirst du den praktischen Teil durchführen.\n");
	strcat(output,"     Mit Bestehen des prakitschen Teiles erhälst du deinen Führrerschein.\n");
	ShowPlayerDialog(playerid, 26,DIALOG_STYLE_MSGBOX,"Der Roller - Führerschein",output,"Starten","Zurück");
  }
  if(lizenz == 21)
  {
	strcat(output,"Allgemein:\n     Wird benötigt um alle größeren Motorräder zu fahren!\n");
	strcat(output,"Vorraussetzungen: \n     Ist ein bestandener Roller Führerschein\n");
	format(string,100,"Kosten:     %i\n",gebuehren(21));
	strcat(output,string);
	strcat(output,"Ablauf:\n     Zuerst musst du eine kurze Theorie Stunde ablegen und die theoretische Prüfung bestehen.\n");
	strcat(output,"     Danach wird ein Fahrlehrer mit dir den praktischen Teil durchführen.\n");
	strcat(output,"     Mit Bestehen des prakitschen Teiles erhälst du deinen Führrerschein.\n");
	ShowPlayerDialog(playerid, 13,DIALOG_STYLE_MSGBOX,"Der Motorrad - Führerschein",output,"Starten","Zurück");
  }
  if(lizenz == 22)
  {
	strcat(output,"Allgemein:\n     Wird benötigt um alle Personal Kraft Wagen zu fahren!\n");
	strcat(output,"Vorraussetzungen: \n");
	format(string,100,"Kosten:     %i\n",gebuehren(22));
	strcat(output,string);
	strcat(output,"Ablauf:\n     Zuerst musst du eine kurze Theorie Stunde ablegen und die theoretische Prüfung bestehen.\n");
	strcat(output,"     Danach wird ein Fahrlehrer mit dir den praktischen Teil durchführen.\n");
	strcat(output,"     Mit Bestehen des prakitschen Teiles erhälst du deinen Führrerschein.\n");
	ShowPlayerDialog(playerid, 14,DIALOG_STYLE_MSGBOX,"Der PKW - Führerschein",output,"Starten","Zurück");
  }
  if(lizenz == 23)
  {
	strcat(output,"Allgemein:\n     Wird benötigt um alle Last Kraft Wagen ohne Anhänger zu fahren!\n");
	strcat(output,"Vorraussetzungen: \n");
	format(string,100,"Kosten:     %i\n",gebuehren(23));
	strcat(output,string);
	strcat(output,"Ablauf:\n     Zuerst musst du eine kurze Theorie Stunde ablegen und die theoretische Prüfung bestehen.\n");
	strcat(output,"     Danach wird ein Fahrlehrer mit dir den praktischen Teil durchführen.\n");
	strcat(output,"     Mit Bestehen des prakitschen Teiles erhälst du deinen Führrerschein.\n");
	ShowPlayerDialog(playerid, 15,DIALOG_STYLE_MSGBOX,"Der LKW - Führerschein",output,"Starten","Zurück");
  }
  if(lizenz == 24)
  {
	strcat(output,"Allgemein:\n     Wird benötigt um alle Last Kraft Wagen mit Anhänger zu fahren!\n");
	strcat(output,"Vorraussetzungen: \n     Ist ein bestandener LKW Führerschein\n");
	format(string,100,"Kosten:     %i\n",gebuehren(24));
	strcat(output,string);
	strcat(output,"Ablauf:\n     Zuerst musst du eine kurze Theorie Stunde ablegen und die theoretische Prüfung bestehen.\n");
	strcat(output,"     Danach wird ein Fahrlehrer mit dir den praktischen Teil durchführen.\n");
	strcat(output,"     Mit Bestehen des prakitschen Teiles erhälst du deinen Führrerschein.\n");
	ShowPlayerDialog(playerid, 16,DIALOG_STYLE_MSGBOX,"Der LKW mit Anhänger - Führerschein",output,"Starten","Zurück");
  }
  if(lizenz == 25)
  {
	strcat(output,"Allgemein:\n     Wird benötigt um alle Sportboote zu fahren!\n");
	strcat(output,"Vorraussetzungen: \n");
	format(string,100,"Kosten:     %i\n",gebuehren(25));
	strcat(output,string);
	strcat(output,"Ablauf:\n     Zuerst musst du eine kurze Theorie Stunde ablegen und die theoretische Prüfung bestehen.\n");
	strcat(output,"     Danach wird ein Fahrlehrer mit dir den praktischen Teil durchführen.\n");
	strcat(output,"     Mit Bestehen des prakitschen Teiles erhälst du deinen Führrerschein.\n");
	ShowPlayerDialog(playerid, 24,DIALOG_STYLE_MSGBOX,"Der Kleinflugzeuge - Führerschein",output,"Starten","Zurück");
  }
  if(lizenz == 26)
  {
	strcat(output,"Allgemein:\n     Wird benötigt um den Beruf des Fischers anzunehmen!\n");
	strcat(output,"Vorraussetzungen: \n     Ist ein bestandener Kleinflugzeug Führerschein\n");
	format(string,100,"Kosten:     %i\n",gebuehren(26));
	strcat(output,string);
	strcat(output,"Ablauf:\n     Zuerst musst du eine kurze Theorie Stunde ablegen und die theoretische Prüfung bestehen.\n");
	strcat(output,"     Danach wird ein Fahrlehrer mit dir den praktischen Teil durchführen.\n");
	strcat(output,"     Mit Bestehen des prakitschen Teiles erhälst du deinen Führrerschein.\n");
	ShowPlayerDialog(playerid, 25,DIALOG_STYLE_MSGBOX,"Der Fracht- & Passagierflugzeug- Führerschein",output,"Starten","Zurück");
  }
  if(lizenz == 27)
  {
	strcat(output,"Allgemein:\n     Wird benötigt um alle kleineren Flugzeuge zu fliegen!\n");
	strcat(output,"Vorraussetzungen: \n");
	format(string,100,"Kosten:     %i\n",gebuehren(27));
	strcat(output,string);
	strcat(output,"Ablauf:\n     Zuerst musst du eine kurze Theorie Stunde ablegen und die theoretische Prüfung bestehen.\n");
	strcat(output,"     Danach wird ein Fahrlehrer mit dir den praktischen Teil durchführen.\n");
	strcat(output,"     Mit Bestehen des prakitschen Teiles erhälst du deinen Führrerschein.\n");
	ShowPlayerDialog(playerid, 17,DIALOG_STYLE_MSGBOX,"Der Kleinflugzeuge - Führerschein",output,"Starten","Zurück");
  }
  if(lizenz == 28)
  {
	strcat(output,"Allgemein:\n     Wird benötigt um alle größeren Flugzeuge zu fliegen!\n");
	strcat(output,"Vorraussetzungen: \n     Ist ein bestandener Kleinflugzeug Führerschein\n");
	format(string,100,"Kosten:     %i\n",gebuehren(28));
	strcat(output,string);
	strcat(output,"Ablauf:\n     Zuerst musst du eine kurze Theorie Stunde ablegen und die theoretische Prüfung bestehen.\n");
	strcat(output,"     Danach wird ein Fahrlehrer mit dir den praktischen Teil durchführen.\n");
	strcat(output,"     Mit Bestehen des prakitschen Teiles erhälst du deinen Führrerschein.\n");
	ShowPlayerDialog(playerid, 18,DIALOG_STYLE_MSGBOX,"Der Fracht- & Passagierflugzeug- Führerschein",output,"Starten","Zurück");
  }
  if(lizenz == 29)
  {
	strcat(output,"Allgemein:\n     Wird benötigt um alle Heliopter zu fliegen!\n");
	strcat(output,"Vorraussetzungen: \n\n");
	format(string,100,"Kosten:     %i\n",gebuehren(29));
	strcat(output,string);
	strcat(output,"Ablauf:\n     Zuerst musst du eine kurze Theorie Stunde ablegen und die theoretische Prüfung bestehen.\n");
	strcat(output,"     Danach wird ein Fahrlehrer mit dir den praktischen Teil durchführen.\n");
	strcat(output,"     Mit Bestehen des prakitschen Teiles erhälst du deinen Führrerschein.\n");
	ShowPlayerDialog(playerid, 19,DIALOG_STYLE_MSGBOX,"Der Helicopter - Führerschein",output,"Starten","Zurück");
  }
}

public fahrschule_startefahrstunde(playerid,lizenz,lizenzname[])
{
  for(new i=0;i<5;i++)
  {
	if(playerdata[fahrlehrer_on[i]][lizenz] == 1 && fahrschueler[fahrlehrer_on[i]] < 0)
	{
	  new pname[100],output[150];
	  GetPlayerName(playerid,pname,100);
	  format(output,150,"~w~%s beantragt eine %s Fahrstunde~n~Annehmen: /fan %i",pname,lizenzname,playerid);
	  GameTextForPlayer(fahrlehrer_on[i], output, 8000, 3);
	}
  }
}

public fahrschule_abbruchfahrstunde(playerid)
{
  fahrstunde[playerid] = 0;
  GameTextForPlayer(playerid, "~w~Im Moment hat kein Fahrlehrer Zeit ~n~Versuche es später erneut", 5000, 3);
}

public fahrschule_annahmestunde(lehrerid,schuelerid)
{
  new ok = 1;
  for(new i=0;i <5;i++)
  {
	if(fahrlehrer_on[i] > -1)
	{
	  if(fahrschueler[fahrlehrer_on[i]] == schuelerid) ok = 0;
	}
  }
  
  if(ok && fahrstunde[schuelerid] > 0)
  {
	KillTimer(timer_fahrschueler[schuelerid]);
	//Lehrerausgabe
	GameTextForPlayer(lehrerid, "~w~Fahrstunde angeommen.~n~ Gehen Sie zum Tor", 5000, 3);
	new pname[100],output[150],lizenz[50];
	GetPlayerName(schuelerid,pname,100);
	switch(fahrstunde[schuelerid])
	{
	  case 21:{ lizenz = "Motorrad";}
	  case 22:{ lizenz = "PKW";}
	  case 23:{ lizenz = "LKW";}
	  case 24:{ lizenz = "LKW mit Anhänger";}
	  case 25:{ lizenz = "Sportboot";}
	  case 26:{ lizenz = "Fischer";}
	  case 27:{ lizenz = "Kleinflugzeug";}
	  case 28:{ lizenz = "Airbus";}
	  case 29:{ lizenz = "Helicopter";}
	}
	giveusermoney(schuelerid,-1 * gebuehren(fahrstunde[schuelerid]));
	format(output,150,"Fahrstunde %s: Schüler - %s",lizenz,pname);
	SendClientMessage(lehrerid, COLOR_YELLOW, output);
	fahrschueler[lehrerid] = schuelerid;
	
	//Schülerausgabe
	GameTextForPlayer(schuelerid, "~w~Fahrstunde angeommen Theorie startet", 3000, 3);
	GetPlayerName(lehrerid,pname,100);
	format(output,150,"Fahrstunde %s: Lehrer - %s",lizenz,pname);
	SendClientMessage(schuelerid, COLOR_YELLOW, output);
	
	//--------Theorie
	fahrschule_theorie(schuelerid);
  }
  else
	SendClientMessage(lehrerid, COLOR_YELLOW, "Schüler bereits vergeben");
}

public fahrschule_theorie(playerid)
{
  new output[500];
  switch(fahrstunde[playerid])
  {
	case 20:
	//Roller - Theorie
	{
	  strcat(output,"Allgemeine Strassen Regeln:\n");
	  strcat(output,"   An Kreuzungen ohne Ampeln gilt Rechts vor Links\n");
	  strcat(output,"   Innerhalb von Ortschaften darf höchstens 70 Km/h gefahren werden\n");
	  strcat(output,"   Außerhalb von Ortschaften höchstens 100 Km/h \n");
	  strcat(output,"   Auf der Autobahn gilt eine Richtgeschwindigkeit von 130 km/h \n");
	  strcat(output,"Fahrzeug Regeln:\n");
	  strcat(output,"   Der Motor eines Fahrzeuges wird (Standart -Z-) gestartet\n");
	  strcat(output,"   Zweiräder haben eine ganztägige Lichtpflicht (Standart -N-)\n");
	  ShowPlayerDialog(playerid, 20,DIALOG_STYLE_MSGBOX,"Der Roller - Führerschein Theorie:",output,"Fragen","");
	}
	case 21:
	//Motorrad - Theorie
	{
	  strcat(output,"Allgemeine Strassen Regeln:\n");
	  strcat(output,"   An Kreuzungen ohne Ampeln gilt Rechts vor Links\n");
	  strcat(output,"   Innerhalb von Ortschaften darf höchstens 70 Km/h gefahren werden\n");
	  strcat(output,"   Außerhalb von Ortschaften höchstens 100 Km/h \n");
	  strcat(output,"   Auf der Autobahn gilt eine Richtgeschwindigkeit von 130 km/h \n");
	  strcat(output,"Fahrzeug Regeln:\n");
	  strcat(output,"   Der Motor eines Fahrzeuges wird (Standart -Z-) gestartet\n");
	  strcat(output,"   Zweiräder haben eine ganztägige Lichtpflicht (Standart -N-)\n");
	  ShowPlayerDialog(playerid, 20,DIALOG_STYLE_MSGBOX,"Der Motorrad - Führerschein Theorie:",output,"Fragen","");
	}
	case 22:
	//PKW - Theorie
	{
	  strcat(output,"Allgemeine Strassen Regeln:\n");
	  strcat(output,"   An Kreuzungen ohne Ampeln gilt Rechts vor Links\n");
	  strcat(output,"   Innerhalb von Ortschaften darf höchstens 70 Km/h gefahren werden\n");
	  strcat(output,"   Außerhalb von Ortschaften höchstens 100 Km/h \n");
	  strcat(output,"   Auf der Autobahn gilt eine Richtgeschwindigkeit von 130 km/h \n");
	  strcat(output,"Fahrzeug Regeln:\n");
	  strcat(output,"   Der Motor eines Fahrzeuges wird (Standart -Z-) gestartet\n");
	  strcat(output,"   Licht muss von 20-6 Uhr eingeschaltet sein (Standart -N-)\n");
	  ShowPlayerDialog(playerid, 20,DIALOG_STYLE_MSGBOX,"Der PKW - Führerschein Theorie:",output,"Fragen","");
	}
	case 23:
	//LKW - Theorie
	{
	  strcat(output,"Allgemeine Strassen Regeln:\n");
	  strcat(output,"   An Kreuzungen ohne Ampeln gilt Rechts vor Links\n");
	  strcat(output,"   Innerhalb von Ortschaften darf höchstens 70 Km/h gefahren werden\n");
	  strcat(output,"   Außerhalb von Ortschaften höchstens 100 Km/h \n");
	  strcat(output,"Fahrzeug Regeln:\n");
	  strcat(output,"   Der Motor eines Fahrzeuges wird (Standart -Z-) gestartet\n");
	  strcat(output,"   LKWs haben eine ganztägige Lichtpflicht (Standart -N-)\n");
	  ShowPlayerDialog(playerid, 20,DIALOG_STYLE_MSGBOX,"Der LKW - Führerschein Theorie:",output,"Fragen","");
	}
	case 24:
	//LKW mit Anhänger - Theorie
	{
	  strcat(output,"Allgemeine Strassen Regeln:\n");
	  strcat(output,"   An Kreuzungen ohne Ampeln gilt Rechts vor Links\n");
	  strcat(output,"   Innerhalb von Ortschaften darf höchstens 70 Km/h gefahren werden\n");
	  strcat(output,"   Außerhalb von Ortschaften höchstens 100 Km/h \n");
      strcat(output,"   Im Bereich von Tankstellen ist besondere Vorsicht geboten !Explosionsgefahr!\n");
	  strcat(output,"Fahrzeug Regeln:\n");
	  strcat(output,"   Der Motor eines Fahrzeuges wird (Standart -Z-) gestartet\n");
	  strcat(output,"   Im Bereich von Tankstellen ist besondere Vorsicht geboten !Explosionsgefahr!\n");
      strcat(output,"   Anhänger werden bei Missionen automatisch an- und abgekuppelt\n");
	  ShowPlayerDialog(playerid, 20,DIALOG_STYLE_MSGBOX,"Der LKW mit Anhänger - Führerschein Theorie:",output,"Fragen","");
	}
	case 25:
	//Sportboot - Theorie
	{
	  strcat(output,"Allgemeine  Regeln:\n");
	  strcat(output,"     Der Berufsschifffahrt (Fischerbooten) ist Vorfahrt zu gewähren\n");
	  strcat(output,"     In Häfen und Anlegestellen gilt eine Maximalgeschwindigkeit von 40 km/h\n");
      strcat(output,"	  Im Hafen gilt bei gleichen Bootsarten Rechts vor Links\n");
      strcat(output,"Fahrzeug Regeln:\n");
	  strcat(output,"     Der Motor eines Bootes wird (Standart -Z-) gestartet\n");
	  ShowPlayerDialog(playerid, 20,DIALOG_STYLE_MSGBOX,"Der Sportboot - Führerschein Theorie:",output,"Fragen","");
	}
	case 26:
	//Fischerboot - Theorie
	{
	  strcat(output,"Allgemeine  Regeln:\n");
	  strcat(output,"     Der Berufsschifffahrt (Fischerboote) hat Vorfahrt gegenüber Freizeitbooten\n");
      strcat(output,"     In Häfen und Anlegestellen gilt eine Maximalgeschwindigkeit von 40 km/h\n");
      strcat(output,"	  Im Hafen gilt bei gleichen Bootsarten Rechts vor Links\n");
	  strcat(output,"Fahrzeug Regeln:\n");
	  strcat(output,"     Der Motor eines Bootes wird (Standart -Z-) gestartet\n");
	  ShowPlayerDialog(playerid, 20,DIALOG_STYLE_MSGBOX,"Der Fischerboot - Führerschein Theorie:",output,"Fragen","");
	}
	case 27:
	//Kleinflugzeug - Theorie
	{
	  strcat(output,"Allgemeine  Regeln:\n");
	  strcat(output,"     Vor jedem Start / Landung muss Erlaubnis für die jeweilige Bahn bantragt werden\n");
	  strcat(output,"	  Auf dem Flughafen gilt landenden Maschinen wird Vorrang gegeben\n");
	  strcat(output,"     Weiterhin gilt eine Geschwindigkeitsbeschränkung von 50 km/h\n");
	  strcat(output,"     Wenn vorhanden werden Fahrmarkierung benutzt!\n");
	  strcat(output,"Fahrzeug Regeln:\n");
	  strcat(output,"     Der Motor eines Fahrzeuges wird (Standart -Z-) gestartet\n");
	  ShowPlayerDialog(playerid, 20,DIALOG_STYLE_MSGBOX,"Der Kleinflugzeug - Führerschein Theorie:",output,"Fragen","");
	}
	case 28:
	//Airbus - Theorie
	{
	  strcat(output,"Allgemeine  Regeln:\n");
	  strcat(output,"     Vor jedem Start / Landung muss Erlaubnis für die jeweilige Bahn bantragt werden\n");
	  strcat(output,"	  Auf dem Flughafen gilt landenden Maschinen wird Vorrang gegeben\n");
	  strcat(output,"     Weiterhin gilt eine Geschwindigkeitsbeschränkung von 50 km/h\n");
	  strcat(output,"     Wenn vorhanden werden Fahrmarkierung benutzt!\n");
	  strcat(output,"Fahrzeug Regeln:\n");
	  strcat(output,"     Der Motor eines Fahrzeuges wird (Standart -Z-) gestartet\n");
	  ShowPlayerDialog(playerid, 20,DIALOG_STYLE_MSGBOX,"Der Airbus - Führerschein Theorie:",output,"Fragen","");
	}
	case 29:
	//Helicopter - Theorie
	{
	  strcat(output,"Allgemeine  Regeln:\n");
	  strcat(output,"     Für Hubschrauber gibt es keine Signale für Start und Landung\n");
	  strcat(output,"	            Flugzuege haben stets Vorrang\n");
	  strcat(output,"     Für die Fortbewegung ist die untere Flughöhe zu wählen\n");
	  strcat(output,"           Tiefflug in bewohnten Gebieten ist untersagt\n");
	  strcat(output,"Fahrzeug Regeln:\n");
	  strcat(output,"     Der Motor eines Fahrzeuges wird (Standart -Z-) gestartet\n");
      strcat(output,"     Der Hubschrauber wird mit (Standart -H-) ruhig gestellt und kann\n");
      strcat(output,"           bei gedrückter Taste nur noch hoch und runter manövrieren\n");
	  ShowPlayerDialog(playerid, 20,DIALOG_STYLE_MSGBOX,"Der Helicopter - Führerschein Theorie:",output,"Fragen","");
	}
  }
}

public fahrschule_stundenende(lehrerid,kind)
{
  new schuelerid = fahrschueler[lehrerid];
  new lizenz = fahrstunde[schuelerid];
  giveusermoney(lehrerid,gebuehren(fahrstunde[schuelerid]));
  if(kind == 0 && schuelerid >= 0 && lizenz > 0)
  {
	setuserlizens(schuelerid,lizenz,lehrerid);
	GameTextForPlayer(schuelerid, "~w~Fahrstunde beendet~n~Sie haben bestanden", 3000, 3);
	GameTextForPlayer(lehrerid, "~w~Fahrstunde beendet", 3000, 3);
	fahrschueler[lehrerid] = -1;
	fahrstunde[schuelerid] = 0;
    RemovePlayerFromVehicle(schuelerid);
  }
  else if(kind == 1 && schuelerid >= 0 && lizenz > 0)
  {
	GameTextForPlayer(schuelerid, "~w~Fahrstunde beendet~n~Sie sind durchgefallen", 3000, 3);
	GameTextForPlayer(lehrerid, "~w~Fahrstunde beendet", 3000, 3);
	fahrschueler[lehrerid] = -1;
	fahrstunde[schuelerid] = 0;
    RemovePlayerFromVehicle(schuelerid);
  }
  return 1;
}

public fahrschule_stundenendeschueler(schuelerid)
{
  new lehrerid;
  for(new i=0;i < 5;i++)
  {
	if(fahrlehrer_on[i]>= 0 && fahrschueler[fahrlehrer_on[i]] == schuelerid)
	  lehrerid = fahrlehrer_on[i];
  }
  GameTextForPlayer(schuelerid, "~w~Fahrstunde beendet", 3000, 3);
  GameTextForPlayer(lehrerid, "~w~Fahrstunde beendet", 3000, 3);
  fahrschueler[lehrerid] = -1;
  giveusermoney(lehrerid,gebuehren(fahrstunde[schuelerid]));
  fahrstunde[schuelerid] = 0;
  return 1;
}

public fahrschule_stundenendelehrer(lehrerid)
{
  new schuelerid = fahrschueler[lehrerid];
  if(schuelerid >= 0)
  {
	GameTextForPlayer(schuelerid, "~w~Fahrstunde beendet", 3000, 3);
	GameTextForPlayer(lehrerid, "~w~Fahrstunde beendet", 3000, 3);
	fahrschueler[lehrerid] = -1;
	giveusermoney(schuelerid,gebuehren(fahrstunde[schuelerid]));
	fahrstunde[schuelerid] = 0;
    RemovePlayerFromVehicle(schuelerid);
  }
  return 1;
}

public fahrschule_lehrerdisconnect(lehrerid)
{
  new schuelerid = fahrschueler[lehrerid];
  for(new i=0;i < 5;i++)
  {
	if(fahrlehrer_on[i] == lehrerid && schuelerid >= 0)
    {
      GameTextForPlayer(schuelerid, "~w~Fahrstunde beendet", 3000, 3);
      GameTextForPlayer(lehrerid, "~w~Fahrstunde beendet", 3000, 3);
      fahrschueler[lehrerid] = -1;
      giveusermoney(schuelerid,gebuehren(fahrstunde[schuelerid]));
      fahrstunde[schuelerid] = 0;
      fahrlehrer_on[i] = -1;
      RemovePlayerFromVehicle(schuelerid);
    }
  }
  return 1;
}

public fahrschule_fragen(playerid,anz,input[])
{
  switch(fahrstunde[playerid])
  {
	case 20:
	//Roller - Fragen
	{
	  switch(anz)
	  {
		case 1:
		{
		  GameTextForPlayer(playerid, "~w~Theorie bestanden. Gehen Sie zu Ihrem Roller", 3000, 3);
		  rollerf(playerid);
		  rollerfahr[playerid] = 0;
		  rollerstraf[playerid] = 0;
		}
	  }
	}
	case 21:
	//Motorrad - Fragen
	{
	  switch(anz)
	  {
		//erste Frage
		case 1: ShowPlayerDialog(playerid, 21,DIALOG_STYLE_INPUT,"Der Motorrad - Führerschein Frage 1:","Wie ist die maximale Geschwindigkeit innerorts:","Weiter","");
		case 2:
		{
		  if(strcmp(input,"70",true)) fahrschule_fragen(playerid,1,"");
		  else ShowPlayerDialog(playerid, 22,DIALOG_STYLE_INPUT,"Der Motorrad - Führerschein Frage 2:","Wie ist die maximale Geschwindigkeit ausserorts:","Weiter","");
		}
		case 3:
		{
		  if(strcmp(input,"100",true)) fahrschule_fragen(playerid,2,"70");
		  else ShowPlayerDialog(playerid, 23,DIALOG_STYLE_INPUT,"Der Motorrad - Führerschein Frage 3:","Wie ist die Taste zum starten des Motors:","Weiter","");
		}
		case 4:
		{
		  if(strcmp(input,"z",true)) fahrschule_fragen(playerid,3,"100");
		  else
		  {
			GameTextForPlayer(playerid, "~w~Theorie bestanden gehen Sie zu Ihrem Lehrer", 3000, 3);
			new lehrerid;
			for(new i=0;i < 5;i++)
			{
			  if(fahrschueler[fahrlehrer_on[i]] == playerid)
				lehrerid = fahrlehrer_on[i];
			}
			GameTextForPlayer(lehrerid, "~w~Schueler Theorie bestanden", 3000, 3);
		  }
		}
	  }
	}
    case 22:
    //Fragen Auto
    {
      switch(anz)
      {
        case 1: ShowPlayerDialog(playerid, 21,DIALOG_STYLE_INPUT,"Der PKW - Führerschein Frage 1:","Wie ist die maximale Geschwindigkeit innerorts:","Weiter","");
		case 2:
		{
		  if(strcmp(input,"70",true)) fahrschule_fragen(playerid,1,"");
		  else ShowPlayerDialog(playerid, 22,DIALOG_STYLE_INPUT,"Der PKW - Führerschein Frage 2:","Wie ist die maximale Geschwindigkeit ausserorts:","Weiter","");
		}
		case 3:
		{
		  if(strcmp(input,"100",true)) fahrschule_fragen(playerid,2,"70");
		  else ShowPlayerDialog(playerid, 23,DIALOG_STYLE_INPUT,"Der PKW - Führerschein Frage 3:","Ab welcher Uhrzeit gilt die Lichtpflicht:","Weiter","");
		}
		case 4:
		{
		  if(strcmp(input,"2000",true)) fahrschule_fragen(playerid,3,"100");
		  else
		  {
			GameTextForPlayer(playerid, "~w~Theorie bestanden gehen Sie zu Ihrem Lehrer", 3000, 3);
			new lehrerid;
			for(new i=0;i < 5;i++)
			{
			  if(fahrschueler[fahrlehrer_on[i]] == playerid)
				lehrerid = fahrlehrer_on[i];
			}
			GameTextForPlayer(lehrerid, "~w~Schueler Theorie bestanden", 3000, 3);
		  }
		}
      }
    }
    case 23:
    //Fragen LKW
    {
      switch(anz)
      {
        case 1: ShowPlayerDialog(playerid, 21,DIALOG_STYLE_INPUT,"Der LKW - Führerschein Frage 1:","Wie ist die maximale Geschwindigkeit innerorts:","Weiter","");
		case 2:
		{
		  if(strcmp(input,"70",true)) fahrschule_fragen(playerid,1,"");
		  else ShowPlayerDialog(playerid, 22,DIALOG_STYLE_INPUT,"Der LKW - Führerschein Frage 2:","Wie ist die maximale Geschwindigkeit ausserorts:","Weiter","");
		}
		case 3:
		{
		  if(strcmp(input,"100",true)) fahrschule_fragen(playerid,2,"70");
		  else ShowPlayerDialog(playerid, 23,DIALOG_STYLE_INPUT,"Der LKW - Führerschein Frage 3:","Gilt für LKWs eine ganztägige lichtpflicht (J/N):","Weiter","");
		}
		case 4:
		{
		  if(strcmp(input,"J",true)) fahrschule_fragen(playerid,3,"100");
		  else
		  {
			GameTextForPlayer(playerid, "~w~Theorie bestanden gehen Sie zu Ihrem Lehrer", 3000, 3);
			new lehrerid;
			for(new i=0;i < 5;i++)
			{
			  if(fahrschueler[fahrlehrer_on[i]] == playerid)
				lehrerid = fahrlehrer_on[i];
			}
			GameTextForPlayer(lehrerid, "~w~Schueler Theorie bestanden", 3000, 3);
		  }
		}
      }
    }
  }
}

public gebuehren(lizenz)
{
  switch(lizenz)
  {
	case 20:return 500; // Roller
        case 21:return 1000; // Motorrad
	case 22:return 1500; // PKW
	case 23:return 5000; // LKW
	case 24:return 3000; // LKW mit Anhänger
	case 25:return 350; // Sportboot
	case 26:return 1800; // Fischer
	case 27:return 10000; // Kleinflugzeug
	case 28:return 20000; // Airbus
	case 29:return 15000; // Helicopter
  }
  return 0;
}

public fahrschule_landungbeantragen(playerid)
{
  new schuelerid = fahrschueler[playerid];
  if(schuelerid >= 0 && fahrstunde[schuelerid] == 27 || fahrstunde[schuelerid] == 28)
  {
	navivar[schuelerid] = 2;
	SetPlayerRaceCheckpoint(schuelerid,CP_TYPE:3,-920.12, 580.82, 118.05,-920.12, 580.82, 118.05, 20);
	GameTextForPlayer(playerid,"~w~Landungscheckpoint gesetzt",3000,3);
	fstart[schuelerid] = 5;
  }
}

public fahrschule_startbeantragen(playerid)
{
  new schuelerid = fahrschueler[playerid];
  if(schuelerid >= 0 && fahrstunde[schuelerid] == 27 || fahrstunde[schuelerid] == 28)
  {
	navivar[schuelerid] = 2;
	SetPlayerCheckpoint(schuelerid,-1681.95,  -192.29,  14.06,5);
	GameTextForPlayer(playerid,"~w~Startcheckpoint gesetzt",3000,3);
	fstart[schuelerid] = 1;
  }
}

public fahrschule_startlandeabwarten(playerid)
{
  if((fstart[playerid] == 5 ||fstart[playerid] == 1) && erlaubnislandbahn(1))
  {
	new lehrerid;
	for(new i=0;i < 5;i++)
	{
	  if(fahrlehrer_on[i]>= 0 && fahrschueler[fahrlehrer_on[i]] == playerid)
		lehrerid = fahrlehrer_on[i];
	}
	landebahnsf = 1;
	if(fstart[playerid] == 5)
	{
	  GameTextForPlayer(playerid,"~w~Sie haben Landeerlaubnis bekommen",3000,3);
	  SetPlayerCheckpoint(playerid,-1681.95,  -192.29,  14.06,5);
	  GameTextForPlayer(lehrerid,"~w~Sie haben Landeerlaubnis bekommen",3000,3);
	}
	else
	{
	  GameTextForPlayer(playerid,"~w~Sie haben Starterlaubnis bekommen",3000,3);
	  GameTextForPlayer(lehrerid,"~w~Sie haben Starterlaubnis bekommen",3000,3);
	  SetPlayerRaceCheckpoint(playerid,CP_TYPE:3,-920.12, 580.82, 118.05,-920.12, 580.82, 118.05,20);
	}
	fstart[playerid]++;
  }
  else if(fstart[playerid] == 6 || fstart[playerid] == 2)
  {
	new lehrerid;
	for(new i=0;i < 5;i++)
	{
	  if(fahrlehrer_on[i]>= 0 && fahrschueler[fahrlehrer_on[i]] == playerid)
		lehrerid = fahrlehrer_on[i];
	}
	GameTextForPlayer(lehrerid,"~w~Startbahn frei",3000,3);
	navivar[playerid] = 0;
	landebahnsf = 0;
  }
  else
  {
    if(fstart[playerid] == 1)
      GameTextForPlayer(playerid,"~r~keine~w~Starterlaubnis~n~warten Sie!",5000,3);
    if(fstart[playerid] == 5)
      GameTextForPlayer(playerid,"~r~keine~w~Landeerlaubnis~n~fliegen Sie eine Schleife!",5000,3);
	if(IsPlayerConnected(playerid))
	  SetTimerEx("fahrschule_startlandeabwarten",5000,false,"i",playerid);
  }
}

public fahrschule_statechange(playerid, newstate, oldstate)
{
  new mid = GetVehicleModel(GetPlayerVehicleID(playerid));
  if(PLAYER_STATE:newstate == PLAYER_STATE_DRIVER && (mid == 511 || mid == 553 || mid == 581|| mid == 454 ||
                                         mid == 507|| mid == 578|| mid == 515|| mid == 446 ||
                                         mid == 457|| mid == 469|| mid == 548 || mid == 448))
  {
    if(playerdata[playerid][2] == 3 && mid != 448)
    {
      new ok = 0;
      for(new i=0;i < 5;i++)
      {
        if(fahrlehrer_on[i] == playerid)
        {
          ok = 1;
        }
      }
      if(ok != 1)
      {
        RemovePlayerFromVehicle(playerid);
		new string[50];
		format(string, sizeof(string), "~w~Du bist nicht~n~~y~im Dienst");
		GameTextForPlayer(playerid, string, 3000, 1);
		SendClientMessage(playerid, COLOR_RED, "*** Nur Fahrlehrer im Dienst dürfen dieses Fahrzeug benutzen ***");
      }
    }
    else
    {
      new ok = 0;
	  if(fahrstunde[playerid] == 20)
		ok = 1;
	  else
	  {
		for(new i=0;i < 5;i++)
		{
		  if(fahrlehrer_on[i] >= 0 && fahrschueler[fahrlehrer_on[i]] == playerid)
		  {
			ok = 1;
		  }
		}
	  }
      if(ok != 1)
      {
        RemovePlayerFromVehicle(playerid);
		new string[50];
		format(string, sizeof(string), "~w~Du bist kein~n~~y~Fahrschueler");
		GameTextForPlayer(playerid, string, 3000, 1);
		SendClientMessage(playerid, COLOR_RED, "*** Nur Fahrschüler dürfen dieses Fahrzeug benutzen ***");
      }
    }
  }
}

public admin_statechange(playerid, newstate, oldstate)
{
  if(PLAYER_STATE:newstate == PLAYER_STATE_DRIVER && GetVehicleModel(GetPlayerVehicleID(playerid)) == 520)
  {
    if(playerdata[playerid][33] == 3 || playerdata[playerid][2] == 3)
    {
      if(playerdata[playerid][2] == 3)
      {
        new ok = 0;
        for(new i=0;i < 5;i++)
        {
          if(fahrlehrer_on[i] == playerid)
          {
            ok = 1;
          }
        }
        if(ok != 1)
        {
          RemovePlayerFromVehicle(playerid);
          new string[50];
          format(string, sizeof(string), "~w~Du bist nicht~n~~y~im Dienst");
          GameTextForPlayer(playerid, string, 3000, 1);
          SendClientMessage(playerid, COLOR_RED, "*** Nur Fahrlehrer im Dienst dürfen dieses Fahrzeug benutzen ***");
        }
      }
    }
    else
    {
      RemovePlayerFromVehicle(playerid);
      new string[50];
      format(string, sizeof(string), "~w~Du bist nicht~n~~y~im Dienst");
      GameTextForPlayer(playerid, string, 3000, 1);
      SendClientMessage(playerid, COLOR_RED, "*** Nur Fahrlehrer im Dienst dürfen dieses Fahrzeug benutzen ***");
    }
  }
}
