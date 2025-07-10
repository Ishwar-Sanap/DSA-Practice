#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

bool dfs(int source, vector<vector<int>> &adjList, vector<int> &visited, vector<int> &pathVisied)
{
    visited[source] = 1;
    pathVisied[source] = 1;

    // Explore neighbors
    for (int neigh : adjList[source])
    {
        if (!visited[neigh])
        {
            bool retVal = dfs(neigh, adjList, visited, pathVisied);
            // bactrack the path
            pathVisied[neigh] = 0;

            if (retVal == true)
                return true;
        }
        else
        {
            // adjacent neigbor is alredy visited,but
            // if it's in same path cycle then exist
            if (pathVisied[neigh] == 1)
                return true;
        }
    }

    pathVisied[source] = 0;

    return false;
}
bool isCyclic(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adjList(V, vector<int>());
    vector<int> visited(V, 0);
    vector<int> pathVisited(V, 0);
    for (auto edge : edges)
    {
        int u = edge[0], v = edge[1];
        adjList[u].push_back(v); // one direction only
    }

    for (int i = 0; i < V; i++)
    {

        if (dfs(i, adjList, visited, pathVisited) == true)
            return true;
    }

    return false;
}
int main()
{
    return 0;
}