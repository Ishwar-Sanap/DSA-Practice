#include <iostream>

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
};

// AS given tree is BST, it will follow the property  left < root < right
// so we can traverse tree using above conditions to find val, in O(Log n)

/*Time Complexity: O(log2N) where N is the number of nodes in the Binary Search Tree. In the best case scenario, where the tree is balanced,
the time complexity is the height of the tree ie. log2N. In the worst-case scenario, where the tree is degenerate (linear), the time
complexity becomes O(n), as it would require traversing all nodes along the path from the root to the leaf.
*/
TreeNode *searchBST(TreeNode *root, int val)
{
    while (root)
    {
        if (root->val == val)
            return root;
        else if (val < root->val)
            root = root->left;
        else
            root = root->right;
    }

    return NULL;
}