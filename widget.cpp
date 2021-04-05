#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent),d_graphe{nullptr}
{

    /*
     * QPushButton* d_djkstra,*d_rang,*d_prufer,*d_kruskal,*d_tarjan,d_exit;
     * QComboBox *d_liste;
     * QTextEdit* d_debugger;
     */


    d_djkstra=new QPushButton("Djkstra");
    d_rang=new QPushButton("Rang");
    d_prufer=new QPushButton("Prufer");
    d_kruskal=new QPushButton("Kruskal");
    d_tarjan=new QPushButton("Tarjan");
    d_liste=new QComboBox;
    d_debugger=new QTextEdit;
    chargerFichiers();
    //int size=d_liste->size();

    for(int x=0;x<(int)d_fichiers.size();x++){
        d_liste->addItem(QString::fromStdString(d_fichiers[x]) );
    }


    d_exit=new QPushButton("Exit");


    auto h1=new QHBoxLayout;
    auto h2=new QHBoxLayout;
    auto h3=new QHBoxLayout;

    auto buttons=new QVBoxLayout;
    auto area=new QVBoxLayout;
    auto all=new QVBoxLayout(this);


    h1->addWidget(d_liste,5);
    h1->addWidget(new QPushButton("GO"),1,Qt::AlignRight);
    buttons->addWidget(d_djkstra);
    buttons->addWidget(d_rang);
    buttons->addWidget(d_prufer);
    buttons->addWidget(d_kruskal);
    buttons->addWidget(d_tarjan);
    h2->addLayout(buttons);

    area->addWidget(d_debugger);

    h2->addLayout(area);
    h3->addWidget(d_exit);

    all->addLayout(h1);
    all->addLayout(h2);
    all->addLayout(h3);





    //menuPrincipale();

}
void Widget::chargerFichiers(){
    string file1="fichier1.txt",file2="fichier2.txt",file3="fichier3.txt",file4="fichier4.txt",file5="fichier5.txt",file6="fichier6.txt",file7="fichier7.txt",file8="fichier8.txt",file9="fichier9.txt",file10="fichier10.txt";
    d_fichiers.push_back(file1);
    //QString str=">>Fichier "+file1+ " created, and added in a vector";
    d_debugger->append("    >>chargement de fichiers");
    d_fichiers.push_back(file2);
    d_fichiers.push_back(file3);
    d_fichiers.push_back(file4);
    d_fichiers.push_back(file5);
    d_fichiers.push_back(file6);
    d_fichiers.push_back(file7);
    d_fichiers.push_back(file8);
    d_fichiers.push_back(file9);
    d_fichiers.push_back(file10);
}
Widget::~Widget()
{
}

Graphe* Widget::creerGraphe(const string& fileName){
    string code;
    ifstream file(fileName);
    file>>code;

    if(code=="CODE00"){
        d_debugger->append("     >>Le fichier contient un graphe non orienté et non valué");
        GrapheNonOriente *graphe=new GrapheNonOriente();
        graphe->readFile(fileName);
        return graphe;
    }else if(code=="CODE01"){
        d_debugger->append("     >>Le fichier contient un graphe non orienté et valué");
        GrapheNonOrienteValue *graphe=new GrapheNonOrienteValue();
        graphe->readFile(fileName);
        return graphe;
    }else if(code=="CODE10"){
        d_debugger->append("     >>Le fichier contient un graphe orienté et non valué");
        GrapheOriente *graphe=new GrapheOriente();
        graphe->readFile(fileName);
        return graphe;
    }else if(code=="CODE11"){
        d_debugger->append("     >>Le fichier contient un graphe orienté et valué");
        GrapheOrienteValue *graphe=new GrapheOrienteValue();
        graphe->readFile(fileName);
        return graphe;
    }
    d_debugger->append("     >>Le fichier inconnu");
    return nullptr;
}


