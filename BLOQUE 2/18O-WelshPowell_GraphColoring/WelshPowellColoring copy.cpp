//DESCARTADOS

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>

#include <numeric> 
#include <utility>

using namespace std;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
{
    return (a.second > b.second); //compara los grados
}

//vector< pair<int, int> >
vector<int>
WelshPowell(vector< pair<int, int> > &grados, int** graph){
  int n=grados.size();

  //CREA EL VECTOR
  vector<int> coloreado (n,-1);
  coloreado[0]=0; //El primer elemento en el grafo tendra color 0
  
  int color=0;
  for (int repet = 1; repet < n; repet++)
  {//repetir las filas del grafo
    vector< pair<int, int> > grados2;
    //vector<int> adyacentesGuardados (n,-1);
    for (int ii = 0; ii < grados.size(); ii++)
    {
      int i = grados[ii].first;//indice
      //cout<<i<<" | "<<repet<<" "<<i<<" : "<<graph[repet][i]<<endl;

      if(graph[repet][i]==1 && repet==i){
        cout<<"No es posible asignar colores a los nodos"<<endl;//Un nodo que se conecta si mismo, genera error al colorear
        return coloreado;
      }
      bool validado=true;
      for (int j = 0; j < count; j++)
      {
        if(graph[repet][i]==0 && coloreado[i]==-1){ 
        coloreado[i]=color; //al encontrar elementos no adyacente y aun si colorear, lo colorea
        validado=true;
        //adyacentesGuardados[i]=j;  && adyacentesGuardados[i]==-1)
        //graph[i][i]=1; //imposibilita colindarle
        }
      }
      
      if(valdiado==true){
        grados2.push_back(grados[ii]);
      } 
    }
    grados = grados2;
    color++;
  }

 
 
  return coloreado;
  
}

int main(int argc, char *argv[]) { //COMPLEJIDAD GENERAL O(n^2)

  // LECTOR DE TXT
  string file = argv[1];
  ifstream input(file);
  string line = "";

  getline(input, line); //N es el tamano del lado de la matriz grafa
  const int n = stoi(line);

  int idxM = 0;
  int idxN = 0;
  const char delim = ' ';

  int **arr = new int*[n]; //crear matriz
  for (int i = 0; i < n; i++) {
    arr[i] = new int[n];
  }
  //int[n][n] arr;

  for (std::string line; getline(input, line);) {

    stringstream ss(line);
    string s;
    while (std::getline(ss, s, delim)) {
      arr[idxM][idxN] = stoi(s);
      idxN++;
    }

    idxM++;
    idxN = 0;
  }
  
  vector< pair<int, int> > grados;
  //IMPRIMIMOS GRAFO RECIBIDO, consegui
  for (int j = 0; j < n; j++) {
      //grados.push_back(0);
      //indices.push_back(j+1);
      int pesito=0;

      for (int k = 0; k < n; k++) {
        //cout << arr[j][k] << " ";
        pesito += arr[j][k];
      }
      pair<int, int> P (j, pesito);
      grados.push_back(P);

      if (j != n ) {
        //cout << " | indice "<< grados[j].first <<"\n";
      }
    }
  
  //std::vector<int> y(x.size());
  /*
  std::iota(indices.begin(), indices.end(), 0);
  auto comparator = [&grados](int a, int b){ return grados[a] < grados[b]; };
  std::sort(indices.begin(), indices.end(), comparator);
  */
  sort(grados.begin(), grados.end(), sortbysec);

  for (int j = 0; j < n; j++) { 
    //cout<<grados[j].first<<" tiene peso "<<grados[j].second<<endl;
  }
  cout<<endl;


  //vector< pair<int,int> > coloreado = WelshPowell(grados, arr);
  vector<int> coloreado= WelshPowell(grados, arr);
  cout << "\nGraph Coloring por Algoritmo Welsh-Poweell - 27 de septiembre 2022" << endl;
  for (int i = 0; i < n; i++)
  {
    cout<<"Node: "<<i<<", Assigned color "<<coloreado[i]<<endl;
  }
  

  return 0;
}