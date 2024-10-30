forward createmeachandtuner();

new Float:paynspray[][3] =
{
  {2072.72, -1831.31, 13.11},
  {-1904.74, 275.79, 40.69},
  {488.35, -1734.28, 10.73},
  {1025.37, -1029.36, 31.65},
  {719.74, -462.90, 16.33},
  {-2424.91, 1028.44, 50.39},
  {-1420.77, 2591.42, 55.82},
  {-100.26, 1111.13, 19.74},
  {1968.19, 2162.08, 10.82}
};

new Float:modshops[][3] =
{
  {1041.09, -1026.49, 31.65},
  {2644.85, -2038.81, 13.30},
  {-1936.16, 239.13, 34.32},
  {-2715.94, 217.45, 4.34},
  {2387.33, 1043.06, 10.82}
};

public createmeachandtuner()
{
  for(new i;i < sizeof(paynspray);i++)
  {
	CreateDynamicMapIcon(paynspray[i][0], paynspray[i][1], paynspray[i][2], 63, -1,-1, -1, -1, 500);
  }
  for(new i;i < sizeof(modshops);i++)
  {
	CreateDynamicMapIcon(modshops[i][0], modshops[i][1], modshops[i][2], 27, -1,-1, -1, -1, 500);
  }
}