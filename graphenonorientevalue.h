#ifndef GRAPHENONORIENTEVALUE_H
#define GRAPHENONORIENTEVALUE_H
#include"sommet.h"
#include"graphenonoriente.h"
#include<iostream>
using namespace std;

class GrapheNonOrienteValue:public GrapheNonOriente
{
public:
    GrapheNonOrienteValue();
    virtual~GrapheNonOrienteValue();
    virtual bool connectionExiste(Sommet*,Sommet*)const override;
    void affiche()const;

};

#endif // GRAPHENONORIENTEVALUE_H