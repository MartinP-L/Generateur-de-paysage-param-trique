#include "Sommet.h"
#include <iostream>
#include "../svg/svgfile.h"


void Sommet::saisir()
{
    m_position.saisir();
    m_selection = false;
}

void Sommet::saisir(double x, double y)
{
    m_position.saisir(x,y);
    m_selection = false;
}

// - - - - - - - - - - - - - - - - -

void Sommet::selectionSommet()
{
    m_selection = true;
}

void Sommet::deselectionSommet()
{
    m_selection = false;
}

// - - - - - - - - - - - - - - - - -

void Sommet::translaterPosition()
{
    m_position.translaterCoords();
}


// - - - - - - - - - - - - - - - - -

void Sommet::afficher() const
{
    m_position.afficher();
}

// - - - - - - - - - - - - - - - - -

Coords Sommet::getPosition()const
{
    return m_position;
}

bool Sommet::getSelection()const
{
    return m_selection;
}

// - - - - - - - - - - - - - - - - -

void Sommet::setPosition(double nouv_x,double nouv_y)
{
    m_position.saisir(nouv_x,nouv_y);
}

// - - - - - - - - - - - - - - - - -

void Sommet::selectionner(bool selec)
{
    if(selec == true)
        m_selection = true;
    if(selec == false)
        m_selection = false;

}



