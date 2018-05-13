#include "Brute.h"

CBrute::CBrute(sf::Texture& LaTexture, const CPosition& Pos, std::string nom) :
    CMonstre(LaTexture, Pos, nom)
{
}

bool CBrute::Attaquer(CHeros& hero)
{
    // Position courante
    CPosition pos = getPosition(); 

    if (PositionsProches(pos, hero.getPosition()) == true)
    {
        if (hero.getDefense() > 0)
        {
            hero.ReduireDefense(1);
        }
        else
        {
            hero.ReduireVie(1);
        }
        std::cout << (*this) << std::string(" attaque ") << hero << std::endl;
    }

    if (hero.getVie() == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

std::ostream& operator<<(std::ostream& os, const CBrute& h)
{
    os << "Brute[Nom:" << h.getNom() << " Pos:" << h.getPosition() << "]";
    return os;
}