#include <bits/stdc++.h>
using namespace std;
/*
Problem Statement: Given a value V, if we want to make a change for V Rs, and we have an infinite 
supply of each of the denominations in Indian currency, i.e., we have an infinite supply of 
{ 1, 2, 5, 10, 20, 50, 100, 500, 1000} valued coins/notes, what is the minimum number of 
 coins and/or notes needed to make the change.
*/

int minCoins(int value)
{
    vector<int>currecny = { 1, 2, 5, 10, 20, 50, 100, 500, 1000};
    // since we want to use minimum no of denominations to make value
    //, so we try with max denominatnion vlaue first

    int ans = 0;
    int i = currecny.size()-1;

    while( i >=0 && value > 0 )
    {
        if(value >= currecny[i]) // you can use ith coin of denominatios
        {
            value -= currecny[i];
            ans++;
            continue; // try to use max no of ith coin so continue with the same coin
        }
        else
        {
            i--; // we need smaller coin
        }
    }

    return ans;

}

int main()
{
    cout<<minCoins(1900)<<endl;

    return 0;
}