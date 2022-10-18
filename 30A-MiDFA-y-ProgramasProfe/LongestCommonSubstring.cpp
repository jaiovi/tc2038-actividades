#include <iostream>
#include <string>

using namespace std;

int inicioLCS = 1000000;
int finLCS = 1;

int longest_common_substring(string s1, string s2){ // 
    int n = s1.length();
    int m = s2.length();
    int LCS[n][m];
    int max = 0;
    // Inicialización renglon 1
    for(int i = 0; i < n; i++){
        if(s1[i] == s2[0]){
            LCS[i][0] = 1;
            max = 1;
        }else{
            LCS[i][0] = 0;
        }
    }
    // Inicialización columna 1
    for(int j = 0; j < m; j++){
        if(s1[0] == s2[j]){
            LCS[0][j] = 1;
            max = 1;
        }else{
            LCS[0][j] = 0;
        }
    }
    // Recorrido usando memoización
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(s1[i] == s2[j]){
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
                if (i<inicioLCS){ // modificacion. Aqui el primer numero que entre se queda para siempre
                    inicioLCS=i + 1; //porque fila y columna 0, aunque empiece 1
                }
                if(LCS[i][j] > max){
                    max = LCS[i][j];
                }
            }else{
                LCS[i][j] = 0;
            }
        }
    }
    finLCS = inicioLCS + (max-1) - 1;
    return max;
}

int main(){
    string s1 = "babbabbaggggaaaa";
    string s2 = "bbabbagg";
    int size = longest_common_substring(s1, s2);
    //cout << "La subcadena comun mas larga tiene longitud " << size << endl;
    cout<<"parte3"<<endl;
    cout<<"\t"<<inicioLCS<<" "<<finLCS<<endl;
    return 0;
} 