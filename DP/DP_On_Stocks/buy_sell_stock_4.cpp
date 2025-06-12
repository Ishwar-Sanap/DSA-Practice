#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
// At most k transcations possible
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).


// Tabulation
int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

    for (int indx = n - 1; indx >= 0; indx--)
    {
        for (int canBuy = 0; canBuy <= 1; canBuy++)
        {
            for (int tsCnt = 1; tsCnt <= k; tsCnt++)
            {
                if (canBuy)
                {
                    int buy = -prices[indx] + dp[indx + 1][0][tsCnt];
                    int skip = 0 + dp[indx + 1][1][tsCnt];

                    dp[indx][canBuy][tsCnt] = max(buy, skip);
                }
                else
                {
                    int sell = prices[indx] + dp[indx + 1][1][tsCnt - 1];
                    int skip = 0 + dp[indx + 1][0][tsCnt];

                    dp[indx][canBuy][tsCnt] = max(sell, skip);
                }
            }
        }
    }

    return dp[0][1][k];
}


// Space optimization
int maxProfitOP(int k, vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> next(2, vector<int>(k + 1, 0));
    vector<vector<int>> curr(2, vector<int>(k + 1, 0));

    for (int indx = n - 1; indx >= 0; indx--)
    {
        for (int canBuy = 0; canBuy <= 1; canBuy++)
        {
            for (int tsCnt = 1; tsCnt <= k; tsCnt++)
            {
                if (canBuy)
                {
                    int buy = -prices[indx] + next[0][tsCnt];
                    int skip = 0 + next[1][tsCnt];

                    curr[canBuy][tsCnt] = max(buy, skip);
                }
                else
                {
                    int sell = prices[indx] + next[1][tsCnt - 1];
                    int skip = 0 + next[0][tsCnt];

                    curr[canBuy][tsCnt] = max(sell, skip);
                }
            }
        }

        next = curr;
    }

    return next[1][k];
}
int main()
{

    return 0;
}