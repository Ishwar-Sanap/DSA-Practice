#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void traverseKaro(TreeNode *root, int row, int column, map < int, map<int, multiset<int>>> &mp)
{
    if (!root)
        return;

    mp[column][row].insert(root->val); // adding value into the multiset

    traverseKaro(root->left, row + 1, column - 1, mp);
    traverseKaro(root->right, row + 1, column + 1, mp);
}

vector<vector<int>> verticalTraversal(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;

    // it will stores the column and row and nodes values
    map < int, map<int, multiset<int>> > mp;
    // multiset stores, duplicate elements in sorted order

    // DFS
    traverseKaro(root, 0, 0, mp);
    // using BFS also we can travers and fill values into the map

    
    for (auto itmp : mp)
    {
        vector<int>verticalNodes;
        // for current column there can be multiple rows, add all these result into verticalNodes 
        for(auto it : itmp.second)
        {
            for(int value : it.second)
                verticalNodes.push_back(value);
       }

        ans.push_back(verticalNodes);
       
    }

    return ans;
}
int main()
{

    return 0;
}