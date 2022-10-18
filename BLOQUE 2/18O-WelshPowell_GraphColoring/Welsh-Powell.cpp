#include <iostream>
#include <list>
#include <algorithm>

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

// A class that represents an undirected graph
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // A dynamic array of adjacency lists
public:
    // Constructor and destructor
    Graph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    ~Graph()
    {
        delete [] adj;
    }

    // function to add an edge to graph
    void addEdge(int v, int w);

    // Prints greedy coloring of the vertices
    void greedyColoring();
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected
}

struct vertexDegree
{
    int v;
    int degree;
};

bool compareByDegree(const vertexDegree& x, const vertexDegree& y)
{
    return x.degree > y.degree;
}

// Assigns colors (starting from 0) to all vertices and prints
// the assignment of colors
void Graph::greedyColoring()
{
    int result[V];

    // Initialize remaining V-1 vertices as unassigned
    for (int u = 1; u < V; u++)
        result[u] = -1;  // no color is assigned to u

    // A temporary array to store the available colors. True
    // value of available[cr] would mean that the color cr is
    // assigned to one of its adjacent vertices
    bool available[V];

    for (int cr = 0; cr < V; cr++)
        available[cr] = false;

    vertexDegree arr[V];
    for (int i = 0; i < V; i++)
    {
        arr[i].v = i;
        arr[i].degree = adj[i].size();
    }


    sort(arr, arr+V, compareByDegree);

    cout << "Sorted vertices \n";
    for (int i = 0; i <V; i++)
    {
        cout << arr[i].v << " ";
    }
    cout << "\n";

    // Assign the first color to first vertex in sorted array
    result[arr[0].v]  = 0;


    // Assign colors to remaining V-1 vertices
    for (int x = 1; x < V; x++)
    {
        int u = arr[x].v;

        // Process all adjacent vertices and flag their colors
        // as unavailable
        //list<int>::iterator i;
        int i;
        for (i = adj[u].begin(); i != adj[u].end(); i++)
            if (result[i] != -1)
                available[result[i]] = true;

        // Find the first available color
        int cr;
        for (cr = 0; cr < V; cr++)
            if (available[cr] == false)
                break;

        result[u] = cr; // Assign the found color

        // Reset the values back to false for the next iteration
        for (i = adj[u].begin(); i != adj[u].end(); i++)
            if (result[i] != -1)
                available[result[i]] = false;
    }

    // print the result
    for (int u = 0; u < V; u++)
        cout << "Vertex " << u << " --->  Color "
             << result[u] << endl;
}

// Driver program to test above function
int main(int argc, char *argv[]) { //COMPLEJIDAD GENERAL O(n^2)

    // LECTOR DE TXT
    string file = argv[1];
    ifstream input(file);
    string line = "";

    getline(input, line); //N es el tamano del lado de la matriz grafa
    const int n = stoi(line);

    int idxM = 0;
    int idxN = 0;
    const char delim = ' ';

    int **arr = new int*[n]; //crear matriz
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }
    //int[n][n] arr;

    for (std::string line; getline(input, line);) {

        stringstream ss(line);
        string s;
        while (std::getline(ss, s, delim)) {
        arr[idxM][idxN] = stoi(s);
        idxN++;
        }

        idxM++;
        idxN = 0;
    }


    //SE AÑADE GRFAO
    Graph g1(5);
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        //
        if(arr[j][k]==1){
            std::cout<<j<<" "<<k<<endl;
            g1.addEdge(k,j);
        }
            
      }
    }
    cout << "Coloring of Graph 1 \n";
    g1.greedyColoring();
    

    /*
    Graph g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 2);
    g2.addEdge(1, 4);
    g2.addEdge(2, 4);
    g2.addEdge(4, 3);
    cout << "\nColoring of Graph 2 \n";
    g2.greedyColoring();
    */

    return 0;
} 