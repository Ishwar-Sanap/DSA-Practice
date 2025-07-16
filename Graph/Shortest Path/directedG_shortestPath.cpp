#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1


// User function Template for C++
class Solution
{
public:
//T.C O(V+E) S.C (V+E)
    void BFS_TopoSort(int src, vector<vector<pair<int, int>>> &adjList, vector<int> &indegree, vector<int> &dist)
    {
        int n = adjList.size();
        queue<int> qNodes;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
                qNodes.push(i); // pushing all nodes having 0 indegreee
        }

        // source node
        dist[src] = 0;

        while (!qNodes.empty())
        {
            int curr = qNodes.front();
            qNodes.pop();

            for (auto &neigh : adjList[curr])
            {
                int v = neigh.first;
                int wt = neigh.second;

                //Edge Relaxation: Ensures shortest paths by updating with minimum possible value from predecessors
                dist[v] = min(dist[v], dist[curr] + wt);

                indegree[v]--;

                if (indegree[v] == 0)
                    qNodes.push(v);
            }
        }
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adjList(V, vector<pair<int, int>>());

        vector<int> indegree(V, 0);
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1], wt = edge[2];
            adjList[u].push_back({v, wt});
            indegree[v]++;
        }

        // As we want to find the shortest path assign path to all nodes as large value
        vector<int> dist(V, 1e6);

        BFS_TopoSort(0, adjList, indegree, dist);

        for (int i = 0; i < V; i++)
        {
            if (dist[i] == 1e6)
                dist[i] = -1; // not able to reach
        }

        return dist;
    }
};

int main()
{
    return 0;
}