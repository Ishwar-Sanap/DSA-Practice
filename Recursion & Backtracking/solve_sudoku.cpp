#include <bits/stdc++.h>
using namespace std;

/*
Time Complexity: O(9(n ^ 2)), in the worst case, for each cell in the n2 board, we have 9 possible numbers.

Space Complexity: O(1), since we are refilling the given board itself, there is no extra space required, so constant space complexity.
*/
bool isPossibleToPlace(char num, int row, int col, vector<vector<char>> &board)
{
    int i = 0;
    while (i < board.size())
    {
        // check horizantally there should not be num exists
        if (board[row][i] == num)
            return false;

        // check vertically there should not be num exists
        if (board[i][col] == num)
            return false;

        // check in 3*3 grid, there should not be num exists
        int rowIndex = 3 * (row / 3) + i / 3;
        int colIndex = 3 * (col / 3) + i % 3;

        if (board[rowIndex][colIndex] == num)
            return false;

        i++;
    }
    return true;
}

bool tryAllWaysToPlaceNumbers(vector<vector<char>> &board)
{
    int n = board.size(), m = board[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // at every empty place cell, we can place numbers from 1 - 9
            if (board[i][j] == '.')
            {
                for (char ch = '1'; ch <= '9'; ch++)
                {
                    if (isPossibleToPlace(ch, i, j, board))
                    {
                        board[i][j] = ch;

                        bool res = false;

                        res = tryAllWaysToPlaceNumbers(board);
                        if (res)
                            return true;

                        board[i][j] = '.'; // BACKTRACK TO PREVIOUS STATE
                    }
                }

                return false; // not any number can be placed return false..
            }
        }
    }

    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    tryAllWaysToPlaceNumbers(board);
}

int main()
{

    return 0;
}