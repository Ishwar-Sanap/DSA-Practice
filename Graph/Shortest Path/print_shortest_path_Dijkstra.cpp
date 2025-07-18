#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1

typedef pair<int, int> pii;

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    vector<vector<pii>> adjList(n + 1, vector<pii>());

    for (auto &edge : edges)
    {
        int u = edge[0], v = edge[1], wt = edge[2];

        adjList[u].push_back({v, wt});
        adjList[v].push_back({u, wt});
    }

    // mean heap
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<int> dist(n + 1, 1e9);
    vector<int> parents(n + 1, 0);

    // Initialize the parents for each ith node
    for (int i = 0; i <= n; i++)
        parents[i] = i;

    pq.push({0, 1}); // 1 as source node
    dist[1] = 0;

    while (!pq.empty())
    {
        int currNode = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();

        for (auto &neig : adjList[currNode])
        {
            int adjNode = neig.first, wt = neig.second;

            // Smaller path found to reach adjNode
            if ((currDist + wt) < dist[adjNode])
            {
                dist[adjNode] = (currDist + wt);

                // store the update distance
                pq.push({dist[adjNode], adjNode});

                // since we want to find path , we will store the parent node of each adjNode
                parents[adjNode] = currNode;
            }
        }
    }

    // If we are unable to reach nth node then path not exist
    if (dist[n] == 1e9)
        return {-1};

    // now we will backtrack the path using parents array
    vector<int> path;
    int node = n;
    while (parents[node] != node)
    {
        path.push_back(node);
        node = parents[node];
    }

    // push the src node
    path.push_back(node);

    reverse(path.begin(), path.end());

    return path;
}
int main()
{
    return 0;
}