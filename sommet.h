#ifndef SOMMET_H
#define SOMMET_H


class Sommet
{
public:
    Sommet(int valeur);
    bool operator==(const Sommet&)const;
    Sommet& operator=(const Sommet&);
    int getValeur()const;
    void setValeur(int);
private:
    int d_valeur;
};

#endif // SOMMET_H
