#include <bits/stdc++.h>
using namespace std;
/*

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
*/

class Solution
{
public:
    struct comp
    {
                            // root ele,      pushed element
        bool operator()(pair<int, int> &ele1, pair<int, int> &ele2)
        {
            // sorting pq in decresing order based on frequencies
            // do swap
            return ele1.second < ele2.second;
        }
    };
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        unordered_map<int, int> mp;
        vector<int> res;
        for (int ele : nums)
            mp[ele]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;

        for (auto it : mp)
            pq.push({it.first, it.second});

        while (k--)
        {
            res.push_back(pq.top().first);
            pq.pop();
        }
        return res;
    }
};

int main()
{

    return 0;
}