#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
class Solution
{
public:
    vector<int> getShortestPath_Dijkstra(int src, vector<vector<pair<int, int>>> &adjList)
    {
        int n = adjList.size();
        vector<int> dist(n, 1e8); // shortest dist, from source to all other nodes..

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> qNodes;
        qNodes.push({0, src});
        dist[src] = 0;

        while (!qNodes.empty())
        {
            int currDist = qNodes.top().first;
            int currNode = qNodes.top().second;
            qNodes.pop();

            for (auto neigh : adjList[currNode])
            {
                int adjNode = neigh.first;
                int wt = neigh.second;

                if ((currDist + wt) < dist[adjNode])
                {
                    dist[adjNode] = (currDist + wt);
                    qNodes.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {

        vector<vector<pair<int, int>>> adjList(n, vector<pair<int, int>>());

        for (auto &it : edges)
        {
            int u = it[0], v = it[1], wt = it[2];
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }

        int cityNo = 0, reachableCities = INT_MAX;

        // Try to find the shortes path distance from each source node to other nodes
        for (int i = 0; i < n; i++)
        {
            vector<int> dist = getShortestPath_Dijkstra(i, adjList);

            // from this dist array, count how many city distances are within threshold for ith city
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (dist[j] <= distanceThreshold)
                    cnt++;
            }

            // Finding smallest number of cities that are reachable
            if (cnt <= reachableCities)
            {
                reachableCities = cnt;
                cityNo = i;
            }
        }
        return cityNo;
    }
};

int main()
{
    return 0;
}