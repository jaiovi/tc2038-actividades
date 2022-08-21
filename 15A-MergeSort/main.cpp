#include <iostream>

#include <fstream>
#include <sstream>
#include <vector>

#include <algorithm>
//Jesus Sebastian Jaime Oviedo A01412442
//19 de agosto del 2022 - Algoritmos avanzados

using namespace std;

template<class T>
void mezcla(vector<T>& list,int start,int mid, int end, int &nCompara){
    //vector auxiliar vacio
    vector<T> left;
    vector<T> right;
    int leftSize=mid-start+1;
    int rightSize=end-mid;

    for(int i=0;i<leftSize;i++)
        left.push_back(list[start+i]);
    for(int i=0;i<rightSize;i++)
        right.push_back(list[i+mid+1]);

    int leftPos=0;
    int rightPos=0;
    int pos=start;

    //comparamos los elementos de la lista izq y der
    while(leftPos<leftSize && rightPos<rightSize){
        nCompara++;
        if(left[leftPos]<right[rightPos]){
            list[pos]=left[leftPos];
            leftPos++;
        }else{
            list[pos]=right[rightPos];
            rightPos++;
        }
        pos++;
    }
    //recorremos la lista der para asignar los elem restantes
    while(leftPos<leftSize){
        list[pos]=left[leftPos];
        leftPos++;
        pos++;
    }
    //recorremos la lista izq para asignar los elem restantes
    while(rightPos<rightSize){
        list[pos]=right[rightPos];
        rightPos++;
        pos++;
    }
}

template<class T>
void mergeSort(vector<T>& list,int inicio, int fin, int &nCompara){//O (n log n)
    if(inicio<fin){
        int centro=(inicio+fin)/2;
        //recursividad para separar
        mergeSort(list,inicio,centro,nCompara);//divide izq
        mergeSort(list, centro+1,fin,nCompara);//divide der
        mezcla(list, inicio, centro, fin, nCompara);//unimos las listas
    }
}

/*MAIN*/
int main(int argc, char *argv[])
{
    string nomArchivo = argv[1]; //toma parametro main
    ifstream fileIn(nomArchivo.c_str()); //convierte en const char * y titula el fileIn

    nomArchivo.resize(nomArchivo.size() - 4); //elimina .txt
    nomArchivo += ".out";
    ofstream fileOut(nomArchivo.c_str());

    string line;
    vector<double> numero; //acepta x cantidad de numeros double

    cout<<"MERGE SORT - Jesus Sebastian Jaime Oviedo A01412442 - 19 agosto 2022 - Algoritmos Avanzados"<<endl;
    cout<<"Inicia lectura de txt..."<<endl;

    while (getline(fileIn,line)){
        numero.push_back( stod(line) ); //convierte el string linea a double
    }
    int longitudVector = numero[0];
    int nCompara=0;
    
    mergeSort(numero, 1, longitudVector, nCompara);

    cout<<"LISTA ORDENADA! Se hicieron "<<nCompara<<" comparaciones"<<endl;
    for(int i=1;i<=longitudVector;i++){
        cout<<numero[i]<<endl;
        fileOut<<numero[i]<<endl;
    }
    cout<<"Fin de la lista"<<endl;
    
    return 0;
}
