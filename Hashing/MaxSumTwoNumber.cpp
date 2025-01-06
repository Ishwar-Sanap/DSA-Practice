#include <bits/stdc++.h>
using namespace std;

/*
Given an array A consisting of N integers, returns the maximum sum of two numbers whose digits add up to an equal sum.
if there are not two numbers whose digits have an equal sum, the function should return -1.
Constraints: N is integer within the range [1, 200000]
each element of array A is an integer within the range [1, 1000000000]

Example1:
Input:
A = [51, 71, 17, 42]
Output: 93
Explanation: There are two pairs of numbers whose digits add up to an equal sum: (51, 42) and (17, 71), The first pair sums up to 93

A = [42, 33, 60]
Output: 102
*/

int getDigitSum(int num)
{
    int sum = 0;

    while(num > 0)
    {
        sum += num%10;
        num = num/10;
    }

    return sum;
}
int getMaxSum(vector<int>&nums)
{
    unordered_map<int, int>mp;  // it will store digit sum and number

    int ans = -1;
    for(int num : nums)
    {
        int digitSum = getDigitSum(num);

        if(mp.find(digitSum) != mp.end())
        {
            ans = max(ans, mp[digitSum] + num);

            if(num > mp[digitSum]) // storing larger number in map having same digit sum
                mp[digitSum] = num;
        }
        else 
            mp[digitSum] = num;
    }
    return ans;
}
int main()
{
    vector<int>arr = {51, 32, 43};
    cout<<getMaxSum(arr)<<endl;
    return 0;
}