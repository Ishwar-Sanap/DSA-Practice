#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array arr[] of size n. The array elements represent n coins of values v1, v2, ....vn.
You play against an opponent in an alternating way. In each turn, a player selects either the first or last coin from the row, removes it from the row permanently, and receives the coin's value.
You need to determine the maximum possible amount of money you can win if you go first.
Note: Both the players are playing optimally.

Examples:

Input: arr[] = [5, 3, 7, 10]
Output: 15
Explanation: The user collects the maximum value as 15(10 + 5). It is guaranteed that we cannot get more than 15 by any possible moves.

https://www.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1?page=1&sortBy=submissions 
*/

int tryAllWays(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (i == j)
        return dp[i][j] = arr[i];
    if (i + 1 == j)
        return dp[i][j] = max(arr[i], arr[j]);

    // if you pick left ith element, then opponent will pick either from left side (i+1)th element or from right side (jth)element
    // assume both the cases and explore recursion for next your turn on remaining portion
    // opponent will try to give you min value since  he will play optimally

    int pickLeft = arr[i] + min(tryAllWays(i + 2, j, arr, dp), tryAllWays(i + 1, j - 1, arr, dp));

    // if you pick right side jth element then opponent will pick either from right side (j-1)th element or from left side (ith) element
    // assuming both cases and explore recursion for next your turn on remaining portion
    //
    int pickRight = arr[j] + min(tryAllWays(i, j - 2, arr, dp), tryAllWays(i + 1, j - 1, arr, dp));

    return dp[i][j] = max(pickLeft, pickRight);
}
int maximumAmount(vector<int> &arr)
{
    // code here

    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return tryAllWays(0, n - 1, arr, dp);
}
int main()
{

    return 0;
}