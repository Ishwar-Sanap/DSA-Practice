#include <bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, find the subarray with the largest sum, and return its sum.
Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

*/
// return the maximum sum from the subArray
int maxSubArray(vector<int> &arr)
{
    int maxSum = INT_MIN;
    int currSum = 0;
    for (int ele : arr)
    {
        currSum += ele;

        maxSum = max(currSum, maxSum);

        // when sum is becomes -ve, then no point in incresing sum, it leads to mimimum sum
        // but we want to maximize the sum so we reset currSum = 0, i.e take next subArray..
        if (currSum < 0)
            currSum = 0;
    }
    return maxSum;
}

// here we want to print the subArray whose sum is maximum..
void maxSumSubArray(vector<int> &arr)
{
    int currSum = 0, n = arr.size();
    int maxSubArrySI = 0, maxSubArrayEI = 0;
    int si = 0, ei = 0; // temporary poiters

    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];

        if (currSum > maxSum)
        {
            maxSum = currSum;
            ei = i; // till this index found the max subArray sum

            maxSubArrySI = si;
            maxSubArrayEI = ei;
        }

        if (currSum < 0)
        {
            // going for next subArray
            currSum = 0;
            si = i + 1;
            ei = i + 1;
        }
    }

    for (int j = maxSubArrySI; j <= maxSubArrayEI; j++)
        cout << arr[j] << " ";

    cout << endl;
}
int main()
{

    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};  // [7 -1 2 3  ] 
   // vector<int> arr = {-8, -7, -1, -9 }; // [ -1 ]

    maxSumSubArray(arr);
    return 0;
}