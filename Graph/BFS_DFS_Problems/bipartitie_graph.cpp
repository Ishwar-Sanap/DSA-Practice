#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool bfs(int source, vector<vector<int>> &graph, vector<int> &colored)
    {
        queue<int> qNodes;
        qNodes.push(source);
        colored[source] = 0; // starting with color 0

        while (!qNodes.empty())
        {
            int node = qNodes.front();
            int color = colored[node];
            qNodes.pop();

            // Explore all adjacent neighbors
            for (int nei : graph[node])
            {
                // Not colored yet
                if (colored[nei] == -1)
                {
                    // give opposite color than it's adjacent node
                    qNodes.push(nei);
                    int newColor = !color; // opposite color
                    colored[nei] = newColor;
                }
                else
                {
                    // adjacent nodes having same color
                    if (colored[nei] == color)
                        return false;
                }
            }
        }

        return true;
    }

    bool dfs(int source, int color, vector<vector<int>> &graph, vector<int> &colored)
    {
        colored[source] = color;

        // Explore all neighbors
        for (int nei : graph[source])
        {
            if (colored[nei] == -1)
            {
                int newColor = !color; // opposite color
                bool retVal = dfs(nei, newColor, graph, colored);
                if (retVal == false)
                    return false;
            }
            else
            {
                if (colored[nei] == color)
                    return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {

        // Bipartite means: If we can colored all nodes using 2 colors and not any adjacent node
        //  having the same color then, it Bipartite graph

        // If graph don't have cycle or Cycle length is Even then it's Bipartite
        // If any Cycle length in grpah is odd then it's not bipartite..

        int n = graph.size();

        // using 2 colors 0 and 1
        vector<int> colored(n, -1); // Initially not any node is colored

        // Consider all source nodes
        for (int i = 0; i < n; i++)
        {
            if (colored[i] == -1 && bfs(i, graph, colored) == false)
                return false;
        }

        return true;
    }
};
int main()
{
    return 0;
}