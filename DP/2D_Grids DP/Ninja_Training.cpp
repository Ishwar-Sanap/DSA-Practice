#include <bits/stdc++.h>
using namespace std;

/*
https://www.naukri.com/code360/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&leftPanelTabValue=PROBLEM

For Example
If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ]
the answer will be 11 as 5 + 3 + 3.
*/

// Memoization approach
// T.C --> O(N*4)*3 , S.C --> O(N) + O(N*4)
int tryAllWays(int dayIndx, int actvtyIndx, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (dayIndx < 0)
        return 0;

    int maxMeritPoints = 0;

    if (dp[dayIndx][actvtyIndx] != -1)
        return dp[dayIndx][actvtyIndx];

    // try for each activity
    for (int i = 0; i < 3; i++)
    {
        // Ninja can't perform same activity on consequetive day
        if (i == actvtyIndx)
            continue;

        int meritPoints = points[dayIndx][i] + tryAllWays(dayIndx - 1, i, points, dp);

        maxMeritPoints = max(maxMeritPoints, meritPoints);
    }

    //Maximum points till given day with actvtyIndx of previous day
    return dp[dayIndx][actvtyIndx] = maxMeritPoints;
}

// Tabulation T.C--> O(N*4)*3 , S.C -->  O(N*4)
int tryAllWays(vector<vector<int>> &points)
{
    int n = points.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));

    // base conditions 
    //build from observations when there is single day..
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

    for (int dayIndx = 1; dayIndx < n; dayIndx++)
    {
        // this represet the last activtiy index
        for (int actvtyIndx = 0; actvtyIndx < 4; actvtyIndx++)
        {
            int maxMeritPoints = 0;

            // For each activity
            for (int i = 0; i < 3; i++)
            {
                if (actvtyIndx == i)
                    continue;

                int meritPoints = points[dayIndx][i] + dp[dayIndx - 1][i];
                maxMeritPoints = max(maxMeritPoints, meritPoints);
            }

            dp[dayIndx][actvtyIndx] = maxMeritPoints;
        }
    }

    return dp[n - 1][3];
}

// Space Optimization :  T.C--> O(N*4)*3 , S.C -->  O(4)
int ninjaTraining_Optimized(vector<vector<int>> &points)
{
    int n = points.size();
    vector<int> prev(n, -1);

    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max({points[0][0], points[0][1], points[0][2]});

    for (int dayIndx = 1; dayIndx < n; dayIndx++)
    {
        vector<int> temp(4, 0);
        // this represet the last activtiy index
        for (int actvtyIndx = 0; actvtyIndx < 4; actvtyIndx++)
        {
            int maxMeritPoints = 0;

            // For each activity
            for (int i = 0; i < 3; i++)
            {
                if (actvtyIndx == i)
                    continue;

                int meritPoints = points[dayIndx][i] + prev[i];
                maxMeritPoints = max(maxMeritPoints, meritPoints);
            }

            temp[actvtyIndx] = maxMeritPoints;
        }

        prev = temp;
    }

    return prev[3];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.

    vector<vector<int>> dp(n, vector<int>(4, -1));

    int ans = tryAllWays(n - 1, 3, points, dp);
    int ans = tryAllWays(points);

    return ans;
}
int main()
{

    return 0;
}