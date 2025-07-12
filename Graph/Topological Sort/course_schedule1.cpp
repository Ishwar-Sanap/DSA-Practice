#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/course-schedule/

//(Kahn's Algorithm..)
void TopoSortBFS(vector<vector<int>> &adjList, vector<int> &topoSort, vector<int> &indegree)
{
    queue<int> qNodes;
    for (int i = 0; i < adjList.size(); i++)
    {
        if (indegree[i] == 0)
            qNodes.push(i); // if indegree 0, then push ndoe into queue
    }

    while (!qNodes.empty())
    {
        int u = qNodes.front();
        qNodes.pop();
        topoSort.push_back(u);

        for (int &v : adjList[u])
        {
            indegree[v]--;

            if (indegree[v] == 0)
                qNodes.push(v);
        }
    }
}
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{

    vector<vector<int>> adjList(numCourses, vector<int>());
    vector<int> indegree(numCourses, 0);

    for (auto it : prerequisites)
    {
        // prerequisites[i] = [ai, bi]
        // as, bi course must take before ai, consider it as edge bi->ai
        // where ai depends on bi
        int a = it[0], b = it[1];
        adjList[b].push_back(a);
        indegree[a]++;
    }

    vector<int> topoSort;
    TopoSortBFS(adjList, topoSort, indegree);

    if (topoSort.size() == numCourses)
        return true;

    // if toposort is not possible then there is cyclic dependancies
    // so all courses can't be completed
    return false;
}
int main()
{
    return 0;
}