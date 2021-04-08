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
    virtual void affiche(QTextEdit*)const override;
    void djkstra(QTextEdit*);
    void tarjan(QTextEdit*);
    virtual void readFile(const string&fileName)override;

    void empiler(vector<int> pile,int valeur);
    int depiler(vector<int> pile);
protected:



    //pour calculer les composantes foretements connexes
    vector<int>d_pile;
    vector<int>d_pilch;
    vector<int>d_prem;
    vector<bool>d_EstDansLaPile;
    vector<int>d_ro;
    vector<int>d_num;
    vector<int>d_cfc;

    vector<bool>d_visited;
    vector<int>d_dfsnum,low;

private:
    void tarjan(int sommet);

};

#endif // GRAPHEORIENTE_H
