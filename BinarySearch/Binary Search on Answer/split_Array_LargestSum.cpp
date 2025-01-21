#include <bits/stdc++.h>
using namespace std;
/*
Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.



Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.

*/

bool canSplitArray(vector<int> &arr, int k, int maxSum)
{
    int subArrCnt = 1;
    int i = 0, n = arr.size();
    int currSum = 0;
    while (i < n)
    {
        currSum += arr[i];
        if (currSum > maxSum)
        {
            currSum = 0;
            subArrCnt++;
            continue;
        }
        i++;
    }
    return subArrCnt <= k;
}

int splitArray(vector<int> &arr, int k)
{
    // code here

    int ans = -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // if we can split array with thease max sum then try to minimize sum
        if (canSplitArray(arr, k, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    // return ans;
    return low;
}
int main()
{

    return 0;
}