#ifndef MASS_H
#define MASS_H
#include<iostream>
#include<QTextEdit>
using namespace std;

typedef struct {
    int s; // première extrmité de l'arète ( 1er sommet de l'arète )
    int t; // deuxième extrmité de l'arète ( 2éme sommet de l'arète )
    double p; // poids de l'arète
} arete;
typedef struct {
    int n; // nombre de sommets du graphe
    int m; //nombre d'arètes du graphe ;
    arete *a; // tableau des aretes du graphe
} graphe;




class Mass{
public:
    Mass();
    void saisie(graphe &g,QTextEdit*d)
    {
        int s, t;
        arete ar;
        cout << "Saisie d'un graphe non oriente value arete par arete " << endl << endl;
         d->append ("Saisie d'un graphe non oriente value arete par arete (!DANS LE CONSOLE)");

        cout << "Donnez le nombre de sommets : ";
         d->append ("Donnez le nombre de sommets : (!DANS LE CONSOLE)");
        cin >> g.n;

        do{
            cout << "Donnez le nombre d'aretes : ";
            d->append ("Donnez le nombre d'aretes : (!DANS LE CONSOLE)");
            cin >> g.m;
        } while (g.m < g.n);

        g.a = new arete[g.m];
        string ss="Saisissez les "+to_string(g.m)+ " aretes" ;
        cout << ss<< endl;

        d->append(QString::fromStdString(ss)+" !DANS LE CONSOLE");

        for (int i = 0; i < g.m; i++)
        {
            cout << "arete n " << i + 1 << " :" << endl;
            do
            {
                cout << "extremite 1 (entre 1 et " << g.n << " ) : ";
                cin >> s;
                ar.s = s;
            } while ((s < 1) && (s > g.n));
            do
            {
                cout << "extremite 2 (entre 1 et " << g.n << " ) : ";
                cin >> t;
                ar.t = t;
            }while ((t < 1) && (t > g.n));
            g.a[i] = ar;
            cout << "Poids de l'arete : ";
            cin >> g.a[i].p;
        }
    }
    void affichage(graphe g,QTextEdit*d)
    {
        QString s="";
        for (int i = 0; i < g.m; i++){
            s+= "Arete No " +QString::number(i + 1 )+ " : (" + QString::number(g.a[i].s )+ " , " + QString::number( g.a[i].t)+ ")  ---  "+ QString::number(g.a[i].p);
            d->append(s);
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
    void lancer();
};
#endif // MASS_H
