#include "graphenonoriente.h"

GrapheNonOriente::GrapheNonOriente()
{

}
GrapheNonOriente::~GrapheNonOriente(){

}
bool GrapheNonOriente::connectionExiste(Sommet* src,Sommet*dest)const{
    int n=d_aps[0];
    for(int i=1;i<=n;i++){
        int k=d_aps[i];
        while(d_fs[k]!=nullptr){
            if(
                    (dest->getValeur()==d_fs[k]->getValeur() && src->getValeur()==d_fs[i]->getValeur())||
                    (src->getValeur()==d_fs[k]->getValeur() && dest->getValeur()==d_fs[i]->getValeur())
             ){
                return true;
            }
            k++;
        }
    }
    return false;
}
/*bool GrapheNonOriente::ajoutSommetPossible(int)const{
    return true;
}*/
void GrapheNonOriente::affiche()const{
    cout<<"void affiche()const de GrapheNonOriente executed correctly"<<endl;
}
