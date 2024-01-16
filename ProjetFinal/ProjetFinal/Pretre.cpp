/**
* \fichier    : Pretre.cpp
* \brief      : Impl�mentation de la classe Pretre
* \date       : 8 mai 2020
* \author     : Alexis Young et Timoth� St-Pierre
*/

#include "Personnage.h"
#include "Pretre.h"
#include "mesFonctions.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const int VIE_PRETRE =70;
const int VIE_MAX = 70;
const int MANA = 15;
const string NOM_ARME_PRETRE = "Marteau";
const int DEGAT_MAX_ARME_PRETRE = 15;
const int DEGAT_MIN_ARME_PRETRE = 10;
const int COUT_GUERISON = 5;
const int POINT_VIE_GUERISON_MAX = 20;
const int POINT_VIE_GUERISON_MIN = 10;


/**
* \brief     : Constructeur avec un nom
* \param[in] : un string qui repr�sente le nom du guerrier
*/
Pretre::Pretre(const std::string& p_nom) : Personnage(p_nom, NOM_ARME_PRETRE, DEGAT_MIN_ARME_PRETRE, DEGAT_MAX_ARME_PRETRE), m_mana(MANA)//Constructeur
{	
	m_classe = accent("Pr�tre");
	m_vie = VIE_PRETRE;
	m_arme = new Arme(NOM_ARME_PRETRE, DEGAT_MIN_ARME_PRETRE, DEGAT_MAX_ARME_PRETRE);
}


/**
* \brief     : Constructeur surcharg�
* \param[in] : un string qui repr�sente le nom de mon pr�tre
* \param[in] : un string qui repr�sente le nom de l'arme
* \param[in] : un entier qui repr�sente le d�gat fait par l'arme
*/
Pretre::Pretre(const std::string& p_nom, const std::string& p_nomArme, int p_degatsMinArme, int p_degatsMaxArme) :
	Personnage(p_nom, p_nomArme, p_degatsMinArme, p_degatsMaxArme), m_mana(MANA) 
{
	m_vie = VIE_PRETRE;
	m_arme = new Arme(NOM_ARME_PRETRE, DEGAT_MIN_ARME_PRETRE, DEGAT_MAX_ARME_PRETRE);
}


/**
* \brief     : Destructeur de la classe Pretre
*/
Pretre::~Pretre()
{

}


/*
* R�le		: Permet d'augmenter le nombre de points de vie du personnage en fonction de la potion
* Entr�e	: Un entier qui repr�sente le nombre de points recup�r�s
* Sortie	: Aucune
*/
void Pretre::sortGuerison()
{
	int viePlus(0);
	//V�rifie si la mana est assez �lev�
	if (m_mana >= COUT_GUERISON) {

		//Trouve un nombre de soins et appel la fonction de gu�rison
		viePlus = trouverAleatoire(POINT_VIE_GUERISON_MIN, POINT_VIE_GUERISON_MAX);
		m_vie += viePlus;

		//V�rifie si la vie est au maximum et affiche le message en cons�quence
		if (m_vie <= VIE_MAX) {
			cout << endl << endl << m_nom << accent(" re�oit ") << viePlus << accent(" de points de vie, il est d�sormais �  ") << m_vie << endl;
			system("PAUSE");
		}
		else {
			m_vie = VIE_MAX;
			cout << endl << endl << m_nom << accent(" a atteint le maximum de vie, il est donc � ") << m_vie << endl;
			system("PAUSE");
		}
		//R�duit la mana
		m_mana -= COUT_GUERISON;
	}
	else {
		//Apparition du message d'erreur
		cout << "Vous n'avez plus de mana, vous rater votre attaque et passer votre tour." << endl;
		system("PAUSE");
	}
}


/*
* R�le : Accesseur de l'attribut m_mana
* Entr�e : Aucune
* Sortie : Un entier qui repr�sente le nombre de points de vie du personnage
*/
int Pretre::getPointsMana() const
{
	return m_mana;
}


/*
* \brief     : m�thode virtuelle qui affiche toutes les informations du druide et masque celle du personnage
* \return    : un string qui repr�sente les informations format�es du magicien
*/
string Pretre::getInfosPersonnage() const
{
	ostringstream os;
	os << accent("Je suis un pr�tre magnifique!!!") << endl;
	//Appel la fonction d'affichage de personnage
	os << Personnage::afficherInformations();
	os << accent("Je poss�de ") << m_mana << " points de mana " << endl;
	os << "*********************************************************************" << endl;
	return os.str();
}


/*
* R�le		: Affichage des choix d'attaque
* Entr�e	: aucune
* Sortie	: Int d�tenant le choix de l'utilisateur
*/
void Pretre::choixAttaque(Personnage& p_cible) {
	ostringstream os;
	int choix(0);

	cout << "Veuillez choisir votre attaque pour " << m_nom << " le " << m_classe << " : " << endl;
	os << "1. Utiliser votre arme (" << DEGAT_MIN_ARME_PRETRE << " - " <<DEGAT_MAX_ARME_PRETRE<< accent(" de d�g�ts)") << endl;
	os << accent("2. Sort de gu�rison (co�t: ") << COUT_GUERISON << " mana) (" << POINT_VIE_GUERISON_MIN << " - " << POINT_VIE_GUERISON_MAX << " points de vie)" << endl;
	os << accent("Faites votre choix : ");
	
	cout << os.str();
	cin >> choix;

	// Si le joueur choisit d'utiliser son arme
	if (choix == 1) {
		//Appel de la fonction attaquer et fait apparaitre le message d'attaque
		cout << endl << endl << m_nom << accent(" utilise son ") << NOM_ARME_PRETRE << " !!" << endl;
		cout << p_cible.getName() << accent(" re�oit ") << attaqueArme(p_cible) << accent(" de d�gats!") << endl;
		system("PAUSE");
	}

	//Si le joueur se gu�rit, appel la fonction de gu�rison
	else if (choix == 2) {
		sortGuerison();
	}
	else {
		//Message d'erreur
		cout << "Choix invalide, vous perdez votre tour!" << endl;
		system("PAUSE");
	}
	
}


/**
* \brief     : m�thode virtuelle qui affiche le message de fin des personnage
* \param[in] : un objet de type personnage qui repr�sente le personnage gagnant
*/
void Pretre::messageFin(Personnage& p_cible) const{
	
	cout << "Le " << m_classe << m_nom << " n'a plus rien de magnifique dans sa tombe!" << endl;
	cout << p_cible.getName() << " reste debout avec " << p_cible.getPointsdeVie() << " points de vie!" << endl;

}