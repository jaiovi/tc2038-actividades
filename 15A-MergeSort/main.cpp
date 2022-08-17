#include <iostream>

#include <fstream>
#include <sstream>
#include <vector>

#include <algorithm>

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
int main()
{
    ifstream fileIn("numeros.txt");
    ofstream fileOut("numeros.out");

    string line;
    vector<int> numero;

    cout<<"Inicia lectura de txt..."<<endl;

    while (getline(fileIn,line)){
        numero.push_back( stoi(line) );
    }

    printf("Hola Mundo\n");

    int longitudVector = numero[0];
    //numero.erase(numero.begin());

    int nCompara=0;

    for(int i=1;i<=longitudVector;i++){
        cout<<numero[i]<<endl;
    }
    cout<<"Fin de la lista"<<endl;
    
    mergeSort(numero, 1, longitudVector, nCompara);

    for(int i=1;i<=longitudVector;i++){
        cout<<numero[i]<<endl;
        fileOut<<numero[i]<<endl;
    }
    cout<<"Fin de la lista"<<endl;
    
    return 0;
}
