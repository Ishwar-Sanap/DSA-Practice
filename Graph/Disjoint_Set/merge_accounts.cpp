#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/accounts-merge/description/

class DisjointSet
{
    vector<int> size; // it store the size of component
    vector<int> parent;

public:
    DisjointSet(int n)
    {
        // for considering 1 based node values..
        size.assign(n + 1, 1); // initally the nodes having single component so size 1
        parent.assign(n + 1, 0);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i; // Initializing parent as self node
        }
    }

    // ultimate parent refers to the topmost node or the root node.
    int findUltimateParent(int node)
    {
        // node is the topMost node
        if (parent[node] == node)
            return node;

        // Path Compression :
        // connecting each node in a particular path to its ultimate parent refers to path compression
        return parent[node] = findUltimateParent(parent[node]);
    }

    // add edge between node u and v
    void unionBysize(int u, int v)
    {
        int ultParentU = findUltimateParent(u);
        int ultParentV = findUltimateParent(v);

        // alredy nodes are in same component
        if (ultParentU == ultParentV)
            return;

        // Prefer attaching smaller tree under the root of the larger one
        if (size[ultParentU] < size[ultParentV])
        {
            // attaching ultParentU to the ultParentV
            parent[ultParentU] = ultParentV;

            size[ultParentV] += size[ultParentU]; // root node v size incresed
        }

        else
        {
            // V is smaller than U

            parent[ultParentV] = ultParentU;
            size[ultParentU] += size[ultParentV]; // since we attached v to u, size of root node u is incresed
        }
    }
};
class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {

        int n = accounts.size();

        unordered_map<string, int> mp;

        DisjointSet ds(n);
        for (int i = 0; i < n; i++)
        {
            // check every email..
            for (int k = 1; k < accounts[i].size(); k++)
            {
                string email = accounts[i][k];

                if (mp.find(email) != mp.end())
                {
                    int j = mp[email];

                    // since email are same ith node and jth node are same person can be grouped together
                    ds.unionBysize(i, j);
                }
                else
                    mp.insert({email, i});
            }
        }

        // after the union all the common emails accounts are grouped into single components

        unordered_map<int, vector<string>> mpEmails;
        for (auto &it : mp)
        {
            int node = it.second;
            string email = it.first;
            int ulp = ds.findUltimateParent(node);

            mpEmails[ulp].push_back(email);
        }

        vector<vector<string>> ans;
        for (auto it : mpEmails)
        {
            int node = it.first;
            vector<string> &emails = it.second;

            vector<string> account;

            // pushing name
            account.push_back(accounts[node][0]);

            // Sorting emails in asending order
            sort(emails.begin(), emails.end());

            account.insert(account.end(), emails.begin(), emails.end());

            ans.push_back(account);
        }

        return ans;
    }
};
int main()
{
    return 0;
}