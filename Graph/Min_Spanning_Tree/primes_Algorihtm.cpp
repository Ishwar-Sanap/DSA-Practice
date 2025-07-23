#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

class Solution
{
public:
    typedef pair<int, int> pii;

//To find the MST of given graph we will use the Prim's Algorithm
//T.C--> O(E*logE) S.C -->O(E+V)
    int MinimumSpanningTree(int V, vector<vector<int>> adj[])
    {

        /*
        adj[0] = {{1, 5}, {2, 1}}  // 0 is connected to 1 (w=5), and 2 (w=1)
        adj[1] = {{0, 5}, {2, 3}}  // 1 is connected to 0 (w=5), and 2 (w=3)
        adj[2] = {{1, 3}, {0, 1}}  // 2 is connected to 1 (w=3), and 0 (w=1)  this is what adjacency list look like
        */

        vector<int> visited(V, 0);
        priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<>> pq;

        //{dist, {node, parentNode}}
        pq.push({0, {0, -1}});

        int mstSum = 0;

        // Storing the MST of given graph..
        vector<vector<int>> mstEdges;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int edgeWt = it.first;
            int currNode = it.second.first;
            int parentNode = it.second.second; // parent node only used to store the MST edges if asked

            if (visited[currNode] == 1)
                continue; // don't go for exploration

            visited[currNode] = 1;

            mstSum += edgeWt; // adding the edge weights

            if (parentNode != -1)
                mstEdges.push_back({currNode, parentNode, edgeWt});

            // Explore it's adjacent neighbors
            for (auto neigh : adj[currNode])
            {
                int node = neigh[0];
                int wt = neigh[1];

                if (!visited[node])
                {
                    pq.push({wt, {node, currNode}});
                }
            }
        }

        // printing the edges of MST
        for (auto edge : mstEdges)
            cout << edge[0] << " " << edge[1] << " " << edge[2] << endl;

        return mstSum;
    }
};
int main()
{

    return 0;
}