forward showtacho(playerid);
forward start_timer(playerid,engine);
forward gesch(playerid);
forward hidetacho(playerid);
forward load_cars();

new Fahrzeugname[212][100];
new Fahrzeugdaten[212][4];
// [ID-400!][0] tank [1] verbrauch [2] Lizenz [3] Typ

new Float:Fahrzeuge[7000][6];
// [0] tank [1] Health [2] Timegoout [3] Owner [4] KM Stand [5] DB ID(wird danach wieder 0 gesetzt)

new Text:Typ[MAX_PLAYERS];
new Text:Gesch[MAX_PLAYERS];
new Text:Tank[MAX_PLAYERS];
new Text:Schaden[MAX_PLAYERS];
new Text:KM[MAX_PLAYERS];
new fahrstunde[MAX_PLAYERS];
new taxidriver[MAX_PLAYERS]; 	// Inhalt Kosten pro Kilometer für Fahrer
new taxistats[MAX_PLAYERS][5]; 	// [0] Fahrten
								// [1] Gewinn
								// [2] Ziel gesetzt für player (playerid)
								// [3] && [4] Gäste auf anderen Plätzen

public load_cars()
{
  new data[100],query[100];
  query = "SELECT * FROM `fahrzeuge` ORDER BY vid";
  mysql_query(query);
  mysql_store_result();
  for(new i = 0;i < 212;i++)
  {
    mysql_fetch_row(data);
    mysql_fetch_field("vname",data);
    Fahrzeugname[i] = data;
    mysql_fetch_field("fueltype",data);
    Fahrzeugdaten[i][3] = strval(data);
    mysql_fetch_field("fuelcap",data);
    Fahrzeugdaten[i][0] = strval(data);
    mysql_fetch_field("verbrauch",data);
    Fahrzeugdaten[i][1] = strval(data);
    mysql_fetch_field("lizenz",data);
    Fahrzeugdaten[i][2] = strval(data);
  }
  mysql_free_result();
  return 1;
}

public showtacho(playerid)
{
  new string[50],output[80];
  format(string,50,"Typ: ~p~%s",Fahrzeugname[GetVehicleModel(GetPlayerVehicleID(playerid))-400]);
  TextDrawSetString(Typ[playerid],string);
  
  if(playerdata[playerid][Fahrzeugdaten[GetVehicleModel(GetPlayerVehicleID(playerid))-400][2]] == 0 && fahrstunde[playerid] != Fahrzeugdaten[GetVehicleModel(GetPlayerVehicleID(playerid))-400][2])
  {
    RemovePlayerFromVehicle(playerid);
	GameTextForPlayer(playerid,"~r~Sie brauchen die entsprechende Lizenz",3000,3);
    return 0;
  }
  else if(playerdata[playerid][57] > 0)
  {
	RemovePlayerFromVehicle(playerid);
	GameTextForPlayer(playerid,"~r~Sie haben ein Fahrverbot",3000,3);
    return 0;
  }
  else if(GetVehicleModel(GetPlayerVehicleID(playerid)) != 509 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 510 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 481)
  {
	format(output,50,"Tank: ~w~%.0f l",Fahrzeuge[GetPlayerVehicleID(playerid)][0]);
	TextDrawSetString(Tank[playerid],output);
    
	new bool:engine, bool:lights, bool:alarm, bool:doors, bool:bonnet, bool:boot, bool:objective;
	GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, doors, bonnet, boot, objective);
	if(engine == true)
    {
      new seconds = gettime() - floatround(Fahrzeuge[GetPlayerVehicleID(playerid)][2]);
      Fahrzeuge[GetPlayerVehicleID(playerid)][0] = Fahrzeuge[GetPlayerVehicleID(playerid)][0] - (0.001 * seconds);
      if(Fahrzeuge[GetPlayerVehicleID(playerid)][0] < 0) Fahrzeuge[GetPlayerVehicleID(playerid)][0] = 0;
      format(output,50,"Tank: ~w~%.0f l",Fahrzeuge[GetPlayerVehicleID(playerid)][0]);
      TextDrawSetString(Tank[playerid],output);
    }
	SetVehicleHealth(GetPlayerVehicleID(playerid),Fahrzeuge[GetPlayerVehicleID(playerid)][1]);
	
	TextDrawShowForPlayer(playerid,Typ[playerid]);
	TextDrawShowForPlayer(playerid,Gesch[playerid]);
	TextDrawShowForPlayer(playerid,Tank[playerid]);
	TextDrawShowForPlayer(playerid,Schaden[playerid]);
    
    //KM Stand
    if(Fahrzeuge[GetPlayerVehicleID(playerid)][3] == playerdata[playerid][0])
    {
      format(output,50,"%7.0f km",Fahrzeuge[GetPlayerVehicleID(playerid)][4]);
      TextDrawSetString(KM[playerid],output);
      TextDrawShowForPlayer(playerid,KM[playerid]);
    }
  }
  
  if(Fahrzeuge[GetPlayerVehicleID(playerid)][3] > 0 && playerdata[playerid][0] != Fahrzeuge[GetPlayerVehicleID(playerid)][3])
  {
    RemovePlayerFromVehicle(playerid);
	GameTextForPlayer(playerid,"~r~Das ist nicht Ihr Auto!",3000,3);
    return 0;
  }
  return 1;
}

public hidetacho(playerid)
{
  TextDrawHideForPlayer(playerid,Typ[playerid]);
  TextDrawHideForPlayer(playerid,Gesch[playerid]);
  TextDrawHideForPlayer(playerid,Tank[playerid]);
  TextDrawHideForPlayer(playerid,Schaden[playerid]);
  TextDrawHideForPlayer(playerid,KM[playerid]);
}

stock CreateVehicleEx(modelid, Float:x, Float:y, Float:z, Float:angle, color1, color2, respawn_delay,owner = 0,km = 0,schild[32] = "")
{
  new vid;
  vid = CreateVehicle(modelid, Float:x, Float:y, Float:z, Float:angle, color1, color2, respawn_delay);
  Fahrzeuge[vid][0] = float(Fahrzeugdaten[modelid-400][0]);
  Fahrzeuge[vid][1] = 1000.0;
  Fahrzeuge[vid][2] = gettime();
  Fahrzeuge[vid][3] = owner;
  Fahrzeuge[vid][4] = km;
  Fahrzeuge[vid][5] = 0;
  SetVehicleNumberPlate(vid,schild);
  return vid;
}

public gesch(playerid)
{
   new Float:Velocity[3], output[80],geschw,schad,verbrauch;
   //Geschwindigkeit
   new bool:engine, bool:lights, bool:alarm, bool:doors, bool:bonnet, bool:boot, bool:objective;
   GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, doors, bonnet, boot, objective);
   if(engine == false)
   {
      TextDrawSetString(Gesch[playerid],"Geschw: Motor ~r~aus");
   }
   else
   {
      GetVehicleVelocity(GetPlayerVehicleID(playerid), Velocity[0], Velocity[1], Velocity[2]);
      geschw = floatround(floatsqroot(Velocity[0]*Velocity[0]+Velocity[1]*Velocity[1]+Velocity[2]*Velocity[2])*100*1.5,floatround_ceil);
      if(geschw < 70)
      {
        format(output, sizeof(output), "Geschw: ~g~%d ~w~km/h",geschw);
        verbrauch = floatround(Fahrzeugdaten[GetVehicleModel(GetPlayerVehicleID(playerid))-400][1] * 0.8);
      }
      else if(geschw >= 70 && geschw < 100)
      {
         format(output, sizeof(output), "Geschw: ~y~%d ~w~km/h",geschw);
         verbrauch = floatround(Fahrzeugdaten[GetVehicleModel(GetPlayerVehicleID(playerid))-400][1]);
      }
      else
      {
         format(output, sizeof(output), "Geschw: ~r~%d ~w~km/h",geschw);
         verbrauch = floatround(Fahrzeugdaten[GetVehicleModel(GetPlayerVehicleID(playerid))-400][1] * 1.2);
      }
      TextDrawSetString(Gesch[playerid],output);
      if(playerdata[playerid][0] == Fahrzeuge[GetPlayerVehicleID(playerid)][3])
	  {
		new Float:strecke = floatsqroot(Velocity[0]*Velocity[0]+Velocity[1]*Velocity[1]+Velocity[2]*Velocity[2]) / 100.0;
		if(strecke < 0.0005) strecke = 0.0005;
		Fahrzeuge[GetPlayerVehicleID(playerid)][4] = Fahrzeuge[GetPlayerVehicleID(playerid)][4] + strecke;
		if(floatround(Fahrzeuge[GetPlayerVehicleID(playerid)][4]) > floatround(Fahrzeuge[GetPlayerVehicleID(playerid)][4] - strecke) && Fahrzeuge[GetPlayerVehicleID(playerid)][4] > 75000)
		{
		  SetVehicleHealth(GetPlayerVehicleID(playerid),(Fahrzeuge[GetPlayerVehicleID(playerid)][1])-3.0);
		}
	  }
      else if(playerdata[playerid][2] == 7 && taxidriver[playerid] > 0)
      {
        new string[100];
        new Float:strecke = floatsqroot(Velocity[0]*Velocity[0]+Velocity[1]*Velocity[1]+Velocity[2]*Velocity[2]) / 100.0;
		if(strecke < 0.0005) strecke = 0.0005;
		Fahrzeuge[GetPlayerVehicleID(playerid)][4] = Fahrzeuge[GetPlayerVehicleID(playerid)][4] + strecke;
		if(floatround(Fahrzeuge[GetPlayerVehicleID(playerid)][4]) > floatround(Fahrzeuge[GetPlayerVehicleID(playerid)][4] - strecke))
        {
          if(taxistats[playerid][2] >= 0) taxiguest[taxistats[playerid][2]]++;
          if(taxistats[playerid][3] >= 0) taxiguest[taxistats[playerid][3]]++;
          if(taxistats[playerid][4] >= 0) taxiguest[taxistats[playerid][4]]++;
          format(string,100,"gef. Strecke: %i km",taxiguest[taxistats[playerid][2]]);
          TextDrawSetString(Gesch[taxistats[playerid][2]],string);
          format(string,100,"Kosten: %i $",taxiguest[taxistats[playerid][2]] * taxidriver[playerid]);
          TextDrawSetString(Tank[taxistats[playerid][2]],string);
        }
      }
   }
   
   //Schaden
   GetVehicleHealth(GetPlayerVehicleID(playerid),Fahrzeuge[GetPlayerVehicleID(playerid)][1]);
   schad = floatround(((((Fahrzeuge[GetPlayerVehicleID(playerid)][1] - 250) / 750) -1) *-100),floatround_ceil);
   if(schad > 100) schad = 100;
   if(schad < 50)
      format(output,50,"Schaden: ~g~%d%",schad);
   else if(schad >= 50 && schad < 75)
      format(output,50,"Schaden: ~y~%d%",schad);
   else
      format(output,50,"Schaden: ~r~%d%",schad);
   TextDrawSetString(Schaden[playerid],output);
   
   //Verbrauch
   new Float:strecke;
   new Float:tanks;
   strecke = floatsqroot(Velocity[0]*Velocity[0]+Velocity[1]*Velocity[1]+Velocity[2]*Velocity[2])*100;
   tanks = (verbrauch * strecke)/300000;
   if(tanks == 0 && engine == true) tanks = 0.00005;
   Fahrzeuge[GetPlayerVehicleID(playerid)][0] = Fahrzeuge[GetPlayerVehicleID(playerid)][0] - tanks;
   if(Fahrzeuge[GetPlayerVehicleID(playerid)][0] <= 0)
   {
	Fahrzeuge[GetPlayerVehicleID(playerid)][0] = 0;
	SetVehicleParamsEx(GetPlayerVehicleID(playerid),false,lights, alarm, doors, bonnet, boot, objective);
	format(output,50,"Tank: ~r~ leer");
	GameTextForPlayer(playerid,"~r~Tank ~w~des Fahrzeugs ist leer",2000,3);
   }
   else if(Fahrzeuge[GetPlayerVehicleID(playerid)][0] < 5)
	format(output,50,"Tank: ~r~%.0f l",Fahrzeuge[GetPlayerVehicleID(playerid)][0]);
   else if(Fahrzeuge[GetPlayerVehicleID(playerid)][0] < 10)
	format(output,50,"Tank: ~y~%.0f l",Fahrzeuge[GetPlayerVehicleID(playerid)][0]);
   else
	format(output,50,"Tank: ~w~%.0f l",Fahrzeuge[GetPlayerVehicleID(playerid)][0]);
   TextDrawSetString(Tank[playerid],output);
   Fahrzeuge[GetPlayerVehicleID(playerid)][2] = gettime();
   
   //KM Stand
   if(playerdata[playerid][0] == Fahrzeuge[GetPlayerVehicleID(playerid)][3])
   {
	format(output,50,"%7.1f km",Fahrzeuge[GetPlayerVehicleID(playerid)][4]);
	TextDrawSetString(KM[playerid],output);
   }
}
