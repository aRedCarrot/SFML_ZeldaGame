/*

CPersonnage.h
Jeremy Belec
17 Mai 2015
Declaration de la classe CPersonnage

*/

#pragma once
#include "Animation.h"
#include "Position.h"
#include "Carte.h"
#include "CObjet.h"
#include "Zelda.h"
#include <string>
using namespace std;
class CPersonnage : public CAnimation
{
	string Nom_; // Nom du personange
	int Vitalite_; // Statistique de vie du personnage
	int Attaque_; // Statistique d'attaque du personnage
	int Defence_; // Statistique de defence du personnage
public:
	///////////////////////////////////////
	// Constructeur parametrique CPersonnage
	//
	// Intrant :  Texture pour le personnage
	//            Position du personnage sur la carte
	//            Nom du personnage
	//            Point de vatalite du personnage
	//            Point d'attaque du personnage
	//            Point de defence du personnage
	////////////////////////////////////////
	CPersonnage(sf::Texture& LaTexture, CPosition Position,string Nom, int Vie, int Attaque, int Defence);
	///////////////////////////////////////////
	// Deplacer
	// Methode virtuelle pure qui sera redefini dans les sous-classes
	//
	// Intrant : Reference vers un Objet CCarte
	//
	// Extrant : Variable de type bool
	///////////////////////////////////////////
	virtual bool Deplacer(CCarte& Reference) = 0;
	//////////////////////////////////////////
	// Prendre
	// Le personnage prend un objet sur le sol ( envoyer en reference )
	//
	// Intrant : Reference vers l'objet au sol
	//
	// Extrant : Variable de type bool qui retourne false 
	//           si l'objet a ete ramasser ou true si non
	//////////////////////////////////////////
	bool Prendre(CObjet& Objet);
	/////////////////////////////////////////
	// Attaquer
	// Attaque le personnage envoyer en reference si il est dans la porte du personnage
	// 
	// Intrant : Reference vers un autre personnage
	//
	// Extrant : Variable de type bool qui retourne false si l'enemie est mort
	//           ou true dans toute autre cas
	///////////////////////////////////////////
	bool Attaquer(CPersonnage& Personnage);
   //////////////////////////////////////////
   // Briser
   // Prend en parametre un CPersonange et inflicte le degat a la victime
   //
   // Intrant : Reference vers un CPersonnage ( Victime )
   //           variable type int pour indiquer le degat a infliger
   /////////////////////////////////////////////
   void Briser(CPersonnage& Victime, int Degat);
	/////////////////////////////////////////
	// Mutateur
	// Affecte l'attribut selon un parametre envoyer
	//
	// Intrant : Valeur desire pour l'attribut
	void SetVitalite(int Vit);
	void SetAttaque(int Attaque);
	void SetDefence(int Defence);
	//
	////////////////////////////////////
	////////////////////////////////////
	// Accesseurs
	// Retourne la valeur de l'attribut selon le nom de la methode
	//
	// Extrant : Valeur de l'attribut
	string GetNom() const;
	int GetVitalite() const;
	int GetAttaque() const;
	int GetDefence() const;
	//////////////////////////////////////
};
std::ostream& operator<<(std::ostream& os, const CPersonnage& o);