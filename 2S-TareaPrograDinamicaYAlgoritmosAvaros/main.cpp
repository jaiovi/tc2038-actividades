#include <iostream>

#include <fstream>
#include <sstream>
#include <vector>
#include <tgmath.h>
using namespace std;



void cambioDinamico(int p, int q, int n, vector<int>& monedas){

}

vector<int> cambioAvaro(vector<int> monedas, int cantMon, int cambio){
    vector<int>cantMonedas( cantMon);
    cout<<"Cambio a fragmentar "<<cambio<<endl;
    for (int i = 0; i < cantMon ; i++)
    {
        cantMonedas[i] = floor(cambio / monedas[i]); //contamos con monedas infinitas
        //cout<<monedas[i]<<" " <<cambio<<" "<<monedas[i]%cambio<<endl;
        cambio = cambio - (monedas[i]*cantMonedas[i]);
        //cout<<cambio<<endl;
    }
    cout<<"Cambio que no se pudo devolver: "<<cambio<<endl;
    return cantMonedas;
}

int main(int argc, char *argv[])
{
    string nomArchivo = argv[1]; //toma parametro main
    ifstream fileIn(nomArchivo.c_str()); //convierte en const char * y titula el fileIn

    nomArchivo.resize(nomArchivo.size() - 4); //elimina .txt
    nomArchivo += ".out";
    ofstream fileOut(nomArchivo.c_str());

    string line;
    vector<int> monedas; //vector donde se guardan las denominaciones monedas

    cout<<"PROGRA DINAMICA Y ALGORITMOS AVAROS - Equipo LOS HIJOS DE FALCON - 2 septiembre 2022 - Algoritmos Avanzados"<<endl;
    cout<<"Inicia lectura de txt..."<<endl;

    bool primerito = true;
    int cantLineas;
    
    while (getline(fileIn,line)){
        if(primerito){
            cantLineas = stoi(line); //primer dato de cant lineas
            primerito = false;
        }else{
            monedas.push_back( stoi(line) ); //mete monedita
        }
    }

    sort(monedas.begin(),monedas.end(),greater<int>());

    ///// TODO CORRECTO ESTE BLOQUE
    int p = strtol(argv[2], NULL, 10); //precio
    int q = strtol(argv[3], NULL, 10);  //lana dada
    int cambio = q-p;

    //

    vector<int> resultadoAvaro;
    resultadoAvaro = cambioAvaro(monedas, cantLineas, cambio);

    for (int i = 0; i < cantLineas; i++)
    {
        cout<<monedas[i]<<" "<<resultadoAvaro[i]<<endl;
    }
    


    
    return 0;
}
