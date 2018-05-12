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
#include "Position.h"
#include "Carte.h"
//--------------------------------------------------------//
// CPersonnage
//--------------------------------------------------------//
class CPersonnage : public CPosition
{
private:
	std::string Nom_;

public:
	//1.	Une référence à une texture;
	//2.	La position du personnage sur la carte(CPosition);
	//3.	Le nom du personnage;

	CPersonnage(sf::Texture& LaTexture, const CPosition& Pos, std::string nom);

	//Déclare la fonction virtuelle pure  Deplacer qui prend
	//une référence à un objet de la classe CCarte ainsi que
	//la position du héros, et qui retourne true ou false;
	virtual bool Deplacer(const CCarte& objet) = 0;
};
