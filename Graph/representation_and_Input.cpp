#include <bits/stdc++.h>
using namespace std;

// Ways to store the graph
// 1) Adjacency Matrix
// 2) Adjacency List

//S.C --> O(N*N)
void storeAdjancencyMatrix()
{
    // n represenets no of nodes, m  represents no of edges
    int n = 0, m = 0;
    cout << "Enter no of nodes : ";
    cin >> n;
    cout << "Enter no of edges : ";
    cin >> m;
    vector<vector<int>> adjMatrix(n + 1, vector<int>(n + 1, 0)); // (n+1) if nodes are named as 1 based

    for (int i = 0; i < m; i++)
    {
        int u = 0, v = 0;
        cout << "Enter nodes u-->v to connect using edge : ";
        cin >> u >> v;

        adjMatrix[u][v] = 1;

        // If we stroing undirected graph, if there is u-->V edge then V-->u edge is also exist
        adjMatrix[v][u] = 1;
    }

    cout << "-----------------------------------------\n";

    for (auto vt : adjMatrix)
    {
        for (int ele : vt)
            cout << ele << " ";

        cout << endl;
    }
}

// S.C --> O(2*M) // for undirected graph
// s.c --> O(M) // for directed graph
void storeAdjancencyList()
{
    // n represenets no of nodes, m  represents no of edges
    int n = 0, m = 0;
    cout << "Enter no of nodes : ";
    cin >> n;
    cout << "Enter no of edges : ";
    cin >> m;

    // key represents node, and it value is neighbous for that key
    unordered_map<int, vector<int>> adjList;

    // or 
    
    // vector<int> adj[n+1];  // array of vectors
    //vector<vector<int>>adj(n+1, vector<int>());
    /*
    vector<vector<int>>adjlist(n+1, vector<int>());
    adjlist[0].push_back(1);
    adjlist[0].push_back(2);
    adjlist[0].push_back(3);

    */

    for (int i = 0; i < m; i++)
    {
        int u = 0, v = 0;
        cout << "Enter nodes u-->v to connect using edge : ";
        cin >> u >> v;

        adjList[u].push_back(v);

        // If we stroing undirected graph, if there is u-->V edge then V-->u edge is also exist
        adjList[v].push_back(u);
    }

    cout << "-----------------------------------------\n";
    for (auto it : adjList)
    {
        cout << it.first << " -> ";
        for (int i = 0; i < it.second.size(); i++)
        {
            cout << it.second[i] << " ";
        }

        cout << endl;
    }
}
int main()
{
    // storeAdjancencyMatrix();

    storeAdjancencyList();
    return 0;
}