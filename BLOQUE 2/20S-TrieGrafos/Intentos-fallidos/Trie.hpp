#include "TrieNode.hpp"

class Trie {
    private:
        TrieNode root;
    public:    
        void Insert (string str);
        TrieNode * Search (string str){
            // return false if Trie is empty
            if (this == nullptr) {
                cout<<"No hay elementos en el arbol"<<endl;
            }
        
            Trie* curr = this;
            for (int i = 0; i < str.length(); i++)
            {
                // go to the next node
                curr = curr->character[str[i]];
                cout<<str[i];
        
                // if the string is invalid (reached end of a path in the Trie)
                if (curr == nullptr) {
                    cout<<endl;
                    cout<<"No encontro similaridades despues"<<endl;
                }
            }
            cout<<"Lo encontramos"<<endl;
        }
};


void Trie::Insert(string str){
    TrieNode* current = &root; //toma de la memoriael dato
    for (int i = 0; i < str.length(); i++)
    {
        char L = str[i];
        if(current->get(i) == NULL){
            current->TrieNode(L);
        }
        current = current->get(i); //avanza al siguiente, i++
    }
    current->set_endWord(true); //defino hojita
    
    
}