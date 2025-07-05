
#include <bits/stdc++.h>
using namespace std;

// T.C O(N) + O(E)
// S.C O(N) + O(N) recursive stack space
void traverseKro(int node, vector<vector<int>> &adj, 
    vector<int> &visited, vector<int> &ans)
{
    visited[node] = 1;
    ans.push_back(node);

    // traverse the all neighbors
    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            traverseKro(neighbor, adj, visited, ans);
        }
    }
}
vector<int> dfs(vector<vector<int>> &adj)
{
    // Code here
    int n = adj.size();
    vector<int> visited(n, 0);
    vector<int> ans;
    // start from 0th node
    traverseKro(0, adj, visited, ans);
    return ans;
}

int main()
{
    return 0;
}