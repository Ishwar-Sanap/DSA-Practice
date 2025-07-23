#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

class Solution
{
public:
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
    int makeConnected(int n, vector<vector<int>> &connections)
    {

        int E = connections.size();

        if (E < n - 1)
            return -1; // not possible to connect
        // since min (n-1) Edges requied to connect all n nodes

        DisjointSet ds(n);

        // Before forming componets all nodes are sepearate and they are individaul components
        // over the time as graph grows that nodes attach to each other and form combine component
        int cntComponents = n;

        // Check how many connected componenta are there
        for (auto con : connections)
        {
            int u = con[0], v = con[1];

            if (ds.findUltimateParent(u) != ds.findUltimateParent(v))
            {
                cntComponents--;
                ds.unionBysize(u, v); //Forming the edge
            }
        }

        // you will requied number components -1 edges to connect all computers
        return cntComponents - 1;
    }
};
int main()
{
    return 0;
}