#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

 
Input: heights = [2,1,5,6,2,3]
Output: 10
*/
int main()
{

    return 0;
}

vector<int> nextSmallestRightElementIndex(vector<int> &heights)
{
    int n = heights.size();
    vector<int> NSR(n, 0);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();

        if (st.empty())
            NSR[i] = n;
        else
            NSR[i] = st.top();

        st.push(i);
    }

    return NSR;
}
vector<int> nextSmallestLeftElementIndex(vector<int> &heights)
{
    int n = heights.size();
    vector<int> NSL(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();

        if (st.empty())
            NSL[i] = -1;
        else
            NSL[i] = st.top();

        st.push(i);
    }

    return NSL;
}
int largestRectangleArea(vector<int> &heights)
{

    vector<int> NSR = nextSmallestRightElementIndex(heights);
    vector<int> NSL = nextSmallestLeftElementIndex(heights);

    int n = heights.size();
    int maxArea = 0;
    for (int i = 0; i < n; i++)
    {
        //how many greter equal to right =  (NSR[i] - i)
        //How many greter equal to left =  (i - NSL[i] -1) 
        int currArea = heights[i] * (NSR[i] - i) + heights[i] * (i - NSL[i] - 1);
        maxArea = max(maxArea, currArea);
    }
    return maxArea;
}