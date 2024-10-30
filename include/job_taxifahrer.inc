forward taxi();
forward taxidialog(playerid);
forward taxidialogr(playerid, dialogid, response, listitem,inputtext[]);
forward taxistreckebeenden(playerid);
forward taxibeenden(playerid);
forward abbruch_taxi(playerid,kind);
forward taxigivedrivercheckpoint(playerid,Float:fX,Float:fY,Float:fZ);
forward taxiguestbeenden(playerid,kind,driverid);
forward taxistartefahrt(playerid);
forward finddriverbyexit(playerid);
forward showfortaxidriver(playerid,kind);
forward taxichangepreis(playerid);

new taxionduty[15]; 			// Alle Taxifahrer auf einem Blick max 15
new taxitimer[MAX_PLAYERS];

public taxi()
{
  CreateVehicleEx(420,1708.79, 1288.5, 10.82,0,6,0,120,0,0,"Taxi");
  CreateVehicleEx(420,1705.54, 1288.5, 10.82,0,6,0,120,0,0,"Taxi");
  CreateVehicleEx(420,1702.44, 1288.5, 10.82,0,6,0,120,0,0,"Taxi");
  CreateVehicleEx(420,1698.71, 1288.5, 10.82,0,6,0,120,0,0,"Taxi");
  CreateVehicleEx(420,1695.30, 1288.5, 10.82,0,6,0,120,0,0,"Taxi");
  
  CreateVehicleEx(420,-1976.0, 173.0, 27.68,90,6,0,120,0,0,"Taxi");
  CreateVehicleEx(420,-1976.0, 177.0, 27.68,90,6,0,120,0,0,"Taxi");
  CreateVehicleEx(420,-1976.0, 182.0, 27.68,90,6,0,120,0,0,"Taxi");
  CreateVehicleEx(420,-1976.0, 187.0, 27.68,90,6,0,120,0,0,"Taxi");
  CreateVehicleEx(420,-1976.0, 192.0, 27.68,90,6,0,120,0,0,"Taxi");
  
  CreateVehicleEx(420, 1777.0, -1887.0, 13.38,270,6,0,120,0,0,"Taxi");
  CreateVehicleEx(420, 1777.0, -1892.0, 13.38,270,6,0,120,0,0,"Taxi");
  CreateVehicleEx(420, 1777.0, -1897.0, 13.38,270,6,0,120,0,0,"Taxi");
  CreateVehicleEx(420, 1777.0, -1902.0, 13.38,270,6,0,120,0,0,"Taxi");
  CreateVehicleEx(420, 1777.0, -1907.0, 13.38,270,6,0,120,0,0,"Taxi");
  
  for(new i;i < sizeof(taxionduty);i++)
	taxionduty[i] = -1;
}

public taxidialog(playerid)
{
  if(taxidriver[playerid] == 0)
    ShowPlayerDialog(playerid, 102, DIALOG_STYLE_MSGBOX, "Taxifahrer", "Starte einen Job als Taxifahrer.\n Info: Es wird eine Kaution für das Fahrzeug erhoben, diese wird erst zurückgegeben bei mindestens einer Fahrt als Taxifahrer." , "Weiter", "Abbrechen");
}

public taxidialogr(playerid, dialogid, response, listitem,inputtext[])
{
  if(dialogid == 102)
  {
	if(response)
	  ShowPlayerDialog(playerid, 103, DIALOG_STYLE_INPUT, "Taxifahrer", "Geben Sie die Kosten für die Fahrt pro Kilometer an: \n (zwischen 1 und 5 $)" , "Starten", "Abbrechen");
	else
	  RemovePlayerFromVehicle(playerid);
  }
  if(dialogid == 103)
  {
	if(response)
	{
	  if(strval(inputtext) >= 1 && strval(inputtext) <= 5)
	  {
		for(new i;i < sizeof(taxionduty);i++)
		{
		  if(taxionduty[i] == -1)
		  {
			taxionduty[i] = playerid;
			i = sizeof(taxionduty);
		  }
		}
        new output[50];
		taxidriver[playerid] = strval(inputtext);
        playerdata[playerid][4] = playerdata[playerid][4] - 500; 
        GivePlayerMoney(playerid,-500);
        format(output,50,"Gaeste im Taxi: 0");
        TextDrawSetString(KM[playerid],output);
        TextDrawShowForPlayer(playerid,KM[playerid]);
		taxistats[playerid][2] = -1;
		taxistats[playerid][3] = -1;
		taxistats[playerid][4] = -1;
	  }
	  else
		ShowPlayerDialog(playerid, 103, DIALOG_STYLE_INPUT, "Taxifahrer", "Geben Sie die Kosten für die Fahrt pro Kilometer an: \n (zwischen 1 und 5 $)" , "Starten", "Abbrechen");
	}
	else
	  RemovePlayerFromVehicle(playerid);
  }
  if(dialogid == 104)
  {
    if(response)
    {
      new ok = -1;
      for(new i; i < sizeof(taxionduty); i++)
      {
        if(taxionduty[i] >= 0)
        {
          if(GetPlayerVehicleID(playerid) == GetPlayerVehicleID(taxionduty[i]))
          {
            ok = taxionduty[i];
            i = sizeof(taxionduty);
          }
        }
      }
      if(ok >= 0)
      {
        new string[100],i;
        if(taxistats[ok][2] >= 0)
        {
          if(taxistats[ok][3] >= 0){ taxistats[ok][4] = playerid; i++;}
          else taxistats[ok][3] = playerid;
          taxiguest[playerid] = 1;
          KillTimer(taxitimer[playerid]);
          i++;
          i++;
        }
        else
        {
          GameTextForPlayer(playerid,"~w~Klick auf die Map",3000,1);
          taxistats[ok][2] = playerid;
          taxiguest[playerid] = 1;
          i++;
        }
        format(string,50,"Gaeste im Taxi: %i",i);
        TextDrawSetString(KM[ok],string);
        TextDrawShowForPlayer(playerid,Tank[playerid]);
        TextDrawShowForPlayer(playerid,Typ[playerid]);
        TextDrawShowForPlayer(playerid,Gesch[playerid]);
        TextDrawSetString(Typ[playerid],"Taxikosten");
        format(string,100,"gef. Strecke: %i km",taxiguest[playerid]);
        TextDrawSetString(Gesch[playerid],string);
        format(string,100,"Kosten: %i $",taxiguest[playerid]);
        TextDrawSetString(Tank[playerid],string);
        showfortaxidriver(playerid,1);
      }
      else
        RemovePlayerFromVehicle(playerid);
    }
    else
      RemovePlayerFromVehicle(playerid);
  }
  if(dialogid == 105)
  {
    new ok = -1;
    for(new i; i < sizeof(taxionduty); i++)
    {
      if(taxionduty[i] >= 0)
      {
        new Float:x, Float:y, Float:z;
        GetPlayerPos(taxionduty[i], x, y, z);
        if(GetPlayerDistanceFromPoint(playerid, x, y, z) < 2000)
        {
          ok = taxionduty[i];
          i = sizeof(taxionduty);
        }
      }
    }
    if(ok >= 0 && taxiguest[playerid] == 0)
    {
      showfortaxidriver(playerid,0);
      GameTextForPlayer(playerid,"~w~Taxi wurde gerufen",3000,1);
      taxiguest[playerid] = -1;
    }
    else
    {
      if(taxiguest[playerid] == 0) GameTextForPlayer(playerid,"~w~Kein Taxi in Reichweite",3000,1);
      taxiguest[playerid] = 0;
      showfortaxidriver(playerid,1);
    }
  }
}

public abbruch_taxi(playerid,kind)
{
  taxistreckebeenden(playerid);
  taxidriver[playerid] = 0;
  for(new i;i < sizeof(taxionduty);i++)
  {
    if(taxionduty[i] == playerid)
	{
	  taxionduty[i] = -1;
	  i = sizeof(taxionduty);
	}
  }
  if(kind == 1)
  {
	giveusermoney(playerid,500);
	SetVehicleParamsEx(GetPlayerVehicleID(playerid), 0, 0, 0, 0, 0, 0, 0);
	SetVehicleToRespawn(GetPlayerVehicleID(playerid));
	new money = floatround((float(Fahrzeugdaten[420-400][0]) - Fahrzeuge[GetPlayerVehicleID(playerid)][0])*1.31);
	playerdata[playerid][4] = playerdata[playerid][4] - money; 
	GivePlayerMoney(playerid,-1 * money);
	Fahrzeuge[GetPlayerVehicleID(playerid)][0] = float(Fahrzeugdaten[420-400][0]);
	RemovePlayerFromVehicle(playerid);
	DisablePlayerCheckpoint(playerid);
	navivar[playerid] = 0;
  }
  taxistats[playerid][0] = 0;
  taxistats[playerid][1] = 0;
  taxistats[playerid][2] = 0;
  TextDrawHideForPlayer(playerid,KM[playerid]);
}

public taxibeenden(playerid)
{
  new Float:dest[][3] =
  {
	{1776.67, -1914.97, 13.38},
	{1686.66, 1288.12, 10.82},
	{-1985.60, 204.36, 27.68}
  };
  taxistreckebeenden(playerid);
  taxistreckebeenden(playerid);
  taxistreckebeenden(playerid);
  new engine, lights, alarm, doors, bonnet, boot, objective;
  GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, doors, bonnet, boot, objective);
  SetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, 1, bonnet, boot, objective);
  SetVehicleParamsForPlayer(GetPlayerVehicleID(playerid),playerid,0,0);
  new Float:distb = 9999.99;
  new baid;
  for(new i=0;i < sizeof(dest);i++)
  {
	if(GetPlayerDistanceFromPoint(playerid,dest[i][0],dest[i][1],dest[i][2]) < distb)
	{
	  distb = GetPlayerDistanceFromPoint(playerid,dest[i][0],dest[i][1],dest[i][2]);
	  baid = i;
	}
  }
  GameTextForPlayer(playerid,"~w~Bringen Sie das Auto zum Punkt.",3000,1);
  SetPlayerCheckpoint(playerid,dest[baid][0],dest[baid][1],dest[baid][2],5.0);
  navivar[playerid] = 2;
}

public taxistreckebeenden(playerid)
{
  if(taxistats[playerid][2] >= 0)
  {
	taxiguestbeenden(taxistats[playerid][2],1,playerid);
  }
}

public taxiguestbeenden(playerid,kind,driverid)
{
  //Kosten Fahrer geben
  new kosten = taxiguest[playerid] * taxidriver[driverid];
  taxistats[playerid][0]++;
  taxistats[playerid][1] = taxistats[playerid][1] + kosten;
  
  playerdata[playerid][4] = playerdata[playerid][4] - kosten;
  GivePlayerMoney(playerid,-1 * kosten);
  
  if(kosten > 20) playerdata[driverid][9]++;
  
  giveusermoney(driverid,kosten);
  new string[50];
  format(string,50,"~w~Sie haben %i $ bezahlt.",kosten);
  GameTextForPlayer(playerid,string,3000,1);
  format(string,50,"~w~Sie haben %i $ erhalten.",kosten);
  GameTextForPlayer(driverid,string,3000,1);
  //alles Null setzen und andere Spieler nachrücken
  if(kind == 1)
  {
	DisablePlayerCheckpoint(driverid);
	navivar[playerid] = 0;
    playerdata[driverid][8]++;
	if(taxistats[driverid][3] >= 0)
	{
	  taxistats[driverid][2] = taxistats[driverid][3];
	  taxistartefahrt(taxistats[driverid][3]);
	  if(taxistats[driverid][4] >= 0)
	  {
		taxistats[driverid][3] = taxistats[driverid][4];
		taxistats[driverid][4] = -1;
	  }
	  else
		taxistats[driverid][3] = -1;
      
	}
	else
	  taxistats[driverid][2] = -1;
  }
  else if(kind == 2)
  {
	if(taxistats[driverid][4] >= 0)
	{
	  taxistats[driverid][3] = taxistats[driverid][4];
	  taxistats[driverid][4] = -1;
	}
	else
	  taxistats[driverid][3] = -1;
  }
  else
	taxistats[driverid][4] = -1;
  taxiguest[playerid] = 0;
  if(taxistats[driverid][4] >= 0)
    format(string,50,"Gaeste im Taxi: %i",3);
  else if(taxistats[driverid][3] >= 0)
    format(string,50,"Gaeste im Taxi: %i",2);
  else if(taxistats[driverid][2] >= 0)
    format(string,50,"Gaeste im Taxi: %i",1);
  else
    format(string,50,"Gaeste im Taxi: %i",0);
  TextDrawSetString(KM[driverid],string);
  RemovePlayerFromVehicle(playerid);
  TextDrawHideForPlayer(playerid,Tank[playerid]);
  TextDrawHideForPlayer(playerid,Gesch[playerid]);
  TextDrawHideForPlayer(playerid,Typ[playerid]);
}

public taxistartefahrt(playerid)
{
  new ok = -1;
  for(new i; i < sizeof(taxionduty); i++)
  {
    if(taxionduty[i] >= 0)
    {
      if(GetPlayerVehicleID(playerid) == GetPlayerVehicleID(taxionduty[i]))
      {
        ok = taxionduty[i];
        i = sizeof(taxionduty);
      }
    }
  }
  if(ok >= 0)
  {
    if(taxistats[ok][2] >= 0 && taxistats[ok][2] != playerid && taxistats[ok][3] >= 0 && taxistats[ok][4] >= 0)
    {
      RemovePlayerFromVehicle(playerid);
    }
    else
    {
      if(taxistats[ok][2] >= 0 && taxistats[ok][2] != playerid)
      {
        ShowPlayerDialog(playerid, 104, DIALOG_STYLE_MSGBOX, "Mitfahren im Taxi", "Der Taxifahrer hat schon ein Ziel von eine anderen Gast.\n Sie können gerne Mitfahren und warten bis sie an der Reihe sind.(15 Sekunden Zeit zur Entscheidung)" , "Mitfahren", "Aussteigen");
        taxitimer[playerid] = SetTimerEx("RemovePlayerFromVehicle",15000,false,"i",playerid);
      }
      else
        ShowPlayerDialog(playerid, 104, DIALOG_STYLE_MSGBOX, "Zieleingabe fürs Taxi", "Kosten pro Kilometer: %.2f\n Zieleingabe per Rechtsklick auf die Karte" , "Auswählen", "Aussteigen");
    }
  }
  else
    RemovePlayerFromVehicle(playerid);
}

public finddriverbyexit(playerid)
{
  for(new i; i < sizeof(taxionduty); i++)
  {
    if(taxionduty[i] >= 0)
    {
      if(taxistats[taxionduty[i]][2] == playerid) taxiguestbeenden(playerid,1,taxionduty[i]);
      else if(taxistats[taxionduty[i]][3] == playerid) taxiguestbeenden(playerid,2,taxionduty[i]);
      else if(taxistats[taxionduty[i]][4] == playerid) taxiguestbeenden(playerid,3,taxionduty[i]);
    }
  }
}

public taxigivedrivercheckpoint(playerid,Float:fX,Float:fY,Float:fZ)
{
  new ok = -1;
  for(new i; i < sizeof(taxionduty); i++)
  {
    if(taxionduty[i] >= 0)
    {
      if(GetPlayerVehicleID(playerid) == GetPlayerVehicleID(taxionduty[i]))
      {
        ok = taxionduty[i];
        i = sizeof(taxionduty);
      }
    }
  }
  if(ok >= 0 && taxistats[ok][2] == playerid)
  {
    SetPlayerCheckpoint(ok,fX,fY,fZ,5);
  }
}

public showfortaxidriver(playerid,kind)
{
  for(new i; i < sizeof(taxionduty); i++)
  {
    if(taxionduty[i] >= 0)
    {
      new Float:x, Float:y, Float:z;
      GetPlayerPos(taxionduty[i], x, y, z);
      if(GetPlayerDistanceFromPoint(playerid, x, y, z) < 2000)
      {
        if(kind == 0)
        {
          SetPlayerMarkerForPlayer(taxionduty[i], playerid, COLOR_YELLOW);
          GameTextForPlayer(playerid,"~w~Neuer Fahrgast in Reichweite.",3000,1);
        }
        else SetPlayerMarkerForPlayer(taxionduty[i], playerid, COLOR_INVISIBLE);
      }
    }
  }
}

public taxichangepreis(playerid)
{
  if(taxistats[playerid][2] < 0 && taxistats[playerid][3] < 0 && taxistats[playerid][4] < 0)
  {
    for(new i;i < sizeof(taxionduty);i++)
	{
	  if(taxionduty[i] == playerid)
	  {
		taxionduty[i] = -1;
		i = sizeof(taxionduty);
	  }
	}
    ShowPlayerDialog(playerid, 103, DIALOG_STYLE_INPUT, "Taxifahrer", "Geben Sie die Kosten für die Fahrt pro Kilometer an: \n (zwischen 1 und 5 $)" , "Starten", "Abbrechen");
  }
}