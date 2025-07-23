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
    vector<int> size; // it store the size of component
    vector<int> parent;

public:
    DisjointSet(int n)
    {
        // for considering 1 based node values..
        size.assign(n + 1, 1); // initally the nodes having single component so size 1
        parent.assign(n + 1, 0);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;  //Initializing parent as self node
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
    void unionBysize(int u, int v)
    {
        int ultParentU = findUltimateParent(u);
        int ultParentV = findUltimateParent(v);

        // alredy nodes are in same component
        if (ultParentU == ultParentV)
            return;

        // Prefer attaching smaller tree under the root of the larger one
        if (size[ultParentU] < size[ultParentV])
        {
            // attaching ultParentU to the ultParentV
            parent[ultParentU] = ultParentV;

            size[ultParentV] += size[ultParentU]; // root node v size incresed 
        }
      
        else
        {
            // V is smaller than U
          
            parent[ultParentV] = ultParentU;
            size[ultParentU]+= size[ultParentV]; // since we attached v to u, size of root node u is incresed
        }
    }
};

int main()
{
    DisjointSet ds(7);
    ds.unionBysize(1, 2);
    ds.unionBysize(2, 3);
    ds.unionBysize(4, 5);
    ds.unionBysize(6, 7);
    ds.unionBysize(5, 6);

    // if 3 and 7 are in same component or not
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";

    // after adding this edge, grah is changed and node 3 and 7 have same ultimate parent
    ds.unionBysize(3, 7); 

    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
    {
        cout << "Same\n";
    }
    else
        cout << "Not same\n";
    return 0;
}