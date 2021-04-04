#include "connectionvalue.h"

ConnectionValue::ConnectionValue(Sommet*src,Sommet*dest,int val):
    Connection{src,dest},
    d_val{val}
{}
ConnectionValue::ConnectionValue(Sommet*src,Sommet*dest):
    ConnectionValue{src,dest,0}
{}

ConnectionValue::~ConnectionValue(){}
int ConnectionValue::getValeur()const{
    return d_val;
}
void ConnectionValue::setValeur(int val){
    d_val=val;
}
Connection& ConnectionValue::operator=(const ConnectionValue& c){
    if(this==&c)
        return *this;
    d_src=c.getSource();
    d_dest=c.getDestination();
    d_val=c.getValeur();
    return *this;
}
bool ConnectionValue::operator==(const ConnectionValue& c)const{
    if(this==&c)
        return true;
    return  d_src==c.getSource()&&
            d_dest==c.getDestination()&&
            d_val==c.getValeur();
}
