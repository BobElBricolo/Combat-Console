/**
* \fichier    : Arme.cpp
* \brief      : Impl�mentation de la classe Arme
* \date       : 8 mai 2021
* \author     : Alexis Young et Timoth� St-Pierre
*/
#include <string>
#include <sstream>
#include "Arme.h"
#include "mesFonctions.h"

using namespace std;

/*
* Constructeur par d�faut
*/
Arme::Arme() : m_nom(accent("B�ton")), m_degatsMin(1), m_degatsMax(5)
{
}

/*
* Constructeur surcharg�
* Entr�e	: Une chaine de caract�re qui repr�sente le nom de l'arme
*			: Un entier qui repr�sente les d�gats de l'arme
*/
Arme::Arme(const std::string& p_nom, int p_degatsMin, int p_degatsMax) : m_nom(p_nom), m_degatsMin(p_degatsMin),
m_degatsMax(p_degatsMax)
{
}

/*
* R�le : Accesseur de l'attribut m_nom
* Entr�e : Aucune
* Sortie : Une cha�ne de caract�re qui repr�sente le nom de l'arme
*/
const std::string& Arme::getNomArme() const
{
	return m_nom;
}

/*
* R�le : Accesseur de l'attribut m_degats
* Entr�e : Aucune
* Sortie : Un entier qui repr�sente les d�g�ts de l'arme
*/
int Arme::getDegatsArme() const
{
	return trouverAleatoire(m_degatsMin, m_degatsMax);
}

/*
* R�le		: Permet de modifier le nom et le nombre de d�gats de l'arme
* Entr�e	: Une cha�ne de caract�re qui repr�sente le nouveau nom de l'arme
*             un entier qui repr�sente le nombre de points de d�g�ts de la nouvelle arme
* Sortie	: Aucune
*/
void Arme::changer(const std::string& p_nom, int p_degatsMin, int p_degatsMax)
{
	m_nom = p_nom;
	m_degatsMin = p_degatsMin;
	m_degatsMax = p_degatsMax;
}

/*
* R�le : Retourner les informations format�es sur l'arme
* Entr�e : Aucune
* Sortie : Cha�ne de caract�re qui contient toutes les informations
*/
string Arme::afficherArme() const
{
	ostringstream os;
	os << "Arme : " << m_nom << accent(" (D�g�ts : ") << m_degatsMin << "-" << m_degatsMax << ")" << endl;

	return os.str();
}
