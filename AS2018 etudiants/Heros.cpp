#include "Heros.h"
#include "Constantes.h"
#include <algorithm>


//    int vie;
//    int defense;
//    int fortune;

/*
A un constructeur paramétrique qui prend cinq (5) paramètres :
Une référence à une texture;
La position du personnage sur la carte (CPosition);
Le nom du personnage;
Le nombre de points de vie initial du Héros
Le nombre de points de défense initial du Héros
Le héros débute toujours avec 0 de fortune
*/
CHeros::CHeros(sf::Texture& LaTexture, const CPosition& Pos, const std::string& nom, int V, int D):
    CPersonnage(LaTexture, Pos, nom), vie(V), defense(D), fortune(0)
{
}

/*
La méthode Deplacer calcule une nouvelle position en fonction de la touche appuyée par le joueur (voir la classe Keyboard de SFML):
Vers le bas : la position y est augmentée de VitesseHeros (Constantes.h)
Vers le haut : la position y est diminuée de VitesseHeros
Vers la droite : la position x est augmentée de VitesseHeros
Vers la gauche : la position x est diminuée de VitesseHeros
*/
bool CHeros::Deplacer(const CCarte& carte, Direction d)
{
    CPosition pos = getPosition();
    CPosition new_pos;
    switch (d)
    {
    case Direction::Bas:
        new_pos = CPosition(pos.x, std::max(pos.y + VitesseHeros, (float)Hauteur));
        break;
    case Direction::Haut:
        new_pos = CPosition(pos.x, std::max(pos.y - VitesseHeros, (float)0));
        break;
    case Direction::Droite:
        new_pos = CPosition(std::max(pos.x + VitesseHeros, (float)Largeur), pos.y);
        break;
    case Direction::Gauche:
        new_pos = CPosition(std::max(pos.x - VitesseHeros, (float)0), pos.y);
        break;
    }

    // check mur
    try
    {
        CCarte& c = const_cast<CCarte&> (carte); // remove const
        if (c.EstPositionValide(new_pos) == true)
        {
            CAnimation::setPosition(new_pos);
            CAnimation::SetDirection(d);
        }
    }
    catch (...)
    {
    }

    return false;
}

/*
Si le héros peut se trouver à cette position de la carte
(voir la classe CCarte), alors la nouvelle position est affectée à la
position courante et la direction est ajustée en conséquence.

Implémente la méthode Prendre qui prend une référence à un objet de
la classe CObjet en paramètre et qui retourne true ou false :
*/

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

bool CHeros::Prendre(const CObjet& obj)
{
    CPosition pos = getPosition();
    if (PositionsProches(pos, obj.getPosition()) == true)
    {
        if (obj.getGainVie() > 0)
        {
            AugmenterVie(obj.getGainVie());
        }

        if (obj.getGainFortune() > 0)
        {
            AugmenterFortune(obj.getGainFortune());
        }

        if (obj.getGainDefense() > 0)
        {
            AugmenterDefense(obj.getGainDefense());
        }

        std::cout << *this << " ramasse objet " << obj << std::endl;
        return false;
    }
    return true;
}


/*
Implémente les méthodes ReduireDefense, ReduireVie et ReduireFortune,
qui enlèvent un point à la caractéristique correspondante, mais qui
ne peuvent pas réduire cette caractéristique plus bas que zéro (0).
*/

int CHeros::ReduireDefense(int val)
{
    defense = std::max(defense - val, 0);
    return defense;
}

int CHeros::ReduireVie(int val)
{
    vie = std::max(vie - val, 0);
    return vie;
}

int CHeros::ReduireFortune(int val)
{
    fortune = std::max(fortune - val, 0);
    return fortune;
}


int CHeros::AugmenterDefense(int val)
{
    defense += val;
    return defense;
}

int CHeros::AugmenterVie(int val)
{
    vie += val;
    return vie;
}

int CHeros::AugmenterFortune(int val)
{
    fortune += val;
    return fortune;
}

std::ostream& operator<<(std::ostream& os, const CHeros& h)
{
    os << "Hero[Nom:" << h.getNom() << " V:" << h.getVie() << " D:" << h.getDefense() << " F:" << h.getFortune() << " Pos:" << h.getPosition() <<"]";
    return os;
}
