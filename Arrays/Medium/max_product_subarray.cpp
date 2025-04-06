
#include <bits/stdc++.h>
using namespace std;

/*
[2,1,-2,4,-1,-5]
maxProduct = 20 
*/

int maxProduct(vector<int> &nums)
{

    int n = nums.size();
    int ans = INT_MIN, currProd = 1;

    for (int i = 0; i < n; i++)
    {
        currProd = currProd * nums[i];
        ans = max(currProd, ans);

        if (currProd == 0)
            currProd = 1;
    }

    currProd = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        currProd = currProd * nums[i];
        ans = max(currProd, ans);
        if (currProd == 0)
            currProd = 1;
    }

    return ans;
}

int main()
{

    return 0;
}