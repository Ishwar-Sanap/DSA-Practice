#include <bits/stdc++.h>
using namespace std;

// T.C  O(M^3)
int tryAllWays(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (j - i == 1)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    // we can cut the stick at given positions
    int minCost = INT_MAX;
    for (int k = i + 1; k < j; k++) // cut's index strated i+1 because at ith loction staring of stick is ther and jth ending of stick
    {
        int leftPart = tryAllWays(i, k, cuts, dp);
        int righPart = tryAllWays(k, j, cuts, dp);

        int currCost = (cuts[j] - cuts[i]) + leftPart + righPart;

        minCost = min(minCost, currCost);
    }

    return dp[i][j] = minCost;
}

// Tabulation
int minCost_T(int n, vector<int> &cuts)
{
    // Appending the stick length at the end of cut's array , so when cut's are performed we can get length of stick
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(cuts.size() + 1, vector<int>(cuts.size() + 1, 0));

    int m = cuts.size();

    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = i + 2; j < m; j++) // by consider recurisive base case started the j
        {
            int minCost = INT_MAX;
            for (int k = i + 1; k < j; k++) // cut's index strated i+1 because at ith loction staring of stick is ther and jth ending of stick
            {
                int leftPart = dp[i][k];
                int righPart = dp[k][j];

                int currCost = (cuts[j] - cuts[i]) + leftPart + righPart;

                minCost = min(minCost, currCost);
            }

            dp[i][j] = minCost;
        }
    }

    return dp[0][m - 1];
}
int minCost(int n, vector<int> &cuts)
{
    // By sorting the CUTS array, we know that at whatever point we are making the cut, the
    //  information on the markings of the left portion will always be present on the left side of
    //   the CUTS array partition. Similarly on the right side.

    // Appending the stick length at the end of cut's array , so when cut's are performed we can get length of stick
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(cuts.size() + 1, vector<int>(cuts.size() + 1, -1));

    return tryAllWays(0, cuts.size() - 1, cuts, dp);
}

int main()
{
    vector<int> cuts = {1, 3, 4, 5};

    cout << minCost(7, cuts);
    return 0;
}