#include "graphe.h"

Graphe::Graphe()
{

}
Graphe::~Graphe(){

}
void Graphe::loadData()const{}

void Graphe::ajoutSommet(){}

void Graphe::matriceFromFichier(const string &NomFichier)
{
    ifstream file;
    file.open(NomFichier);
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
int* Graphe::nbSuccesseurs()const
{
    int *nbs;//nombre de successeurs
    int nSommet=d_aps[0];
    nbs=new int[nSommet+1];
    nbs[0]=nSommet;
    int indexFs;
    for(int i=1;i<=d_aps[0];i++){
        nbs[i]=0;
        indexFs=d_aps[i];
        while(d_fs[indexFs]!=0){
            nbs[i]+=1;
            indexFs++;
        }
    }
    return nbs;
}
int* Graphe::nbPredecesseurs()const
{
    int *nbp;//nombre de predecesseurs
    int nbSommet=d_aps[0];
    nbp=new int[nbSommet+1];
    nbp[0]=nbSommet;
    int indexFs;
    for(int i=1;i<=d_aps[0];i++)
    {nbp[i]=0;}
    for(int i=1;i<=d_aps[0];i++)
    {
        indexFs=d_aps[i];
        while(d_fs[indexFs]!=0)
        {
            nbp[d_fs[indexFs]]+=1;
            indexFs++;
        }

    }
    return nbp;
}
int* Graphe::getApp()const
{
    int*app;
    int nbSommet=d_aps[0];
    app=new int[nbSommet+1];
    app[0]=nbSommet;
    app[1]=1;
    for(int i=2;i<=nbSommet;i++)
    {int j=i-1;
       app[i]=app[j]+ nbPredecesseurs()[j]+1;
    }
    return app;
}
int* Graphe::getFp()const
{
    int taillFs=d_fs[0];
    int* fp=new int[taillFs+1];
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
    {
        tab[i]=-1;

    }
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
                   //cout<<' '<<fin<<'='<<file[fin];
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

int** Graphe::distance()const
{
    int nbSommet=d_aps[0];
    int **mat;
    mat=new int*[nbSommet+1];
    mat[0]=new int[nbSommet+1];
    mat[0][0]=nbSommet;
    mat[0][1]=d_fs[0]-nbSommet;
    for(int i=1;i<=nbSommet;i++)
    {
        mat[i]=distance(i);
    }
    return mat;
}
int* Graphe::rangProfrondeur()const
{
    int nbSommet=d_aps[0];
    int *resultat=new int[nbSommet+1];
    int *file=new int[50];
    int *ddi;


    ddi=nbPredecesseurs();
    cout<<"ddi[";
    for(int i=1;i<=nbSommet;i++)
    {
        cout<<ddi[i]<<",";
    }
    cout<<endl;
    resultat[0]=nbSommet;
    int tete=0,quefile=0;
    for(int s=1;s<=nbSommet;s++)
    {
        if(ddi[s]==0)
        {
           file[quefile]=s;
           quefile++;
           resultat[s]=0;
        }
    }
    int fin=quefile;
    int r=0;
    while(tete<quefile)
    {//cout<<"t="<<tete<<"q="<<quefile<<endl;
        for(int i=tete;i<fin;i++)
        {//cout<<"s="<<file[i]<<"i="<<i<<endl;
            int sommet=file[i];
             cout<<"s="<<sommet<<"ddi="<<ddi[sommet]<<endl;
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
        cout<<r<<"------------------"<<endl;
    }
    return resultat;
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

