#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/network-delay-time/

class Solution
{
public:
    typedef pair<int, int> pii;
    //T.C --> O(ElogV)
    //S.C --> O(V + E)
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {

        // Using Dijkstra algorithm to find the shortes path dist
        // to reach all nodes from given source node k

        // Create the adjacency list
        vector<vector<pii>> adjList(n + 1, vector<pii>());

        for (auto &time : times)
        {
            int u = time[0], v = time[1], w = time[2];
            adjList[u].push_back({v, w});
        }

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(n + 1, 1e9);

        //{dist, src}
        pq.push({0, k});
        dist[k] = 0;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int currNode = it.second;
            int currDist = it.first;

            for (auto neigh : adjList[currNode])
            {
                int adjNode = neigh.first;
                int adjNodeDist = neigh.second;

                if ((currDist + adjNodeDist) < dist[adjNode])
                {
                    dist[adjNode] = (currDist + adjNodeDist);
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int minTime = -1;
        for (int i = 1; i <= n; i++)
        {
            // if we can't reach to ith node return -1
            if (dist[i] == 1e9)
                return -1;

            //All min distacne to reach i from src node store in dist array, we just need to reaturn max value from it
            // max value indicates that, min time must required to send signal to all nodes..
            minTime = max(minTime, dist[i]);
        }

        return minTime;
    }
};

int main()
{
    return 0;
}