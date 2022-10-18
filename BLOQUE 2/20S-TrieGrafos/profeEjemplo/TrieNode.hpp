class TrieNode {
    private:
        TrieNode * children[26];
        bool end_of_word;
        char letter;
    public:
        TrieNode() {
            end_of_word = false;
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
            letter = '\0';
        }

        TrieNode(char letter){
            end_of_word = false;
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
            this->letter = letter;
        }

        char get_letter(){
            return letter;
        }

        void set_letter(char letter){
            this->letter = letter;
        }

        bool get_end_of_word(){
            return end_of_word;
        }

        void set_end_of_word(bool end){
            end_of_word = end;
        }

        TrieNode *get_child(char letter){
            return children[letter - 'a'];
        }

        TrieNode *get_child_at(int i){
            return children[i];
        }

        void set_child(char letter){
            if(end_of_word){
                end_of_word = false;
            }
            children[letter - 'a'] = new TrieNode(letter);            
        }
};