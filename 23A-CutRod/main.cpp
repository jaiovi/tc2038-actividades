#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//Jesus Sebastian Jaime Oviedo A01412442
//2 de septiembre del 2022 - Algoritmos avanzados

template<class T>
int memoizedCutRod(vector<T>& p, int n, vector<T>& r){ //recuerda q te regres r grandote
    int q;
    if(r[n]>=0){
        return r[n];
    } 
    if(n==0){q=0;}   //si r es de 1 a n+1
    else{
        q=-1;
        for (int i = 1; i <= n; i++) //ojo con los indices
        {
            q = max(q, p[i-1] + memoizedCutRod(p,n-i,r));
        }
        
    }
    r[n]=q;
    return q;
    
}

template<class T>
int bottomUpCutRod(vector<T>& p, int n){ //s es nuestro 2do return
    vector<int> r;
    int q;
    r.push_back(0);//r[0]=0;

    for (int j = 0; j < n; j++)
    {
        q=-1;
        for (int i = 1; i < j; i++)
        {
            q = max(q, p[i] + r[j-1]);
            /*
            if(q<p[i]+r[j-1]){
                q=p[1]+r[j-1];
                s.push_back
            }
            */
        }
        r.push_back(q); //r[j]=q;
        
    }

    return r[n];
    
}

template<class T>
void printCutRodSolution(vector<T>& p, int n){
    
}

int main()
{
    int n=5; //tamaño de vector
    vector<int> p{1,5,8,9,10,17,17,20,24,30}; //precio

    vector<int> r(n+1,-1); //donde se guardaran los cortes MEMOIZED
    cout << "r[" << n << "] Memoized " << memoizedCutRod(p, n, r) <<endl;
    
    //vector<int> s;
    cout<< "r[" <<n <<"] Bottom Up "<<bottomUpCutRod(p,n)<<endl;

    return 0;
}
