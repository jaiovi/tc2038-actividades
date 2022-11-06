#include <iostream>
#include <utility>
#include <vector>

#include <fstream>
#include <iostream>
#include <sstream>

#include <stack>

using namespace std;
//https://docs.google.com/document/d/1MvEVP64Gb1IKOJj_txNNNRGP5LzNv3lzE7Ce3ll34Dw/edit?usp=sharing

pair<int,int> p0;

pair<int,int> nextToTop(stack<pair<int,int> >&S){
    pair<int,int> p = S.top();
	S.pop();
	pair<int,int> res = S.top();
	S.push(p);
	return res;
}

/*
float arctan(pair<int,int> punto, pair<int,int> origen){
    int x= punto.first - origen.first;
    int y=punto.second - origen.second;
    int res = atan(y/x);
    return res;
}
*/

int distSq(pair<int,int> p1, pair<int,int> p2)
{
    return (p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second);
}

int orientation(pair<int,int> p, pair<int,int> q, pair<int,int> r) //en reemplazo del arctan.
{
    //p siendo nuestro origen, q y r los puntos a calcular distancia. Usar ec. distancia cuadrada
    int valor = (q.second - p.second) * (r.first - q.first) - (q.first - p.first) * (r.second - q.second);
 
    if (valor == 0) return 0;  //puntos colineares
    return (valor > 0)? 1 : 2; //1 horario, 2 antihorario
}

//checa si es menor o mayor distancia, auxilia el qsort
int compare(const void *vp1, const void *vp2){
    pair<int,int> *p1 = (pair<int,int> *)vp1;
    pair<int,int> *p2 = (pair<int,int> *)vp2;

    int o = orientation(p0, *p1, *p2);
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;

    return (o == 2)? -1: 1;
}


void GrahamScan(vector<pair<int,int> > listado, int n){ //en n puntos encontra figura convexa de m puntos. O(n log n)
    //ordenar, encontrando el punto mas cercano linea 0
    int ymin = listado[0].second;
    int min = 0;
    for (int i = 0; i < n; i++)
    {
        int y = listado[i].second;
        //elge el izquierdo o mas fondo, y lo va haciendo hasta el mas
        if( (y<ymin) || (ymin==y && listado[i].first<listado[min].first) ){
            ymin = listado[i].second;
            min=i;
        }
    }
    swap(listado[0],listado[min]);
    p0 = listado[0];
    qsort(&listado[1], n-1, sizeof(pair<int,int>), compare); //ordena todo

    //1RA PARTE
    int m=1;
    for (int i = 1; i < n; i++)
    {
        while( i<n-1 && orientation(p0,listado[i],listado[i+1])==0){
            i++;//ignora punto si colinear
        }
        listado[m] = listado[i];
        m++;//m es la nueva n
    }

    if(m<3){
        return;//con menos de tres puntos no jala Graham Scan
    }

    //2DA PARTE
    stack<pair<int,int> > S;
    S.push(listado[0]);
    S.push(listado[1]);
    S.push(listado[2]);

    for (int i = 3; i < m; i++){ //Por orientacion (angulo) evalua si incluir punto en figura o no
        while(S.size()>1 && orientation(nextToTop(S),S.top(), listado[i])!=2){
            S.pop();
        }
        S.push(listado[i]);
    }

    stack<pair<int,int> > temp;

    //IMPRIMIR STACK
    while (!S.empty())//reordena como pedido en el ejercicio
    {
        temp.push(S.top());
        S.pop();
    }
    while (!temp.empty()){ 
        pair<int,int> p = temp.top();
        cout << p.first << " " << p.second << endl;
        temp.pop();
    }

}

int main(int argc, char *argv[])
{
    // LECTOR DE TXT
    string file = argv[1];
    ifstream input(file);
    string line = "";
        
    getline(input, line); //N es el tamano del lado de los datos
    const int n = stoi(line);

    int idxM = 0;
    int idxN = 0;
    const char delim = ' ';

    int **arr = new int*[n]; //crear matriz
    for (int i = 0; i < n; i++) {
        arr[i] = new int[2];
    }
    vector< pair<int,int> > listado;

    for (std::string line; getline(input, line);) {

        stringstream ss(line);
        string s;
        while (std::getline(ss, s, delim)) {
        arr[idxM][idxN] = stoi(s);
        idxN++;
        }
        pair<int,int> a(arr[idxM][0],arr[idxM][1]);
        listado.push_back(a);
        idxM++;
        idxN = 0;
    }
    /* lector finaliza */

    /*
    for (int i = 0; i < listado.size(); i++)
    {
        cout<<listado[i].first<<" "<<listado[i].second<<endl;
    }
    */
   
   cout<<"Graham Scan para Caso Convexo - Jesus Sebastian Jaime Oviedo A01412442 - Algoritmos Avanzados 6 noviembre 2022"<<endl;
   GrahamScan(listado, n);
    
}