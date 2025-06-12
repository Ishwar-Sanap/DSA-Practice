#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/

/*
Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

*/

int maxProfit(vector<int> &prices)
{

    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));

    // base case
    dp[n][0] = dp[n][1] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int canBuy = 0; canBuy < 2; canBuy++)
        {
            if (canBuy)
            {
                int buy = -prices[i] + dp[i + 1][0];
                int skip = 0 + dp[i + 1][1];

                dp[i][canBuy] = max(buy, skip);
            }
            else
            {

                // selling the stock, and take rest next day, buy stock nex to next day
                int sell = prices[i] + dp[i + 2][1];

                int skip = 0 + dp[i + 1][0];

                dp[i][canBuy] = max(sell, skip);
            }
        }

    }
    
    return dp[0][1];
}

    int main()
    {

        return 0;
    }
