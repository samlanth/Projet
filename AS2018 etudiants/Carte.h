////////////////////////////////////////////////////////////
// Carte.h
//
// D�claration de la classe CCarte qui repr�sente le monde
// dans lequel �voluent les personnages et les objets
// 
// Joan-S�bastien Morales 
// Cr�ation: 28 avril 2010
// Version 1.0
// Version 1.1 - Bloquer la copie
// Version 2.0 - 9 mai 2014 Adaptation � SFML - Carte d�rive de Sprite
////////////////////////////////////////////////////////////
#pragma once

#include <SFML/Graphics.hpp>
#include "Position.h"

//--------------------------------------------------------//
// CCarte
//--------------------------------------------------------//
class CCarte: public sf::Sprite
{
public:
	////////////////////////////////////////////////////////////
	// CCarte
	// Constructeur param�trique
	//
	// Intrants: 
	// Texture: Texture contenant l'image du monde 
	//                  
	// Obstruction: L'image d'obstruction est une version de
	//              l'image du monde o� les pixels
	//              o� les personnages peuvent passer
	//              sont de couleurs noires(RGB 0,0,0)
	////////////////////////////////////////////////////////////
	CCarte(sf::Texture& LaTexture, sf::Image& Obstruction);

	////////////////////////////////////////////////////////////
	// Afficher
	// Affiche la carte dans une fen�tre
	//
	// Intrant: Fenetre: Fen�tre dans laquelle la carte doit
	//                    �tre affich�e
	////////////////////////////////////////////////////////////
	void Afficher(sf::RenderWindow& Fenetre);

	////////////////////////////////////////////////////////////
	// EstPositionValide
	// Permet de v�rifier si un personnage peut se trouver �
	// une certain position sur la carte
	//
	// Intrant: Position: Position du personnage
	//
	// Extrant: Vrai si le personnage peut se trouver � cette
	//          position sur la carte, faux dans le cas 
	//          contraire
	////////////////////////////////////////////////////////////
	bool EstPositionValide(const CPosition& Position);


private:
	// Bloquer la copie
	CCarte(const CCarte&);
	CCarte& operator=(const CCarte&);

	// Image d'obstruction
	sf::Image& Obstruction_;
};
