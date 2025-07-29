#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/critical-connections-in-a-network/description/

// A critical edge is an edge in an undirected graph, such that if you remove it, the graph breaks into 2 or more components.
// It aslo called as Bridge
// To find Bridges we have to use Tarjan's Algorithm

// disCoveryTime[u] --> Time when node u is first visited.
// low [u] --> Lowest possible disover time node where we can reach from node u 

void dfs(int node, int parent, int &time, vector<vector<int>> &adjList, vector<int> &DisoveryTime, vector<int> &low,
    vector<vector<int>> &bridges)
{
    DisoveryTime[node] = low[node] = time;
    time++;

    for (int neigh : adjList[node])
    {
        if (neigh == parent)
            continue;

        if (DisoveryTime[neigh] == -1)
        {
            // not yet vistied

            dfs(neigh, node, time, adjList, DisoveryTime, low, bridges);
            low[node] = min(low[node], low[neigh]); // update lowest discover time if neighbor node have found

            // Bridge/Critical Edge
            if (low[neigh] > DisoveryTime[node])
            {
                bridges.push_back({node, neigh});
            }
        }
        else
        {
            // alredy visited, have back edge
            low[node] = min(low[node], DisoveryTime[neigh]);
        }
    }
}

// Using Tarjen's Algorithm..

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{

    vector<vector<int>> adjList(n);
    for (auto connection : connections)
    {
        int u = connection[0], v = connection[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // disCoveryTime[u] --> Time when node u is first visited.
    // low [u] --> Lowest possible node v disover time where we can reach from node u 
    vector<int> DisoveryTime(n, -1);
    vector<int> low(n, -1);

    vector<vector<int>> bridges;
    int time = 0;
    for (int i = 0; i < n; i++)
    {
        if (DisoveryTime[i] == -1)
            dfs(i, -1, time, adjList, DisoveryTime, low, bridges);
    }

    return bridges;
}
int main()
{
    return 0;
}