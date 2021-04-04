#ifndef GRAPHENONORIENTE_H
#define GRAPHENONORIENTE_H
#include"sommet.h"
#include"graphe.h"
#include<iostream>
using namespace std;
class GrapheNonOriente:public Graphe
{
public:
    GrapheNonOriente();
    virtual ~GrapheNonOriente();
    virtual bool connectionExiste(Sommet*,Sommet*)const;

    void affiche()const;
};

#endif // GRAPHENONORIENTE_H
