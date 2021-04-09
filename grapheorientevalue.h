#ifndef GRAPHEORIENTEVALUE_H
#define GRAPHEORIENTEVALUE_H
#include"grapheoriente.h"
#include<iostream>
using namespace std;
class GrapheOrienteValue:public GrapheOriente{
public:
    GrapheOrienteValue();
    virtual ~GrapheOrienteValue();
    virtual void affiche(QTextEdit*)const override;
    virtual void djkstra(QTextEdit*);
    void ordonnancement(int *&fpc, int *&appc, int *&lc,int *&d)const;
    void ordonnancement( int *d, int *&fpc, int *&appc, int *&lc)const;
    virtual void readFile(const string&fileName)override;
};

#endif // GRAPHEORIENTEVALUE_H
