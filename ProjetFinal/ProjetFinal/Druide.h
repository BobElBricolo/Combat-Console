/**
* \file    : Guerrier.h
* \brief   : Fichier qui contient l'interface de la classe Druide hérite de la classe Pretre.
* \date    : 8 mai 2020
* \auteur  : Alexis Young et Timothé St-Pierre
*/


#pragma once
#include "Pretre.h"

class Druide :
    public Pretre
{
public:
    // Constructeurs
    Druide(const std::string& p_nom);
    Druide(const std::string& p_nom, const std::string& p_nomArme, int p_degatsMinArme, int p_degatsMaxArme);
   
    //Destructeur
    ~Druide();

    int attaqueCeleste(Personnage& p_cible);

    virtual std::string getInfosPersonnage() const;
    virtual void choixAttaque(Personnage& p_cible);
    virtual void messageFin(Personnage& p_cible) const;

protected:

};

