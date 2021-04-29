/*

CObjet.h
Jeremy Belec
17 Mai 2015
Declaration de la classe CObjet

*/

#include "CObjet.h"

CObjet::CObjet(sf::Texture& LaTexture, CPosition Position, string Nom, int GainVie, int GainAtk, int GainDef)
{
	FrameHauteur_ = LaTexture.getSize().x;
	FrameLargeur_ = LaTexture.getSize().y;

	setPosition(Position.x, Position.y);
	setOrigin(static_cast<float>(FrameLargeur_ / 2), static_cast<float>(FrameHauteur_));
	Nom_ = Nom;
	GainVie_ = GainVie;
	GainAtk_ = GainAtk;
	GainDef_ = GainDef;
	setTexture(LaTexture);
}

void CObjet::Afficher(sf::RenderWindow& Window)
{
	Window.draw(*this);
}

string CObjet::GetNom() const
{
	return Nom_;
}

int CObjet::GetAttaque() const
{
	return GainAtk_;
}

int CObjet::GetVitalite() const
{
	return GainVie_;
}

int CObjet::GetDefence() const
{
	return GainDef_;
}

std::ostream& operator<<(std::ostream& os, const CObjet& o)
{
	// Envoyez l’affichage à os, utilisez l objet o
	os << "Statistique de " << o.GetNom() << "| Gain Attaque : " << o.GetAttaque() << " |Gain Defence : " << o.GetDefence() << " |Gain Vitalite : " << o.GetVitalite() << endl;
	return os;
}