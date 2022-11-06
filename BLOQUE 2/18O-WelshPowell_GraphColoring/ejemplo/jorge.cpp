#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <numeric>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

//Complejidad 0(n²)
int main(int argc, char *argv[]) {

  // read .txt File
  string file = argv[1];
  ifstream input(file);
  string line = "";

  getline(input, line);
  const int m = stoi(line);

  int idxM = 0;
  int idxN = 0;
  const char delim = ' ';
  int colors[m];
  colors[0] = 0;
  int idx;

  int **arr = new int *[m];

  for (int i = 0; i < m; i++) {
    arr[i] = new int[m];
  }

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


  
  list<int> *adyacencia;
  adyacencia = new list<int>[m];
  
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == 1) {
        adyacencia[i].push_back(j);
        adyacencia[j].push_back(i);
      }
    }
  }

  for (int i = 1; i < m; i++) {
    colors[i] = -1;
  }

  bool visitados[m];
  for (int j = 0; j < m; j++) {
    visitados[j] = false;
  }

  for (int k = 1; k < m; k++) {
    list<int>::iterator i;
    for (i = adyacencia[k].begin(); i != adyacencia[k].end(); ++i) {
      if (colors[*i] != -1) {
        visitados[colors[*i]] = true;
      }
    }
    for (idx = 0; idx < m; idx++) {
      if (visitados[idx] == false) {
        break;
      }
    }

    colors[k] = idx;
    for (i = adyacencia[k].begin(); i != adyacencia[k].end(); ++i) {
      if (colors[*i] != -1) {
        visitados[colors[*i]] = false;
      }
    }
  }

  for (int l = 0; l < m; l++) {
    cout << "Node: " << l << ", Assigned Color: " << colors[l] << endl;
  }

  return 0;
}