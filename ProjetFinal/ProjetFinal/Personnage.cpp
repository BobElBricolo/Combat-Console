/**
* \fichier    : Personnage.cpp
* \brief      : Impl�mentation de la classe Personnage
* \date       : 8 mai 2021
* \author     : Alexis Young et Timoth� St-Pierre
*/

#include <string>
#include <iostream>
#include <sstream>
#include "Personnage.h"
#include "mesFonctions.h"

using namespace std;

/*
* Constructeur par d�faut
*/
Personnage::Personnage(const string& p_nom) : m_vie(40), m_arme(0), m_nom(p_nom),m_classe("Personnage") {
	m_arme = new Arme();
}


/*
* Constructeur surcharg�
* Entr�e	: Une cha�ne de caract�re qui repr�sente le nom de l'arme
*			: Un entier qui repr�sente les d�gats de l'arme
*/
Personnage::Personnage(const string& p_nom, const std::string& p_nomArme, int p_degatsArmeMin, int p_degatsArmeMax) : m_vie(100),
m_arme(0), m_nom(p_nom), m_classe("Personnage")
{
	m_arme = new Arme(p_nomArme, p_degatsArmeMin, p_degatsArmeMax);
}


/**
* \brief     : Constructeur de copie
* \param[in] : un objet Personnage qui repr�sente le personnage � copier
*/
Personnage::Personnage(const Personnage& p_personnageACopier) : m_nom(p_personnageACopier.getName()),
m_vie(p_personnageACopier.getPointsdeVie()), m_arme(0)
{
	m_arme = new Arme(*(p_personnageACopier.m_arme));
}


/**
* \brief     : Surcharge de l'op�rateur d'assignation pour la classe Personne
* \param[in] : un objet Personnage qui repr�sente le personnage � copier
*/
Personnage& Personnage::operator=(Personnage const& p_personnageACopier)
{
	if (this != &p_personnageACopier)
		//On v�rifie que l'objet n'est pas le m�me que celui re�u en argument
	{
		m_nom = p_personnageACopier.getName();
		m_vie = p_personnageACopier.m_vie; //On copie tous les champs
		delete m_arme;
		m_arme = new Arme(*(p_personnageACopier.m_arme));
	}
	return *this; //On renvoie l'objet lui-m�me
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
* R�le : Accesseur de l'attribut m_vie
* Entr�e : Aucune
* Sortie : Un entier qui repr�sente le nombre de points de vie du personnage
*/
int Personnage::getPointsdeVie() const
{
	return m_vie;
}

string Personnage::getName() const {

	return m_nom;
}

/*
* R�le : Retourner les informations format�es sur le personnage
* Entr�e : Aucune
* Sortie : Cha�ne de caract�re qui contient toutes les informations
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
* R�le		: Permet de dimunuer les points de vie du personnage en fonction des d�g�ts re�us
* Entr�e	: Un entier qui repr�sente le nombre de d�g�ts
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
* R�le		: Permet d'attaquer un autre personnage avec son arme
* Entr�e	: Un objet Personne qui est la cible de l'attaque
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
* R�le		: V�rifie si le personnage est toujours vivant
* Entr�e	: Aucune
* Sortie	: Un bool�en (vrai si vivant sinon faux)
*/
bool Personnage::estVivant() const
{
	bool estVivant = true;
	if (m_vie == 0) {
		estVivant = false;
	}

	return estVivant;
}