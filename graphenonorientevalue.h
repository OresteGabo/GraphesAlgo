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
    virtual void affiche()const override;
    virtual void displayData()const override;
    virtual void createFile(const string&)const override;
    virtual void readFile(const string&) override;
private:

};

#endif // GRAPHENONORIENTEVALUE_H
