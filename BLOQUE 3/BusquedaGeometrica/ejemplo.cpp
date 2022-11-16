
#include <fstream>
#include <iostream>
#include <sstream>

#include <utility>
#include <vector>
#include <float.h>
#include <math.h>
using namespace std;

class Punto
{
	public:
	int x, y;
	
};

//FUNCIONES para qsort
int compareX(const void* a, const void* b)
{
	Punto *p1 = (Punto *)a, *p2 = (Punto *)b;
	return (p1->x - p2->x);
}
int compareY(const void* a, const void* b)
{
	Punto *p1 = (Punto *)a, *p2 = (Punto *)b;
	return (p1->y - p2->y);
}
float dist(Punto p1, Punto p2)
{
	return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) );
}

//Calcula distancia para 2 o 3 puntos
float fuerzaBruta(Punto P[], int n)
{
	float min = FLT_MAX;
	for (int i = 0; i < n; ++i){
		for (int j = i+1; j < n; ++j){
			if (dist(P[i], P[j]) < min){
				min = dist(P[i], P[j]);
			}
		}
	}
	return min;
}

//Cierra el strip para hace busq eficiente. O(n)
float stripClosest(Punto strip[], int size, float d)
{
	float min=d;
	qsort(strip, size, sizeof(Punto), compareY);

	for (int i = 0; i < size; ++i){
		//parece n^2, pero a lo max corre 6 veces
		for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j){
			if (dist(strip[i],strip[j]) < min)
				min = dist(strip[i], strip[j]);
		}
	}
	return min;
}

float closestUtil(Punto P[], int n)
{
	// caso bruto, 2 o 3 puntos
	if (n <= 3)
		return fuerzaBruta(P, n);

	//ubicamos punto medio
	int mid = n/2;
	Punto midPoint = P[mid];

	//empezamos similitud mergeSort
	float dl = closestUtil(P, mid);
	float dr = closestUtil(P + mid, n - mid);
	float d = min(dl, dr);

	// construyes strip de puntos cercanos
	Punto strip[n];
	int j = 0;
	for (int i = 0; i < n; i++)
		if (abs(P[i].x - midPoint.x) < d)
			strip[j] = P[i], j++;

	// Sacas minn
	return min(d, stripClosest(strip, j, d) );
}
//Principal, o(n log n)
float closest(Punto P[], int n)
{
	qsort(P, n, sizeof(Punto), compareX);
	return closestUtil(P, n);
}

// Driver code
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

    Punto listado[n];

    for (std::string line; getline(input, line);) {
        stringstream ss(line);
        string s;
        while (std::getline(ss, s, delim)) {
			arr[idxM][idxN] = stoi(s);
			idxN++;
        }
        Punto A = {arr[idxM][0],arr[idxM][1]};
		listado[idxM]=A;
		//reset al sig ciclo
        idxM++;
        idxN = 0;
    }
    /* lector finaliza */

	cout<<"Busqueda Geometrica 2 puntos por divide venceras - Jesus Sebastian Jaime Oviedo A01412442 - Algoritmos Avanzados 8 noviembre 2022"<<endl;
	cout << "La distancia mas corta es: " << closest(listado, n);
	return 0;
}