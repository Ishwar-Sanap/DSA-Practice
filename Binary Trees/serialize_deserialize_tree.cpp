#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 
// Encodes a tree to a single string.
string serialize(TreeNode *root)
{
    if (!root)
        return "";

    string treeStructure = "";

    // use level order traversls and create the string of all nodes including null

    queue<TreeNode *> qNodes;
    qNodes.push(root);

    while (!qNodes.empty())
    {
        TreeNode *currNode = qNodes.front();
        qNodes.pop();

        if (currNode)
        {
            treeStructure += to_string(currNode->val) + ","; // comma as seperator
            qNodes.push(currNode->left);
            qNodes.push(currNode->right);
        }
        else
        {

            // add null nodes
            treeStructure += "N,";
        }
    }

    return treeStructure; // returning the serialized tree structure
}

vector<string> parseTreeStructure(string data)
{
    // tokenize the data using , operator
    vector<string> res;
    int i = 0, n = data.length();
    while (i < n)
    {
        string token = "";

        while (i < n && data[i] != ',')
        {
            token += data[i];
            i++;
        }

        res.push_back(token);
        i++;
    }

    return res;
}
// Decodes your encoded data to tree.
TreeNode *deserialize(string data)
{
    if (data.length() == 0)
        return NULL;

    vector<string> tokens = parseTreeStructure(data);
    int token_size = tokens.size();

    // we have level order traversal of tree, so create the tree from it.

    int val = stoi(tokens[0]);
    TreeNode *root = new TreeNode(val);

    queue<TreeNode *> qNodes;
    qNodes.push(root);

    int i = 1;
    while (!qNodes.empty())
    {
        TreeNode *currNode = qNodes.front();
        qNodes.pop();

        if (tokens[i] != "N")
        {
            int val = stoi(tokens[i]);
            currNode->left = new TreeNode(val);
            qNodes.push(currNode->left);
        }
        i++;

        if (i < token_size && tokens[i] != "N")
        {
            int val = stoi(tokens[i]);
            currNode->right = new TreeNode(val);
            qNodes.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main()
{

    string data = "12,2,-3,N,N,4,5";

    vector<string> tokens = parseTreeStructure(data);

    for (string str : tokens)
        cout << str << endl;
    return 0;
}