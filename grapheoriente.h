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
    virtual bool connectionExiste(Sommet*,Sommet*)const override;
    virtual void affiche(QTextEdit*)const override;
    virtual void displayData()const override;
    virtual void createFile(const string&)const override;
    virtual void readFile(const string&) override;
protected:
    vector<int>d_aps;
    vector<Sommet*>d_fs;
};

#endif // GRAPHEORIENTE_H
