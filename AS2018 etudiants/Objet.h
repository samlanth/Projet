/*
La classe CObjet

	Dérive de la classe Sprite de SFML;
	Possède quatre (4) attributs :
1.	Un Nom;
2.	Un gain en points de vie: représente le nombre de points de vie qui seront ajoutés au personnage qui ramasse cet objet (exemple : une potion);
3.	Un gain en points de fortune: représente le nombre de points de fortune qui seront ajoutés au personnage qui ramasse cet objet (exemple : un trésor);
4.	Un gain en points de défense: représente le nombre de points de défense qui seront ajoutés au personnage qui ramasse cet objet (exemple : un bouclier);
	 Possède un constructeur paramétrique avec, dans l’ordre, les six (6) paramètres suivants :
1.	Une référence à une texture;
2.	La position de l’objet sur la carte (CPosition);
3.	Le nom de l’objet
4.	Le gain en points de vie;
5.	Le gain en points de fortune;
6.	Le gain en points de défense ;
	Le constructeur doit initialiser la position de l'objet ainsi que le point d'origine qui doit être situé en bas au centre de la texture.
	La méthode Afficher qui prend une référence à un RenderWindow et qui affiche l’objet dans la fenêtre.
	Les mutateurs et accesseurs jugés nécessaires;
	Et finalement, l'opérateur << qui permet d'afficher les caractéristiques de l'objet à la console.
	Inspirez-vous grandement de ce que vous avez fait dans la classe CHeros.

*/
#pragma once
#include <SFML/Graphics.hpp>
#include "Position.h"

//--------------------------------------------------------//
// CObjet
//--------------------------------------------------------//
//class CObjet : public CAnimation
class CObjet : public sf::Sprite
{
private:
	std::string nom;
	int GainVie;
	int GainFortune;
	int GainDefense;

public:
	/*
	Possède un constructeur paramétrique avec, dans l’ordre, les six (6) paramètres suivants :
    1.	Une référence à une texture;
    2.	La position de l’objet sur la carte (CPosition);
    3.	Le nom de l’objet
    4.	Le gain en points de vie;
    5.	Le gain en points de fortune;
    6.	Le gain en points de défense ;
	*/
    CObjet(sf::Texture& LaTexture, const CPosition& Pos, const std::string& anom, int v, int f, int d) :
        sf::Sprite(LaTexture), nom(anom), GainVie(v), GainFortune(f), GainDefense(d)
    {
        setPosition(Pos);
        //int FrameLargeur_ = LaTexture.getSize().x / 1;
        //int FrameHauteur_ = LaTexture.getSize().y / 1;
        //setOrigin(static_cast<float>(FrameLargeur_ / 2),
        //    static_cast<float>(FrameHauteur_)); // Les pieds!
    }

    /*
    La méthode Afficher qui prend une référence à un RenderWindow
    et qui affiche l’objet dans la fenêtre.
    */
    void Afficher(sf::RenderWindow& Fenetre)
    {
        //sf::Sprite::Afficher(Fenetre);
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

//std::ostream& operator<<(std::ostream& os, const CObjet& h)
//{
//    os << "Objet[Nom:" << h.getNom() << "GainV:" << h.getGainVie() << "GainF:" << h.getGainFortune() << "GainD:" << h.getGainDefense() << " Pos:" << h.getPosition() << "]";
//    return os;
//}