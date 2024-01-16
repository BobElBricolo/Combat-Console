/**
* \fichier    : Arme.cpp
* \brief      : Implémentation de la classe Arme
* \date       : 8 mai 2021
* \author     : Alexis Young et Timothé St-Pierre
*/
#include <string>
#include <sstream>
#include "Arme.h"
#include "mesFonctions.h"

using namespace std;

/*
* Constructeur par défaut
*/
Arme::Arme() : m_nom(accent("Bâton")), m_degatsMin(1), m_degatsMax(5)
{
}

/*
* Constructeur surchargé
* Entrée	: Une chaine de caractère qui représente le nom de l'arme
*			: Un entier qui représente les dégats de l'arme
*/
Arme::Arme(const std::string& p_nom, int p_degatsMin, int p_degatsMax) : m_nom(p_nom), m_degatsMin(p_degatsMin),
m_degatsMax(p_degatsMax)
{
}

/*
* Rôle : Accesseur de l'attribut m_nom
* Entrée : Aucune
* Sortie : Une chaîne de caractère qui représente le nom de l'arme
*/
const std::string& Arme::getNomArme() const
{
	return m_nom;
}

/*
* Rôle : Accesseur de l'attribut m_degats
* Entrée : Aucune
* Sortie : Un entier qui représente les dégâts de l'arme
*/
int Arme::getDegatsArme() const
{
	return trouverAleatoire(m_degatsMin, m_degatsMax);
}

/*
* Rôle		: Permet de modifier le nom et le nombre de dégats de l'arme
* Entrée	: Une chaîne de caractère qui représente le nouveau nom de l'arme
*             un entier qui représente le nombre de points de dégâts de la nouvelle arme
* Sortie	: Aucune
*/
void Arme::changer(const std::string& p_nom, int p_degatsMin, int p_degatsMax)
{
	m_nom = p_nom;
	m_degatsMin = p_degatsMin;
	m_degatsMax = p_degatsMax;
}

/*
* Rôle : Retourner les informations formatées sur l'arme
* Entrée : Aucune
* Sortie : Chaîne de caractère qui contient toutes les informations
*/
string Arme::afficherArme() const
{
	ostringstream os;
	os << "Arme : " << m_nom << accent(" (Dégâts : ") << m_degatsMin << "-" << m_degatsMax << ")" << endl;

	return os.str();
}
