#include "grapheorientevalue.h"

GrapheOrienteValue::GrapheOrienteValue()
{

}
GrapheOrienteValue::~GrapheOrienteValue()
{

}


/*

void GrapheOrienteValue::createFile(const string& fileName)const{
    cout<<"\t\t>>createFile(const string& fileName)const function called"<<endl;
    ofstream file(fileName);
    int size=10;
    file<<size<<endl<<"   197 2 3 4 5 6 7 8 9 10 "<<endl;
    int size2=10;
    file<<size2<<endl<<"   10 20 30 40 50 60 70 80 90 100 "<<endl;
    cout<<"\t\t>>createFile function called closed "<<endl;
}
*/
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
