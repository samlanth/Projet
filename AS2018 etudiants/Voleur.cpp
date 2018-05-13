#include "Voleur.h"

CVoleur::CVoleur(sf::Texture& LaTexture, const CPosition& Pos, std::string nom) :
    CMonstre(LaTexture, Pos, nom)
{
}

/*
Redéfinit la méthode Attaquer qui prend une référence à un héros en paramètre
et qui retourne true ou false :
La méthode Attaquer vérifie dans un premier temps si l’ennemi passé en paramètre
est proche (voir la classe CPosition) . Si c’est le cas, alors il y a une attaque.
Si le Héros possède de la Fortune, le Voleur lui en enlève un point.
Sinon, si le Héros possède de la Défense, le Voleur lui en enlève un point.
Sinon, le Voleur déclare qu’il n’y a rien d’intéressant à voler ici et l’attaque ne produira aucun effet.
Le Voleur ne peut pas tuer le Héros, donc la méthode retourne toujours true.
De plus, la méthode doit afficher à la console tous les détails de l’attaque
ainsi que les caractéristiques finales du Héros
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