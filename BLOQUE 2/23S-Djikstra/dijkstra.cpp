#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>

#include <limits.h>


//V (tamano de lado) es n. hay que pasarlo entre las funciones.
using namespace std;

int minDistance(int dist[], int n)

{
  int min = INT_MAX, min_index;
  for (int v = 0; v < n; v++ ){
    
  }

  return 0;
}

void printSolution(int dist[], int src, int tamanoLado){ //aqui imprime el vector - O(n)
  cout << "Vertex \t Distance from Source" << endl;
  for (int i = 0; i < tamanoLado; i++)
    cout << "N = INTode " <<src<<" to node "<< i << " : " << dist[i] << endl;
}

void dijkstra(int** graph, int src, int n){

}

int main(int argc, char *argv[]) {

  // LECTOR DE TXT
  string file = argv[1];
  ifstream input(file);
  string line = "";

  getline(input, line); //N es el tamano del lado de la matriz grafa
  const int n = stoi(line);

  int idxM = 0;
  int idxN = 0;
  const char delim = ' ';

  //int **arr = new int*[n];
  int arr[n][n];

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

}