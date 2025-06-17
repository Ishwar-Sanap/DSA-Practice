#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/largest-divisible-subset/description/

Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.

*/


// Note: Questions is asking about the subset.. so there can be any subset possible
// Subset : We can choose any elements from array in any sequence
// Subsequences : We have to choose any element in array but order of elements choosen should be original array element order 


vector<int> getLongestIncresingDivisibleSubsequence(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // i --> 0 : n
    // p --> -1 : n-1
    for (int i = n - 1; i >= 0; i--)
    {
        for (int prevIndx = i - 1; prevIndx >= -1; prevIndx--)
        {
            int pick = 0, notPick = 0;

            if (prevIndx == -1 || nums[i] % nums[prevIndx] == 0)
                pick = 1 + dp[i + 1][i + 1];

            notPick = 0 + dp[i + 1][prevIndx + 1];

            dp[i][prevIndx + 1] = max(pick, notPick);
        }
    }

    // cout<<dp[0][0]<<endl; // len LongestIncresingDivisibleSubsequence

    // Backtrack in dp table to print the subsequence
    int indx = 0, prevIndx = -1;
    vector<int> ans;
    while (indx < n)
    {
        if (prevIndx == -1 || nums[indx] % nums[prevIndx] == 0)
        {
            int pick = dp[indx + 1][indx + 1];
            int notPick = dp[indx + 1][prevIndx + 1];

            if (pick >= notPick)
            {
                ans.push_back(nums[indx]);
                prevIndx = indx;
            }
        }

        indx++;
    }

    return ans;
}

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    // we had sorted the array, to find the len of longest divisible subsequence
    // 2 4 7 8 16 -->> [2,4,8,16] is our expected answer and since array is sorted
    // if(ans[1] % ans[0] == 0) then we can say that ans[2] % arr[1] ==0 and so onn....
    sort(nums.begin(), nums.end());

    return getLongestIncresingDivisibleSubsequence(nums);
}

int main()
{
    vector<int> arr = {2, 4, 7, 8, 16, 3, 9};

    vector<int> ans = getLongestIncresingDivisibleSubsequence(arr);

    for (int ele : ans)
        cout << ele << " ";

    return 0;
}