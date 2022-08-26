#include <iostream>
#include <vector>
using namespace std;

//Jesus Sebastian Jaime Oviedo A01412442
//26 de agosto del 2022 - Algoritmos avanzados

class Actividad{
    private:
        int s;
        int f;
    public:
        Actividad(int ss, int ff){s=ss; f=ff;}
        int getS(){return s;}
        int getF(){return f;}
        void imprime(){cout<<s<< " " <<f;}
};

vector<Actividad> greedyActivitySelector(vector<Actividad> total){
    int n = total.size();

    vector<Actividad> A;
    A.push_back(total[0]); //siempre empezamos por la primera actividad

    int k=0;

    for (int m = 1; m < n; m++) //1=0 hay que indexas
    {
        if (total[m].getS() >= total[k].getF())
        {
            A.push_back(total[m]); //esta es la U nion que pauta
            k=m; //traslada puntero para desarollar
        }
        
    }
    return A;
}

int main()
{
    vector<Actividad> total;
    total.push_back(Actividad(1,4));
    total.push_back(Actividad(3,5));
    total.push_back(Actividad(0,6));
    total.push_back(Actividad(5,7));
    total.push_back(Actividad(3,9));
    total.push_back(Actividad(5,9));
    total.push_back(Actividad(6,10));
    total.push_back(Actividad(8,11));
    total.push_back(Actividad(8,12));
    total.push_back(Actividad(2,14));
    total.push_back(Actividad(12,16));

    //vector<int> s{1,3,0,5,3,5,6,8,8,2,12};
    //vector<int> f{4,5,6,7,9,9,10,11,12,14,16};

    vector<Actividad> acts = greedyActivitySelector(total);

    for(auto i:acts){
        i.imprime();
        cout<<endl;
    }
    
    return 0;
}
