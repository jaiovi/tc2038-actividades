#include <string>
using namespace std;

class TrieNode {
    private:
        TrieNode * children[26];
        bool end_of_word;
        char letter;
    public:
        TrieNode() {
            end_of_word = false;
            for (int i = 0; i < 26; i++) { //26 de las posibles bifurcaciones de letras al siguiente
                children[i] = NULL;
            }
            letter = '\0';
        }

        TrieNode(char letter){ //es mi setter
            letter = letter;
        }

        void set_endWord(bool setter){end_of_word=setter;}

        char get(int i){return letter;}

};