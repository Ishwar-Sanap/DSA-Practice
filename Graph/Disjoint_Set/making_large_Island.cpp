#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/making-a-large-island/

class DSU
{
public:
    vector<int> parent, size;

    DSU(int n)
    {
        parent.assign(n + 1, 0);
        size.assign(n + 1, 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUltimateParent(int node)
    {
        if (parent[node] == node)
            return node;

        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            // attach u to v
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            // attach v to u
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    bool isValid(int i, int j, vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();

        if (i >= 0 && j >= 0 && i < n && j < m)
            return true;

        return false;
    }
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();

        DSU ds(n * m + 1);

        int maxSizeIsland = 0;

        // Step1 : creating the graph components
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 0)
                    continue;

                vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

                for (auto &dir : dirs)
                {
                    int nri = i + dir[0];
                    int nci = j + dir[1];

                    if (isValid(nri, nci, grid) && grid[nri][nci] == 1)
                    {
                        // Converting 2D cell (i, j) into 1D node --> i * m + j

                        // we can form edge between (i,j) and (nri,nci) node

                        int u = (m * i + j);
                        int v = (m * nri + nci);

                        ds.unionBySize(u, v);
                    }
                }
            }
        }

        // Step2 : Changing the any one of the 0 to 1 for making larger island (component)
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    continue;

                vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

                // From 4 direction components sizes can possibly added together..
                //  but make sure to add unique componets only
                unordered_set<int> components;
                for (auto &dir : dirs)
                {
                    int nri = i + dir[0];
                    int nci = j + dir[1];

                    if (isValid(nri, nci, grid) && grid[nri][nci] == 1)
                    {
                        int adjNode = (m * nri + nci);
                        

                        components.insert(ds.findUltimateParent(adjNode));
                    }
                }

                // add adjacent component size
                int adjComponentSize = 0;
                for (auto &node : components)
                {
                    adjComponentSize += ds.size[node];
                }

                // 1 is added for flipping 0 to 1 so 1 node get's added
                maxSizeIsland = max(maxSizeIsland, adjComponentSize + 1);
            }
        }

        return maxSizeIsland == 0 ? (n * m) : maxSizeIsland;
    }
};