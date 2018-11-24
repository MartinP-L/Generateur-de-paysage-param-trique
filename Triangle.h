#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include <iostream>
#include <string>
#include "../maillage/Sommet.h"
#include "../codesBase/couleur.h"
#include "../maillage/maillage.h"


class Triangle
{
    private :
        Sommet m_sommet1;
        Sommet m_sommet2;
        Sommet m_sommet3;
        Couleur m_couleur;

    public :
        //void creerTriangle(Maillage maillage1);
        void creerTriangleV2(Maillage maillage1,int a, int b, int c);
        Sommet getSommet(int numSommet)const;
        Couleur getCouleur()const;
};


#endif // TRIANGLE_H_INCLUDED
