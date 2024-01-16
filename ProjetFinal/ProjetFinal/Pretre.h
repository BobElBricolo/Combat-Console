/**
* \file    : Pretre.h
* \brief   : Fichier qui contient l'interface de la classe Pretre hérite de la classe personnage.
* \date    : 8 mai 2020
* \auteur  : Alexis Young et Timothé St-Pierre
*/

#pragma once
#include <string>
#include "Personnage.h"

class Pretre : public Personnage
{
public:

	// Constructeurs
	Pretre(const std::string& p_nom); 
	Pretre(const std::string& p_nom, const std::string& p_nomArme, int p_degatsMinArme, int p_degatsMaxArme); 

	//Destructeur
	virtual ~Pretre();

	void sortGuerison();
	int getPointsMana() const;

	virtual std::string getInfosPersonnage() const;
	virtual void choixAttaque(Personnage& p_cible);
	virtual void messageFin(Personnage& p_cible) const;

protected:
	int m_mana;
};

