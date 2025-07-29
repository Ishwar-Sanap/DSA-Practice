#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/description/

void dfs(int src, vector<vector<int>> &adjList, vector<int> &visited)
{
    visited[src] = 1;

    for (int neigh : adjList[src])
    {
        if (!visited[neigh])
            dfs(neigh, adjList, visited);
    }
}

// Approach 1 using DFS : counting the number of connected components
// T.C --> O(n^2) , S.C --> O(n^2)
int removeStones(vector<vector<int>> &stones)
{
    //[x, y]  consider that stone position as sinlge node
    // if any [xi, yi] are 2 nodes [xj, yj] and (xi == xj sharing same row)
    // or same column (yi == yj) then we can form the undirected edge between them

    int n = stones.size();

    vector<vector<int>> adjList(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (stones[i][0] == stones[j][0] ||
                stones[i][1] == stones[j][1])
            {
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }

    vector<int> visited(n, 0);
    int connectedComponets = 0;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, adjList, visited);
            connectedComponets++;
        }
    }

    // Those stones positions share the same or same column are grouped together into single componet
    // so we can remove all possible nodes except 1 (since, 1 node must be in componet as per problem statemnet)

    // suppose size of componets are s1, s2, s3 we can remove (size -1 ) from all componets
    // (s1 - 1) + (s2 -1) + (s3 - 1) .
    // (s1+ s2 + s3 ) - (1 + 1 + 1 )
    // (n - 3)
    // n - (numberOfConnectedComponetns) // n is number of nodes in graph

    return n - connectedComponets;
}

// Appraoch 2 -->  Optimized using DSU
// T.C (n)
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

int removeStones2(vector<vector<int>> &stones)
{
    int maxRow = 0, maxCol = 0;

    for (auto &it : stones)
    {
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }

    int n = stones.size();

    unordered_set<int> uniqeNdoes;
    DisjointSet ds(maxRow + maxCol + 1);

    for (auto &stone : stones)
    {
        int u = stone[0], v = stone[1] + maxRow + 1;
        ds.unionBysize(u, v); // form the edge

        uniqeNdoes.insert(u);
        uniqeNdoes.insert(v);
    }

    int connectedComponets = 0;
    for(int node : uniqeNdoes)
    {
        if(ds.findUltimateParent(node) == node)
            connectedComponets++;

    }

    return n - connectedComponets;

}
int main()
{
    return 0;
}