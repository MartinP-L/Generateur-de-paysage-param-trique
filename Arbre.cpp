#include "Arbre.h"



//- - - - - - - - - - - - - - - -
//CONSTRUCTEUR :

Arbre::Arbre(double x1,double y1,double taille,Couleur cTronc,Couleur cFeuillesMoy):ObjetsComplexes(x1,y1,cFeuillesMoy),m_taille(taille),m_couleurTronc(cTronc)
{}

//- - - - - - - - - - - - - - - -

void Arbre::dessiner(Svgfile& out)
{
    Arbre::dessinerTronc(out);
    Arbre::dessinerFeuilles(out);
}

//- - - - - - - - - - - - - - - -

void Arbre::dessinerTronc(Svgfile& out)
{
    //m_x1 et m_y1 sont les coordonnées du coin supérieur gauche du tronc
    double xbas, ybas,x,y;
    uint8_t degrade = 2;
    uint8_t r,v,b;
    r = m_couleurTronc.getR();
    v = m_couleurTronc.getV();
    b = m_couleurTronc.getB();
    Couleur c(r,v,b);
    x = m_x1; //création de variables de position temporaires pour garder m_x1 et m_y1 de base
    y = m_y1;
    xbas = m_x1;     //l'abscisse de la coordonnées bas gauche est la même que celle du coin haut gauche
    ybas = m_y1 + m_taille;           //on définit l'abscisse du coin bas gauche

    for(int i=0; i<m_taille/10; ++i) //15 correspond à la demi largeur du tronc
    {
        r = r - degrade;
        v = v - degrade;
        b = b - degrade;
        c.modifier(r, v, b);
        ++x;
        if(i%3 == 0) //baisser d'un y uniquement tous les 3 tours de boucle
            y = y + 1;
        xbas = x;     //l'abscisse de la coordonnées bas gauche est la même que celle du coin haut gauche
        ybas = y + m_taille;           //on définit l'abscisse du coin bas gauche
        out.addLine(x,y ,xbas ,ybas,c);     //assemblage de ligne pour créer la partie gauche du tronc
    }

    for(int i=0; i<m_taille/10; ++i)
    {
        r = r - degrade;
        v = v - degrade;
        b = b - degrade;
        c.modifier(r, v, b);
        ++x;
        if(i%3 == 0)
            y = y - 1;
        xbas = x;         //même abscisse que la base
        ybas = y + m_taille;   //coordonnée y du coin bas gauche
        out.addLine(x,y,xbas,ybas ,c);         //assemblage de ligne pour créer la partie droite du tronc
    }

}

//- - - - - - - - - - - - - - - -

void Arbre::dessinerFeuilles(Svgfile& out)
{

    double rx;
    double ry;
    double xfeuille;
    double yfeuille;
    uint8_t r2(0),v2(0),b2(0);
    Couleur c(r2,v2,b2);

    for(int i=0; i<50; ++i)
    {
        r2= util::alea(m_couleur.getR()-10,m_couleur.getR()+10);
        v2=util::alea(m_couleur.getV()-10,m_couleur.getV()+10);
        b2=util::alea(m_couleur.getV()-10,m_couleur.getV()+10);
        c.modifier(r2,v2,b2);
        xfeuille = util::alea(m_x1 - m_taille/2, m_x1 + m_taille/2 + m_taille/5); //coordonnées du centre des feuilles en fct du point supérieur gauche du tronc (on rajoute aussi la largeur du tronc)
        yfeuille = util::alea(m_y1-25,m_y1 + m_taille/2); //expansion des feuilles en hauteur
        rx = util::alea(m_taille/4,m_taille/2); //rayons de l'ellipse
        ry = util::alea(m_taille/8,m_taille/4);
        out.addEllipse(xfeuille,yfeuille,rx,ry,c);
    }

}


//- - - - - - - - - - - - - - - -

void Arbre::modifierTaille(double& taille)
{
    m_taille = taille;
}

void Arbre::modifierX(double& x)
{
    m_x1 = x;
}

void Arbre::modifierY(double& y)
{
    m_y1 = y;
}

