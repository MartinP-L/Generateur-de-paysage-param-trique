#include "coords.h"
#include <iostream>
#include <stdlib.h>


void Coords::translaterCoords()
{
    double x,y;
    std::cout<<std::endl<<"Saisisez le vecteur translation x et y"<<std::endl;
    std::cin>> x >> y; //récupération saisie des trois indices sommets
    m_x = m_x + x;
    m_y = m_y + y;
}


//- - - - - - - - - - - - - - - -

Coords::Coords(double x, double y)
    : m_x{x}, m_y{y}
{ }

Coords::Coords()
    : m_x{0}, m_y{0}
{ }

void Coords::afficher() const
{
    std::cout << "(" << m_x << ", " << m_y << ")";
}

void Coords::saisir()
{
    std::cout << "Veuillez saisir x et y SVP : "<<std::endl;
    std::cin >> m_x >> m_y;
}

void Coords::saisir(double x,double y)
{
    m_x = x;
    m_y = y;
}

double Coords::getX() const
{
    return m_x;
}

double Coords::getY() const
{
    return m_y;
}

/// Somme vectorielle (version courte)
Coords operator+(const Coords& c1, const Coords& c2)
{
    return {c1.m_x + c2.m_x, c1.m_y + c2.m_y };
}
