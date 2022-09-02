#include<iostream>
using namespace std;

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

int main(){
	string T, P;
    cout << "Introduce el texto: " << endl;
    cin >> T;
    cout << "Introduce el patron: " << endl;
	cin >> P;
	z_algorithm(T, P);
	return 0;
}
