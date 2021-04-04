#ifndef GRAPHE_H
#define GRAPHE_H
#include <vector>
#include"sommet.h"
#include<iostream>
using namespace std;

class Graphe
{
public:
    Graphe();
    virtual ~Graphe();
    void loadData()const;
    virtual bool connectionExiste(Sommet*,Sommet*)const=0;
    bool ajoutSommetPossible(int)const;

    void ajoutSommet();

protected:
    vector<int>d_aps;
    vector<Sommet*>d_fs;
};

#endif // GRAPHE_H
