#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>

#include <limits.h>
//V (tamano de lado) es "n" hay que pasarlo entre las funciones.

using namespace std;

int minDistance(int dist[], bool sptSet[],const int n) //Complejida O(n)
{
  int min = INT_MAX, min_index; //definimos dos ints

  for (int v = 0; v < n; v++){
    if (sptSet[v] == false && dist[v] <= min){
      min = dist[v];
      min_index = v;
    }
  }
  return min_index;
}

void printSolution(int dist[], int src, const int tamanoLado){ //aqui imprime el vector - Complejida O(n)
  for (int i = 0; i < tamanoLado; i++){
    //consideramos programaticamente pos 0. Validamos que no es "node 1 to node 1"
    if(src!=i)
      cout << "node " <<src+1<<" to node "<< i+1 << " : " << dist[i] << endl; 
  }
}

void dijkstra(int** graph, int src, const int n){ //COMPLEJIDAD O(n^2)
  //definimos vectores auxiliares
  int dist[n];
  bool sptSet[n];
  for (int i = 0; i < n; i++){
    dist[i] = INT_MAX;
    sptSet[i] = false;
  }

  //del src al src, pues es 0 la distancia: estas encima de el
  dist[src] = 0;

  for (int count = 0; count < n - 1; count++) {
    int u = minDistance(dist, sptSet, n);
    sptSet[u] = true;

    //empieza a ver las conexiones con sus distancias
    for (int v = 0; v < n; v++){
      if (!sptSet[v]
      && graph[u][v] != -1
      && dist[u] != INT_MAX 
      && dist[u] + graph[u][v] < dist[v]) //graph[u][v] != -1 es que existe conexion
        dist[v] = dist[u] + graph[u][v];
    }
  }

  //sale del for, e imprime solucion
  printSolution(dist, src, n);
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
  
  //IMPRIMIMOS GRAFO RECIBIDO
  for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        cout << arr[j][k] << " ";
      }
      if (j != n - 1) {
        cout << "\n";
      }
    }
  cout << "\nDijkstra - Eq1 Los hijos de Falcon - 27 de septiembre 2022" << endl;
  //AHORA PROCESAMOS
  for (int i = 0; i < n; i++)
    {
        dijkstra(arr, i, n);
        cout<<endl;
    }
}