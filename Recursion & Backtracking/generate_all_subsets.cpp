#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/subsets/description/
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

//T.C --> O(2^N)  S.C -- > O(N)
void generateAll(int index, int n, vector<int> &nums, vector<int>&temp,vector<vector<int>> &ans )
{
    if(index >= n)
    {
        ans.push_back(temp);
        return ;
    }

    //take index
    temp.push_back(nums[index]);
    generateAll(index+1,n,nums,temp,ans);
    temp.pop_back();  // make sure to remove current element for further calls.

    // not take index
    generateAll(index+1,n,nums,temp,ans);

}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    int index = 0;
    int n = nums.size();

    vector<int> temp;

    generateAll(index,n,nums,temp,ans);

    return ans;
}
int main()
{
    vector<int>nums = {1,2,3};
    vector<vector<int>>ans = subsets(nums);

    for(auto vt: ans)
    {
        for(auto ele : vt)
            cout<<ele <<" ";
        
        cout<<endl;
    }
    return 0;
}