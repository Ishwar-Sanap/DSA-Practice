#include <bits/stdc++.h>
using namespace std;
/*
You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true

If we flatten 2d array into 1D array, it will looks like sorted array, and we can apply Binary serach on it.

*/
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();

    int low = 0, high = n * m - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int ele = matrix[mid / m][mid % m];

        if (ele == target)
            return true;
        else if (ele > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return false;
}

int main()
{

    return 0;
}