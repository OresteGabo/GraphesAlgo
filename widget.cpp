#include "widget.h"

Widget::Widget(Graphe*g,QWidget *parent)
    : QWidget(parent),d_graphe{g}
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

    d_fsAps=new QPushButton("Afficher FSAPS");

    d_matrice=new QPushButton("MATRICE");
    d_nbSuccesseur=new QPushButton("NB SUCCESSEURS");
    d_nbPredecesseur=new QPushButton("PREDECESSEURS");
    d_distance=new QPushButton("DISTANCE");
    d_ddi=new QPushButton("DDI");
    d_dde=new QPushButton("DDE");
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
    /*buttons->addWidget(d_addSommet);
    buttons->addWidget(d_addConnection);
    buttons->addWidget(d_removeConnection);
    buttons->addWidget(d_removeSommet);
    buttons->addWidget(d_display);*/

    buttons->addWidget(d_fsAps);
    buttons->addWidget(d_matrice);
    buttons->addWidget(d_distance);
    buttons->addWidget(d_ddi);
    buttons->addWidget(d_dde);

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
    connect(d_fsAps,&QPushButton::clicked,this,&Widget::onFsAps);
    connect(d_matrice,&QPushButton::clicked,this,&Widget::onMatrice);
    connect(d_distance,&QPushButton::clicked,this,&Widget::onDistance);
    connect(d_ddi,&QPushButton::clicked,this,&Widget::onDdi);
    connect(d_dde,&QPushButton::clicked,this,&Widget::onDde);


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
    //disableAllButtons();

    if(code=="CODE00"){
        d_debugger->append("     >>Le fichier contient un graphe non orienté et non valué");

        d_prufer->setEnabled(true);
        d_rang->setEnabled(true);
        d_addConnection->setEnabled(true);
        d_addSommet->setEnabled(true);
        d_removeConnection->setEnabled(true);
        d_removeSommet->setEnabled(true);
        //matrice d'adjecence
        return;

    }else if(code=="CODE01"){
        d_debugger->append("     >>Le fichier contient un graphe non orienté et valué");
        d_kruskal->setEnabled(true);
        d_rang->setEnabled(true);
        d_addConnection->setEnabled(true);
        d_addSommet->setEnabled(true);
        d_removeConnection->setEnabled(true);
        d_removeSommet->setEnabled(true);
        //matrice d'adjecence
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
        d_tarjan->setEnabled(true);
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
    //d_graphe->djkstra(d_debugger);
}
void Widget::onRang(){
    //Le rand is like the trees floors, when a tree form a cycle, the rang becomes infinity
    d_debugger->append("    >>Rang clicked");
    QString s="";
    //int* rg=d_graphe->det_rang()
    d_graphe->rangProfrondeur(d_debugger);
}
void Widget::onPrufer(){
    d_debugger->append("    >>prufer clicked");
}

void Widget::onTarjan(){
    d_debugger->append("    >>Trajan clicked");
    ((GrapheOriente*)d_graphe)->tarjan(d_debugger);
    std::vector<int> prem;
        std::vector<int> pilch;
        std::vector<int> cfc;
        ((GrapheOriente*)d_graphe)->calculerCFC(prem,pilch,cfc);
        d_debugger->append("le tableau prem : ");
        QString premStr="",pilchStr,cfcStr;
        for(unsigned int i =0 ;i<prem.size();i++){
             premStr+=(QString::number(prem[i])+"    ");
        }
        d_debugger->append(premStr);

         d_debugger->append("le tableau pilch : ");
         for(unsigned int i =1 ;i<pilch.size();i++){
             //cout<<"sommet "<<i<<":"<<pilch[i]<< " ";
             d_debugger->append("Sommet "+QString::number(pilch[i])+" : "+QString::number(pilch[i])+"    ");
         }
         d_debugger->append("le tableau cfc : ");
         for(unsigned int i =0 ;i<cfc.size();i++)
         {
             cfcStr+=(QString::number(cfc[i])+"    ");

         }
         d_debugger->append(cfcStr);

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

void Widget::onFsAps(){
    d_debugger->append("");
    d_graphe->afficheFsAps(d_debugger);
}
void Widget::onMatrice(){
    d_graphe->afficheMatrice(d_debugger);
}
void Widget::onDdi(){
    d_debugger->append("");
    d_graphe->afficheDDI(d_debugger);
}
void Widget::onDde(){
    d_debugger->append("");
    d_graphe->afficheDDE(d_debugger);
}
void Widget::onNbPredecesseur(){}
void Widget::onNbSuccesseur(){}
void Widget::onDistance(){
    d_debugger->append("");
    d_graphe->afficheDistance(d_debugger);
}
void Widget::onKruskal(){
    Mass m;
    d_debugger->append("");
    d_debugger->append("    >>kruskal clicked");
    graphe g, t;
    m.saisie(g,d_debugger);
    int n = g.n;
    int *prem = new int[n + 1];
    int *pilch = new int[n + 1];
    int *cfc = new int[n + 1];
    int *NbElem = new int[n + 1];
    for(int i=1; i<=n;i++)
    {					// prem ,pilch, cfc sont initialisé avant le début du programme
        prem[i] = i;
        pilch[i] = 0;
        cfc[i] = i;
        NbElem[i] = 1;
    }
    m.trier(g);
    m.kruskal(g, t, prem, pilch, cfc,NbElem);
    m.affichage(t,d_debugger);
}
void Widget::onOrdonnancement(){

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

