/*
La classe CMonstre

	Dérive de la classe CPersonnage;
	Possède un seul attribut :
	Le nombre de tours pendant lesquels le monstre continuera d’avancer dans la direction qu’il a choisie (voir détails plus bas).
	A un constructeur paramétrique qui prend les mêmes trois (3) paramètres et dans le même ordre que le constructeur paramétrique de la classe CPersonnage;
	Redéfinit la méthode Deplacer :
	Un monstre se déplace en choisissant une direction valide (pour laquelle il est possible de faire un pas sans cogner un mur) qui le rapprocherait du héros dont la position a été reçue en paramètre.
	Si deux directions valides le rapprocheraient du héros, il doit en choisir une au hasard (pour ne pas que le héros puisse deviner ce qu’il va faire).
	Si aucune direction pouvant le rapprocher du héros n’est utilisable, il choisit une direction au hasard.
	Il sélectionne aussi un nombre de tours pendant lesquels il conservera cette direction, entre NbToursMin et NbToursMax (constantes).
	Pendant ce nombre de tours là, il continue simplement à avancer d’un pas (constante VitesseMonstres) dans la même direction à chaque tour, en réduisant le nombre de tours restants.
	Lorsque ce nombre de tours arrive à zéro (0) ou lorsqu’il ne peut plus avancer dans la direction choisie parce qu’il frappe un mur, il doit choisir une nouvelle direction et un nouveau nombre de tours comme au point 1.
	La méthode retourne True.
	Déclare la fonction virtuelle pure  Attaquer qui prend une référence à un objet de la classe CHeros, et qui retourne true ou false;

*/
#pragma once
#include <SFML/Graphics.hpp>
#include "Position.h"
#include "Carte.h"
#include "Personnage.h"
#include "Heros.h"
//--------------------------------------------------------//
// CMonstre
//--------------------------------------------------------//
class CMonstre : public CPersonnage
{
private:
	int NombreTours;
    int NombreToursAFaire;

public:

	CMonstre(sf::Texture& LaTexture, const CPosition& Pos, std::string nom):
        CPersonnage(LaTexture, Pos, nom), NombreTours(0)
    {
        NombreToursAFaire = NbToursMin + (rand() % (NbToursMax - NbToursMin));
    }

    bool Deplacer(const CCarte& carte, Direction d) override
    {
        return false;
    }

    bool DeplacerVers(const CCarte& carte, Direction d, CPosition posHero) override
    {
        CPosition pos = getPosition();
        if (NombreTours < NombreToursAFaire)
        {
            CPosition new_pos = getnewPos(d);
            if (carte.EstPositionValide(new_pos) == true)
            {
                NombreTours++;
                CAnimation::setPosition(new_pos);
                return false;

            }
        }

        // Reset direction
        CPosition new_pos[4] = { getnewPos(Bas), getnewPos(Haut), getnewPos(Droite), getnewPos(Gauche) };
        bool ok[4];
        Direction vd[4] = { Bas, Haut, Droite, Gauche };
        int n = 0;
        for (int i = 0; i < 4; i++)
        {
            ok[i] = false;
            if (carte.EstPositionValide(new_pos[i]) == true)
            {
                float dist_avant = distance(pos, posHero);
                float dist_apres = distance(new_pos[i], posHero);
                if (dist_apres < dist_avant)
                {
                    ok[i] = true;
                    n++;
                }
            }
        }

        if (n == 0)
        {
            for (int i = 0; i < 4; i++)
            {
                ok[i] = false;
                if (carte.EstPositionValide(new_pos[i]) == true)
                {
                    ok[i] = true;
                    n++;
                }
            }
        }

        if (n > 0)
        {
            int r = rand() % n;
            n = 0;
            for (int i = 0; i < 4; i++)
            {
                if (ok[i] == true)
                {
                    if (n == r)
                    {
                        NombreTours = 1;
                        CAnimation::setPosition(new_pos[i]);
                        CAnimation::SetDirection(vd[i]);
                        NombreToursAFaire = NbToursMin + (rand() % (NbToursMax - NbToursMin));
                        break;
                    }
                    else
                    {
                        n++;
                    }
                }
            }
        }

        return false;
    }

	//	Déclare la fonction virtuelle pure  Attaquer qui prend une référence à un objet de la classe CHeros, et qui retourne true ou false;
    virtual bool Attaquer(CHeros& objet) = 0;

    CPosition getnewPos(Direction d)
    {
        CPosition pos = getPosition();
        CPosition new_pos = pos;

        switch (d)
        {
        case Direction::Bas:
            new_pos = CPosition(pos.x, std::max(pos.y + VitesseMonstres, (float)Hauteur));
            break;
        case Direction::Haut:
            new_pos = CPosition(pos.x, std::max(pos.y - VitesseMonstres, (float)0));
            break;
        case Direction::Droite:
            new_pos = CPosition(std::max(pos.x + VitesseMonstres, (float)Largeur), pos.y);
            break;
        case Direction::Gauche:
            new_pos = CPosition(std::max(pos.x - VitesseMonstres, (float)0), pos.y);
            break;
        }
        return new_pos;
    }
};