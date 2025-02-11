#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/find-median-from-data-stream/description/

The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
*/
class MedianFinder
{
public:
    // 1 2 3 4 5 6
    // -2 -3 -1 stream

    priority_queue<int> leftSideMax;
    priority_queue<int, vector<int>, greater<int>> RightSideMin;
    MedianFinder()
    {
    }

    void addNum(int num)
    {

        if (leftSideMax.empty() || num < leftSideMax.top())
            leftSideMax.push(num);
        else
            RightSideMin.push(num);

        // always make sure lefSide pq will have larger size to handle
        // odd no of elements cases
        int n1 = leftSideMax.size();
        int n2 = RightSideMin.size();

        if (n1 - n2 > 1) // multiple smaller element
        {
            RightSideMin.push(leftSideMax.top());
            leftSideMax.pop();
        }
        else if (n2 > n1)
        {
            leftSideMax.push(RightSideMin.top());
            RightSideMin.pop();
        }
    }

    double findMedian()
    {

        int n1 = leftSideMax.size();
        int n2 = RightSideMin.size();

        if ((n1 + n2) % 2 == 0) // even  no of elements
            return (leftSideMax.top() + RightSideMin.top()) / 2.0;

        else // odd no of elements
            return leftSideMax.top();
    }
};

int main()
{

    return 0;
}