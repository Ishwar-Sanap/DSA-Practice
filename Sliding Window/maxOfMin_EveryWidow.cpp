#include <bits/stdc++.h>
using namespace std;
/*
Given an array of integers arr[] of size N, the task is to find the maximum of the minimum values for every possible window size in the array, where the window size ranges from 1 to N.

More formally, for each window size k, determine the smallest element in all windows of size k, and then find the largest value among these minimums where 1<=k<=N.

// 10 20 30 50 10 70 30
// 70 30 20 10 10 10 10 Output

*/


vector<int> maxOfMinBruteForce(vector<int> &arr)
{
    // Your code here
    int n = arr.size();
    vector<int>res(n, 0);

    for(int i = 0; i<n; i++)
    {   
        int minEle = INT_MAX;
        for(int j = i; j<n; j++)
        {
            minEle = min(minEle, arr[j]);
            res[j-i] = max(minEle,res[j-i]);
        }
    }
    return res;
}

int main()
{

    return 0;
}