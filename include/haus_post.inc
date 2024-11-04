forward post();
forward sendpost(playerid,row);
forward dopost(playerid,text[]);
forward post_response(playerid, dialogid, response, listitem, inputtext[]);
forward post_pickups(playerid,pickupid);

new postenter,postdia,postexit,postinfo,Menu:postmenu,postw[MAX_PLAYERS];

/*
 * Arten von Express
 * 0 => kurze Nachricht(35) = kurze Strecke
 * 1 => mittlere Nachricht (75) = mittlere Strecke
 * 2 => grosse Nachricht(125) = grosse Strecke
 * 3 => mittlere Nachricht(75) = kurze Strecke
 * 4 => grosse Nachricht(125) = kurze Strecke
 */

public post()
{
  postenter = CreatePickup(1559, 1, -1749.69,  870.55,  25.5,0);
  Create3DTextLabel("Postamt betreten",COLOR_WHITE,-1749.69,  870.55,  26,10,0,false);
  postdia = CreatePickup(1239, 1, 822.24,  1.98,  1004.17,0);
  Create3DTextLabel("Werbung beantragen",COLOR_WHITE,822.24,  1.98,  1005,10,0,false);
  postexit = CreatePickup(1559, 1, 834.50,  7.35,  1004.18,0);
  Create3DTextLabel("Postamt verlassen",COLOR_WHITE,834.50,  7.35,  1005,10,0,false);
  postinfo = CreatePickup(1239, 1, 830.24,  1,  1004.17,0);
  Create3DTextLabel("Information",COLOR_WHITE,830.24,  1,  1005,10,0,false);
  
  postmenu = CreateMenu("Postamt",1, 50.0, 100.0, 650.0);
  
  AddMenuItem(postmenu, 0, "Kleine Werbung");
  AddMenuItem(postmenu, 0, "Mittlere Werbung");
  AddMenuItem(postmenu, 0, "Grosse Werbung");
  AddMenuItem(postmenu, 0, "Mittlere Express");
  AddMenuItem(postmenu, 0, "Grosse Express Werbung");
  
  CreateDynamicMapIcon(-1749.69,  870.55,  25.5, 32, -1,-1, -1, -1, 500);
}

public sendpost(playerid,row)
{
  new query[100],data[25];
  format(query, sizeof(query), "SELECT COUNT(*) as anz FROM `accounts` WHERE `jobid`=2");
  mysql_query(query);
  mysql_store_result();
  mysql_fetch_row(data);
  mysql_fetch_field("anz",data);
  ;
  if(strval(data) > 0)
  {
	ShowPlayerDialog(playerid, 100,DIALOG_STYLE_INPUT , "Text für die Werbung", "Gebe hier deinen Text für die Werbung ein (Absender und Telefonnummer werden automatisch hinzugefügt):", "Bestätigen", "Abbrechen");
  }
  else
  {
	SendClientMessage(playerid,COLOR_RED,"Zur Zeit gibt es keine Postboten um die Werbung auszutragen!");
	TogglePlayerControllable(playerid,true);
  }
  postw[playerid] = row ;
}

public dopost(playerid,text[])
{
  new txt[126];
  if(postw[playerid] == 0){format(txt,36,"%s",text); giveusermoney(playerid,-75);}
  else if(postw[playerid] == 1){format(txt,76,"%s",text);giveusermoney(playerid,-150);}
  else if(postw[playerid] == 2){format(txt,126,"%s",text);giveusermoney(playerid,-300);}
  else if(postw[playerid] == 3){format(txt,76,"%s",text);giveusermoney(playerid,-200);}
  else if(postw[playerid] == 4){format(txt,126,"%s",text);giveusermoney(playerid,-350);}
  new query[250];
  mysql_real_escape_string(txt,txt);
  format(query, sizeof(query), "INSERT INTO werbung (playerid,kind,msg) VALUES (%i,%i,'%s')",playerdata[playerid][0],postw[playerid],txt);
  mysql_query(query);
  SendClientMessage(playerid,COLOR_YELLOW,"Werbung wurde in Auftrag geben ein Postbote wird sie ausliefern!");
  TogglePlayerControllable(playerid,true);
}

public post_response(playerid, dialogid, response, listitem, inputtext[])
{
  if(dialogid == 100)
  {
  	if(response)
	  dopost(playerid,inputtext);
	else
      TogglePlayerControllable(playerid,true);
  }
}

public post_pickups(playerid,pickupid)
{
  if(pickupid == postdia)
  {
    ShowMenuForPlayer(postmenu,playerid);
    TogglePlayerControllable(playerid,false);
    SetPlayerPos(playerid,825.24,  1.98,  1004.17);
  }
  if(pickupid == postenter)
  {
	SetPlayerInterior(playerid, 3);
	SetPlayerPos(playerid,830.52,  6.36,  1004.17);
	textonenterbuilding(playerid,"Postamt");
  }
  if(pickupid == postexit)
  {
	SetPlayerInterior(playerid, 0);
	SetPlayerPos(playerid,-1747.69,  860.55,  25.5);
  }
  if(pickupid == postinfo)
  {
	hilfe(playerid,"werbung");
	SetPlayerPos(playerid,827.24,  1.98,  1004.17);
  }
}