/*

CHeros.cpp
Jeremy Belec
17 Mai 2015
Definition de la classe CHeros

*/
#include "Heros.h"

CHeros::CHeros(sf::Texture& LaTexture, CPosition Position, string Nom, int Vie, int Attaque, int Defence) : CPersonnage(LaTexture,Position,Nom,Vie,Attaque,Defence)
{

}

bool CHeros::Deplacer(CCarte& Monde)
{
	bool Quittez = false;
   CPosition Position = getPosition();

   if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
   {
      setPosition(getPosition().x, getPosition().y - VitesseZelda);
      SetDirection(Haut);
      if (!Monde.EstPositionValide(getPosition()))
      {
         setPosition(getPosition().x, getPosition().y + VitesseZelda);
      }
   }
   else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
   {
      setPosition(getPosition().x - VitesseZelda, getPosition().y);
      SetDirection(Gauche);
      if (!Monde.EstPositionValide(getPosition()))
      {
         setPosition(getPosition().x + VitesseZelda, getPosition().y);
      }
   }
   else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
   {
      setPosition(getPosition().x, getPosition().y + VitesseZelda);
      SetDirection(Bas);
      if (!Monde.EstPositionValide(getPosition()))
      {
         setPosition(getPosition().x, getPosition().y - VitesseZelda);
      }
   }
   else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
   {
      setPosition(getPosition().x + VitesseZelda, getPosition().y);
      SetDirection(Droite);
      if (!Monde.EstPositionValide(getPosition()))
      {
         setPosition(getPosition().x - VitesseZelda, getPosition().y);
      }
   }
   else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
   {
      Quittez = true;
   }

	return Quittez;
}