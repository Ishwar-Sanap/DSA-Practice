#include <bits/stdc++.h>
using namespace std;

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water 
it can trap after raining.

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/
int trap(vector<int> &height)
{
    // for trapping water ON left and right it should have larger building height than current height.

    int n = height.size();

    vector<int> prefixMax(n, 0);
    vector<int> suffixMax(n, 0);

    int trappedWater = 0;

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            prefixMax[i] = height[i];
        else
            prefixMax[i] = max(height[i], prefixMax[i - 1]);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
            suffixMax[i] = height[i];
        else
            suffixMax[i] = max(height[i], suffixMax[i + 1]);
    }

    for (int i = 0; i < n; i++)
    {
        // if current height is lesser than the side building heights then only you can trap water
        if (height[i] < prefixMax[i] && height[i] < suffixMax[i])
        {
            int minBuildingHeight = min(prefixMax[i], suffixMax[i]);
            trappedWater += minBuildingHeight - height[i];
        }
    }

    return trappedWater;
}

int main()
{

    return 0;
}