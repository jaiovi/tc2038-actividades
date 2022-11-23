#include <fstream>
#include <iostream>
#include <sstream>

#include <utility>
#include <vector>
#include <float.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

class Point
{
	public:
	int x, y;
};

//FUNCIONES para qsort
int compareX(const void* a, const void* b) 
{ 
    Point *p1 = (Point *)a, *p2 = (Point *)b; 
    return (p1->x - p2->x); 
} 
int compareY(const void* a, const void* b) 
{ 
    Point *p1 = (Point *)a, *p2 = (Point *)b; 
    return (p1->y - p2->y); 
}
float dist(pair<int, int> p1, pair<int, int> p2) 
{ 
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) ); 
} 

//Calcula distancia para 2 o 3 puntos
float bruteForce(vector< pair<int, int> > P, int n) 
{ 
    float min = FLT_MAX; 
    for (int i = 0; i < n; ++i) 
        for (int j = i+1; j < n; ++j) 
            if (dist(P[i], P[j]) < min) 
                min = dist(P[i], P[j]); 
    return min; 
} 

/*Saques el min
float min(float x, float y) 
{ 
    return (x < y)? x : y; 
} 
*/
  
//Cierra el strip para hace busq eficiente. O(n)
float stripClosest(vector<Point > strip, int size, float d){
    float min=d;
    qsort(strip, size, sizeof(Point), compareY); 

    for (int i = 0; i < size; i++)
    {
        //parece n^2, pero a lo max corre 6 veces
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)
        {
            if (dist(strip[i],strip[j]) < min) 
                min = dist(strip[i], strip[j]); 
        }
        
    }
    return min;
    
}

float closestUtil(vector<Point > P, int n){
    if(n<=3)
        return bruteForce(P,n);
    int mid = n/2;
    Point midPoint = P[mid];

    //empezamos similitud mergeSort
    float dl = closestUtil(P, mid); 
    float dr = closestUtil(P + mid, n - mid);  
    float d = min(dl, dr); 

    Point strip[n]; 
    int j = 0; 
    for (int i = 0; i < n; i++) 
        if (abs(P[i].x - midPoint.x) < d) 
            strip[j] = P[i], j++;

    float res = stripClosest(strip, j, d);
    return min(d, res);
}

float closest(vector<Point> P, int n) 
{ 
    qsort(P, n, sizeof(Point), compareX); 
  
    // Use recursive function closestUtil()
    // to find the smallest distance 
    return closestUtil(P, n); 
} 


int main(int argc, char *argv[]){
    
    //vector<Point> P = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    
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
        Punto a(arr[idxM][0],arr[idxM][1]);
        listado.push_back(a);
        idxM++;
        idxN = 0;
    }

    //vector<pair<int, int> > P;
    int n = sizeof(P) / sizeof(P[0]);
    cout << "The smallest distance is " << closest(listado, n); 
    return 0;
}