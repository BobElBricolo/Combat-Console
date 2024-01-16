/**
* \file    : Arme.h
* \brief   : Fichier qui contient l'interface de la classe Arme.
* \date    : 8 mai 2021
* \auteur  : Alexis Young et Timothé St-Pierre
*/
#pragma once

#include <string>

/**
* \class Arme
* \brief Classe qui permet de créer/gérer les armes
*/
#pragma once
#include <string>

class Arme
{
public:
	Arme();
	Arme(const std::string& p_nom, int p_degatsMin, int p_degatsMax);
	~Arme() {};

	//Accesseurs
	const std::string& getNomArme() const;
	int getDegatsArme() const;

	void changer(const std::string& p_nom, int p_degatsMin, int p_degatsMax);
	std::string afficherArme() const;

protected:
	std::string m_nom;
	int m_degatsMin;
	int m_degatsMax;
};

