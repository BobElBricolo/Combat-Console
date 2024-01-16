/**
* \file    : Guerrier.h
* \brief   : Fichier qui contient l'interface de la classe Guerrier hérite de la classe personnage.
* \date    : 8 mai 2020
* \auteur  : Alexis Young et Timothé St-Pierre
*/
#pragma once

#include "Personnage.h"

class Guerrier : public Personnage
{
public:
	//Constructeurs
	Guerrier(const std::string& p_nom);
	Guerrier(const std::string& p_nom, const std::string& p_nomArme, int p_degatsMinArme, int p_degatsMaxArme);

	//Destructeur
	virtual ~Guerrier();

	void chargePercutante(Personnage& p_cible) const;
	virtual void choixAttaque(Personnage& p_cible);
	virtual void messageFin(Personnage& p_cible) const;
	virtual std::string getInfosPersonnage() const;
	
};

