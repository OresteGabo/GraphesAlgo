#include "graphe.h"

Graphe::Graphe()
{

}
Graphe::~Graphe(){

}
void Graphe::loadData()const{}

void Graphe::ajoutSommet(){}
bool Graphe::ajoutSommetPossible(int val)const{
    for(int x=0;x<d_fs.size();x++){
        if(val==d_fs[0]->getValeur())
            return false;
    }
    return true;
}
