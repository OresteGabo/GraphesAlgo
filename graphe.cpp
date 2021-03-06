#include "graphe.h"
Graphe::Graphe()
{
    creerUnFichierMatrice();
}
Graphe::~Graphe(){

}


void Graphe::ajoutSommet(){}

void Graphe::matriceFromFichier(const string &NomFichier)
{
    ifstream file;
    file.open(NomFichier);
    if(!file)
        cout<<"FILE_ERROR";
    int NombreSommet;
    int NombreArc;
    file>>NombreSommet;
    file>>NombreArc;
    d_matrice=new int*[NombreSommet+1];
    for(int i=0;i<=NombreSommet;i++)
    {
        d_matrice[i]=new int[NombreSommet+1];
    }
    d_matrice[0][0]=NombreSommet;
    d_matrice[0][1]=NombreArc;
    for(int i=2;i<=NombreSommet;i++)
    {
       file>>d_matrice[0][i];
    }
    for(int i=1;i<=NombreSommet;i++)
    {
        for(int j=0;j<=NombreSommet;j++)
        {
         file>>d_matrice[i][j];

        }
    }
}
void Graphe::fsApsFromFichier(const string &NomFichier)
{
    ifstream file;
    file.open(NomFichier);
    if(!file)
        cout<<"FILE_ERROR";
    int tailleFs;
    file>>tailleFs;
    d_fs=new int[tailleFs+1];
    d_fs[0]=tailleFs;
    for(int j=1;j<=tailleFs;j++){
         file>>d_fs[j];
    }
    int NombreSommet;
    file>>NombreSommet ;
    d_aps=new int [NombreSommet+1];
    d_aps[0]=NombreSommet;
    for(int j=1;j<=NombreSommet;j++){
         file>>d_aps[j];
    }
}
void Graphe::matriceToFsAps()
{
    int NombreSommet=d_matrice[0][0];
    int NombreArc=d_matrice[0][1];
    d_fs=new int [NombreSommet+NombreArc+1];
    d_aps=new int[NombreSommet+1];
    d_fs[0]=NombreSommet+NombreArc;
    d_aps=new int[NombreSommet+1];
    d_aps[0]=NombreSommet;
    int indexFs=1;
    int indexAps=indexFs;
    for(int i=1;i<=NombreSommet;i++)
    {
        d_aps[indexAps]=indexFs;
        for(int j=1;j<=NombreSommet;j++)
        {
            if(d_matrice[i][j]==1)
            {
                d_fs[indexFs]=j;
                indexFs++;
            }
        }
        d_fs[indexFs]=0;
        indexFs++;
        indexAps++;
    }
}
void Graphe::fsApsToMatrice(){

    int NombreSommet=d_aps[0];
    d_matrice=new int*[NombreSommet+1];
    for(int i=0;i<=NombreSommet;i++){
        d_matrice[i]=new int[NombreSommet+1];
    }
    for(int i=0;i<=NombreSommet;i++){
        for(int j=0;j<=NombreSommet;j++){
            d_matrice[i][j]=0;
        }
    }
    d_matrice[0][0]=NombreSommet;

    int NombreArc=d_fs[0]-NombreSommet;
    d_matrice[0][1]=NombreArc;

    int indexFs;
    for(int i=1;i<=d_aps[0];i++){
        indexFs=d_aps[i];
        while(d_fs[indexFs]!=0){
            d_matrice[i][d_fs[indexFs]]=1;
            indexFs++;
        }
    }


}
int* Graphe::nbSuccesseurs()const {
    int *dde;//nombre de successeurs
    int nSommet=d_aps[0];
    dde=new int[nSommet+1];
    dde[0]=nSommet;
    int indexFs;
    for(int i=1;i<=d_aps[0];i++){
        dde[i]=0;//initialiser le nombre de successeur ?? zero
        indexFs=d_aps[i];
        while(d_fs[indexFs]!=0){
            dde[i]+=1;//incrementer le nb de successeur
            indexFs++;
        }
    }
    return dde;
}
int* Graphe::nbPredecesseurs()const{
    int *nbp;//nombre de predecesseurs
    int nbSommet=d_aps[0];
    nbp=new int[nbSommet+1];
    nbp[0]=nbSommet;
    int indexFs;
    for(int i=1;i<=d_aps[0];i++)
    {nbp[i]=0;}
    for(int i=1;i<=d_aps[0];i++){
        indexFs=d_aps[i];
        while(d_fs[indexFs]!=0){
            nbp[d_fs[indexFs]]+=1;
            indexFs++;
        }
    }
    return nbp;
}
int* Graphe::getApp()const{
    int *App;
    int NombreSommet=d_aps[0];
    App=new int[NombreSommet+1];
    App[0]=NombreSommet;
    App[1]=1;
    for(int i=2;i<=NombreSommet;i++)
    {int j=i-1;
       App[i]=App[j]+nbPredecesseurs()[j]+1;
    }
    return App;
}
int* Graphe::getFp()const{
    int *fp;
    int taillFs=d_fs[0];
    fp=new int[taillFs+1];
    fp[0]=taillFs;
    int indexFp,indexFs;
    for(int i=1;i<=d_aps[0];i++){
        indexFs=d_aps[i];
        while(d_fs[indexFs]!=0){
            indexFp=getApp()[d_fs[indexFs]];
            fp[indexFp]=i;
            getApp()[d_fs[indexFs]]+=1;
            indexFs++;
        }
    }
    for(int i=1;i<=d_aps[0];i++){
        fp[getApp()[i]]=0;
    }
    return fp;
}
int* Graphe::distance(int sommet)const{
    int *tab;
    int NombreSommet=d_aps[0];
    tab=new int[NombreSommet+1];
    tab[0]=d_aps[0];
    for(int i=1;i<=d_aps[0];i++)
        tab[i]=-1;
    tab[sommet]=0;
    int file[NombreSommet];
    int distance=1;
    int indexFs;
    int debut=1,courant=0,fin=1;
    file[debut]=sommet;
    while(courant<fin){
        for(int i=courant+1;i<=debut;i++){
            indexFs=d_aps[file[i]];
            while(d_fs[indexFs]!=0){
                if(tab[d_fs[indexFs]]==-1){
                    tab[d_fs[indexFs]]=distance;
                    fin++;
                    file[fin]=d_fs[indexFs];
                }
                indexFs++;
            }
        }
        courant=debut;
        debut=fin;
        distance++;
    }
    return tab;
}

int** Graphe::distance()const{
    int nbSommet=d_aps[0];
    int **mat;
    mat=new int*[nbSommet+1];
    mat[0]=new int[nbSommet+1];
    mat[0][0]=nbSommet;
    mat[0][1]=d_fs[0]-nbSommet;
    for(int i=1;i<=nbSommet;i++){
        mat[i]=distance(i);
    }
    return mat;
}
// det la longuer du plus long chemin arrivant a un sommet
int* Graphe::rang(int *&num)const{
    int n = d_aps[0];
    num = new int[n+1];
    int *resultat = new int[n+1];
    num[0] = n;

    int *pile = new int[n+1]; // pour g??rer les sommets
    // indices dans la pile
    int t = 1;
    int r = 0;
    int pas = -1;
    int e = 0;
    int y,d;

    //init le rang
    for(int i = 1; i <= n; i++){
        resultat[i] = -1;
        num[i] = -1;
    }
    resultat[0] = n;
    num[0] = n;

    for(int i = 1; i <= n; i++){
        if(nbPredecesseurs()[i] == 0) //pas d'arc vers le sommet i
            pile[++e] = i; //empile le sommet i
    }
    d = n+1;
    while((e != 0) && (e != n+1)) //tant qu'il reste des arcs de ddi dans la pile
    {
        int x = e; // permutation des elements de la pile
        e = d;
        d = x;
        while((d != 0)&&(d != n+1)) // s'il reste des atcs de ddi dans la pile invers??e
        {
            int s = pile[d]; // sommet de la pile
            resultat[s] = r; // le rang du sommet courant
            num[s] = t;
            t++;
            for(int i = d_aps[s]; (y=d_fs[i]) > 0; i++) // parcours des successeurs du sommet
            {
                nbPredecesseurs()[y]--; // arc de moins
                if(nbPredecesseurs()[y] == 0){
                    e += pas;
                    pile[e] = y; // ajout du sommet qui n'a plus d'arcs
                }
            }
            d += pas; //
        }
        r++; // rang suivant
        pas = -pas; // parcours au sens inverse
    }
    return resultat;
}
int* Graphe::rangProfrondeur(QTextEdit* d)const{
    int nbSommet=d_aps[0];
    int *resultat=new int[nbSommet+1];
    int *file=new int[50];
    int *ddi=nbPredecesseurs();
    afficheDDI();
    resultat[0]=nbSommet;
    int tete=0,quefile=0;
    for(int s=1;s<=nbSommet;s++){
        if(ddi[s]==0){
           file[quefile]=s;
           quefile++;
           resultat[s]=0;
        }
    }
    int fin=quefile;
    int r=0;
    while(tete<quefile){
        for(int i=tete;i<fin;i++){
            int sommet=file[i];
            d->append("s="+QString::number(sommet)+"ddi="+QString::number(ddi[sommet]));
            if(ddi[sommet]==0){
                resultat[sommet]=r;
                int indexFs=d_aps[sommet];
                int s=d_fs[indexFs];
                while(s!=0){
                    if(ddi[s]!=0)ddi[s]--;
                    file[quefile]=s;
                    quefile++;
                    indexFs++;
                    s=d_fs[indexFs];
                }
            }else{
                int indexFs=d_aps[sommet];
                int s=d_fs[indexFs];
                while(s!=0){
                    file[quefile]=s;
                    quefile++;
                    indexFs++;
                    s=d_fs[indexFs];
                }
            }
        }
        tete=fin;
        fin=quefile;
        r++;
        d->append(QString::number(r)+"------------------");
    }
    return resultat;
}
int* Graphe::det_rang(int *&num){
    int *rrang;
    int n = d_aps[0];
    num = new int[n+1];
    rrang = new int[n+1];
    num[0] = n;

    int *pile = new int[n+1]; // pour g??rer les sommets
    // indices dans la pile
    int t = 1;
    int r = 0;
    int pas = -1;
    int e = 0;
    int y,d;

    //init le rang
    for(int i = 1; i <= n; i++)
    {
        rrang[i] = -1;
        num[i] = -1;
    }
    rrang[0] = n;
    num[0] = n;

    for(int i = 1; i <= n; i++)
    {
        if(nbSuccesseurs()[i] == 0) //pas d'arc vers le sommet i
            pile[++e] = i; //empile le sommet i
    }
    d = n+1;
    while((e != 0) && (e != n+1)) //tant qu'il reste des arcs de ddi dans la pile
    {
        int x = e; // permutation des elements de la pile
        e = d;
        d = x;
        while((d != 0)&&(d != n+1)) // s'il reste des atcs de ddi dans la pile invers??e
        {
            int s = pile[d]; // sommet de la pile
            rrang[s] = r; // le rang du sommet courant
            num[s] = t;
            t++;
            for(int l = d_aps[s]; (y=d_fs[l]) > 0; l++) // parcours des successeurs du sommet
            {
                nbSuccesseurs()[y]--; // arc de moins
                if(nbSuccesseurs()[y] == 0)
                {
                    e += pas;
                    pile[e] = y; // ajout du sommet qui n'a plus d'arcs
                }
            }
            d += pas; //
        }
        r++; // rang suivant
        pas = -pas; // parcours au sens inverse
    }
    return rrang;
}

void Graphe::afficheFsAps(QTextEdit* debugger)const{
    QString fs="",aps="";
    for(int i=0;i<=d_fs[0];i++){
        fs+=" ";
        fs+=QString::number(d_fs[i]);
    }
    for(int i=0;i<=d_aps[0];i++){
        aps+=" ";
        aps+=QString::number(d_aps[i]);
    }
    debugger->append("FS: "+fs);
    debugger->append("APS: "+aps);

}
void Graphe::afficheTab(int*tab)const{
    cout<<endl;
    for(int i=0;i<=tab[0];i++){
        cout << ' '<<tab[i];
    }cout<<endl;
}

void Graphe::afficheTab(int*tab,QTextEdit* d)const{
    cout<<endl;
    string str="";
    for(int i=0;i<=tab[0];i++){
        str=str+ " "+to_string (tab[i]);
    }cout<<endl;
    d->append(QString::fromStdString(str));
}

void Graphe::afficheMatrice(QTextEdit* debugger,int** m)const{
    debugger->append("\nMatrice ");
    for(int i=0;i<=m[0][0];i++){
        QString s="             ";
        for(int j=0;j<=m[0][0];j++){
            s+= QString::number(m[i][j]);
        }
        debugger->append(s);
     }
}
void Graphe::afficheMatrice(QTextEdit* debugger)const{
    afficheMatrice(debugger,d_matrice);
}
void Graphe::afficheDistance(QTextEdit* debugger)const{
    afficheMatrice(debugger,distance());
}
void Graphe::afficheFsAps()const{
    cout<<"FS: ";
    afficheTab(d_fs);
    cout<<"APS: ";
    afficheTab(d_aps);
}

void Graphe::afficheMatrice()const{
    afficheMatrice(d_matrice);
}
int *Graphe::getFs()const{return d_fs;}
int *Graphe::getAps()const{return d_aps;}
int **Graphe::getMatrice()const{return d_matrice;}
void Graphe::creerUnFichierMatrice()const{
    ofstream f("Matrice.txt");
    f<<" 7 9 0 0 0 0 0 0 "<<endl<<" 0 0 1 1 0 1 0 0 "<<endl<<" 0 0 0 1 0 0 0 0 "<<endl<<" 0 0 0 0 1 0 0 0 "<<endl;
    f<<" 0 0 0 0 0 0 1 0 "<<endl<<" 0 0 0 1 0 0 0 0 "<<endl<<" 0 0 0 0 0 0 0 0 "<<endl<<" 0 0 0 0 1 0 1 0 "<<endl;

    ofstream f2("MatriceD.txt");
    f2<<" 4 0 0 0 0 "<<endl<<" 0 0 -3 214748364 7 "<<endl<<" 0 -1 0 2 214748364 "<<endl<<" 0 5 214748364 0 1 "<<endl;
    f2<<" 0 2 214748364 214748364 0 ";

    ofstream f3("FsAps.txt");
    f3<<" 11 2 4 5 0 0 2 0 3 0 4 0 "<<endl<<" 5 1 5 6 8 10 "<<endl;

    ofstream f4("FpAppD.txt");
    f4<<" 29 0 1 0 1 0 2 3 0 3 0 4 5 0 4 6 0 4 6 0 6 8 0 2 7 8 9 0 10 0 "<<endl<<" 11 1 2 4 7 9 11 14 17 20 23 28 "<<endl;
    f4<<" 11 0 3 4 2 5 3 1 3 4 2 0 "<<endl;


    ofstream f5("ordonnancement.txt");
    f5<<" 31 2 3 0 4 5 0 5 7 0 6 0 7 8 9 0 7 8 9 0 10 0 11 0 11 0 12 0 13 0 11 0 "<<endl;
    f5<<" 13 1 4 7 10 12 16 20 22 24 26 28 30 31 ";

    ofstream f6("test.txt");
    f6<<" 4 1 0 1 0 "<<endl<<" 2 1 3";


 }


void Graphe::clearFs(){
    clearTable(d_fs,d_fs[0]+1);
}
void Graphe::clearAps(){
    clearTable(d_aps,d_aps[0]+1);
}
void Graphe::clearTable(int *&t,int taill){
    for(int i=taill-1;i>=0;i--){
        int *j=t+i;
        delete j;
     }
}
void Graphe::afficheDDE()const{
    int* dde=nbSuccesseurs();
    cout<<"DDE:";
    afficheTab(dde);

}
void Graphe::afficheDDE(QTextEdit*d)const{
    int *dde=nbSuccesseurs();
    d->append("DDE:");
    afficheTab(dde,d);
}
void Graphe::afficheDDI(QTextEdit*d)const{
    int *ddi=nbPredecesseurs();
    d->append("DDI:");
    afficheTab(ddi,d);
}
void Graphe::afficheDDI()const{
    int *ddi=nbPredecesseurs();
        cout<<"DDI:";
        afficheTab(ddi);
}

void Graphe::afficheFpApp()const{
    cout<<"FP:";
    afficheTab(getFp());
    cout<<"APP:";
    afficheTab(getApp());

}
void Graphe::afficheMatrice(int** m)const{
    for(int i=0;i<=m[0][0];i++){
        for(int j=0;j<=m[0][0];j++){
            cout<<' '<<m[i][j];
        }cout<<endl;
    }cout<<endl;
}
bool Graphe::djikstra (int s, int *&d, int *&pred)
{/*
    int n = d_aps[0];
    int j,l,x;
    d = new int[n+1];
    pred = new int[n+1];
    d[0] = n;
    pred[0] = n;
    bool *ins = new bool [n+1];
    for (int i = 1; i <= n; i++)
    {
        ins[i] = true;
        d[i] = c[s][i];
        pred[i] = s;
    }
    d[s]=INT_MAX;
    while (n--<0)
    {
        j = dmin(ins,d); // fct dmin ?? impl??menter
        if(d[j] == INT_MAX || j == -1 || j == s)
                return false;
        ins[j] = false;
        for(int k = d_aps[j]; (l=d_fs[k]) > 0; k++)
        {
            if(l != s && ins[l] == true && c[j][l] != INT_MAX)
            {
                x = d[j] + c[j][i];
                if(x < d[l])
                {
                    d[l] = x;
                    pred[l] = j;
                }
            }
        }
    }
    d[s] = 0;
    pred[s] = s;*/
    return true;
}
/*
void Graphe::createFile(const string& fileName)const{
    cout<<"\t\t>>createFile(const string& fileName)const function called"<<endl;
    ofstream file(fileName);
    int size=10;
    file<<size<<endl<<"   197 2 3 4 5 6 7 8 9 10 "<<endl;
    int size2=10;
    file<<size<<endl<<"   10 20 30 40 50 60 70 80 90 100 "<<endl;
    cout<<"\t\t>>createFile function called closed "<<endl;
}
*/
void Graphe::readFile(const string& fileName){
    cout<<"\t\t>>readFile(const string& fileName)const function called"<<endl;
    ifstream file(fileName);
    int size;
    file>>size;
    //d_fs.resize(size);
    cout<<endl<<"\t\t>>the size is fs "<<size<<" read successifully called"<<endl;
    for(int x=0;x<size;x++){
        int nb;
        file>>nb;
        if(nb!=0){
            //d_fs[x+1]=new Sommet(nb);
        }else{
            //d_fs[x+1]=nullptr;
        }
        cout<<x<<": "<<nb<<"   ";
    }
    int size2;
    file>>size2;
    cout<<endl<<"\t\t>>the size is aps"<<size<<" read successifully called"<<endl;

    for(int x=0;x<size2;x++){
        int nb;
        file>>nb;
        cout<<x<<": "<<nb<<"   ";
    }
    cout<<endl<<"end of loop aps, and end of function "<<endl;
}
