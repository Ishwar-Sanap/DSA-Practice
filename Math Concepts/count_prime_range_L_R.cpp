#include <bits/stdc++.h>
using namespace std;

vector<int> getSieve(int n)
{
    vector<int> primes(n + 1, 1);

    primes[0] = 0, primes[1] = 0;

    for (int i = 2; i * i <= n; i++)
    {
        if (primes[i] == 1)
        {
            // make the multplites of i as 0
            for (int j = i * i; j <= n; j += i)
            {
                primes[j] = 0;
            }
        }
    }

    return primes;
}

vector<int> geCountOfPrimes(vector<pair<int, int>> &queries)
{
    // Precomputing the primes for larger n i.e largest input r in query
    vector<int> primes = getSieve(1000000);

    // since we need to get the count of multiple queries we can apply prefix sum of primes array
    // so that, count can be get in O(1) time...

    int prefixCnt = 0, n = primes.size();
    for (int i = 2; i < n; i++)
    {
        prefixCnt += primes[i];
        primes[i] = prefixCnt;
    }

    // For each query count the no of primes in range
    vector<int> counts;

    for (auto query : queries)
    {
        int l = query.first;
        int r = query.second;

        int cnt = primes[r] - primes[l - 1];
        counts.push_back(cnt);
    }

    return counts;
}

int main()
{
    vector<pair<int, int>> queries = {{1, 100}, {90, 100}, {1, 20}, {8, 10}};
    vector<int> counts = geCountOfPrimes(queries);

    int n = queries.size();
    for (int i = 0; i < n; i++)
    {
        cout << "Count of prime numbers in [" << queries[i].first << " - " << queries[i].second << "] " << counts[i] << endl;
    }
    return 0;
}