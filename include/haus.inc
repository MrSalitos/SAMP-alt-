#include <haus_rathaus>
#include <user_tacho>
#include <haus_tankstellen>
#include <haus_freiewirtschaft>
#include <haus_post>
#include <haus_berufsschule>
#include <user_bank>
#include <haus_rollerf>
#include <haus_autohaus>
#include <user_haus>
#include <user_mietwagen>

forward erstellehaeuser();
forward opengate(id);
forward closegate(id);
forward toropener(playerid);
forward creategates();
forward settime();
forward uhrstellen();
forward timerall30min();

//TORIDS
new flugtor1,flugtor2,flugtor3,flugtor4,truckdepottor1,truckdepottor2,postdepottor1,policesfpdtor4;
new policelspdtor1,policelspdtor2,policesfpdtor1,policesfpdtor2,policesfpdtor3,policelvpdtor1,policelvpdtor2,policelvpdtor3;
//TIMER
new timerflugtor,timerflugtor2,timerflugtor3,timertruckdepottor1,timerpostdepottor1,timerpolicelspdtor1,vipgateplesure1,vipgateplesure2;
new timerpolicelspdtor2,timerpolicesfpdtor1,timerpolicesfpdtor2,timerpolicesfpdtor3,timerpolicelvpdtor1,timerpolicelvpdtor2,timerpolicelvpdtor3,timervipgateplesure;
new Float:Blitzer[10][5] = 
{
	{ 270.58, 54.18, 2.08, 75.0, 0.0 },
	{ 270.58, 54.18, 2.08, 75.0, 0.0 },
	{ 270.58, 54.18, 2.08, 75.0, 0.0 },
	{ 270.58, 54.18, 2.08, 75.0, 0.0 },
	{ 270.58, 54.18, 2.08, 75.0, 0.0 },
	{ 270.58, 54.18, 2.08, 75.0, 0.0 },
	{ 270.58, 54.18, 2.08, 75.0, 0.0 },
	{ 270.58, 54.18, 2.08, 75.0, 0.0 },
	{ 270.58, 54.18, 2.08, 75.0, 0.0 },
	{ 270.58, 54.18, 2.08, 75.0, 0.0 }
};
new Strafkatalog[7] =
{
	0,
	-15,
	-50,
	-75,
	-120,
	-150,
	-250
};
new Text:zeitanzeigen;

public erstellehaeuser()
{
  zeitanzeigen = TextDrawCreate(550.0, 30.0, "00:00");
  TextDrawLetterSize(zeitanzeigen, 0.8, 1.0);
  uhrstellen();
  
  zahltag = TextDrawCreate(490.0, 430.0, "Zahltag:");
  TextDrawFont(zahltag,TEXT_DRAW_FONT:2);
  TextDrawColour(zahltag, 0xFFFFFFFF);
  TextDrawSetShadow(zahltag,0);
  TextDrawLetterSize(zahltag, 0.3, 1.3);
  
  userlevel = TextDrawCreate(477.0, 418.0, "Userlevel:");
  TextDrawFont(userlevel,TEXT_DRAW_FONT:2);
  TextDrawColour(userlevel, 0xFFFFFFFF);
  TextDrawSetShadow(userlevel,0);
  TextDrawLetterSize(userlevel, 0.3, 1.3);
  
  berufserf = TextDrawCreate(477.0, 406.0, "Berufserf:");
  TextDrawFont(berufserf,TEXT_DRAW_FONT:2);
  TextDrawColour(berufserf, 0xFFFFFFFF);
  TextDrawSetShadow(berufserf,0);
  TextDrawLetterSize(berufserf, 0.3, 1.3);
  
  for(new i = 0;i < MAX_PLAYERS; i++)
  {
    paydaydraw1[i] = TextDrawCreate(560.0, 430.0, "I");
    TextDrawColour(paydaydraw1[i], 0xFF0000FF);
    TextDrawSetShadow(paydaydraw1[i],0);
    TextDrawLetterSize(paydaydraw1[i], 0.3, 1.3);
    
    paydaydraw2[i] = TextDrawCreate(560.0, 430.0, " IIIIIIIIIIIIIIIIII");
    TextDrawColour(paydaydraw2[i], 0x000000FF);
    TextDrawSetShadow(paydaydraw2[i],0);
    TextDrawLetterSize(paydaydraw2[i], 0.3, 1.3);
    
    userleveldraw1[i] = TextDrawCreate(560.0, 418.0, "I");
    TextDrawColour(userleveldraw1[i], 0xFF0000FF);
    TextDrawSetShadow(userleveldraw1[i],0);
    TextDrawLetterSize(userleveldraw1[i], 0.3, 1.3);
    
    userleveldraw2[i] = TextDrawCreate(560.0, 418.0, " IIIIIIIIIIIIIIIIII");
    TextDrawColour(userleveldraw2[i], 0x000000FF);
    TextDrawSetShadow(userleveldraw2[i],0);
    TextDrawLetterSize(userleveldraw2[i], 0.3, 1.3);
    
    berufserf1[i] = TextDrawCreate(560.0, 406.0, "I");
    TextDrawColour(berufserf1[i], 0xFF0000FF);
    TextDrawSetShadow(berufserf1[i],0);
    TextDrawLetterSize(berufserf1[i], 0.3, 1.3);
    
    berufserf2[i] = TextDrawCreate(560.0, 406.0, " IIIIIIIIIIIIIIIIII");
    TextDrawColour(berufserf2[i], 0x000000FF);
    TextDrawSetShadow(berufserf2[i],0);
    TextDrawLetterSize(berufserf2[i], 0.3, 1.3);
    
    Typ[i]= TextDrawCreate(25.0, 280.0, "Typ:");
 	TextDrawUseBox(Typ[i], true);
    TextDrawTextSize(Typ[i], 150, 280);
    TextDrawLetterSize(Typ[i],0.4,0.9);
    TextDrawSetShadow(Typ[i],0);
    TextDrawFont(Typ[i],TEXT_DRAW_FONT:1);
    TextDrawBoxColour(Typ[i],0x00000055);
    
	Gesch[i]= TextDrawCreate(25.0, 294.0, "Geschw:");
	TextDrawUseBox(Gesch[i], true);
	TextDrawTextSize(Gesch[i], 150, 280);
    TextDrawLetterSize(Gesch[i],0.4,0.9);
    TextDrawSetShadow(Gesch[i],0);
    TextDrawFont(Gesch[i],TEXT_DRAW_FONT:1);
    TextDrawBoxColour(Gesch[i],0x00000055);
    
	Tank[i]= TextDrawCreate(25.0, 308.0, "Tank: ~g~100%");
	TextDrawUseBox(Tank[i], true);
	TextDrawTextSize(Tank[i], 150, 280);
    TextDrawLetterSize(Tank[i],0.4,0.9);
    TextDrawSetShadow(Tank[i],0);
    TextDrawFont(Tank[i],TEXT_DRAW_FONT:1);
    TextDrawBoxColour(Tank[i],0x00000055);
    
	Schaden[i]= TextDrawCreate(25.0, 322.0, "Schaden: ~g~0%");
	TextDrawUseBox(Schaden[i], true);
	TextDrawTextSize(Schaden[i], 150, 280);
    TextDrawLetterSize(Schaden[i],0.4,0.9);
    TextDrawSetShadow(Schaden[i],0);
    TextDrawFont(Schaden[i],TEXT_DRAW_FONT:1);
    TextDrawBoxColour(Schaden[i],0x00000055);
    
    KM[i]= TextDrawCreate(25.0, 265.5, "0 km");
	TextDrawUseBox(KM[i], true);
	TextDrawTextSize(KM[i], 150, 280);
    TextDrawLetterSize(KM[i],0.4,0.9);
    TextDrawSetShadow(KM[i],0);
    TextDrawFont(KM[i],TEXT_DRAW_FONT:1);
    TextDrawBoxColour(KM[i],0x00000055);
  }
  
  rathaus();
  print("Lade Rathaus");
  GetCurrentGasStationInfo();
  print("Lade Tankstellen");
  CreateTankstellenMapIcons();
  print("Lade MapIcons");
  burgershot();
  print("Lade Burgershots");
  post();
  print("Lade Post");
  creategates();
  print("Lade Tore");
  berufsschule();
  print("Lade Berufsschule");
  create_atms();
  print("Lade ATMs");
  roller();
  print("Lade Rollerfahrschule");
  autohaus();
  print("Lade Autohaeuser");
  userhaus();
  print("Lade User-Haeuser / Wohnungen");
  MietwagenErstellen();
  print("Lade Mietwagen");
  
}
public creategates()
{
  //EINAGNGSTOR SFAIRPORT
  flugtor1 = CreateDynamicObject(985, -1548.5,  -428.0,  6.5, 0, 0, 135);
  flugtor2 = CreateDynamicObject(985, -1542.9,  -433.55,  6.5, 0, 0, 315);
  flugtor3 = CreateDynamicObject(980, -1266.0,  98.52,  7.5, 0, 0, 45);
  flugtor4 = CreateDynamicObject(980, -1257.5,  106.5,  7.5, 0, 0, 45);
  
  //PARKHAUSTOR SFAIRPORT
  CreateDynamicObject(3049, -76.2,  -348.2,  2.8, 0, 0, 270);
  truckdepottor1 = CreateDynamicObject(3049, -76.4,  -352.7,  2.8, 0, 0, 270);
  truckdepottor2 = CreateDynamicObject(3049, -76.4,  -357.2,  2.8, 0, 0, 270);
  CreateDynamicObject(3049, -76.2,  -361.6,  2.8, 0, 0, 270);
  
  //POSTDEPOT
  CreateDynamicObject(966, 1496.62,  989.46,  10, 0, 0, 270);
  postdepottor1 = CreateDynamicObject(968, 1496.62,  989.46,  11, 0, 90,90);
  
  //LSPD
  policelspdtor1 = CreateDynamicObject(2920,  1544.7,  -1630.97,  13.2, 90, 90,90);
  CreateDynamicObject(1422, 1545,  -1620,  13, 0, 0,90);
  policelspdtor2 = CreateDynamicObject(3037,1589.5,  -1638,  14.5, 0, 0,90);
  CreateDynamicObject(2959, 1582.6,  -1637.99,  12.5, 0, 0,270); // tür
  
  //SFPD
  CreateDynamicObject(2959, -1621.7,  688.26,  6.5, 0, 0,270); // tür
  CreateDynamicObject(2959, -1619.3,  688.26,  6.5, 0, 0,90); // tür
  
  policesfpdtor1 = CreateDynamicObject(2920,  -1572.2,  658.71,  7, 90, 90,90);
  policesfpdtor2 = CreateDynamicObject(3037,-1637.1,  688.07,  8.7, 0, 0,90);
  policesfpdtor3 = CreateDynamicObject(3037,-1626.85,  688.07,  8.7, 0, 0,90);
  policesfpdtor4 = CreateDynamicObject(2920, -1701.43,  687.8,  24.7, 90, 0,0);
  
  //LVPD
  policelvpdtor1 = CreateDynamicObject(2920, 2238.2, 2450.2,  10.7, 90, 90,90);
  policelvpdtor2 = CreateDynamicObject(3037, 2293.94, 2497.65,  5, 0, 0,0);
  policelvpdtor3 = CreateDynamicObject(3037, 2335.56,  2444.72,  7.55, 0, 0,330);
  
  //VIP Gates
  vipgateplesure1 = CreateDynamicObject(1557, -2677.5, 1423.9, 905.46, 0, 0,225);
  vipgateplesure2 = CreateDynamicObject(1557, -2679.65, 1421.75, 905.46, 0, 0,45);
  
  //Leitplanken SFAIRPORT
  
  
}
public opengate(id)
{
  switch(id)
  {
	case 1:
	{
	  MoveDynamicObject(flugtor1, -1552.2,-424.35, 6.5, 2.00);
	  MoveDynamicObject(flugtor2, -1539.2,-437.2, 6.5, 2.00);
	}
	case 2:
	  MoveDynamicObject(flugtor3, -1275, 90.5, 7.5, 2.00);
	case 3:
	  MoveDynamicObject(flugtor4, -1248.5, 112.5, 7.5, 2.00);
	case 4:
	{
	  MoveDynamicObject(truckdepottor1,-76.4,  -348.2,  2.8, 2.00,0,0,270);
	  MoveDynamicObject(truckdepottor2, -76.4,  -361.6,  2.8, 2.00,0,0,270);
	}
	case 5:
	  MoveDynamicObject(postdepottor1,1496.62,  989.46,  11, 5.00,0,0,90);
	case 6:
	  MoveDynamicObject(policelspdtor1,1544.7,  -1630.97,  13.2,5.00, 0, 0,0);
	case 7:
	  MoveDynamicObject(policelspdtor2,1589.5,  -1638,  19,2.00, 0, 0,90);
	case 8:
	{
	  MoveDynamicObject(policesfpdtor2, -1637.1,  688.07,  12.7, 2.00,0,0,90);
	  MoveDynamicObject(policesfpdtor3, -1626.85,  688.07,  12.7, 2.00,0,0,90);
	}
	case 9:
	  MoveDynamicObject(policesfpdtor1,-1572.2,  658.71,  7,5.00, 0, 0,0);
	case 10:
	  MoveDynamicObject(policelvpdtor2,2293.94, 2497.6,  9,2.00, 0, 0,0);
	case 11:
	  MoveDynamicObject(policelvpdtor1,2238.2, 2450.2,  10.7,5.00, 0, 0,0);
	case 12:
	  MoveDynamicObject(policelvpdtor3,2335.56,  2444.72,  12,2.00, 0, 0,330);
	case 13:
	  MoveDynamicObject(policesfpdtor4,-1701.43,  687.8,  24.7,5.00, 0, 0,0);
	case 14:
	{
	  MoveDynamicObject(vipgateplesure1,-2676.5, 1424.9, 905.46,1.00,0, 0,225);
	  MoveDynamicObject(vipgateplesure2,-2680.5, 1420.9, 905.46,1.00,0, 0,45);
	}
  }
}
public closegate(id)
{
  switch(id)
  {
	case 1:
	{
	  MoveDynamicObject(flugtor1, -1548.5,  -428.0,  6.5, 2.00);
	  MoveDynamicObject(flugtor2, -1542.9,  -433.55,  6.5, 2.00);
	}
	case 2:
	  MoveDynamicObject(flugtor3,-1266.0,  98.52,  7.5, 2.00);
	case 3:
	  MoveDynamicObject(flugtor4,-1257.5,  106.5,  7.5, 2.00);
	case 4:
	{
	  MoveDynamicObject(truckdepottor1, -76.4,  -352.7,  2.8, 2.00,0,0,270);
	  MoveDynamicObject(truckdepottor2, -76.4,  -357.2,  2.8, 2.00,0,0,270);
	}
	case 5:
	  MoveDynamicObject(postdepottor1, 1496.62,  989.46,  11, 5.00,0,90,90);
	case 6:
	  MoveDynamicObject(policelspdtor1,1544.7,  -1630.97,  13.2,5.00, 90, 90,90);
	case 7:
	  MoveDynamicObject(policelspdtor2,1589.5,  -1638,  14.5,2.00, 0, 0,90);
	case 8:
	{
	  MoveDynamicObject(policesfpdtor2, -1637.1,  688.07, 8.7, 2.00,0,0,90);
	  MoveDynamicObject(policesfpdtor3, -1626.85,  688.07,  8.7, 2.00,0,0,90);
	}
	case 9:
	  MoveDynamicObject(policesfpdtor1,-1572.2,  658.71,  7,5.00, 90, 90,90);
	case 10:
	  MoveDynamicObject(policelvpdtor2,2293.94, 2497.6,  4.9,2.00, 0, 0,0);
	case 11:
	  MoveDynamicObject(policelvpdtor1,2238.2, 2450.2,  10.7,5.00, 90, 90,90);
	case 12:
	  MoveDynamicObject(policelvpdtor3,2335.56,  2444.72,  7.55,2.00, 0, 0,330);
	case 13:
	  MoveDynamicObject(policesfpdtor4,-1701.43,  687.8,  24.7,5.00,90, 0,0);
	case 14:
	{
	  MoveDynamicObject(vipgateplesure1,-2677.5, 1423.9, 905.46,1.00,0, 0,225);
	  MoveDynamicObject(vipgateplesure2,-2679.65, 1421.75, 905.46,1.00,0, 0,45);
	}
  }
}
public toropener(playerid)
{
  new Float:X,Float:Y,Float:Z;
  GetPlayerPos(playerid,X,Y,Z);
  if(playerdata[playerid][2] == 3 || playerdata[playerid][2] == 5 || playerdata[playerid][33] == 3)
  {
	if(IsPlayerInRangeOfPoint(playerid, 9, -1545.17,  -430.54,  5.97))
	{
	  KillTimer(timerflugtor);
	  opengate(1);
	  timerflugtor = SetTimerEx("closegate",1000,false,"i",1);
	}
  }
  if(playerdata[playerid][2] == 1 || playerdata[playerid][33] == 3)
  {
	if(IsPlayerInRangeOfPoint(playerid, 8.5, -1266.21,  98.86,  5.09))
	{
	  KillTimer(timerflugtor2);
	  opengate(2);
	  timerflugtor2 = SetTimerEx("closegate",1000,false,"i",2);
	}
	if(IsPlayerInRangeOfPoint(playerid, 8.5, -1250.57,  100.42,  6.61))
	{
	  KillTimer(timerflugtor3);
	  opengate(3);
	  timerflugtor3 = SetTimerEx("closegate",1000,false,"i",3);
	}
	if(IsPlayerInRangeOfPoint(playerid, 15, -76.36,  -353.71,  1.42))
	{
	  KillTimer(timertruckdepottor1);
	  opengate(4);
	  timertruckdepottor1 = SetTimerEx("closegate",1000,false,"i",4);
	}
  }
  if(playerdata[playerid][2] == 2 || playerdata[playerid][33] == 3)
  {
	if(IsPlayerInRangeOfPoint(playerid, 7.5,  1496,  993,  10))
	{
	  KillTimer(timerpostdepottor1);
	  opengate(5);
	  timerpostdepottor1 = SetTimerEx("closegate",1000,false,"i",5);
	}
  }
  if(playerdata[playerid][2] == 4 || playerdata[playerid][33] == 3)
  {
	if(IsPlayerInRangeOfPoint(playerid, 9.5,  1543.64,  -1627.39,  13.38))
	{
	  KillTimer(timerpolicelspdtor1);
	  opengate(6);
	  timerpolicelspdtor1 = SetTimerEx("closegate",1000,false,"i",6);
	}
	if(IsPlayerInRangeOfPoint(playerid, 9.5, 1588.5,  -1637.78,  14.5))
	{
	  KillTimer(timerpolicelspdtor2);
	  opengate(7);
	  timerpolicelspdtor2 = SetTimerEx("closegate",1000,false,"i",7);
	}
	if(IsPlayerInRangeOfPoint(playerid, 13, -1633,  688.07,  8.7))
	{
	  KillTimer(timerpolicesfpdtor2);
	  opengate(8);
	  timerpolicesfpdtor2 = SetTimerEx("closegate",1000,false,"i",8);
	}
	if(IsPlayerInRangeOfPoint(playerid, 9.5, -1572,  660,  7))
	{
	  KillTimer(timerpolicesfpdtor1);
	  opengate(9);
	  timerpolicesfpdtor1 = SetTimerEx("closegate",1000,false,"i",9);
	}
	if(IsPlayerInRangeOfPoint(playerid, 9.5, 2293.94, 2497.5,  4.8))
	{
	  KillTimer(timerpolicelvpdtor2);
	  opengate(10);
	  timerpolicelvpdtor2 = SetTimerEx("closegate",1000,false,"i",10);
	}
	if(IsPlayerInRangeOfPoint(playerid, 9.5, 2238.2, 2450.2,  10.7))
	{
	  KillTimer(timerpolicelvpdtor1);
	  opengate(11);
	  timerpolicelvpdtor1 = SetTimerEx("closegate",1000,false,"i",11);
	}
	if(IsPlayerInRangeOfPoint(playerid, 8.5, 2335.56,  2444.72,  7.55))
	{
	  KillTimer(timerpolicelvpdtor3);
	  opengate(12);
	  timerpolicelvpdtor3 = SetTimerEx("closegate",1000,false,"i",12);
	}
	if(IsPlayerInRangeOfPoint(playerid, 8.5, -1701.43,  687.8,  24.7))
	{
	  KillTimer(timerpolicesfpdtor3);
	  opengate(13);
	  timerpolicesfpdtor3 = SetTimerEx("closegate",1000,false,"i",13);
	}
  }
  if(playerdata[playerid][33] > 0)
  {
	if(IsPlayerInRangeOfPoint(playerid, 3.0,-2678.5, 1422.5, 905.46))
	{
	  KillTimer(timervipgateplesure);
	  opengate(14);
	  timervipgateplesure = SetTimerEx("closegate",1000,false,"i",14);
	}
  }
  if(GetPlayerVehicleID(playerid))
	{
		for(new i = 0; i < 10; i++)
		{			
			new Float:Velocity[3], output[128];
			if(IsPlayerInRangeOfPoint(playerid, 8, Blitzer[i][0],  Blitzer[i][1],  Blitzer[i][2]))
			{
				GetVehicleVelocity(GetPlayerVehicleID(playerid), Velocity[0], Velocity[1], Velocity[2]);
				new geschw = floatround(floatsqroot(Velocity[0]*Velocity[0]+Velocity[1]*Velocity[1]+Velocity[2]*Velocity[2])*100*1.5,floatround_ceil);
				new ZuSchnell = floatround(geschw - Blitzer[i][3]);
				if(geschw > Blitzer[i][3])
				{
					if(ZuSchnell <= 5)
					{
						if(Blitzer[i][4] == 1)
							format(output, sizeof(output), "***Blitzer: Sie sind innerorts %i Km/h zu schnell gefahren. ***", ZuSchnell);
						if(Blitzer[i][4] == 2)
							format(output, sizeof(output), "***Blitzer: Sie sind außerorts %i Km/h zu schnell gefahren. ***", ZuSchnell);
						SendClientMessage(playerid, COLOR_YELLOW, output);
						format(output, sizeof(output), "*** Verwarnung: Achten Sie auf Ihre Geschwindigkeit ***");
						SendClientMessage(playerid, COLOR_YELLOW, output);
					}
					if(ZuSchnell > 5 && ZuSchnell <= 10)
					{
						if(Blitzer[i][4] == 1)
							format(output, sizeof(output), "***Blitzer: Sie sind innerorts %i Km/h zu schnell gefahren. ***", ZuSchnell);
						if(Blitzer[i][4] == 2)
							format(output, sizeof(output), "***Blitzer: Sie sind außerorts %i Km/h zu schnell gefahren. ***", ZuSchnell);
						SendClientMessage(playerid, COLOR_YELLOW, output);
						format(output, sizeof(output), "*** Strafe: Ihnen wurden %i $ abgezogen ***", Strafkatalog[1]);
						SendClientMessage(playerid, COLOR_YELLOW, output);
						playerdata[playerid][4] = playerdata[playerid][4] + Strafkatalog[1];
						GivePlayerMoney(playerid, Strafkatalog[1]);
					}
					if(ZuSchnell > 10 && ZuSchnell <= 20)
					{
						if(Blitzer[i][4] == 1)
							format(output, sizeof(output), "***Blitzer: Sie sind innerorts %i Km/h zu schnell gefahren. ***", ZuSchnell);
						if(Blitzer[i][4] == 2)
							format(output, sizeof(output), "***Blitzer: Sie sind außerorts %i Km/h zu schnell gefahren. ***", ZuSchnell);
						SendClientMessage(playerid, COLOR_YELLOW, output);
						format(output, sizeof(output), "*** Strafe: Ihnen wurden %i $ abgezogen ***", Strafkatalog[2]);
						SendClientMessage(playerid, COLOR_YELLOW, output);
						playerdata[playerid][4] = playerdata[playerid][4] + Strafkatalog[2];
						GivePlayerMoney(playerid, Strafkatalog[2]);
					}
					if(ZuSchnell > 20 && ZuSchnell <= 25)
					{
						if(Blitzer[i][4] == 1)
							format(output, sizeof(output), "***Blitzer: Sie sind innerorts %i Km/h zu schnell gefahren. ***", ZuSchnell);
						if(Blitzer[i][4] == 2)
							format(output, sizeof(output), "***Blitzer: Sie sind außerorts %i Km/h zu schnell gefahren. ***", ZuSchnell);
						SendClientMessage(playerid, COLOR_YELLOW, output);
						format(output, sizeof(output), "*** Strafe: Ihnen wurden %i $ abgezogen ***", Strafkatalog[3]);
						SendClientMessage(playerid, COLOR_YELLOW, output);
						playerdata[playerid][4] = playerdata[playerid][4] + Strafkatalog[3];
						GivePlayerMoney(playerid, Strafkatalog[3]);
					}
					if(ZuSchnell > 25 && ZuSchnell <= 30)
					{
						if(Blitzer[i][4] == 1)
							format(output, sizeof(output), "***Blitzer: Sie sind innerorts %i Km/h zu schnell gefahren. ***", ZuSchnell);
						if(Blitzer[i][4] == 2)
							format(output, sizeof(output), "***Blitzer: Sie sind außerorts %i Km/h zu schnell gefahren. ***", ZuSchnell);
						SendClientMessage(playerid, COLOR_YELLOW, output);
						format(output, sizeof(output), "*** Strafe: Ihnen wurden %i $ abgezogen ***", Strafkatalog[4]);
						SendClientMessage(playerid, COLOR_YELLOW, output);
						playerdata[playerid][4] = playerdata[playerid][4] + Strafkatalog[4];
						GivePlayerMoney(playerid, Strafkatalog[4]);
					}
					if(ZuSchnell > 30 && ZuSchnell <= 35)
					{
						if(Blitzer[i][4] == 1)
							format(output, sizeof(output), "***Blitzer: Sie sind innerorts %i Km/h zu schnell gefahren. ***", ZuSchnell);
						if(Blitzer[i][4] == 2)
							format(output, sizeof(output), "***Blitzer: Sie sind außerorts %i Km/h zu schnell gefahren. ***", ZuSchnell);
						SendClientMessage(playerid, COLOR_YELLOW, output);
						format(output, sizeof(output), "*** Strafe: Ihnen wurden %i $ abgezogen ***", Strafkatalog[5]);
						SendClientMessage(playerid, COLOR_YELLOW, output);
						playerdata[playerid][57] = 10;
						playerdata[playerid][4] = playerdata[playerid][4] + Strafkatalog[5];
						GivePlayerMoney(playerid, Strafkatalog[5]);
					}
					if(ZuSchnell > 35)
					{
						if(Blitzer[i][4] == 1)
							format(output, sizeof(output), "***Blitzer: Sie sind innerorts %i Km/h zu schnell gefahren. ***", ZuSchnell);
						if(Blitzer[i][4] == 2)
							format(output, sizeof(output), "***Blitzer: Sie sind außerorts %i Km/h zu schnell gefahren. ***", ZuSchnell);
						SendClientMessage(playerid, COLOR_YELLOW, output);
						format(output, sizeof(output), "*** Strafe: Ihnen wurden %i $ abgezogen ***", Strafkatalog[6]);
						SendClientMessage(playerid, COLOR_YELLOW, output);
						playerdata[playerid][57] = 60;
						playerdata[playerid][4] = playerdata[playerid][4] + Strafkatalog[6];
						GivePlayerMoney(playerid, Strafkatalog[6]);
					}
				}
			}
		}
	}

}
public settime()
{
  new Hour, Minute,Seconds, output[10];
  gettime(Hour,Minute,Seconds);
  format(output,10,"%02d:%02d", Hour, Minute);
  SetWorldTime(Hour);
  if(Minute == 0 || Minute == 30) timerall30min();
  if(Hour == 0) pbote_add();
  TextDrawSetString(zeitanzeigen,output);
}
public uhrstellen()
{
  new Hour, Minute,Seconds;
  gettime(Hour, Minute,Seconds);
  if(Seconds != 0)
  {
	settime(Hour,Minute,Seconds);
	SetTimer("uhrstellen",(60 - Seconds)*1000,false);
  }
  else
  {
	SetTimer("settime",60000,true);
  }
}
public timerall30min()
{
  stellegebautos();
  trucker_biz_timer();
}