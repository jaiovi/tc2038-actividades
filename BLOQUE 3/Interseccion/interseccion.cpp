#include <iostream>
#include <utility>
#include <vector>

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

int directionSeg(pair<int, int> pi,pair<int, int> pj,pair<int, int> pk){
    int px1 = pk.first - pi.first;
    int py1 = pk.second - pi.second;
    int px2 = pk.first - pj.first;
    int py2 = pk.second - pj.second;
    pair<int, int> a (px1, py1);
    pair<int, int> b (px2, py2);
    return ( (a.first * b.second) - (b.first * a.second) );
}

bool onSegment(pair<int, int> pi,pair<int, int> pj,pair<int, int> pk){
    int minX = min(pi.first, pj.first);
    int maxX = max(pi.first, pj.first);
    int minY = min(pi.second, pj.second);
    int maxY = max(pi.second, pj.second);
    //cout<<minX<<" "<<maxX<<" - "<<minY<<" "<<maxY<<" ---- "<<pk.first<<" "<<pk.second<<endl;
    if( ( minX < pk.first && pk.first< minY) && ( minY < pk.second && pk.second < maxY ))
        return true;
    else
        return false;
}

bool segmentsIntersect(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3, pair<int, int> p4){
    int d1=directionSeg(p3,p4,p1);
    int d2=directionSeg(p3,p4,p2);
    int d3=directionSeg(p1,p2,p3);
    int d4=directionSeg(p1,p2,p4);
    if( ((d1>0 && d2<0) || (d1<0 && d2>0))  &&  ((d3>0 && d4<0) || (d3<0 && d4>0)) ){
        //cout<<"caso 1"<<endl;
        return true;
    }else if(d1==0 && onSegment(p3,p4,p1)){
        return true;
    }else if(d2==0 && onSegment(p3,p4,p2)){
        return true;
    }else if(d3==0 && onSegment(p1,p2,p3)){
        return true;
    }else if(d4==0 && onSegment(p1,p2,p4)){
        return true;
    }else{
        //cout<<"caso 3"<<endl;
        return false;
    }
}

/*
    pair<int,int> a1 (1 , 1);
    pair<int,int> a2 (5,4);
    pair<int,int> b1 (5,8);
    pair<int,int> b2 (7,5);
    cout<<segmentsIntersect(a1,a2,b1,b2)<<endl;
*/

// 4 CASOS PRUEBA, solo permite subir cpp al entregable https://drive.google.com/drive/folders/1nKzVtHinwcGFXDlNec2TNmZNZDpBrNvC?usp=sharing

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
        arr[i] = new int[4];
    }
    vector< pair<int,int> > listado;

    for (std::string line; getline(input, line);) {

        stringstream ss(line);
        string s;
        while (std::getline(ss, s, delim)) {
        arr[idxM][idxN] = stoi(s);
        idxN++;
        }
        pair<int,int> a(arr[idxM][0],arr[idxM][1]);
        pair<int,int> b(arr[idxM][2],arr[idxM][3]);
        listado.push_back(a);
        listado.push_back(b);
        idxM++;
        idxN = 0;
    }
    
    cout<<"SegmentsIntersect - Jesus Sebastian Jaime Oviedo A01412442 - Algoritmos Avanzados 1 noviembre 2022"<<endl;
    for (int i = 0; i < listado.size(); i += 2)
    {
        for (int j = 0; j < listado.size(); j+=2)
        {
            cout<<segmentsIntersect(listado[i],listado[i+1], listado[j],listado[j+1])<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
  


    return 0;
}
