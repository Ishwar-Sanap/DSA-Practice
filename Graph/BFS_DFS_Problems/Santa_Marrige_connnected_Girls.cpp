
#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/santa-banta2814/1?page=1&category=Graph&sortBy=difficulty

class Solution
{
public:
    // precompute the all primes numbers till 10^5
    vector<int> primes;
    // i.e you have to genearte all the prime numbers from 0 to 10^5 and store in primes array

    void precompute()
    {

        int n = 1e7;
        vector<int> seive(1e7 + 1, 1);

        // Initially in seive array store whether the num is prime or not

        for (long long i = 2; i * i <= n; i++)
        {
            if (seive[i] == 1)
            {
                for (long long j = i * i; j <= n; j += i)
                {
                    seive[j] = 0; // mark's the mulitple of i as not prime
                }
            }
        }

        // now we have seive array ready to check whether the till 1 to 1e5 number is prime or not

        for (int k = 2; k <= n; k++)
        {
            if (seive[k] == 1)
                primes.push_back(k);
        }
    }

    int getConnectedNodesBFS(int src, vector<vector<int>> &adjList, vector<int> &visited)
    {
        int cnt = 0;

        queue<int> qNodes;
        qNodes.push(src);
        visited[src] = 1;

        while (!qNodes.empty())
        {
            int node = qNodes.front();
            qNodes.pop();
            cnt++;

            for (int neigh : adjList[node])
            {
                if (!visited[neigh])
                {
                    qNodes.push(neigh);
                    visited[neigh] = 1;
                }
            }
        }

        return cnt;
    }

    int helpSanta(int n, int m, vector<vector<int>> &g)
    {
        // Code here
        vector<vector<int>> adjList(n + 1, vector<int>());

        for (auto &edge : g)
        {
            int u = edge[0], v = edge[1];

            // Since connection can be undirected edge between the girls.
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int> visited(n + 1, 0);

        int maxConnected = 1;

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                int cnt = getConnectedNodesBFS(i, adjList, visited);
                maxConnected = max(maxConnected, cnt);
            }
        }

        // From all the groups, not any girl have connections
        if (maxConnected == 1)
            return -1;

        // return the kth prime numebr and k = maxConnected

        // cout<< primes.size()<<endl;
        return primes[maxConnected - 1];
    }
};
int main()
{
    return 0;
}
