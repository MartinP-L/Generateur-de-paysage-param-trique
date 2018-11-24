#include "maillage.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Sommet.h"
#include "maillage.h"
#include "../formes/Triangle.h"
#include "stdlib.h"

void Maillage::afficherSommets(Maillage maillage1) const
{
    std::vector<Sommet*> collection;
    collection = maillage1.geterSommet();
    for(double i=0; i<collection.size();++i)
    {
        collection[i]->afficher();
        std::cout << std :: endl;
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - -


void Maillage::selection(Svgfile& out,bool selec)
{
    double indice,x,y;
    Sommet sommet;

    if(collection_sommets.size() == 0) // si tableau vide
    {
        std::cout<<std::endl<<"Aucun sommet existant, creez en au moins trois via le menu 3 et reessayez"<<std::endl;
        system("pause");
    }
    else //sinon
    {
        if(selec == true)
        {
            std::cout<<std::endl<<"Saisisez l indice du sommet a selectionner"<<std::endl;
            std::cin>> indice; //récupération saisie des trois indices sommets
            if(indice>collection_sommets.size()-1) //si l'indice entré ne peut pas exister
            {
                std::cout<<std::endl<<"la case d indice "<< indice << " n existe pas" << std::endl <<std::endl;
                system("pause");
            }
            else //sinon -> si l'indice est valide
            {
                //selection du sommet
                collection_sommets[indice]->selectionSommet();
                //ajout effet graphique de la selection
                x = collection_sommets[indice]->getPosition().getX();
                y = collection_sommets[indice]->getPosition().getY();
                out.addCircle(x, y, 10, 2, "green");

            }
        }

        if(selec == false)
        {
            std::cout<<std::endl<<"Saisisez l indice du sommet a deselectionner"<<std::endl;
            std::cin>> indice; //récupération saisie des trois indices sommets
            if(indice>collection_sommets.size()-1) //si l'indice entré ne peut pas exister
            {
                std::cout<<std::endl<<"la case d indice "<< indice << " n existe pas" << std::endl <<std::endl;
                system("pause");
            }
            else //sinon -> si l'indice est valide
            {
                collection_sommets[indice]->deselectionSommet();
            }

        }
    }
}


// - - - - - - - - - - - - - - - - - - - - - - - -

void Maillage::translater()
{
    if(collection_sommets.size() == 0) // si tableau vide
    {
        std::cout<<std::endl<<"Aucun sommet existant, creez en au moins trois via le menu 3 et reessayez"<<std::endl;
        system("pause");
    }
    else //sinon
    {


        for(size_t i=0;i<collection_sommets.size();++i)
        {
            collection_sommets[i]->afficher();
            if(collection_sommets[i]->getSelection() == true) //si on trouve un sommet sélectionné
            {
                std::cout<<std::endl<<"! ! ! AVANT TRANSLATION ! ! !"<<std::endl;
                collection_sommets[i]->afficher();

                collection_sommets[i]->translaterPosition();

                std::cout<<std::endl<<"! ! ! APRES TRANSLATION ! ! !"<<std::endl;
                collection_sommets[i]->afficher();
            }
        }
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - -

void Maillage::ajouterSommet(Sommet* nouveauSommet)
{
    collection_sommets.push_back(nouveauSommet);
}

// - - - - - - - - - - - - - - - - - - - - - - - -

void Maillage::ajouterTriangle(Triangle* nouveauTriangle)
{
    collection_triangles.push_back(nouveauTriangle);
}

// - - - - - - - - - - - - - - - - - - - - - - - -

std::vector<Sommet*> Maillage::geterSommet()
{
    return collection_sommets;
}

// - - - - - - - - - - - - - - - - - - - - - - - -

std::vector<Triangle*> Maillage::geterTriangle()
{
    return collection_triangles;
}



