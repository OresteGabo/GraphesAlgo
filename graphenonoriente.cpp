#include "graphenonoriente.h"

GrapheNonOriente::GrapheNonOriente()
{
    string fichier="oreste.txt";
    createFile(fichier);
    readFile(fichier);
}
GrapheNonOriente::~GrapheNonOriente(){

}
void GrapheNonOriente::ajouterConnection(){
    //ici on ajoute uniquement les connections non value!!
}
bool GrapheNonOriente::connectionExiste(Sommet* src,Sommet*dest)const{
    /*int n=d_aps[0];
    for(int i=1;i<=n;i++){
        int k=d_aps[i];
        while(d_fs[k]!=nullptr){
            if(
                    (dest->getValeur()==d_fs[k]->getValeur() && src->getValeur()==d_fs[i]->getValeur())||
                    (src->getValeur()==d_fs[k]->getValeur() && dest->getValeur()==d_fs[i]->getValeur())
             ){
                return true;
            }
            k++;
        }
    }*/
    return false;
}
/*bool GrapheNonOriente::ajoutSommetPossible(int)const{
    return true;
}*/

void GrapheNonOriente::displayData()const {

}
void GrapheNonOriente::createFile(const string& fileName)const{
    cout<<"\t\t>>createFile(const string& fileName)const function called"<<endl;
    ofstream file(fileName);
    int size=10;
    file<<"CODE00   "; //1 er 0:non oriente  2eme 0:non valué
    file<<size<<endl<<"   197 2 3 4 5 6 7 8 9 10 "<<endl;
    int size2=10;
    file<<size<<endl<<"   10 20 30 40 50 60 70 80 90 100 "<<endl;
    cout<<"\t\t>>createFile function called closed "<<endl;
}
/*Sommet* Graphe::getSommetByID(int)const{
    return nullptr;
}*/
void GrapheNonOriente::readFile(const string& fileName){
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
void GrapheNonOriente::affiche(QTextEdit*debugger)const {
    debugger->append("GrapheNonOriente affiche statrt");
}
