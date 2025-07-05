#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/number-of-provinces/description/

// BFS/ DFS on Adjancency matrix
void dfs(int node, vector<vector<int>> &isConnected, vector<int> &visited)
{
    visited[node] = 1;
    int n = isConnected.size();
    for (int j = 0; j < n; j++)
    {
        if (isConnected[node][j] && !visited[j])
        {
            dfs(j, isConnected, visited);
        }
    }
}

void bfs(int node, vector<vector<int>> &isConnected, vector<int> &visited)
{
    int n = isConnected.size();
    queue<int> qNodes;
    visited[node] = 1;
    qNodes.push(node);

    while (!qNodes.empty())
    {
        int currNode = qNodes.front();
        qNodes.pop();

        // Exploring all neighbors of currNode
        for (int j = 0; j < n; j++)
        {
            if (isConnected[currNode][j] && !visited[j])
            {
                qNodes.push(j);
                visited[j] = 1;
            }
        }
    }
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    int cnt = 0, n = isConnected.size();

    vector<int> visited(n, 0);

    //For simpliciy you can convert the adjacency matrix to adjacency list
    // and apply BFS/DFS on adj list

    // vector<vector<int>> adjList( n, vector<int>());

    // for(int i = 0; i<n; i++)
    // {
    //     for(int j = 0; j<n ;j ++)
    //     {
    //         if(isConnected[i][j] && i != j)
    //         {
    //             adjList[i].push_back(j);
    //        
    //         }
    //     }
    // }


    // starting source node can be any one so try all source
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cnt++;
            // dfs(i,isConnected,visited);
            bfs(i, isConnected, visited);
        }
    }

    return cnt;
}
int main()
{
    return 0;
}