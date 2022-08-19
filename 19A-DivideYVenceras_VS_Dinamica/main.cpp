#include <iostream>
#include <vector>
using namespace std;

int fibDinamico(int n, vector<int> memo){ //ligerisimo
    int f;
    if(memo[n] == n){
        return memo[n]; //res final
    }
    else if(n<=2){
        f=1;
    }else{
        f=fibDinamico(n-1, memo) + fibDinamico(n-2, memo);
    }
    memo[n]=f;
    return f; //cierra ramita de recursv
}

int fibBottomUp(int n, vector<int> fiboArreglo){ //ligerisimo
    int f;
    for(int k=1;k<=n;k++){
        if(k<=2)
            f=1;
        else
            f=fibBottomUp(k-1, fiboArreglo)+fibBottomUp(k-2, fiboArreglo);
        fiboArreglo[k]=f;//cierra ramita de recursv
    }
    return fiboArreglo[n]; //res final
}

int fib(int n){ //pesado, divide y venceras
    if(n==1 || n==2){
        return 1;
    }else{
        return fib(n-1) + fib(n-2);
    }
}

int main()
{
    int n;
    cin>>n;
    cout<<"Resultado de Fibo normal: "<<fib(n)<<endl;

    //int * memo;
    //memo = new int[n];
    //for(int i=0;i<n;i++){memo[i]=-1;}
    vector<int> memo(n,-1);
    cout<<"Resultado de Fibo Dianmico: "<<fibDinamico(n, memo)<<endl;

    vector<int> fiboArreglo(n,0);
    cout<<"Resultado de Fibo BottomUp: "<<fibBottomUp(n, fiboArreglo)<<endl;
    
    return 0;
}
