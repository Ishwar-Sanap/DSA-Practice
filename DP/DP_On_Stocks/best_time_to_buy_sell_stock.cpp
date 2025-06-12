#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/
// Input: prices = [7,1,5,3,6,4]
// Output: 5

int maxProfit(vector<int> &prices)
{

    int n = prices.size();

    int maxProfit = 0, buyPrice = prices[0];
    for (int i = 0; i < n; i++)
    {
        buyPrice = min(buyPrice, prices[i]);

        maxProfit = max(maxProfit, prices[i] - buyPrice);
    }

    return maxProfit;
}

int main()
{

    return 0;
}