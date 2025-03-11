#include <bits/stdc++.h>
using namespace std;

// Given an array of digit strings nums and a digit string target, return the number of pairs of indices (i, j) (where i != j) such that the concatenation of nums[i] + nums[j] equals target.

 

// Example 1:

// Input: nums = ["777","7","77","77"], target = "7777"
// Output: 4
// Explanation: Valid pairs are:
// - (0, 1): "777" + "7"
// - (1, 0): "7" + "777"
// - (2, 3): "77" + "77"
// - (3, 2): "77" + "77"

int numOfPairs(vector<string> &nums, string target)
{

    int n = nums.size();
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }

    int cnt = 0;
    for (string prefix : nums)
    {
        int n = prefix.length();
        if (prefix.length() >= target.length())
            continue;

        string suffix = target.substr(n); // start from nth index to end of the target string
        if (prefix == target.substr(0, n)) // prefix is mathcing with the target prefix part
        {
            if (mp.find(suffix) != mp.end())
            {
                if (prefix == suffix)
                    cnt += mp[suffix] - 1;

                else
                    cnt += mp[suffix];
            }
        }
    }
    return cnt;
}
int main()
{
    vector<string> num = {"12" , "13" , "1" , "213" , "12" , "31"};
    cout<<numOfPairs(num, "1213")<<endl;


    return 0;
}