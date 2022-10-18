#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <stack>

#include <limits.h>
  
using namespace std;

int** floydWarshall (int** W, int n){
    //int** dp = W; //crear matriz de distancias
    int dp[n][n]=W;
    int pi[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if( i == j || W[i][j] = INT_MAX)
            {
                pi[i][j] = NULL;
            }
            else if (i => j && W[i][j] < INT_MAX){
                    pi[i][j] = i;
            } 
        }
        
    }
    

    
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(dp[i][j] > dp[i][k] + dp[k][j] && (dp[k][j] != INT_MAX && dp[i][k] != INT_MAX) )
                {
                    dp[i][j] = dp[i][k] + dp[k][j];
                    pi[i][j] = pi[k][j];
                }
            }
            
        }
        
    }
    ImprimirCamino(pi, 1, f);
    return dp;
}

void ImprimirCamino(int **pi, int i, int f){
    stack<int> my_stack;
    my_stack.push(f);
    while (true){
        f = pi[i][f]; //subarray minus last item
        my_stack.push(f);
        if(f == 1){
            break;
        }
    }

    while (!my_stack.empty()){
        int regalo = my_stack.pop();
        cout << regalo << " -> "<<endl;
    };

}

int main(int argc, char *argv[]) { //COMPLEJIDAD GENERAL O(n^3)

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

    floydWarshall(arr, n);

}