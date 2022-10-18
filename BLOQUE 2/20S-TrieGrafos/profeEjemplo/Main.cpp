#include<iostream>
#include "Trie.hpp"

using namespace std;

int main() {

    Trie T;
    int N;
    cout << "Ingresa el numero N de palabras que insertaras: ";
    cin >> N;
    string palabra;
    for(int i = 0; i < N; i++){
        cout << "Palabra " << i + 1 <<": ";
        cin >> palabra;
        T.Insert(palabra);
    } 

    // Buscar el prefijo en el Trie.
    cout << "Inserta la palabra a buscar: ";
    string prefix;
    cin >> prefix;
    TrieNode *current = T.Search(prefix);
    /*cout << "sali del search" << endl;
    while(current->get_end_of_word() != true){
        cout << current->get_letter() << endl;
        for(int i = 0; i < 26; i++){
            if(current->get_child_at(i) != NULL){
                cout << current->get_child_at(i)->get_letter() << endl;
            }
        }
        break;
    }*/


    
    if (current == NULL or current == &T.root) {
        cout << "No se encontraron palabras que empaten con el prefijo." << endl;
    } else {
        // El prefijo se encontró en el árbol, se buscan los hijos.
        bool haschildren = false;
        for (int c = 0; c < 26; c++) {
            if (current->get_child_at(c) != NULL) {
                 haschildren = true; 
                 break;
            }
        }
        // No se encontraron palabras con el prefijo (solo el pregijo fue encontrado)
        if (haschildren == false) {
            cout << "No se encontraron palabras que empaten con el prefijo." << endl;
        } else {
            cout << "Palabra(s) con el prefijo: " << prefix << endl;
            T.PrintLexical(current, prefix, "");
        }
    }
    return 0;
}