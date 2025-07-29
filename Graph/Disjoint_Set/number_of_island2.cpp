#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/problems/number-of-islands/1

// User function Template for C++
class DisjointSet
{
    vector<int> size; // it store the size of component
    vector<int> parent;

public:
    DisjointSet(int n)
    {
        // for considering 1 based node values..
        size.assign(n + 1, 1); // initally the nodes having single component so size 1
        parent.assign(n + 1, 0);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i; // Initializing parent as self node
        }
    }

    // ultimate parent refers to the topmost node or the root node.
    int findUltimateParent(int node)
    {
        // node is the topMost node
        if (parent[node] == node)
            return node;

        // Path Compression :
        // connecting each node in a particular path to its ultimate parent refers to path compression
        return parent[node] = findUltimateParent(parent[node]);
    }

    // add edge between node u and v
    void unionBysize(int u, int v)
    {
        int ultParentU = findUltimateParent(u);
        int ultParentV = findUltimateParent(v);

        // alredy nodes are in same component
        if (ultParentU == ultParentV)
            return;

        // Prefer attaching smaller tree under the root of the larger one
        if (size[ultParentU] < size[ultParentV])
        {
            // attaching ultParentU to the ultParentV
            parent[ultParentU] = ultParentV;

            size[ultParentV] += size[ultParentU]; // root node v size incresed
        }

        else
        {
            // V is smaller than U
            parent[ultParentV] = ultParentU;
            size[ultParentU] += size[ultParentV]; // since we attached v to u, size of root node u is incresed
        }
    }
};
class Solution
{
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators)
    {
        // code here

        // As Island is expanding after each new query, ther might be number of islands incresed
        // or decresed after queries are executed..
        //Dynmic Graph

        DisjointSet ds(n * m + 1);
        vector<int> ans;

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int islandCnt = 0;

        for (auto &op : operators)
        {
            int i = op[0], j = op[1];

            if (!visited[i][j])
            {
                islandCnt++;

                vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                for (auto &dir : dirs)
                {
                    int nri = i + dir[0];
                    int nci = j + dir[1];

                    if (nri >= 0 && nci >= 0 && nri < n && nci < m)
                    {
                         //Converting 2D cell (i, j) into 1D node --> i * m + j 
                         
                        // we can form edge between (i,j) and (nri,nci) node
                        int u = (m * i + j);
                        int v = (m * nri + nci);
                        
                        // If neighbor is also land and belongs to a different component then
                        if (visited[nri][nci] == 1 && ds.findUltimateParent(u) != ds.findUltimateParent(v))
                        {
                            // add the edge
                            ds.unionBysize(u, v);
                            
                            //Island is merged with adjacent island so count decrease..
                            islandCnt--;
                        }
                    }
                }
            }

            ans.push_back(islandCnt);
            visited[i][j] = 1;
        }

        return ans;
    }
};

int main()
{
    return 0;
}