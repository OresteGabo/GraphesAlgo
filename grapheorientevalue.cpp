#include "grapheorientevalue.h"

GrapheOrienteValue::GrapheOrienteValue()
{

}
GrapheOrienteValue::~GrapheOrienteValue()
{

}



void GrapheOrienteValue::readFile(const string& fileName){
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
void GrapheOrienteValue::affiche(QTextEdit* debugger)const {
    debugger->append("GrapheOrienteValue affiche statrt");
}
void GrapheOrienteValue::djkstra(QTextEdit*){

}
void GrapheOrienteValue::ordonnancement(int *d, int *&fpc, int *&appc, int *&lc)
{
    //appc premier predecesseur des chemins critique
    //fpc file predeceseur chemin critique
    int *app=getApp();
    int *fp=getFp();
    int NombreSommet= app[0], taillFs= fp[0];
    fpc = new int[taillFs+1];
    appc = new int[NombreSommet+1];
    appc[0] = NombreSommet;
    lc = new int[NombreSommet+1];
    lc[0] = NombreSommet;

    for(int i=1;i<=NombreSommet;i++){
        lc[i]=0;
    }
    int kc, t, lg;
    lc[1] = 0;
    fpc[1] = 0;
    appc[1] = 1;
    kc = 1;
    //afficheFpApp();
    for(int s = 2;s <= NombreSommet;s++){
        //lc[s] = 0;
        appc[s] = kc+1;
        int k;
        for (k = app[s];(t = fp[k]) != 0;k++){
            lg = lc[t] + d[t];

            if (lg >= lc[s]){
                if (lg > lc[s]){
                    lc[s] = lg;
                    kc = appc[s];
                    fpc[kc] = t;
                }else{
                    kc++;
                    fpc[kc] = t;
                }
             }
        }

        kc++ ;
        fpc[kc] = 0;
    }
    fpc[0] = kc;
    afficheFsAps();
    afficheFpApp();
    afficheTab(fpc);
    afficheTab(appc);
}


