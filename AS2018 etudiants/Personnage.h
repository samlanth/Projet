////////////////////////////////////////////////////////////
// Personnage.h
// 
// Déclaration de la classe CPersonnage qui représente
// toute les personnages
//
// Samuel Lanthier
// Création: 2018-05-15
// - CAnimation - Dérive de CAnimation
////////////////////////////////////////////////////////////
/*
La classe CPersonnage

	Dérive de la classe CAnimation.
	Possède un seul attribut :
1.	Un nom.
	Possède un constructeur paramétrique avec, dans l’ordre, les trois (3) paramètres suivants :
1.	Une référence à une texture;
2.	La position du personnage sur la carte (CPosition);
3.	Le nom du personnage;
	Déclare la fonction virtuelle pure  Deplacer qui prend une référence à un objet de la classe CCarte ainsi que la position du héros, et qui retourne true ou false;
	Les mutateurs et accesseurs jugés nécessaires;
*/
#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Position.h"
#include "Carte.h"

//--------------------------------------------------------//
// CPersonnage
//--------------------------------------------------------//
class CPersonnage : public CAnimation
{
private:
	std::string nom;

public:
	//1.	Une référence à une texture;
	//2.	La position du personnage sur la carte(CPosition);
	//3.	Le nom du personnage;

    CPersonnage(sf::Texture& LaTexture, const CPosition& Pos, const std::string& anom) :  
        CAnimation(LaTexture, Pos), nom(anom)
    {
    }

	//Déclare la fonction virtuelle pure  Deplacer qui prend
	//une référence à un objet de la classe CCarte ainsi que
	//la position du héros, et qui retourne true ou false;
	virtual bool Deplacer(const CCarte& objet, Direction d) = 0;

    virtual bool DeplacerVers(const CCarte& objet, Direction d, CPosition pos) = 0;

    void setNom(const std::string& anom)
    {
        nom = anom;
    }

    std::string getNom() const
    {
        return nom;
    }
};
