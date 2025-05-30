#include <bits/stdc++.h>
using namespace std;

// Recusive solution: T.C --> O(2^n) S.C--> O(N)
bool tryAllWays(int i, int sum, vector<int> &arr)
{
    // base cases
    if (sum == 0)
        return true;

    if (i == 0)
    {
        if (arr[i] == sum)
            return true;

        return false;
    }

    bool pick = false, notPick = false;

    if (arr[i] <= sum)
        pick = tryAllWays(i - 1, sum - arr[i], arr);

    notPick = tryAllWays(i - 1, sum, arr);

    return pick || notPick;
}

// Memoization solution: T.C --> O(n) S.C--> O(n) + O(n*k)
bool tryAllWays(int i, int sum, vector<int> &arr, vector<vector<int>> &dp)
{
    // base cases
    if (sum == 0)
        return true;

    if (i == 0)
    {
        if (arr[i] == sum)
            return true;

        return false;
    }

    if (dp[i][sum] != -1)
        return dp[i][sum];

    bool pick = false, notPick = false;

    if (arr[i] <= sum)
        pick = tryAllWays(i - 1, sum - arr[i], arr);

    notPick = tryAllWays(i - 1, sum, arr);

    return dp[i][sum] = (pick || notPick);
}

// Tabulation:
bool subsetSumToK_T(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));

    // base case
    //for sum == 0 , at any index (0 -> n-1) if sum becomes zero, then we are good.. found the subset sum equals to K
    for (int i = 0; i < n; i++)
        dp[i][0] = 1; // mark it as true

    // considering the first element of the array with the target equal to the first element itself
    if (arr[0] <= k)
        dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int sum = 1; sum <= k; sum++)
        {
            bool pick = false, notPick = false;

            if (arr[i] <= sum)
                pick = dp[i - 1][sum - arr[i]];

            notPick = dp[i - 1][sum];

            dp[i][sum] = (pick || notPick);
        }
    }

    return dp[n - 1][k];
}

// Space optimizaiton
bool subsetSumToKOptimized(int n, int k, vector<int> &arr)
{

    // only required prevRow of size k+1
    vector<int> preRow(k + 1, 0);
    vector<int> currRow(k + 1, 0);

    // base case
    //for sum == 0 , at any index (0 -> n-1) if sum becomes zero, then we are good.. found the subset sum equals to K
    preRow[0] = currRow[0] = 1;

    // considering the first element of the array with the target equal to the first element itself
    if (arr[0] <= k)
        preRow[arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int sum = 1; sum <= k; sum++)
        {
            bool pick = false, notPick = false;

            if (arr[i] <= sum)
                pick = preRow[sum - arr[i]];

            notPick = preRow[sum];

            currRow[sum] = (pick || notPick);
        }

        preRow = currRow;
    }

    return preRow[k];
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.

    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return tryAllWays(n - 1, k, arr, dp);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int n = arr.size();
    int sum = 5;

    return 0;
}