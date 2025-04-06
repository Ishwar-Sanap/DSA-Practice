#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    int row = 1;
    while (row <= numRows)
    {
        vector<int> temp(row, 1);

        if (row <= 2)
        {
            ans.push_back(temp);
        }
        else
        {

            for (int i = 1; i < row - 1; i++)
            {
                temp[i] = ans[row - 2][i - 1] + ans[row - 2][i];
            }
            ans.push_back(temp);
        }
        row++;
    }

    return ans;
}

int main()
{

    return 0;
}