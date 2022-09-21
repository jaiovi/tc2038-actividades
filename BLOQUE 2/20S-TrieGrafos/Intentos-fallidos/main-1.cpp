#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include <Trie.hpp>

int main(int argc, char *argv[])
{
    string nomArchivo = argv[1]; //toma parametro main
    ifstream fileIn(nomArchivo.c_str()); //convierte en const char * y titula el fileIn

    nomArchivo.resize(nomArchivo.size() - 4); //elimina .txt
    nomArchivo += ".out";
    ofstream fileOut(nomArchivo.c_str());

    string line;
    vector<string> palabras; //vector donde se guardan las denominaciones monedas

    cout<<"re-TRIES-val | Jesus Sebastian Jaime Oviedo A01412442 - 2 septiembre 2022 - Algoritmos Avanzados"<<endl;
    cout<<"Inicia lectura de txt..."<<endl;

    bool primerito = true;
    int cantLineas;
    
    while (getline(fileIn,line)){
        if(primerito){
            cantLineas = stoi(line); //primer dato de cant lineas
            primerito = false;
        }else{
            palabras.push_back( line ); //mete
        }
    }

    string busqueda;
    cout<<"Dame la palabra a buscar: ";
    cin>>busqueda;

    return 0;
}
