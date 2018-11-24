#include "ObjetsComplexes.h"

ObjetsComplexes::ObjetsComplexes(double x, double y, Couleur couleur):m_x1(x),m_y1(y),m_couleur(couleur)
{}


void ObjetsComplexes::modifierCouleur(Couleur nouvelleCouleur)
{
    uint8_t rt,vt,bt;
    rt = nouvelleCouleur.getR();
    vt = nouvelleCouleur.getV();
    bt = nouvelleCouleur.getB();
    m_couleur.modifier(rt,vt,bt);
}
