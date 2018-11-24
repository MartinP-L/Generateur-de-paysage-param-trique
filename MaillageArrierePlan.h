#ifndef MAILLAGEARRIEREPLAN_H_INCLUDED
#define MAILLAGEARRIEREPLAN_H_INCLUDED

#include "../objetsComplexes/ObjetsComplexes.h"
#include <vector>


class MaillageArrierePlan
{
    private :
        std::vector<ObjetsComplexes*> objets_arriereplan;

    public :
        void ajouterObjet(ObjetsComplexes* nouvelObjet);
        void dessinerObjets(Svgfile& out) const;




};

#endif // MAILLAGEARRIEREPLAN_H_INCLUDED
