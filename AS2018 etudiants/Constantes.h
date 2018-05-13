////////////////////////////////////////////////////////////
// Constantes.h
// 
// D�claration des constantes servant � param�trer ais�ment
// le jeu
//
// Etienne Forest
// Cr�ation: 27 avril 2018
// Version 1.0
////////////////////////////////////////////////////////////
#pragma once

// Nombre de sous au d�but du jeu
const int NbSous = 15;

// Nombre d'autres objets (pains, boucliers) au d�but du jeu
const int NbAutresObjets = 15;

// Nombre total d'objets au d�but du jeu
const int NbObjets = NbSous + NbAutresObjets;

// Nombre de sous que doit poss�der le h�ros pour gagner
const int NbSousVictoire = 10;

// Nombre de monstres au total dans le jeu
const int NbMonstres = 30;

// Longueur d'un d�placement de monstre (en pixels)
const int VitesseMonstres = 3;

// Longueur d'un d�placement du h�ros (en pixels)
const int VitesseHeros = 6;

// Nombre de tours minimum et maximum pendant lesquels un monstre
// conservera sa direction avant de la changer pour se rapprocher
// du h�ros.  Plus les nombres sont petits, plus les monstres tentent
// de suivre le h�ros, mais moins ils ont de chance de contourner
// les obstacles.
const int NbToursMin = 5;
const int NbToursMax = 20;

// Dimensions du monde
const int Largeur = 1024;
const int Hauteur = 768;

// Carte dimension
const int MondeX = 2398;
const int MondeY = 2298;