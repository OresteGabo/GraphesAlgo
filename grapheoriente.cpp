#include "grapheoriente.h"

#include <QDebug>

GrapheOriente::GrapheOriente()
{
    string fichier="oreste.txt";
    /*createFile(fichier);
    readFile(fichier);*/
}
GrapheOriente::~GrapheOriente(){

}
/*

void GrapheOriente::createFile(const string& fileName)const{
    cout<<"\t\t>>createFile(const string& fileName)const function called"<<endl;
    ofstream file(fileName);
    int size=10;
    file<<"CODE10   "; //1 er 1:oriente  2eme 0:non valué
    file<<size<<endl<<"   197 2 3 4 5 6 7 8 9 10 "<<endl;
    int size2=10;
    file<<size<<endl<<"   10 20 30 40 50 60 70 80 90 100 "<<endl;
    cout<<"\t\t>>createFile function called closed "<<endl;
}
*/
void GrapheOriente::readFile(const string&fileName) {
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
void GrapheOriente::affiche(QTextEdit* debugger)const {
    debugger->append("GrapheOriente affiche statrt");
}
void GrapheOriente::djkstra(QTextEdit* debugger){
    debugger->append("djkstra called in Graphe oriente");
}
void GrapheOriente::empiler(vector<int> pile,int valeur)
{
    pile[valeur]=pile[0];
    pile[0]=valeur;
}
int GrapheOriente::depiler(vector<int> pile)
{
    int sommet=pile[0];
    pile[0]=pile[sommet];
    return sommet;
}
void GrapheOriente::tarjan(int sommet){
    int p=0,k=0;
    p++;

        d_num[sommet]=p;
        d_ro[sommet]=p;
        empiler(d_pile,sommet);
        d_EstDansLaPile[sommet]=true;
        int i=d_aps[sommet];
        while(d_fs[i]!=0)
        {
            if(d_num[d_fs[i]]==0)
            {
                tarjan(d_fs[i]);
                if(d_ro[d_fs[i]]<d_ro[sommet])
                {
                    d_ro[sommet]=d_ro[d_fs[i]];
                }
            }
            else
            {
                if(d_num[d_fs[i]]<d_ro[sommet] && d_EstDansLaPile[d_fs[i]])
                {
                    d_ro[sommet]=d_num[d_fs[i]];
                }
            }
            i++;
        }
        if(d_ro[sommet]==d_num[sommet])
        {
            k++;
            int element=d_pile[0];
            //cout<<"le c"<<k<<"[";
            while(d_num[element]>=d_num[sommet])
            {
              // cout<<element<<",";
                element=depiler(d_pile);
                d_EstDansLaPile[element]=false;
                empiler(d_pilch,element);
                d_cfc[element]=k;
                element=d_pile[0];

            }
            //cout<<"]"<<endl;
            d_prem[k]=d_pilch[0];
            d_pilch[0]=0;
        }
}

void GrapheOriente::tarjan(QTextEdit* d){
    d->append(">>Trajan called from GrapheOriente");
    /*vector<bool>visited(d_apssize(),false);

    d->append(" Tarjan called ");
    for(unsigned long x=1;x<d_aps.size();x++){
        if(!visited[x]){
            tarjan(x);
            visited[x]=true;
            d->append(" Le sommet "+QString::number(x)+" dans "+QString::number(visited.size())+" est traité\n");
        }
    }*/
}
