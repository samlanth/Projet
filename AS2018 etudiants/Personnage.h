/*
La classe CPersonnage

	D�rive de la classe CAnimation.
	Poss�de un seul attribut :
1.	Un nom.
	Poss�de un constructeur param�trique avec, dans l�ordre, les trois (3) param�tres suivants :
1.	Une r�f�rence � une texture;
2.	La position du personnage sur la carte (CPosition);
3.	Le nom du personnage;
	D�clare la fonction virtuelle pure  Deplacer qui prend une r�f�rence � un objet de la classe CCarte ainsi que la position du h�ros, et qui retourne true ou false;
	Les mutateurs et accesseurs jug�s n�cessaires;
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
	//1.	Une r�f�rence � une texture;
	//2.	La position du personnage sur la carte(CPosition);
	//3.	Le nom du personnage;

	CPersonnage(sf::Texture& LaTexture, const CPosition& Pos, std::string nom);

	//D�clare la fonction virtuelle pure  Deplacer qui prend
	//une r�f�rence � un objet de la classe CCarte ainsi que
	//la position du h�ros, et qui retourne true ou false;
	virtual bool Deplacer(const CCarte& objet) = 0;
};