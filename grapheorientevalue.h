#ifndef GRAPHEORIENTEVALUE_H
#define GRAPHEORIENTEVALUE_H
#include"grapheoriente.h"
#include<iostream>
using namespace std;
class GrapheOrienteValue:public GrapheOriente
{
public:
    GrapheOrienteValue();
    virtual ~GrapheOrienteValue();
    virtual bool connectionExiste(Sommet*,Sommet*)const override;
    void affiche()const;
};

#endif // GRAPHEORIENTEVALUE_H
