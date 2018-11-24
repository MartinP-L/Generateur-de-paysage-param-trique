#include "Immeuble.h"
#include <math.h>

///constructeur :
Immeuble::Immeuble(double x, double y, double largeur, double hauteur, double profondeur, Couleur couleur):ObjetsComplexes(x,y,couleur),m_largeur(largeur),m_hauteur(hauteur),m_profondeur(profondeur)
{}

// - - - - - - - - - - - - - - - -

void Immeuble::dessiner(Svgfile& out)
{
    uint8_t ajout = 50;
    double x2(m_x1),y2(m_y1+m_hauteur),x3(m_x1+m_largeur),y3(m_y1+m_hauteur),x4(m_x1+m_largeur),y4(m_y1),x5(m_x1+m_largeur+m_profondeur),y5(m_y1+m_hauteur-m_profondeur)
    ,x6(m_x1+m_largeur+m_profondeur),y6(m_y1-m_profondeur),x7(m_x1+m_profondeur),y7(m_y1-m_profondeur);


    out.addQuadrilatere(m_x1,m_y1,x2,y2,x3,y3,x4,y4,m_couleur); //façade

    Couleur couleurFoncee(m_couleur.getR()-ajout,m_couleur.getV()-ajout,m_couleur.getB()-ajout);
    out.addQuadrilatere(x4,y4,x3,y3,x5,y5,x6,y6,couleurFoncee); //face droite

    Couleur couleurClaire(m_couleur.getR()+ajout,m_couleur.getV()+ajout,m_couleur.getB()+ajout);
    out.addQuadrilatere(m_x1,m_y1,x4,y4,x6,y6,x7,y7,couleurClaire); //face dessus

    Immeuble::dessinFenetres(out);
}

// - - - - - - - - - - - - -

void Immeuble::dessinFenetres(Svgfile& out)
{
    double x1f,y1f, x2f,y2f, x3f,y3f, x4f,y4f, x1c,y1c, x2c,y2c, x3c,y3c, x4c,y4c, espFenetresLargeur, espFenetresHauteur, espFenetresProfondeur;
    double hauteurFenetre(15),largeurFenetre(10),profondeurFenetre(2.5),nbrFenetresLargeur,nbrFenetresHauteur,nbrFenetresProfondeur,intpartLargeurFenetre,intpartHauteurFenetre,intpartProfondeurFenetre;
    Couleur couleur(169, 234, 254);

    nbrFenetresLargeur = (m_largeur*2)/(3*largeurFenetre);
    nbrFenetresHauteur = ((m_hauteur-15)*3)/(4*hauteurFenetre);
    nbrFenetresProfondeur = (m_profondeur*2)/(3*profondeurFenetre);

    nbrFenetresLargeur = nbrFenetresLargeur - modf(nbrFenetresLargeur, &intpartLargeurFenetre);
    nbrFenetresHauteur = nbrFenetresHauteur - modf(nbrFenetresHauteur, &intpartHauteurFenetre);
    nbrFenetresProfondeur = nbrFenetresProfondeur - modf(nbrFenetresProfondeur, &intpartProfondeurFenetre);

    espFenetresLargeur = (m_largeur - nbrFenetresLargeur*largeurFenetre)/(nbrFenetresLargeur+1);
    espFenetresHauteur = (m_hauteur-15 - nbrFenetresHauteur*hauteurFenetre)/(nbrFenetresHauteur+1);
    espFenetresProfondeur = (m_profondeur - nbrFenetresProfondeur*profondeurFenetre)/(nbrFenetresProfondeur+1);


    for(int j=1; j<=nbrFenetresHauteur; ++j)
    {
        for(int i=1; i<=nbrFenetresLargeur; ++i)
        {
            if(j==1 && i==1)
            {
                x1f = m_x1 + espFenetresLargeur;
                y1f = m_y1 + espFenetresHauteur; //initialisation des deux premières coordonnées
            }
            if(j==1  && i!= 1)
            {
                x1f = m_x1 + (espFenetresLargeur + largeurFenetre)*i - largeurFenetre;
                y1f = m_y1 + espFenetresHauteur; //initialisation des deux premières coordonnées
            }
            if(j!=1 && i==1)
            {
                x1f = m_x1 + espFenetresLargeur;
                y1f = m_y1 + (espFenetresHauteur + hauteurFenetre)*j - hauteurFenetre; //initialisation des deux premières coordonnées
            }
            else
            {
                x1f = m_x1 + (espFenetresLargeur + largeurFenetre)*i - largeurFenetre;
                y1f = m_y1 + (espFenetresHauteur + hauteurFenetre)*j - hauteurFenetre; //initialisation des deux premières coordonnées
            }


            x2f = x1f;
            y2f = y1f + hauteurFenetre;

            x3f = x1f + largeurFenetre;
            y3f = y1f + hauteurFenetre;

            x4f = x1f + largeurFenetre;
            y4f = y1f;

            out.addQuadrilatereTrait(x1f,y1f,x2f,y2f,x3f,y3f,x4f,y4f,couleur);
        }

        for(int k=1; k<=nbrFenetresProfondeur; ++k)
        {
            if(j==1 && k==1)
            {
                x1c = m_x1 + m_largeur + espFenetresProfondeur;
                y1c = m_y1 + espFenetresHauteur;
            }
            if(j==1  && k!= 1)
            {
                x1c = m_x1 + m_largeur + (espFenetresProfondeur + profondeurFenetre)*k - profondeurFenetre;
                y1c = m_y1 + espFenetresHauteur - (espFenetresProfondeur + profondeurFenetre)*k + profondeurFenetre + espFenetresProfondeur;
            }
            if(j!=1 && k==1)
            {
                x1c = m_x1 + m_largeur + espFenetresProfondeur;
                y1c = m_y1 + (espFenetresHauteur + hauteurFenetre)*j - hauteurFenetre - profondeurFenetre;
            }
            else
            {
                x1c = m_x1 + m_largeur + (espFenetresProfondeur + profondeurFenetre)*k - profondeurFenetre;
                y1c = m_y1 + (espFenetresHauteur + hauteurFenetre)*j - hauteurFenetre - (espFenetresProfondeur + profondeurFenetre)*k + espFenetresProfondeur;
            }


            x2c = x1c;
            y2c = y1c + hauteurFenetre;

            x3c = x1c + profondeurFenetre;
            y3c = y1c + hauteurFenetre - profondeurFenetre;

            x4c = x1c + profondeurFenetre;
            y4c = y1c - profondeurFenetre;

            out.addQuadrilatereTrait(x1c,y1c,x2c,y2c,x3c,y3c,x4c,y4c,couleur);
        }
    }
    //traitements sur les x1f et y1f
    //taille des fenètres constantes, créé par rapport au pt supérieur gauche


}
