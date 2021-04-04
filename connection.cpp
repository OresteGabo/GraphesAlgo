#include "connection.h"

Connection::Connection(Sommet*src,Sommet*dest):
    d_src{src},d_dest{dest}
{}
Connection::~Connection(){}
Sommet* Connection::getSource()const{
    return d_src;
}
Sommet* Connection::getDestination()const{
    return d_dest;
}
Connection& Connection::operator=(const Connection& c){
    if(this==&c)
        return *this;
    d_src=c.getSource();
    d_dest=c.getDestination();
    return *this;
}
bool Connection::operator==(const Connection& c)const{
    if(&c==this)
        return true;
    return c.getSource()==d_src && c.getDestination()==d_dest;
}
