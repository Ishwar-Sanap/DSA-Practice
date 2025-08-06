#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
// https://leetcode.com/problems/clone-graph/description/?envType=problem-list-v2&envId=graph


class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

//Return a deep copy (clone) of the graph.

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(!node)return NULL;

        Node* root =  new Node(node->val);

        //it will store the mapping for old Node to new Node
        // that means,  copies[node] gives the address of new deeply copied node.
        unordered_map<Node* , Node*> copies;
        copies[node] = root;

        queue<Node*>qNodes;
        qNodes.push(node);

        while(!qNodes.empty())
        {
            auto currNode = qNodes.front();
            qNodes.pop();
          
            //Exploring the neighbors of node
            for(auto neigh : currNode->neighbors)
            {
                if(copies.find(neigh) == copies.end()) // not yet visited.
                {
                    //for old neigh node --> mapping with the new deeply copied node
                    copies[neigh] = new Node(neigh->val); 
                    qNodes.push(neigh);
                }
                
                //Stroing the newly copied neighbors
                copies[currNode]->neighbors.push_back(copies[neigh]);
               
            }
        }
        
        return root;
    }
};
int main()
{
   return 0;
}