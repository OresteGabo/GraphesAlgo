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

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void menuPrincipale();
    string choisirFichier();
    Graphe* creerGraphe(const string& fileName);
    void chargerFichiers();
private:
    vector<string>d_fichiers;
    Graphe* d_graphe;
    QPushButton* d_djkstra,*d_rang,*d_prufer,*d_kruskal,*d_tarjan,*d_exit,*d_addSommet,*d_addConnection,*d_removeConnection,*d_removeSommet,*d_go;
    QComboBox *d_liste;
    QTextEdit* d_debugger;

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


};
#endif // WIDGET_H
