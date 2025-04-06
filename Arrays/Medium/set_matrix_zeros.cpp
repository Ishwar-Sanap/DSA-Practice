#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

// T.C O(N*M)  --> S,C O(1)
     void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();

        int zeroCol = -1;
        int zeroRow = -1;

        // check 0th col has any 0 alredy  or not??
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][0] == 0)
                zeroCol = 0;
        }

        // check 0th row has any 0 alredy or not??
        for (int j = 0; j < m; j++)
        {
            if (matrix[0][j] == 0)
                zeroRow = 0;
        }

        // Imagine 0th row and 0th col as supportive extra arrys
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] == 0) // then mark 0th row and 0th col index as 0 for making zero's
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // make zeros other than 0th row and 0th column
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }

        if (zeroRow == 0)
        {
            // entire 0th row can be made zero
            for (int j = 0; j < m; j++)
            {
                matrix[0][j] = 0;
            }
        }

        if (zeroCol == 0)
        {
            // entire 0th col can be made zero
            for (int i = 0; i < n; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};
int main()
{

    return 0;
}