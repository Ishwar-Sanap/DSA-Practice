#include <bits/stdc++.h>
using namespace std;

/*
 Your task is to find the size of the largest subtree within this binary tree that also satisfies the
  properties of a Binary Search Tree (BST). The size of a subtree is defined as the number of nodes
it contains.

*/
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

vector<int> traversePostOrder(Node *root, int &ans)
{   
    // for single NULL node it is valid BST
    if (!root)
        return {0, INT_MIN, INT_MAX}; // node count, largest, smallest

    vector<int> leftSide = traversePostOrder(root->left, ans);
    vector<int> rightSide = traversePostOrder(root->right, ans);

    // cout << " ROOT : " << root->data << endl;

    // cout << leftSide[0] << " " << leftSide[1] << " " << leftSide[2] << endl;
    // cout << rightSide[0] << " " << rightSide[1] << " " << rightSide[2] << endl;

    if (leftSide[1] < root->data && root->data < rightSide[2])
    {
        int cnt = leftSide[0] + rightSide[0] + 1;
        int smallest = min({root->data,  leftSide[2]});
        int largest = max({root->data,  rightSide[1]});

        ans = max(ans, cnt);
        return {cnt, largest, smallest};
    }
    else
    {
        // not valid BST // changed Smallest and Largest
        return {0,  INT_MAX , INT_MIN};
    }
}

int largestBst(Node *root)
{
    // Your code here

    int ans = 0;
    traversePostOrder(root, ans);

    return ans;
}

int main()
{

    Node *root = new Node(1);
    root->left = new Node(4);
    root->right = new Node(4);
    root->left->left = new Node(6);
    root->left->right = new Node(8);

    cout << largestBst(root) << endl;

    return 0;
}