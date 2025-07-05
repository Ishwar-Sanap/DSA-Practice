#include <bits/stdc++.h>
using namespace std;

/*
Input: adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]
Output: [0, 2, 3, 1, 4]
*/

// T.C O(N) + O(E)
// S.C O(N)
vector<int> bfs(vector<vector<int>> &adj){
    int n = adj.size();
    vector<int> visited(n, 0);
    queue<int> qNodes;

    qNodes.push(0); // since given that, vertex is started from 0
    visited[0] = 1;

    vector<int> ans;
    while (!qNodes.empty())
    {
        int node = qNodes.front();
        qNodes.pop();

        ans.push_back(node);

        // Explore all the neighbours node exists in adjacency list..
        for (int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = 1;
                qNodes.push(neighbor);
            }
        }
    }
    return ans;
}
int main()
{
    return 0;
}