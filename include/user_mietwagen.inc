
forward MietwagenErstellen();
forward MietwagenStateChange(playerid, oldstate, newstate);
forward MietwagenDialog(playerid);
forward MietwagenDialogResponse(playerid, dialogid, response, listitem, inputtext[]);

public MietwagenErstellen()
{
	for(new i = 0; i < sizeof(mietwagen); i++)
	{	
		mietwagen[i][0] = CreateVehicleEx(floatround(mietwagen[i][1]), mietwagen[i][2], mietwagen[i][3], mietwagen[i][4], mietwagen[i][5], floatround(mietwagen[i][6]), floatround(mietwagen[i][7]), -1, 0, 0, "Mietwagen");
	}
}

public MietwagenStateChange(playerid, oldstate, newstate)
{
	if(PLAYER_STATE:newstate == PLAYER_STATE_DRIVER)
	{
		for(new i = 0; i <= sizeof(mietwagen); i++)
		{
			if(GetPlayerVehicleID(playerid) == mietwagen[i][0])
			{
				if(mietwagen[i][8] == 0)
				{
					MietwagenDialog(playerid);
				}
				if(mietwagen[i][8] == playerid)
				{
					new output[128];
					format(output, sizeof(output), "*** Die Restliche Mietdauer beträgt %i Minuten ***", floatround(mietwagen[i][10]));
					SendClientMessage(playerid, COLOR_YELLOW, output);
				}
			}
		}
	}
}


public MietwagenDialog(playerid)
{
	ShowPlayerDialog(playerid, 2300, DIALOG_STYLE_MSGBOX, "Autovermietung", "Hier können Sie für 20 Minuten ein\nAuto mieten. Die kosten hierfür betragen 15$\npro Minute", "Mieten", "Abbrechen");
}

public MietwagenDialogResponse(playerid, dialogid, response, listitem, inputtext[])
{
	if(dialogid == 2300)
	{
		if(response)
		{
			for(new i;i < sizeof(mietwagen);i++)
			{
				if(mietwagen[i][0] == GetPlayerVehicleID(playerid))
				{
					if(giveusermoney(playerid, -1 * floatround(mietwagen[i][9])))
					{
						mietwagen[i][8] = playerdata[playerid][0];
						mietwagen[i][10] = 20;
						giveusermoney(playerid, -1 * (floatround(mietwagen[i][9]) * 20 + 500));
						mietwagen_alive[i][0] = true;
					}
					else
					{
						RemovePlayerFromVehicle(playerid);
						GameTextForPlayer(playerid,"~r~Sie haben nicht genug Geld.",3000,3);
					}
				}
			}
		}
		else
      RemovePlayerFromVehicle(playerid);
	 }
}