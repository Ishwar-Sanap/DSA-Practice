#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    int i = 0, n = intervals.size();

    // sorted based on start incresing order, since all starting element came first and easy to find merging intervals
    sort(intervals.begin(), intervals.end());

    while (i < n)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];

        // merging overlapping interval
        if (intervals[i][0] <= end)
        {
            while (i < n && intervals[i][0] <= end)
            {
                end = max(end, intervals[i][1]);
                i++;
            }
        }
        else
        {
            i++;
        }

        ans.push_back({start, end});
    }

    return ans;
}

int main()
{

    return 0;
}