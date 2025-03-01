#include <bits/stdc++.h>
using namespace std;

int generateSubsequences(int index, int currSum, vector<int> &arr, int target)
{
    if (index >= arr.size())
    {
        // condition satisfised
        if (currSum == target)
            return 1;

        return 0;
    }

    // take
    int pick = 0, nonpick = 0;
    currSum += arr[index];
    if (currSum <= target)
        pick = generateSubsequences(index + 1, currSum, arr, target);

    currSum -= arr[index];
    // not take
    nonpick = generateSubsequences(index + 1, currSum, arr, target);

    return pick + nonpick;
}
int perfectSum(vector<int> &arr, int target)
{
    // code here

    int index = 0, currSum = 0, n = arr.size();

    // vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    int cnt = generateSubsequences(index, currSum, arr, target);
    return cnt;
}
int main()
{

    vector<int> arr = {5, 2, 3, 10, 6, 8};
    int target = 10;

    cout << perfectSum(arr, target) << endl;

    return 0;
}