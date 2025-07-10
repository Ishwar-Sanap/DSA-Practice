#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/surrounded-regions/description/ 
class Solution
{
public:
    vector<vector<int>> visited;
    bool isSafe(int sr, int sc, vector<vector<char>> &board)
    {
        int n = board.size(), m = board[0].size();
        if (sr < 0 || sc < 0 || sr >= n || sc >= m)
            return false;
        return true;
    }
    void dfs(int sr, int sc, vector<vector<char>> &board)
    {
        visited[sr][sc] = 1;
        if (board[sr][sc] == 'X')
            return;

        // Explore 4 directions

        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < 4; i++)
        {
            int nri = dir[i][0] + sr;
            int nci = dir[i][1] + sc;

            if (isSafe(nri, nci, board) && !visited[nri][nci])
            {
                dfs(nri, nci, board);
            }
        }
    }
    void solve(vector<vector<char>> &board)
    {

        int n = board.size(), m = board[0].size();
        visited.assign(n, vector<int>(m, 0));

        // Traverse through the every boundry and mark 0 as visited, as depth we can go..

        // Horizontal boundarie
        for (int j = 0; j < m; j++)
        {
            if (!visited[0][j])
                dfs(0, j, board);

            if (!visited[n - 1][j])
                dfs(n - 1, j, board);
        }

        // vertical boundarie
        for (int i = 0; i < n; i++)
        {
            if (!visited[i][0])
                dfs(i, 0, board);

            if (!visited[i][m - 1])
                dfs(i, m - 1, board);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j])
                    board[i][j] = 'X';
            }
        }
    }
};

int main()
{
    return 0;
}