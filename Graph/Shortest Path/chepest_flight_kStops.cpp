#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

typedef pair<int, int> pii;

// Using Modified Dijkstra algorithm T.C O(E Log V)
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<vector<pii>> adjList(n, vector<pii>());

    for (auto it : flights)
    {
        int u = it[0], v = it[1], cost = it[2];
        adjList[u].push_back({v, cost}); // u -> v flight with given cost
    }

    //{cost, {stops, node}}
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;

    pq.push({0, {0, src}});

    // You need to track (node, stops) as separate states, even if the cost is higher..
    vector<vector<int>> dist(n, vector<int>(k + 1, 1e9));
    dist[src][0] = 0;

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        int costSoFar = it.first;
        int currStops = it.second.first;
        int currNode = it.second.second;

        if (currNode == dst)
            return costSoFar;

        // Explore adjacent nodes only when currStops < k
        if (currStops <= k)
        {
            for (auto neigh : adjList[currNode])
            {
                int node = neigh.first, cost = neigh.second;

                if ((costSoFar + cost) < dist[node][currStops])
                {
                    dist[node][currStops] = (costSoFar + cost);
                    pq.push({dist[node][currStops], {currStops + 1, node}});
                }
            }
        }
    }

    return -1;
}

// Approach 2 : T.C O(N)
int findCheapestPrice2(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<vector<pii>> adjList(n, vector<pii>());

    for (auto it : flights)
    {
        int u = it[0], v = it[1], cost = it[2];
        adjList[u].push_back({v, cost}); // u -> v flight with given cost
    }

    vector<int> dist(n, 1e9);

    // performnig BFS using stops .. min stops will be explored first as we
    // incresing stops when we visit node so, at front queue give min. value of stops  no need of priority queue

    // {stops, {node, dist}}
    queue<pair<int, pii>> qNodes;

    qNodes.push({0, {src, 0}});
    dist[src] = 0;

    while (!qNodes.empty())
    {
        auto it = qNodes.front();
        qNodes.pop();

        int currStops = it.first;

        int currNode = it.second.first;
        int costSoFar = it.second.second;

        // Explore adjacent nodes only when currStops <= k
        if (currStops <= k)
        {
            for (auto neigh : adjList[currNode])
            {
                int node = neigh.first, cost = neigh.second;

                if ((costSoFar + cost) < dist[node])
                {
                    dist[node] = (costSoFar + cost);
                    qNodes.push({currStops + 1, {node, dist[node]}});
                }
            }
        }
    }

    // If the destination node is unreachable return ‘-1’
    // else return the calculated dist from src to dst.
    return dist[dst] == 1e9 ? -1 : dist[dst];
}
int main()
{
    return 0;
}