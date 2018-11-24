#include "Ciel.h"

//CONSTRUCTEUR :
Ciel::Ciel(Couleur c):ObjetsComplexes(0,0,c)//non utilisation des attributs m_x1 et m_y1 pour les objets ciel
{}


///Prog dessin du ciel
void Ciel::dessiner(Svgfile& out)
{
    int decalageX(0), decalageY(0);
    uint8_t degrade(1);
    uint8_t r,v,b;

    for(int i=0; i<100;++i)
    {
        decalageX = decalageX + 20;
        decalageY = decalageY + 10;
        r= r + degrade;
        v= v + degrade;
        b = m_couleur.getB(); //pas de changement en bleu
        m_couleur.modifier(r,v,b); //couleur de test
        out.addEllipse(1350-decalageX,500-decalageY,100,1000,m_couleur);
    }
    std::cout << "CIEL dessine avec succes !" << std::endl;
}


///Prog dessin du ciel // version surchargée
void Ciel::dessiner(Svgfile& out,Couleur couleurMoy)
{
    int decalageX(0), decalageY(0);
    uint8_t degrade(1);
    uint8_t r(0);
    uint8_t v(0);
    uint8_t b(0);

    r = couleurMoy.getR();
    v = couleurMoy.getV();
    b = couleurMoy.getB();
    m_couleur = couleurMoy; //modification de l'attribut couleur de l'objet

    for(int i=0; i<100;++i)
    {
        decalageX = decalageX + 20;
        decalageY = decalageY + 10;
        r= r + degrade;
        v= v + degrade;
        //b = b + degrade;
        couleurMoy.modifier(r,v,b); //couleur de test
        out.addEllipse(1350-decalageX,500-decalageY,100,1000,couleurMoy);
        std::cout << "CIEL dessine avec succesSSs !" << std::endl;

    }
}
