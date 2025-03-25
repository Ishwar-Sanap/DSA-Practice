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

// https://www.geeksforgeeks.org/problems/merge-two-bst-s/1

// Perfoming Inorder traversal using stack,
// TC. -- O(n1 + n2)  S.C --> O(h1 + h2)

void insertLeftSideNodes(stack<Node *> &st, Node *root)
{
    while (root)
    {
        st.push(root);
        root = root->left;
    }
}
vector<int> merge(Node *root1, Node *root2)
{

    stack<Node *> st1;
    stack<Node *> st2;

    vector<int> ans;

    insertLeftSideNodes(st1, root1);
    insertLeftSideNodes(st2, root2);

    // Same As merge 2 sorted array, but here is BST, traversal in stack.
    while (!st2.empty() && !st1.empty())
    {
        // smaller element found in second tree
        if (st2.top()->data <= st1.top()->data)
        {
            ans.push_back(st2.top()->data);

            root2 = st2.top()->right;
            st2.pop(); // remove visited node

            insertLeftSideNodes(st2, root2);
        }
        else
        {
            ans.push_back(st1.top()->data);

            root1 = st1.top()->right;
            st1.pop(); // remove visited node

            insertLeftSideNodes(st1, root1);
        }
    }

    while (!st2.empty())
    {
        ans.push_back(st2.top()->data);
        root2 = st2.top()->right;
        st2.pop(); // remove visited node
        insertLeftSideNodes(st2, root2);
    }

    while (!st1.empty())
    {
        ans.push_back(st1.top()->data);

        root1 = st1.top()->right;
        st1.pop(); // remove visited node

        insertLeftSideNodes(st1, root1);
    }

    return ans;
}

int main()
{

    return 0;
}