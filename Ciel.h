#ifndef CIEL_H_INCLUDED
#define CIEL_H_INCLUDED

#include <iostream>
#include "../ssProgs/menu.h"
#include "../codesBase/util.h"
#include "../svg/svgfile.h"
#include "../codesBase/couleur.h"
#include "ObjetsComplexes.h"

class Ciel : public ObjetsComplexes //classe dérivée d' ObjetsComplexes
{

//cette classe est dérivée de la classe ObjetsComplexes et n'a pas d'attributs particuliers
    public:
        Ciel(Couleur c);
        void dessiner(Svgfile& out);
        void dessiner(Svgfile& out,Couleur couleurMoy);

};

#endif // CIEL_H_INCLUDED
