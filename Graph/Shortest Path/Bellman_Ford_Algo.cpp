#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

class Solution
{
public:

//T.C O(V * E)
//S.C (V)

//The bellman-Ford algorithm helps to find the shortest distance from the source node to all other nodes.
// It also works for -ve edge weights..

//Negative Cycle: A cycle is called a negative cycle if the sum of all its weights becomes negative.

    vector<int> bellmanFord(int V, vector<vector<int>> &edges, int src)
    {
        // AS Graph containing the -ve edge weights we have to Relax the all edges V-1 times
        // For detecting the -ve weight cycle, we have to do relaxatation one more time if relaxatation
        // happnes it means ther is -ve weight cycle in graph.

        vector<int> dist(V, 1e8);
        dist[src] = 0;

        // Iterate n-1 times to get the shortes distance
        for (int i = 0; i < V - 1; i++)
        {
            bool flagRelaxed = false;
            for (auto &edge : edges)
            {
                int u = edge[0], v = edge[1], wt = edge[2];

                // perform relaxation only when you have reached to the node u and
                // If the distance to reach v through u(i.e. dist[u] + wt) is smaller than dist[v], 
                // we will update the value of dist[v] with (dist[u] + wt).
                if (dist[u] != 1e8 && (dist[u] + wt) < dist[v])
                {
                    dist[v] = (dist[u] + wt);
                    flagRelaxed = true;
                }

            }
            // Since relaxation is not happen at this iteration
            // so next iteration will also not perform the relaxation
            if (flagRelaxed == false)
                return dist;
        }

        // Iterate one more time to check wheter the -ve edge wt cycle exist??
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1], wt = edge[2];

            // perform relaxation only when you have reached to the node u
            if (dist[u] != 1e8 && (dist[u] + wt) < dist[v])
            {
                dist[v] = (dist[u] + wt);
                return {-1};
            }
        }

        return dist;
    }

    vector<int> bellmanFord_Optimized(int V, vector<vector<int>> &edges, int src)
    {
        // AS Graph containing the -ve edge weights we have to Relax the all edges V-1 times
        // For detecting the -ve weight cycle, we have to do relaxatation one more time if relaxatation
        // happnes it means ther is -ve weight cycle in graph.

        vector<int> dist(V, 1e8);
        dist[src] = 0;

        int iterations = 1;

        while (iterations <= V)
        {
            bool flagRelaxed = false;
            for (auto &edge : edges)
            {
                int u = edge[0], v = edge[1], wt = edge[2];

                // perform relaxation only when you have reached to the node u
                if (dist[u] != 1e8 && (dist[u] + wt) < dist[v])
                {
                    dist[v] = (dist[u] + wt);
                    flagRelaxed = true;
                }
            }
            // Since relaxation is not happen at this iteration
            // so next iteration will also not perform the relaxation
            if (flagRelaxed == false)
                return dist; // return the shortest dist from src to all other rechable nodes..

            iterations++;
        }

        // Contains the -ve edge wt cycle, since in iterations edge relaxation happens.
        return {-1};
    }
};

int main()
{
    return 0;
}