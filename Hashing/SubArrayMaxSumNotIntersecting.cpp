#include <bits/stdc++.h>
using namespace std;

// Given an array find the maximum sum of subarray which are not intersecting
/*
    arr = { 2,3,-8,7,-1,2,3}
    maxSumSubarray1 = {7,-1,2,3} = 11
    maxSumSubarray2 = {2,3} = 5

    so, 11 + 5 = 16 ans.
*/
/*
Initialize two vectors prefixMax and suffixMax
Traverse array A and implement Kadane Algorithm from left to right and store the maximum subarray sum in prefixMax[i].
Traverse array A and implement Kadane Algorithm from right to left and store the maximum subarray sum in suffixMax[i].
Traverse from 0 to N and calculate maximum value of (prefixMax[i-1] + suffixMax[i]) and store in the variable result.
Return the result as the final answer. 
*/

int getSum(vector<int> arr)
{
    int n = arr.size();
    int ans = INT_MIN;

    vector<int> prefixMax(n);
    vector<int> suffixMax(n);
   
    // Find maximumm sum till any index i using kadence algo (from left to right)
    int currSum = 0;
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);

        if (currSum < 0) // if currsum is being -ve so it is better to set as 0 for getting maxSum
            currSum = 0;

        prefixMax[i] = maxSum;
    }

    // Find maximumm sum till any index i using kadence algo (from right to left)
    currSum = 0;
    maxSum = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        currSum += arr[i];
        maxSum = max(currSum, maxSum);

        if (currSum < 0) // if currsum is being -ve so it is better to set as 0 for getting maxSum
            currSum = 0;

        suffixMax[i] = currSum;
    }

    // Calculte maximum sum
    for (int i = 0; i < n; i++)
    {
        if(i == 0)
         ans = max(ans, 0 + suffixMax[i]); // at index 0 there is no left side prefix subarray so added 0

        else
            ans = max(ans, prefixMax[i-1] + suffixMax[i]); // as we taken prefixSum till index i but not inclued ith index in left part, 
                                                           // we have added ith index in right part. to avoid duplication
    }

    return ans;
}

int main()
{

    vector<int>arr = {2,3,-8,7,-1,2,3};
    // vector<int>arr = {5, -2, 3, -6, 5};
    int sum = getSum(arr);
    cout<<"Non overlapping subarray max sum : " << sum<<endl;
    return 0;
}