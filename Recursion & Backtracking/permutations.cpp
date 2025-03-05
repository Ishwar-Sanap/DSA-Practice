#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/permutations/description/
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

//T.C --> N! * N
void tryAllWays1(vector<int> &nums, unordered_set<int> &st, vector<int> &temp, vector<vector<int>> &ans)
{
    if (st.size() == nums.size())
    {
        // we can directly take elemetn from set and store it into ans, but unordered set don't follow number sequences
        // so we may get differnet orders of element so use temporary array also.
        ans.push_back(temp);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        int ele = nums[i];
        if (st.find(ele) == st.end()) // not alredy taken
        {
            st.insert(ele);
            temp.push_back(ele);
            tryAllWays1(nums, st, temp, ans);
            st.erase(ele); // backtrack
            temp.pop_back();
        }
    }
}


//T.C --> N!
void tryAllWays2(int index, vector<int> &nums, vector<vector<int>> &ans)
{
    if (index == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[i], nums[index]);
        tryAllWays2(index + 1, nums, ans);
        swap(nums[i], nums[index]); // bactrack to previous state
    }
}

vector<vector<int>> permute(vector<int> &nums)
{

    vector<vector<int>> ans;
    unordered_set<int> st;
    vector<int> temp;
    tryAllWays2(0, nums, ans);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans = permute(nums);

    for (auto vt : ans)
    {
        for (auto ele : vt)
            cout << ele << " ";

        cout << endl;
    }
    return 0;
}