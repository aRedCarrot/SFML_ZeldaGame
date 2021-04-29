/*

CPersonnage.cpp
Jeremy Belec
17 Mai 2015
Definition de la classe CPersonnage

*/
#include "CPersonnage.h"

void CPersonnage::SetVitalite(int Vit)
{
		Vitalite_ = Vit;
}

void CPersonnage::SetAttaque(int Attaque)
{
	if (Attaque > 0)
	{
		Attaque_ = Attaque;
	}
}

void CPersonnage::SetDefence(int Defence)
{
	if (Defence > 0)
	{
		Defence_ = Defence;
	}
}

string CPersonnage::GetNom() const
{
	return Nom_;
}

int CPersonnage::GetVitalite() const
{
	return Vitalite_;
}

int CPersonnage::GetAttaque() const
{
	return Attaque_;
}

int CPersonnage::GetDefence() const
{
	return Defence_;
}

CPersonnage::CPersonnage(sf::Texture& LaTexture, CPosition Position, string Nom, int Vie, int Attaque, int Defence) : CAnimation(LaTexture,Position)
{
	Nom_ = Nom;
	SetVitalite(Vie);
	SetAttaque(Attaque);
	SetDefence(Defence);
}

bool CPersonnage::Attaquer(CPersonnage& Personnage)
{
	if (PositionsProches(this->getPosition(), Personnage.getPosition()))
	{
      int Chance = rand() % (Max - Min + Min) + Min;
      if (Chance >= Personnage.GetDefence())
      {
         int Damage = rand() % (this->GetAttaque() + Min) + Min;
         Briser(Personnage, Damage);
      }
		if (Personnage.GetVitalite() <= 0)
		{
			return false;
		}
	}

	return true;
}

void CPersonnage::Briser(CPersonnage& Victime, int Degat)
{
   int Vie = Victime.GetVitalite();
   
   Victime.SetVitalite(Vie - Degat);
   cout << *this << endl << Victime << endl;
   cout << this->GetNom() << " inflige a " << Victime.GetNom() << " " << Degat << " point de degats!" << endl;
   cout << *this << endl << Victime << endl;
}

bool CPersonnage::Prendre(CObjet& Objet)
{
	if (PositionsProches(this->getPosition(), Objet.getPosition()))
	{
		SetAttaque(GetAttaque() + Objet.GetAttaque());
		SetVitalite(GetVitalite() + Objet.GetVitalite());
		SetDefence(GetDefence() + Objet.GetDefence());
		cout << *this << endl << Objet << endl;
		cout << this->GetNom() << " gagne " << Objet.GetAttaque() << " point d attaque , " << Objet.GetVitalite() << " point de vie , et " << Objet.GetDefence() << " point de defence!" << endl;
		cout << *this << endl;
		return false;
	}
   return true;
}

ostream& operator<<(ostream& os, const CPersonnage& o)
{
	// Envoyez l’affichage à os, utilisez le personnage o
   os << "Statistique de " << o.GetNom() << "| Attaque : " << o.GetAttaque() << " |Defence : " << o.GetDefence() << " |Vitalite : " << o.GetVitalite() << endl;
	return os;
}
