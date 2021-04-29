////////////////////////////////////////////////////////////
// main.cpp
// 
// Programme principal de jeu de Zelda
// Activité Synthèse 420-KAB-LG
// Etienne Forest
// Joan-Sébastien Morales 
// Création: 28 avril 2010
// Version 1.0
// Version 2.0 - Adaptation à SFML - 10 mai 2014
////////////////////////////////////////////////////////////
#include <iostream>
#include "Carte.h"
#include "Heros.h"
#include "Monstre.h"
using namespace std;
using namespace sf;

int main(int argc, char *argv[])
{
   bool bQuitter = true; // Vrai s'il faut continuer la partie
   bool bPain = true;    // Vrai si le pain existe encore
   bool bGlaive = true;  // Vrai si le glaive existe encore
   bool bMechant = true; // Vrai si le méchant est vivant
   bool bLink = true;	  // Vrai si le héros est vivant
    
   srand(static_cast<unsigned int>(time(0)));

   try
   {
      // Création des objets
      RenderWindow Fenetre(VideoMode(640, 480), "Zelda");
      Texture MondeText;
      MondeText.loadFromFile("res\\lemonde.bmp");
      Image MondeMasque;
      MondeMasque.loadFromFile("res\\MasqueDuMonde.bmp");

      CCarte Monde(MondeText, MondeMasque);

      Texture LinkText;
      LinkText.loadFromFile("res\\link.png");
      CHeros Link(LinkText, CPosition(848, 1989), "Link", 10, 2, 10);

      Texture MechantText;
      MechantText.loadFromFile("res\\monstre.png");
      CMonstre Mechant(MechantText, CPosition(648, 2089), "Mechant", 100, 10, 10);

      Texture PainText;
      PainText.loadFromFile("res\\pain.png");
      CObjet Pain(PainText, CPosition(902, 1902), "Pain", 100, 0, 0);

      Texture GlaiveText;
      GlaiveText.loadFromFile("res\\epee.png");
      CObjet Glaive(GlaiveText, CPosition(758, 1830), "Glaive", 0, 10, 0);


      do
      {
         // Déplacer les personnages
         bQuitter = Link.Deplacer(Monde);
         Mechant.Deplacer(Monde);

         // Essayer de prendre les objets
         if (bPain)
            bPain = Link.Prendre(Pain);
         if (bGlaive)
            bGlaive = Link.Prendre(Glaive);

         // Essayer d'attaquer
         if (bMechant && bLink)
            bMechant = Link.Attaquer(Mechant);
         if (bMechant && bLink)
            bLink = Mechant.Attaquer(Link);

         // Affichage
         View Vue = Fenetre.getView();
         Vue.setCenter(Link.getPosition());
         Fenetre.setView(Vue);

		 Monde.Afficher(Fenetre);
		 if (bPain)
			 Pain.Afficher(Fenetre); 
		 if (bGlaive)
			 Glaive.Afficher(Fenetre);
         if (bMechant)
            Mechant.Afficher(Fenetre);
         if (bLink)
            Link.Afficher(Fenetre);

         // Rafraichir la fenêtre
         Fenetre.display();

		 // On inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		 Event event;
		 while (Fenetre.pollEvent(event))
		 {
			 // évènement "fermeture demandée" : on ferme la fenêtre
			 if (event.type == Event::Closed)
				 Fenetre.close();
		 }

         // Attendre 30 millisecondes	
         sleep(milliseconds(30));
	  } 
	  while (!bQuitter && bLink && Fenetre.isOpen());
   }
   catch (string s)
   {
      cout << s;
   }

   if (!bLink)
   {
      cout << "Tu es mort!" << endl;
   }
   return 0;
}