/**
* \file    : main.cpp
* \brief   : Projet final
* \date    : 8 mai 2021
* \auteur  : Alexis Young et Timoth� St-Pierre
*/

#include <iostream>
#include <vector>
#include "Personnage.h"
#include "Guerrier.h"
#include "Pretre.h"
#include "Druide.h"
#include "mesFonctions.h"
#include <ctime>

using namespace std;

int main() {

	bool vivant(true);
	const int NB_PERSONNAGES = 2;
	string nomJoueur;
	int classe(0);
	int nbRonde(0);

	//Permet de modifier le nombre al�atoire
	srand(time(NULL));
	
	//Cr�ation de la collection h�t�rog�ne qui contient l'adresse de mes personnages
	vector<Personnage*> listePersonnages;

	//Fonction d'introduction
	intro();

	//Cr�ation des deux personnages et ajout dans le vector
	for (unsigned int i = 0; i < NB_PERSONNAGES; i++)
	{
		nomJoueur = choixNom(i+1);
		classe = choixClasse();
		switch (classe)
		{
		case 1:
			listePersonnages.push_back(new Guerrier(nomJoueur));
			break;
		case 2:
			listePersonnages.push_back(new Pretre(nomJoueur));
			break;
		case 3:
			listePersonnages.push_back(new Druide(nomJoueur));
			break;
		}
	}

	cout << accent("Les combattants sont maintenant par�s au combat!!") << endl;
	system("PAUSE");
	system("cls");

	do {
		nbRonde++;//Augmente le num�ro de la ronde

		//Affiche les informations des personnages
		cout << listePersonnages[0]->getInfosPersonnage();
		cout << listePersonnages[1]->getInfosPersonnage();

		cout << "Ronde de combat #" << nbRonde << endl;

		//Choix de l'attaque du premier personnage
		listePersonnages[0]->choixAttaque(*listePersonnages[1]);
		
		system("cls");

		//V�rifie si les joueurs sont toujours vivant
		if (listePersonnages[0]->estVivant() == false || listePersonnages[1]->estVivant() == false) {
		vivant = false;
		}

		else {
			//S'ils sont toujours vivant
			system("cls");
			
			//Affiche les informations des personnages
			cout << listePersonnages[0]->getInfosPersonnage();
			cout << listePersonnages[1]->getInfosPersonnage();

			cout << "Ronde de combat #" << nbRonde << endl;
			
			//Choix de l'attaque du deuxi�me personnage
			listePersonnages[1]->choixAttaque(*listePersonnages[0]);

			system("cls");
		}

		//V�rifie si les joueurs sont toujours vivant
		if (listePersonnages[0]->estVivant() == false || listePersonnages[1]->estVivant() == false) {
			vivant = false;
		}
		else {

			//S'ils sont toujours vivant, passage � la ronde suivante
			cout << endl << endl << "Fin de la ronde #" << nbRonde << endl;
			cout << accent("Passage � la suivante!!!") << endl << endl;
			system("PAUSE");
			system("cls");
		}
		
	} while (vivant == true);


	//V�rifie quel joueur est encore vivant et fait appara�tre le message
	if (listePersonnages[0]->estVivant() == false) {
		listePersonnages[0]->messageFin(*listePersonnages[1]);
	}
	else if (listePersonnages[1]-> estVivant() == false) {
		listePersonnages[1]->messageFin(*listePersonnages[0]);
	}

	//Lib�ration de la m�moire pour les adresses de nos personnages dans le vecteur
	for (unsigned int i = 0; i < listePersonnages.size(); i++)
	{
		delete listePersonnages[i];
		listePersonnages[i] = 0;
	}


	system("PAUSE");
	return 0;
}




