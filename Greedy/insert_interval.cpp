#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{

    int n = intervals.size();
    vector<vector<int>>ans;

    int i = 0;
    // left part non overlapping
    while(i <n && intervals[i][1] < newInterval[0])
    {
        ans.push_back(intervals[i]);
        i++;
    }

    // handling overlapping part
    while(i < n && intervals[i][0] <= newInterval[1] )
    {
        newInterval[0] = min(intervals[i][0],newInterval[0]);
        newInterval[1] = max(intervals[i][1],newInterval[1]);
        i++;
    }
    ans.push_back(newInterval);

    // right part non overlapping
    while(i < n)
    {
        ans.push_back(intervals[i]);
        i++;
    }
    
    return ans;
}

int main()
{

    return 0;
}