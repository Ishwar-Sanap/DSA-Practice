#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;

// Memoization : T.C --> O(N*k)  , S.C --> O(N*K) + O(N)
int tryAllWays(int indx, int sum, vector<int> &arr, vector<vector<int>> &dp)
{
    // we have to go till the 0th index for counting all subsets...
    if (indx == 0)
    {
        // try the both pick and non pick her
        int pick = (sum - arr[indx] == 0) ? 1 : 0;
        int nonPick = (sum == 0) ? 1 : 0;

        return pick + nonPick;
    }

    if (dp[indx][sum] != -1)
        return dp[indx][sum];

    int pick = 0, nonPick = 0;

    if (arr[indx] <= sum)
        pick = tryAllWays(indx - 1, sum - arr[indx], arr, dp);

    nonPick = tryAllWays(indx - 1, sum, arr, dp);

    return dp[indx][sum] = (pick + nonPick) % mod;
}

// Tabulation : T.C --> O(N*k)  , S.C --> O(N*K)
int tryAllWays(int k, vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    for (int i = 0; i < n; i++)
    {
        for (int sum = 0; sum <= k; sum++)
        {
            // base case..
            // we have to go till the 0th index for counting all subsets...
            if (i == 0)
            {
                // try the both pick and non pick her
                int pick = (sum - arr[i] == 0) ? 1 : 0;
                int nonPick = (sum == 0) ? 1 : 0;

                dp[i][sum] = pick + nonPick;
                continue;
            }

            int pick = 0, notPick = 0;

            if (arr[i] <= sum)
                pick = dp[i - 1][sum - arr[i]];

            notPick = dp[i - 1][sum];

            dp[i][sum] = (pick + notPick) % mod;
        }
    }

    return dp[n - 1][k];
}

// Space optimization : T.C --> O(N*k)  , S.C --> O(k)
int findWays_optimized(int k, vector<int> &arr)
{
    int n = arr.size();
    vector<int> prevRow(k + 1, 0);
    vector<int> currRow(k + 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int sum = 0; sum <= k; sum++)
        {
            // base case..
            // we have to go till the 0th index for counting all subsets...
            if (i == 0)
            {
                // try the both pick and non pick her
                int pick = (sum - arr[i] == 0) ? 1 : 0;
                int nonPick = (sum == 0) ? 1 : 0;

                currRow[sum] = pick + nonPick;
                continue;
            }

            int pick = 0, notPick = 0;

            if (arr[i] <= sum)
                pick = prevRow[sum - arr[i]];

            notPick = prevRow[sum];

            currRow[sum] = (pick + notPick) % mod;
        }
        prevRow = currRow;
    }

    return prevRow[k];
}

int findWays(vector<int> &arr, int k)
{
    // Write your code here.

    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    // return tryAllWays(n - 1, k, arr, dp);
    return tryAllWays(k, arr);
}

int main()
{
    // vector<int> arr = {1, 4, 4, 5};
    vector<int> arr = {0, 1, 4};
    cout << findWays(arr, 5) << endl;
    return 0;
}