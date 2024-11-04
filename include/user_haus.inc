forward userhaus();
forward userhaus_pickup(playerid,pickupid);
forward userhaus_response(playerid, dialogid, response, listitem, inputtext[]);

new Float:wohnungsintor[][11] =
/*
[0] => Interiorid
[1] => Virtualworld
[2] => posX Enterpoint
[3] => posY Enterpoint
[4] => posZ Enterpoint
[5] => posX for leaving
[6] => posY for leaving
[7] => posZ for leaving
[8] => posY sell
[9] => posX sell
[10] => posZ sell
*/
{
  {12.0, 0.0,  444.93,   512.70, 1001.41,  443.29,   508.71, 1001.41,  443.48,   513.94, 1001.41}, //Budget inn motel room  - 0
  {1.0,  0.0,  247.81,   305.23,  999.14,  243.71,   304.88,  999.14,  243.81,   301.89,  999.14}, //Denise room            - 1
  {2.0,  0.0,  271.88,   306.63,  999.15,  266.49,   304.94,  999.14,  273.45,   303.46,  999.15}, //Katie room 		    - 2
  {3.0,  0.0,  292.39,   305.36,  999.14,  293.21,   310.22,  999.14,  290.40,   310.93,  999.14}, //Helena room 	        - 3
  {4.0,  0.0,  299.74,   305.70,  999.14,  302.65,   300.36,  999.14,  305.21,   309.67,  999.14}, //Michelle room 		    - 4
  {5.0,  0.0,  322.61,   306.58,  999.14,  322.00,   302.35,  999.14,  327.25,   305.70,  999.14}, //Barbara room 			- 5
  {6.0,  0.0,  346.32,   308.84,  999.15,  343.71,   305.12,  999.14,  347.75,   301.56,  999.14}, //Millie room 			- 6
  {3.0,  0.0, 2494.96, -1708.88, 1014.74, 2495.97, -1692.14, 1014.74, 2491.80, -1694.64, 1014.74}, //Cj's house 			- 7
  {5.0,  0.0, 1300.51,  -790.95, 1084.00, 1298.65,  -796.58, 1084.00, 1304.39,  -787.45, 1084.00}, //Madd Doggs mansion unt	- 8
  {5.0,  0.0, 1264.50,  -781.38, 1091.90, 1261.37,  -785.04, 1091.90, 1262.11,  -772.71, 1091.90}, //Madd Doggs mansion obe	- 9
  {2.0,  0.0, 2454.72, -1700.87, 1013.52, 2468.07, -1698.08, 1013.50, 2455.82, -1705.81, 1013.50}, //Ryders house 	 		- 10
  {5.0,  0.0, 2347.45, -1180.99, 1027.97, 2352.42, -1180.51, 1027.97, 2348.66, -1187.56, 1027.97}, //Gang house 			- 11
  {8.0,  0.0, 2807.92, -1170.66, 1025.57, 2807.60, -1174.75, 1025.57, 2810.04, -1165.26, 1025.57}, //Colonel Furhberger's 	- 12
  {5.0,  0.0,  318.94,  1117.20, 1083.88,  318.30,  1114.48, 1083.88,  325.63,  1116.60, 1083.88}, //Crack den 			    - 13 
  {12.0, 0.0, 2318.06, -1147.44, 1050.70, 2324.57, -1149.51, 1050.71, 2313.35, -1141.96, 1050.70}  //safe house	            - 14
};

new Float:userhaeuser[][10] =
/*
[0] => PosX entry
[1] => PosY entry
[2] => PosZ entry
[3] => wohnungsintor ID Standart 
[4] => PosX exit
[5] => PosY exit
[6] => PosZ exit
[7] => 1 = kaufen 2 = mieten
[8] => anz user möglich die mieten/kaufen können
[9] => Preis
*/
{
  {1298.66, -799.31, 84.50, 8.0, 1300.38, -804.63, 84.14, 1.0, 1.0, 1200000.0},
  {1247.78,-1560.40, 13.13, 2.0, 1247.71, -1566.61, 13.55,2.0,10.0,150.0},
  {1497.02, -688.00, 95.56,14.0,1496.38, -690.87, 94.75,1.0,1.0,1200000.0},
  {1093.87, -807.14,107.41,14.0,1093.27, -803.87, 107.42,1.0,1.0,1200000.0},
  {1034.32, -812.26,101.85,13.0,1035.32,-811.26,101.85,1.0,1.0,750000.0},
  {1016.95, -762.85,112.56,13.0,1015.95,-761.85,112.56,1.0,1.0,750000.0},
  {1111.82, -741.78,100.13,13.0,1110.82,-740.78,100.13,1.0,1.0,750000.0},
  { 989.34, -828.18,100.13,13.0,988.34,-827.18,100.13,1.0,1.0,750000.0},
  { 937.18, -847.21, 93.81,13.0,936.18,-846.21,93.81,1.0,1.0,750000.0},
  {1249.15, -877.30, 46.64,1.0,1245.82, -875.64, 46.64,2.0,2.0,150.0},
  {1241.30, -872.10, 46.63,1.0,1245.15, -874.04, 46.64,2.0,2.0,150.0},
  {1252.41, -902.05, 46.59,1.0,1249.17, -906.02, 46.60,2.0,2.0,150.0},
  {1247.07, -908.43, 46.60,1.0,1249.17, -906.02, 46.60,2.0,2.0,150.0},
  {1288.37, -874.02, 46.84,1.0,1284.08, -871.25, 46.84,2.0,2.0,150.0},
  {1280.04, -868.63, 46.83,1.0,1284.08, -871.25, 46.84,2.0,2.0,150.0},
  {1283.58, -898.25, 46.62,1.0,1287.30, -900.25, 46.63,2.0,2.0,150.0},
  {1291.82, -902.95, 46.63,1.0,1287.30, -900.25, 46.63,2.0,2.0,150.0}
};

new haeuserpickups[sizeof(userhaeuser)];
new Text3D:haeusertextlabels[sizeof(userhaeuser)];
new haeusericons[sizeof(userhaeuser)];
new leavingpickups[sizeof(wohnungsintor)];
new sellingpickups[sizeof(wohnungsintor)];
new userbuyimmobile[MAX_PLAYERS];

public userhaus()
{
  new query[250],data[50],label[150];
  for(new i = 0;i < sizeof(userhaeuser);i++)
  {
    format(query,250,"SELECT COUNT(*) as anz FROM user_house WHERE houseid = %i",i);
    mysql_query(query);
    mysql_store_result();
    mysql_fetch_field("anz",data);
    ;
    if(strval(data) < floatround(userhaeuser[i][8]))
    {
      haeuserpickups[i] = CreatePickup(1273, 1, userhaeuser[i][0], userhaeuser[i][1], userhaeuser[i][2], -1);
      if(floatround(userhaeuser[i][7]) == 2)
        format(label,150,"WOHNUNGEN zu vermieten \n Frei Wohnungen: %.0f \n Miete: %.0f $ pro Zahltag",userhaeuser[i][8],userhaeuser[i][9]);
      else
        format(label,150,"Immobilie zu verkaufen \n Kaufpreis: %.0f $",userhaeuser[i][9]);
      haeusericons[i] = CreateDynamicMapIcon(userhaeuser[i][0], userhaeuser[i][1], userhaeuser[i][2], 31, -1,-1, -1, -1, 500);
    }
    else
    {
      haeuserpickups[i] = CreatePickup(1272, 1, userhaeuser[i][0], userhaeuser[i][1], userhaeuser[i][2], -1);
      if(floatround(userhaeuser[i][7]) == 2)
        format(label,150,"Haus betreten");
      else
        format(label,150,"Immobilie betreten");
    }
    haeusertextlabels[i] = Create3DTextLabel(label, COLOR_WHITE,  userhaeuser[i][0], userhaeuser[i][1], userhaeuser[i][2]+1.0, 10, 0, false);
    userhaeuser[i][8] = userhaeuser[i][8] - floatstr(data);
  }
  for(new i = 0;i < sizeof(wohnungsintor);i++)
  {
    leavingpickups[i] = CreatePickup(1559,1,wohnungsintor[i][5], wohnungsintor[i][6], wohnungsintor[i][7],-1);
    sellingpickups[i] = CreatePickup(1274,1,wohnungsintor[i][8], wohnungsintor[i][9], wohnungsintor[i][10],-1);
  }
}

public userhaus_pickup(playerid,pickupid)
{
  for(new i = 0;i < sizeof(haeuserpickups);i++)
  {
    if(pickupid == haeuserpickups[i])
    {
      new inter = -1;
      if(playerdata[playerid][58] == i && playerdata[playerid][59] >= 0) inter = playerdata[playerid][59];
      else if(playerdata[playerid][60] == i && playerdata[playerid][61] >= 0) inter = playerdata[playerid][61];
      else if(playerdata[playerid][62] == i && playerdata[playerid][63] >= 0) inter = playerdata[playerid][63];
      else if(playerdata[playerid][64] == i && playerdata[playerid][65] >= 0) inter = playerdata[playerid][65];
      else if(playerdata[playerid][66] == i && playerdata[playerid][67] >= 0) inter = playerdata[playerid][67];

      if(inter >= 0)
      {
        SetPlayerInterior(playerid, floatround(wohnungsintor[inter][0]));
        SetPlayerPos(playerid,wohnungsintor[inter][2], wohnungsintor[inter][3],wohnungsintor[inter][4]);
        wohnungsintor[inter][1] = wohnungsintor[i][1] + 1.0;
        SetPlayerVirtualWorld(playerid,floatround(wohnungsintor[inter][1]));
        playerinhouse[playerid] = i;
      }
      else if(floatround(userhaeuser[i][8]) > 0 && (
               ((playerdata[playerid][58] < 0 || playerdata[playerid][60] < 0 || playerdata[playerid][62] < 0) && floatround(userhaeuser[i][7]) == 2)
                ||
               (playerdata[playerid][56] == 1 && (playerdata[playerid][64] < 0 || playerdata[playerid][66] < 0))
              ))
      {
        SetPlayerPos(playerid,userhaeuser[i][4], userhaeuser[i][5],userhaeuser[i][6]);
        new output[250];
        if(floatround(userhaeuser[i][7]) == 2)
        {
          format(output,250,"Diese Wohnung können sie mieten.\n\n Die Miete wird jeden Monat im vorraus für den nächsten bezahlt. \n\nSie beträgt: %.0f $ \n\n In diesem Haus sind noch %.0f Wohnung frei zum vermieten.",userhaeuser[i][9],userhaeuser[i][8]);
          ShowPlayerDialog(playerid, 95, DIALOG_STYLE_MSGBOX ,"Wohnung mieten", output, "Mieten", "Abbrechen");
          userbuyimmobile[playerid] = i;
          userhaeuser[i][8] = userhaeuser[i][8] - 1.0;
        }
        else
        {
          format(output,250,"Diese Immobilie können sie kaufen.\n\n Der Kaufpreis liegt bei: %.0f $ \n\n Es fallen keine weiteren Kosten an.",userhaeuser[i][9]);
          userbuyimmobile[playerid] = i;
          ShowPlayerDialog(playerid, 95, DIALOG_STYLE_MSGBOX ,"Immobilie kaufen", output, "Kaufen", "Abbrechen");
          userhaeuser[i][8] = userhaeuser[i][8] - 1.0;
        }
      }
      else
      {
        GameTextForPlayer(playerid, "~r~Sie wohnen hier nicht.", 3000, 1);
      }
    }
  }
  for(new i = 0;i < sizeof(wohnungsintor);i++)
  {
    if(pickupid == leavingpickups[i])
    {
      SetPlayerInterior(playerid, 0);
      SetPlayerPos(playerid, userhaeuser[playerinhouse[playerid]][4],userhaeuser[playerinhouse[playerid]][5],userhaeuser[playerinhouse[playerid]][6]);
      wohnungsintor[i][1] = wohnungsintor[i][1] - 1.0;
      SetPlayerVirtualWorld(playerid,0);
      playerinhouse[playerid] = -1;
    }
    if(pickupid == sellingpickups[i])
    {
      new k = 0;
      if(playerinhouse[playerid] == playerdata[playerid][58]) k = 58;
      else if(playerinhouse[playerid] == playerdata[playerid][60]) k = 60;
      else if(playerinhouse[playerid] == playerdata[playerid][62]) k = 62;
      else if(playerinhouse[playerid] == playerdata[playerid][64]) k = 64;
      else if(playerinhouse[playerid] == playerdata[playerid][66]) k = 66;
      
      if(k > 0)
      {
        SetPlayerPos(playerid,wohnungsintor[i][2], wohnungsintor[i][3],wohnungsintor[i][4]);
        new output[150];
        if(userhaeuser[playerinhouse[playerid]][7] == 2)
        {
          format(output,150,"Diese Wohnung können sie kündigen.\n\n Bedenken Sie, einmal bezahlte Miete wird nicht erstattet. \n\n");
          ShowPlayerDialog(playerid, 96, DIALOG_STYLE_MSGBOX ,"Wohnung kündigen", output, "Kündigen", "Abbrechen");
        }
        else
        {
          format(output,150,"Diese Immobilie können sie verkaufen.\n\n Ein Makler würde diese Immobilie für %i$ kaufen.\n\nMöchten Sie verkaufen?",floatround(userhaeuser[playerinhouse[playerid]][9] * 0.75));
          ShowPlayerDialog(playerid, 96, DIALOG_STYLE_MSGBOX ,"Immobilie verkaufen", output, "Verkaufen", "Abbrechen");
        }
      }
    }
  }
}

public userhaus_response(playerid, dialogid, response, listitem, inputtext[])
{
  if(dialogid == 95)
  {
    if(response)
    {
      if(giveusermoney(playerid,(floatround(userhaeuser[userbuyimmobile[playerid]][9]) * -1)))
      {
        new query[150],price,label[150];
        if(floatround(userhaeuser[userbuyimmobile[playerid]][7]) == 2)
        {
          price = floatround(userhaeuser[userbuyimmobile[playerid]][9]);
          GameTextForPlayer(playerid, "~g~Sie haben die Wohnung.", 3000, 3);
        }
        else
        {
          price = 0;
          GameTextForPlayer(playerid, "~g~Sie haben die Immobilie.", 3000, 3);
        }
        format(query,150,"INSERT INTO user_house (houseid,accid,interid,price) VALUES (%i,%i,%i,%i)",userbuyimmobile[playerid],playerdata[playerid][0],floatround(userhaeuser[userbuyimmobile[playerid]][3]),price);
        mysql_query(query);
        playerdata[playerid][68] = playerdata[playerid][68] + price;
        if(userhaeuser[userbuyimmobile[playerid]][8] == 0.0)
        {
          DestroyPickup(haeuserpickups[userbuyimmobile[playerid]]);
          haeuserpickups[userbuyimmobile[playerid]] = CreatePickup(1272, 1, userhaeuser[userbuyimmobile[playerid]][0], userhaeuser[userbuyimmobile[playerid]][1], userhaeuser[userbuyimmobile[playerid]][2], -1);
          DestroyDynamicMapIcon(haeusericons[userbuyimmobile[playerid]]);
          if(floatround(userhaeuser[userbuyimmobile[playerid]][7]) == 2)
            format(label,150,"Haus betreten");
          else
            format(label,150,"Immobilie betreten");
          Update3DTextLabelText(haeusertextlabels[userbuyimmobile[playerid]],COLOR_WHITE,label);
        }
        else if(floatround(userhaeuser[userbuyimmobile[playerid]][7]) == 2 && userhaeuser[userbuyimmobile[playerid]][8] > 0.0)
        {
          format(label,150,"WOHNUNGEN zu vermieten \n Frei Wohnungen: %.0f \n Miete: %.0f $ pro Zahltag",userhaeuser[userbuyimmobile[playerid]][8],userhaeuser[userbuyimmobile[playerid]][9]);
          Update3DTextLabelText(haeusertextlabels[userbuyimmobile[playerid]],COLOR_WHITE,label);
        }
        if(playerdata[playerid][58] == -1){playerdata[playerid][58] = userbuyimmobile[playerid]; playerdata[playerid][59] = floatround(userhaeuser[userbuyimmobile[playerid]][3]);}
        else if(playerdata[playerid][60] == -1){playerdata[playerid][60] = userbuyimmobile[playerid]; playerdata[playerid][61] = floatround(userhaeuser[userbuyimmobile[playerid]][3]);}
        else if(playerdata[playerid][62] == -1){playerdata[playerid][62] = userbuyimmobile[playerid]; playerdata[playerid][63] = floatround(userhaeuser[userbuyimmobile[playerid]][3]);}
        else if(playerdata[playerid][64] == -1){playerdata[playerid][64] = userbuyimmobile[playerid]; playerdata[playerid][65] = floatround(userhaeuser[userbuyimmobile[playerid]][3]);}
        else if(playerdata[playerid][66] == -1){playerdata[playerid][66] = userbuyimmobile[playerid]; playerdata[playerid][67] = floatround(userhaeuser[userbuyimmobile[playerid]][3]);}
        userbuyimmobile[playerid] = -1;
      }
      else
      {
        userhaeuser[userbuyimmobile[playerid]][8] = userhaeuser[userbuyimmobile[playerid]][8] + 1.0;
        userbuyimmobile[playerid] = -1;
        GameTextForPlayer(playerid, "~r~Sie haben nicht genug Geld dabei,~n~ um zu bezahlen.", 3000, 3);
      }
    }
    else
    {
      userhaeuser[userbuyimmobile[playerid]][8] = userhaeuser[userbuyimmobile[playerid]][8] + 1.0;
      userbuyimmobile[playerid] = -1;
    }
  }
  if(dialogid == 96 && response)
  {
    new k = 0,label[150],price;
    if(playerinhouse[playerid] == playerdata[playerid][58]) k = 58;
    else if(playerinhouse[playerid] == playerdata[playerid][60]) k = 60;
    else if(playerinhouse[playerid] == playerdata[playerid][62]) k = 62;
    else if(playerinhouse[playerid] == playerdata[playerid][64]) k = 64;
    else if(playerinhouse[playerid] == playerdata[playerid][66]) k = 66;
    
    if(k > 0)
    {
      if(userhaeuser[playerinhouse[playerid]][7] == 1)
      {
        giveusermoney(playerid,floatround(userhaeuser[playerinhouse[playerid]][9] * 0.75));
        GameTextForPlayer(playerid, "~g~Sie haben die Immobilie verkauft.", 3000, 3);
      }
      else
        GameTextForPlayer(playerid, "~g~Sie haben die Wohnung abgeben.", 3000, 3);
      price = floatround(userhaeuser[playerinhouse[playerid]][9]);
      playerdata[playerid][68] = playerdata[playerid][68] - price;
      if(floatround(userhaeuser[playerinhouse[playerid]][8]) == 0)
      {
        DestroyPickup(haeuserpickups[playerinhouse[playerid]]);
        haeuserpickups[playerinhouse[playerid]] = CreatePickup(1273, 1, userhaeuser[playerinhouse[playerid]][0], userhaeuser[playerinhouse[playerid]][1], userhaeuser[playerinhouse[playerid]][2], -1);
        haeusericons[playerinhouse[playerid]] = CreateDynamicMapIcon(userhaeuser[playerinhouse[playerid]][0], userhaeuser[playerinhouse[playerid]][1], userhaeuser[playerinhouse[playerid]][2], 31, -1,-1, -1, -1, 500);
      }
      userhaeuser[playerinhouse[playerid]][8] = userhaeuser[playerinhouse[playerid]][8] + 1.0;
      if(floatround(userhaeuser[playerinhouse[playerid]][7]) == 2)
        format(label,150,"WOHNUNGEN zu vermieten \n Frei Wohnungen: %.0f \n Miete: %.0f $ pro Zahltag",userhaeuser[playerinhouse[playerid]][8],userhaeuser[playerinhouse[playerid]][9]);
      else
        format(label,150,"Immobilie zu verkaufen \n Kaufpreis: %.0f $",userhaeuser[playerinhouse[playerid]][9]);
      Update3DTextLabelText(haeusertextlabels[playerinhouse[playerid]],COLOR_WHITE,label);
      playerdata[playerid][k] = playerdata[playerid][(k+1)] = -1;
      new output[150];
      format(output,150,"DELETE FROM `user_house` WHERE houseid=%i AND accid=%i",playerinhouse[playerid],playerdata[playerid][0]);
      mysql_query(output);
    }
  }
}