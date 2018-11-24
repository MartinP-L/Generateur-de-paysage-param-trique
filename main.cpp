#include <iostream>
#include "ssProgs/menu.h"
#include "objetsComplexes/Arbre.h"
#include "codesBase/util.h"
#include "objetsComplexes/Immeuble.h"
#include "objetsComplexes/Ciel.h"
#include "maillage/MaillageArrierePlan.h"

///________________________________________
///CODE PAR
///         REMI FIORENZA & GUILLAUME MARIE & MARTIN PUYOU-LASCASSIES
///TD2 - ING 2022
///________________________________________


int main()
{
    double Xalea(0),Yalea(0),LargeurAlea(0),HauteurAlea(0),ProfondeurAlea;
    uint8_t ra,va,ba;
    Svgfile out;
    out.addGrid();

    MaillageArrierePlan objetsArrierePlan;

    for(int i=0 ; i< 15 ; ++i)
    {
        Xalea = util::alea(50,1200);
        Yalea = util::alea(5,600);
        LargeurAlea = util::alea(25,150);
        HauteurAlea = util::alea(35,150);
        ProfondeurAlea = util::alea(20,100);
        ra = util::alea(50,205);
        va = util::alea(50,205);
        ba = util::alea(50,205);
        Couleur couleur(ra,va,ba); //couleur de test

        Immeuble* immeubleTemp = nullptr;
        immeubleTemp = new Immeuble{Xalea,Yalea,LargeurAlea,HauteurAlea,ProfondeurAlea,couleur};

        objetsArrierePlan.ajouterObjet(immeubleTemp);
    }

    objetsArrierePlan.dessinerObjets(out);


    ///TEST CIEL : _____________________________
    /*Couleur couleurCiel(30,144,255);
    Ciel cielTest(couleurCiel);
    cielTest.dessiner(out,couleurCiel);*/


    ///TEST ARBRES : _____________________________
    /*

    Couleur couleurTronc(133,109,77);
    Couleur couleurFeuillesMoy(30,125,20);


    for(int i=0; i<10 ; ++i)
    {

        xa = util::alea(0,1300);
        ya = util::alea(0,800);
        std::cout << xa << " , " << ya << std::endl;
        taillea = util::alea(20,50);
        Arbre arbreTest(xa,ya,taillea,couleurTronc,couleurFeuillesMoy);
        arbreTest.dessiner(out);
    }*/
    ///___________________________________________

    /*
    ///TESTS IMMEUBLES :__________________________
    double Xalea,Yalea,LargeurAlea,HauteurAlea,profondeurAlea,ra,va,ba;

    for(int i=0; i<20;++i)
    {
        Xalea = util::alea(50,1200);
        Yalea = util::alea(5,600);
        LargeurAlea = util::alea(25,150);
        HauteurAlea = util::alea(35,150);
        profondeurAlea = util::alea(20,100);
        ra = util::alea(50,205);
        va = util::alea(50,205);
        ba = util::alea(50,205);
        Couleur couleur(ra,va,ba); //couleur de test
        Immeuble immeubletemp(Xalea,Yalea,LargeurAlea,HauteurAlea,profondeurAlea,couleur);
        immeubletemp.dessinerImmeuble(out);
    }*/
    /*
    affichage_entete(); //affichage bannière de bienvenue
    menu_console(); //affchage du menu console
    */
    return 0;
}
