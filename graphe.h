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

    virtual void affiche(QTextEdit*)const=0;
    virtual void readFile(const string&fileName);
    void ajoutSommet();
    void matriceFromFichier(const string &NomFichier);  //TESTED
    void fsApsFromFichier(const string &NomFichier);   //TESTED
    void matriceToFsAps();  //TESTED
    void fsApsToMatrice();  //TESTED
    int* nbSuccesseurs()const; //TESTED
    int* nbPredecesseurs()const;//TESTED
    int* getApp()const;//TESTED
    int* getFp()const;//TESTED
    int* distance(int sommet)const;//TESTED
    int** distance()const;//TESTED
    int* rangProfrondeur()const;

    void afficheFsAps()const;  //TESTED
    void afficheTab(int*)const;
    void afficheMatrice()const;   //TESTED
    int *getFs()const;      //TESTED
    int *getAps()const;     //TESTED
    int **getMatrice()const;    //TESTED

    //Affichage dans un textEdit de QT
    void afficheFsAps(QTextEdit*)const;
    void afficheMatrice(QTextEdit* debugger)const;
    int* rang(int *&pileDesEntrets,int *&pileDesElement);
    int* rang(int *&num)const;

    //Les fonction pour les tests
    void clearFs();
    void clearAps();
    void clearTable(int *&t,int taill);
    void afficheDDE()const; //TESTED
    void afficheDDI()const;  //TESTED
    void afficheFpApp()const;
    void afficheMatrice(int** m)const;




protected:
 int **d_matrice;
 int *d_fs,*d_aps;

private:
 void creerUnFichierMatrice()const;

};

#endif // GRAPHE_H
