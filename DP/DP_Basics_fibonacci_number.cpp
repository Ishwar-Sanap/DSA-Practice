#include <bits/stdc++.h>
using namespace std;

// 0,1,1,2,3,5,8,13,21,.
//  Every ith number of the series is equal to the sum of (i-1)th and (i-2)th number where the first and second number is given as 0 and 1 respectively.

// Using Recusion
// T.C (2^n) S.C O(N) recursion stack space
int getFibonacciNumber(int n)
{
    if (n <= 1)
        return n;

    return getFibonacciNumber(n - 1) + getFibonacciNumber(n - 2);
}

// Converting Recusion into memoization, to avoid overlapping sub problems
// Memoization : Top to bottom approach  --> the problem is solved in the direction of the main problem to the base cases.
// T.C O(N), S.C O(N) extra dp array + O(N) recursion stack space
int getFibonacciNumber(int n, vector<int> &dp)
{
    // base case
    if (n <= 1)
        return n;

    // step2 : if sub problem is alredy solved then return the ans
    if (dp[n] != -1)
        return dp[n];

    // step 3 storing the results of computed sub problem
    return dp[n] = getFibonacciNumber(n - 1, dp) + getFibonacciNumber(n - 2, dp);
}

// Tabulation : Bottom up approach --> usually the problem is solved in the direction of solving the base cases to the main problem
//  T.C O(N) , S.C O(N) extra DP array
int getFibonacciNumberT(int n)
{
    // step1: declare the DP array
    vector<int> dp(n + 1, -1);

    // step2 : Initialize the base conditions values into dp array
    dp[0] = 0; // since we know 0th fibonacci number is 0
    dp[1] = 1; // 1st fibonacci number is 1

    for (int i = 2; i <= n; i++)
    {
        // step 3: forming recurance relation and storing intermediate results of subproblems
        // dp[i]--> is the best answer till ith index
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // Step4: return the main problem answer
    return dp[n];
}

// Spcae optimization (Most effective solution)
// T.C-->O(N)  S.C --> O(1)
// Thought process build from the Tabulation approach
long long fibonacci(int n)
{
    if (n <= 1)
        return n;

    // since every time we required only prev1 and prev2 we can use 2 varible insted of array
    long long prev2 = 0;
    long long prev1 = 1;

    for (int i = 2; i <= n; i++)
    {
        long long curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    int n = 5;
    auto start = std::chrono::high_resolution_clock::now();
    // cout<<getFibonacciNumber(n)<<endl;

    // // step1 : create the DP array
    // vector<int>dp(n+1, -1);
    // // cout<<getFibonacciNumber(n,dp)<<endl;

    // cout<<getFibonacciNumberT(n)<<endl;
    cout << fibonacci(n) << endl;

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Execution time: " << duration.count() << " microseconds" << std::endl;

    return 0;
}