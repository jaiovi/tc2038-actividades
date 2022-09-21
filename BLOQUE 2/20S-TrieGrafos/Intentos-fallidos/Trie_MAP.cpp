#include <iostream>
#include <map>

using namespace std;


class Trie
{
    private:
        map<char, Trie> arbol;
        bool finPalabra = false;

        //DEL INSERT
        string s; ///Palabra a insertar en el Trie
        int tamPalabra; ///Tamaño de la palabra + 1
    public:
        void insertar(Trie &t, int pos, string s, int tamPalabra) ///El Trie por referencia
        {
            if(pos < tamPalabra) //si encuentr
            {
                if(pos == tamPalabra-1)
                    t.finPalabra = true;
                insertar(t.arbol[s[pos]], pos+1, s, tamPalabra); //lo inserta en la siguiente posicion
            }
        }

        void recorrer(Trie t, string palabra)
        {
            if(t.finPalabra)
                cout << palabra << endl;
            for(auto &i:t.arbol)//hasta donde acaben sus ramitas
                recorrer(i.second, palabra+i.first);
        }
};



int main(){
    cout<<"re-TRIES-val | Jesus Sebastian Jaime Oviedo A01412442 - 2 septiembre 2022 - Algoritmos Avanzados"<<endl;
    cout<<"Inicia lectura de txt..."<<endl;
    Trie t;

    string pal[9] =
    {
        "hola",
        "aab",
        "holas",
        "holass",
        "xz",
        "aa",
        "aax",
        "holax",
        "ho"
    };

    for(int i=0; i<9; i++)
    {
        string s = pal[i];
        int tamPalabra = s.size()+1;
        t.insertar(t, 0, s, tamPalabra);
    }

    t.recorrer(t, "");

    return 0;
}