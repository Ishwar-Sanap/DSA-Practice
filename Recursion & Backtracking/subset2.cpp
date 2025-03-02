#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/subsets-ii/description/
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
*/

void tryAllPossibleWays2(int indx, vector<int> &temp, vector<int> &arr, vector<vector<int>> &ans)
{
    if (indx == arr.size())
    {
        ans.push_back(temp);
        return;
    }

    // pick
    temp.push_back(arr[indx]);
    tryAllPossibleWays2(indx + 1, temp, arr, ans);
    // backtrack
    temp.pop_back();

    // ingnorning the duplicates:
    while (indx + 1 < arr.size() && arr[indx] == arr[indx + 1])
        indx++;

    // not pick
    tryAllPossibleWays2(indx + 1, temp, arr, ans);
}

void tryAllPossibleWays1(int indx, vector<int> &temp, vector<int> &arr, vector<vector<int>> &ans)
{
    ans.push_back(temp);

    for (int i = indx; i < arr.size(); i++)
    {
        // ignoring duplicates
        if (i > indx && arr[i] == arr[i - 1])
            continue;
        // pick
        temp.push_back(arr[i]);
        tryAllPossibleWays1(i + 1, temp, arr, ans);
        // backtrack
        temp.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int> &arr)
{

    vector<int> temp;
    vector<vector<int>> res;
    sort(arr.begin(), arr.end());

    tryAllPossibleWays2(0, temp, arr, res);
    return res;
}

int main()
{
    vector<int> candidates = {1, 2, 2};
    vector<vector<int>> ans = subsetsWithDup(candidates);

    for (auto vt : ans)
    {
        for (auto ele : vt)
            cout << ele << " ";

        cout << endl;
    }

    return 0;
}