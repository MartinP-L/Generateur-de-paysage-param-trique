#ifndef COORDS_H_INCLUDED
#define COORDS_H_INCLUDED


class Coords
{
    public :
        Coords(double x, double y);
        Coords();

        void afficher() const;
        void saisir();
        void saisir(double x, double y); // version surchargée pour translation

        double getX() const;
        double getY() const;

        friend Coords operator+(const Coords& c1, const Coords& c2);
        void translaterCoords();

    private :
        double m_x;
        double m_y;
};


#endif // COORDS_H_INCLUDED
