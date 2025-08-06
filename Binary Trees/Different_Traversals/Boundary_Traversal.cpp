#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

/*
	1. Left Boundary: This includes all the nodes on the path from the root to the leftmost leaf node. You must prefer the left child over the right child when traversing. Do not include leaf nodes in this section.
	2. Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or right boundary.
    3. Reverse Right Boundary: This includes all the nodes on the path from the rightmost leaf node to the root, traversed in reverse order

*/

void getLeftMostNodes(Node *root, vector<int> &ans)
{
    if (!root || !root->left && !root->right)
        return;

    // left side nodes
    ans.push_back(root->data);

    if (root->left)
        getLeftMostNodes(root->left, ans);

    else if (root->right)
        getLeftMostNodes(root->right, ans);
}

void getLeafNodes(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    else if (!root->left && !root->right)
    { // only adds leaf nodes dataues
        ans.push_back(root->data);
        return;
    }

    getLeafNodes(root->left, ans);
    getLeafNodes(root->right, ans);
}

void getRightMostNodes(Node *root, vector<int> &ans)
{
    if (!root || !root->left && !root->right)
        return;

    if (root->right)
        getRightMostNodes(root->right, ans);

    else if (root->left)
        getRightMostNodes(root->left, ans);

    ans.push_back(root->data);
}

vector<int> boundaryTraversal(Node *root)
{
    // code here

    vector<int> ans;
    if (!root)
        return ans;

    if (root->left || root->right)
        ans.push_back(root->data);

    getLeftMostNodes(root->left, ans);
    getLeafNodes(root, ans);
    getRightMostNodes(root->right, ans);

    return ans;
}

int main()
{

    return 0;
}