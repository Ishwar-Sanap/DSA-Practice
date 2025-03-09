#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};

void traverseKaroBFS(Node *root, map<int, int> &mp)
{
    if (!root)
        return;

    queue<pair<Node *, int>> qNodes;
    qNodes.push({root, 0});

    while (!qNodes.empty())
    {
        Node *currNode = qNodes.front().first;
        int col = qNodes.front().second;
        qNodes.pop();

        //since we want, last node for the column , so update col every time with latest node
        mp[col] = currNode->data; // inserting the data, 
        
        if (currNode->left)
            qNodes.push({currNode->left, col - 1});

        if (currNode->right)
            qNodes.push({currNode->right, col + 1});
    }
}

vector<int> bottomView(Node *root)
{
    // code here
    map<int, int> mp; // it will store, the column, and first seen node value
    // column will start from the root node, and for left child, decrement count
    // for right child increment the count

    // DFS will not give correct answer, if column is visited first by internal nodes,

    traverseKaroBFS(root, mp);

    vector<int> ans;
    for (pair<int, int> p : mp)
    {
        ans.push_back(p.second);
    }

    return ans;
}