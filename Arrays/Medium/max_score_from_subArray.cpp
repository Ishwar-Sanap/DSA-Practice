#include <bits/stdc++.h>
using namespace std;

/*
https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/0?category&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=max-sum-in-sub-arrays

Given an array arr[], with 0-based indexing, select any two indexes, i and j such that i < j. From the subarray arr[i...j], select the
smallest and second smallest numbers and add them, you will get the score for that subarray. Return the maximum possible score across all
the subarrays of array arr[].

Examples :
Input : arr[] = [4, 3, 1, 5, 6]
Output : 11

*/
int pairWithMaxSum(vector<int> &arr)
{
    // Your code goes here

    int maxSum = 0;

    int i = 0, n = arr.size();

    for (i = 1; i < n; i++)
    {
        maxSum = max(maxSum, arr[i] + arr[i - 1]);
    }
    return maxSum;
}
int main()
{

    return 0;
}