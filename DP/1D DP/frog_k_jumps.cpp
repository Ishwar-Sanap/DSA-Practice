#include <bits/stdc++.h>
using namespace std;

// Recursive solution : T.C (k^n)
int tryAllWays(int indx, vector<int> &heights, int k)
{
    if (indx == 0)
        return 0;

    int minCost = INT_MAX;
    // We had k choices from index to jump so try all of these
    for (int i = indx - 1; i >= 0 && i >= indx - k; i--)
    {
        int currStepCost = abs(heights[indx] - heights[i]);
        minCost = min(minCost, currStepCost + tryAllWays(i, heights, k));
    }

    return minCost;
}
// Memoization solution : T.C (k*n)
int tryAllWays(int indx, vector<int> &heights, int k, vector<int> &dp)
{
    if (indx == 0)
        return 0;

    if (dp[indx] != -1)
        return dp[indx];

    int minCost = INT_MAX;
    // We had k choices from index to jump so try all of these
    for (int i = indx - 1; i >= 0 && i >= indx - k; i--)
    {
        int currStepCost = abs(heights[indx] - heights[i]);
        minCost = min(minCost, currStepCost + tryAllWays(i, heights, k, dp));
    }

    return dp[indx] = minCost;
}

// Tabulation
int frogJump_T(vector<int> &heights, int k)
{
    int n = heights.size();
    if (n <= 1)
        return 0;

    vector<int> dp(n + 1, -1);

    // base conditions by basic observations
    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);

    for (int indx = 2; indx < n; indx++)
    {
        int minCost = INT_MAX;
        int i = indx - 1;
        // We had k choices from index to jump so try all of these
        while (i >= 0 && i >= indx - k)
        {
            int currCost = abs(heights[indx] - heights[i]);
            minCost = min(minCost, currCost + dp[i]);
            i--;
        }

        dp[indx] = minCost;
    }

    return dp[n - 1];
}
int frogJump(vector<int> &heights, int k)
{
    int n = heights.size();
    // return tryAllWays(n - 1, heights, k);

    // vector<int> dp(n + 1, -1);
    // return tryAllWays(n - 1, heights, k, dp);

    return frogJump_T(heights, k);
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();

    vector<int> heights = {15, 4, 1, 14, 15};

    cout << frogJump(heights, 3) << endl;

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;

    return 0;
}