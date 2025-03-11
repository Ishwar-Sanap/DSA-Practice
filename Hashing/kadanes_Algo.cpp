#include <bits/stdc++.h>
using namespace std;

/*
Given an array arr[], the task is to find the subarray that has the maximum sum and return its sum.

	Input: arr[] = {2, 3, -8, 7, -1, 2, 3}
	Output: 11
	Explanation: The subarray {7, -1, 2, 3} has the largest sum 11.

*/

long getMaxSumSubarray(int arr[] , int n)
{
    long maxSum = INT_MIN;
    long currSum = 0;

    for(int i = 0; i<n; i++)
    {
        currSum += arr[i];
        maxSum = max(maxSum, currSum);

        // if some is going to -ve then, no point in adding more array elements to current sum
        // it will never gives max sum, so make it to 0
        if(currSum < 0)
            currSum = 0;
    }

    return maxSum;
}

int main()
{
    int  arr[] = {2, 3, -8, 7, -1, 2, 3};
    cout<<getMaxSumSubarray(arr,7)<<endl;
    return 0;
}