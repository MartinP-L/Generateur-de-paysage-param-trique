#ifndef MAILLAGE_H_INCLUDED
#define MAILLAGE_H_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../svg/svgfile.h"
class Sommet;
class Triangle;


class Maillage
{
    //attributs
    private :
        std::vector<Sommet*> collection_sommets;
        std::vector<Triangle*> collection_triangles;

    public :
        void afficherSommets(Maillage maillage1) const;
        void ajouterSommet(Sommet* nouveauSommet);
        void ajouterTriangle(Triangle* nouveauTriangle);
        std::vector<Sommet*> geterSommet();
        std::vector<Triangle*> geterTriangle();
        void translater();
        void selection(Svgfile& out, bool selec);

};

#endif // MAILLAGE_H_INCLUDED
