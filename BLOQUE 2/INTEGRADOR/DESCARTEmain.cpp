#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*
ACTIVIDAD INTEGRADORA
Carlos Alejandro Morales Leal A00830435
Jorge Loredo Meléndez     A01284185
Jesus Sebastian Jaime Oviedo  A01412442
17 de octubre del 2022
*/

int inicioLCS = 10000000;
int finLCS = 1;

int longest_common_substring(const char* s1, const char* s2){ // COMPLEJIDAD O(n * m^2)
    //int n = s1.length();
    //int m = s2.length();
    int n = strlen(s1);
    int m = strlen(s2);
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
                    inicioLCS=i; //porque fila y columna 0, aunque empiece 1
                }
                if(LCS[i][j] > max){
                    max = LCS[i][j];
                }
            }else{
                LCS[i][j] = 0;
            }
        }
    }
    finLCS = inicioLCS + (max-1);
    return max;
}

int main()
{
    /* INICIA LECTOR */
    string mcode1 = "mcode1.txt";
    string mcode2 = "mcode2.txt";
    string mcode3 = "mcode3.txt";
    string tras1 = "transmission1.txt";
    string tras2 = "transmission2.txt";

    ifstream Lm1(mcode1.c_str());
    ifstream Lm2(mcode2.c_str());
    ifstream Lm3(mcode3.c_str());
    ifstream Lt1(tras1.c_str());
    ifstream Lt2(tras2.c_str());

    char* m1, m2, m3, t1, t2;
    string line;

    while (getline(Lm1,line)){ m1=line; }
    while (getline(Lm2,line)){ m2=line; }
    while (getline(Lm3,line)){ m3=line; }
    while (getline(Lt1,line)){ t1=line; }
    while (getline(Lt2,line)){ t2=line; }

    Lm1.close();
    Lm2.close();
    Lm3.close();
    Lt1.close();
    Lt2.close();

    cout<<m1<<endl;
    cout<<m2<<endl;
    cout<<m3<<endl;
    cout<<t1<<endl;
    cout<<t2<<endl;
    /* FIN LECTOR */

    int size = longest_common_substring(t1.c_str(), t2.c_str());
    cout<<"parte3"<<endl;
    cout<<"\t"<<inicioLCS<<" "<<finLCS<<endl;

    return 0;
}
