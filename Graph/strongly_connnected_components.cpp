#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

// Using Tarjen's Algorithm T.C O(V+E) Single Traversal  S.C --> 4*(V)
class Solution
{
    vector<int> discoveryTime;
    vector<int> lowsestDiscTime;
    vector<bool> inStack;
    stack<int> stkNodes;
    int timer;
    vector<vector<int>> ans;

public:
    Solution()
    {
        timer = 0;
    }
    void dfs(int src, vector<vector<int>> &adjList)
    {
        discoveryTime[src] = timer;
        lowsestDiscTime[src] = timer;
        timer++;

        stkNodes.push(src);
        inStack[src] = true;

        for (int neigh : adjList[src])
        {
            // not yet visited
            if (discoveryTime[neigh] == -1)
            {
                dfs(neigh, adjList);

                lowsestDiscTime[src] = min(lowsestDiscTime[src], lowsestDiscTime[neigh]);
            }
            else
            {
                // if neighbor is alredy visited and still in stack, means there is back edge else it is cross edge
                if (inStack[neigh] == true) // means there is backEdge
                    lowsestDiscTime[src] = min(lowsestDiscTime[src], discoveryTime[neigh]);
            }
        }

        // when all neighbors are processedd
        //  if discovery time and lowestDiscTime is eqaul then it's the head of SCC
        if (discoveryTime[src] == lowsestDiscTime[src])
        {
            vector<int> strongCompo;
            while (!stkNodes.empty() && stkNodes.top() != src)
            {
                int node = stkNodes.top();
                inStack[node] = false;
                stkNodes.pop();

                strongCompo.push_back(node);
            }

            if (!stkNodes.empty())
            {
                stkNodes.pop(); // poping the src node
                inStack[src] = false;
                strongCompo.push_back(src);

                ans.push_back(strongCompo);
            }
        }
    }
    // Return strongly connected components using Tarjen's algo
    vector<vector<int>> getSCC(vector<vector<int>> &adjList)
    {
        int n = adjList.size();
        discoveryTime.assign(n, -1);
        lowsestDiscTime.assign(n, -1);
        inStack.assign(n, false);

        for (int i = 0; i < n; i++)
        {
            if (discoveryTime[i] == -1)
                dfs(i, adjList);
        }

        return ans;
    }
};

// Using Kosarajus Algorithm
// Note: The sorting of the nodes according to their finishing time is very important.
// By performing this step, we will get to know where we should start our DFS calls.
// The top-most element of the stack will finish last and it will surely belong to the SCC1.

// T.C --> O(V+E) + O(V+E) + O(V+E) ~ O(V+E)  , S.c --> O(V+E)
class Solution2
{
public:
    stack<int> stNodes;

    void dfs(int src, vector<vector<int>> &adjList, vector<bool> &visited)
    {
        visited[src] = true;

        for (int neigh : adjList[src])
        {
            if (!visited[neigh])
                dfs(neigh, adjList, visited);
        }

        // When all neighbors are explored store the node
        stNodes.push(src);
    }
    void dfs2(int src, vector<vector<int>> &adjList, vector<bool> &visited, vector<int> &scCompo)
    {
        visited[src] = true;
        scCompo.push_back(src);

        for (int neigh : adjList[src])
        {
            if (!visited[neigh])
                dfs2(neigh, adjList, visited,scCompo);
        }
    }
    int kosaraju(vector<vector<int>> &adjList)
    {
        int n = adjList.size();
        vector<bool> visited(n, false);

        // Step1 : Perform the DFS and store all nodes based there finishing time, in stack daata structure
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
                dfs(i, adjList, visited);
        }

        // Step2 create another adjList with reversed all the edges,
        // by reversing edge we can't traverse to all connected componets so it helps differtiate those SCC in next step
        // reversing edge doesn't affect on strongly connected componet they remains as it is..
        vector<vector<int>> adjListRev(n);

        for (int i = 0; i < n; i++)
        {
            for (int node : adjList[i])
            {
                adjListRev[node].push_back(i);
            }
        }

        // Step3 count the SCC by traversing through teh nodes in the stack..
        int sccCnt = 0;
        visited.clear();
        visited.assign(n, false);

        vector<vector<int>> ans;
        while (!stNodes.empty())
        {
            int scr = stNodes.top();
            stNodes.pop();

            if (!visited[scr])
            {
                vector<int> scCompo;
                dfs2(scr, adjListRev, visited, scCompo);
                ans.push_back(scCompo);
                sccCnt++;
            }
        }

        // Printing all Strongly connected components
        for (auto it : ans)
        {
            for (int ele : it)
                cout << ele << " ";

            cout << endl;
        }

        // returning the count of Strongly connected componetns
        return sccCnt;
    }
};

int main()
{
    int V = 8;

    // Creating the Directed graph..
    vector<vector<int>> adjList(V);
    adjList[0].push_back(1);
    adjList[1].push_back(2);
    adjList[1].push_back(3);
    adjList[2].push_back(7);
    adjList[3].push_back(4);
    adjList[4].push_back(0);
    adjList[4].push_back(5);
    adjList[4].push_back(6);
    adjList[5].push_back(3);
    adjList[5].push_back(2);
    adjList[5].push_back(6);
    adjList[6].push_back(5);

    Solution2 sobj;
    // vector<vector<int>> scc = sobj.getSCC(adjList);

    cout<< "No of SCC : " << sobj.kosaraju(adjList) << endl;

    // for (auto it : scc)
    // {
    //     for (int ele : it)
    //         cout << ele << " ";

    //     cout << endl;
    // }

    return 0;
}