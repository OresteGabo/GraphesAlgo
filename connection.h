#ifndef CONNECTION_H
#define CONNECTION_H
#include"sommet.h"

class Connection
{
public:
    Connection(Sommet*,Sommet*);
    virtual~Connection();
    virtual Connection& operator=(const Connection&);
    virtual bool operator==(const Connection&)const;
    Sommet* getSource()const;
    Sommet* getDestination()const;
protected:
    Sommet* d_src,*d_dest;
};

#endif // CONNECTION_H
