#ifndef SOMMET_H_INCLUDED
#define SOMMET_H_INCLUDED

#include <iostream>
#include "../svg/svgfile.h"
#include "Coords.h"


class Sommet
{
    //attributs :
    private :
        Coords m_position;
        bool m_selection;

    public :
        void saisir();
        void saisir(double x,double y);
        void afficher() const;
        Coords getPosition()const;
        bool getSelection()const;
        void selectionner(bool selec);
        void setPosition(double nouv_x,double nouv_y);
        void translaterPosition();
        void selectionSommet();
        void deselectionSommet();

};

#endif // SOMMET_H_INCLUDED
