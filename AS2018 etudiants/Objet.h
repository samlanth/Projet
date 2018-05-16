////////////////////////////////////////////////////////////
// Objet.h
// 
// Déclaration de la classe CObjet qui représente
// le sprite
//
// Samuel Lanthier
// Création: 2018-05-15
// - CObjet - Dérive de Sprite
////////////////////////////////////////////////////////////

#pragma once
#include <SFML/Graphics.hpp>
#include "Position.h"

//--------------------------------------------------------//
// CObjet
//--------------------------------------------------------//
// Dérive de la classe Sprite de SFML;
class CObjet : public sf::Sprite
{
	// Possède quatre (4) attributs :
private:
	// Un nom
	std::string nom;
	// Un gain en points de vie : représente le nombre de points de vie qui seront ajoutés au personnage qui ramasse cet objet(exemple : une potion);
	int GainVie;
	// Un gain en points de fortune : représente le nombre de points de fortune qui seront ajoutés au personnage qui ramasse cet objet(exemple : un trésor);
	int GainFortune;
	// Un gain en points de défense : représente le nombre de points de défense qui seront ajoutés au personnage qui ramasse cet objet(exemple : un bouclier);
	int GainDefense;

public:

	////////////////////////////////////////////////////////////
	// CObjet
	//
	// un constructeur paramétrique avec, dans l’ordre, les six (6) paramètres suivants :
	// Initialise la position de l'objet ainsi que le point d'origine qui doit être situé en bas au centre de la texture.
	//
	// Intrants :  1.	Une référence à une texture;
	//             2.	La position de l’objet sur la carte(CPosition);
	//             3.	Le nom de l’objet
	//             4.	Le gain en points de vie;
	//             5.	Le gain en points de fortune;
	//             6.	Le gain en points de défense;
	//
	////////////////////////////////////////////////////////////
    CObjet(sf::Texture& LaTexture, const CPosition& Pos, const std::string& anom, int v, int f, int d) :
        sf::Sprite(LaTexture), nom(anom), GainVie(v), GainFortune(f), GainDefense(d)
    {
        setPosition(Pos);
    }

	////////////////////////////////////////////////////////////
	// CObjet
	//
	// La methode afficher.
	// Affiche l'objet dans la fenetre
	// une référence à un RenderWindow
	// 
	//
	// Intrants : Une référence à un RenderWindow
	//
	////////////////////////////////////////////////////////////
    void Afficher(sf::RenderWindow& Fenetre)
    {
        Fenetre.draw(*this);
    }

    /*
    Les mutateurs et accesseurs jugés nécessaires;
    */
    std::string getNom() const { return nom; }
    int getGainVie() const { return GainVie; }
    int getGainFortune() const { return GainFortune; }
    int getGainDefense() const { return GainDefense; }
};

// L'opérateur << qui permet d'afficher les caractéristiques de l'objet à la console.
std::ostream& operator<<(std::ostream& os, const CObjet& h);
