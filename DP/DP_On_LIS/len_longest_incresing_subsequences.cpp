#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/longest-increasing-subsequence/

Given an integer array nums, return the length of the longest strictly increasing subsequence.



Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
*/
int tryAllWays(int indx, int preIndx, vector<int> &nums, vector<vector<int>> &dp)
{
    if (indx == nums.size())
        return 0;

    // Shifting of the indcies--> since, -ve prevIndex can't be store
    if (dp[indx][preIndx + 1] != -1)
        return dp[indx][preIndx + 1];

    int pick = 0, notPick = 0;
    if (preIndx == -1 || nums[indx] > nums[preIndx])
        pick = 1 + tryAllWays(indx + 1, indx, nums, dp);

    notPick = 0 + tryAllWays(indx + 1, preIndx, nums, dp);

    return dp[indx][preIndx + 1] = max(pick, notPick);
}

// Tabulation
int lengthOfLIS_T(vector<int> &nums)
{

    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // i --> 0 : n
    // p --> -1 : n-1 : since second state of varible in shifted from [-1 : n-1] to  [0 : n]  --> we have to use +1
    // while accessing 2nd state
    for (int i = n - 1; i >= 0; i--)
    {
        for (int prevIndx = i - 1; prevIndx >= -1; prevIndx--)
        {
            int pick = 0, notPick = 0;

            if (prevIndx == -1 || nums[i] > nums[prevIndx])
                pick = 1 + dp[i + 1][i + 1];

            notPick = 0 + dp[i + 1][prevIndx + 1];

            dp[i][prevIndx + 1] = max(pick, notPick);
        }
    }

    return dp[0][0];
}

// Tabulation Alogrithm
int lengthLISOP(vector<int> &nums)
{
    int n = nums.size();

    vector<int> dp(n + 1, 1); /// From each index we can form 1 length LIS

    // dp[i]-->  // it gives the length of LIS ending at index i

    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (nums[i] > nums[prev])
                dp[i] = max(dp[i], 1 + dp[prev]); //  1 + dp[prev] means current element can be added into the previous LIS
        }

        if (dp[i] > maxLen)
            maxLen = dp[i];
    }

    return maxLen;
}

int lengthOfLIS(vector<int> &nums)
{

    // 2 states : indx and previous number
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return tryAllWays(0, -1, nums, dp); // Here prevIndx is send as -1, so we have use index shifting to handle -ve indices..
}

int main()
{
    vector<int> arr = {12, 4, 11, 1, 16, 8};
    // vector<int> arr = {11,12,13};

    cout << lengthLISOP(arr) << endl;

    return 0;
}