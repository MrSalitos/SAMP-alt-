forward create_atms();
forward bank_response(playerid, dialogid, response, listitem, inputtext[]);
forward bank_activate(playerid);

new Float:atms[][4] =
// 0 => x; 1 => y; 2 => z; 3 => rZ;
{
  {-1539.96, -438.64, 5.5, 225.0},
  {2134.5, -1151.8, 23.5, 180.0}
};

public create_atms()
{
  for(new i;i < sizeof(atms);i++)
  {
	CreateDynamicObject(2942, atms[i][0], atms[i][1], atms[i][2], 0,0,atms[i][3]);
	CreateDynamicMapIcon(atms[i][0], atms[i][1], atms[i][2], 52, -1,-1, -1, -1, 500);
  }
}

public bank_activate(playerid)
{
  new Float:X,Float:Y,Float:Z;
  GetPlayerPos(playerid,X,Y,Z);
  for(new i = 0;i < sizeof(atms);i++)
  {
	if(IsPlayerInRangeOfPoint(playerid, 3, atms[i][0],  atms[i][1],  atms[i][2]))
	{
	  ShowPlayerDialog(playerid, 70,DIALOG_STYLE_LIST , "Bankautomat", "Kontostand abfragen\nEinzahlen\nAuszahlen\nÜberweisung\n", "Auswählen", "Abbrechen");
	  return 1;
	}
  }
  return 0;
}

public bank_response(playerid, dialogid, response, listitem, inputtext[])
{
  if(dialogid == 70 && response)
  {
	switch(listitem)
	{
	  case 0:
	  {
		new output[100];
		format(output,100,"Ihr Kontostand beträgt:\n     %i $.",playerdata[playerid][5]);
		ShowPlayerDialog(playerid, 71,DIALOG_STYLE_MSGBOX , "Bankautomat - Kontostand abfragen", output, "Schliessen", "Zurück");
	  }
	  case 1: ShowPlayerDialog(playerid, 72,DIALOG_STYLE_INPUT , "Bankautomat - Einzahlen", "Geben Sie den Betrag ein, welchen Sie einzahlen möchten.", "Ausführen", "Zurück");
	  case 2: ShowPlayerDialog(playerid, 73,DIALOG_STYLE_INPUT , "Bankautomat - Auszahlen", "Geben Sie den Betrag ein, welchen Sie sich auszahlen lassen möchten.", "Ausführen", "Zurück");
	  case 3: ShowPlayerDialog(playerid, 74,DIALOG_STYLE_INPUT , "Bankautomat - Überweisung", "Geben Sie den Namen des Spielers und den Betrag ein, welchen Sie überweisen möchten.\n Beispiel(45 10000)", "Weiter", "Zurück");
	}
  }
  if(dialogid == 71 && !response)
	ShowPlayerDialog(playerid, 70,DIALOG_STYLE_LIST , "Bankautomat", "Kontostand abfragen\nEinzahlen\nAuszahlen\nÜberweisung\n", "Auswählen", "Abbrechen");
  if(dialogid == 72)
  {
	if(response)
	{
	  new output[100];
	  if(strval(inputtext) > 0 && giveusermoney(playerid,(strval(inputtext)*-1)))
	  {
		playerdata[playerid][5] = playerdata[playerid][5] + strval(inputtext);
		format(output,100,"Ihrem Konto wurden %i $ gutgeschrieben.",strval(inputtext));
		SendClientMessage(playerid,COLOR_YELLOW,output);
	  }
	  else if(strval(inputtext) <= 0)
	  {
		format(output,100,"Sie können ihrem Konto keinen negativ Betrag gutschreiben.",strval(inputtext));
		SendClientMessage(playerid,COLOR_RED,output);
	  }
	  else
	  {
		format(output,100,"Sie haben nicht soviel Geld.");
		SendClientMessage(playerid,COLOR_RED,output);
	  }
  	}
	else
	  ShowPlayerDialog(playerid, 70,DIALOG_STYLE_LIST , "Bankautomat", "Kontostand abfragen\nEinzahlen\nAuszahlen\nÜberweisung\n", "Auswählen", "Abbrechen");
  }
  if(dialogid == 73)
  {
	if(response)
	{
	  new output[100];
	  if(strval(inputtext) > 0 && strval(inputtext) <= playerdata[playerid][5])
	  {
		playerdata[playerid][5] = playerdata[playerid][5] - strval(inputtext);
		giveusermoney(playerid,strval(inputtext));
		format(output,100,"Sie haben %i $ von ihrem Konto abgehoben.",strval(inputtext));
		SendClientMessage(playerid,COLOR_YELLOW,output);
	  }
	  else if(strval(inputtext) <= 0)
	  {
		format(output,100,"Sie können ihrem con Konto keinen negativ Betrag abheben.");
		SendClientMessage(playerid,COLOR_RED,output);
	  }
	  else
	  {
		format(output,100,"Sie haben nicht soviel Geld auf ihrem Konto.");
		SendClientMessage(playerid,COLOR_RED,output);
	  }
	}
	else
	  ShowPlayerDialog(playerid, 70,DIALOG_STYLE_LIST , "Bankautomat", "Kontostand abfragen\nEinzahlen\nAuszahlen\nÜberweisung\n", "Auswählen", "Abbrechen");
  }
  if(dialogid == 74)
  {
	if(response)
	{
	  new output[100],pname[25];
	  if(IsPlayerConnected(strval(strget(inputtext, 0))) && playerid != strval(strget(inputtext, 0)) && strval(strget(inputtext, 1)) > 0 && playerdata[playerid][5] >= strval(strget(inputtext, 1)))
	  {
		GetPlayerName(strval(strget(inputtext, 0)),pname,25);
		format(output,100,"Dem Spieler %s wurden %i $ gutgeschrieben.",pname,strval(strget(inputtext, 1)));
		SendClientMessage(playerid,COLOR_YELLOW,output);
		GetPlayerName(playerid,pname,25);
		format(output,100,"Sie haben vom Spieler %s , %i $ gutgeschrieben bekommen.",pname,strval(strget(inputtext, 1)));
		SendClientMessage(strval(strget(inputtext, 0)),COLOR_YELLOW,output);
		playerdata[playerid][5] = playerdata[playerid][5] - strval(strget(inputtext, 1));
		playerdata[strval(strget(inputtext, 0))][5] = playerdata[strval(strget(inputtext, 0))][5] + strval(strget(inputtext, 1));
	  }
	  else if(strval(strget(inputtext, 1)) <= 0)
	  {
		format(output,100,"Sie können ihrem con Konto keinen negativ Betrag abheben.");
		SendClientMessage(playerid,COLOR_RED,output);
	  }
	  else if(playerid == strval(strget(inputtext, 0)))
	  {
		format(output,100,"Sie können sich nicht selbst Geld gutschreiben.");
		SendClientMessage(playerid,COLOR_RED,output);
	  }
	  else if(playerdata[playerid][5] < strval(strget(inputtext, 1)))
	  {
		format(output,100,"Sie haben nicht soviel Geld auf ihrem Konto.");
		SendClientMessage(playerid,COLOR_RED,output);
	  }
	  else
		ShowPlayerDialog(playerid, 74,DIALOG_STYLE_INPUT , "Bankautomat - Überweisung", "Geben Sie die ID des Spielers ein, welchen Sie das Geld überweisen möchten.\n {FF0000}Den Spieler gibt es nicht!", "Weiter", "Zurück");
	}
	else
	  ShowPlayerDialog(playerid, 70,DIALOG_STYLE_LIST , "Bankautomat", "Kontostand abfragen\nEinzahlen\nAuszahlen\nÜberweisung\n", "Auswählen", "Abbrechen");
  }
}