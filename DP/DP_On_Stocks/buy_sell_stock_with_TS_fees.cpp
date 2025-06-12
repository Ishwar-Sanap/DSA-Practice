#include <bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note:

You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

*/

int maxProfit(vector<int> &prices, int fee)
{

    // you are allowed tod do multiple transcations but you need to pay fee per transcation

    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    for (int i = n - 1; i >= 0; i--)
    {
        // can buy
        int buy = -prices[i] + dp[i + 1][0];
        int skipBuy = 0 + dp[i + 1][1];
        dp[i][1] = max(buy, skipBuy);

        // must sell
        int sell = (prices[i] + dp[i + 1][1]) - fee; // trascation is done.. pay fees
        int skipSell = 0 + dp[i + 1][0];

        dp[i][0] = max(sell, skipSell);
    }

    return dp[0][1];
}

// we can optimized the space since every time next and curr row is used..
// vector<int>next(2,0)  vector<int>curr(2,0)

int main()
{

    return 0;
}