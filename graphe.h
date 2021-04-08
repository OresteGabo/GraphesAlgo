#ifndef GRAPHE_H
#define GRAPHE_H
#include <vector>
#include"sommet.h"
#include<iostream>
#include <fstream>
#include <ostream>
#include<QTextEdit>
using namespace std;

class Graphe
{
public:
    Graphe();
    virtual ~Graphe();
    void loadData()const;

    virtual void affiche(QTextEdit*)const=0;
    virtual void readFile(const string&fileName);
    void ajoutSommet();
    void matriceFromFichier(const string &NomFichier);
    void fsApsFromFichier(const string &NomFichier);
    void matriceToFsAps();
    void fsApsToMatrice();
    int* nbSuccesseurs()const;
    int* nbPredecesseurs()const;
    int* getApp()const;
    int* getFp()const;
    int* distance(int sommet)const;
    int** distance()const;
    int* rangProfrondeur()const;


protected:
 int **d_matrice;
 int *d_fs,*d_aps;

};

#endif // GRAPHE_H
