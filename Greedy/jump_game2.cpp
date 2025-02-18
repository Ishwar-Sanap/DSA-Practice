
#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/jump-game-ii/
minimum no of jumps to reach end.

    Input: nums = [2,3,1,1,4]
    Output: 2

    Input : 3,4,5,2,1,1,2,7
    Output : 2

*/

int jump(vector<int> &nums)
{
    int jumpsCnt = 0, n = nums.size();
    int left = 0, right = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (right >= n - 1)
            return jumpsCnt;

        int currMaxPossJump = i + nums[i];
        if (currMaxPossJump > right)
        {
            if (i >= left)
            {
                left = right + 1;
                jumpsCnt++;
            }

            right = currMaxPossJump;
        }
    }

    return jumpsCnt;
}

int main()
{

    return 0;
}