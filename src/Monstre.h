/*

Monstre.h
Jeremy Belec
17 Mai 2015
Declaration de la classe CMonstre

*/

#pragma once
#include "CPersonnage.h"

class CMonstre : public CPersonnage
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
	CMonstre(sf::Texture& LaTexture, CPosition Position, string Nom, int Vie, int Attaque, int Defence);
	/////////////////////////////////////////
	// Deplacer
	// Redifinition de la methode virtuelle pure Deplacer de CPersonnage
	// Le monstre ce deplace de 3 pixel selon une direction au hasard
	// Si la position presente n'est pas valide le monstre change de direction au hasard
	// 
	// Extrant : Retourne true
	/////////////////////////////////////////
	virtual bool Deplacer(CCarte& Monde);
};