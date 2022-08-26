#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//Jesus Sebastian Jaime Oviedo A01412442
//23 de agosto del 2022 - Algoritmos avanzados

class Resultado{
    private:
        int *r;
        int *s;
    public:
    Resultado(int n){
        r = new int[n + 1];
        s = new int[n];
    }

    void set_r_at(int pos, int value){
        r[pos] = value;
    }

    void set_s_at(int pos, int value){
        s[pos] = value;
    }

    int get_r_at(int pos){
        return r[pos];
    }

    int get_s_at(int pos){
        return s[pos];
    }
};

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

Resultado extended_bottom_up_cut_rod(vector<int> p, int n){
    Resultado res(n);
    res.set_r_at(0, 0);
    int q;
    for(int j = 1; j <= n; j++){
        q = -1;
        for(int i = 1; i <= j; i++){
            if( q < p[i - 1] + res.get_r_at(j - i)){
                q = p[i - 1] + res.get_r_at(j - i);
                res.set_s_at(j - 1, i);
            }
        }
        res.set_r_at(j, q);
    }
    return res;
}

int main()
{
    int n=5; //tamaño de vector
    vector<int> p{1,5,8,9,10,17,17,20,24,30}; //precio

    vector<int> r(n+1,-1); //donde se guardaran los cortes MEMOIZED
    cout << "r[" << n << "] Memoized " << memoizedCutRod(p, n, r) <<endl;
    
    //vector<int> s;
    cout<< "r[" <<n <<"] Bottom Up "<<bottomUpCutRod(p,n)<<endl;

    cout << "Extended bottom-up cut rod" << endl;

    Resultado res = extended_bottom_up_cut_rod(p, n);
    cout << "r["<< n << "] = "<< res.get_r_at(n) << endl;
    while(n > 0){
        cout << res.get_s_at(n - 1) << " ";
        n -= res.get_s_at(n - 1);
    }

    return 0;
}