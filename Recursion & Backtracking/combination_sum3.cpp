#include <bits/stdc++.h>
using namespace std;
/*
https://leetcode.com/problems/combination-sum-iii/description/
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

*/

void tryAllPossibleWays(int indx, int currSum, int k , int n, vector<int>&temp,  vector<vector<int>> &ans)
{
    // we have allowed to take number from 1 to 9
    if(indx > 9){
        if(temp.size() == k && currSum == n)
            ans.push_back(temp);
        
        return;
    }

    // pick
    if(temp.size() < k)
    {
        currSum += indx;
        temp.push_back(indx);
        tryAllPossibleWays(indx+1,currSum,k,n,temp,ans);
        currSum -= indx;
        temp.pop_back();
    }

    //non pick
    tryAllPossibleWays(indx+1,currSum,k,n,temp,ans);
}

void tryAllPossibleWays2(int indx, int currSum, int k , int n, vector<int>&temp,  vector<vector<int>> &ans)
{
    if(temp.size() == k && currSum == n)
        ans.push_back(temp);


    // we have allowed to take number from 1 to 9
    for(int i = indx; i<= 9; i++)
    {
        // pick
        if(temp.size() < k)
        {
            currSum += i;
            temp.push_back(i);
            tryAllPossibleWays2(i+1,currSum,k,n,temp,ans);
            currSum -= i;
            temp.pop_back();
        }
        //non pick
        // will be done after loop counter increments
    }

}
vector<vector<int>> combinationSum3(int k, int n) 
{
    vector<vector<int>> ans;
    vector<int>temp;
    tryAllPossibleWays(1,0,k,n,temp,ans);      
    return ans;  
}

int main()
{

    return 0;
}