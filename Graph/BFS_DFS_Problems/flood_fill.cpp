#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/flood-fill/

bool isValidMove(int i, int j, vector<vector<int>> &image, int baseColor)
{
    int n = image.size(), m = image[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m || image[i][j] != baseColor)
        return false;
    return true;
}
void bfs(int i, int j, vector<vector<int>> &image, int baseColor, int Newcolor)
{
    queue<pair<int, int>> qNodes;
    qNodes.push({i, j});

    while (!qNodes.empty())
    {
        i = qNodes.front().first;
        j = qNodes.front().second;

        qNodes.pop();

        // updating color
        image[i][j] = Newcolor;

        // Check Horizontal
        if (isValidMove(i, j - 1, image, baseColor))
            qNodes.push({i, j - 1});

        if (isValidMove(i, j + 1, image, baseColor))
            qNodes.push({i, j + 1});

        // check Vertical
        if (isValidMove(i - 1, j, image, baseColor))
            qNodes.push({i - 1, j});

        if (isValidMove(i + 1, j, image, baseColor))
            qNodes.push({i + 1, j});
    }
}

// T.C --> O(N * M)
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{

    int n = image.size(), m = image[0].size();
    int baseColor = image[sr][sc];
    if (baseColor != color)
        bfs(sr, sc, image, baseColor, color);
    return image;
}
int main()
{
    return 0;
}