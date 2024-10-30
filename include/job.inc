#include <job_fahrradkurier>
#include <job_trucker>
#include <job_postbote>
#include <job_fahrlehrer>
#include <job_pilot>
#include <job_limofahrer>
#include <job_prodfahrer>
#include <job_mechandtuner>
#include <job_taxifahrer>

forward erstelleberufe();

public erstelleberufe()
{
  fahrradkurier();
  print("Erstelle Job Fahrradkurier");
  trucker();
  print("Erstelle Job Trucker");
  postbote();
  print("Erstelle Job Postbote");
  prodfahrer();
  print("Erstelle Job Prod-Fahrer");
  pilot();
  print("Erstelle Job Pilot");
  fahrzeuge_fahrschule();
  print("Erstelle Fahrschule");
  limofahrer();
  print("Erstelle Limofahrer");
  createmeachandtuner();
  print("Erstelle Mechaniker / Tuner");
  taxi();
  print("Erstelle Taxi");
}