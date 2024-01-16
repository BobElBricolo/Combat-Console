/**
* \fichier    : Guerrier.cpp
* \brief      : Implémentation de la classe Guerrier
* \date       : 8 mai 2020
* \author     : Alexis Young et Timothé St-Pierre
*/


#include <iostream>
#include <string>
#include <sstream>
#include "mesFonctions.h"
#include "Guerrier.h"

using namespace std;

const int VIE_GUERRIER = 80;
const string NOM_ARME_GUERRIER = accent("Épée double");
const int DEGAT_MAX_ARME_GUERRIER = 20;
const int DEGAT_MIN_ARME_GUERRIER = 5;
const int DEGAT_MAX_CHARGE = 30;
const int DEGAT_MIN_CHARGE = 10;
bool usageCharge(false);

/**
* \brief     : Constructeur avec un nom
* \param[in] : un string qui représente le nom du guerrier
*/
Guerrier::Guerrier(const std::string& p_nom) : Personnage(p_nom)
{
	m_classe = "Guerrier";
	m_vie = VIE_GUERRIER;
	m_arme = new Arme(NOM_ARME_GUERRIER, DEGAT_MIN_ARME_GUERRIER, DEGAT_MAX_ARME_GUERRIER);
}

/**
* \brief     : Constructeur surchargé
* \param[in] : un string qui représente le nom de mon guerrier
* \param[in] : un string qui représente le nom de l'arme
* \param[in] : un entier qui représente le dégat fait par l'arme
*/
Guerrier::Guerrier(const std::string& p_nom, const std::string& p_nomArme, int p_degatsMinArme, int p_degatsMaxArme) :
	Personnage(p_nom, p_nomArme, p_degatsMinArme, p_degatsMaxArme)
{
	m_vie = VIE_GUERRIER;
	m_arme = new Arme(NOM_ARME_GUERRIER, DEGAT_MIN_ARME_GUERRIER, DEGAT_MAX_ARME_GUERRIER);
}

/**
* \brief     : Destructeur de la classe Guerrier
*/
Guerrier::~Guerrier()
{

}

/**
* \brief     : attaque spéciale du guerrier sur une cible
* \param[in] : un objet de type personnage qui représente la cible de l'attaque
*/
void Guerrier::chargePercutante(Personnage& p_cible) const
{
	int degat = trouverAleatoire(DEGAT_MIN_CHARGE, DEGAT_MAX_CHARGE);
	p_cible.recevoirDegats(degat);
	cout << endl << endl << "Votre charge percutante inflige " << degat << accent(" points de dégâts") << endl;
	system("PAUSE");
}

/**
* \brief     : méthode virtuelle qui offre les options d'attaque du guerrier et fait l'attaque
* \param[in] : un objet de type personnage qui représente la cible de l'attaque
*/
void Guerrier::choixAttaque(Personnage& p_cible)
{

	int choix(0);

	//Vérifie si la charge a été utilisé
	if (usageCharge == false) {
		cout << "Veuillez choisir votre attaque pour " << m_nom << " le " << m_classe << " : " << endl;
		cout << "1- Effectuer une charge percutante ("<<DEGAT_MIN_CHARGE<<" - " << DEGAT_MAX_CHARGE<< accent(" points de dégats)") << endl;
		cout << accent("2- Attaquer à l'aide de votre arme (") << DEGAT_MIN_ARME_GUERRIER << " - " << DEGAT_MAX_ARME_GUERRIER << accent(" points de dégats)") << endl;
		cout << "Faites votre choix : ";
		cin >> choix;

		//Choix de l'attaque selon l'utilisateur
		switch (choix)
		{
		case 1:
			//Appel de la fonction charge percutante
			chargePercutante(p_cible);

			//Défini la charge comme étant utilisée
			usageCharge = true;
			break;

		case 2:
			//Utilisiation de l'arme
			cout << endl << endl << m_nom << accent(" utilise son ") << NOM_ARME_GUERRIER << " !!" << endl;
			cout << p_cible.getName() << accent(" reçoit ") << attaqueArme(p_cible) << accent(" de dégats!") << endl;
			system("PAUSE");
			break;
		default:
			//Apparition du message d'erreur
			cout << "Choix non-valide, vous perdez votre tour!" << endl;
			system("PAUSE");
		}
	}
	else {
		//Si la charge a déjà été utilisée, modifie les choix d'attaques
		cout << "Veuillez choisir votre attaque pour " << m_nom << " le " << m_classe << " : " << endl;
		cout << accent("1- Votre charge percutente a déjà été utilisée, impossible de la réutiliser") << endl;
		cout << accent("2- Attaquer à l'aide de votre arme (") << DEGAT_MIN_ARME_GUERRIER << " - " << DEGAT_MAX_ARME_GUERRIER << accent(" points de dégats)") << endl;
		cout << "Faites votre choix : ";
		cin >> choix;

		switch (choix)
		{
		
		case 2:
			//Attaque de l'arme
			cout << endl << endl << m_nom << accent(" utilise son ") << NOM_ARME_GUERRIER << " !!" << endl;
			cout << p_cible.getName() << accent(" reçoit ") << attaqueArme(p_cible) << accent(" de dégats!") << endl;
			system("PAUSE");
			break;
		
		default:
			//Apparition du message d'erreur
			cout << "Choix non-valide, vous perdez votre tour" << endl;
			system("PAUSE");
		}
	}
	
}

/**
* \brief     : méthode virtuelle qui affiche toutes les informations du guerrier
* \return    : un string qui représente les informations formatées du guerrier
*/
std::string Guerrier::getInfosPersonnage() const
{
	ostringstream os;
	os << "Je suis un puissant guerrier !!!" << endl;
	//Appel la fonction d'affichage de personnage
	os << Personnage::afficherInformations();
	os << "*********************************************************************" << endl;

	return os.str();
}


/**
* \brief     : méthode virtuelle qui affiche le message de fin des personnage
* \param[in] : un objet de type personnage qui représente le personnage gagnant
*/
void Guerrier::messageFin(Personnage& p_cible) const {

	cout << "Le " << m_classe << m_nom << " est tombé au combat!" << endl;
	cout << p_cible.getName() << " reste debout avec " << p_cible.getPointsdeVie() << " points de vie!" << endl;

}