#ifndef TRANSFORMATION_H_INCLUDED
#define TRANSFORMATION_H_INCLUDED

#include "../maillage/Coords.h"


///_____________________________________________________________________
///BESOIN d'une classe "matrice" pour fonctionner
///mais à l'heure ou j'écris ça je sais pas encore à quoi ça va servir
///_____________________________________________________________________

/*
//#include "matrice.h"
/// Classe pour les transformations affines usuelles
/// Ce code n'est pas optimal (calculs inutiles dans certains cas)

struct Translation
{
    Coords vecteur;
};

struct Rotation
{
    Coords centre;
    double angle;
};

struct Homothetie
{
    Coords centre;
    double rapport;
};

struct Symetrie
{
    Coords centre;
    double angle;
};

class Transformation
{
    public :
        Transformation();
        Transformation(const Translation& translation);
        Transformation(const Rotation& rotation);
        Transformation(const Homothetie& homothetie);
        Transformation(const Symetrie& symetrie);

        void appliquer(Coords& c) const;
        Coords resultat(const Coords& c) const;

    private :
        Matrice m_matrice;
        Coords m_centre;
        Coords m_translation;
};
*/


#endif // TRANSFORMATION_H_INCLUDED
