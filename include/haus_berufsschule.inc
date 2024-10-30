forward berufsschule();
forward berufs_pickup(playerid,pickupid);
forward berufs_response(playerid, dialogid, response, listitem, inputtext[]);
forward berufs_theorie(playerid);
forward berufs_fragen(playerid,anz,input[]);

new berufs_enter,berufs_exit,berufs_info,berufs[MAX_PLAYERS];

public berufsschule()
{
  berufs_enter = CreatePickup(1559, 1, 1218.51, -1692.62, 20, 0);
  Create3DTextLabel("Berufsschule betreten",COLOR_WHITE,1218.51, -1692.62, 20,10,0,false);
  berufs_exit = CreatePickup(1559, 1, 1494.46, 1303.58, 1093.28, 0);
  Create3DTextLabel("Berufsschule verlassen",COLOR_WHITE, 1494.46, 1303.58, 1093.28,10,0,false);
  berufs_info = CreatePickup(1239, 1, 1491.23, 1306.77, 1093.28, 0);
  Create3DTextLabel("Berufsschule Information",COLOR_WHITE,1491.23, 1306.77, 1093.28,0,false);
  CreateDynamicMapIcon(1218.51, -1692.62, 20, 36, -1,-1, -1, -1, 500);
}

public berufs_pickup(playerid,pickupid)
{
  if(pickupid == berufs_enter)
  {
    SetPlayerInterior(playerid, 3);
    SetPlayerPos(playerid,1495.91, 1308.08, 1093.29);
    SetPlayerFacingAngle(playerid,146.06);
    textonenterbuilding(playerid,"Berufsschule");
  }
  if(pickupid == berufs_exit)
  {
    SetPlayerInterior(playerid, 0);
    SetPlayerPos(playerid,1223.79, -1692.27, 19.46);
    SetPlayerFacingAngle(playerid,270);
  }
  if(pickupid == berufs_info)
  {
    new output[500];
    strcat(output,"Herzlich Willkommen in der Breufsschule \n\n");
    strcat(output,"Hier werden alle Grundlagen für die meisten Berufe vermittelt.\n\n");
    strcat(output,"Im nächsten Fenster steht eine Auswahl der Kurs für Sie bereit.\n\n");
    ShowPlayerDialog(playerid, 60, DIALOG_STYLE_MSGBOX , "Berufschule Information",output, "Kurswahl", "Verlassen");
    SetPlayerPos(playerid,1500.31, 1309.32, 1093.28);
  }
}

public berufs_response(playerid, dialogid, response, listitem, inputtext[])
{
  if(dialogid == 60 && response)
  {
    new output[500];
    strcat(output,"Fahrlehrer\n");
    strcat(output,"Pilot \n");
    strcat(output,"Postbote \n");
    strcat(output,"Polizist \n");
    strcat(output,"Prodfahrer \n");
    strcat(output,"Trucker \n");
    strcat(output,"Bauer \n");
    strcat(output,"Waffenhändler \n");
    strcat(output,"Fischer \n");
    strcat(output,"Drogenhändler \n");
    strcat(output,"Taxifahrer \n");
    strcat(output,"Sanitäter \n");
    strcat(output,"Müllfahrer \n");
    strcat(output,"Auftragsmörder \n");
    strcat(output,"Touristik \n");
    ShowPlayerDialog(playerid, 61, DIALOG_STYLE_LIST , "Kurs wählen",output, "Kurs starten", "Verlassen");
  }
  if(dialogid == 61 && response)
  {
    switch(listitem)
    {
      case 0:
      {
        //Fahrlehrer
        if(playerdata[playerid][38] == 0)
          berufs[playerid] = 38;
        else
          GameTextForPlayer(playerid, "~r~ Sie haben diesen Kurs bereits!", 3000, 1);
      }
      case 1:
      {
        //Pilot
        if(playerdata[playerid][39] == 0)
          berufs[playerid] = 39;
        else
          GameTextForPlayer(playerid, "~r~ Sie haben diesen Kurs bereits!", 3000, 1);
      }
      case 2:
      {
        //Postbote
        if(playerdata[playerid][41] == 0)
          berufs[playerid] = 41;
        else
          GameTextForPlayer(playerid, "~r~ Sie haben diesen Kurs bereits!", 3000, 1);
      }
      case 3:
      {
        //Polizist
        if(playerdata[playerid][40] == 0)
          berufs[playerid] = 40;
        else
          GameTextForPlayer(playerid, "~r~ Sie haben diesen Kurs bereits!", 3000, 1);
      }
      case 4:
      {
        //Prodfahrer
        if(playerdata[playerid][42] == 0)
          berufs[playerid] = 42;
        else
          GameTextForPlayer(playerid, "~r~ Sie haben diesen Kurs bereits!", 3000, 1);
      }
      case 5:
      {
        //Trucker
        if(playerdata[playerid][43] == 0)
          berufs[playerid] = 43;
        else
          GameTextForPlayer(playerid, "~r~ Sie haben diesen Kurs bereits!", 3000, 1);
      }
      case 6:
      {
        //Bauer
        if(playerdata[playerid][45] == 0)
          berufs[playerid] = 45;
        else
          GameTextForPlayer(playerid, "~r~ Sie haben diesen Kurs bereits!", 3000, 1);
      }
      case 7:
      {
        //Waffendealer
        if(playerdata[playerid][46] == 0)
          berufs[playerid] = 46;
        else
          GameTextForPlayer(playerid, "~r~ Sie haben diesen Kurs bereits!", 3000, 1);
      }
      case 8:
      {
        //Fischer
        if(playerdata[playerid][47] == 0)
          berufs[playerid] = 47;
        else
          GameTextForPlayer(playerid, "~r~ Sie haben diesen Kurs bereits!", 3000, 1);
      }
      case 9:
      {
        //Drogendealer
        if(playerdata[playerid][48] == 0)
          berufs[playerid] = 48;
        else
          GameTextForPlayer(playerid, "~r~ Sie haben diesen Kurs bereits!", 3000, 1);
      }
      case 10:
      {
        //Taxifahrer
        if(playerdata[playerid][50] == 0)
          berufs[playerid] = 50;
        else
          GameTextForPlayer(playerid, "~r~ Sie haben diesen Kurs bereits!", 3000, 1);
      }
      case 11:
      {
        //Sanitäter
        if(playerdata[playerid][51] == 0)
          berufs[playerid] = 51;
        else
          GameTextForPlayer(playerid, "~r~ Sie haben diesen Kurs bereits!", 3000, 1);
      }
      case 12:
      {
        //Müllfahrer
        if(playerdata[playerid][52] == 0)
          berufs[playerid] = 52;
        else
          GameTextForPlayer(playerid, "~r~ Sie haben diesen Kurs bereits!", 3000, 1);
      }
      case 13:
      {
        //Auftragsmörder
        if(playerdata[playerid][53] == 0)
          berufs[playerid] = 53;
        else
          GameTextForPlayer(playerid, "~r~ Sie haben diesen Kurs bereits!", 3000, 1);
      }
      case 14:
      {
        //Touristik
        if(playerdata[playerid][54] == 0)
          berufs[playerid] = 54;
        else
          GameTextForPlayer(playerid, "~r~ Sie haben diesen Kurs bereits!", 3000, 1);
      }
    }
    
    if(berufs[playerid] > 0)
    {
      
      if(giveusermoney(playerid,-100))
        berufs_theorie(playerid);
      else GameTextForPlayer(playerid, "~r~ Nicht genug Geld dabei!", 3000, 1);
    }
  }
  if(dialogid == 62 && response)
  {
    berufs_fragen(playerid,1,inputtext);
  }
  if(dialogid == 63 && response)
  {
    berufs_fragen(playerid,2,inputtext);
  }
  if(dialogid == 64 && response)
  {
    berufs_fragen(playerid,3,inputtext);
  }
  if(dialogid == 65 && response)
  {
    berufs_fragen(playerid,4,inputtext);
  }
  if(dialogid == 66 && response)
  {
    berufs_fragen(playerid,5,inputtext);
  }
  if(dialogid == 67 && response)
  {
    berufs_fragen(playerid,6,inputtext);
  }
  if(dialogid == 68 && response)
  {
    berufs_fragen(playerid,7,inputtext);
  }
  if(dialogid == 69 && response)
  {
    berufs_fragen(playerid,8,inputtext);
  }
}

public berufs_theorie(playerid)
{
  switch(berufs[playerid])
  {
    case 38:
    {
      new output[500];
      strcat(output,"Der Beruf Fahrlehrer \n");
      strcat(output,"   Aufgaben: Er bildet Spieler hinterm Steuer von verschieden Fahrzeugen aus.\n");
      strcat(output,"   Funktion: Führt Fahrstunden durch um Lizenzen zu verteilen.\n");
      strcat(output,"\tBeschreibung: \n\t\tDer Fahrlehrer ist ein gehobener Beruf mit einem dynamischen Grundgehalt.\n");
      strcat(output,"\t\tSein Verdienst regelt sich nach seinen Fahrstunden und der Art der Fahrstunde.\n");
      strcat(output,"\t\tEr hat sein Hauptdepot am Flughafen in San Fierro.\n");
      strcat(output,"\t\tUm als Fahrlehrer in Dienst zu gehen muss er im Depot durch ein i laufen.\n");
      strcat(output,"\t\tEs gibt verschiedene 'Befehle' und Regeln für den Fahrlehrer. Befehle können über das Aktionsmenü ausgeführt werden.\n");
      strcat(output,"\tRegeln: \n\t\tAlle Fahrschüler müssen mit einem Cady herumgefahren werden.\n");
      strcat(output,"\t\tDer Zugang zum Depot / Gelände ist nur Piloten und Fahrlehrern (-Schülern) gestattet.\n");
      strcat(output,"\t\tFahrschulautos werden beim Aussteigen des Fahrleherers betankt und repariert.\n");
      strcat(output,"\t\tBei Flugzeugausbildung beantragt der Fahrlehrer die Start- /Landeerlaubnis für den Schüler.\n");
      strcat(output,"\t\tDer Fahrlehrer kann nur die Lizenzen ausbilden, welche er auch selbst besitzt.\n");
      strcat(output,"\t\tEs gelten immer die allgemeinen Verkehrsregeln.\n");
      ShowPlayerDialog(playerid, 62, DIALOG_STYLE_MSGBOX , "Fahrlehrerkurs",output, "Weiter", "");
    }
    case 39:
    {
      new output[500];
      strcat(output,"Der Beruf Pilot \n");
      strcat(output,"\tAufgaben: Fliegt Passagierrouten zwischen den 3 Städten und Frachtflüge.\n");
      strcat(output,"\tFunktion: Transportiert Güter zwischen den Flughäfen.\n");
      strcat(output,"\tBeschreibung: \n\t\tDer Pilot ist ein gehobener Beruf mit einem Grundgehalt von 5000 $ pro Zahltag.\n");
      strcat(output,"\t\tEr hat sein Hauptdepot am Flughafen in San Fierro und fliegt überwiegend Passagierflüge.\n");
      strcat(output,"\t\tBei Bedarf fliegt er Frachtflüge mit einer Transportmaschine und Kurierflüge mit einem Helicopter.\n");
      strcat(output,"\t\tEs gibt 5 Erfahrungsstufen, welche jede Einzelne eine extra Provision pro Flug gibt.\n");
      ShowPlayerDialog(playerid, 62, DIALOG_STYLE_MSGBOX , "Pilotenkurs",output, "Weiter", "");
    }
    case 40:
    {
      new output[500];
      strcat(output,"Der Beruf Polizist \n");
      strcat(output,"   Aufgaben: \n");
      strcat(output,"   Funktion: \n");
      ShowPlayerDialog(playerid, 62, DIALOG_STYLE_MSGBOX , "Polizistkurs",output, "Weiter", "");
    }
    case 41:
    {
      new output[500];
      strcat(output,"Der Beruf Postbote \n");
      strcat(output,"\tAufgaben: Verteilt Pakete und Werbung an verschiedene Adressen in Las Venturas.\n");
      strcat(output,"\tFunktion: Verteilt von Spielern aufgebene Werbung / Flyer\n");
      strcat(output,"\tBeschreibung: \n\t\tDer Postbote ist ein Mittelständiger Beruf mit einem Grundgehalt von 1400 $ pro Zahltag.\n");
      strcat(output,"\t\tEs ist ein Job mit einem Depot in Las Venturas und hat verschiedene Postrouten und Expressstrecken.\n");
      strcat(output,"\t\tEs gibt 5 Erfahrungsstufen, welche immer mehr Extraverdienst pro Auslieferung mit sich bringen.\n");
      ShowPlayerDialog(playerid, 62, DIALOG_STYLE_MSGBOX , "Postbotekurs",output, "Weiter", "");
    }
    case 42:
    {
      new output[500];
      strcat(output,"Der Beruf Prodfahrer \n");
      strcat(output,"   Aufgaben: \n");
      strcat(output,"   Funktion: \n");
      ShowPlayerDialog(playerid, 62, DIALOG_STYLE_MSGBOX , "Prodfahrerkurs",output, "Weiter", "");
    }
    case 43:
    {
      new output[500];
      strcat(output,"Der Beruf Trucker \n");
      strcat(output,"   Aufgaben: \n");
      strcat(output,"   Funktion: \n");
      ShowPlayerDialog(playerid, 62, DIALOG_STYLE_MSGBOX , "Truckerkurs",output, "Weiter", "");
    }
    case 45:
    {
      new output[500];
      strcat(output,"Der Beruf Bauer \n");
      strcat(output,"   Aufgaben: \n");
      strcat(output,"   Funktion: \n");
      ShowPlayerDialog(playerid, 62, DIALOG_STYLE_MSGBOX , "Bauerkurs",output, "Weiter", "");
    }
    case 46:
    {
      new output[500];
      strcat(output,"Der Beruf Waffenhändler \n");
      strcat(output,"   Aufgaben: \n");
      strcat(output,"   Funktion: \n");
      ShowPlayerDialog(playerid, 62, DIALOG_STYLE_MSGBOX , "Waffenhändlerkurs",output, "Weiter", "");
    }
    case 47:
    {
      new output[500];
      strcat(output,"Der Beruf Fischer \n");
      strcat(output,"   Aufgaben: \n");
      strcat(output,"   Funktion: \n");
      ShowPlayerDialog(playerid, 62, DIALOG_STYLE_MSGBOX , "Fischerkurs",output, "Weiter", "");
    }
    case 48:
    {
      new output[500];
      strcat(output,"Der Beruf Drogenhändler \n");
      strcat(output,"   Aufgaben: \n");
      strcat(output,"   Funktion: \n");
      ShowPlayerDialog(playerid, 62, DIALOG_STYLE_MSGBOX , "Drogenhändlerkurs",output, "Weiter", "");
    }
    case 50:
    {
      new output[500];
      strcat(output,"Der Beruf Taxifahrer \n");
      strcat(output,"   Aufgaben: Ist es Spieler von a nach b fahren\n");
      strcat(output,"   Funktion: Ist der schnelle Transport von Spielern die kein Auto oder kein Auto in Reichweite haben\n");
      strcat(output,"\tBeschreibung:\n\t\t Der Taxifahrer ist ein notweniger Beruf um das weite Laufen zwischen Punkten zu unterbinden\n");
      strcat(output,"\t\t Er hat in jeder Stadt ein Depot in LS und SF am Bahnhof und in LV am Flughafen.\n");
      strcat(output,"\t\t Er ist billiger und schneller vor Ort als Das Laufen zu einem Mietwagen. Er kann über das Aktionsmenü(Standart -N-)gerufen werden.\n");
      strcat(output,"\t\t Danach wird für den Taxifahrer in Reichweite eine Markierung in Gelb auf der Karte gesetzt.(Die Position des Spielers.\n");
      strcat(output,"\t\t Es geht nach dem Motto, wer zuerst kommt, mahlt zuerst.\n");
      strcat(output,"\t\t Über das Jobmenü (Standart -2-) kann der Fahrpreis, ein Fahrgast abgelehnt oder der Job beendet werden, um Kaution wieder zu bekommen.\n");
      ShowPlayerDialog(playerid, 62, DIALOG_STYLE_MSGBOX , "Taxifahrerkurs",output, "Weiter", "");
    }
    case 51:
    {
      new output[500];
      strcat(output,"Der Beruf Sanitäter \n");
      strcat(output,"   Aufgaben: \n");
      strcat(output,"   Funktion: \n");
      ShowPlayerDialog(playerid, 62, DIALOG_STYLE_MSGBOX , "Sanitäterkurs",output, "Weiter", "");
    }
    case 52:
    {
      new output[500];
      strcat(output,"Der Beruf Müllfahrer \n");
      strcat(output,"   Aufgaben: \n");
      strcat(output,"   Funktion: \n");
      ShowPlayerDialog(playerid, 62, DIALOG_STYLE_MSGBOX , "Müllfahrerkurs",output, "Weiter", "");
    }
    case 53:
    {
      new output[500];
      strcat(output,"Der Beruf Auftragsmörder \n");
      strcat(output,"   Aufgaben: \n");
      strcat(output,"   Funktion: \n");
      ShowPlayerDialog(playerid, 62, DIALOG_STYLE_MSGBOX , "Auftragsmörderkurs",output, "Weiter", "");
    }
    case 54:
    {
      new output[500];
      strcat(output,"Der Beruf Auftragsmörder \n");
      strcat(output,"   Aufgaben: \n");
      strcat(output,"   Funktion: \n");
      ShowPlayerDialog(playerid, 62, DIALOG_STYLE_MSGBOX , "Touristikkurs",output, "Weiter", "");
    }
  }
}

public berufs_fragen(playerid,anz,input[])
{
  switch(berufs[playerid])
  {
    case 38:
    {
      switch(anz)
	  {
		//Fahrlehrer
		case 1: ShowPlayerDialog(playerid, 63,DIALOG_STYLE_INPUT,"Frage 1:","Was macht der Befehl /dienst ?\n a) Fahrlehrer im Dienst b) Fahrlehrer Ausserdienst c) nichts","Weiter","");
		case 2:
		{
		  if(strcmp(input,"c",true)) berufs_fragen(playerid,1,"");
		  else ShowPlayerDialog(playerid, 64,DIALOG_STYLE_INPUT,"Frage 2:","Wo ist die Fahrschule? LS, SF oder LV","Weiter","");
		}
		case 3:
		{
		  if(strcmp(input,"SF",true)) berufs_fragen(playerid,2,"c");
		  else ShowPlayerDialog(playerid, 65,DIALOG_STYLE_INPUT,"Frage 3:","Weleche Lizenzen darf ein Fahrlehrer ausbilden?\n a) alle b) nur festgelegte c) seine eigenen","Weiter","");
		}
		case 4:
		{
		  if(strcmp(input,"c",true)) berufs_fragen(playerid,3,"SF");
		  else
		  {
			GameTextForPlayer(playerid, "~w~Theorie bestanden. Gratulation!", 3000, 3);
			playerdata[playerid][38] = 1;
            berufs[playerid] = 0;
		  }
		}
	  }
    }
    case 39:
    {
      switch(anz)
	  {
		//Pilot
		case 1: ShowPlayerDialog(playerid, 63,DIALOG_STYLE_INPUT,"Frage 1:","Funktion des Piloten? a) Passagierflüge b) Gütertransport c) Privatflüge","Weiter","");
		case 2:
		{
		  if(strcmp(input,"b",true)) berufs_fragen(playerid,1,"");
		  else ShowPlayerDialog(playerid, 64,DIALOG_STYLE_INPUT,"Frage 2:","Wie viele Erfahrungsstufen gibt es?","Weiter","");
		}
		case 3:
		{
		  if(strcmp(input,"5",true)) berufs_fragen(playerid,2,"b");
		  else ShowPlayerDialog(playerid, 65,DIALOG_STYLE_INPUT,"Frage 3:","Hauptdepot liegt in? LS, SF oder LV","Weiter","");
		}
		case 4:
		{
		  if(strcmp(input,"SF",true)) berufs_fragen(playerid,3,"5");
		  else
		  {
			GameTextForPlayer(playerid, "~w~Theorie bestanden. Gratulation!", 3000, 3);
			playerdata[playerid][39] = 1;
            berufs[playerid] = 0;
		  }
		}
	  }
    }
    case 41:
    {
      switch(anz)
	  {
		//Postbote
		case 1: ShowPlayerDialog(playerid, 63,DIALOG_STYLE_INPUT,"Frage 1:","Welche Farbe hat die Markierung für Gäste? a) Rot b) Blau c) Gelb","Weiter","");
		case 2:
		{
		  if(strcmp(input,"c",true)) berufs_fragen(playerid,1,"");
		  else ShowPlayerDialog(playerid, 64,DIALOG_STYLE_INPUT,"Frage 2:","Wie ist die Standarttaste für Aktionsmenü","Weiter","");
		}
		case 3:
		{
		  if(strcmp(input,"n",true)) berufs_fragen(playerid,2,"c");
		  else ShowPlayerDialog(playerid, 65,DIALOG_STYLE_INPUT,"Frage 3:","","Weiter","");
		}
		case 4:
		{
		  if(strcmp(input,"b",true)) berufs_fragen(playerid,3,"5");
		  else
		  {
			GameTextForPlayer(playerid, "~w~Theorie bestanden. Gratulation!", 3000, 3);
			playerdata[playerid][41] = 1;
            berufs[playerid] = 0;
		  }
		}
	  }
    }
    case 50:
    {
      switch(anz)
	  {
		//Taxifahrer
		case 1: ShowPlayerDialog(playerid, 63,DIALOG_STYLE_INPUT,"Frage 1:","Welche Farbe hat die Markierung der Gäste? a) rot b) gelb c)blau","Weiter","");
		case 2:
		{
		  if(strcmp(input,"b",true)) berufs_fragen(playerid,1,"");
		  else ShowPlayerDialog(playerid, 64,DIALOG_STYLE_INPUT,"Frage 2:","Wie viele Depots gibt es?","Weiter","");
		}
		case 3:
		{
		  if(strcmp(input,"3",true)) berufs_fragen(playerid,2,"b");
		  else ShowPlayerDialog(playerid, 65,DIALOG_STYLE_INPUT,"Frage 3:","Was ist die eigentliche Aufgabe des Taxifahrers? \n a) Sinnlos fahren b) Transport von Paketen c) Transport von Personen","Weiter","");
		}
		case 4:
		{
		  if(strcmp(input,"c",true)) berufs_fragen(playerid,3,"3");
		  else
		  {
			GameTextForPlayer(playerid, "~w~Theorie bestanden. Gratulation!", 3000, 3);
			playerdata[playerid][50] = 1;
            berufs[playerid] = 0;
		  }
		}
	  }
    }
  }
}
