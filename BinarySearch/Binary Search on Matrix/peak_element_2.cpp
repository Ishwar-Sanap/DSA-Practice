#include <bits/stdc++.h>
using namespace std;

/*
A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each ce

[
[1,2,5,1,4,5],
[2,9,3,2,3,2],
[1,7,6,0,1,3],
[3,6,2,3,7,2]
]

output : {1,1} --> 9 is peak element
There can be many peak elements return any one of them..
*/

bool getMaxElementRow(vector<vector<int>> &mat, int col)
{
    int n = mat.size(), m = mat[0].size();

    int maxEleRow = 0;
    for (int i = 0; i < n; i++)
    {
        if (mat[i][col] > mat[maxEleRow][col])
            maxEleRow = i;
    }
    return maxEleRow;
}
vector<int> findPeakGrid(vector<vector<int>> &mat)
{

    int n = mat.size(), m = mat[0].size();

    int low = 0, high = m - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int maxEleRow = getMaxElementRow(mat, mid);

        if (mid + 1 < m && mat[maxEleRow][mid + 1] > mat[maxEleRow][mid])
            low = mid + 1;
        else if (mid - 1 >= 0 && mat[maxEleRow][mid - 1] > mat[maxEleRow][mid])
            high = mid - 1;

        else
            return {maxEleRow, mid};
    }

    return {-1, -1};
}

int main()
{
    vector<vector<int>> mat = {
        {1, 2, 5, 1, 4, 5},
        {2, 9, 3, 2, 3, 2},
        {1, 7, 6, 0, 1, 3},
        {3, 6, 2, 3, 7, 2}
    };

    vector<int>res = findPeakGrid(mat);
    cout<<res[0] <<" "<<res[1]<<endl;

    return 0;
}