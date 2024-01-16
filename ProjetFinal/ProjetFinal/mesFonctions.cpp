/**
* \file    : mesFonctions.h
* \brief   : Fichier qui contient le prototypes de mes fonctions.
* \date    : 8 mai  2021
* \auteur  : Alexis Young et Timothé St-Pierre
*/

#include <string>
#include <Windows.h>
#include <iostream>
#include <sstream>


using namespace std;


/*
* Rôle : Transformer les accents pour la console Windows
* Entrée : Tableau de caractère à convertir
* Sortie : Chaîne de caractère convertie
*/
string accent(const char p_tab[]) {
	char buffer[256];
	CharToOemA(p_tab, buffer);
	string str(buffer);
	return str;
}


/*
Role	: Trouve un nombre aléatoire entre le min et le max
Entrée1 : Un entier qui représente le nombre minimum possible
Entrée2 : Un entier qui représente le nombre maximum possible
Sortie	: Un entier qui représente le nombre aléatoire contenu
		  entre le minimum et le maximum
*/
int trouverAleatoire(int p_min, int p_max) {
	int nombre;
	nombre = (rand() % ((p_max - p_min) + 1)) + p_min;
	return nombre;
}


/*
* Rôle		: Affichage de l'introduction
* Entrée	: Aucune
* Sortie	: Aucune
*/
void intro() {

	ostringstream os;
	os << "***************************************************************************************" << endl;

	os << accent("Bienvenue dans le combat incroyable!!!!") << endl;
	os << accent("Vous allez être confronté dans un 1v1 ÉPIQUE!") << endl;
	os << accent("Ce combat ne verra sa fin qu'une fois la dernière goutte de sang écoulée.") << endl << endl;
	os << accent("Vous pouvez incarner 1 des 3 rôles :") << endl;
	
	os << accent("1 - Un guerrier qui possède beaucoup d'endurance et de puissantes attaques physiques.") << endl;
	os << accent("2 - Un prêtre qui possède des pouvoirs de guérison, une bonne arme et une bonne endurance.") << endl;
	os << accent("3 - Un druide moins endurant pouvant également se guérir et possède une puissante attaque magique.") << endl << endl;

	os << accent("À vous de faire votre choix. ") << endl;
	os << "***************************************************************************************" << endl;
	cout << os.str() << endl;

	system("PAUSE");
	
}

/*
* Rôle		: Récupération du nom du joueur
* Entrée	: Int représentant le numéro du joueur
* Sortie	: String représentant le nom du joueur
*/
string choixNom(int p_nombre) {
	string nom("");
	
	cout << "Joueur #" << p_nombre << " entrez le nom de votre personnage: " << endl;
	cin >> nom;

	return nom;
}


/*
* Rôle		: Récupération du nom du joueur
* Entrée	: Aucune
* Sortie	: Int représentant le numéro de la classe du joueur
*/
int choixClasse() {
	int choix(0);

	cout << accent("Veuillez choisir votre classe!") << endl;
	cout << "1 - Guerrier" << endl;
	cout << accent("2 - Prêtre") << endl;
	cout << "3 - Druide" << endl<< endl;
	cout << "Faites votre choix : ";
	cin >> choix;
	cout << "***************************************************************************************" << endl;
	
	return choix;
}