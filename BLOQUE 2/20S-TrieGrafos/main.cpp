#include <iostream>
#include <string>
#include <vector>

using namespace std;
 
#define ALPHABET_SIZE (26)
#define CHAR_TO_INDEX(c) ((int)c - (int)'a') //genera los indices int, recibiendo algun a-z(26)
 
struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isWordEnd;
};
 
// Constructor del arbol Trie, lleno de nulos
struct TrieNode* getNode(void){
    struct TrieNode* pNode = new TrieNode;
    pNode->isWordEnd = false;
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;
 
    return pNode;
}
 
void insert(struct TrieNode* root, const string key){
    struct TrieNode* pCrawl = root;
    
    //llendo por los niveles...
    for (int i = 0; i < key.length(); i++) {
        int index = CHAR_TO_INDEX(key[i]);
        if (!pCrawl->children[index]) //si es nulo, creamos nuevo nodo referenciador
            pCrawl->children[index] = getNode();
 
        pCrawl = pCrawl->children[index]; //sig
    }
 
    pCrawl->isWordEnd = true; //el ultimo se marca como endWord
}
 
// Si es el ultimo, entrega false. Necesario para impresion autocompletado.
bool esUltimoNodo(struct TrieNode* root){
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return 0;
    return 1;
}
 
void recursivoSugerir(struct TrieNode* root, string prefijoActual){
    // Fin de recursividad de la rama e imprime.
    if (root->isWordEnd)
        cout << prefijoActual << endl;
 
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i]) {
            //  Recursivea por sus hijos para que autocomplete todo.
            char child = 'a' + i;
            recursivoSugerir(root->children[i], prefijoActual + child);
        }
}
 
int definePrintAutocompletado(TrieNode* root, const string consulta){
    struct TrieNode* pCrawl = root;
    for (char c : consulta) {
        int ind = CHAR_TO_INDEX(c);
        
        if (!pCrawl->children[ind])
            return 0;   // ningun string tiene ese prefijo
 
        pCrawl = pCrawl->children[ind]; //traslada
    }
    
    if (esUltimoNodo(pCrawl)) {// Si el prefijo es la misma palabra, porque buscariamos nodos?
        cout << consulta << endl;
        return -1;
    }
    recursivoSugerir(pCrawl, consulta);
    return 1;
}
 
int main()
{
    struct TrieNode* root = getNode();

    int numeroStrings;
    cout<<"RE-TRIES-VAL | Jesus Sebastian Jaime Oviedo A01412442 - 2 septiembre 2022 - Algoritmos Avanzados"<<endl;
    cout<<"\nInserte numero de palabras a meter al arbol: ";
    cin>>numeroStrings;

    for (int i = 0; i < numeroStrings; i++)
    {
        string palabrita;
        cout<<"Inserte palabra #"<<i+1<<" : ";
        cin>>palabrita;
        insert(root, palabrita);
    }

    int repet=1;

    while(repet==1){
        string palabraBusq;
        cout<<"\n+++ Palabra a buscar? ";
        cin>>palabraBusq;

        cout<<"### Coincidencias (autocomplete):"<<endl;
        int comp = definePrintAutocompletado(root, palabraBusq);

        if (comp == -1)
            cout << "No se encontraron otros strings con este prefijo\n";

        else if (comp == 0)
            cout << "Ni palabra ni prefijo se encontro :c\n";
        
        cout<<"\n---------- Crear nueva busqueda? 1 si, 0 no "<<endl;
        cin>>repet;
    }
    return 0;
}