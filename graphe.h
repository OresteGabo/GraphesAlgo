#ifndef GRAPHE_H
#define GRAPHE_H
#include <vector>
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
    int* rangProfrondeur(QTextEdit* d)const;
    bool djikstra (int s, int *&d, int *&pred);

    void afficheFsAps()const;  //TESTED
    void afficheFsAps(int*,QTextEdit*)const;  //TESTED
    void afficheTab(int*)const;
    void afficheTab(int*tab,QTextEdit* d)const;
    void afficheMatrice()const;   //TESTED
    void afficheMatrice(QTextEdit* debugger)const;//TESTED
    void afficheMatrice(QTextEdit* debugger,int**)const;//TESTED
    void afficheDistance(QTextEdit* debugger)const;//TESTED
    int *getFs()const;      //TESTED
    int *getAps()const;     //TESTED
    int **getMatrice()const;    //TESTED


    //Affichage dans un textEdit de QT
    void afficheFsAps(QTextEdit*)const;
    int* det_rang( int *&num);
    int* rang(int *&pileDesEntrets,int *&pileDesElement);
    int* rang(int *&num)const;

    //Les fonction pour les tests
    void clearFs();
    void clearAps();
    void clearTable(int *&t,int taill);
    void afficheDDE()const; //TESTED
    void afficheDDE(QTextEdit*d)const;
    void afficheDDI(QTextEdit*)const;  //TESTED
    void afficheDDI()const;  //TESTED
    void afficheFpApp()const;
    void afficheMatrice(int** m)const;




protected:
 int **d_matrice;
 int *d_fs,*d_aps;
 QTextEdit* d_debugger;

private:
 void creerUnFichierMatrice()const;

};

#endif // GRAPHE_H
