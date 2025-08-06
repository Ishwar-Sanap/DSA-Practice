#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/minimum-height-trees/?envType=problem-list-v2&envId=graph

class Solution
{
public:
 //Logic is --> going from leaf node toward the center nodes..
    vector<int> bfsTopoSort(vector<vector<int>> &adjList, vector<int> &degree)
    {
        int n = adjList.size();

        queue<int> qNodes;
        for (int i = 0; i < n; i++)
        {
            // it means this is leaf node// start tarversal from leave nodes
            if (degree[i] == 1)
            {
                qNodes.push(i);
            }
        }

        while (n > 2)
        {
            int qSize = qNodes.size();
            // traversing nodes level wise..
            for (int i = 0; i < qSize; i++)
            {
                auto currNode = qNodes.front();
                qNodes.pop();
                n--;
                // Explore the neighbors
                for (int neigh : adjList[currNode])
                {
                    degree[neigh]--;

                    if (degree[neigh] == 1)
                    {
                        qNodes.push(neigh);
                    }
                }
            }
        }

        // Every graph has At most 2 possibles mhts
        vector<int> mhts;
        while (!qNodes.empty())
        {
            mhts.push_back(qNodes.front());
            qNodes.pop();
        }
        return mhts;
    }

    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {

        if (n == 1)
            return {0};
        vector<int> degree(n, 0);
        vector<vector<int>> adjList(n);


        for (auto edge : edges)
        {
            int u = edge[0], v = edge[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }

        return bfsTopoSort(adjList, degree);
    }
};
int main()
{
    return 0;
}