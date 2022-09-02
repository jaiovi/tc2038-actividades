#include <iostream>

using namespace std;

int *compute_prefix_function(string P){
    int m = P.length();
    int *pi = new int[m + 1];
    pi[0] = -1;
    int k = -1;m
    for(int q = 1; q < m; q++){
        while(k > -1 && P[k + 1] != P[q]){
            k = pi[k];
        }
        if(P[k + 1] == P[q]){
            k = k + 1;
        }
        pi[q] = k;
    }
    return pi;
}

void KMP(string T, string P){
    int n = T.length();
    int m = P.length();
    int *pi = compute_prefix_function(P);    
    int q = -1;
    for(int i = 0; i < n; i++){
        while(q > 0 && P[q + 1] != T[i]){
            q = pi[q];
        }
        if(P[q + 1] == T[i]){
            q = q + 1;
        }
        if(q == m - 1){
            cout << "Pattern occurs with shift " << i - (m - 1) << endl;
            q = pi[q];
        }
    }
}

int main(){
    string T, P;
    cout << "Ingrese el texto T: " << endl;
    cin >> T;
    cout << "Ingrese el patron P a buscar en T:" << endl;
    cin >> P;
    KMP(T, P);
}