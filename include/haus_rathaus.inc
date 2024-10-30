forward rathaus();
forward perso(playerid);
forward gewerbe(playerid);
forward deljob(playerid);
forward checkjob(playerid,i);
forward rath_pickups(playerid,pickupid);
forward jobmenu(playerid);
forward rathaus_response(playerid, dialogid, response, listitem, inputtext[]);

new rathausenter,rathausexit,jobs,einwamt;
new Menu:aamtmenu,Menu:einwamtmenu,Menu:njobmenu;

public rathaus()
{	
  rathausenter = CreatePickup(1559,1,1286,-1329.3,13.5,1);
  Create3DTextLabel("Rathaus betreten",COLOR_WHITE,1286,-1329.2,13.5,15,1,false);
    
  rathausexit = CreatePickup(1559,1,2309,-15.2,27,1);
  Create3DTextLabel("Rathaus verlassen",COLOR_WHITE,2309,-15.2,27,8,1,false);
    
  einwamt = CreatePickup(1239,1,2309,-1.81,26.8,1);
  Create3DTextLabel("Einwohnermeldeamt",COLOR_WHITE,2309,-1.81,27.5,10,1,false);
    
  jobs = CreatePickup(1239,1,2310,-8.71,26.8,1);
  Create3DTextLabel("Arbeitsamt",COLOR_WHITE,2310,-8.71,27.5,10,1,false);
  
  /*
   -----------------------------------------------------------------------------
   Menüs
  */
  einwamtmenu = CreateMenu("Einwohnermeldeamt", 1, 175.0, 100.0, 150.0);
  AddMenuItem(einwamtmenu, 0, "Personalausweis aktualisieren");
  AddMenuItem(einwamtmenu, 0, "Gewerbeschein beantragen");
  
  aamtmenu = CreateMenu("Arbeitsamt", 1, 175.0, 100.0, 150.0);
  AddMenuItem(aamtmenu, 0, "Job-Angebote");
  AddMenuItem(aamtmenu, 0, "Nebenjobs");
  AddMenuItem(aamtmenu, 0, "Arbeitslos melden");
  /*
   -----------------------------------------------------------------------------
   Nebenjobs (um einen hinzuzufügen bei OnPlayerSelectedMenuRow auch hinzufügen!)
  */
  njobmenu = CreateMenu("Nebenjobs", 1, 175.0, 100.0, 150.0);
  AddMenuItem(njobmenu, 0, "Fahrradkurier");
  AddMenuItem(njobmenu, 0, "Limosinenfahrer");
  AddMenuItem(njobmenu, 0, "Abbruch");
  /*
   -----------------------------------------------------------------------------
  */
  
  CreateDynamicMapIcon(1286,-1329.3,13.5, 32, -1,-1, -1, -1, 500);
}

public jobmenu(playerid)
{
  new query[256],dataname[50],datastellmax[25],datastellmin[25];
  new output[250] = "Zurück zur Auswahl \n",output2[50],k;
  
  for(new i = 1;i < 7;i++)
  {
    format(query,256,"SELECT jname,anzstellen,COUNT(accounts.jobid) as cnt FROM jobs,accounts WHERE jobs.jobid=%i AND accounts.jobid=%i",i,i);
    mysql_query(query);
    mysql_store_result();
    mysql_fetch_field("jname",dataname);
    mysql_fetch_field("anzstellen",datastellmax);
    mysql_fetch_field("cnt",datastellmin);
    mysql_free_result();
    if((strval(datastellmax)-strval(datastellmin)) > 0) k = strval(datastellmax)-strval(datastellmin); else k = 0;
    format(output2,50,"%s (%i frei) \n",dataname,k);
    strcat(output,output2);
  }
  ShowPlayerDialog(playerid, 9,DIALOG_STYLE_LIST,"Berufe",output,"Weiter","Zurück");
}

public perso(playerid)
{
  if(playerdata[playerid][32] == 0)
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Ihr Personalausweis wurde aktualisiert! Eine Bearbeitungsgebühr von 10$ wurde erhoben.");
    playerdata[playerid][32] = 1;
    giveusermoney(playerid,-10);
  }
  if(playerdata[playerid][32] == 1)
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Ihr Personalausweis wurde bereits aktualisiert!");
  }
  TogglePlayerControllable(playerid,true);
}

public gewerbe(playerid)
{
  TogglePlayerControllable(playerid,true);
}

public deljob(playerid)
{
  new query[256], data[25];
  if(playerdata[playerid][2] == 0)
    SendClientMessage(playerid,COLOR_YELLOW,"Sie sind bereits arbeitslos gemeldet.");
  else
  {
	format(query, sizeof(query), "SELECT (NOW()-jobtime) as `time` FROM `accounts` WHERE `accid`=%i", playerdata[playerid][0]);
	mysql_query(query);
	mysql_store_result();
	mysql_fetch_row(data);
	mysql_fetch_field("time",data);
	mysql_free_result();
	if(strval(data) < 86400)
	  SendClientMessage(playerid,COLOR_YELLOW,"Sie haben noch keine 24h in ihrem Beruf gearbeitet.");
	else
	{
	  SendClientMessage(playerid,COLOR_YELLOW,"Sie haben sich arbeitslos gemeldet.");
	  setuserjob(playerid,0);
	}
  }
  TogglePlayerControllable(playerid,true);
}

public checkjob(playerid,i)
{
  new output[100];
  new query[256];
  new data[125];
  if(playerdata[playerid][2] == 0)
  {
    new ok = 0;
    //Jobvoraussetzungen
    switch(i)
    {
      case 1: //Trucker
      {
        if(playerdata[playerid][24] == 1 && playerdata[playerid][43] == 1)
          ok = 1;
        else if(playerdata[playerid][24] == 0)
          format(output,100,"Sie brauchen den LKW mit Anhänger Führerschein.",output);
        else
          format(output,100,"Sie müssen die Berufsschule besuchen.",output);
      }
      case 2: //Postbote
      {
        if(playerdata[playerid][22] == 1 && playerdata[playerid][41] == 1)
          ok = 1;
        else if(playerdata[playerid][22] == 0)
          format(output,100,"Sie brauchen den PKW Führerschein.",output);
        else
          format(output,100,"Sie müssen die Berufsschule besuchen.",output);
      }
      case 3: //Fahrlehrer
      {
        if(playerdata[playerid][22] == 1 && playerdata[playerid][24] == 1 && playerdata[playerid][38] == 1)
          ok = 1;
        else if(playerdata[playerid][22] == 0 || playerdata[playerid][23] == 0)
          format(output,100,"Sie brauchen den PKW, LKW und LKW mit Anhänger Führerschein.",output);
        else
          format(output,100,"Sie müssen die Berufsschule besuchen.",output);
      }
      case 4: //Polizist
      {
        if(playerdata[playerid][22] == 1 && playerdata[playerid][31] == 1 && playerdata[playerid][40] == 1)
          ok = 1;
        else if(playerdata[playerid][22] == 0 || playerdata[playerid][31] == 0)
          format(output,100,"Sie brauchen den PKW Führerschein und einen Waffenschein.",output);
        else
          format(output,100,"Sie müssen die Berufsschule besuchen.",output);
      }
      case 5: //Pilot
      {
        if(playerdata[playerid][28] == 1 && playerdata[playerid][29] == 1 && playerdata[playerid][39] == 1)
          ok = 1;
        else if(playerdata[playerid][28] == 0 || playerdata[playerid][29] == 0)
          format(output,100,"Sie brauchen den Helicopter und den Airbus Führerschein.",output);
        else
          format(output,100,"Sie müssen die Berufsschule besuchen.",output);
      }
      case 6: //Prodfahrer
      {
        if(playerdata[playerid][23] == 1 && playerdata[playerid][42] == 1)
          ok = 1;
        else if(playerdata[playerid][23] == 0)
          format(output,100,"Sie brauchen den LKW Führerschein.",output);
        else
          format(output,100,"Sie müssen die Berufsschule besuchen.",output);
      }
      case 7: //Taxifahrer
      {
        if(playerdata[playerid][22] == 1 && playerdata[playerid][50] == 1)
          ok = 1;
        else if(playerdata[playerid][22] == 0)
          format(output,100,"Sie brauchen den PKW Führerschein.",output);
        else
          format(output,100,"Sie müssen die Berufsschule besuchen.",output);
      }
    }
    if(ok)
    {
      new data3[100],anz[50];
      format(query, sizeof(query), "SELECT jName,anzstellen FROM `jobs` WHERE jobid=%i",i);
      mysql_query(query);
      mysql_store_result();
      mysql_fetch_row(data);
      mysql_fetch_field("anzstellen",data3);
      mysql_fetch_field("jName",output);
      mysql_free_result();
      format(query, sizeof(query), "SELECT COUNT(*) as anz FROM `accounts` WHERE jobid=%i",i);
      mysql_query(query);
      mysql_store_result();
      mysql_fetch_row(data);
      mysql_fetch_field("anz",anz);
      mysql_free_result();
      if(strval(data3) > strval(anz))
      {
        setuserjob(playerid,i);
        format(output,100,"Sie haben den Job! Sie sind nun %s.",output);
      }
      else
      {
        format(output,100,"Für den Job %s sind keine Stellen mehr frei.",output);
      }
    }
    SendClientMessage(playerid,COLOR_YELLOW,output);
    TogglePlayerControllable(playerid,true);
  }
  else
  {
    SendClientMessage(playerid,COLOR_YELLOW,"Sie müssen sich erst arbeitslos melden!");
    TogglePlayerControllable(playerid,true);
  }
}

public rath_pickups(playerid,pickupid)
{
  if(pickupid == rathausenter)
  {
    SetPlayerInterior(playerid, 0);
	SetPlayerPos(playerid,2312,-15.5,26.742187);
    SetPlayerVirtualWorld(playerid,1);
	textonenterbuilding(playerid,"Rathaus");
  }
  if(pickupid == rathausexit)
  {
    SetPlayerInterior(playerid, 0);
    SetPlayerVirtualWorld(playerid,0);
	SetPlayerPos(playerid,1275,-1329,13.5);
  }
  if(pickupid == einwamt)
  {
    ShowMenuForPlayer(einwamtmenu,playerid);
    TogglePlayerControllable(playerid,false);
    SetPlayerPos(playerid,2313,-1.49,26.742187);
  }
  if(pickupid == jobs)
  {
    ShowMenuForPlayer(aamtmenu,playerid);
    TogglePlayerControllable(playerid,false);
    SetPlayerPos(playerid,2313,-8.7,26.742187);
  }
}

public rathaus_response(playerid, dialogid, response, listitem, inputtext[])
{
  if(dialogid == 9)
  {
    if(response && listitem > 0)
    {
      checkjob(playerid,listitem);
    }
    else
      ShowMenuForPlayer(aamtmenu,playerid);
  }
}