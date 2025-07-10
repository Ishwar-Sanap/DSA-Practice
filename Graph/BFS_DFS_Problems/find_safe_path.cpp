#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/find-eventual-safe-states/description/

bool dfs(int source, vector<vector<int>> &graph, vector<int> &visited, vector<int> &pathVisited)
{
    visited[source] = 1;
    pathVisited[source] = 1;

    for (int nei : graph[source])
    {
        if (!visited[nei])
        {
            bool ret = dfs(nei, graph, visited, pathVisited);
            if (ret)
                return true;
            pathVisited[nei] = 0; // backtrack
        }
        else if (pathVisited[nei] == 1)
            return true;
    }

    pathVisited[source] = 0;
    return false;
}
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{

    int n = graph.size();
    vector<int> visited(n, 0);
    vector<int> pathVisited(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, graph, visited, pathVisited);
        }
    }

    // ALL nodes that are part of cycle are marked as pathVisted
    // so they never be the safe nodes..

    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (pathVisited[i] == 0)
            ans.push_back(i);
    }

    return ans;
}
int main()
{
    return 0;
}