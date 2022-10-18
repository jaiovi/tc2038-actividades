#include <iostream>
using namespace std;

// Imprimir la subcadena
void imprimir_substring(string str, int izquierda, int derecha){
    for (int i = izquierda; i <= derecha; i++)
        cout << str[i];
}



void manacher(string T){
    // Obtener la longitud de la cadena de entrada.
    int n = T.size();

    // Todas las subcadenas de longitud 1 son palíndromos.
    int max_longitud = 1;
    
    int inicio = 0;

    // Revisar todas las subcadenas.
    for (int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            int flag = 1;

            // Verificar una subcadena que sea palíndromo.
            for (int k = 0; k < (j - i + 1) / 2; k++)
                if (T[i + k] != T[j - k])
                    flag = 0;

            // Si la subcadena es un palíndromo
            if (flag && (j - i + 1) > max_longitud){
                inicio = i;
                max_longitud = j - i + 1;
            }
        }
    }
    cout << "El palindromo mas largo es: ";
    imprimir_substring(T, inicio, inicio + max_longitud - 1);
}

int main(){
    string T;
    cout << "Ingrese el texto: ";
    cin >> T;
    manacher(T);
    return 0;
}