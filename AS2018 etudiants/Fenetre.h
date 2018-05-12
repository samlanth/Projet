////////////////////////////////////////////////////////////
// Fenetre.h
//
// D�claration de la classe CFenetre qui permet de manipuler
// une fen�tre Windows.
//
// Joan-S�bastien Morales 
// Cr�ation: 28 avril 2010
// Version 1.0
// Version 1.1 - Bloquer la copie
// Version 2.0 - Encapsule RenderWindow - 5 mai 2014
////////////////////////////////////////////////////////////
#pragma once 
#include <SFML/Graphics.hpp>
#include <string>
#include "Position.h"
using namespace sf;

//--------------------------------------------------------//
// CFenetre
//--------------------------------------------------------//
class CFenetre : public RenderWindow
{
public:
	////////////////////////////////////////////////////////////
	// CFenetre
	// Constructeur mixte
	//
	// Intrants: 
	// Titre: Nom qui sera affich� dans la barre de titre de la
	//        fen�tre
	// Largeur: Largeur de la fen�tre en pixels
	// Hauteur: Hauteur de la fen�tre en pixels
	//
	////////////////////////////////////////////////////////////
   CFenetre(int Hauteur = 800, int Largeur = 800, std::string Titre = "") : RenderWindow(VideoMode(Hauteur, Largeur), Titre) {}

	////////////////////////////////////////////////////////////
	// ~CFenetre
	// Destructeur
	//
	////////////////////////////////////////////////////////////
	//~CFenetre();

	////////////////////////////////////////////////////////////
	// Rafraichir
	// Mettre � jour la fen�tre
	//
	////////////////////////////////////////////////////////////
	//void Rafraichir() const;

	////////////////////////////////////////////////////////////
	// SetCamera
	// Modifie la position de la cam�ra dans le monde.
	// Puisque le monde est plus grand que la fen�tre,
	// seulement une partie du monde sera affich�e.
	// La fen�tre sera centr�e sur la position de la 
	// cam�ra.
	//
	// Intrant: position de la cam�ra
	//
	////////////////////////////////////////////////////////////
	void SetCamera(const CPosition& Camera);

	////////////////////////////////////////////////////////////
	// GetCamera
	// Retourne la position de la cam�ra dans le monde
	//
	// Extrant: position de la cam�ra 
	//
	////////////////////////////////////////////////////////////
	const CPosition& GetCamera() const;

	////////////////////////////////////////////////////////////
	// GetHauteur
	// Retourne la hauteur de la fen�tre en pixels
	//
	// Extrant: Hauteur de la fen�tre 
	//
	////////////////////////////////////////////////////////////
	//int GetHauteur() const;

	////////////////////////////////////////////////////////////
	// GetLargeur
	// Retourne la largeur de la fen�tre en pixels
	//
	// Extrant: Largeur de la fen�tre 
	//
	////////////////////////////////////////////////////////////
	//int GetLargeur() const;

	////////////////////////////////////////////////////////////
	// GetSurface
	// Retourne la surface SDL utilis�e par la fen�tre
	// *** VOUS NE DEVEZ PAS UTILISER CETTE M�THODE!!!
	//
	// Extrant: Pointeur sur la surface SDL 
	//
	////////////////////////////////////////////////////////////
	/*SDL_Surface* GetSurface() { return Surface_; }*/

private:
	// Bloquer la copie
	CFenetre(const CFenetre&);
	CFenetre& operator=(const CFenetre&);

	// Largeur en pixels de la fen�tre
	//int Largeur_;
	// Hauteur en pixels de la fen�tre
	//int Hauteur_;
	// Position de la cam�ra sur la carte
	// La fen�tre sera centr�e sur cette position
	CPosition Camera_; // viewport??
	
	// Mutateurs priv�s
	//void SetHauteur(int Hauteur);
	//void SetLargeur(int Largeur);
	//void SetSurface(SDL_Surface *Surface);

	// Largeur et hauteur par d�faut
	//const static int iLARGEURDEFAUT=800;
	//const static int iHAUTEURDEFAUT=800;

	// Surface SDL
   //RenderWindow Rw_;
};
