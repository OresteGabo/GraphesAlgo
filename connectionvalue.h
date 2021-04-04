#ifndef CONNECTIONVALUE_H
#define CONNECTIONVALUE_H
#include"sommet.h"
#include"connection.h"

class ConnectionValue:public Connection
{
public:
    ConnectionValue(Sommet*,Sommet*);
    ConnectionValue(Sommet*,Sommet*,int val);
    virtual ~ConnectionValue();
    int getValeur()const;
    void setValeur(int);
    virtual Connection& operator=(const ConnectionValue&);
    virtual bool operator==(const ConnectionValue&)const;
private:
    int d_val;
};

#endif // CONNECTIONVALUE_H
