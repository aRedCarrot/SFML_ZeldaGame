/*

CObjet.h
Jeremy Belec
17 Mai 2015
Declaration de la classe CObjet

*/
#include <SFML/Graphics.hpp>
#include "Position.h"
#include <string>
using namespace std;

class CObjet : public sf::Sprite
{
	string Nom_; // Nom de l'objet
	int GainVie_; // Augmente la vie du personnage selon la valeur de l'objet
	int GainAtk_; // Augmente l'attaque du personnage selon la valeur de l'objet
	int GainDef_; // Augmente la defence du personnage selon la valeur de l'objet
	int FrameHauteur_; // Hauteur de l'image de l'objet
	int FrameLargeur_; // Largeur de l'image de l'objet
public:
	//////////////////////////////////////////
	// CObjet
	// Constructeur parametrique
	//
	// Intrant : Texture de l'objet
	//           Position de l'objet sur la carte ( Voir CPosition )
	//           Nom de l'objet
	//			 Gain de vie que l'objet offre
	//			 Gain d'attaque que l'objet offre
	//			 Gain de defence que l'objet offre
	//////////////////////////////////////////////
	CObjet(sf::Texture& LaTexture, CPosition Position, string Nom, int GainVie, int GainAtk, int GainDef);
	///////////////////////////////////////////
	// Afficher
	// Affiche l'objet dans la fenetre
	///////////////////////////////////////////
	void Afficher(sf::RenderWindow& Window);
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
/////////////////////////////////////////////
// Operator
// Envoie a la console les statistique d'un objet
//
//  Intrant : Ostream
//            Un CObjet
/////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os, const CObjet& o);