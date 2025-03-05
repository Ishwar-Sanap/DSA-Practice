#include <bits/stdc++.h>
using namespace std;
/*
Time Complexity :  n!
    For the first col, we have N choices.
    For the second col, we have at most N-1 choices (since one row is occupied).
    For the third col, at most N-2 choices, and so on.
    
Space complexity : O(N) (for the recursion stack and row tracking arrays)


*/

bool canPlaceQueen(int row, int col, int n, vector<string> &board)
{
    // vertically ther should not be any placed queen it not required to check, since we plcing one by one queen
    //  from top to bottom.

    // horizontally there should not be any placed queen
    for (int j = 0; j < n; j++)
    {
        if (board[row][j] == 'Q')
            return false;
    }

    // diagonnaly there should not be any placed queen
    int i = row, j = col;
    while (i >= 0 && j >= 0) // going upper side
    {
        if (board[i][j] == 'Q')
            return false;
        i--;
        j--;
    }

    i = row, j = col;
    while (i < n && j >= 0) // going downward side
    {
        if (board[i][j] == 'Q')
            return false;
        i++;
        j--;
    }

    return true; // queen can be placed..
}

// trying to place queen's in column wise manner..
// if at any perticular column we not able to place queen in any cell, the backtrack, to previos state, remove
// that placing queen and try placing in further row's of same column.
void tryAllPossibleWaysToPlaceQ(int Col_index, int n, vector<string> &board, vector<vector<string>> &ans)
{
    if (Col_index == n)
    {
        ans.push_back(board);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (canPlaceQueen(i, Col_index, n, board))
        {
            board[i][Col_index] = 'Q';
            tryAllPossibleWaysToPlaceQ(Col_index + 1, n, board, ans); // go for nex column to place queen.
            board[i][Col_index] = '.';                                // backtrack to previous state.
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    string str(n, '.');
    vector<string> board(n, str); // Initially all cells in borad are empty..
    int Col_index = 0;
    tryAllPossibleWaysToPlaceQ(Col_index, n, board, ans);
    return ans;
}

int main()
{
    vector<vector<string>> ans = solveNQueens(4);

    for (auto boards : ans)
    {
        for (string str : boards)
            cout << str << " ";

        cout << endl;
    }

    return 0;
}