#include <bits/stdc++.h>
using namespace std;

/*
https://www.naukri.com/code360/problems/unbounded-knapsack_1215029?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

You need to fill the knapsack with the items in such a way that you get the maximum profit. 
You are allowed to take one item multiple times.

w' = 10,
'profit' = [5, 11, 13]
'weight' = [2, 4, 6]

output --> 27 max profit

5 + 11 + 11 = 27
*/
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.

    vector<int> prevRow(w + 1, 0);
    vector<int> currRow(w + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int cap = 0; cap <= w; cap++)
        {
            // base case..
            if (i == 0)
            {
                // storing as many proift you can earn.
                if (weight[i] <= cap)
                    currRow[cap] = profit[i] * (cap / weight[i]);

                continue;
            }

            int pick = 0, notpick = 0;
            if (weight[i] <= cap)
                pick = profit[i] + currRow[cap - weight[i]];

            notpick = 0 + prevRow[cap];

            currRow[cap] = max(pick, notpick);
        }

        prevRow = currRow;
    }

    return prevRow[w];
}

// More optimized : only single row used...
int unboundedKnapsack_OP(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.

    //    vector<int>prevRow(w+1, 0);
    vector<int> currRow(w + 1, 0);
    for (int i = 0; i < n; i++)
    {
        for (int cap = 0; cap <= w; cap++)
        {
            // base case..
            if (i == 0)
            {
                if (weight[i] <= cap)
                    currRow[cap] = profit[i] * (cap / weight[i]);

                continue;
            }

            int pick = 0, notpick = 0;
            if (weight[i] <= cap)
                pick = profit[i] + currRow[cap - weight[i]];

            notpick = 0 + currRow[cap];

            currRow[cap] = max(pick, notpick);
        }

        // prevRow = currRow;
    }

    return currRow[w];
}
int main()
{

    return 0;
}