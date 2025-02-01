#include <bits/stdc++.h>
using namespace std;

/*
You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

Return the sum of all subarray ranges of nums.
nums : [1,2,3]
Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
*/

vector<int> nextGreterstRight(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 0);
    stack<pair<int, int>> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top().first <= nums[i])
            st.pop();

        if (st.empty())
            ans[i] = n;
        else
            ans[i] = st.top().second;

        st.push({nums[i], i});
    }

    return ans;
}

vector<int> prevGretestLeft(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 0);
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top().first < nums[i])
            st.pop();

        if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top().second;

        st.push({nums[i], i});
    }

    return ans;
}

long long sumOfSubrrayMax(vector<int> &nums)
{
    int n = nums.size();
    vector<int> NGR = nextGreterstRight(nums);
    vector<int> PGL = prevGretestLeft(nums);

    long long totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        long long cnt = (long long)nums[i] * (NGR[i] - i);

        // how many time cnt will be repeted,,
        cnt = cnt * (i - PGL[i]);

        totalSum += cnt;
    }

    return totalSum;
}

vector<int> nextSmallestRight(vector<int> &nums)
{
    int n = nums.size();
    stack<pair<int, int>> st;
    vector<int> res(n, 0);

    for (int i = n - 1; i >= 0; i--)
    {

        while (!st.empty() && st.top().first >= nums[i])
            st.pop();

        if (st.empty())
            res[i] = n;
        else
            res[i] = st.top().second;

        st.push({nums[i], i});
    }

    return res;
}

vector<int> prevSmallestLeft(vector<int> &nums)
{
    int n = nums.size();
    stack<pair<int, int>> st;
    vector<int> res(n, 0);

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top().first > nums[i])
            st.pop();

        if (st.empty())
            res[i] = -1;
        else
            res[i] = st.top().second;

        st.push({nums[i], i});
    }

    return res;
}

long long sumOfSubrrayMin(vector<int> &nums)
{
    int n = nums.size();
    vector<int> NSR = nextSmallestRight(nums);
    vector<int> PSL = prevSmallestLeft(nums);

    long long totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        long long cnt = (long long)nums[i] * (NSR[i] - i);
        // how many time cnt will be repeted,,
        cnt = cnt * (i - PSL[i]);

        totalSum += cnt;
    }

    return totalSum;
}

long long subArrayRanges(vector<int> &nums)
{
    return sumOfSubrrayMax(nums) - sumOfSubrrayMin(nums);
}

int main()
{

    vector<int> nums = {1, 2, 3};

    cout << subArrayRanges(nums) << endl;

    return 0;
}