#include "Objet.h"


std::ostream& operator<<(std::ostream& os, const CObjet& h)
{
    os << "Objet[Nom:" << h.getNom() << " GainV:" << h.getGainVie() << " GainF:" << h.getGainFortune() << " GainD:" << h.getGainDefense() << " Pos:" << h.getPosition() << "]";
    return os;
}

