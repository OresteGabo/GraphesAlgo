#include "sommet.h"

Sommet::Sommet(int valeur):
    d_valeur{valeur}
{

}
int Sommet::getValeur()const{
    return d_valeur;
}
void Sommet::setValeur(int valeur){
    d_valeur=valeur;
}
bool Sommet::operator==(const Sommet& s)const{
    if(&s==this)
        return true;
    return s.getValeur()==d_valeur;
}
Sommet& Sommet::operator=(const Sommet& s){
    if(this==&s)
        return *this;
    d_valeur=s.getValeur();
    return *this;
}
