#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/combinations/description/
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
You may return the answer in any order.
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]

*/

/*

Note: 
The loop-based approach is generally more efficient and cleaner because the loop takes care of moving to the next index automatically.

The take/not-take approach is useful for subset problems, where you need to include/exclude elements explicitly.

both approaches works similar

*/

int cntFnCall = 0;

void tryAllPossibleWay2(int start, int k, int n, vector<int> &temp, vector<vector<int>> &ans)
{

    if (temp.size() == k)
        ans.push_back(temp);

    if (start > n)
    {
        return;
    }

    for (int i = start; i <= n; i++)
    {   
        //take
        if (temp.size() < k)
        {
            temp.push_back(i);
            tryAllPossibleWay2(i + 1, k, n, temp, ans);
            temp.pop_back();
        }

        //non take call is done when loop iterates further
    }
}

void tryAllPossibleWay1(int i, int k, int n, vector<int> &temp, vector<vector<int>> &ans)
{

    if (i > n)
    {
        if (temp.size() == k)
            ans.push_back(temp);

        return;
    }

    // take
    if (temp.size() < k)
    {
        temp.push_back(i);
        tryAllPossibleWay2(i + 1, k, n, temp, ans);
        temp.pop_back();
    }

    // non take
    tryAllPossibleWay1(i + 1, k, n, temp, ans);
}
vector<vector<int>> combine(int n, int k)
{

    vector<int> temp;
    vector<vector<int>> ans;

    tryAllPossibleWay1(1, k, n, temp, ans);

    return ans;
}

int main()
{
    vector<vector<int>> ans = combine(3, 2);

    cout<<cntFnCall<<endl;

    for (auto vt : ans)
    {
        for (auto ele : vt)
            cout << ele << " ";

        cout << endl;
    }

    return 0;
}