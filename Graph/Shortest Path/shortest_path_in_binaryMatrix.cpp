#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/shortest-path-in-binary-matrix/description/


class Solution
{
public:
    typedef pair<int, int> pii;
    bool isValid(int i, int j, vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] == 1)
            return false;

        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {

        int n = grid.size();

        vector<vector<int>> dist(n, vector<int>(n, 1e6));

        queue<vector<int>> qNodes;
        qNodes.push({1, 0, 0});

        while (!qNodes.empty())
        {
            auto curr = qNodes.front();
            int currDist = curr[0], ri = curr[1], ci = curr[2];
            qNodes.pop();
            if (!isValid(ri, ci, grid))
                return -1;

            if (ri == n - 1 && ci == n - 1)
                return currDist;

            // Explored the possible 8 directions
            for (int m1 = -1; m1 <= 1; m1++)
            {
                for (int m2 = -1; m2 <= 1; m2++)
                {
                    if (isValid(ri + m1, ci + m2, grid))
                    {
                        if ((currDist + 1) < dist[ri + m1][ci + m2])
                        {
                            dist[ri + m1][ci + m2] = (currDist + 1);
                            qNodes.push({dist[ri + m1][ci + m2], ri + m1, ci + m2});
                        }
                    }
                }
            }
        }

        return -1;
    }
};
int main()
{
    return 0;
}