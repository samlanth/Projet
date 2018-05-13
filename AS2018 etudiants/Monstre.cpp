#include "Monstre.h"
#include "Constantes.h"

CMonstre::CMonstre(sf::Texture& LaTexture, const CPosition& Pos, std::string nom) :
    CPersonnage(LaTexture, Pos, nom), NombreTours(0)
{
    NombreToursAFaire = NbToursMin + (rand() % (NbToursMax - NbToursMin));
}

bool CMonstre::DeplacerVers(const CCarte& carte, Direction d, CPosition posHero) 
{
    // Position courante
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

    //---------------------
    // Reset direction
    //---------------------

    // Liste new position selon direction
    CPosition new_pos[4] = { getnewPos(Bas), getnewPos(Haut), getnewPos(Droite), getnewPos(Gauche) };

    // Flag si new position valide
    bool ok[4]; 

    // Liste des direction
    Direction vd[4] = { Bas, Haut, Droite, Gauche };

    // compteur nombre new position valide
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

// Calculer new position selon direction
CPosition CMonstre::getnewPos(Direction d)
{
    CPosition pos = getPosition();  // position courante
    CPosition new_pos = pos;        // position apres direction

    switch (d)
    {
    case Direction::Bas:
        new_pos = CPosition(pos.x, std::min(pos.y + VitesseMonstres, (float)MondeY));
        break;
    case Direction::Haut:
        new_pos = CPosition(pos.x, std::max(pos.y - VitesseMonstres, (float)0));
        break;
    case Direction::Droite:
        new_pos = CPosition(std::min(pos.x + VitesseMonstres, (float)MondeX), pos.y);
        break;
    case Direction::Gauche:
        new_pos = CPosition(std::max(pos.x - VitesseMonstres, (float)0), pos.y);
        break;
    }
    return new_pos;
}
