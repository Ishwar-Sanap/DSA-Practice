
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

void getAllPossiblePaths(Node *root, vector<int> &path, vector<vector<int>> &ans)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        path.push_back(root->data); // adding leaf node
        ans.push_back(path);
        path.pop_back(); // removing leaf node..
        return;
    }

    path.push_back(root->data);
    getAllPossiblePaths(root->left, path, ans);
    getAllPossiblePaths(root->right, path, ans);
    path.pop_back(); // BACKTRACT TO PREVIOUS STATE
}
vector<vector<int>> Paths(Node *root)
{
    // code here

    vector<int> path;
    vector<vector<int>> ans;
    getAllPossiblePaths(root, path, ans);
    return ans;
}

int main()
{

    return 0;
}