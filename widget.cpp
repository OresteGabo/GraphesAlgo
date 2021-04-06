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
    d_addSommet=new QPushButton("Add sommet");
    d_addConnection=new QPushButton("Add connection");
    d_removeConnection=new QPushButton("remove Connection");
    d_removeSommet=new QPushButton("remove Sommet");
    d_go=new QPushButton("GO");
    d_liste=new QComboBox;
    d_debugger=new QTextEdit;
    d_debugger->setTextColor(QColor(0,0,100));
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
    h1->addWidget(d_go,1,Qt::AlignRight);
    buttons->addWidget(d_djkstra);
    buttons->addWidget(d_rang);
    buttons->addWidget(d_prufer);
    buttons->addWidget(d_kruskal);
    buttons->addWidget(d_tarjan);
    buttons->addWidget(d_addSommet);
    buttons->addWidget(d_addConnection);
    buttons->addWidget(d_removeConnection);
    buttons->addWidget(d_removeSommet);

    h2->addLayout(buttons);

    area->addWidget(d_debugger);

    h2->addLayout(area);
    h3->addWidget(d_exit);

    all->addLayout(h1);
    all->addLayout(h2);
    all->addLayout(h3);




    d_debugger->setEnabled(false);
    //d_debugger->setTextBackgroundColor(QColor(255,255,0));

    //menuPrincipale();
    connect(d_djkstra,&QPushButton::clicked,this,&Widget::onDjkstra);
    connect(d_rang,&QPushButton::clicked,this,&Widget::onRang);
    connect(d_prufer,&QPushButton::clicked,this,&Widget::onPrufer);
    connect(d_kruskal,&QPushButton::clicked,this,&Widget::onKruskal);
    connect(d_tarjan,&QPushButton::clicked,this,&Widget::onTarjan);
    connect(d_addSommet,&QPushButton::clicked,this,&Widget::onAddSommet);
    connect(d_addConnection,&QPushButton::clicked,this,&Widget::onAddConnection);
    connect(d_removeSommet,&QPushButton::clicked,this,&Widget::onRemoveSommet);
    connect(d_removeConnection,&QPushButton::clicked,this,&Widget::onRemoveConnection);
    connect(d_exit,&QPushButton::clicked,this,&Widget::onExit);
    connect(d_go,&QPushButton::clicked,this,&Widget::onGO);


    //connect(d_liste,SIGNAL(currentTextChanged(const QString &)), this, SLOT(onListe(const QString &)));

    connect(d_liste,&QComboBox::currentIndexChanged,this,&Widget::onListe);

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

void Widget::onListe(){
    d_debugger->append("    >>Liste selected");

}
void Widget::onDjkstra(){
    d_debugger->append("    >>Djkstra clicked");
}
void Widget::onRang(){
    d_debugger->append("    >>Rang clicked");
}
void Widget::onPrufer(){
    d_debugger->append("    >>prufer clicked");
}
void Widget::onKruskal(){
    d_debugger->append("    >>kruskal clicked");
}
void Widget::onTarjan(){
    d_debugger->append("    >>Trajan clicked");
}
void Widget::onExit(){
    d_debugger->append("    >>Exit clicked");
    close();
}
void Widget::onAddSommet(){
    d_debugger->append("    >>Sommet clicked");
}
void Widget::onAddConnection(){
    d_debugger->append("    >>Add connection clicked");
}
void Widget::onRemoveConnection(){
    d_debugger->append("    >>Remove connection clicked");
}
void Widget::onRemoveSommet(){
    d_debugger->append("    >>Remove sommet clicked");
}
void Widget::onGO(){
    d_debugger->append("    >>Go clicked");
}

