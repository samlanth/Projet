////////////////////////////////////////////////////////////
// Monstre.h
// 
// Déclaration de la classe CMonstre qui représente
// les monstres
//
// Samuel Lanthier
// Création: 2018-05-15
// - CMonstre - Dérive de CPersonnage
////////////////////////////////////////////////////////////

#pragma once
#include <SFML/Graphics.hpp>
#include "Position.h"
#include "Carte.h"
#include "Personnage.h"
#include "Heros.h"

//--------------------------------------------------------//
// CMonstre
//--------------------------------------------------------//
class CMonstre : public CPersonnage
{
	
private:
	// // Le nombre de tours pendant lesquels le monstre continuera d’avancer dans la direction qu’il a choisie(voir détails plus bas).
	int NombreTours;
    int NombreToursAFaire;

public:
	////////////////////////////////////////////////////////////
	// CMonstre
	//
	// un constructeur paramétrique qui prend les mêmes trois (3) paramètres et dans le même ordre que le constructeur paramétrique de la classe CPersonnage;
	// 
	//
	// Intrants : Une référence à une texture;
	//			  La position du personnage sur la carte(CPosition);
	//            Le nom du personnage;
	//
	////////////////////////////////////////////////////////////
    CMonstre(sf::Texture& LaTexture, const CPosition& Pos, std::string nom);


	////////////////////////////////////////////////////////////
	// CMonstre
	//
	// Redéfinit la méthode Déplacer :
	// La méthode Deplacer calcule une nouvelle position en fonction de la touche appuyée par le joueur(voir la classe Keyboard de SFML) :
	// 
	//
	// Intrants : une référence à une carte en paramètre
	//			  La direction du personnage :
	//			  Vers le bas : la position y est augmentée de VitesseHeros (Constantes.h)
	//			  Vers le haut : la position y est diminuée de VitesseHeros
	//            Vers la droite : la position x est augmentée de VitesseHeros
	//	          Vers la gauche : la position x est diminuée de VitesseHeros
	//
	// Extrants : La méthode retourne true si le joueur a appuyé sur la touche Échappement, sinon elle retourne false.
	//
	////////////////////////////////////////////////////////////
    bool Deplacer(const CCarte& carte, Direction d) override { return false; }

    bool DeplacerVers(const CCarte& carte, Direction d, CPosition posHero) override;

	////////////////////////////////////////////////////////////
	// CMonstre
	//
	// La fonction virtuelle pure  Attaquer
	// qui prend une référence à un objet de la classe CHeros, et qui retourne true ou false;
	// 
	//
	// Intrants : Qui prend une référence à un objet de 
	//            la classe CHeros
	//
	//
	////////////////////////////////////////////////////////////
    virtual bool Attaquer(CHeros& objet) = 0;

    // Calculer new position selon direction
    CPosition getnewPos(Direction d);
};