#ifndef OBJETSCOMPLEXES_H_INCLUDED
#define OBJETSCOMPLEXES_H_INCLUDED

#include "../codesBase/couleur.h"
#include "../svg/svgfile.h"


class ObjetsComplexes //CLASSE ABSTRAITE POUR OBJETS COMPLEXES
{

    protected :
        double m_x1;
        double m_y1;
        Couleur m_couleur;  //attribut pour toutes les classes dérivées


    public :
        ObjetsComplexes(double x, double y, Couleur couleur);
        virtual ~ObjetsComplexes() = default; //destructeur
        virtual void dessiner(Svgfile& out) = 0; //méthode virtuelle pure de dessin d'un objet complexe sur un fichier svg
        virtual void modifierCouleur(Couleur nouvelleCouleur);



};

#endif // OBJETSCOMPLEXES_H_INCLUDED
