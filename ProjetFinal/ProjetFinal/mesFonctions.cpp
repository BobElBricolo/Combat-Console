/**
* \file    : mesFonctions.h
* \brief   : Fichier qui contient le prototypes de mes fonctions.
* \date    : 8 mai  2021
* \auteur  : Alexis Young et Timoth� St-Pierre
*/

#include <string>
#include <Windows.h>
#include <iostream>
#include <sstream>


using namespace std;


/*
* R�le : Transformer les accents pour la console Windows
* Entr�e : Tableau de caract�re � convertir
* Sortie : Cha�ne de caract�re convertie
*/
string accent(const char p_tab[]) {
	char buffer[256];
	CharToOemA(p_tab, buffer);
	string str(buffer);
	return str;
}


/*
Role	: Trouve un nombre al�atoire entre le min et le max
Entr�e1 : Un entier qui repr�sente le nombre minimum possible
Entr�e2 : Un entier qui repr�sente le nombre maximum possible
Sortie	: Un entier qui repr�sente le nombre al�atoire contenu
		  entre le minimum et le maximum
*/
int trouverAleatoire(int p_min, int p_max) {
	int nombre;
	nombre = (rand() % ((p_max - p_min) + 1)) + p_min;
	return nombre;
}


/*
* R�le		: Affichage de l'introduction
* Entr�e	: Aucune
* Sortie	: Aucune
*/
void intro() {

	ostringstream os;
	os << "***************************************************************************************" << endl;

	os << accent("Bienvenue dans le combat incroyable!!!!") << endl;
	os << accent("Vous allez �tre confront� dans un 1v1 �PIQUE!") << endl;
	os << accent("Ce combat ne verra sa fin qu'une fois la derni�re goutte de sang �coul�e.") << endl << endl;
	os << accent("Vous pouvez incarner 1 des 3 r�les :") << endl;
	
	os << accent("1 - Un guerrier qui poss�de beaucoup d'endurance et de puissantes attaques physiques.") << endl;
	os << accent("2 - Un pr�tre qui poss�de des pouvoirs de gu�rison, une bonne arme et une bonne endurance.") << endl;
	os << accent("3 - Un druide moins endurant pouvant �galement se gu�rir et poss�de une puissante attaque magique.") << endl << endl;

	os << accent("� vous de faire votre choix. ") << endl;
	os << "***************************************************************************************" << endl;
	cout << os.str() << endl;

	system("PAUSE");
	
}

/*
* R�le		: R�cup�ration du nom du joueur
* Entr�e	: Int repr�sentant le num�ro du joueur
* Sortie	: String repr�sentant le nom du joueur
*/
string choixNom(int p_nombre) {
	string nom("");
	
	cout << "Joueur #" << p_nombre << " entrez le nom de votre personnage: " << endl;
	cin >> nom;

	return nom;
}


/*
* R�le		: R�cup�ration du nom du joueur
* Entr�e	: Aucune
* Sortie	: Int repr�sentant le num�ro de la classe du joueur
*/
int choixClasse() {
	int choix(0);

	cout << accent("Veuillez choisir votre classe!") << endl;
	cout << "1 - Guerrier" << endl;
	cout << accent("2 - Pr�tre") << endl;
	cout << "3 - Druide" << endl<< endl;
	cout << "Faites votre choix : ";
	cin >> choix;
	cout << "***************************************************************************************" << endl;
	
	return choix;
}