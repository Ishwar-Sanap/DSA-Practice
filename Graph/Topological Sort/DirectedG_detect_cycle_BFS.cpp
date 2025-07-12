#include <bits/stdc++.h>
using namespace std;

// Finding Topo sort using BFS--> called (Kahn's Algorithm..)

//TC. O(V + E) V-> number of vertices E-> number of edges

void bfs(vector<vector<int>> &adjList, vector<int> &indegree, vector<int> &ans)
{

    // Those nodes having 0 indegree that can be pushed into queue for further exploration
    //  u -> v  (if indegree of u is zero then it can be added into the Topo sort ordering)
    queue<int> qNodes;

    // Pushed all nodes whose Indegree is 0
    for (int i = 0; i < adjList.size(); i++)
    {
        if (indegree[i] == 0)
        {
            qNodes.push(i);
        }
    }

    while (!qNodes.empty())
    {
        int u = qNodes.front();
        ans.push_back(u); // Indegree 0 elements added into answer
        qNodes.pop();

        for (auto &v : adjList[u])
        {
            indegree[v]--;
            if (indegree[v] == 0)
            {
                qNodes.push(v);
            }
        }
    }
}
bool isCyclic(int V, vector<vector<int>> &edges)
{
    // code here

    vector<vector<int>> adjList(V, vector<int>());
    for (auto edge : edges)
    {
        int u = edge[0], v = edge[1];
        adjList[u].push_back(v);
    }

    // Finding the Indegree of each nodes..
    vector<int> indegree(V, 0);

    for (auto nodes : adjList)
    {
        for (int node : nodes)
            indegree[node]++;
    }

    vector<int> ans;

    bfs(adjList, indegree, ans);

    // that mean Topo sort is possible, then no cycle
    // All nodes are stored in topological sorted array
    if (ans.size() == V)
        return false;

    return true;
}
int main()
{
    return 0;
}