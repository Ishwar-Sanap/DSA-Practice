#include <bits/stdc++.h>
using namespace std;

/*
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
*/

void rotate(vector<vector<int>>& matrix) {
        
    int n = matrix.size();

    // find Transpose of matrix, i.e changing row into columns
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<n; j++)
        {
            if(j > i)
                swap(matrix[i][j], matrix[j][i]);
        }
    }

    // now reverse the rows:
    for(int row =0; row < n; row++)
    {
        int i = 0, j = n-1;
        while(i < j)
        {
            swap(matrix[row][i], matrix[row][j]);
            i++;
            j--;
        }
    } 
}


int main()
{

    return 0;
}