
#include <bits/stdc++.h>
using namespace std;
/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6

*/

class Solution {
public:
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>>SumMatrix(n, vector<int>(m,0) );

        int maxArea = 0;
        for(int col = 0; col < m ; col++)
        {
            int currSum = 0;
            for(int row = 0; row<n; row++)
            {
                if(matrix[row][col] == '1')
                    currSum += 1;
                else
                    currSum = 0;
                
                SumMatrix[row][col] = currSum;
            }
        }

        for(int row = 0; row<n; row++)
        {
            int rowArea = largestRectangleArea(SumMatrix[row]);
            maxArea = max(maxArea , rowArea);
        }

        return maxArea;
    }
};



int main()
{

    return 0;
}