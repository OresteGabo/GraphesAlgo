#ifndef GRAPHEORIENTE_H
#define GRAPHEORIENTE_H
#include"graphe.h"
#include<iostream>
using namespace std;
class GrapheOriente:public Graphe
{
public:
    GrapheOriente();
    virtual~GrapheOriente();
    virtual bool connectionExiste(Sommet*,Sommet*)const;
    void affiche()const;
};

#endif // GRAPHEORIENTE_H
