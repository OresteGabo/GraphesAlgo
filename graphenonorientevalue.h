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

    virtual void affiche(QTextEdit*)const override;
    virtual void readFile(const string&fileName)override;
    void kruskal();
private:

};

#endif // GRAPHENONORIENTEVALUE_H
