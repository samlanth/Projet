#include "Voleur.h"

CVoleur::CVoleur(sf::Texture& LaTexture, const CPosition& Pos, std::string nom) :
    CMonstre(LaTexture, Pos, nom)
{
}

/*
Red�finit la m�thode Attaquer qui prend une r�f�rence � un h�ros en param�tre
et qui retourne true ou false :
La m�thode Attaquer v�rifie dans un premier temps si l�ennemi pass� en param�tre
est proche (voir la classe CPosition) . Si c�est le cas, alors il y a une attaque.
Si le H�ros poss�de de la Fortune, le Voleur lui en enl�ve un point.
Sinon, si le H�ros poss�de de la D�fense, le Voleur lui en enl�ve un point.
Sinon, le Voleur d�clare qu�il n�y a rien d�int�ressant � voler ici et l�attaque ne produira aucun effet.
Le Voleur ne peut pas tuer le H�ros, donc la m�thode retourne toujours true.
De plus, la m�thode doit afficher � la console tous les d�tails de l�attaque
ainsi que les caract�ristiques finales du H�ros
*/
bool CVoleur::Attaquer(CHeros& hero)
{
    // Position courante
    CPosition pos = getPosition();

    if (PositionsProches(pos, hero.getPosition()) == true)
    {
        if (hero.getFortune() > 0)
        {
            hero.ReduireFortune(1);
            std::cout << (*this) << std::string(" attaque ") << hero << std::endl;
        }
        else if (hero.getDefense() > 0)
        {
            hero.ReduireDefense(1);
            std::cout << (*this) << std::string(" attaque ") << hero << std::endl;
        }
        else
        {
        }
    }

    return true;
}

std::ostream& operator<<(std::ostream& os, const CVoleur& h)
{
    os << "Voleur[Nom:" << h.getNom() << " Pos:" << h.getPosition() << "]";
    return os;
}