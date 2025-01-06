#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers(positive as well as negative) ,select some elements from this array(select a subset) such that:-
1. Sum of those elements is maximum(Sum of the subset is maximum) .
2. No two elements in the subset should be consecutive (i.e adjucent element are not allowed )
*/
int maxSumSubset(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 0);

    dp[0] = max(arr[0], 0); // to handle first element negative case
    dp[1] = max(arr[1], dp[0]);

    for (int i = 2; i < n; i++)
    { // select current   no select current
        dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
    }

    return dp[n - 1];
}

int main()
{

    // vector<int>arr = {2,-3,5,-8,7};
    vector<int> arr = {-2, -1, -4};
    cout << maxSumSubset(arr) << endl;

    return 0;
}