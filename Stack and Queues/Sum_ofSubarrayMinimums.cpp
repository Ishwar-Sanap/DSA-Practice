#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

 Input: arr = [3,1,2,4]
Output: 17
Explanation:
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
*/

vector<int> NextSmallestRight(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res(n, 0);

    stack<pair<int, int>> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top().first >= arr[i])
            st.pop();

        if (st.empty())
            res[i] = n;
        else
            res[i] = st.top().second;

        st.push({arr[i], i});
    }

    return res;
}
vector<int> PrevSmallestLeft(vector<int> &arr)
{
    int n = arr.size();
    vector<int> res(n, 0);

    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top().first > arr[i])
            st.pop();

        if (st.empty())
            res[i] = -1;
        else
            res[i] = st.top().second;

        st.push({arr[i], i});
    }

    return res;
}
int sumSubarrayMins(vector<int> &arr)
{

    int mod = 1e9 + 7;
    int n = arr.size();
    vector<int> NSR = NextSmallestRight(arr);
    vector<int> NSL = PrevSmallestLeft(arr);

    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        // current elemnet is smallest till right
        int cnt = NSR[i] - i;
        long sum = (long)arr[i] * cnt;

        // til these many time sum can be repeted
        sum = sum * (i - NSL[i]);

        totalSum = (totalSum + sum) % mod;
    }

    return totalSum;
}
int main()
{

    return 0;
}