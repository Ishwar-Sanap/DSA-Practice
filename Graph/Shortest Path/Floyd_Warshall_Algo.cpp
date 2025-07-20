#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

//Floyd Warshall algorithm, we need to figure out the shortest distance from each node to every other node.

//It can also work with -ve edge wt and also detect the cycle..
//To detect cycle, check, wheter in dist matrix, dist[i][i] < 0 then ther is -ve Edge cycle

void floydWarshall(vector<vector<int>> &dist)
{
    // Code here
    int n = dist.size();

    // Traverse each i-> j via all n nodes
    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // via path should be explored by someone other..
                if (dist[i][via] != 1e8 && dist[via][j] != 1e8)
                {
                    int currDist = dist[i][via] + dist[via][j];

                    dist[i][j] = min(dist[i][j], currDist);
                }
            }
        }
    }
}
int main()
{
    return 0;
}