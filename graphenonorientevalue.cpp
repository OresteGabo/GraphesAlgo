#include "graphenonorientevalue.h"

GrapheNonOrienteValue::GrapheNonOrienteValue(){}
GrapheNonOrienteValue::~GrapheNonOrienteValue(){}
bool GrapheNonOrienteValue::connectionExiste(Sommet*,Sommet*)const{return true;}
void GrapheNonOrienteValue::affiche() const{
    cout<<"GrapheNonOrienteValue::affiche() executed correctly"<<endl;
}
