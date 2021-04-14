#ifndef WIDGET_H
#define WIDGET_H
#include<iostream>
#include <QWidget>
#include <qapplication.h>
#include <qpushbutton.h>
#include <qslider.h>
#include <qlcdnumber.h>
#include <qfont.h>
#include"graphe.h"
#include"grapheorientevalue.h"
#include"graphenonorientevalue.h"
#include"grapheoriente.h"
#include"graphenonoriente.h"
#include<fstream>
#include<istream>
#include <QComboBox>
#include<QTextEdit>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QString>
#include<QInputDialog>
#include<QDir>

typedef struct {
    int s; // première extrmité de l'arète ( 1er sommet de l'arète )
    int t; // deuxième extrmité de l'arète ( 2éme sommet de l'arète )
    double p; // poids de l'arète
} arete;
typedef struct {
    int n; // nombre de sommets du graphe
    int m; //nombre d'arètes du graphe ;
    arete *a; // tableau des aretes du graphe
} graphe;
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(Graphe*g,QWidget *parent = nullptr);
    ~Widget();
    void menuPrincipale();
    string choisirFichier();
    Graphe* creerGraphe(const string& fileName);
    void chargerFichiers();
    bool fichierValide(const string&)const;
    void loadFile(const string& fileName);
    void generateRandomFiles();
    void saisie(graphe &g);//pour kruskal^

    void saisie_fich(const string& nom, int** &a);//pour prufer

private:
    vector<string>d_fichiers;
   Graphe* d_graphe;
    QPushButton* d_djkstra,*d_rang,*d_prufer,*d_kruskal,*d_tarjan,*d_exit,*d_addSommet,*d_addConnection,
    *d_removeConnection,*d_removeSommet,*d_go,*d_display,*d_fsAps,*d_matrice,*d_nbSuccesseur,*d_nbPredecesseur,*d_distance, *d_ddi,*d_dde;
    QComboBox *d_liste;
    QTextEdit* d_debugger;
    string d_fichier;//current file

    void MAJBoutons();
    void MAJFichier();
    void disableAllButtons();

private slots:
    void onListe();
    void onDjkstra();
    void onRang();
    void onPrufer();
    void onKruskal();
    void onTarjan();
    void onExit();
    void onAddSommet();
    void onAddConnection();
    void onRemoveConnection();
    void onRemoveSommet();
    void onGO();
    void onClear();
    void onDisplay();
    void onFsAps();
    void onMatrice();
    void onDdi();
    void onDde();
    void onNbPredecesseur();
    void onNbSuccesseur();
    void onDistance();
    void onOrdonnancement();



};
#endif // WIDGET_H
