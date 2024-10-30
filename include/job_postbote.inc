forward postbote();
forward pbroute(playerid);
forward start_pbroute(playerid);
forward abbruch_pbote(playerid,vehicleid);
forward pbote_response(playerid, dialogid, response, listitem, inputtext[]);
forward pbote_statechange(playerid, newstate, oldstate);
forward pbote_add();


new pbote[MAX_PLAYERS];
new Float:pospb[MAX_PLAYERS][3];
new Express[MAX_PLAYERS][3][3];
new timer_pbote[MAX_PLAYERS];
/*
 * Arten von Express
 * 0 => kurze Nachricht(35) = kurze Strecke
 * 1 => mittlere Nachricht (75) = mittlere Strecke
 * 2 => grosse Nachricht(125) = grosse Strecke
 * 3 => mittlere Nachricht(75) = kurze Strecke
 * 4 => grosse Nachricht(125) = kurze Strecke
 */

public postbote()
{
  CreateVehicleEx(609, 1473, 1029, 10.8, 270, 6, 0, 300);
  CreateVehicleEx(609, 1473, 1038, 10.8, 270, 6, 0, 300);
  CreateVehicleEx(609, 1473, 1066, 10.8, 270, 6, 0, 300);
  CreateVehicleEx(609, 1473, 1045, 10.8, 270, 6, 0, 300);
  CreateVehicleEx(609, 1473, 1052, 10.8, 270, 6, 0, 300);
  CreateVehicleEx(609, 1473, 1059, 10.8, 270, 6, 0, 300);
  
  CreateDynamicMapIcon(1473, 1045, 10.8, 51, -1,-1, -1, -1, 500);
}

public pbroute(playerid)
{
    new string[150];
    new Float:kleinroute[][3] = {{1704.5, 1436.5, 10.0},{1676.5, 1447.5, 10.0},{2158.5, 1672.5, 10.0},{2194.0, 1677.64, 11.92},
                          {2036.0, 1923.0, 11.73},{2020.5, 1919.5, 11.89},{2226.5, 1285.0, 10.23},{2238.5, 1284.5, 10.34},
                          {2176.5, 978.5, 10.32},{2178.0, 962.0, 10.38}};
    new Float:mittelroute[][3] = {{1136.5, 1441.5, 5.38},{1123.5, 1465.0, 5.39},{1001.0, 1886.0, 10.36},{985.0,  1879.5, 11.02},
                          {979.0, 2147.5, 10.39},{970.0, 2158.5, 10.38},{1301.0, 2060.0, 10.39},{1311.0, 2084.5, 10.37},
                          {1701.5, 2055.5, 10.36},{1685.5, 2046.5, 11.02},{2033.5, 2148.0, 10.38},{2033.0, 2160.5, 10.38},
                          {2218.0, 1839.0, 10.38},{2225.0, 1837.5, 10.38},{1943.0, 1347.0, 8.67},{1931.0, 1345.0, 9.53}};
    new Float:grossroute[][3] = {{1544.0, 749.8, 10.38},{1532.0, 752.0, 10.59},{1293.8, 267.9, 18.97},{1288.9, 270.7, 19.12},
                          {326.6, -85.8, 1.15},{313.6, -92.2, 3.10},{96.2, -201.6, 1.1},{93.3, -187.7, 1.03},{-178.4,1103.1, 19.22},
                          {-176.5, 1111.8, 19.31},{411.0, 1151.9, 7.71},{398.2, 1157.7, 7.9},{783.6, 1878.0, 4.46},{777.8, 1871.8, 4.46}};
    new Float:distpbkurz[][3]={{2173.6, 1125.1, 12.13},{2187.2, 1116.1, 12.21},{2024.9, 1343.3, 10.38},{1956.2, 1343.1, 14.93},
						  {2031.3, 1560.8, 10.39},{1968.8,1623.6, 12.42},{1491.1, 2218.9,10.58},{1483.2, 2214.3, 10.59},
						  {1000.631530,1683.876342, 10.48},{964.0, 1684.1, 8.40},{1004.6, 1093.6,10.37},{1013.1,1058.6, 10.56}};
	new Float:distpbmitt[][3]={{-226.75,  2704.58,  62.53},{-226.94,  2709.92,  62.98},{-90.61,  1216.81,  19.74},{-90.38,  1229.10,  19.74},
						  {253.19,  -65.93,  1.57},{254.03,  -57.12,  1.57},{1307.57,  322.33,  19.40},{1310.57,  329.11,  19.91},
						  {2337.57,  8.10,  26.48},{2329.93,  6.78,  26.51}};
	new Float:distpbgross[][3]={{-1980.80,  542.39,  35.01},{-1963.12,  539.45,  35.17},{1221.11,  -920.17,  42.91},{1208.19,  -918.05,  43.05}};
	
	if(pbote[playerid] == 1 || pbote[playerid] == 15 || pbote[playerid] == 49 || (pbote[playerid] > 100 && pbote[playerid] < 105)) //Start
    {
      GetPlayerPos(playerid, pospb[playerid][0], pospb[playerid][1], pospb[playerid][2]);
      GameTextForPlayer(playerid, "~w~Fahre zur ~n~ersten Adresse", 3000, 1);
      SendClientMessage(playerid, COLOR_PBOTE, "*** Postbote: Eine Kaution für das Fahrzeug wurde erhoben ($500) ***");
      playerdata[playerid][4] = playerdata[playerid][4] - 500; 
      GivePlayerMoney(playerid,-500);
	  if(pbote[playerid] > 100)
	  {
		new query[80],rand;
		format(query, sizeof(query), "UPDATE `werbung` SET `onwork`=%i WHERE `werbungid`=%i",playerid,Express[playerid][(pbote[playerid]-101)][0]);
		mysql_query(query);
		if(Express[playerid][(pbote[playerid]-101)][1] == 1)
		{
		  rand = random(5);
		  if(rand % 2 == 1) rand++;
		  SetPlayerCheckpoint(playerid,distpbmitt[rand][0],distpbmitt[rand][1],distpbmitt[rand][2],5);
		}
		else if(Express[playerid][(pbote[playerid]-101)][1] == 2)
		{
		  rand = random(1);
		  if(rand % 2 == 1) rand++;
		  SetPlayerCheckpoint(playerid,distpbgross[rand][0],distpbgross[rand][1],distpbgross[rand][2],5);
		}
		else
		{
		  rand = random(9);
		  if(rand % 2 == 1) rand++;
		  SetPlayerCheckpoint(playerid,distpbkurz[rand][0],distpbkurz[rand][1],distpbkurz[rand][2],5);
		}
		SendClientMessage(playerid, COLOR_PBOTE, "*** Postbote: Expresslieferung gestartet ***");
		Express[playerid][(pbote[playerid]-101)][2] = (rand+1);
		pbote[playerid] = pbote[playerid]+ 99;
	  }
      else if(pbote[playerid] > 0 && pbote[playerid] < 14)
      {
        SendClientMessage(playerid, COLOR_PBOTE, "*** Postbote: kurze Strecke gestartet ***");
        SetPlayerCheckpoint(playerid, kleinroute[(pbote[playerid]-1)][0],kleinroute[(pbote[playerid]-1)][1], kleinroute[(pbote[playerid]-1)][2], 2);
      }
      else if(pbote[playerid] > 14 && pbote[playerid] < 33)
      {
        SendClientMessage(playerid, COLOR_PBOTE, "*** Postbote: mittlere Strecke gestartet ***");
        SetPlayerCheckpoint(playerid, mittelroute[(pbote[playerid]-15)][0],mittelroute[(pbote[playerid]-15)][1], mittelroute[(pbote[playerid]-15)][2], 2);
      }
      else if(pbote[playerid] > 48 && pbote[playerid] < 99)
      {
        SendClientMessage(playerid, COLOR_PBOTE, "*** Postbote: grosse Strecke gestartet ***");
        SetPlayerCheckpoint(playerid, grossroute[(pbote[playerid]-49)][0],grossroute[(pbote[playerid]-49)][1], grossroute[(pbote[playerid]-49)][2], 2);
      }
      pbote[playerid]++;
    }
    else if((pbote[playerid] % 2 == 0 && pbote[playerid] != 12 && pbote[playerid] != 32 && pbote[playerid] < 100 && pbote[playerid] != 64 && pbote[playerid] != 100 )|| (pbote[playerid] > 200 && pbote[playerid] < 205)) //per Fahrzeug anfahren
    {
      if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 609)
      {
        DisablePlayerCheckpoint(playerid);
        GameTextForPlayer(playerid, "~w~Liefere das Paket zu Fuss.", 3000, 1);
        if(pbote[playerid] < 14) SetPlayerCheckpoint(playerid, kleinroute[(pbote[playerid]-1)][0],kleinroute[(pbote[playerid]-1)][1], kleinroute[(pbote[playerid]-1)][2], 2);
        else if(pbote[playerid] < 33) SetPlayerCheckpoint(playerid, mittelroute[(pbote[playerid]-15)][0],mittelroute[(pbote[playerid]-15)][1], mittelroute[(pbote[playerid]-15)][2], 2);
        else if(pbote[playerid] < 99) SetPlayerCheckpoint(playerid, grossroute[(pbote[playerid]-49)][0],grossroute[(pbote[playerid]-49)][1], grossroute[(pbote[playerid]-49)][2], 2);
        else if(pbote[playerid] < 300)
		{
		  new rand = Express[playerid][(pbote[playerid]-201)][2];
		  if(Express[playerid][(pbote[playerid]-201)][1] == 1)
			SetPlayerCheckpoint(playerid,distpbmitt[rand][0],distpbmitt[rand][1],distpbmitt[rand][2],5);
		  else if(Express[playerid][(pbote[playerid]-201)][1] == 2)
			SetPlayerCheckpoint(playerid,distpbgross[rand][0],distpbgross[rand][1],distpbgross[rand][2],5);
		  else
			SetPlayerCheckpoint(playerid,distpbkurz[rand][0],distpbkurz[rand][1],distpbkurz[rand][2],5);
		  pbote[playerid] = pbote[playerid] + 99;
		}
		pbote[playerid]++;
      }
      else SendClientMessage(playerid, COLOR_RED, "*** Postbote: Du brauchst ein Postauto ***");
    }
    else if(pbote[playerid] % 2 == 1 && pbote[playerid] < 100 || (pbote[playerid] > 300 && pbote[playerid] < 305)) //zustellen zu Fuss
    {
      if(GetPlayerVehicleID(playerid) == 0)
      {
        new query[100],skill=0;
        new skilllevel[] = {0,5,10,15,20,30};
        DisablePlayerCheckpoint(playerid);
        format(string, sizeof(string), "~g~Paket geliefert!");
        GameTextForPlayer(playerid, string, 3000, 1);
        if(pbote[playerid] < 14){ giveusermoney(playerid,(10+skilllevel[(playerdata[playerid][3])]));skill=1;}
        else if(pbote[playerid] < 33){ giveusermoney(playerid,(15+skilllevel[(playerdata[playerid][3])]));skill=1;}
        else if(pbote[playerid] < 99){ giveusermoney(playerid,(20+skilllevel[(playerdata[playerid][3])]));skill=1;}
		else if(pbote[playerid] > 300)
		{
		  if(Express[playerid][(pbote[playerid]-301)][1] == 0){ giveusermoney(playerid,50);skill=2;}
		  if(Express[playerid][(pbote[playerid]-301)][1] == 1){ giveusermoney(playerid,125);skill=5;}
		  if(Express[playerid][(pbote[playerid]-301)][1] == 2){ giveusermoney(playerid,250);skill=10;}
		  if(Express[playerid][(pbote[playerid]-301)][1] == 3){ giveusermoney(playerid,150);skill=5;}
		  if(Express[playerid][(pbote[playerid]-301)][1] == 4){ giveusermoney(playerid,300);skill=5;}
		  sendmessagetoallplayer("",playerid,0,Express[playerid][(pbote[playerid]-301)][0]);
		  format(query, sizeof(query), "DELETE FROM `werbung` WHERE `werbungid`=%i",Express[playerid][(pbote[playerid]-301)][0]);
		  mysql_query(query);
          pbote[playerid] = pbote[playerid] + 99;
		}
        playerdata[playerid][8] = playerdata[playerid][8] + skill;
        if(pbote[playerid] == 11 || pbote[playerid] == 31 || pbote[playerid] == 63 || pbote[playerid] > 300) SetPlayerCheckpoint(playerid, pospb[playerid][0], pospb[playerid][1], pospb[playerid][2], 5);
        else if(pbote[playerid] < 14) SetPlayerCheckpoint(playerid, kleinroute[(pbote[playerid]-1)][0],kleinroute[(pbote[playerid]-1)][1], kleinroute[(pbote[playerid]-1)][2], 5);
        else if(pbote[playerid] < 33) SetPlayerCheckpoint(playerid, mittelroute[(pbote[playerid]-15)][0],mittelroute[(pbote[playerid]-15)][1], mittelroute[(pbote[playerid]-15)][2], 5);
        else if(pbote[playerid] < 99) SetPlayerCheckpoint(playerid, grossroute[(pbote[playerid]-49)][0],grossroute[(pbote[playerid]-49)][1], grossroute[(pbote[playerid]-49)][2], 2);
        pbote[playerid]++;
      }
      else GameTextForPlayer(playerid, "~w~Liefere das Paket ~r~ zu Fuss.", 3000, 1);
    }
    else if(pbote[playerid] == 12 || pbote[playerid] == 32 || pbote[playerid] == 64 || pbote[playerid] > 400) //Ziel
    {
      new Float:z,Float:health,paydaycount;
      GetVehicleZAngle(GetPlayerVehicleID(playerid), z);
      GetVehicleHealth(GetPlayerVehicleID(playerid),health);
      if(GetVehicleModel(GetPlayerVehicleID(playerid)) == 609 && z > 260 && z < 280 && health > 900)
      {
        DisablePlayerCheckpoint(playerid);
        format(string, sizeof(string), "~g~Autrag beendet.");
        giveusermoney(playerid,500);
        if(pbote[playerid] > 400 || pbote[playerid] == 64) paydaycount = 3;
        else if(pbote[playerid] == 32) paydaycount = 2;
        else paydaycount = 1;
        playerdata[playerid][9] = playerdata[playerid][9] + paydaycount;
        SendClientMessage(playerid, COLOR_PBOTE, "*** Postbote: Kaution zurückgegeben. ***");
        GameTextForPlayer(playerid, string, 3000, 1);
        pbote[playerid] = 0;
        navivar[playerid] = 0;
        Fahrzeuge[GetPlayerVehicleID(playerid)][1] = 1000.0;
        Fahrzeuge[GetPlayerVehicleID(playerid)][0] = float(Fahrzeugdaten[GetVehicleModel(GetPlayerVehicleID(playerid))-400][0]);
        RemovePlayerFromVehicle(playerid);
      }
      else if(health <= 900)
      {
        format(string, sizeof(string), "~w~Dein Postauto ist zu ~r~beschaedigt~n~~w~repariere es!");
        DisablePlayerCheckpoint(playerid);
        SetPlayerCheckpoint(playerid, 1966, 2161, 10.38, 5);
        pbote[playerid] = 100;
        GameTextForPlayer(playerid, string, 3000, 1);
      }
      else if(z < 260 || z > 280)
      {
        format(string, sizeof(string), "~w~Parke das Postauto ~r~rückwaerts~w~!");
        GameTextForPlayer(playerid, string, 3000, 1);
      }
      else SendClientMessage(playerid, COLOR_RED, "*** Postbote: Du brauchst ein Postauto ***");
    }
    else //wenn Auto mehr als 10% Schaden
    {
      SetPlayerCheckpoint(playerid, pospb[playerid][0], pospb[playerid][1], pospb[playerid][2], 5);
      pbote[playerid] = 12;
    }
}

public start_pbroute(playerid)
{
  new query[80],data[50],string[200] = "",string1[100],skilllevel[] = {0,5,10,15,20,30};
  format(query, sizeof(query), "SELECT COUNT(*) as anz FROM `werbung` WHERE `onwork`=-1");
  mysql_query(query);
  mysql_store_result();
  mysql_fetch_row(data);
  mysql_fetch_field("anz",data);
  mysql_free_result();
  if(strval(data) > 0)
  {
	new j;
	if(strval(data) > 3) j = 3; else j = strval(data);
	for(new i=0;i < j;i++)
	{
	  format(query, sizeof(query), "SELECT kind,werbungid FROM `werbung` WHERE `onwork`=-1 LIMIT %i,1",i);
	  mysql_query(query);
	  mysql_store_result();
	  mysql_fetch_row(data);
	  mysql_fetch_field("werbungid",data);
	  Express[playerid][i][0] = strval(data);
	  mysql_fetch_field("kind",data);
	  Express[playerid][i][1] = strval(data);
	  if(strval(data) == 0) strcat(string,"\nExpress (50$)");
	  if(strval(data) == 1) strcat(string,"\nExpress (125$)");
	  if(strval(data) == 2) strcat(string,"\nExpress (250$)");
	  if(strval(data) == 3) strcat(string,"\nExpress (150$)");
	  if(strval(data) == 4) strcat(string,"\nExpress (300$)");
	  mysql_free_result();
	}
  }
  format(string1,100,"Postbote (Erfahrung: %i ): Strecke wählen",playerdata[playerid][3]);
  format(string,200,"kleine Strecke ($%i pro Paket)\nmittlere Strecke ($%i pro Paket)\ngrosse Strecke ($%i pro Paket)%s",(10+skilllevel[(playerdata[playerid][3])]),(15+skilllevel[(playerdata[playerid][3])]),(20+skilllevel[(playerdata[playerid][3])]),string);
  ShowPlayerDialog(playerid, 10, DIALOG_STYLE_LIST, string1, string, "Bestätigen", "Abbrechen");
}

public abbruch_pbote(playerid,vehicleid)
{
  pbote[playerid] = 0;
  DisablePlayerCheckpoint(playerid);
  new query[80];
  format(query, sizeof(query), "UPDATE `werbung` SET `onwork`=-1 WHERE `onwork`=%i",playerid);
  mysql_query(query);
  SetVehicleToRespawn(vehicleid);
  SendClientMessage(playerid, COLOR_PBOTE, "*** Postbote: Auftrag abgeben! ***");
}

public pbote_response(playerid, dialogid, response, listitem, inputtext[])
{
  if(dialogid == 10) 
  {
    if(response)
    {
      if(listitem == 0)
		pbote[playerid] = 1;
	  else if(listitem == 1)
		pbote[playerid] = 15;
      else if(listitem == 2)
		pbote[playerid] = 49;
      else if(listitem == 3)
		pbote[playerid] = 101;
      else if(listitem == 4)
		pbote[playerid] = 102;
      else if(listitem == 5)
		pbote[playerid] = 103;
      pbroute(playerid);
      navivar[playerid] = 2;
    }
    else
      RemovePlayerFromVehicle(playerid);
  }
}

public pbote_statechange(playerid, newstate, oldstate)
{
  if(PLAYER_STATE:newstate == PLAYER_STATE_ONFOOT) 
  {
    if(pbote[playerid] > 0)
      timer_pbote[playerid] = SetTimerEx("abbruch_pbote", 60000, false, "ii", playerid,GetPlayerVehicleID(playerid)); //Abbruch Timer Postbote
  }
  if(PLAYER_STATE:newstate == PLAYER_STATE_DRIVER && GetVehicleModel(GetPlayerVehicleID(playerid)) == 609)
  {
	if(playerdata[playerid][2] == 2 && pbote[playerid] == 0)
	{
	  start_pbroute(playerid);
	}
	else if(playerdata[playerid][2] != 2)
	{
	  RemovePlayerFromVehicle(playerid);
	  GameTextForPlayer(playerid, "~w~Du bist kein~n~~y~Postbote", 3000, 1);
	  SendClientMessage(playerid, COLOR_RED, "*** Nur Postboten dürfen dieses Fahrzeug benutzen ***");
	}
	KillTimer(timer_pbote[playerid]);
  }
}

public pbote_add()
{
  new query[250],a,b;
  b = random(5);
  a = random(3);
  if(a == 0)
    format(query, sizeof(query), "INSERT INTO werbung (playerid,kind,msg) VALUES (%i,%i,'%s')",2,b,"Besucht uns öfters");
  else if(a == 1)
    format(query, sizeof(query), "INSERT INTO werbung (playerid,kind,msg) VALUES (%i,%i,'%s')",2,b,"Besucht uns öfters öfters");
  else
    format(query, sizeof(query), "INSERT INTO werbung (playerid,kind,msg) VALUES (%i,%i,'%s')",2,b,"Besucht uns öfters öfters öfters");
  mysql_query(query);
}