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

vector<int>
WelshPowell(int** graph, int n){ //COMPLEJIDAD O(n^2)
    list<int> *adyacencia;

    adyacencia = new list<int>[n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
        if (graph[i][j] == 1) {
            adyacencia[i].push_back(j);
            adyacencia[j].push_back(i);
            }
        }
    }
    vector<int> colors (n,-1);
    colors[0]=0; //El primer elemento en el grafo tendra color 0

    vector<bool> visited(n, false);
    int idx;

    //PROCEDIMIENTO
    for (int k = 1; k < n; k++) {
        list<int>::iterator i;
        for (i = adyacencia[k].begin(); i != adyacencia[k].end(); ++i) {
            if (colors[*i] != -1) {
                visited[colors[*i]] = true; //visitamos adayacentes y alertamos
            }
        }
        for (idx = 0; idx < n; idx++) {
            if (visited[idx] == false) {
                break; //damos cuello al color min a darle
            } else if (idx+1 == n){
                cout<<"!!!!!"<<endl;
                cout<<"No es posible asignar colores a los nodos"<<endl; //colision y no se pudo
                return colors;
            }
        }

        colors[k] = idx; //se le asigna
        for (i = adyacencia[k].begin(); i != adyacencia[k].end(); ++i) {
            if (colors[*i] != -1) {
                visited[colors[*i]] = false; //quitamos las alertas
            }
        }
    }
    return colors;
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
    /*TERMINA EL LECTOR*/

    vector<int> coloreado= WelshPowell(arr, n);
    cout << "\nGraph Coloring por Algoritmo Welsh-Powell - 21 de octubre del 2022 - Jesus Sebastian Jaime Oviedo A01412442" << endl;
    for (int i = 0; i < n; i++)
    {
        cout<<"Node: "<<i<<", Assigned color "<<coloreado[i]<<endl;
    }

}