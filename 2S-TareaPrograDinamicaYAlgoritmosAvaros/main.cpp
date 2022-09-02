#include <iostream>

#include <fstream>
#include <sstream>
#include <vector>

#include <tgmath.h>
#include <algorithm>

using namespace std;

/*
int minCoins(int N, int M, vector<int> dp, vector<int> monedas) //N es cambio, M es cantMon
{
  dp.push_back(0); //cambio de 0 es 0
  
  //Iterating in the outer loop for possible values of sum between 1 to N
  //Since our final solution for sum = N might depend upon any of these values
  for(int i = 1;i<=N;i++)
  {
    //Inner loop denotes the index of coin array.
    //For each value of sum, to obtain the optimal solution.
    for(int j = 0;j<M;j++)
    {
      //i —> sum
      //j —> next coin index
      //If we can include this coin in our solution
      if(monedas[j] <= i)
      {
        //Solution might include the newly included coin
        dp.push_back ( monedas[j] );
      }
    }
  }
  return dp[N];
}
*/

/*
vector<int> cambioDinamico(vector<int> monedas, int indice, int cantMon, int cambio){
  vector<int> cantMonedas( cantMon);

  if(indice==cantMon-1){//va reduciendo el limite
    cantMonedas[indice] = floor(cambio / monedas[indice]);
    cambio = cambio - (monedas[indice]*cantMonedas[indice]);
  }else{
    cantMonedas = cambioDinamico(monedas, indice+1, cantMon, cambio);
  }
  return cantMonedas;

}
*/

vector<int> minCoins(vector<int> coins, int m, int V)
{
    vector<int> table(V+1, INT_MAX);
    table[0] = 0;
 
    // values from 1 to V
    for (int i=1; i<=V; i++)
    {
        for (int j=0; j<m; j++)
          if (coins[j] <= i)
          {
              int sub_res = table[i-coins[j]];
              if (sub_res != INT_MAX && sub_res + 1 < table[i])
                  table[i] = sub_res + 1;
          }
    }
    if(table[V]==INT_MAX)
      return vector<int>();
   
    return table;
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

    cout<<"Resultado avaro"<<endl;
    vector<int> resultadoAvaro;
    resultadoAvaro = cambioAvaro(monedas, cantLineas, cambio);

    
    
    vector<int> dp;
    cout<<"Resultado dinamico"<<endl;
    vector<int> resultadoDinamico;
    //resultadoDinamico = cambioDinamico (monedas, 0, cantLineas, cambio);
    resultadoDinamico=minCoins(monedas, cantLineas, cambio);
    //cout << "Minimum coins required is "<< minCoins(coins, m, V);

    for (int i = cantLineas-1; i >=0 ; i--)
    {
        cout<<monedas[i]<<" "<<resultadoAvaro[i]<<endl;
        //cout<<monedas[i]<<" "<<resultadoDinamico[i]<<endl;
        fileOut<<monedas[i]<<" "<<resultadoAvaro[i]<<endl;
    }

    /*
    cout<<"MinCoins :" << minCoins(cambio, cantLineas, dp, monedas);
    for (int i = 0; i < dp.size(); i++)
    {
        cout<<dp[i]<<endl;
    }
    */
        
    return 0;
}
