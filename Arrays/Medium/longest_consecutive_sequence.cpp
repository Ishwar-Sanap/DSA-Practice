#include <bits/stdc++.h>
using namespace std;

/*
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

int longestConsecutive(vector<int> &nums)
{

    unordered_set<int> st(nums.begin(), nums.end());

    int n = nums.size();
    int i = 0;

    int ans = 0;
    while (!st.empty())
    {
        int cnt = 0;
        int ele = *st.begin();

        // check the larger consecutive numbers from sequence are exist
        int num = ele;
        while (st.find(num) != st.end())
        {
            st.erase(num);
            cnt++;
            num++;
        }

        // check the smaller consecutive numbers from sequence are exist
        num = ele - 1;
        while (st.find(num) != st.end())
        {
            st.erase(num);
            cnt++;
            num--;
        }

        ans = max(ans, cnt);
    }

    return ans;
}


int main()
{

    return 0;
}
