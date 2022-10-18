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
  /*
  vector< pair<int, int> > coloreado;
  //primer nodo es color 0
  pair<int, int> Pfirst (0, 0);
  coloreado.push_back(Pfirst);
  //y el resto
  for (int i = 1; i < n; i++)
  {
    pair<int, int> P (i, 99);
    coloreado.push_back(P);
  }
  */
 vector<int> coloreado (n,99);
 coloreado[0]=0;
  /*
  int i=1;
  
  for (int color = 0; color < n; color++)
  {
    for (int j = 0; j < n; j++) {
      int ii = grados[i].first;//indice
      cout<<graph[ii][j]<<" ";
      if( graph[ii][j]==0 && coloreado[j].second!=99){ //&& coloreado[j].second!=coloreado[ii].second
        coloreado[j].second=color;
      }
      i++;
    }
    cout<<endl;
  }
  */
 int color=0;
  //for (int color = 0; color < 5; color++){
    for (int repet = 1; repet < n; repet++)
    {//repetir las filas del grafo
    for (int ii = 0; ii < n; ii++)
    {
      int i = grados[ii].first;//indice
      cout<<i<<" | "<<repet<<" "<<i<<" : "<<graph[repet][i]<<endl;
      if(graph[repet][i]==0 && coloreado[i]==99){
        coloreado[i]=color;
      }
      
    }
    color++;
    }

 //}
 
 
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
        cout << arr[j][k] << " ";
        pesito += arr[j][k];
      }
      pair<int, int> P (j, pesito);
      grados.push_back(P);

      if (j != n ) {
        cout << " | indice "<< grados[j].first <<"\n";
      }
    }
  
  //std::vector<int> y(x.size());
  /*
  std::iota(indices.begin(), indices.end(), 0);
  auto comparator = [&grados](int a, int b){ return grados[a] < grados[b]; };
  std::sort(indices.begin(), indices.end(), comparator);
  */
  sort(grados.begin(), grados.end(), sortbysec);

  for (int j = 0; j < n; j++) { cout<<grados[j].first<<" tiene peso "<<grados[j].second<<endl;}
  cout<<endl;


  //vector< pair<int,int> > coloreado = WelshPowell(grados, arr);
  vector<int> coloreado= WelshPowell(grados, arr);
  cout << "\nGraph Coloring por Algoritmo Welsh-Poweell - 27 de septiembre 2022" << endl;
  //for (int j = 0; j < n; j++) { cout<<coloreado[j].first<<" tiene color "<<coloreado[j].second<<endl;}
  for (int i = 0; i < n; i++)
  {
    cout<<i<<"tiene color"<<coloreado[i]<<endl;
  }
  

  return 0;
}