/**
* \file    : Druide.cpp
* \brief   : Impl�mentation de la classe Druide
* \date    : 8 mai 2021
* \author  : Alexis Young et Timoth� St-Pierre
*/

#include <iostream>
#include <string>
#include "mesFonctions.h"
#include "Druide.h"
#include <sstream>

using namespace std;

const int VIE_DRUIDE = 50;
const int VIE_MAX = 50;
const int MANA_DRUIDE = 30;
const string NOM_ARME_DRUIDE = accent("B�ton");
const int DEGAT_MAX_ARME_DRUIDE = 10;
const int DEGAT_MIN_ARME_DRUIDE = 1;
const int COUT_ATTAQUE_CELESTE = 10;
const int COUT_GUERISON = 5;
const int DEGAT_MAX_CELESTE = 25;
const int DEGAT_MIN_CELESTE = 15;
const int POINT_VIE_GUERISON_MAX = 20;
const int POINT_VIE_GUERISON_MIN = 10;


/**
* \brief     : Constructeur avec un nom
* \param[in] : un string qui repr�sente le nom du guerrier
*/
Druide::Druide(const std::string& p_nom): Pretre(p_nom, NOM_ARME_DRUIDE, DEGAT_MIN_ARME_DRUIDE, DEGAT_MAX_ARME_DRUIDE) {
	m_classe = "Druide";
	m_vie = VIE_DRUIDE;
	m_mana = MANA_DRUIDE;
	m_arme = new Arme(NOM_ARME_DRUIDE, DEGAT_MIN_ARME_DRUIDE, DEGAT_MAX_ARME_DRUIDE);
}


/**
* \brief     : Constructeur surcharg�
* \param[in] : un string qui repr�sente le nom de mon druide
* \param[in] : un string qui repr�sente le nom de l'arme
* \param[in] : un entier qui repr�sente le d�gat fait par l'arme
*/
Druide::Druide(const std::string& p_nom, const std::string& p_nomArme, int p_degatsMinArme, int p_degatsMaxArme) :
	Pretre(p_nom, p_nomArme, p_degatsMinArme, p_degatsMaxArme)
{
	m_vie = VIE_DRUIDE;
	m_mana = MANA_DRUIDE;
	m_arme = new Arme(NOM_ARME_DRUIDE, DEGAT_MIN_ARME_DRUIDE, DEGAT_MAX_ARME_DRUIDE);
}


/**
* \brief     : Destructeur de la classe Druide
*/
Druide::~Druide()
{
}




/*
* R�le		: Permet d'attaquer un autre personnage avec son attaque c�leste
* Entr�e	: Un objet Personne qui est la cible de l'attaque
* Sortie	: Aucune
*/
int Druide::attaqueCeleste(Personnage& p_cible)
{
	int degat(0);
	//V�rifie si la mana est assez �lev�
	if (m_mana >= COUT_ATTAQUE_CELESTE) {
		

		//Trouve un nombre de d�gats et appel la fonction de dommage
		degat = trouverAleatoire(DEGAT_MIN_CELESTE, DEGAT_MAX_CELESTE);
		p_cible.recevoirDegats(degat);
		m_mana -= COUT_ATTAQUE_CELESTE;

	}
	else {
		//Si le nombre de mana est pas assez �lev�, message d'erreur
		cout << "Vous n'avez plus de mana, vous rater votre attaque et passer votre tour." << endl;
		system("PAUSE");
	}
	return degat;
}

/*
* \brief     : m�thode virtuelle qui affiche toutes les informations du druide et masque celle du personnage
* \return    : un string qui repr�sente les informations format�es du magicien
*/
string Druide::getInfosPersonnage() const
{
	ostringstream os;
	os << accent("Je suis un puissant druide !!!") << endl;
	os << Personnage::afficherInformations();
	os<< accent("J'ai  ") << m_mana << " points de mana" << endl;
	os << "*********************************************************************" << endl;

	return os.str();
}


/**
* \brief     : m�thode virtuelle qui affiche les choix d'attaques et fait l'attaque
* \param[in] : un objet de type personnage qui repr�sente le personnage � attaquer
*/
void Druide::choixAttaque(Personnage& p_cible) {
	ostringstream os;
	int choix(0);

	cout << "Veuillez choisir votre attaque pour " << m_nom << " le " << m_classe << " : " << endl;
	os << "1. Utiliser votre arme ("<< DEGAT_MIN_ARME_DRUIDE<<" - " << DEGAT_MAX_ARME_DRUIDE<< accent(" de d�g�ts)") << endl;
	os << accent("2. Sort de gu�rison (co�t: ") << COUT_GUERISON << " mana) (" << POINT_VIE_GUERISON_MIN << " - " << POINT_VIE_GUERISON_MAX << " points de vie)" << endl;
	os << accent("3. Attaque c�lestre (co�t: ")<<COUT_ATTAQUE_CELESTE<<" mana) ("<<DEGAT_MIN_CELESTE<<" - " <<DEGAT_MAX_CELESTE <<accent(" de d�g�ts)") << endl;
	os << accent("Faites votre choix : ");

	cout << os.str();
	cin >> choix;

	// Si le joueur choisit d'utiliser son arme
	if (choix == 1) {
		//Appel de la fonction attaquer et fait apparaitre le message d'attaque
		cout << endl << endl << m_nom << accent(" utilise son ") << NOM_ARME_DRUIDE << " !!" << endl;
		cout << p_cible.getName() << accent(" re�oit ") << attaqueArme(p_cible) << accent(" de d�gats!") << endl;
		system("PAUSE");
	}

	//Si le joueur se gu�rit, appel la fonction de gu�rison
	else if (choix == 2) {
		sortGuerison();
	}

	//Si le joueur utilise son attaque c�leste
	else if (choix == 3) {
		cout << endl << endl << m_nom << accent(" utilise son attaque c�leste !!") << endl;
		cout << p_cible.getName() << accent(" re�oit ") << attaqueCeleste(p_cible) << accent(" de d�gats!") << endl;
		system("PAUSE");
		
	}
	else {
		cout << "Choix invalide, vous perdez votre tour!" << endl;
		system("PAUSE");
	}
}


/**
* \brief     : m�thode virtuelle qui affiche le message de fin des personnage
* \param[in] : un objet de type personnage qui repr�sente le personnage gagnant
*/
void Druide::messageFin(Personnage& p_cible) const {

	cout << "Le "<< m_classe << " " << m_nom << " n'a plus rien de puissant une fois mort!" << endl;
	cout << p_cible.getName() << " reste debout avec " << p_cible.getPointsdeVie() << " points de vie!" << endl;

}