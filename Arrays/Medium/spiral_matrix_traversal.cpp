#include <bits/stdc++.h>
using namespace std;

// T.C O(N*M)
vector<int> spiralOrder(vector<vector<int>> &matrix)
{

    vector<int> ans;
    int n = matrix.size(), m = matrix[0].size();

    int startRow = 0, startCol = 0;
    int endRow = matrix.size() - 1, endCol = matrix[0].size() - 1;

    int visited = 0;
    while (visited < n * m)
    {
        // go left

        for (int j = startRow; j <= endCol && visited < n * m; j++, visited++)
            ans.push_back(matrix[startRow][j]);

        startRow++;

        // go bottom
        for (int i = startRow; i <= endRow && visited < n * m; i++, visited++)
            ans.push_back(matrix[i][endCol]);

        endCol--;
        // go right
        for (int j = endCol; j >= startCol && visited < n * m; j--, visited++)
            ans.push_back(matrix[endRow][j]);

        endRow--;

        // go up

        for (int i = endRow; i >= startRow && visited < n * m; i--, visited++)
            ans.push_back(matrix[i][startCol]);

        startCol++;
    }

    return ans;
}

int main()
{

    return 0;
}
