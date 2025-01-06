#include <bits/stdc++.h>
using namespace std;
/*
Input: arr[] = [1, -1, 5, -2, 3], k = 3
Output: 4
Explanation: The subarray [1, -1, 5, -2] has a sum of 3 and a length 4.
*/
int lenOfLongestSubarr(vector<int> &arr, int k)
{
    // code here
    unordered_map<int, int> prefixSumMap;
    prefixSumMap[0] = -1; // to handle case where from 0th index subArrat have sum k
    int n = arr.size();
    long currSum = 0;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        // As we want largest subarray so update prefixSumMap index only when currSum occures first time.
        if (prefixSumMap.find(currSum) == prefixSumMap.end())
            prefixSumMap[currSum] = i;

        long req = currSum - k;

        if (prefixSumMap.find(req) != prefixSumMap.end())
            ans = max(ans, i - prefixSumMap[req]);
    }
    return ans;
}

int main()
{

    return 0;
}