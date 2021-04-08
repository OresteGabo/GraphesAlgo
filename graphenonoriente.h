#ifndef GRAPHENONORIENTE_H
#define GRAPHENONORIENTE_H
#include"sommet.h"
#include"graphe.h"
#include<iostream>
#include<QTextEdit>
using namespace std;
class GrapheNonOriente:public Graphe
{
public:
    GrapheNonOriente();
    virtual ~GrapheNonOriente();
    virtual void affiche(QTextEdit*)const override;
    virtual void readFile(const string&fileName)override;

protected:
};

#endif // GRAPHENONORIENTE_H
