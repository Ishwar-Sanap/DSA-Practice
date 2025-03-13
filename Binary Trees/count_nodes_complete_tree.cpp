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
class Solution
{
public:
//	- T.C for getting leftHeight and rightHeight it will take, o(Logn) time
// And also we travesing it for each node, so O(Logn) * O(logn) = O(Logn)^2 …..

//logn
    int getLeftNodes(TreeNode *root)
    {
        int cnt = 0;
        while (root)
        {
            cnt++;
            root = root->left;
        }
        return cnt;
    }
    int getRightNodes(TreeNode *root)
    {
        int cnt = 0;
        while (root)
        {
            cnt++;
            root = root->right;
        }
        return cnt;
    }

    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;

        int lh = getLeftNodes(root);
        int rh = getRightNodes(root);

        // tree is Perfect Binary tree, all internal nodes has 2 children and all leaf are same level
        if (lh == rh)
        {
            int nodes = pow(2, lh) - 1;
            return nodes;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main()
{

    return 0;
}