#include <bits/stdc++.h>
using namespace std;

/*
The Fibonacci sequence is a sequence where the next term is the sum of the previous two terms. The first two terms of the Fibonacci sequence are 0 followed by 1.
The Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21

*/
// Brute Force approach
// TC O(2^n) Since each call spawns two recursive calls, the number of function calls grows exponentially.

// S,C O(N)  --> total max no funtions call will remains in the stack.
int nthFibonacci(int n)
{
    // code here

    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;

    return nthFibonacci(n - 1) + nthFibonacci(n - 2);
}

// optmized approach:
// T.C O(N) S.C O(1)
int nthFibo(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;

    int prev1 = 1, prev2 = 0;
    for (int i = 2; i <= n; i++)
    {
        int sum = prev1 + prev2;

        prev2 = prev1;
        prev1 = sum;
    }
    return prev1;
}
int main()
{

    return 0;
}