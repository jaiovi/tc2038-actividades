#include "TrieNode.hpp"
#include <string>

using namespace std;

class Trie {

    public:

    TrieNode root;
    /*
    Insertar la palabra en el Trie. Revisar cada caracterer en la cadena.
    Si nunguno de los hijos del nodo actual contiene el caracterer, crear 
    un nuevo hijo para el nodo actual para guardar el caracterer.
    */
    void Insert (string str) {
        TrieNode * current = &root;
        for (int i = 0; i < str.size(); i++) {
            if (current->get_child(str.at(i)) == NULL) {
                current->set_child(str.at(i));
            }
            current = current->get_child(str.at(i));
        }
        current->set_end_of_word(true);
    }

    // Buscar la palabra en el Trie.
    TrieNode * Search (string str) {
        TrieNode * current = &root;
        for (int i = 0; i < str.size(); i++) {
            if (current->get_child(str.at(i))) {
                current = current->get_child(str.at(i));
             } else {
                current = NULL;
                break;
             }
        }
        return current;
    }

    // Imprimir las palabras con el prefijo dado en order léxico.
    void PrintLexical (TrieNode * current, string prefix, string suffix) {
        if (current->get_end_of_word() and suffix.size() != 0) {
            cout << prefix+suffix << endl;  
            return;          
        }
        for (int i=0; i<26; i++) {
            string temp = suffix;
            if (current->get_child_at(i)) {
                temp += current->get_child_at(i)->get_letter();
                PrintLexical(current->get_child_at(i), prefix, temp);
            }
        }
    }
};