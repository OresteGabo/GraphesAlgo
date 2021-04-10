#include "widget.h"
#include<iostream>
#include <QApplication>
#include"grapheorientevalue.h"
#include"graphenonorientevalue.h"
#include"grapheoriente.h"
#include"graphenonoriente.h"
#include<fstream>
#include<istream>
using namespace std;
/*
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();

}
*/
int main(int argc, char *argv[])
{
    auto g=GrapheOriente();

        int *fpc,*appc,*lc,*d,*lt;

        g.fsApsFromFichier("test.txt");

        g.afficheFsAps();
        g.afficheFpApp();
        d=new int[g.getApp()[0]+1];
        d[0]=13;
        d[1]=0;
        d[2]=7;
        d[3]=2;
        d[4]=4;
        d[5]=6;
        d[6]=2;
        d[7]=1;
        d[8]=4;
        d[9]=1;
        d[10]=1;
        d[11]=2;
        d[12]=1;
        d[13]=0;

        //g.ordonnancement(d,fpc,appc,lc);

        //AfficherFs(fp);
        //AfficherAps(app);
        //datePlusTard(fs,aps,lc,lt,d);

        /*MatriceFromFichier(mata,"MatriceD.txt");
        AfficherMatrice(mata);
        bool k=true;
        Dantzig(mata,k);
        if(k)AfficherMatrice(mata);
        else*/
        /*int **a,  *prf;
        saisie_fich("arbre.txt", a);
        AfficherMatrice(a);
        prufer(a,prf);
        AfficherAps(prf);
        cout << "Hello world!"<<INT_MAX<<endl;
        int **b;
        decdPrufer(b,prf);
        AfficherMatrice(b);*/
        /*if(0>=-1)if(-1>-1)
        {
            cout<<"je suis la"<<endl;
        }
        else
        {
            cout<<"je suis o"<<endl;
        }*/
        return 0;



}
