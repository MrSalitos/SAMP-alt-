forward navi(playerid,ort[]);
forward navibox(playerid);
forward navi_response(playerid, dialogid, response, listitem, inputtext[]);
forward navi_geschaefte(playerid);
forward navi_behoerden(playerid);
forward navi_depots(playerid);
forward navi_nextbank(playerid);
forward navi_nextfast(playerid);
forward navi_nextpnspray(playerid);
forward navi_mietwagen(playerid);

public navi(playerid,ort[])
{
  if(navivar[playerid] == 2)
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Keine Navigation möglich.");
  }
  else if(strlen(ort) < 1)
  {
	navibox(playerid);
  }
  else if(!strcmp(ort,"fkurier",true))
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Ziel gesetzt auf Fahrradkurierdepot gesetzt.");
    SetPlayerCheckpoint(playerid,1102,-1201,17.8,5.0);
    navivar[playerid] = 1;
  }
  else if(!strcmp(ort,"stop",true))
  {
	if(navivar[playerid]== 1)
	{
	  SendClientMessage(playerid,COLOR_YELLOW,"Navigation abgebrochen.");
	  DisablePlayerCheckpoint(playerid);
	  navivar[playerid]= 0;
	}
  }
  else if(!strcmp(ort,"LSPD",true))
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Ziel gesetzt auf LSPD gesetzt.");
    SetPlayerCheckpoint(playerid,CP_LSPD,5.0);
    navivar[playerid]= 1;
  }
  else if(!strcmp(ort,"SFPD",true))
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Ziel gesetzt auf SFPD gesetzt.");
    SetPlayerCheckpoint(playerid,CP_SFPD,5.0);
    navivar[playerid]= 1;
  }
  else if(!strcmp(ort,"LVPD",true))
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Ziel gesetzt auf LVPD gesetzt.");
    SetPlayerCheckpoint(playerid,CP_LVPD,5.0);
    navivar[playerid]= 1;
  }
  else if(!strcmp(ort,"Sheriff_Dillimore",true))
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Ziel: Der Sheriff in Dillimore");
    SetPlayerCheckpoint(playerid,CP_SHERIFF_DILLIMORE,5.0);
    navivar[playerid]= 1;
  }
  else if(!strcmp(ort,"Sheriff_AngelPine",true))
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Ziel: Der Sheriff in Angel Pine");
    SetPlayerCheckpoint(playerid,CP_SHERIFF_ANGELPINE,5.0);
    navivar[playerid]= 1;
  }
  else if(!strcmp(ort,"Sheriff_ElQuedbrados",true))
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Ziel: Der Sheriff in El Quedbrados");
    SetPlayerCheckpoint(playerid,CP_SHERIFF_ELQUEDBRADOS,5.0);
    navivar[playerid]= 1;
  }
  else if(!strcmp(ort,"Sheriff_FortCarson",true))
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Ziel: Der Sheriff in Fort Carson");
    SetPlayerCheckpoint(playerid,CP_SHERIFF_FORTCARSON,5.0);
    navivar[playerid]= 1;
  }
  else if(!strcmp(ort,"versls",true))
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Ziel: Versicherung Los Santos");
    SetPlayerCheckpoint(playerid,1110.65, -1795.96, 16.6,5.0);
    navivar[playerid]= 1;
  }
  else if(!strcmp(ort,"verssf",true))
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Ziel: Versicherung San Fierro");
    SetPlayerCheckpoint(playerid,-2664.78, -9.99, 6.0,5.0);
    navivar[playerid]= 1;
  }
  else if(!strcmp(ort,"verslv",true))
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Ziel: Versicherung Las Venturas");
    SetPlayerCheckpoint(playerid,1841.92, 2155.90, 11.3,5.0);
    navivar[playerid]= 1;
  }
  else if(!strcmp(ort,"Gebrlso",true))
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Ziel: Gebrauchtwagenhändler Los Santos Ost");
    SetPlayerCheckpoint(playerid,2126.56, -1138.36, 25.3,25.0);
    navivar[playerid]= 1;
  }
  else if(!strcmp(ort,"Gebrlss",true))
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Ziel: Gebrauchtwagenhändler Los Santos Süd");
    SetPlayerCheckpoint(playerid,1077.50, -1772.77, 13.24,35.0);
    navivar[playerid]= 1;
  }
  else if(!strcmp(ort,"autosf1",true))
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Ziel: Autohändler San Fierro");
    SetPlayerCheckpoint(playerid,-1956.18, 292.73, 35.46,35.0);
    navivar[playerid]= 1;
  }
  else if(!strcmp(ort,"autosf2",true))
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Ziel: Autohändler San Fierro");
    SetPlayerCheckpoint(playerid,-1662.47, 1214.05, 7.25,35.0);
    navivar[playerid]= 1;
  }
  else if(!strcmp(ort,"autolv",true))
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Ziel: Autohändler Las Venturas");
    SetPlayerCheckpoint(playerid,1938.45, 1772.51, 12.55,45.0);
    navivar[playerid]= 1;
  }
  else if(!strcmp(ort,"Fahrschule",true))
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Ziel: Fahrschule.");
    SetPlayerCheckpoint(playerid,-1545.91,-442.25,6.00,15.0);
    navivar[playerid]= 1;
  }
  else if(!strcmp(ort,"Berufsschule",true))
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Ziel: Berufsschule.");
    SetPlayerCheckpoint(playerid,1218.51, -1692.62, 20,8.0);
    navivar[playerid]= 1;
  }
  else if(!strcmp(ort,"Rathaus",true))
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Ziel: Rathaus.");
    SetPlayerCheckpoint(playerid,1286,-1329.3,13.5,8.0);
    navivar[playerid]= 1;
  }
  else if(!strcmp(ort,"Postamt",true))
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Ziel: Postamt.");
    SetPlayerCheckpoint(playerid,-1749.69,  870.55,  25.5,8.0);
    navivar[playerid]= 1;
  }
  else if(!strcmp(ort,"limof",true))
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Ziel: Limosinenfahrerdepot.");
    SetPlayerCheckpoint(playerid,2327.12,1459.86,42.82,8.0);
    navivar[playerid]= 1;
  }
  else if(!strcmp(ort,"pilotd",true))
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Ziel: Pilotendepot.");
    SetPlayerCheckpoint(playerid,-1328.01,  -397.49,  14.14,8.0);
    navivar[playerid]= 1;
  }
  else if(!strcmp(ort,"truck",true))
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Ziel: Truckdepot.");
    SetPlayerCheckpoint(playerid,-76.4,  -352.7,  2.8,8.0);
    navivar[playerid]= 1;
  }
  else if(!strcmp(ort,"limof",true))
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Ziel: Limousinenfahrerdepot.");
    SetPlayerCheckpoint(playerid,2353.85,  1419.0,  42.39,20.0);
    navivar[playerid]= 1;
  }
  else
	navibox(playerid);
}

public navibox(playerid)
{
  ShowPlayerDialog(playerid, 50,DIALOG_STYLE_LIST, "Navigation:", "öffentliche Geschäfte\nBehörden\nDepots\nnächste Bank(Automat)\nnächster Fastfoodstand\nnächster Mietwagen", "Öffnen", "Schliessen");
}

public navi_response(playerid, dialogid, response, listitem, inputtext[])
{
  if(dialogid == 50 && response)
  {
	switch(listitem)
	{
	  case 0: navi_geschaefte(playerid);
	  case 1: navi_behoerden(playerid);
	  case 2: navi_depots(playerid);
	  case 3: navi_nextbank(playerid);
	  case 4: navi_nextfast(playerid);
      case 5: navi_mietwagen(playerid);
	}
  }
  if(dialogid == 52)
  {
	if(response)
	{
	  switch(listitem)
	  {
        case 0: navi(playerid,"Gebrlso");
        case 1: navi(playerid,"Gebrlss");
        case 2: navi(playerid,"autosf1");
        case 3: navi(playerid,"autosf2");
        case 4: navi(playerid,"autolv");
	  }
	}
	else
	  navibox(playerid);
  }
  if(dialogid == 53)
  {
	if(response)
	{
	  switch(listitem)
	  {
		case 0: navi(playerid,"lspd");
		case 1: navi(playerid,"sfpd");
		case 2: navi(playerid,"lvpd");
		case 3: navi(playerid,"Sheriff_Dillimore");
		case 4: navi(playerid,"Sheriff_AngelPine");
		case 5: navi(playerid,"Sheriff_ElQuedbrados");
		case 6: navi(playerid,"Sheriff_FortCarson");
		case 7: navi(playerid,"Fahrschule");
		case 8: navi(playerid,"Berufsschule");
		case 9: navi(playerid,"Rathaus");
		case 10: navi(playerid,"Postamt");
        case 11: navi(playerid,"versls");
        case 12: navi(playerid,"verssf");
        case 13: navi(playerid,"verslv");
	  }
	}
	else
	  navibox(playerid);
  }
  if(dialogid == 54)
  {
	if(response)
	{
	  switch(listitem)
	  {
		case 0: navi(playerid,"fkurier");
        case 1: navi(playerid,"limof");
        case 2: navi(playerid,"truck");
        case 3: navi(playerid,"postb");
        case 4: navi(playerid,"proddls");
        case 5: navi(playerid,"proddsf");
        case 6: navi(playerid,"proddlv");
	  }
	}
	else
	  navibox(playerid);
  }
}

public navi_geschaefte(playerid)
{
  ShowPlayerDialog(playerid, 52,DIALOG_STYLE_LIST, "öffentliche Geschäfte:", "Gebrauchtwagenhändler LS Ost\nGebrauchtwagenhändler LS Süd\nAutohaus SF 1\nAutohaus SF 2\nLuxus - Motorrad Autohaus LV", "Starten", "Zurück");
}

public navi_behoerden(playerid)
{
  ShowPlayerDialog(playerid, 53,DIALOG_STYLE_LIST, "Behörden:", "LSPD\nSFPD\nLVPD\nSheriff Dillimore\nSheriff AngelPine\nSheriff ElQuedbrados\nSheriff FortCarson\nFahrschule\nBerufsschule\nRathaus\nPostamt\nVersicherung LS\nVersicherung SF\nVersicherung LV", "Starten", "Zurück");
}

public navi_depots(playerid)
{
  ShowPlayerDialog(playerid, 54,DIALOG_STYLE_LIST, "Depots:", "Fahrradkurierdepot\nLimousinenfahrerdepot\nTruckerdepot\nPostdepot\nProdfahrerdepot LS\nPilotdepot", "Starten", "Zurück");
}

public navi_nextbank(playerid)
{
  new Float:dista = 9999.99;
  new baid;
  for(new i=0;i < sizeof(atms);i++)
  {
	if(GetPlayerDistanceFromPoint(playerid,atms[i][0],atms[i][1],atms[i][2]) < dista)
	{
	  dista = GetPlayerDistanceFromPoint(playerid,atms[i][0],atms[i][1],atms[i][2]);
	  baid = i;
	}
  }
  SendClientMessage(playerid,COLOR_YELLOW,"nächster Bankautomat ist hier!");
  SetPlayerCheckpoint(playerid,atms[baid][0],atms[baid][1],atms[baid][2],10.0);
  navivar[playerid]= 1;
}

public navi_nextfast(playerid)
{
  new Float:distb = 9999.99;
  new baid;
  for(new i=0;i < sizeof(shopsenter);i++)
  {
	if(shopsenter[i][4] < 3.0 && GetPlayerDistanceFromPoint(playerid,shopsenter[i][1],shopsenter[i][2],shopsenter[i][3]) < distb)
	{
	  distb = GetPlayerDistanceFromPoint(playerid,shopsenter[i][1],shopsenter[i][2],shopsenter[i][3]);
	  baid = i;
	}
  }
  SendClientMessage(playerid,COLOR_YELLOW,"nächste Fastfood Geschäft ist hier!");
  SetPlayerCheckpoint(playerid,shopsenter[baid][1],shopsenter[baid][2],shopsenter[baid][3],5.0);
  navivar[playerid] = 1;
}

public navi_nextpnspray(playerid)
{
  new Float:distb = 9999.99;
  new baid;
  for(new i=0;i < sizeof(paynspray);i++)
  {
	if(GetPlayerDistanceFromPoint(playerid,paynspray[i][0],paynspray[i][1],paynspray[i][2]) < distb)
	{
	  distb = GetPlayerDistanceFromPoint(playerid,paynspray[i][0],paynspray[i][1],paynspray[i][2]);
	  baid = i;
	}
  }
  SendClientMessage(playerid,COLOR_YELLOW,"nächster Pay 'N' Spray ist hier!");
  SetPlayerCheckpoint(playerid,paynspray[baid][0],paynspray[baid][1],paynspray[baid][2],5.0);
  navivar[playerid]= 1;
}

public navi_mietwagen(playerid)
{
  new Float:distb = 9999.99;
  new baid;
  for(new i=0;i < sizeof(mietwagen);i++)
  {
		if(GetPlayerDistanceFromPoint(playerid,mietwagen[i][2],mietwagen[i][3],mietwagen[i][4]) < distb)
		{
			distb = GetPlayerDistanceFromPoint(playerid,mietwagen[i][2],mietwagen[i][3],mietwagen[i][4]);
			baid = i;
		}
  }
  SendClientMessage(playerid,COLOR_YELLOW,"Der nächste freie Mietwagen wurde auf der Karte Markiert.");
  SetPlayerCheckpoint(playerid,mietwagen[baid][2],mietwagen[baid][3],mietwagen[baid][4],5.0);
  navivar[playerid]= 1;
}