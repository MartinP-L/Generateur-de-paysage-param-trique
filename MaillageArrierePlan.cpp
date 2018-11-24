#include "MaillageArrierePlan.h"

// - - - - - - - - - - - - - - - -

void MaillageArrierePlan::ajouterObjet(ObjetsComplexes* nouvelObjet)
{
    objets_arriereplan.push_back(nouvelObjet);
}

// - - - - - - - - - - - - - - - -

void MaillageArrierePlan::dessinerObjets(Svgfile& out) const
{
    for(double i=0; i<objets_arriereplan.size();++i)
    {
        objets_arriereplan[i]->dessiner(out);
    }
}

// - - - - - - - - - - - - - - - -

