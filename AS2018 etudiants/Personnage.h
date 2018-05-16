////////////////////////////////////////////////////////////
// Personnage.h
// 
// Déclaration de la classe CPersonnage qui représente
// toute les personnages
//
// Samuel Lanthier
// Création: 2018-05-15
// - CPersonnage - Dérive de CAnimation
////////////////////////////////////////////////////////////
/*
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
// 	Dérive de la classe CAnimation.
class CPersonnage : public CAnimation
{
	// 	Possède un seul attribut :
private:
	// Un nom.
	std::string nom;

public:
	////////////////////////////////////////////////////////////
	// CPersonnage
	//
	// Un constructeur paramétrique avec, dans l’ordre, les trois (3) paramètres suivants :
	// 
	//
	// Intrants : 1.	Une référence à une texture;
    //	          2.	La position du personnage sur la carte(CPosition);
	//            3.	Le nom du personnage;
	//
	////////////////////////////////////////////////////////////
    CPersonnage(sf::Texture& LaTexture, const CPosition& Pos, const std::string& anom) :  
        CAnimation(LaTexture, Pos), nom(anom)
    {
    }

	////////////////////////////////////////////////////////////
	// CMonstre
	//
	// fonction virtuelle pure  Deplacer
	// La méthode Deplacer calcule une nouvelle position en fonction de la touche appuyée par le joueur(voir la classe Keyboard de SFML) :
	// 
	//
	// Intrants : une référence à une carte en paramètre
	//			  La direction du personnage :
	//			  Vers le bas : la position y est augmentée de VitesseHeros (Constantes.h)
	//			  Vers le haut : la position y est diminuée de VitesseHeros
	//            Vers la droite : la position x est augmentée de VitesseHeros
	//	          Vers la gauche : la position x est diminuée de VitesseHeros
	//			  retourne true ou false
	//
	////////////////////////////////////////////////////////////
	virtual bool Deplacer(const CCarte& objet, Direction d) = 0;

    virtual bool DeplacerVers(const CCarte& objet, Direction d, CPosition pos) = 0;
	
	// Methode setNom
	// 
	// accesseur necessaire
	// intrants : un nom.
    void setNom(const std::string& anom)
    {
        nom = anom;
    }

	// Methode getNom
	// 
	// mutateur necessaire
    std::string getNom() const
    {
        return nom;
    }
};
