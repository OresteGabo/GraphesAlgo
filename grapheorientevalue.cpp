#include "grapheorientevalue.h"

GrapheOrienteValue::GrapheOrienteValue()
{

}
GrapheOrienteValue::~GrapheOrienteValue()
{

}
bool GrapheOrienteValue::connectionExiste(Sommet*,Sommet*)const{
    return true;
}

void GrapheOrienteValue::affiche()const{
    cout<<"The object is well created";
}
