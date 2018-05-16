////////////////////////////////////////////////////////////
// Voleur.h
// 
// Déclaration de la classe CVoleur qui représente
// un type de monstre - les voleurs
//
// Samuel Lanthier
// Création: 2018-05-15
// - CVoleur - Dérive de CMonstre
////////////////////////////////////////////////////////////

#include <SFML/Graphics.hpp>
#include "Position.h"
#include "Carte.h"
#include "Personnage.h"
#include "Heros.h"
#include "Monstre.h"

//--------------------------------------------------------//
// CVoleur
//--------------------------------------------------------//
// Dérive de la classe CMonstre;
class CVoleur : public CMonstre
{
	// Ne possède aucun attribut
private:

public:
	////////////////////////////////////////////////////////////
	// CVoleur
	//
	// Un constructeur paramétrique qui prend les mêmes trois (3) paramètres et dans le même ordre que le constructeur paramétrique de la classe CMonstre
	// 
	//
	// Intrants : Une référence à une texture;
	//			  La position du personnage sur la carte(CPosition);
	//            Le nom du personnage;
	//
	////////////////////////////////////////////////////////////
    CVoleur(sf::Texture& LaTexture, const CPosition& Pos, std::string nom);

	/*
    De plus, la méthode doit afficher à la console tous les détails de l’attaque
    ainsi que les caractéristiques finales du Héros
	*/
	////////////////////////////////////////////////////////////
	// CVoleur
	//
	// Redéfinit la méthode Attaquer qui prend une référence à un héros en paramètre 
	// et qui retourne true ou false :
	// 
	//
	// Intrants : Une référence à un objet de la classe CHeros
	//
	// Extrants: La méthode Attaquer vérifie dans un premier temps si l’ennemi passé en paramètre
	// est proche(voir la classe CPosition).Si c’est le cas, alors il y a une attaque.
	//	Si le Héros possède de la Fortune, le Voleur lui en enlève un point.
	//	Sinon, si le Héros possède de la Défense, le Voleur lui en enlève un point.
	//	Sinon, le Voleur déclare qu’il n’y a rien d’intéressant à voler ici et l’attaque ne produira aucun effet.
	//	Le Voleur ne peut pas tuer le Héros, donc la méthode retourne toujours true.
	////////////////////////////////////////////////////////////
    virtual bool Attaquer(CHeros& hero);
};

std::ostream& operator<<(std::ostream& os, const CVoleur& h);
