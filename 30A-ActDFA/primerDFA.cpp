#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Jesus Sebastian Jaime Oviedo A01412442
//2 de septiembre del 2022 - Algoritmos avanzados

// codigo disponible en canvas

char E[] = {'a','b','c'};
int delta[3][8] = {{1,0,0},{1,2,0},{3,0,0},{1,4,0},{5,0,0},{1,4,6},{7,0,0},{1,2,0}}; //num states & alphabet size
int m=7; //desde 0 hasta m

int index()

bool DFA1(string texto){
    /*
    int n = texto.lenght();
    int q=0;
    for (int i = 0; i < n; i++)
    {
        q = delta[q][texto.at(n)]
        if(q==m)
            return true;
    }
    */
    return false;
    
}


int *computePrefixFunction(string texto){
    m=texto.length();
    int *pi = new int[m+1];
    pi[1]=-1;
    int k=-1;
    for (int q = 1; q < m; q++)
    {
        while (k>0 && texto[k+1]!=texto[q]){
            k=pi[k];
        }
        if(texto[k+1] == texto[q])
            k+=1;
        pi[q] = k;
    }
    return pi;
    
}
void KMP(string texto, string T){
    int n = T.length();
    int m = texto.length();
    int *pi = computePrefixFunction(texto);
    int q=-1;
    for (int i = 0; i < count; i++)
    {
        /* code */
    }
    
}

int main()
{
    string T="ababaabbc";
    string texto; //p
    cout<<"Introducir el texto o cadena: ";
    cin>>texto;
    if( DFA1(texto) ){
        cout<<"Patron encontrado"<<endl;
    }



    return 0;
}
