#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/word-search/description/

Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
*/

// T.C --> O(m * n * 4 ^k) , k is length of word
// s.c --> O(k) (due to recursion depth of k, where k is the word length)
bool findWord(int indx, int row, int col, string &word, vector<vector<char>> &board)
{
    if (indx == word.length())
        return true;

    // check out of bound conditions
    if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
        return false;

    // cheking board charcter is matching with word of index char
    if (board[row][col] != word[indx])
        return false;

    // marked it as visited, to avoid, duplicacy, repeted function call, and selecting already choosen elements
    char temp = board[row][col];
    board[row][col] = '#';

    // try seraching in all directions, either any of the fucntion call find's the word return true.
    bool res = false;
    res = res || findWord(indx + 1, row - 1, col, word, board); // up
    res = res || findWord(indx + 1, row, col + 1, word, board); // right
    res = res || findWord(indx + 1, row + 1, col, word, board); // down
    res = res || findWord(indx + 1, row, col - 1, word, board); // left

    // backtrack to original state
    board[row][col] = temp;

    return res;
}
bool exist(vector<vector<char>> &board, string word)
{
    if (word.size() == 0)
        return true;

    int n = board.size(), m = board[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (word[0] == board[i][j])
            {
                // if from current ith row and jth column word is found
                bool res = findWord(0, i, j, word, board);
                if (res)
                    return true;
            }
        }
    }

    return false;
}
int main()
{

    return 0;
}