#include <bits/stdc++.h>
using namespace std;

/*
You are given an adjacency list, adj of Undirected Graph having unit weight of the edges, 
find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, 
then return -1 for that vertex.

https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1

*/

class Solution
{
public:
    // Function to find the shortest path from source to all other nodes
    void bfs(int src, vector<vector<int>> &adj, vector<int> &visited, vector<int> &res)
    {

        queue<pair<int, int>> qNodes;
        qNodes.push({src, 0});
        visited[src] = 1;

        while (!qNodes.empty())
        {
            int curr = qNodes.front().first;
            int steps = qNodes.front().second;
            res[curr] = steps;

            qNodes.pop();

            for (auto &neigh : adj[curr])
            {
                if (!visited[neigh])
                {
                    qNodes.push({neigh, steps + 1});
                    visited[neigh] = 1;
                }
            }
        }
    }
    vector<int> shortestPath(vector<vector<int>> &adj, int src)
    {
        // code here

        int n = adj.size();

        vector<int> visited(n, 0);
        vector<int> res(n, -1);

        bfs(src, adj, visited, res);

        return res;
    }
};
int main()
{
    return 0;
}