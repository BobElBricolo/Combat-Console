/**
* \fichier    : Personnage.cpp
* \brief      : Implémentation de la classe Personnage
* \date       : 8 mai 2021
* \author     : Alexis Young et Timothé St-Pierre
*/

#include <string>
#include <iostream>
#include <sstream>
#include "Personnage.h"
#include "mesFonctions.h"

using namespace std;

/*
* Constructeur par défaut
*/
Personnage::Personnage(const string& p_nom) : m_vie(40), m_arme(0), m_nom(p_nom),m_classe("Personnage") {
	m_arme = new Arme();
}


/*
* Constructeur surchargé
* Entrée	: Une chaîne de caractère qui représente le nom de l'arme
*			: Un entier qui représente les dégats de l'arme
*/
Personnage::Personnage(const string& p_nom, const std::string& p_nomArme, int p_degatsArmeMin, int p_degatsArmeMax) : m_vie(100),
m_arme(0), m_nom(p_nom), m_classe("Personnage")
{
	m_arme = new Arme(p_nomArme, p_degatsArmeMin, p_degatsArmeMax);
}


/**
* \brief     : Constructeur de copie
* \param[in] : un objet Personnage qui représente le personnage à copier
*/
Personnage::Personnage(const Personnage& p_personnageACopier) : m_nom(p_personnageACopier.getName()),
m_vie(p_personnageACopier.getPointsdeVie()), m_arme(0)
{
	m_arme = new Arme(*(p_personnageACopier.m_arme));
}


/**
* \brief     : Surcharge de l'opérateur d'assignation pour la classe Personne
* \param[in] : un objet Personnage qui représente le personnage à copier
*/
Personnage& Personnage::operator=(Personnage const& p_personnageACopier)
{
	if (this != &p_personnageACopier)
		//On vérifie que l'objet n'est pas le même que celui reçu en argument
	{
		m_nom = p_personnageACopier.getName();
		m_vie = p_personnageACopier.m_vie; //On copie tous les champs
		delete m_arme;
		m_arme = new Arme(*(p_personnageACopier.m_arme));
	}
	return *this; //On renvoie l'objet lui-même
}


/*
* Destructeur de personnage
*/
Personnage::~Personnage()
{
	delete m_arme;
	m_arme = 0;
}


/*
* Rôle : Accesseur de l'attribut m_vie
* Entrée : Aucune
* Sortie : Un entier qui représente le nombre de points de vie du personnage
*/
int Personnage::getPointsdeVie() const
{
	return m_vie;
}

string Personnage::getName() const {

	return m_nom;
}

/*
* Rôle : Retourner les informations formatées sur le personnage
* Entrée : Aucune
* Sortie : Chaîne de caractère qui contient toutes les informations
*/
std::string Personnage::afficherInformations() const
{
	ostringstream os;

	os << "Mon nom est : " << m_nom << endl;
	os << "Nombre de points de vie : " << m_vie << endl;
	os << m_arme->afficherArme();


	return os.str();
}

/*
* Rôle		: Permet de dimunuer les points de vie du personnage en fonction des dégâts reçus
* Entrée	: Un entier qui représente le nombre de dégâts
* Sortie	: Aucune
*/
void Personnage::recevoirDegats(int p_nbDegats)
{
	m_vie -= p_nbDegats;
	if (m_vie < 0) {
		m_vie = 0;
	}
}

/*
* Rôle		: Permet d'attaquer un autre personnage avec son arme
* Entrée	: Un objet Personne qui est la cible de l'attaque
* Sortie	: Aucune
*/
int Personnage::attaqueArme(Personnage& p_cible)
{
	int degat(0);
	degat = m_arme->getDegatsArme();
	p_cible.recevoirDegats(degat);

	return degat;
}



/*
* Rôle		: Vérifie si le personnage est toujours vivant
* Entrée	: Aucune
* Sortie	: Un booléen (vrai si vivant sinon faux)
*/
bool Personnage::estVivant() const
{
	bool estVivant = true;
	if (m_vie == 0) {
		estVivant = false;
	}

	return estVivant;
}