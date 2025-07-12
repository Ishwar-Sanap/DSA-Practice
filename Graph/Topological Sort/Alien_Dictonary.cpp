#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/problems/alien-dictionary/1#approach-1-using-kahns-algorithm

void bfsTopoSort(vector<vector<int>> &adjList, vector<int> &indegree, vector<int> &ans)
{
    queue<int> qNodes;
    for (int i = 0; i < indegree.size(); i++)
    {
        if (indegree[i] == 0)
            qNodes.push(i);
    }

    while (!qNodes.empty())
    {
        int u = qNodes.front();
        qNodes.pop();
        ans.push_back(u);

        for (int v : adjList[u])
        {
            indegree[v]--;

            if (indegree[v] == 0)
                qNodes.push(v);
        }
    }
}
string findOrder(vector<string> &words)
{
    vector<int> exists(26, 0);
    for (string word : words)
    {
        for (char ch : word)
            exists[ch - 'a']++;
    }

    int V = 26;
    vector<vector<int>> adjList(V, vector<int>());

    vector<int> indegree(V, -1);

    int disticnt = 0;
    for (int i = 0; i < 26; i++)
    {
        if (exists[i])
        {
            indegree[i] = 0;
            disticnt++;
        }
    }
    int n = words.size();

    for (int i = 0; i < n - 1; i++)
    {
        string str1 = words[i];
        string str2 = words[i + 1];

        if (str1.length() > str2.length() && str1.substr(0, str2.length()) == str2)
            return ""; // Invalid case: prefix issue {"abc", "ab"};

        int j = 0, k = 0;

        while (j < str1.length() && k < str2.length())
        {
            if (str1[j] != str2[k])
            {
                // str1[j] should come before the str2[k]
                int u = str1[j] - 'a', v = str2[k] - 'a';
                adjList[u].push_back(v);
                indegree[v]++;
                break;
            }

            j++;
            k++;
        }
    }

    vector<int> topo;

    bfsTopoSort(adjList, indegree, topo);

    if (topo.size() != disticnt)
        return ""; // Cycle exist

    string res = "";
    for (int i = 0; i < topo.size(); i++)
    {
        char ch = 'a' + topo[i];
        res += ch;
    }

    return res;
}

int main()
{
    vector<string> words = {"baa", "abcd", "abca", "cab", "cad"};
    // vector<string> words = {"abc", "abcd", "abcde",};
    // vector<string> words = {"bdbc", "dbe", "bcebc", "e", "bedb"};

    cout << findOrder(words) << endl;
    return 0;
}