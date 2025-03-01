#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/combination-sum/description/
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]

Candidtas = [1,2,3,4,5] , target = 5

1 1 1 1 1 
1 1 1 2 
1 1 3
1 2 2
1 4
1 2 2
1 4
2 3
5

*/

void tryAllCombinations(int indx, int currSum, vector<int> temp, int target, vector<int> &candidates, vector<vector<int>> &ans)
{
    if (indx == candidates.size())
    {
        if (currSum == target)
        {
            ans.push_back(temp);
        }
        return;
    }

    // pick unlimited time current index
    if (currSum <= target)
    {
        currSum += candidates[indx];
        temp.push_back(candidates[indx]);
        tryAllCombinations(indx, currSum, temp, target, candidates, ans);
        currSum -= candidates[indx];
        temp.pop_back();
    }

    // non pick
    tryAllCombinations(indx + 1, currSum, temp, target, candidates, ans);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    tryAllCombinations(0, 0, temp, target, candidates, ans);
    return ans;
}

int main()
{

    vector<int> candidates = {1, 2, 3, 4, 5};
    vector<vector<int>> ans = combinationSum(candidates, 5);

    for (auto vt : ans)
    {
        for (auto ele : vt)
            cout << ele << " ";

        cout << endl;
    }

    return 0;
}