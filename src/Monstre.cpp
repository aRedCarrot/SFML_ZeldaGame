/*

Monstre.h
Jeremy Belec
17 Mai 2015
Definition de la classe CMonstre

*/

#include "Monstre.h"
#include "Carte.h"


CMonstre::CMonstre(sf::Texture& LaTexture, CPosition Position, string Nom, int Vie, int Attaque, int Defence) : CPersonnage(LaTexture,Position,Nom,Vie,Attaque,Defence)
{

}

bool CMonstre::Deplacer(CCarte& Monde)
{
   CPosition Position = getPosition();

   bool ABouger = false;
	while (ABouger == false)
	{
      Direction Direction_ = GetDirection();
		switch (Direction_)
		{
		case Bas:
         setPosition(getPosition().x, getPosition().y + VitesseMonstre);
         ABouger = true;
			if (!Monde.EstPositionValide(getPosition()))
			{
            setPosition(getPosition().x, getPosition().y - VitesseMonstre);
            ABouger = false;
			}
			break;
		case Gauche:
         setPosition(getPosition().x - VitesseMonstre, getPosition().y);
         ABouger = true;
         if (!Monde.EstPositionValide(getPosition()))
         {
            setPosition(getPosition().x + VitesseMonstre, getPosition().y);
            ABouger = false;
         }
			break;
		case Droite:
         setPosition(getPosition().x + VitesseMonstre, getPosition().y);
         ABouger = true;
         if (!Monde.EstPositionValide(getPosition()))
         {
            setPosition(getPosition().x - VitesseMonstre, getPosition().y);
            ABouger = false;
         }
         break;
		case Haut:
         setPosition(getPosition().x, getPosition().y - VitesseMonstre);
         ABouger = true;
         if (!Monde.EstPositionValide(getPosition()))
         {
            setPosition(getPosition().x, getPosition().y + VitesseMonstre);
            ABouger = false;
         }
         break;
		}
		if (ABouger == false)
		{
			int Rand = rand() % 4;
         switch (Rand)
         {
         case 0:
            SetDirection(Bas);
            break;
         case 1:
            SetDirection(Gauche);
            break;
         case 2:
            SetDirection(Droite);
            break;
         case 3:
            SetDirection(Haut);
            break;
         }
		}
	}
	return true;
}
