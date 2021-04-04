#include "grapheoriente.h"

GrapheOriente::GrapheOriente()
{

}
GrapheOriente::~GrapheOriente(){

}
bool GrapheOriente::connectionExiste(Sommet* src,Sommet* dest)const{
    int n=d_aps[0];
    for(int i=1;i<=n;i++){
        int k=d_aps[i];
        while(d_fs[k]!=nullptr){
            if(
                    (src->getValeur()==d_fs[k]->getValeur() && dest->getValeur()==d_fs[i]->getValeur())
             ){
                return true;
            }
            k++;
        }
    }
    return false;
}

void GrapheOriente::affiche()const{
    cout<<"void affiche()const de GrapheOriente executed correctly"<<endl;
}
