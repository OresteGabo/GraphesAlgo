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
    virtual void affiche()const override;
    virtual void displayData()const override;
    virtual void createFile(const string&)const override;
    virtual void readFile(const string&)override;
};

#endif // GRAPHEORIENTEVALUE_H
