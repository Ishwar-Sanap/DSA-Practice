#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool comp(vector<int> &ele1, vector<int> &ele2)
    {
        return ele1[1] < ele2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {

        /*
        if two intervals overlap, remove the one that ends later because keeping the shorter interval increases room for more intervals to be theres, and we need minimum removals..
		
		- Sorting the intervals based on end, in incresing order helps to minimize the removals

        */
        sort(intervals.begin(), intervals.end(), comp); // incresing order based on end

        int n = intervals.size();
        int start = intervals[0][0];
        int end = intervals[0][1];

        int removeCnt = 0;
        for (int i = 1; i < n; i++)
        {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            if (currStart < end) // overlapping found
                removeCnt++;
            else
                end = currEnd;
        }

        return removeCnt;
    }
};

int main()
{

    return 0;
}