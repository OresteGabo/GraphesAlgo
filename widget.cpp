#include "widget.h"

Widget::Widget(Graphe*g,QWidget *parent)
    : QWidget(parent),d_graphe{g}
{

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
    d_debugger->setStyleSheet("background-color: rgb(180,180,180);");

    d_fsAps=new QPushButton("Afficher FSAPS");

    d_matrice=new QPushButton("MATRICE");
    d_nbSuccesseur=new QPushButton("NB SUCCESSEURS");
    d_nbPredecesseur=new QPushButton("PREDECESSEURS");
    d_distance=new QPushButton("DISTANCE");
    d_ddi=new QPushButton("DDI");
    d_dde=new QPushButton("DDE");
    generateRandomFiles();
    MAJFichier();
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

Widget::~Widget()
{
}

Graphe* Widget::creerGraphe(const string& fileName){
    /*string code;
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
    */return nullptr;
}
bool Widget::fichierValide(const string&fileName)const{
    ifstream ist(fileName);
    if(!ist){
        return false;
    }
    return true;
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
    /*
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
    */
}

void Widget::MAJFichier( ){
    d_fichier=d_liste->currentText().toStdString();
    //d_debugger->append("Mifstarted##");
    if(d_liste->currentText()=="Matrice.txt" || d_liste->currentText()=="MatriceD.txt"){
        d_graphe->matriceFromFichier("Matrice.txt");
        d_graphe->matriceToFsAps();
    }else if(d_liste->currentText()=="FsAps.txt"){
        d_graphe->fsApsToMatrice();
        d_debugger->append("FsAps.txt##");

    }else if(d_liste->currentText()=="FpAppD.txt"){
        d_debugger->append("FpAppDD.txt##");
    }
    /*else if(d_liste->currentText()==".txt"){

    }else if(d_liste->currentText()==".txt"){

    }else if(d_liste->currentText()==".txt"){

    }*/

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
    MAJFichier();
    if(fichierValide(d_liste->currentText().toStdString())){
        d_debugger->append("fichier valide");
        MAJFichier();
        MAJBoutons();
    }else{
        d_debugger->append("FILE_NOT_FOUND");
        disableAllButtons();
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



void Widget::saisie(graphe &g){
    int s, t;
    arete ar;
    d_debugger->append( "Saisie d'un graphe non oriente value arete par arete ");
    g.n=QInputDialog::getInt(this,"sommets","Donnez le nombre de sommets",QLineEdit::Normal,3);

    do{
        g.m=QInputDialog::getInt(this,"aretes","Donnez le nombre d'aretes :",QLineEdit::Normal,3);
    } while (g.m < g.n);

    g.a = new arete[g.m];

    d_debugger->append(  "Saisissez les " +QString::number( g.m )+ " aretes" );
    for (int i = 0; i < g.m; i++){
        cout << "arete n " << i + 1 << " :" << endl;
        d_debugger->append( "arete n " +QString::number( i + 1)+" :");
        do{
            s=QInputDialog::getInt(this,"extremite","extremite 1 (entre 1 et " +QString::number(g.n)+ " ) ",QLineEdit::Normal,1);
            ar.s = s;
        } while ((s < 1) && (s > g.n));
        do{
            t=QInputDialog::getInt(this,"aretes","extremite 2 (entre 1 et " +QString::number(g.n)+ " ) : ",QLineEdit::Normal);
            ar.t = t;
        }while ((t < 1) && (t > g.n));
        g.a[i] = ar;
        g.a[i].p=QInputDialog::getInt(this,"aretes","Poids de l'arete : ",QLineEdit::Normal);
    }
}
void affichage(graphe g,QTextEdit * d){
    for (int i = 0; i < g.m; i++){
        d->append( "Arete No "+ QString::number( i + 1) + " : (" +QString::number( g.a[i].s )+ " , " +QString::number( g.a[i].t) + ")  ---  " + QString::number(g.a[i].p) );
        cout << "Arete No " << i + 1 << " : (" << g.a[i].s << " , " << g.a[i].t << ")  ---  " << g.a[i].p << endl;

    }
}
void trier(graphe &g)
{
    double p;

    for (int i = 0; i < g.m - 1; i++)
        for (int j = i + 1; j < g.m; j++)
            if ((g.a[j].p < g.a[i].p) || (g.a[j].p == g.a[i].p && g.a[j].s < g.a[i].t) || (g.a[j].p == g.a[i].p && g.a[j].t < g.a[i].t))
            {
                p = g.a[j].p;
                g.a[j].p = g.a[i].p;
                g.a[i].p = p;
            }
}

void fusionner(int i, int j, int *prem, int *pilch, int *cfc, int *NbElem)
// i et j sont les numéros des composantes à fusionner
// en une seule composante qui portera le numéro le plus
// petit des deux
{
    if (NbElem[i] < NbElem[j])
    {
        int aux = i;
        i = j;
        j = aux;
    }
    int s = prem[j];
    cfc[s] = i;
    while (pilch[s] != 0)
    {
        s = pilch[s];
        cfc[s] = i;
    }
    pilch[s] = prem[i];
    prem[i] = prem[j];
    NbElem[i] += NbElem[j];
}

void kruskal(graphe g, graphe &t, int *prem, int *pilch, int *cfc, int *NbElem)
//Les tableaux prem, pilch et cfc sont des variables globales initialis�es dans le main
//Le tableau des ar�tes de g est d�j� tri�
{
    t.a = new arete[g.n-1];
    int x; // respectivement le num�ro de composante de la 1�re  extr�mit� de l�ar�te courante
    int y; // respectivement le num�ro de composante de la 2�me  extr�mit� de l�ar�te courante
    int i = 0, j = 0;//respectivement indice dans g et t
    while (j < g.n-1)
    {
        arete ar = g.a[i];
        x = cfc[ar.s];
        y = cfc[ar.t];
        if (x != y)
        {
            t.a[j++] = g.a[i];
            fusionner(x, y, prem, pilch, cfc, NbElem);
        }
        i++;
    }
    t.n = g.n;
    t.m = g.n - 1;
}
void Widget::onKruskal(){
    d_debugger->setText("");
    d_debugger->setText("Les données de cet algorithmes doivent etre saisi a la main!");
    graphe g, t;
    saisie(g);
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
    //d_debugger->append("TRI DU GRAPHE EN COURS");
    trier(g);
    //d_debugger->append("KRUSKAL");
    kruskal(g, t, prem, pilch, cfc,NbElem);
    //d_debugger->append("RESULTAT (AFFICHAGE)");
    affichage(t,d_debugger);
}

//pour prufer
void Widget::saisie_fich(const string& nom, int** &a){
    int nb_som, som;
    ifstream fichier(nom);
    if (!fichier){
        d_debugger->append( "Probleme d'ouverture du fichier ");// << nom << endl;
        return;
    }
    fichier >> nb_som;

    a = new int*[nb_som+1];
    a[0] = new int;
    a[0][0] = nb_som;
    for(int i=1; i<=nb_som; i++)
    {
        a[i] = new int[nb_som+1];
        for(int j=0; j <=nb_som; j++)
            a[i][j] = 0;
    }


    for (int i = 1; i <= nb_som; i++)
    for (int j = 1; j <= nb_som; j++)
    {
        fichier >> som;
        a[i][j] = som;     // parcours le fichier pour lire les diffÃ©rents sommets
        a[i][0] += som;
    }
}

int* prufer(int **a)
{
    int *prf;
    int nb_som = a[0][0];
    prf = new int[nb_som-1];
    prf[0] = nb_som-2;
    int k = 1;
    while (k <= nb_som-2)
    {	int i = 1;
        for (; a[i][0] != 1; i++);
        int j=1;
        for (; a[i][j] != 1; j++);
        prf[k++]=j;
        a[i][j]=0;
        a[j][i]=0;
        a[i][0]=0;
        a[j][0]--;
    }
    return prf;
}
void Widget::onPrufer(){

    d_debugger->append("    >>prufer clicked");
    int **a,  *prf;
    saisie_fich("arbre.txt", a);
    prf=prufer(a);
    d_graphe->afficheTab(prf);

}

void Widget::onOrdonnancement(){

}




void Widget::generateRandomFiles(){

    ofstream f1("Matrice.txt");
    f1<<"7 9 0 0 0 0 0 0 "<<endl;
    f1<<"0 0 1 1 0 1 0 0 "<<endl;
    f1<<"0 0 0 1 0 0 0 0 "<<endl;
    f1<<"0 0 0 0 1 0 0 0 "<<endl;
    f1<<"0 0 1 0 0 0 0 0 "<<endl;
    f1<<"0 0 0 0 0 0 0 0 "<<endl;
    f1<<"0 0 0 0 1 0 1 0 "<<endl;

    vector<string>strs;
    d_fichiers.push_back("Matrice.txt");
    d_fichiers.push_back("MatriceD.txt");
    d_fichiers.push_back("FsAps.txt");
    d_fichiers.push_back("FpAppD.txt");//pour ordonnancement



    //return strs;
}

