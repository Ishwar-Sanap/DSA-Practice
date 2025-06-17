#include <bits/stdc++.h>
using namespace std;

/*
A Bitonic Sequence is a sequence of numbers that is first strictly increasing and then strictly decreasing.

A strictly ascending order sequence is also considered bitonic, with the decreasing part as empty, and same for a strictly descending order sequence.

For example, the sequences [1, 3, 5, 3, 2], [1, 2, 3, 4] are bitonic, whereas the sequences [5, 4, 1, 4, 5] and [1, 2, 2, 3] are not.

You are given an array 'arr' consisting of 'n' positive integers.

Find the length of the longest bitonic subsequence of 'arr'.

*/

int longestBitonicSubsequence(vector<int> &arr, int n)
{
    // Write your code here.

    vector<int> dp1(n, 1); // dp1[i] stores the length of the longest increasing subsequence ending at arr[i]
    vector<int> dp2(n, 1); // dp2[i] stores the length of the longest decreasing subsequence ending at arr[i]

    // Longest incresing subsequences (LIS)
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[i] > arr[prev])
                dp1[i] = max(dp1[i], 1 + dp1[prev]);
        }
    }

    // Longest decresing subsequences (LDS)
    // If we see array from right side then we will apply same LIS to find LDS
    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev = n - 1; prev > i; prev--)
        {
            if (arr[i] > arr[prev])
                dp2[i] = max(dp2[i], 1 + dp2[prev]);
        }
    }

    int maxLen = 0;
    for (int i = 0; i < n; i++)
    {
        maxLen = max(maxLen, (dp1[i] + dp2[i]) - 1);
    }

    return maxLen;
}

int main()
{

    return 0;
}