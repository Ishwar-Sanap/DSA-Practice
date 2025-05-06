#include <bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/binary-subarrays-with-sum/description/

Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

A subarray is a contiguous part of the array.

 

Example 1:

Input: nums = [1,0,1,0,1], goal = 2
Output: 4
Explanation: The 4 subarrays are bolded and underlined below:
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]
[1,0,1,0,1]

*/

// Approach1
//  T.C O(n) S.C O(n)
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    unordered_map<int, int> prefixSum;
    prefixSum[0] = 1;

    int currSum = 0, cnt = 0;
    for (int num : nums)
    {
        currSum += num;

        int req = currSum - goal;
        cnt += prefixSum[req];

        prefixSum[currSum]++;
    }
    return cnt;
}

// Approach2:
int atMostKOnes(vector<int> &nums, int k)
{
    int i = 0, j = 0, n = nums.size();
    int cntSubArray = 0, oneCnts = 0;

    if (k < 0)
        return 0;
    while (j < n)
    {
        if (nums[j] == 1)
            oneCnts++;

        if (oneCnts <= k)
        {
            cntSubArray += (j - i + 1);
            j++;
        }
        else
        {

            while (i < n && oneCnts > k)
            {
                if (nums[i] == 1)
                    oneCnts--;

                i++;
            }

            cntSubArray += (j - i + 1);
            j++;
        }
    }
    return cntSubArray;
}
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    return atMostKOnes(nums, goal) - atMostKOnes(nums, goal - 1);
}
int main()
{

    return 0;
}