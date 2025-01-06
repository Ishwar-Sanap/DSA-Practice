/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a
subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
*/

int minSubArrayLen(int target, vector<int> &nums)
{

    int n = nums.size();
    int i = 0, j = 0, sum = 0, minLen = n + 1;
    while (j < n)
    {
        sum += nums[j];
        if (sum < target)
            j++;

        else
        {
            while (sum >= target)
            {
                minLen = min(minLen, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
    }

    return minLen == n + 1 ? 0 : minLen;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{

    return 0;
}