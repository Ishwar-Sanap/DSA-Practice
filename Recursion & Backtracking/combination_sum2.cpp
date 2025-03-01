#include <bits/stdc++.h>
using namespace std;

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

    // pick
    if (currSum <= target)
    {
        currSum += candidates[indx];
        temp.push_back(candidates[indx]);
        tryAllCombinations(indx + 1, currSum, temp, target, candidates, ans);
        currSum -= candidates[indx];
        temp.pop_back();

        while(indx+1 < candidates.size() && candidates[indx] == candidates[indx+1])
        {
            indx++;
        }
    }

    // non pick
    tryAllCombinations(indx + 1, currSum, temp, target, candidates, ans);
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<int> temp;
    vector<vector<int>> ans;

    // sorting the element so we can ignonre the repetating elements while calling functions.
    sort(candidates.begin(),candidates.end());
    tryAllCombinations(0, 0, temp, target, candidates, ans);

    return ans;
}

int main()
{

    vector<int> candidates = {1, 2, 3, 3, 1, 2};
    vector<vector<int>> ans = combinationSum2(candidates, 6);

    for (auto vt : ans)
    {
        for (auto ele : vt)
            cout << ele << " ";

        cout << endl;
    }

    return 0;
}