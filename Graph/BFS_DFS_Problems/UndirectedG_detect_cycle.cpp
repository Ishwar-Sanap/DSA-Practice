#include <bits/stdc++.h>
using namespace std;

/*
Given an undirected graph with V vertices and E edges,
represented as a 2D vector edges[][], where each entry edges[i] = [u, v]
denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.

https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
*/
class Solution
{
public:
    bool bfs(int node, vector<vector<int>> &adjList, vector<int> &visited)
    {
        queue<int> qNodes;
        qNodes.push(node);
        visited[node] = 1;

        while (!qNodes.empty())
        {
            int curr = qNodes.front();
            qNodes.pop();

            int cnt = 0;
            for (int neighbors : adjList[curr])
            {
                if (!visited[neighbors])
                {
                    qNodes.push(neighbors);
                    visited[neighbors] = 1;
                }
                else
                    cnt++; // to find how many times, the neighor is alredy visited
            }

            if (cnt > 1)
                return true; // Cycle is exist
        }

        return false;
    }
    bool dfs(int node, int parent, vector<vector<int>> &adjList, vector<int> &visited)
    {
        visited[node] = 1;

        for (int neighbors : adjList[node])
        {
            if (!visited[neighbors])
            {
                bool retVal = dfs(neighbors, node, adjList, visited);
                if (retVal == true)
                    return true; // cycle found then don't go for further calls...
            }

            else
            {
                //Already visited, but it's not parent
                if (neighbors != parent)
                    return true; // In path, Cycle found
            }
        }

        return false;
    }
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        // Code here

        vector<vector<int>> adjList(V, vector<int>());
        vector<int> visited(V, 0);

        // Constructing the Adjacency List
        for (auto edge : edges)
        {
            int u = edge[0], v = edge[1];

            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        // we have to try for all source nodes, sice in graph Component's may exist..
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                // if (bfs(i, adjList, visited))
                if (dfs(i, -1, adjList, visited))
                    return true;
            }
        }

        return false;
    }
};
int main()
{
    return 0;
}