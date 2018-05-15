////////////////////////////////////////////////////////////
// Brute.h
// 
// Déclaration de la classe CBrute qui représente
// un type de monstre
//
// Samuel Lanthier
// Création: 2018-05-15
// - CBrute - Dérive de CMonstre
////////////////////////////////////////////////////////////

#pragma once
#include <SFML/Graphics.hpp>
#include "Position.h"
#include "Carte.h"
#include "Personnage.h"
#include "Heros.h"
#include "Monstre.h"

//--------------------------------------------------------//
// CBrute
//--------------------------------------------------------//
// Dérive de la classe CMonstre;
class CBrute : public CMonstre
{
private:
	// Ne possède aucun attribut
public:
	////////////////////////////////////////////////////////////
	// CBrute
	//
	// Un constructeur paramétrique qui prend les mêmes trois(3) paramètres
	// et dans le même ordre que le constructeur paramétrique de la classe CMonstre;
	//
	// Intrants : Texture, position, et le nom
	//
	////////////////////////////////////////////////////////////
    CBrute(sf::Texture& LaTexture, const CPosition& Pos, std::string nom);

	////////////////////////////////////////////////////////////
	// CBrute
	//
	// Redéfinit la méthode Attaquer qui prend une référence à un héros en paramètre
	// et qui retourne true ou false
	// La méthode Attaquer vérifie dans un premier temps si l’ennemi passé en paramètre
	// est proche(voir la classe CPosition).Si c’est le cas, alors il y a une attaque.
	// Si le Héros possède de la Défense, la Brute lui en enlève un point.
	// Sinon, la Brute lui enlève un point de Vie
	// Si le Héros est mort(s’il n’a plus de points de vie), la méthode retourne false,
	// sinon elle retourne true.De plus, la méthode doit afficher à la console tous les
	// détails de l’attaque ainsi que les caractéristiques finales du Héros
	//
	// Intrants : une référence à un héros en paramètre
	//			  et qui retourne true ou false
	//
	// Extrant: Si le Héros est mort(s’il n’a plus de points de vie), la méthode retourne false,
	//			sinon elle retourne true
	////////////////////////////////////////////////////////////
    virtual bool Attaquer(CHeros& hero);
};

std::ostream& operator<<(std::ostream& os, const CBrute& h);
