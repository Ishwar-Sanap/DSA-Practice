#include <bits/stdc++.h>
using namespace std;

/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and
 return an array of the non-overlapping intervals that cover all the intervals in the input.

Input : [[2,3],[4,5],[6,7],[8,9],[1,10]]
output : [[1,10]]

Input : [[1,3],[2,6],[8,10],[15,18]]
Output : [[1,6],[8,10],[15,18]]

*/
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    vector<vector<int>> res;

    sort(intervals.begin(), intervals.end());

    int start = intervals[0][0];
    int end = intervals[0][1];
    for (int i = 1; i < n; i++)
    {
        if (intervals[i][0] <= end)
        {
            end = max(end, intervals[i][1]);
        }
        else
        {

            res.push_back({start, end});
            start = intervals[i][0];
            end = intervals[i][1];
        }
    }

    res.push_back({start, end});

    return res;
}
