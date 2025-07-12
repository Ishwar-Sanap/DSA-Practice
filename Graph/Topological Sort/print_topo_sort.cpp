#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/topological-sort/1

void dfs(int source, vector<vector<int>> &adjList, vector<int> &visited, stack<int> &st)
{
    visited[source] = 1;

    // Explore neighbors
    for (auto ne : adjList[source])
    {
        if (!visited[ne])
        {
            dfs(ne, adjList, visited, st);
        }
    }

    // When all neighbors are explore then add into answer
    st.push(source);
}

// Finding Topo sort using BFS--> called (Kahn's Algorithm..)
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
vector<int> topoSortDFS(int V, vector<vector<int>> &edges)
{
    vector<vector<int>> adjList(V, vector<int>());
    vector<int> visited(V, 0);
    stack<int> st;

    for (auto edge : edges)
    {
        int u = edge[0], v = edge[1];
        adjList[u].push_back(v);
    }

    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            dfs(i, adjList, visited, st);
    }

    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

vector<int> topoSortBFS(int V, vector<vector<int>> &edges)
{
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

   bfs(adjList,indegree,ans);

   return ans;
}
int main()
{
    return 0;
}