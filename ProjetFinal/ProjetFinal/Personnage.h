/**
* \file    : Personnage.h
* \brief   : Fichier qui contient l'interface de la classe Personnage.
* \date    : 10 mai 2020
* \auteur  : Dave Lacourse
*/
#pragma once
#include <string>
#include "Arme.h"

/**
* \file    : Personnage.h
* \brief   : Fichier qui contient l'interface de la classe Personnage.
* \date    : 8 mai 2021
* \auteur  : Alexis Young et Timothé St-Pierre
*/

class Personnage {
public:

	// Constructeurs
	Personnage(const std::string& p_nom);
	Personnage(const std::string& p_nom, const std::string& p_nomArme, int p_degatsArmeMin, int p_degatsArmeMax);

	//Destructeur
	~Personnage(); 

	std::string getName() const;
	std::string afficherInformations() const;
	int getPointsdeVie() const;
	int attaqueArme(Personnage& p_cible);
	void recevoirDegats(int p_nbDegats);
	bool estVivant() const;

	virtual std::string getInfosPersonnage() const = 0;
	virtual void choixAttaque(Personnage& p_cible) = 0;
	virtual void messageFin(Personnage& p_cible) const = 0;

protected:
	int m_vie;
	Arme* m_arme;
	std::string m_nom;
	std::string m_classe;

private:
	//Construteur de copie privé
	Personnage(const Personnage& p_personnageACopier);
	//Surcharge de l'opérateur = privé
	Personnage& operator=(Personnage const& p_personnageACopier);
};