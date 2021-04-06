#include "widget.h"
#include<iostream>
#include <QApplication>
#include"grapheorientevalue.h"
#include"graphenonorientevalue.h"
#include"grapheoriente.h"
#include"graphenonoriente.h"
#include<fstream>
#include<istream>
using namespace std;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
