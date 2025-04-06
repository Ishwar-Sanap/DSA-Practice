#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/subarray-sum-equals-k/

[1,-1,2,1,3] k = 3
Output --> 3
*/
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {

        int n = nums.size();
        unordered_map<int, int> mp;

        mp[0] = 1;
        int currSum = 0;
        int cnt = 0;
        for (int ele : nums)
        {
            currSum += ele;

            int req = currSum - k;

            cnt += mp[req];

            mp[currSum]++;
        }
        return cnt;
    }
};

int main()
{

    return 0;
}