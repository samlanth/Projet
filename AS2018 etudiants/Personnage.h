////////////////////////////////////////////////////////////
// Personnage.h
// 
// D�claration de la classe CPersonnage qui repr�sente
// toute les personnages
//
// Samuel Lanthier
// Cr�ation: 2018-05-15
// - CPersonnage - D�rive de CAnimation
////////////////////////////////////////////////////////////
/*
	D�clare la fonction virtuelle pure  Deplacer qui prend une r�f�rence � un objet de la classe CCarte ainsi que la position du h�ros, et qui retourne true ou false;
	Les mutateurs et accesseurs jug�s n�cessaires;
*/
#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Position.h"
#include "Carte.h"

//--------------------------------------------------------//
// CPersonnage
//--------------------------------------------------------//
// 	D�rive de la classe CAnimation.
class CPersonnage : public CAnimation
{
	// 	Poss�de un seul attribut :
private:
	// Un nom.
	std::string nom;

public:
	////////////////////////////////////////////////////////////
	// CPersonnage
	//
	// Un constructeur param�trique avec, dans l�ordre, les trois (3) param�tres suivants :
	// 
	//
	// Intrants : 1.	Une r�f�rence � une texture;
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
	// La m�thode Deplacer calcule une nouvelle position en fonction de la touche appuy�e par le joueur(voir la classe Keyboard de SFML) :
	// 
	//
	// Intrants : une r�f�rence � une carte en param�tre
	//			  La direction du personnage :
	//			  Vers le bas : la position y est augment�e de VitesseHeros (Constantes.h)
	//			  Vers le haut : la position y est diminu�e de VitesseHeros
	//            Vers la droite : la position x est augment�e de VitesseHeros
	//	          Vers la gauche : la position x est diminu�e de VitesseHeros
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
