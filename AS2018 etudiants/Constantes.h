////////////////////////////////////////////////////////////
// Constantes.h
// 
// Déclaration des constantes servant à paramétrer aisément
// le jeu
//
// Etienne Forest
// Création: 27 avril 2018
// Version 1.0
////////////////////////////////////////////////////////////
#pragma once

// Nombre de sous au début du jeu
const int NbSous = 15;

// Nombre d'autres objets (pains, boucliers) au début du jeu
const int NbAutresObjets = 15;

// Nombre total d'objets au début du jeu
const int NbObjets = NbSous + NbAutresObjets;

// Nombre de sous que doit posséder le héros pour gagner
const int NbSousVictoire = 10;

// Nombre de monstres au total dans le jeu
const int NbMonstres = 30;

// Longueur d'un déplacement de monstre (en pixels)
const int VitesseMonstres = 3;

// Longueur d'un déplacement du héros (en pixels)
const int VitesseHeros = 6;

// Nombre de tours minimum et maximum pendant lesquels un monstre
// conservera sa direction avant de la changer pour se rapprocher
// du héros.  Plus les nombres sont petits, plus les monstres tentent
// de suivre le héros, mais moins ils ont de chance de contourner
// les obstacles.
const int NbToursMin = 5;
const int NbToursMax = 20;

// Dimensions du monde
const int Largeur = 1024;
const int Hauteur = 768;

// Carte dimension
const int MondeX = 2398;
const int MondeY = 2298;