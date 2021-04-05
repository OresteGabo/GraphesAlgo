#ifndef GRAPHENONORIENTE_H
#define GRAPHENONORIENTE_H
#include"sommet.h"
#include"graphe.h"
#include<iostream>
#include"connection.h"
using namespace std;
class GrapheNonOriente:public Graphe
{
public:
    GrapheNonOriente();
    virtual ~GrapheNonOriente();
    virtual bool connectionExiste(Sommet*,Sommet*)const override;
    virtual void displayData()const override;
    virtual void affiche()const override;
    virtual void ajouterConnection();
    void generateFile(const string &)const;

    virtual void createFile(const string&)const override;
    virtual void readFile(const string&) override;
protected:
    vector<Sommet*> d_sommets;
    vector<Connection*> d_connections;
};

#endif // GRAPHENONORIENTE_H
