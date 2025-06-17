#include <bits/stdc++.h>
using namespace std;

// Tabulation
int lengthOfLIS_T(vector<int> &nums)
{

    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // i --> 0 : n
    // p --> -1 : n-1
    for (int i = n - 1; i >= 0; i--)
    {
        for (int prevIndx = i - 1; prevIndx >= -1; prevIndx--)
        {
            int pick = 0, notPick = 0;

            if (prevIndx == -1 || nums[i] > nums[prevIndx])
                pick = 1 + dp[i + 1][i + 1];

            notPick = 0 + dp[i + 1][prevIndx + 1];

            dp[i][prevIndx + 1] = max(pick, notPick);
        }
    }

    /********* Printing the LIS ********** */

    vector<int> lis;
    int indx = 0, preIndx = -1;

    // Resonstructing the dp i.e backtracing how DP table is filled up initially and accordingly storing values

    while (indx < n)
    {
        if (preIndx == -1 || nums[indx] > nums[preIndx])
        {
            int pick = dp[indx + 1][indx + 1];
            int notPick = dp[indx + 1][preIndx + 1];

            if (pick >= notPick)
            {
                lis.push_back(nums[indx]);
                preIndx = indx;
            }
        }

        // Move to next index always
        indx++;
    }

    /********* Printing the LIS ********** */
    for (int ele : lis)
    {
        cout << ele << " ";
    }
    cout << "\n\n";

    return dp[0][0];
}

// Printing the LIS using Tabulation Algorithm
void printLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> hash(n, 1); // hash array to back trace the LIS

    int maxLen = 0, maxLenIndx = -1;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i; // initialize with current index i

        for (int prev = 0; prev < i; prev++)
        {
            if (nums[i] > nums[prev])
            {
                if ((1 + dp[prev]) > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
        }

        if (dp[i] > maxLen)
        {
            maxLen = dp[i];
            maxLenIndx = i;
        }
    }

    vector<int> ans;
    ans.push_back(nums[maxLenIndx]);

    // back tracing the compute dp array using hash array..
    while (hash[maxLenIndx] != maxLenIndx)
    {
        maxLenIndx = hash[maxLenIndx];
        ans.push_back(nums[maxLenIndx]);
    }

    reverse(ans.begin(), ans.end());

    for (int ele : ans)
        cout << ele << " ";
}

int main()
{
    vector<int> arr = {12, 4, 11, 1, 16, 8};

    cout << lengthOfLIS_T(arr) << endl;
    printLIS(arr);

    return 0;
}