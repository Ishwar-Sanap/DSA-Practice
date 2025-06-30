#include <bits/stdc++.h>
using namespace std;

/*
You are given two integers L and R, your task is to find the XOR of elements of the range [L, R].

Example:

Input: 
L = 4, R = 8 
Output:
8 
Explanation:
4 ^ 5 ^ 6 ^ 7 ^ 8 = 8

*/
int oneToN_XOR(int n)
{
    // based on observations:
    //observe a pattern that arises due to the cyclic behaviour of XOR operations 
    //when applied to a sequence of consecutive numbers.
    
    if (n % 4 == 0)
        return n;
    else if (n % 4 == 1)
        return 1;
    else if (n % 4 == 2)
        return n + 1;
    else if (n % 4 == 3)
        return 0;
}
int findXOR(int l, int r)
{
    // XOR of 1 to L-1  ^  XOR of 1 to R
    int ans = oneToN_XOR(l - 1) ^ oneToN_XOR(r);
    return ans;
}

int main()
{
    return 0;
}