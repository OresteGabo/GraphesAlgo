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
    auto d_clear=new QPushButton("clear");
    d_removeSommet=new QPushButton("remove Sommet");
    d_display=new QPushButton("display");
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


    h1->addWidget(d_liste,10);
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
    buttons->addWidget(d_display);

    h2->addLayout(buttons);

    area->addWidget(d_debugger);

    h2->addLayout(area);
    h3->addWidget(d_exit,10);
    h3->addWidget(d_clear,1,Qt::AlignRight);

    all->addLayout(h1);
    all->addLayout(h2);
    all->addLayout(h3);




    d_debugger->setEnabled(false);
    MAJFichier();
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
    connect(d_clear,&QPushButton::clicked,this,&Widget::onClear);
    connect(d_display,&QPushButton::clicked,this,&Widget::onDisplay);
    //connect(d_liste,&QComboBox::currentTextChanged(const QString&),this,&Widget::onGO());
    //connect(d_liste, SIGNAL(currentTextChanged(const string&)), this, SLOT(onChangeFile(const string&)));

    connect(d_go,&QPushButton::clicked,this,&Widget::onGO);


    //connect(d_liste,SIGNAL(currentTextChanged(const QString &)), this, SLOT(onListe(const QString &)));
    generateRandomFiles();
    connect(d_liste,&QComboBox::currentIndexChanged,this,&Widget::onListe);
    MAJFichier();
    MAJBoutons();
    resize(900,500);
}
void Widget::chargerFichiers(){
    string file1="fichier1.txt",file2="fichier2.txt",file3="fichier3.txt",file4="fichier4.txt",file5="fichier5.txt",file6="fichier6.txt",file7="fichier7.txt",file8="fichier8.txt",file9="fichier9.txt",file10="fichier10.txt";
    d_fichiers.push_back(file1);
    //QString str=">>Fichier "+file1+ " created, and added in a vector";

    d_fichiers.push_back(file2);
    d_fichiers.push_back(file3);
    d_fichiers.push_back(file4);
    d_fichiers.push_back(file5);
    d_fichiers.push_back(file6);
    d_fichiers.push_back(file7);
    d_fichiers.push_back(file8);
    d_fichiers.push_back(file9);
    d_fichiers.push_back(file10);
    d_debugger->append("    >>chargement de fichiers");
    /*vector<QString> vect=generateRandomFiles();
    d_debugger->append(">>The size of the vector is "+QString::number(vect.size()));
    for(unsigned long x=0;x<vect.size();x++){
        d_fichiers.push_back(vect[x].toStdString());
        d_debugger->append(">>"+vect[x]);
    }*/
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
bool Widget::fichierValide(const string&fileName)const{
    ifstream ist(fileName);
    if(!ist){
        d_debugger->append(">>FILE_NOT_FOUND");
        return false;
    }
    string code;
    ist>>code;
    if(code=="CODE00" || code=="CODE01" || code=="CODE10" || code=="CODE11"){
        d_debugger->append("     >>Le fichier chargé avec success");
        return true;
    }
    d_debugger->append("     >>FILE_WRONG_TYPE");
    return false;
}
void Widget::loadFile(const string& fileName){
    if(fichierValide(fileName)){
        d_graphe=creerGraphe(fileName);
    }
}
void Widget::disableAllButtons(){
    d_djkstra->setEnabled(false);
    d_rang->setEnabled(false);
    d_prufer->setEnabled(false);
    d_kruskal->setEnabled(false);
    d_tarjan->setEnabled(false);
    d_addSommet->setEnabled(false);
    d_addConnection->setEnabled(false);
    d_removeConnection->setEnabled(false);
    d_removeSommet->setEnabled(false);


}
void Widget::MAJBoutons(){
    ifstream ist(d_fichier);
    string code;
    ist>>code;
    disableAllButtons();

    if(code=="CODE00"){
        d_debugger->append("     >>Le fichier contient un graphe non orienté et non valué");

        d_prufer->setEnabled(true);
        d_rang->setEnabled(true);
        d_addConnection->setEnabled(true);
        d_addSommet->setEnabled(true);
        d_removeConnection->setEnabled(true);
        d_removeSommet->setEnabled(true);
        return;

    }else if(code=="CODE01"){
        d_debugger->append("     >>Le fichier contient un graphe non orienté et valué");
        d_kruskal->setEnabled(true);
        d_rang->setEnabled(true);
        d_addConnection->setEnabled(true);
        d_addSommet->setEnabled(true);
        d_removeConnection->setEnabled(true);
        d_removeSommet->setEnabled(true);
        return;

    }else if(code=="CODE10"){
        d_debugger->append("     >>Le fichier contient un graphe orienté et non valué");
        d_addConnection->setEnabled(true);
        d_addSommet->setEnabled(true);
        d_removeConnection->setEnabled(true);
        d_removeSommet->setEnabled(true);
        d_tarjan->setEnabled(true);
        d_rang->setEnabled(true);
        //Matrice dadjencence
        //disatance
        return;

    }else if(code=="CODE11"){
        d_debugger->append("     >>Le fichier contient un graphe orienté et valué");
        d_djkstra->setEnabled(true);
        d_rang->setEnabled(true);
        d_addConnection->setEnabled(true);
        d_addSommet->setEnabled(true);
        d_removeConnection->setEnabled(true);
        d_removeSommet->setEnabled(true);
        //distance
        //matrice d'adjecence
        return;
    }
}

void Widget::MAJFichier( ){
    d_fichier=d_liste->currentText().toStdString();
}





















void Widget::onListe(){
    d_debugger->append("    >>Liste selected");
    onGO();

}

void Widget::onDjkstra(){
    d_debugger->append("    >>Djkstra clicked");
}
void Widget::onRang(){
    //Le rand is like the trees floors, when a tree form a cycle, the rang becomes infinity
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
    if(fichierValide(d_liste->currentText().toStdString())){
        MAJFichier();
        MAJBoutons();
    }else{
        d_debugger->append("fichier invalide");
    }

}
void Widget::onClear(){
    d_debugger->setText("");
}
void Widget::onDisplay(){
    //GrapheDisplay *graphe=new GrapheDisplay(this);
    //graphe->show();
}
vector<QString> Widget::generateRandomFiles(){
    ofstream f1("fichier1.txt"); f1<<"CODE00 "<<endl<<"8"<<endl<<"2 3 4 0 3 0 0 2"<<endl<<"4"<<endl<<"1 5 7 8";
    ofstream f2("fichier2.txt"); f2<<"CODE01 "<<endl<<"8"<<endl<<"2 3 4 0 3 0 0 2"<<endl<<"4"<<endl<<"1 5 7 8";
    ofstream f3("fichier3.txt"); f3<<"CODE10 "<<endl<<"8"<<endl<<"2 3 4 0 3 0 0 2"<<endl<<"4"<<endl<<"1 5 7 8";
    ofstream f4("fichier4.txt"); f4<<"CODE11 "<<endl<<"8"<<endl<<"2 3 4 0 3 0 0 2"<<endl<<"4"<<endl<<"1 5 7 8";
    ofstream f5("fichier5.txt"); f5<<"CODE00 "<<endl<<"8"<<endl<<"2 3 4 0 3 0 0 2"<<endl<<"4"<<endl<<"1 5 7 8";
    ofstream f6("fichier6.txt"); f6<<"CODE01 "<<endl<<"8"<<endl<<"2 3 4 0 3 0 0 2"<<endl<<"4"<<endl<<"1 5 7 8";
    ofstream f7("fichier7.txt"); f7<<"CODE10 "<<endl<<"8"<<endl<<"2 3 4 0 3 0 0 2"<<endl<<"4"<<endl<<"1 5 7 8";
    ofstream f8("fichier8.txt"); f8<<"CODE11 "<<endl<<"8"<<endl<<"2 3 4 0 3 0 0 2"<<endl<<"4"<<endl<<"1 5 7 8";
    ofstream f9("fichier9.txt"); f9<<"CODE00 "<<endl<<"8"<<endl<<"2 3 4 0 3 0 0 2"<<endl<<"4"<<endl<<"1 5 7 8";
    ofstream f10("fichier10.txt"); f10<<"CODE11 "<<endl<<"8"<<endl<<"2 3 4 0 3 0 0 2"<<endl<<"4"<<endl<<"1 5 7 8";

    vector<QString>strs;
    for(int x=1;x<=10;x++){
        QString str="fichier"+QString::number(x)+".txt";
        str.push_back(str);
        d_debugger->append(">>The file added is  at "+QString::number(x-1)+""+str);
    }

    return strs;
}

