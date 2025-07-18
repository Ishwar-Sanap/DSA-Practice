#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/

class Solution
{
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>> &roads)
    {

        vector<vector<pair<int, int>>> adjList(n, vector<pair<int, int>>());
        for (auto &edge : roads)
        {
            int u = edge[0], v = edge[1], wt = edge[2];
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt}); // undirected graph..
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

        vector<long long> dist(n, LLONG_MAX); // Initialized with large value
        vector<int> counts(n, 0);

        pq.push({0, 0});
        dist[0] = 0;
        counts[0] = 1;

        // Step5 : Traverse the pq nodes
        while (!pq.empty())
        {
            // min distance will be always on top PQ
            long long currNodedist = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            for (auto &it : adjList[currNode])
            {
                int adjNode = it.first;
                int adjNodeEdgeWt = it.second;

                // Updating the min distance to reach adjacent nodes
                if ((currNodedist + adjNodeEdgeWt) == dist[adjNode])
                {
                    counts[adjNode] = (counts[adjNode] + counts[currNode]) % mod;
                }
                else if ((currNodedist + adjNodeEdgeWt) < dist[adjNode])
                {
                    dist[adjNode] = (currNodedist + adjNodeEdgeWt);

                    counts[adjNode] = counts[currNode];

                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return counts[n - 1];
    }
};
int main()
{
    return 0;
}