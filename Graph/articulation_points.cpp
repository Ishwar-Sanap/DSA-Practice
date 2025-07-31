#include <bits/stdc++.h>
using namespace std;

// Articulation Points are vertices in a graph which, if removed along with their associated edges,
// increase the number of connected components in the graph.

// In an undirected connected graph, a vertex v is an articulation point
// if removing v (and all edges connected to it) makes the graph disconnected
// or increases the number of connected components.

// https://www.geeksforgeeks.org/problems/articulation-point-1/1

//T.C O(V+E)
class Solution
{
public:
    vector<int> disTime;
    vector<int> lowDisTime;
    vector<bool> artiPoints; // articulations points
    int timer = 0;
    void dfs(int src, int parent, vector<int> adj[])
    {
        disTime[src] = lowDisTime[src] = timer;
        timer++;
        int children = 0;
        for (int neigh : adj[src])
        {
            // ignore child to parent edge
            if (neigh == parent)
                continue;

            // if not visited neighbors
            if (disTime[neigh] == -1)
            {
                children++;
                dfs(neigh, src, adj);

                lowDisTime[src] = min(lowDisTime[src], lowDisTime[neigh]);

                // case 1, AP is root node
                if (parent == -1 && children > 1)
                    artiPoints[src] = true;

                // case 2 AP is not root node
                if (parent != -1 && lowDisTime[neigh] >= disTime[src])
                    artiPoints[src] = true;
            }
            else
            {
                // back edge
                lowDisTime[src] = min(lowDisTime[src], disTime[neigh]);
            }
        }
    }
    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        disTime.assign(V, -1);
        lowDisTime.assign(V, -1);
        artiPoints.assign(V, false);

        for (int i = 0; i < V; i++)
        {
            if (disTime[i] == -1)
                dfs(i, -1, adj);
        }

        vector<int> ans;

        for (int i = 0; i < V; i++)
        {
            if (artiPoints[i] == true)
                ans.push_back(i);
        }

        if (ans.size() == 0)
            return {-1};

        return ans;
    }
};

int main()
{
    return 0;
}