// CPP program to implement traveling salesman
// problem using naive approach.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define V 4

// implementation of traveling Salesman Problem
int travllingSalesmanProblem(int graph[][V], int s)
{
	// store all vertex apart from source vertex
	vector<int> vertex;

    vector<vector<bool> > grafoRuta;
    grafoRuta.resize(V, std::vector<bool>(V, false));

	for (int i = 0; i < V; i++)
		if (i != s)
			vertex.push_back(i);

	// store minimum weight Hamiltonian Cycle.
	int min_path = INT_MAX;
	do {
		// store current Path weight(cost)
        vector<vector<bool> > grafoTemp;
        grafoTemp.resize(V, std::vector<bool>(V, false));
		int current_pathweight = 0;

		// compute current path weight
		int k = s;
        int ejeX, ejeY;
		for (int i = 0; i < vertex.size(); i++) {
			current_pathweight += graph[k][vertex[i]];
            ejeX=k;
            cout<<" - "<<k+1;
            //busca el siguiente
			k = vertex[i];
            //
            cout<<" "<<k+1;
            ejeY=k;
            grafoTemp[ejeX][ejeY]=true;
		}
        grafoTemp[ejeY][s]=true;
        cout<<endl;
		current_pathweight += graph[k][s];
        
        int mp2 = min_path;// guarda al menor
		min_path = min(min_path, current_pathweight);
        
        if(mp2!=min_path)
            grafoRuta=grafoTemp;//cout<<"true "<<min_path<<endl;

	} while (
		next_permutation(vertex.begin(), vertex.end())); //procedimiento que reordena los vertices (considera que entre todos esten conectados, osea Hamilton cycle)

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout<<grafoRuta[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
	return min_path;
}

// Driver Code
int main()
{
	// matrix representation of graph
	int graph[][V] = { { 0, 10, 15, 20 },
					{ 10, 0, 35, 25 },
					{ 15, 35, 0, 30 },
					{ 20, 25, 30, 0 } };
	int s = 0;
	cout << travllingSalesmanProblem(graph, s) << endl;
	return 0;
}
