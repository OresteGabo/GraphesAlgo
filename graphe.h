#ifndef GRAPHE_H
#define GRAPHE_H
#include <vector>
#include"sommet.h"
#include<iostream>
#include <fstream>
#include <ostream>
#include<QTextEdit>
using namespace std;

class Graphe
{
public:
    Graphe();
    virtual ~Graphe();
    void loadData()const;
    virtual bool connectionExiste(Sommet*,Sommet*)const=0;
    bool ajoutSommetPossible(int)const;
    virtual void displayData()const=0;
    virtual void affiche(QTextEdit*)const=0;
    //virtual Sommet* getSommetByID(int)const=0;
    void ajoutSommet();
    virtual void createFile(const string&)const=0;
    virtual void readFile(const string&)=0;

protected:


};

#endif // GRAPHE_H
