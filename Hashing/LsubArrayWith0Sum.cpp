#include <bits/stdc++.h>
using namespace std;
/*
Input: arr[] = [15, -2, 2, -8, 1, 7, 10, 23]
Output: 5
Explanation: The largest subarray with a sum of 0 is [-2, 2, -8, 1, 7].
*/
int maxLen(vector<int> &arr)
{
    unordered_map<int, int> mp;
    mp[0] = -1;
    int maxiLen = 0, currSum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        currSum += arr[i];
        if (mp.find(currSum) != mp.end())
        {
            maxiLen = max(maxiLen, i - mp[currSum]);
        }

        else
            mp[currSum] = i;
    }
    return maxiLen;
}