#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b){
    return (a>b) ? a : b;
}

//como se resuelve la matriz DE MANERA MANUAL

int Knapsack(int W, int wt[], int val[], int n){
    int i, w;
    vector<vector<int>> K(n+1, vector<int>(W+1)); //filas de cantidad de objetos, y pesos enteros posibles en la mochila

    for (i = 0; i < n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if(i==0||w==0) //primera fila subproblema en 0s
                K[i][w]=0;
            else if(wt[i-1] <= w) //magia
                K[i][w] = max(
                    val[i-1] + K[i-1][ w + wt[i-1] ],
                    K[i-1][w]
                );
            else
                K[i][w] = K[i-1][w];
        }
        
    }
    //BACKTRACKING
    w=W;
    i=n;
    cout<<"Items del Knapsack: "<<endl;
    while(i>0){
        if(K[i][w] == K[i-1][w]){
            i--;
        }else{
            cout<<i<<" ";
            w = w - wt[i];
            i--;
        }
    }

    //IMPRIMO TABLA COMPLETA
    cout<<"\n\nTabla:"<<endl;
    for (i = 0; i <= n; i++)
    {
        for ( w = 0; w < W; w++)
        {
            cout<<K[i][w]<<" ";
        }
        cout<<endl;
        
    }
    return K[n][w];
    
    
}

int main(){
    int val[] = {1,2,3,4,5,6,7,8,9,10};
    int wt[] = {1,2,3,4,5,6,7,8,9,10};
    int W=7;

    int n = sizeof(val) / sizeof(val[0]);
    cout<<"\nMax value found: "<<Knapsack(W,wt,val,n);
}