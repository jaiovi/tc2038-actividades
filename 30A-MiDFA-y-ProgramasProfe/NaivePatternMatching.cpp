#include <iostream>

using namespace std;

int naive_string_matcher(string T, string P){
    int n = T.length();
    int m = P.length();
    bool pattern_matched;
    for(int s = 0; s <= n - m; s++){
        pattern_matched = true;
        for(int i = 0; i < m; i++){
            if(T[s + i] != P[i]){
                pattern_matched = false;
                break;
            }
        }
        if(pattern_matched){
            return s;
        }
    }
    return -1;
}

int main(){
    string T, P;
    cout << "Ingrese el texto T: " << endl;
    cin >> T;
    cout << "Ingrese el patron P a buscar en T:" << endl;
    cin >> P;
    int shift = naive_string_matcher(T, P);
    if(shift != -1){
        cout << "Encontre el patron con shift " << shift << endl;
    }else{
        cout << "Patron no encontrado" << endl;
    }

    return 0;
}