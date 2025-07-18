#include <bits/stdc++.h>
using namespace std;

/*
T.C --> O(E log V) , E --> no of edges , V --> no fo vertices
S.C --> O(E+V)
*/

// https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
// Dijkstra’s Algorithm is a greedy algorithm used to find the shortest path from a source node to all other nodes
//  in a weighted graph with non-negative edge weights.

// Using Priority Queue min heap
vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
{

    // Step1 : Created adjacency list
    vector<vector<pair<int, int>>> adjList(V, vector<pair<int, int>>());
    for (auto &edge : edges)
    {
        int u = edge[0], v = edge[1], wt = edge[2];
        adjList[u].push_back({v, wt});
        adjList[v].push_back({u, wt}); // undirected graph..
    }

    // Step2 : Create the Min heap of distance and nodes, to travese {distFromSrc, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Step3 : Create the distance array to find the shortest dist from source to others
    vector<int> dist(V, 1e6); // Initialized with large value

    // step4 : Intialize the source : {distFromSrc, node}
    pq.push({0, src});
    dist[src] = 0;

    // Step5 : Traverse the pq nodes
    while (!pq.empty())
    {
        // min distance will be always on top PQ
        int currNodedist = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();

        for (auto &it : adjList[currNode])
        {
            int adjNode = it.first;
            int adjNodeEdgeWt = it.second;

            // Updating the min distance to reach adjacent nodes
            if ((currNodedist + adjNodeEdgeWt) < dist[adjNode])
            {
            
                dist[adjNode] = (currNodedist + adjNodeEdgeWt);
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

// Approach2 Using set Same Time complexity

// The only difference between using a Priority Queue and a Set is that in a set we can check
//  if there exists a pair with the same node but a greater distance than the current inserted node
//  as there will be no point in keeping that node into the set if we come across a much better value
//  than that. So, we simply delete the element with a greater distance value for the same node.
vector<int> dijkstra2(int V, vector<vector<int>> &edges, int src)
{

    // Step1 : Created adjacency list
    vector<vector<pair<int, int>>> adjList(V, vector<pair<int, int>>());
    for (auto &edge : edges)
    {
        int u = edge[0], v = edge[1], wt = edge[2];
        adjList[u].push_back({v, wt});
        adjList[v].push_back({u, wt}); // undirected graph..
    }

    // Step2 : Create the ordereded set of distance and nodes, to travese {distFromSrc, node}
    set<pair<int, int>> st;

    // Step3 : Create the distance array to find the shortest dist from source to others
    vector<int> dist(V, 1e6); // Initialized with large value

    // step4 : Intialize the source : {distFromSrc, node}
    st.insert({0, src});
    dist[src] = 0;

    // Step5 : Traverse the set
    while (!st.empty())
    {
        // min distance from source till currNode will be always be first element of set
        int currNodedist = st.begin()->first;
        int currNode = st.begin()->second;

        st.erase({currNodedist, currNode});

        for (auto &it : adjList[currNode])
        {
            int adjNode = it.first;
            int adjNodeEdgeWt = it.second;

            // Updating the min distance to reach adjacent nodes
            if ((currNodedist + adjNodeEdgeWt) < dist[adjNode])
            {
                // that means node is already explored by some other path with large dist
                if (dist[adjNode] != 1e6)
                {
                    // erase that path from set, since that will no longer requied as we now got smaller dist to reach that node
                    st.erase({dist[adjNode], adjNode});
                }

                dist[adjNode] = (currNodedist + adjNodeEdgeWt);

                st.insert({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

int main()
{
    return 0;
}