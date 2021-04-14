#include "grapheoriente.h"

#include <QDebug>

GrapheOriente::GrapheOriente(){
    string fichier="oreste.txt";
}
GrapheOriente::~GrapheOriente(){
}

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
/*void GrapheOriente::tarjan(int sommet){
    int p=0,k=0;
    p++;

        d_num[sommet]=p;
        d_ro[sommet]=p;
        empiler(d_pile,sommet);
        d_EstDansLaPile[sommet]=true;
        int i=d_aps[sommet];
        while(d_fs[i]!=0){
            if(d_num[d_fs[i]]==0){
                tarjan(d_fs[i]);
                if(d_ro[d_fs[i]]<d_ro[sommet]){
                    d_ro[sommet]=d_ro[d_fs[i]];
                }
            }else{
                if(d_num[d_fs[i]]<d_ro[sommet] && d_EstDansLaPile[d_fs[i]]){
                    d_ro[sommet]=d_num[d_fs[i]];
                }
            }
            i++;
        }
        if(d_ro[sommet]==d_num[sommet]){
            k++;
            int element=d_pile[0];
            //cout<<"le c"<<k<<"[";
            while(d_num[element]>=d_num[sommet]){
                cout<<element<<",";
                element=depiler(d_pile);
                d_EstDansLaPile[element]=false;
                empiler(d_pilch,element);
                d_cfc[element]=k;
                element=d_pile[0];
            }
            cout<<"]"<<endl;
            d_prem[k]=d_pilch[0];
            d_pilch[0]=0;
        }
}*/
void GrapheOriente::composantC(){
    int noSommet=d_aps[0];
        d_visite=new bool[noSommet];
        stack<int> stack;
        d_dfsnum = new int[noSommet];
        d_low = new int[noSommet];

        for(int i = 0;i < noSommet; i++) {
            d_dfsnum[i] = -1;
            d_low[i] = -1;
        }

        for(int sommet = 1;sommet < noSommet; sommet++) {
            if(d_dfsnum[sommet] == -1){
                tarjan(sommet,stack);
            }
        }
}
void GrapheOriente::tarjan(int sommet, stack<int> st){
    int noSommet=d_aps[0];
    int** adj;
        d_dfsnum[sommet] = d_low[sommet] = (d_num++);
        st.push(sommet);
        d_visite[sommet] = true;

        for(int v = 0; v < noSommet; v++) {
            if(adj[sommet][v]==1){
                if(d_dfsnum[v] == -1){
                    tarjan(v,st);
                    d_low[sommet]=min(d_low[v],d_low[sommet]);
                }
                else if(d_visite[v]){
                    d_low[sommet]=min(d_dfsnum[v],d_low[sommet]);
                }
            }
        }

        int w = -1;
        if (d_low[sommet] == d_dfsnum[sommet])
        {
            while (w != sommet)
            {
                w =st.top(); st.pop();
                cout<<w + " ";
                d_visite[w] = false;
            }
            cout<<endl;
        }
    }
void GrapheOriente::tarjan(QTextEdit* d){
    d->append(">>Trajan called from GrapheOriente");

            /*bool*visited=new bool[noOfVertices];
            stack<int> stack;
            dfsnum = new int[noOfVertices];
            low = new int[noOfVertices];

            for(int i = 0;i < noOfVertices; i++) {
                dfsnum[i] = -1;
                low[i] = -1;
            }

            for(int vertex = 0;vertex < noOfVertices; vertex++) {
                if(dfsnum[vertex] == -1){
                    findSC(vertex,stack);
                }
            }*/


}

void GrapheOriente::calculerCFC(vector<int>& prem,vector<int>& pilch,vector<int>& cfc) const
{
  int n = d_aps[0];
  prem.clear();
  prem.reserve(n+1);
  prem.resize(1);
  pilch.resize(n+1);
  cfc.resize(n+1);

  std::stack<int> tarj{};
  std::vector<bool> enTarj(n+1, false);

  int ns = 0;
  int nc = 0;
  std::vector<int> num(n+1, 0);
  std::vector<int> ro(n+1);

  for (int s = 1; s <= n; ++s)
  {
    if (num[s] == 0)
    {
      traverse(s, prem, pilch, cfc, tarj, enTarj, ns, nc, num, ro);
    }
  }
}

void GrapheOriente::traverse(int s,vector<int>& prem,vector<int>& pilch,vector<int>& cfc,stack<int>& tarj,vector<bool>& enTarj,int& ns,int& nc,vector<int>& num,vector<int>& ro) const
{
    ro[s] = num[s] = ++ns;
    tarj.push(s);
    enTarj[s] = true;
    int t;
    for (int k = d_aps[s] ; (t = d_fs[k]) != 0 ; ++k){
        if (num[t] == 0){
            traverse(t, prem, pilch, cfc, tarj, enTarj, ns, nc, num, ro);
            if (ro[t] < ro[s])
            ro[s] = ro[t];
        }
        else if (enTarj[t] == true && num[t] < ro[s])
            ro[s] = num[t];
    }
    if (ro[s] == num[s]){
        int u = tarj.top();
        tarj.pop();
        enTarj[u] = false;
        prem.push_back(u);
        cfc[u] = ++nc;
        int ind = u;
        while (u != s){
            u = tarj.top();
            tarj.pop();
            enTarj[u] = false;
            pilch[ind] = u;
            ind = u;
            cfc[u] = nc;
        }
        pilch[u] = 0;
    }
}
/*
GrapheOriente GrapheOriente::calculerGrapheReduit(const std::vector<int>& prem,
                                        const vector<int>& pilch,
                                        const vector<int>& cfc) const
{
  GrapheOriente grapheReduit;
  std::vector<bool> marque(prem.size());
  int kr = 1;
  int s;
  int t;
  for (int c = 1; c < prem.size(); ++c)
  {
    for (int j = 1; j < marque.size(); ++j)
      marque[j] = false;
    marque[c] = true;
    s = prem[c];
    grapheReduit.d_aps.push_back(kr);
    while (s != 0)
    {
      for (int k = d_aps[s]; (t = d_fs[k]) != 0; ++k)
      {
        if (marque[cfc[t]] == false)
        {
          ++kr;
          grapheReduit.d_fs.push_back(cfc[t]);
          marque[cfc[t]] = true;
        }
      }
      s = pilch[s];
    }
    ++kr;
    grapheReduit.d_fs.push_back(0);
  }
  grapheReduit.d_aps[0] = prem.size();
  grapheReduit.d_fs[0] = kr;
  return grapheReduit;
}
*/


































