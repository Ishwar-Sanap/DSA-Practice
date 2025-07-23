#include <bits/stdc++.h>
using namespace std;

// It uses the Disjoint set data structure to find the MST
//https://www.geeksforgeeks.org/problems/minimum-spanning-tree-kruskals-algorithm/1

class DisjointSet
{
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n)
    {
        parent.assign(n + 1, 0);
        size.assign(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUltimateParent(int node)
    {
        if (node == parent[node])
            return parent[node];

        // Path compression
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBysize(int u, int v)
    {
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);

        if (pu == pv)
            return; // belong to same components

        // Attaching smaller size component to larger
        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu]; // size incres of larger component
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv]; // size incres of larger component
        }
    }
};

//Time Complexity: O(E * log E) 
//Space Complexit : O(E+V)
int kruskalsMST(int V, vector<vector<int>> &edges)
{
    // sorting the edges based on Weights in incresing order
    sort(edges.begin(), edges.end(), [](auto &ele1, auto &ele2)
         {

        if(ele1[2] <= ele2[2]) 
            return true;

        return false; });

    DisjointSet ds(V);

    int totalSum = 0; // Total sum of weights of the MST

    for (auto &edge : edges)
    {
        int u = edge[0], v = edge[1], wt = edge[2];

        // Not belongs to same component
        if (ds.findUltimateParent(u) != ds.findUltimateParent(v))
        {
            // That mean, edge (u v) is part of MST
            //If you need the MST, the also store edge (u, v) in answer if required
            totalSum += wt;

            // add edge to component
            ds.unionBysize(u, v);
        }
    }

    return totalSum;
}
int main()
{

    return 0;
}