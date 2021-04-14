#include "widget.h"
#include<iostream>
#include <QApplication>
#include"grapheorientevalue.h"
#include"graphenonorientevalue.h"
#include"grapheoriente.h"
#include"graphenonoriente.h"
#include"graphe.h"
#include<fstream>
#include<istream>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GrapheOrienteValue *g=new GrapheOrienteValue();
    g->matriceFromFichier("Matrice.txt");
    g->matriceToFsAps();

    Widget w(g);
    w.show();
    return a.exec();
}

