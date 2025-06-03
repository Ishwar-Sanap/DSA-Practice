#include <bits/stdc++.h>
using namespace std;

/*
https://www.geeksforgeeks.org/problems/rod-cutting0840/1

Given a rod of length n inches and an array price[], where price[i] denotes the value of a piece of length i. Your task is to determine the maximum value obtainable by cutting up the rod and selling the pieces.

Note: n = size of price, and price[] is 1-indexed array.
Input: price[] = [1, 5, 8, 9, 10, 17, 17, 20]
Output: 22
Explanation: The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5 + 17 = 22.
*/

/*
- Function parameters,
        index --> represent the piece length
        rodLength --> currentRod length remaining after cutting the rod

*/
int cutRod(vector<int> &price)
{
    // code here
    int n = price.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    // we can cut rod into 1 to n  pieces...
    // base cases..

    for (int i = 0; i < n; i++) // pieces length
    {
        for (int rodLength = 1; rodLength <= n; rodLength++)
        {
            // base case..
            if (i == 0)
            {
                dp[0][rodLength] = price[0] * rodLength;
                continue;
            }

            int pick = 0, notpick = 0;
            if ((i + 1) <= rodLength)                         // (i+1), since they have mentioned to use 1 based indexing
                pick = price[i] + dp[i][rodLength - (i + 1)]; // we can break rod of same pieces len multiple times

            notpick = dp[i - 1][rodLength];

            dp[i][rodLength] = max(pick, notpick);
        }
    }

    return dp[n - 1][n];
}

int cutRod_OP(vector<int> &price)
{
    // code here
    int n = price.size();
    vector<int> prevRow(n + 1, 0);
    vector<int> currRow(n + 1, 0);

    // we can cut rod into 1 to n  pieces...
    // base cases..

    for (int i = 0; i < n; i++)
    {
        for (int rodLength = 1; rodLength <= n; rodLength++)
        {
            // base case..
            if (i == 0)
            {
                currRow[rodLength] = price[0] * rodLength;
                continue;
            }

            int pick = 0, notpick = 0;
            if ((i + 1) <= rodLength)                           // (i+1), since they have mentioned to use 1 based indexing
                pick = price[i] + currRow[rodLength - (i + 1)]; // we can break rod of same pieces len multiple times

            notpick = prevRow[rodLength];

            currRow[rodLength] = max(pick, notpick);
        }

        prevRow = currRow;
    }

    return prevRow[n];
}
int main()
{
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    // cout << cutRod(price);
    cout << cutRod_OP(price);
    return 0;
}