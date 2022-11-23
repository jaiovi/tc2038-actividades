#include <iostream>
#include <utility>
#include <vector>

#include <fstream>
#include <iostream>
#include <sstream>

#include <stack>
#include <math.h>

using namespace std;

/*
class pair<int,int>
{
	public:
	int x, y;
};
*/

//FUNCIONES para qsort
int compareX(const void* a, const void* b) 
{ 
    pair<int,int> *p1 = (pair<int,int> *)a;
    pair<int,int> *p2 = (pair<int,int> *)b; 
    //pair<int,int> *p1 = (pair<int,int> *)vp1;
    return (p1->first - p2->first); 
} 
int compareY(const void* a, const void* b) 
{ 
    pair<int,int> *p1 = (pair<int,int> *)a;
    pair<int,int> *p2 = (pair<int,int> *)b; 
    return (p1->second - p2->second); 
}
float dist(pair<int, int> p1, pair<int, int> p2) 
{ 
    return sqrt( (p1.first - p2.first)*(p1.first - p2.first) + (p1.second - p2.second)*(p1.second - p2.second) ); 
} 

//Calcula distancia para 2 o 3 puntos
float bruteForce(vector< pair<int, int> > P, int n) 
{ 
    float min = 1000000; 
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
float stripClosest(vector<pair<int,int> > strip, int size, float d){
    float min=d;
    qsort(&strip, size, sizeof(pair<int,int>), compareY); 

    for (int i = 0; i < size; i++)
    {
        //parece n^2, pero a lo max corre 6 veces
        for (int j = i+1; j < size && (strip[j].second - strip[i].second) < min; ++j)
        {
            if (dist(strip[i],strip[j]) < min) 
                min = dist(strip[i], strip[j]); 
        }
        
    }
    return min;
    
}

float closestUtil(vector<pair<int,int> > &P, int n, int high){
    if(n<=3)
        return bruteForce(P,n);
    int mid = n/2;
    pair<int,int> midPoint = P[mid];

    //empezamos similitud mergeSort

    //parametro por referencia, se debe ver reflejado por el propio objeto
    //indice bajo + indice
    float dl = closestUtil(P, mid); 
    float dr = closestUtil(P + mid, n - mid);  
    float d = min(dl, dr); 

    vector<pair<int,int>> strip; 
    int j = 0; 
    for (int i = 0; i < n; i++) 
        if (abs(P[i].first - midPoint.first) < d) 
            strip[j] = P[i], j++;

    float res = stripClosest(strip, j, d);
    return min(d, res);
}

float closest(vector<pair<int,int> > P, int n) 
{ 
    qsort(&P, n, sizeof(pair<int,int>), compareX); 
  
    // Use recursive function closestUtil()
    // to find the smallest distance 
    return closestUtil(P, n); 
} 


int main(){
    /*
    pair<int, int> a(2,3);
    pair<int, int> b(12,30);
    pair<int, int> c(40,50);
    pair<int, int> d(2,3);
    */
    vector<pair<int, int> > P;
    P.push_back(make_pair(2,3));
    P.push_back(make_pair(12,30));
    int n=2;
    cout << "The smallest distance is " << closest(P, n); 
    return 0;
}