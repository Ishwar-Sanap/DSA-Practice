#include <bits/stdc++.h>
using namespace std;
/*
ou are Given an integer array A of size N. Your task is to select exactly B elements from either the left end or the right end of the array A in order to maximize the sum of the selected elements.

Here are the details of the problem:

You are given an integer array A of size N where 1 <= N <= 10^5.
You need to select exactly B elements from either the left end or the right end of the array A.
The goal is to find and return the maximum possible sum of elements you can pick.

[5, -2, 3, 1, 2], 3
output : 8

4 5 8 1 2 5 4 1 3 2 10
*/
int getMaxSum(vector<int> arr, int B)
{
    int n = arr.size();
    int totalSum = 0;
    int prefixSum = 0;

    vector<int> suFixSum(n, 0);
    // right to left sum
    for (int i = n - 1; i >= 0; i--)
    {
        suFixSum[i] = (i + 1) < n ? (suFixSum[i + 1] + arr[i]) : arr[i];
    }

    int maxSum = suFixSum[n - B]; // Initilized maxSum with right picked elements

    for (int i = 0; i < B; i++)
    {
        prefixSum += arr[i];
        int indx = (n - B + i + 1); // from this index we can pick right elements

        if (indx < n)
            maxSum = max(maxSum, prefixSum + suFixSum[indx]);
    }

    return maxSum;
}
int main()
{
    vector<int> arr = {4, 5, 8, 1, 2, -2, 10};
    int B = 3;
    cout << getMaxSum(arr, B) << endl;
    return 0;
}