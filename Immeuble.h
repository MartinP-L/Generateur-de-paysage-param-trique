#ifndef IMMEUBLE_H_INCLUDED
#define IMMEUBLE_H_INCLUDED

#include <vector>
#include "../svg/svgfile.h"
#include "../codesBase/couleur.h"
#include "ObjetsComplexes.h"

class Immeuble : public ObjetsComplexes
{
    private:
        double m_hauteur;
        double m_largeur;
        double m_profondeur;        // m_profondeur ne correspond pas à la profondeur réelle mais à la profondeur 2D
        Couleur m_couleur;

    public:
        Immeuble(double x, double y, double largeur, double hauteur, double profondeur, Couleur couleur); //constructeur
        void dessiner(Svgfile& out);
        void dessinFenetres(Svgfile& out);



};


#endif // IMMEUBLE_H_INCLUDED
