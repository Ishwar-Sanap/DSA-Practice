#include <bits/stdc++.h>
using namespace std;

// You allowed to have at most 2 transcation
//You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/ 

int tryAllWays(int indx, int canBuyStock, int tsCnt, vector<int> &prices, vector<vector<vector<int>>> &dp)
{
    if (tsCnt == 0)
        return 0;
    if (indx == prices.size())
        return 0;

    if (dp[indx][canBuyStock][tsCnt] != -1)
        return dp[indx][canBuyStock][tsCnt];

    if (canBuyStock)
    {
        int buy = -prices[indx] + tryAllWays(indx + 1, 0, tsCnt, prices, dp);

        int skip = 0 + tryAllWays(indx + 1, 1, tsCnt, prices, dp);

        return dp[indx][canBuyStock][tsCnt] = max(buy, skip);
    }
    else
    {
        int sell = prices[indx] + tryAllWays(indx + 1, 1, tsCnt - 1, prices, dp); // once you sell the stock the 1 transcation is completed..

        int skip = 0 + tryAllWays(indx + 1, 0, tsCnt, prices, dp);

        return dp[indx][canBuyStock][tsCnt] = max(sell, skip);
    }
}

// Tabulation T.C O(N * 2 * 2) --> O(N * 4) --> O(N)
// S.C O(N * 2 * 3) --> O(N*6) --> O(N)

int maxProfit_T(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

    // write base case
    for (int i = n - 1; i >= 0; i--)
    {
        dp[i][0][0] = 0;
        dp[i][1][0] = 0;
    }

    // simply writing the loops in oposite direction of the recursion..
    for (int indx = n - 1; indx >= 0; indx--)
    {
        for (int canBuy = 0; canBuy <= 1; canBuy++)
        {
            for (int tsCnt = 1; tsCnt <= 2; tsCnt++)
            {
                int profit = 0;
                if (canBuy)
                {
                    int buy = -prices[indx] + dp[indx + 1][0][tsCnt];
                    int skip = 0 + dp[indx + 1][1][tsCnt];

                    dp[indx][canBuy][tsCnt] = max(buy, skip);
                }
                else
                {

                    int sell = prices[indx] + dp[indx + 1][1][tsCnt - 1]; // transctaion completed
                    int skip = 0 + dp[indx + 1][0][tsCnt];

                    dp[indx][canBuy][tsCnt] = max(sell, skip);
                }
            }
        }
    }

    return dp[0][1][2];
}

// Space optimization
int maxProfitOP(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> next(2, vector<int>(3, 0));
    vector<vector<int>> curr(2, vector<int>(3, 0));

    // simply writing the loops in oposite direction of the recursion..
    for (int indx = n - 1; indx >= 0; indx--)
    {
        for (int canBuy = 0; canBuy <= 1; canBuy++)
        {
            for (int tsCnt = 1; tsCnt <= 2; tsCnt++)
            {
                int profit = 0;
                if (canBuy)
                {
                    int buy = -prices[indx] + next[0][tsCnt];
                    int skip = 0 + next[1][tsCnt];

                    curr[canBuy][tsCnt] = max(buy, skip);
                }
                else
                {

                    int sell = prices[indx] + next[1][tsCnt - 1]; // transctaion completed
                    int skip = 0 + next[0][tsCnt];

                    curr[canBuy][tsCnt] = max(sell, skip);
                }
            }
        }

        next = curr;
    }

    return next[1][2];
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

    return tryAllWays(0, 1, 2, prices, dp);
}

int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    cout << maxProfit(prices) << endl;

    return 0;
}