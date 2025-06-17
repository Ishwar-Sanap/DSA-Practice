#include <bits/stdc++.h>
using namespace std;

/*
	https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
	
	Given an integer array nums, return the number of longest increasing subsequences.
	
	Notice that the sequence has to be strictly increasing.
	
	 
	Example 1:
	
	Input: nums = [1,3,5,4,7]
	Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].

*/

int findNumberOfLIS(vector<int> &nums)
{

    int n = nums.size();
    int maxLen = 0;
    vector<int> dp(n, 1); // it gives the length of LIS ending at index i
    vector<int> cnts(n, 1); //Counts of LIS endintg at i
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (nums[i] > nums[prev])
            {
                if ((1 + dp[prev]) == dp[i]) // for current subsequence legth it alreday appered
                {
                    cnts[i] += cnts[prev];
                }
                else if ((1 + dp[prev]) > dp[i])
                {

                    dp[i] = 1 + dp[prev];
                    cnts[i] = cnts[prev];
                }
            }
        }

        if (dp[i] > maxLen)
        {
            maxLen = dp[i];
        }
    }

    int totalLIS = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxLen)
            totalLIS += cnts[i];
    }
    return totalLIS;
}
int main()
{

    return 0;
}