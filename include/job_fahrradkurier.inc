forward fahrradkurier();
forward fkurier(playerid);
forward fk_route(playerid);
forward abbruch_kurier(playerid);
forward fk(playerid);
forward fkurier_mittel(playerid);
forward fk_route_mittel(playerid);
forward fkurier_lang(playerid);
forward fk_route_lang(playerid);
forward fkurier_response(playerid, dialogid, response, listitem, inputtext[]);

new fkur[MAX_PLAYERS];
new fkurm[MAX_PLAYERS];
new fkurl[MAX_PLAYERS];

/* Objekte Bereich Fahrradkurier */

public fahrradkurier()
{
    CreateVehicleEx(509,1087,-1190,18,270,6,0,11);
    CreateVehicleEx(509,1087,-1195,18,270,6,0,11);
    CreateVehicleEx(509,1087,-1200,18,270,6,0,11);
    CreateVehicleEx(509,1104,-1191,18,180,6,0,11);
    CreateVehicleEx(509,1109,-1191,18,180,6,0,11);
    CreateVehicleEx(509,1114,-1191,18,180,6,0,11);

    CreatePickup(1239,1,1099,-1188,20,-1);
    Create3DTextLabel("Setzen Sie sich auf ein Fahrrad\nund geben Sie /fkurier ein,\num als Fahrradkurier zu arbeiten!\nEntfernen Sie sich länger als 10sek vom Fahrrad,\nwird ihr Job abgebrochen!",COLOR_WHITE,1099,-1188,19,25,0);
	CreateDynamicMapIcon(1099,-1188,20, 51, -1,-1, -1, -1, 500);
}


/* Aufruf Fenster */

public fk(playerid)
{
  ShowPlayerDialog(playerid,1000,DIALOG_STYLE_LIST , "Fahrradkurier:", "Strecke 1(100$)\nStrecke 2(110$)\nStrecke 3(210$)", "Fahren", "Abbrechen");
}

/* kurze Strecke */

public fkurier(playerid)
{
  SetPlayerCheckpoint(playerid,1087,-1216,18,3.0);
  SendClientMessage(playerid,COLOR_LIGHTBLUE,"Sie arbeiten nun als Fahrradkurier und befahren die kurze Strecke.");
  SendClientMessage(playerid,COLOR_LIGHTBLUE,"Die Fahrradkaution beträgt 100$ und wird nur bei Beenden der Tour zurück erstattet.");
  SetVehicleParamsEx(GetPlayerVehicleID(playerid),true,false,false,false,false,false,false);
  fkur[playerid] = 1;
  playerdata[playerid][4] = playerdata[playerid][4] - 100; 
  GivePlayerMoney(playerid,100);
  navivar[playerid] = 2;
  return 1;
}


public fk_route(playerid)
{
    switch(fkur[playerid])
    {
	case 1: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1089,-1095,25,3.0);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Gratis Zeitung ausgeliefert");
            fkur[playerid]++;
	}
        case 2: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1047,-945,42,3.0);
            fkur[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 3: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,829,-924,55,3.0);
            fkur[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 4: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,830,-863,69,3.0);
            fkur[playerid]++;
            giveusermoney(playerid,10);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 10$");
	}
        case 5: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1023,-778,102,3.0);
            fkur[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 6: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1253,-807,83,3.0);
            fkur[playerid]++;
            giveusermoney(playerid,10);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 10$");
	}
        case 7: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1496,-691,94,3.0);
            fkur[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 8: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1536,-850,63,3.0);
            fkur[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 9: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1430,-893,50,3.0);
            fkur[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 10: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1450,-922,37,3.0);
            fkur[playerid]++;
            giveusermoney(playerid,10);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 10$");
	}
        case 11: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1337,-1095,24,3.0);
            fkur[playerid]++;
            giveusermoney(playerid,10);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 10$");
	}
        case 12: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1305,-1370,13,3.0);
            fkur[playerid]++;
            giveusermoney(playerid,10);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 10$");
	}
        case 13: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1188,-1479,13,3.0);
            fkur[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 14: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1070,-1355,13,3.0);
            fkur[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 10$");
	}
        case 15: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1099,-1205,17,3.0);
            fkur[playerid]++;
            giveusermoney(playerid,10);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 10$");
	}
	case 16:	
	{	
            DisablePlayerCheckpoint(playerid);
            giveusermoney(playerid,100);
            SetVehicleToRespawn(GetPlayerVehicleID(playerid));
            fkur[playerid] = 0;
            navivar[playerid] = 0;
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Sie haben Ihren Job beendet.");
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Die Fahrradkaution wurde Ihnen wieder gutgeschrieben!");
	}
    }
}

/* Mittellange Strecke */

public fkurier_mittel(playerid)
{
  SetPlayerCheckpoint(playerid,1087,-1216,18,3.0);
  SendClientMessage(playerid,COLOR_LIGHTBLUE,"Sie arbeiten nun als Fahrradkurier und befahren die mittlere Strecke.");
  SendClientMessage(playerid,COLOR_LIGHTBLUE,"Die Fahrradkaution beträgt 100$ und wird nur bei Beenden der Tour zurück erstattet.");
  SetVehicleParamsEx(GetPlayerVehicleID(playerid),true,false,false,false,false,false,false);
  fkurm[playerid] = 1;
  navivar[playerid] = 2;
  giveusermoney(playerid,-100);
  return 1;
}

public fk_route_mittel(playerid)
{
    switch(fkurm[playerid])
    {
	case 1: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1235,-1156,23,3.0);
            fkurm[playerid]++;
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Gratis Zeitung ausgeliefert");
	}
        case 2: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1427,-1177,26,3.0);
            fkurm[playerid]++;
            giveusermoney(playerid,1);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Gratis Zeitung ausgeliefert");
	}
        case 3: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1523,-1111,20,3.0);
            fkurm[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 4: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1829,-1126,23,3.0);
            fkurm[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 5: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1915,-1082,24,3.0);
            fkurm[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 6: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1999,-1119,26,3.0);
            fkurm[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 7: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,2087,-1166,25,3.0);
            fkurm[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 8: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,2149,-1242,24,3.0);
            fkurm[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 9: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,2333,-1263,27,3.0);
            fkurm[playerid]++;
            giveusermoney(playerid,10);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 10$");
	}
        case 10: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,2404,-1344,25,3.0);
            fkurm[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 11: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,2229,-1333,24,3.0);
            fkurm[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 12: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,2195,-1282,24,3.0);
            fkurm[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 13: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,2149,-1288,24,3.0);
            fkurm[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 14: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,2095,-1321,25,3.0);
            fkurm[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 15: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1997,-1324,23,3.0);
            fkurm[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 16: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1839,-1418,13,3.0);
            fkurm[playerid]++;
            giveusermoney(playerid,10);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 10$");
	}
        case 17: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1745,-1457,13,3.0);
            fkurm[playerid]++;
            giveusermoney(playerid,10);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 10$");
	}
        case 18: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1447,-1393,13,3.0);
            fkurm[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 19: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1239,-1133,23,3.0);
            fkurm[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
         case 20: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1099,-1205,17,3.0);
            fkurm[playerid]++;
            giveusermoney(playerid,10);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 10$");
	}
        case 21:	
	{	
            DisablePlayerCheckpoint(playerid);
            giveusermoney(playerid,100);
            SetVehicleToRespawn(GetPlayerVehicleID(playerid));
            fkurm[playerid] = 0;
            navivar[playerid] = 0;
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Sie haben Ihren Job beendet.");
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Die Fahrradkaution wurde Ihnen wieder gutgeschrieben!");
	}
    }
}


/* Lange Kurierstrecke */

public fkurier_lang(playerid)
{
  SetPlayerCheckpoint(playerid,1087,-1216,18,3.0);
  SendClientMessage(playerid,COLOR_LIGHTBLUE,"Sie arbeiten nun als Fahrradkurier und befahren die lange Strecke.");
  SendClientMessage(playerid,COLOR_LIGHTBLUE,"Die Fahrradkaution beträgt 100$ und wird nur bei Beenden der Tour zurück erstattet.");
  SetVehicleParamsEx(GetPlayerVehicleID(playerid),true,false,false,false,false,false,false);
  fkurl[playerid] = 1;
  giveusermoney(playerid,-100);
  return 1;
}


public fk_route_lang(playerid)
{
    switch(fkurl[playerid])
    {
	case 1: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,949,-1166,22,3.0);
            fkurl[playerid]++;
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Gratis Zeitung ausgeliefert");
	}
        case 2: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,789,-1087,23,3.0);
            fkurl[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 3: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,696,-1166,15,3.0);
            fkurl[playerid]++;
            giveusermoney(playerid,10);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 10$");
	}
        case 4: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,477,-1280,15,3.0);
            fkurl[playerid]++;
            giveusermoney(playerid,10);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 10$");
	}
        case 5: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,277,-1434,13,3.0);
            fkurl[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 6: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,273,-1609,32,3.0);
            fkurl[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 7: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,361,-2031,7,3.0);
            fkurl[playerid]++;
            giveusermoney(playerid,15);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 15$");
	}
        case 8: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,386,-1878,7,3.0);
            fkurl[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 9: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,412,-1760,7,3.0);
            fkurl[playerid]++;
            giveusermoney(playerid,10);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 10$");
	}
        case 10: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,506,-1757,13,3.0);
            fkurl[playerid]++;
            giveusermoney(playerid,20);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 20$");
	}
        case 11: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,679,-1795,12,3.0);
            fkurl[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 12: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,822,-1758,13,3.0);
            fkurl[playerid]++;
            giveusermoney(playerid,10);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 10$");
	}
        case 13: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,993,-1817,13,3.0);
            fkurl[playerid]++;
            giveusermoney(playerid,20);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 20$");
	}
        case 14: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1109,-1836,16,3.0);
            fkurl[playerid]++;
            giveusermoney(playerid,15);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 15$");
	}
        case 15: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1230,-1858,13,3.0);
            fkurl[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 16: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1449,-1843,13,3.0);
            fkurl[playerid]++;
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Gratis Zeitung ausgeliefert");
	}
        case 17: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1729,-1911,13,3.0);
            fkurl[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 18: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1857,-1873,13,3.0);
            fkurl[playerid]++;
            giveusermoney(playerid,10);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 10$");
	}
        case 19: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,2498,-1754,13,3.0);
            fkurl[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 20: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,2361,-1532,23,3.0);
            fkurl[playerid]++;
            giveusermoney(playerid,10);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 10$");
	}
        case 21: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,2231,-1411,23,3.0);
            fkurl[playerid]++;
            giveusermoney(playerid,15);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 15$");
	}
        case 22: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,2096,-1283,24,3.0);
            fkurl[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 23: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1830,-1175,23,3.0);
            fkurl[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 24: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1322,-1176,23,3.0);
            fkurl[playerid]++;
            giveusermoney(playerid,15);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 15$");
	}
        case 25: 
	{
            DisablePlayerCheckpoint(playerid);
            SetPlayerCheckpoint(playerid,1099,-1205,17,3.0);
            fkurl[playerid]++;
            giveusermoney(playerid,5);
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Zeitung ausgeliefert, Sie erhalten 5$");
	}
        case 26:
	{	
            DisablePlayerCheckpoint(playerid);
            giveusermoney(playerid,100);
            SetVehicleToRespawn(GetPlayerVehicleID(playerid));
            fkurl[playerid] = 0;
            navivar[playerid] = 0;
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Sie haben Ihren Job beendet.");
            SendClientMessage(playerid,COLOR_LIGHTBLUE,"Die Fahrradkaution wurde Ihnen wieder gutgeschrieben!");
	}
    }
}

/* Abbruch des Jobs */

public abbruch_kurier(playerid)
{
    DisablePlayerCheckpoint(playerid);
    SendClientMessage(playerid,COLOR_RED,"Job abgebrochen!");
    fkur[playerid] = 0;
    fkurm[playerid] = 0;
    fkurl[playerid] = 0;
    navivar[playerid] = 0;
}

public fkurier_response(playerid, dialogid, response, listitem, inputtext[])
{
  if(dialogid == 1000)
  {
  	if(response)
  	{
  	  if(listitem == 0)
  	  {
		fkurier(playerid);
	  }
      if(listitem == 1)
  	  {
  		fkurier_mittel(playerid);
	  }
	  if(listitem == 2)
  	  {
  		fkurier_lang(playerid);
	  }
	}
	else
      RemovePlayerFromVehicle(playerid);
  }
}
