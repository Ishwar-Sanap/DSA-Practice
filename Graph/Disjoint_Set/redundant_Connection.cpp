#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/redundant-connection/?envType=problem-list-v2&envId=graph

class DSU
{

public:
    vector<int> parent;
    vector<int> size;

    DSU(int n)
    {
        parent.assign(n + 1, 0);
        size.assign(n + 1, 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUltimateParent(int node)
    {
        if (parent[node] == node)
            return node;

        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int pu = findUltimateParent(u);
        int pv = findUltimateParent(v);

        if (pu == pv)
            return;

        // attaching smaller component to larger one
        if (size[pv] <= size[pu])
        {
            parent[pv] = parent[pu];
            size[pu] += size[pv];
        }
        else
        {
            parent[pu] = parent[pv];
            size[pv] += size[pu];
        }
    }
};


vector<int> findRedundantConnection(vector<vector<int>> &edges)
{
    int n = edges.size();

    DSU ds(n);
    vector<int> ans(2, 0);
    for (auto edge : edges)
    {
        int u = edge[0], v = edge[1];

        // edge u - v forming the cycle
        if (ds.findUltimateParent(u) == ds.findUltimateParent(v))
        {
            ans[0] = u;
            ans[1] = v;
        }

        ds.unionBySize(u, v);
    }

    return ans;
}
int main()
{
    return 0;
}