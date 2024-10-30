forward hilfe(playerid, Eingabe[]);
forward hilfe_box(playerid);
forward hilfe_response(playerid, dialogid, response, listitem, inputtext[]);
forward hilfe_jobs(playerid);

public hilfe(playerid, Eingabe[])
{
  new output[1000];
  if(strlen(Eingabe) < 1)
  {
	hilfe_box(playerid);
  }
  else if(!strcmp(Eingabe,"fkurier",true))
	ShowPlayerDialog(playerid, 49, DIALOG_STYLE_MSGBOX, "Fahrradkurier", "Der Fahrradkurier", "Schließen", "");
  else if(!strcmp(Eingabe,"werbung",true))
  {
	strcat(output,"Grundlegend gibt es 3 verschiedene Arten von Werbung:\nkleine Werbung:\n     umfasst ein 35 Zeichen Nachricht, kostet 75$ und wird schnell zugestellt\n\n");
	strcat(output,"mittlere Werbung:\n     umfasst ein 75 Zeichen Nachricht, kostet 125$ und hat eine normale Zustellzeit\n     Expresszustellung: 200$ und eine schnelle Zustellung\n\n");
	strcat(output,"grosse Werbung:\n     umfasst ein 125 Zeichen Nachricht, kostet 300$ und hat eine lange Zustellzeit\n");
	strcat(output,"     Expresszustellug: 350$ und hat eine schnelle Zustellung\n");
	ShowPlayerDialog(playerid, 49,DIALOG_STYLE_MSGBOX , "Werbung", output, "Schließen","Zurück");
  }
  else if(!strcmp(Eingabe,"fahrlehrer",true))
  {
	if(fahrlehrer_on[0] != -1 || fahrlehrer_on[1] != -1 || fahrlehrer_on[2] != -1 || fahrlehrer_on[3] != -1 || fahrlehrer_on[4] != -1)
	{
	  new pname[100];
	  strcat(output,"Fahrlehrer im Dienst:\n\n");
	  for(new i=0;i<5;i++)
	  {
		if(fahrlehrer_on[i] != -1)
		{
		  GetPlayerName(playerid,pname,100);
		  strcat(output,pname);
		  strcat(output,"\nLehrer für folgende Lizenzen:\n ~ ");
		  if(playerdata[fahrlehrer_on[i]][21] == 1) strcat(output,"Motorrad ~ ");
		  if(playerdata[fahrlehrer_on[i]][22] == 1) strcat(output,"PKW ~ ");
		  if(playerdata[fahrlehrer_on[i]][23] == 1) strcat(output,"LKW ~ ");
		  if(playerdata[fahrlehrer_on[i]][24] == 1) strcat(output,"LKW mit Anhänger ~ ");
		  strcat(output,"\n");
		  if(playerdata[fahrlehrer_on[i]][27] == 1) strcat(output,"Kleinflugzeug ~ ");
		  if(playerdata[fahrlehrer_on[i]][28] == 1) strcat(output,"Fracht- und Passagierflugzeuge ~ ");
		  if(playerdata[fahrlehrer_on[i]][29] == 1) strcat(output,"Helicopter ~ ");
          strcat(output,"\n");
          if(playerdata[fahrlehrer_on[i]][25] == 1) strcat(output,"Sportboote ~ ");
		  if(playerdata[fahrlehrer_on[i]][26] == 1) strcat(output,"Fischerboote ~ ");
		  strcat(output,"\n\n");
		}
	  }
	}
	else
	{
	  output = "Zur Zeit sind keine Fahrlehrer in der Fahrschule im Dienst.";
	}
	ShowPlayerDialog(playerid, 49,DIALOG_STYLE_MSGBOX , "Fahrlehrer", output, "Schließen","Zurück");
  }
  else
	hilfe_box(playerid);
}

public hilfe_box(playerid)
{
  ShowPlayerDialog(playerid, 40,DIALOG_STYLE_LIST, "Hilfe:", "Befehle\nJobs\nLizenzen\nGebäude\nWerbung\nFahrlehrer Info", "Öffnen", "Schliessen");
}

public hilfe_response(playerid, dialogid, response, listitem, inputtext[])
{
  if(dialogid == 40 && response)
  {
	switch(listitem)
	{
	  case 0: hilfe(playerid, "befehle");
	  case 1: hilfe_jobs(playerid);
	  case 2: hilfe(playerid, "lizenzen");
	  case 3: hilfe(playerid, "gebäude");
	  case 4: hilfe(playerid, "werbung");
      case 5: hilfe(playerid, "Fahrlehrer");
	}
  }
  if(dialogid == 41)
  {
	if(response)
	{
	  switch(listitem)
	  {
		case 0: hilfe(playerid, "jobs");
		case 1: hilfe(playerid, "fkurier");
		case 2: hilfe(playerid, "lfahrer");
		case 3: hilfe(playerid, "trucker");
        case 4: hilfe(playerid, "taxifahrer");
	  }
	}
	else
	  hilfe_box(playerid);
  }
  if(dialogid == 49 && !response)
  {
	hilfe_box(playerid);
  }
}

public hilfe_jobs(playerid)
{
  ShowPlayerDialog(playerid, 41,DIALOG_STYLE_LIST, "Jobs:", "Allgemein\nFahrradkurier\nLimosinenfahrer\nTrucker\nTaxifahrer", "Öffnen", "Zurück");
}