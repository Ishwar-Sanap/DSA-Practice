#include <bits/stdc++.h>
using namespace std;

/* We can't apply sliding window 2 pointer approach i.e j++ for increseSum and i-- for decrese sum
     directly when There is negative numbers in array,
     We have to store, currSum in monotonically incresing format. to apply above technique

    Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.

A subarray is a contiguous part of an array.

     2 - 1 3  2 , Target = 5 ,, For sum >= Target, Subarray possible--> [2 -1 3 2] , [ 3 2]
      minimum length = 2

    - By consider problem use case, we have remove and add element from back to maintain monotoinically incresing order
    - And also we have to shrink the window i.e removing elements from front when sum >= Target, so we can think of deque
    Data structure, where insertaton and delation is possible at both the End.

     */

int shortestSubarray(vector<int> &nums, int k)
{
    int n = nums.size();
    deque<pair<long long, int>> dq; // store sum and indices

    long long currSum = 0;
    int i = 0, j = 0, minLen = n + 1;
    while (j < n)
    {
        currSum += nums[j];

        if (currSum >= k)
            minLen = min(minLen, j - i + 1);

        // Try to shrik window for minimum length
        while (dq.size() > 0 && (currSum - dq.front().first) >= k)
        {
            int startIndex = dq.front().second;
            minLen = min(minLen, j - startIndex);
            dq.pop_front();
        }

        // maintain monotonic deque of PrefixSum indices
        while (dq.size() > 0 && dq.back().first >= currSum)
            dq.pop_back();

        dq.push_back({currSum, j});

        j++;
    }

    return minLen == n + 1 ? -1 : minLen;
}

int main()
{

    return 0;
}