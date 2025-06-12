#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

/*
On each day, you may decide to buy and/or sell the stock. You can only hold at
most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

*/

// Memoizatino : T.C --> O(N * 2)  S.C --> O(N) + O(N * 2)
// n is the number of days (i.e., prices.size()).
// 2 represents the two possible states of canBuyStock — either 1 (you can buy) or 0 (you must sell).

int tryAllWays(int indx, int canBuyStock, vector<int> &prices, vector<vector<int>> &dp)
{
    // base case
    if (indx == prices.size())
        return 0;

    if (dp[indx][canBuyStock] != -1)
        return dp[indx][canBuyStock];

    if (canBuyStock)
    {
        // stock is buy,  buying new stock we must sell current stock.. so next buy is not possible
        int buy = -prices[indx] + tryAllWays(indx + 1, 0, prices, dp);

        // at this day there is chance to buy stock, but we are not intrested to buy the stock
        int skip = 0 + tryAllWays(indx + 1, 1, prices, dp);

        return dp[indx][canBuyStock] = max(buy, skip);
    }
    else
    {

        // we have sell the current holding stock, so, next stock buy is possible..
        int sell = prices[indx] + tryAllWays(indx + 1, 1, prices, dp);

        // at this day not intrested to sell the stock
        int skip = 0 + tryAllWays(indx + 1, 0, prices, dp);

        return dp[indx][canBuyStock] = max(sell, skip);
    }
}

// Converting into Tabulation
int maxProfit_T(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));

    // base case
    dp[n][0] = dp[n][1] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        // for (int canBuy = 0; canBuy < 2; canBuy++)
        // {
        //     if (canBuy)
        //     {
        //         int buy = -prices[i] + dp[i + 1][0];
        //         int skip = 0 + dp[i + 1][1];

        //         dp[i][canBuy] = max(buy, skip);
        //     }
        //     else
        //     {

        //         // selling the stock
        //         int sell = prices[i] + dp[i + 1][1];

        //         int skip = 0 + dp[i + 1][0];

        //         dp[i][canBuy] = max(sell, skip);
        //     }
        // }

        // canBuy only have 2 states so we can ommit the for loop as well

        int buy = -prices[i] + dp[i + 1][0];
        int skip = 0 + dp[i + 1][1];

        dp[i][1] = max(buy, skip);

        // selling the stock
        int sell = prices[i] + dp[i + 1][1];

        skip = 0 + dp[i + 1][0];

        dp[i][0] = max(sell, skip);
    }

    return dp[0][1];
}

// Space optimization 
//    // Recursion --->>> to O(N) T.C and O(1) space optimization
int maxProfit_OP(vector<int> &prices)
{
    int n = prices.size();
    int nextSell = 0, nextBuy = 0, currSell = 0, currBuy = 0;

    for (int i = n - 1; i >= 0; i--)
    {

        // canBuy the stock
        int buy = -prices[i] + nextSell;
        int skip = 0 + nextBuy;

        currBuy = max(buy, skip);

        // selling the stock
        int sell = prices[i] + nextBuy;
        skip = 0 + nextSell;

        currSell = max(sell, skip);

        nextSell = currSell;
        nextBuy = currBuy;
    }

    return nextBuy;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return tryAllWays(0, 1, prices, dp);
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    // vector<int> prices = {1, 2, 3, 4, 5};

    cout << maxProfit(prices) << endl;

    return 0;
}