#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED

#include <iostream>
#include "../ssProgs/menu.h"
#include "../codesBase/util.h"
#include "../svg/svgfile.h"
#include "../codesBase/couleur.h"
#include "ObjetsComplexes.h"


class Arbre : public ObjetsComplexes
{
private:
    double m_taille;
    Couleur m_couleurTronc;

public:
    Arbre(double x1,double y1,double taille,Couleur cTronc, Couleur cFeuillesMoy); //constructeur
    void dessiner(Svgfile& out);
    void dessinerTronc(Svgfile& out);
    void dessinerFeuilles(Svgfile& out);
    void modifierTaille(double& taille);
    void modifierX(double& x);
    void modifierY(double& y);
};

#endif // ARBRE_H_INCLUDED
