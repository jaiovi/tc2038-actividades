#include <iostream>
#include <vector>

using namespace std;

// there are four nodes in example graph (graph is 1-based)
const int n = 4;
// give appropriate maximum to avoid overflow
const int MAX = 1000000;

// dist[i][j] represents shortest distance to go from i to j
// this matrix can be calculated for any given graph using
// all-pair shortest path algorithms
int dist[n + 1][n + 1] = {
	{ 0, 0, 0, 0, 0 }, { 0, 0, 10, 15, 20 },
	{ 0, 10, 0, 25, 25 }, { 0, 15, 25, 0, 30 },
	{ 0, 20, 25, 30, 0 },
};

// memoization for top down recursion
int memo[n + 1][1 << (n + 1)];


vector<vector<bool> > grafoRuta;
grafoRuta.resize(n+1, std::vector<bool>(n+1, false));

vector<vector<bool> > grafoTemp;
grafoTemp.resize(n+1, std::vector<bool>(n+1, false));

int fun(int i, int mask)
{
	// base case
	// if only ith bit and 1st bit is set in our mask,
	// it implies we have visited all other nodes already
	if (mask == ((1 << i) | 3)){
        grafoTemp[1][i]=true;
		return dist[1][i];
    }
	// memoization
	if (memo[i][mask] != 0)
		return memo[i][mask];

	int res = MAX; // result of this sub-problem

	// we have to travel all nodes j in mask and end the
	// path at ith node so for every node j in mask,
	// recursively calculate cost of travelling all nodes in
	// mask except i and then travel back from node j to
	// node i taking the shortest path take the minimum of
	// all possible j nodes

	for (int j = 1; j <= n; j++){
        grafoTemp[i][j]=true;
		if ((mask & (1 << j)) && j != i && j != 1)
			res = std::min(res, fun(j, mask & (~(1 << i)))
									+ dist[j][i]);
    }
	return memo[i][mask] = res;
}
// Driver program to test above logic
int main()
{
	int ans = MAX;
	for (int i = 1; i <= n; i++){
		// try to go from node 1 visiting all nodes in
		// between to i then return from i taking the
		// shortest route to 1
		if(ans > fun(i, (1 << (n + 1)) - 1)+ dist[i][1]){
            ans=fun(i, (1 << (n + 1)) - 1)+ dist[i][1];
            grafoRuta=grafoTemp;
        }
    }
	printf("The cost of most efficient tour = %d", ans);

	return 0;
}

// This code is contributed by Serjeel Ranjan
