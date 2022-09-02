#include <iostream>

using namespace std;

long long prhf(string S){
    int n = S.length();
    int p = 31;
    int m = 1e9 + 9;
    long long valorHash = 0;
    long long potencia = 1;

    for(int i = 0; i < n; i++){
        valorHash = (valorHash + (S[i] - 'a' + 1) * potencia) % m;
        potencia = (potencia * p) % m;
    }
    return valorHash;
}

int main(){
    string S1, S2;
    cout << "Introduce el texto 1: ";
    cin >> S1;
    cout << "Introduce el texto 2: ";
    cin >> S2;
    long long hash1 = prhf(S1);
    long long hash2 = prhf(S2);
    cout << "Valor hash1: " << hash1 << endl;
    cout << "Valor hash2: " << hash2 << endl;
    if(hash1 == hash2){
        cout << "Iguales! Hay colision?" << endl;
    }else{
        cout << "Diferentes" << endl; 
    }
    return 0;
}