#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/rotting-oranges/description/
class Solution
{
public:
    vector<vector<int>> visited;
    bool isValid(int i, int j, vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] == 0 || visited[i][j] == 1)
            return false;

        return true;
    }
    int bfs(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        // Initially store all rotten oranges in queue since at 0 level, these are only rotten
        queue<pair<int, int>> qRottens;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    visited[i][j] = 1;
                    qRottens.push({i, j});
                }
            }
        }

        if (qRottens.empty())
            return 0; // no any rooten orange;
        int mins = -1;

        while (!qRottens.empty())
        {
            int size = qRottens.size();
            // to maintain the levels
            mins++; // that exploring the levels

            for (int i = 0; i < size; i++)
            {
                int row = qRottens.front().first;
                int col = qRottens.front().second;
                qRottens.pop();

                // Explore all adjacent neighbor to curr rotten orange
                // sicne ther are 4 possible directions
                int deltaRow[] = {-1, 1, 0, 0}; // up down,  left right
                int deltaCol[] = {0, 0, -1, 1}; // up down, left right

                for (int move = 0; move < 4; move++)
                {
                    int nrow = deltaRow[move] + row;
                    int ncol = deltaCol[move] + col;
                    if (isValid(nrow, ncol, grid))
                    {
                        qRottens.push({nrow, ncol});
                        visited[nrow][ncol] = 1;
                        grid[nrow][ncol] = 2;
                    }
                }
            }
        }
        return mins;
    }
    int orangesRotting(vector<vector<int>> &grid)
    {

        int n = grid.size(), m = grid[0].size();
        visited.assign(n, vector<int>(m, 0));

        int mins = bfs(grid);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // if any fresh orange remains in grid then return -1
                if (grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return mins;
    }
};
int main()
{
    return 0;
}