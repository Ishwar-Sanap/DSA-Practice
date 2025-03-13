#include <bits/stdc++.h>
using namespace std;

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

void makeParentNodeArrangement(Node *root, unordered_map<Node *, Node *> &parent, int target, Node *&targetNode)
{
    if (!root)
        return;

    if (root->data == target)
        targetNode = root;

    if (root->left)
        parent[root->left] = root;
    if (root->right)
        parent[root->right] = root;

    makeParentNodeArrangement(root->left, parent, target, targetNode);
    makeParentNodeArrangement(root->right, parent, target, targetNode);
}

int minTime(Node *root, int target)
{
    if (!root)
        return 0;

    // storing node and it's parents
    unordered_map<Node *, Node *> parent;
    Node *targetNode = NULL;
    makeParentNodeArrangement(root, parent, target, targetNode);
    if (!targetNode)
        return 0;

    unordered_map<Node *, bool> visitedNodes;

    queue<Node *> qNodes;
    qNodes.push(targetNode);

    int level = 0;
    while (!qNodes.empty())
    {
        int n = qNodes.size();
        for (int i = 1; i <= n; i++)
        {
            Node *currNode = qNodes.front();
            qNodes.pop();
            visitedNodes[currNode] = true;

            if (currNode->left && !visitedNodes[currNode->left])
                qNodes.push(currNode->left);

            if (currNode->right && !visitedNodes[currNode->right])
                qNodes.push(currNode->right);

            Node *parentNode = parent[currNode];
            if (parentNode && !visitedNodes[parentNode])
                qNodes.push(parentNode);
        }

        level++;
    }

    return level - 1;
}

// Approach 2 :
// <<<<<---- Single Pass DFS --->>>>>
int traverseKaro(Node *root, int target, int &ans)
{
    if (!root)
        return 0;

    int leftSubTreeHeight = traverseKaro(root->left, target,ans);
    int rightSubTreeHeight = traverseKaro(root->right, target,ans);

    if (root->data == target) // burn node occured while traversing
    {
        ans = max(leftSubTreeHeight, rightSubTreeHeight);
        return -1;
        //Return -1; // to send depth of burning node, and -ve sign indicates it's occurace..
    }
    else if (leftSubTreeHeight >=0 && rightSubTreeHeight>= 0) // burned node not yet occured while traversing, simply return the max height
    {
        return 1 + max(leftSubTreeHeight, rightSubTreeHeight);
    }
    else // burn occured
    {   
        int depth = abs(leftSubTreeHeight)  + abs(rightSubTreeHeight);
        ans = max(ans, depth);

        return min(leftSubTreeHeight, rightSubTreeHeight) - 1;
        // adding -1 to negative will increse the depth for burning nodes for further nodes….
    }
}
int minTime2(Node *root, int target)
{
    int ans = 0;
    if (!root)
        return 0;
    traverseKaro(root, target, ans);

    return ans;
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(50);
    root->left->left = new Node(1);
    root->right->left = new Node(40);
    root->right->right = new Node(100);
    int target = 50;

    cout << minTime2(root, target) << endl;

    return 0;
}