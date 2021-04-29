/*

CHeros.h
Jeremy Belec
17 Mai 2015
Declaration de la classe CHeros

*/

#pragma once
#include "CPersonnage.h"

class CHeros : public CPersonnage
{
public:
	///////////////////////////////////////
	// Constructeur parametrique CHeros
	// Renvoie tous les parametres en pre-construction vers le constructeur de CPersonnage
	//
	// Intrant :  Texture pour le personnage
	//            Position du personnage sur la carte
	//            Nom du personnage
	//            Point de vatalite du personnage
	//            Point d'attaque du personnage
	//            Point de defence du personnage
	////////////////////////////////////////
	CHeros(sf::Texture& LaTexture, CPosition Position, string Nom, int Vie, int Attaque, int Defence);
	/////////////////////////////////////////
	// Deplacer
	// Redifinition de la methode virtuelle pure Deplacer de CPersonnage
	// Le Heros ce deplace de 3 pixel selon une touche appuyer au clavier
	// 
	// Extrant : Retourne true si la touche Echappement est appuyer,
	//           retourne false si non
	/////////////////////////////////////////
	virtual bool Deplacer(CCarte& Monde);
};