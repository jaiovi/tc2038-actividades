#include <iostream>
#define ALPHABET_SIZE 3
#define NUMBER_STATES 8
using namespace std;

char E[] = {'a', 'b', 'c'};
int d[NUMBER_STATES][ALPHABET_SIZE] = {1, 0, 0, 1, 2, 0, 3, 0, 0, 1, 4, 0, 5, 0, 0, 1, 4, 6, 7, 0, 0, 1, 2, 0};
int qStart = 0;
int qFinal = 7;

int index(char c){
    for(int i = 0; i < ALPHABET_SIZE; i++){
        if(c == E[i]){
            return i;
        }
    }
    return 0;
}

bool DFA_matcher(string T){
    int n = T.size();
    int q = qStart;
    for(int i = 0; i < n; i++){
        q = d[q][index(T[i])];
        if(q == qFinal){
            cout << "El patron ocurre con desplazamiento " << (i + 1) - (NUMBER_STATES - 1) << endl;
            return true;
        }
    }
    return false;
}

int main(){
    string s;
    cout << "Introduzca el texto E={a,b,c}: " << endl;
    cin >> s;
    if(DFA_matcher(s) == false){
        cout << "Patron no encontrado" << endl;
    }
    return 0;
}