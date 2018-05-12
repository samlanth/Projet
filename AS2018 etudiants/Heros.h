/*
La classe CHeros

Dérive de la classe CPersonnage;
	Possède trois (3) attributs :
1.	Le nombre de points de vie (V) : représente la vitalité du personnage;
2.	Le nombre de points de défense (D) : représente l’état de l’armure du personnage, qui lui permettra de résister aux attaques dévastatrices des Brutes pour un certain temps;
3.	Le nombre de points de fortune (F) : représente le trésor accumulé par le personnage, son but étant d’arriver à 10.
	A un constructeur paramétrique qui prend cinq (5) paramètres :
	Une référence à une texture;
	La position du personnage sur la carte (CPosition);
	Le nom du personnage;
	Le nombre de points de vie initial du Héros
	Le nombre de points de défense initial du Héros
	Le héros débute toujours avec 0 de fortune
	Redéfinit la méthode Déplacer :
	La méthode Deplacer calcule une nouvelle position en fonction de la touche appuyée par le joueur (voir la classe Keyboard de SFML):
	Vers le bas : la position y est augmentée de VitesseHeros (Constantes.h)
	Vers le haut : la position y est diminuée de VitesseHeros
	Vers la droite : la position x est augmentée de VitesseHeros
	Vers la gauche : la position x est diminuée de VitesseHeros
	Si le héros peut se trouver à cette position de la carte (voir la classe CCarte), alors la nouvelle position est affectée à la position courante et la direction est ajustée en conséquence.
	La méthode retourne true si le joueur a appuyé sur la touche Échappement, sinon elle retourne false.
	Implémente la méthode Prendre qui prend une référence à un objet de la classe CObjet en paramètre et qui retourne true ou false :
	La méthode Prendre vérifie dans un premier temps si l’objet passé en paramètre est proche du personnage (voir la classe CPosition) .  Si c’est le cas, l’objet est ramassé. Lorsqu’un objet est ramassé, les caractéristiques de l’objet (GainVie, GainFortune et GainDefense) sont ajoutées aux caractéristiques correspondantes (V.F.D.) du personnage et un message contenant les nouvelles caractéristiques du personnage ainsi que les attributs de l’objet ramassé est affiché à la console.  La méthode retourne false si l’objet a été ramassé (puisque l’objet maintenant n’existe plus), true dans le cas contraire.
	Implémente les méthodes ReduireDefense, ReduireVie et ReduireFortune, qui enlèvent un point à la caractéristique correspondante, mais qui ne peuvent pas réduire cette caractéristique plus bas que zéro (0).
	Implémente les accesseurs nécessaires.
	Et finalement, l'opérateur << qui permet d'afficher aisément les caractéristiques du héros à la console.
La déclaration de l’opérateur << doit être placée dans le fichier .h, mais en dehors de la classe, après la déclaration de la classe elle-même :
	std::ostream& operator<<(std::ostream& os, const CHeros& h);
	La définition de l’opérateur << doit être dans le fichier .cpp

*/
#pragma once
#include <SFML/Graphics.hpp>
#include "Personnage.h"
#include "Objet.h"

//--------------------------------------------------------//
// CHeros
//--------------------------------------------------------//
class CHeros : public CPersonnage
{
private:
	int vie;
	int defense;
	int fortune;

public:
/*
	A un constructeur paramétrique qui prend cinq (5) paramètres :
	Une référence à une texture;
	La position du personnage sur la carte (CPosition);
	Le nom du personnage;
	Le nombre de points de vie initial du Héros
	Le nombre de points de défense initial du Héros
	Le héros débute toujours avec 0 de fortune
*/
	CHeros(sf::Texture& LaTexture, const CPosition& Pos, const std::string& nom, int V, int D);

	/*		Redéfinit la méthode Déplacer :
	La méthode Deplacer calcule une nouvelle position en fonction de la touche appuyée par le joueur (voir la classe Keyboard de SFML):
	Vers le bas : la position y est augmentée de VitesseHeros (Constantes.h)
	Vers le haut : la position y est diminuée de VitesseHeros
	Vers la droite : la position x est augmentée de VitesseHeros
    Vers la gauche : la position x est diminuée de VitesseHeros
	*/
    bool Deplacer(const CCarte& objet, Direction d) override;

	/*
    Si le héros peut se trouver à cette position de la carte
	(voir la classe CCarte), alors la nouvelle position est affectée à la
	position courante et la direction est ajustée en conséquence.
	La méthode retourne true si le joueur a appuyé sur la touche Échappement,
    sinon elle retourne false. 


	Implémente la méthode Prendre qui prend une référence à un objet de 
    la classe CObjet en paramètre et qui retourne true ou false :
	*/
	bool Prendre(const CObjet& objet);


    /*
    La méthode Prendre vérifie dans un premier temps si l’objet passé en 
    paramètre est proche du personnage (voir la classe CPosition) .
    Si c’est le cas, l’objet est ramassé. Lorsqu’un objet est ramassé,
    les caractéristiques de l’objet (GainVie, GainFortune et GainDefense)
    sont ajoutées aux caractéristiques correspondantes (V.F.D.) du personnage 
    et un message contenant les nouvelles caractéristiques du personnage ainsi que 
    les attributs de l’objet ramassé est affiché à la console.  La méthode
    retourne false si l’objet a été ramassé (puisque l’objet maintenant
    n’existe plus), true dans le cas contraire.
    */

    /*
	Implémente les méthodes ReduireDefense, ReduireVie et ReduireFortune,
    qui enlèvent un point à la caractéristique correspondante, mais qui
    ne peuvent pas réduire cette caractéristique plus bas que zéro (0).
    */

	int ReduireDefense(int val);
	int ReduireVie(int val);
	int ReduireFortune(int val);

    int AugmenterDefense(int val);
    int AugmenterVie(int val);
    int AugmenterFortune(int val);

    // Implémente les accesseurs nécessaires
    int getVie() const { return vie; };
    int getDefense() const  { return defense; };
    int getFortune() const { return fortune; };
		
};

std::ostream& operator<<(std::ostream& os, const CHeros& h);
