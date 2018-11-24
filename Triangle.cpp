#include "../codesBase/couleur.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "../maillage/Sommet.h"
#include "Triangle.h"
#include "../codesBase/couleur.h"

void Triangle::creerTriangleV2(Maillage maillage1,int a, int b, int c)
{
    Sommet sommet1,sommet2,sommet3;
    //Couleur couleur;

    std::vector<Sommet*> collection;
    collection = maillage1.geterSommet(); //récupération du tableau de Sommets dans maillage1

    if(collection.size() == 0) // si tableau vide
    {
        std::cout<<std::endl<<"Aucun sommet existant, creez en au moins trois via le menu 3 et reessayez"<<std::endl;
        system("pause");
    }
    else //sinon
    {
            //récupération des sommets sélectionnés
            sommet1 = *collection[a];
            sommet2 = *collection[b];
            sommet3 = *collection[c];

            //copie des valeurs dans les sommets de l'objet triangle
            m_sommet1 = sommet1;
            m_sommet2 = sommet2;
            m_sommet3 = sommet3;

            /*std::cout<<std::endl<<"Saisisez la couleur, format r v b"<<std::endl;
            m_couleur.saisir();*/

    }
}

// - - - - - - - - - - - - - - - - - - - - - - - -


/*
void Triangle::creerTriangle(Maillage maillage1)
{
    double i1,i2,i3;
    Sommet sommet1,sommet2,sommet3;
    //Couleur couleur;

    std::vector<Sommet*> collection;
    collection = maillage1.geterSommet(); //récupération du tableau de Sommets dans maillage1

    if(collection.size() == 0) // si tableau vide
    {
        std::cout<<std::endl<<"Aucun sommet existant, creez en au moins trois via le menu 3 et reessayez"<<std::endl;
        system("pause");
    }
    else //sinon
    {
        std::cout<<std::endl<<"Saisisez les 3 indices sommets"<<std::endl;
        std::cin>> i1 >> i2 >> i3; //récupération saisie des trois indices sommets
        if((i1>collection.size()-1) || (i3>collection.size()-1) || (i3>collection.size()-1)) //si un des indices entrés ne peuvent pas exister
        {
            if(i1>collection.size()-1)
                std::cout<<std::endl<<"la case d indice "<< i1 << " n existe pas" << std::endl;

            if(i2>collection.size()-1)
                std::cout<<std::endl<<"la case d indice "<< i2 << " n existe pas" << std::endl;

            if(i3>collection.size()-1)
                std::cout<<std::endl<<"la case d indice "<< i3 << " n existe pas" << std::endl;

            std::cout<<std::endl;
            system("pause");
        }
        else //sinon -> si toutes les cases sont valides
        {
            //récupération des sommets sélectionnés
            sommet1 = *collection[i1];
            sommet2 = *collection[i2];
            sommet3 = *collection[i3];

            //copie des valeurs dans les sommets de l'objet triangle
            m_sommet1 = sommet1;
            m_sommet2 = sommet2;
            m_sommet3 = sommet3;

            std::cout<<std::endl<<"Saisisez la couleur, format r v b"<<std::endl;
            m_couleur.saisir();


        }
    }
}
*/

// - - - - - - - - - - - - - - - - - - - - - - - -

Sommet Triangle::getSommet(int i)const
{
    if(i==1)
        return m_sommet1;
    if(i==2)
        return m_sommet2;
    if(i==3)
        return m_sommet3;
}

Couleur Triangle::getCouleur()const
{
    return m_couleur;
}

