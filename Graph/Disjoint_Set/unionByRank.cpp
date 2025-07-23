#include <bits/stdc++.h>
using namespace std;

// Use of Disjoint set Data structure:
/*
Finding the whether the given 2 nodes are part of same components or not??

 we can use either the DFS or BFS traversal technique like if we traverse the components of the graph
 we can find that node 1 and node 5 are not in the same component. This is actually the
 brute force approach whose time complexity is O(N+E)(N = no. of nodes, E = no. of edges).
 But using a Disjoint Set data structure we can solve this same problem in constant time O(1)

*/
/*
Functionalities of Disjoint Set data structure:
The disjoint set data structure generally provides two types of functionalities:

Finding the parent for a particular node (findPar())
Union (in broad terms this method basically adds an edge between two nodes)
- Union by rank
- Union by size
*/

//T.C -->  O(α(n)) --> O(1) 
// where α(n) is the inverse Ackermann function, which grows extremely slowly 
//and is often treated as a constant for practical purposes. 

//S.C --> O(n)
class DisjointSet
{
    vector<int> rank;  // store the rank of nodes
    vector<int> parent; // array that maintain the parent of each nodes

public:
    DisjointSet(int n)
    {
        // for considering 1 based node values..
        rank.assign(n + 1, 0);
        parent.assign(n + 1, 0);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i; //Initializing parent as self node
        }
    }

    // ultimate parent refers to the topmost node or the root node.
    int findUltimateParent(int node)
    {
        // node is the topMost node
        if (parent[node] == node)
            return node;

        // Path Compression :
        // connecting each node in a particular path to its ultimate parent refers to path compression
        return parent[node] = findUltimateParent(parent[node]);
    }

    // add edge between node u and v
    void unionByRank(int u, int v)
    {
        int ultParentU = findUltimateParent(u);
        int ultParentV = findUltimateParent(v);

        // alredy nodes are in same component
        if (ultParentU == ultParentV)
            return;

        // Prefer attaching smaller tree under the root of the larger one
        if (rank[ultParentU] < rank[ultParentV])
        {
            // attaching ultParentU to the ultParentV
            parent[ultParentU] = ultParentV;
        }
        else if (rank[ultParentV] < rank[ultParentU])
        {
            // attaching ultParentV to ultParentU
            parent[ultParentV] = ultParentU;
        }
        else if (rank[ultParentU] == rank[ultParentV])
        {
            // We can attaching to any one
            // and make sure to increse the rank : as The root becomes taller by one level.

            parent[ultParentV] = ultParentU;
            rank[ultParentU]++; // since we attached v to u
        }
    }
};

int main()
{
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // if 3 and 7 are in same component or not
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";

    ds.unionByRank(3, 7); // after adding this edge, grah is changed and node 3 and 7 have same ultimate parent

    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";
    return 0;
}