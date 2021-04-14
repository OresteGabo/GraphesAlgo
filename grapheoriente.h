#ifndef GRAPHEORIENTE_H
#define GRAPHEORIENTE_H
#include"graphe.h"
#include<iostream>
#include<stack>
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
    void tarjan(int sommet);
    void composantC();
    void tarjan(int vertex, stack<int> st);


    GrapheOriente calculerGrapheReduit(const vector<int>& prem,const vector<int>& pilch,const vector<int>& cfc) const;
    void traverse(int s,vector<int>& prem,vector<int>& pilch,vector<int>& cfc,stack<int>& tarj,vector<bool>& enTarj,int& ns,int& nc,vector<int>& num,vector<int>& ro) const;
    void calculerCFC(std::vector<int>& prem,vector<int>& pilch,vector<int>& cfc) const;








protected:



    //pour calculer les composantes foretements connexes
    vector<int>d_pile;
    vector<int>d_pilch;
    vector<int>d_prem;
    vector<bool>d_EstDansLaPile;
    vector<int>d_ro;
    vector<int>d_cfc;




    bool* d_visite;
    int*d_dfsnum,*d_low;
    int d_num=0;

private:


};

#endif // GRAPHEORIENTE_H
