#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <sstream>
using namespace std;

//EJERCICIO CLASE 2 SEPTIEMBRE
//Carlos Alejandro Morales Leal A00830435
//Jorge Loredo Meléndez     A01284185
//Jesus Sebastian Jaime Oviedo  A01412442

//Z ALGORITHM
int *calculate_z_array(string str);

void z_algorithm(string T, string P){
	string S = P + "$" + T;
	int l = S.length();
	int *Z = calculate_z_array(S);	
	for (int i = 0; i < l; ++i){
		if (Z[i] == P.length()){
			cout << "Patron encontrado en el indice " << i - P.length() - 1 << endl;
        }
	}
}


int *calculate_z_array(string str){
	int n = str.length();
    int *Z = new int[n];
	int L, R, k;
	L = R = 0;
	for (int i = 1; i < n; ++i){
		if (i > R){
			L = R = i;
			while (R<n && str[R-L] == str[R]){
				R++;
            }
			Z[i] = R-L;
			R--;
		}else{
			k = i-L;
			if (Z[k] < R-i+1){
				Z[i] = Z[k];
            }else{			
				L = i;
				while (R<n && str[R-L] == str[R]){
					R++;
                }
				Z[i] = R-L;
				R--;
			}
		}
	}
    return Z;
}


//HASH
bool validadorHash(int hash1, int hash2){
    if(hash1==hash2)
        return true;
    else
        return false;
}

long long prhf(string S){
    int n = S.length();
    int p = 31;
    int m = 1e9 + 9;
    long long valorHash = 0;
    long long potencia = 1;

    for(int i = 0; i < n; i++){
        valorHash = (valorHash + (S[i] - 'a' + 1) * potencia) % m;
        potencia = (potencia * p) % m;
    }
    return valorHash % 20000;
}


//KMP (deprecated)
int *compute_prefix_function(string P){
    int m = P.length();
    int *pi = new int[m + 1];
    pi[0] = -1;
    int k = -1;
    for(int q = 1; q < m; q++){
        while(k > -1 && P[k + 1] != P[q]){
            k = pi[k];
        }
        if(P[k + 1] == P[q]){
            k = k + 1;
        }
        pi[q] = k;
    }
    return pi;
}

void KMP(string T, string P){
    int n = T.length();
    int m = P.length();
    int *pi = compute_prefix_function(P);    
    int q = -1;
    for(int i = 0; i < n; i++){
        while(q > 0 && P[q + 1] != T[i]){
            q = pi[q];
        }
        if(P[q + 1] == T[i]){
            q = q + 1;
        }
        if(q == m - 1){
            cout << "Pattern occurs with shift " << i - (m - 1) << endl;
            q = pi[q];
        }
    }
}

int main(int argc, char *argv[])
{
    //LECTOR
    string file = argv[1];
    ifstream input(file);
    string line = "";
    
    vector<string> palabras;
    const char delim = ' ';



    for(std::string line; getline(input, line);) {
      
        stringstream ss(line);
        string s;
        while (std::getline(ss, s, delim)) {
            palabras.push_back(s);
        }
    }

    //for(int j = 0; j<palabras.size(); j++){
    //    cout<<palabras[j]<<" ";
    //}


    //PROCESAMIENTO
        
    vector<string> hash(50000);

    for (int i = 0; i < palabras.size(); i++)
    {
        hash[prhf(palabras[i])] = palabras[i];
        //hash.push_back( prhf(palabras[i]) );
    }

    string busqueda;
    string palabrasConcat="";

    cout<<"Deme la palabra a buscar: ";
    cin>>busqueda;

    //cout<<hash[prhf(busqueda)]<<endl;

    if( hash[prhf(busqueda)] == busqueda ){
        cout<<"Si esta :D"<<endl;
        for(int l = 0; l<palabras.size(); l++){
            palabrasConcat += palabras[l] + " ";
        }
        //cout<<palabrasConcat;
        z_algorithm(palabrasConcat,busqueda);

    } else{
        cout<<"No esta :c";
    }
    
    return 0;
}
