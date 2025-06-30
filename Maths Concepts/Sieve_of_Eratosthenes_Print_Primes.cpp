#include <bits/stdc++.h>
using namespace std;

bool isPrime(int num)
{
    // (i * i) <= num is equivalent to i <= sqrt(num)
    for (int i = 2; (i * i) <= num; i++)
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

// T.C --> O(N * sqrt(n))
vector<int> getALLPrimes(int n)
{
    vector<int> ans;
    // return all prime numbers from 1 to n
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i)) // O(sqrt(i))
            ans.push_back(i);
    }

    return ans;
}

// Optimized way
// Sieve of Eratosthenes T.C-->  nlog(logn) + O(n) , S.C --> O(n)
vector<int> getALLPrimesOP(int n)
{
    // Initialize the array with all 1
    // this array helps to check the n is prime or not in O(1) time
    vector<bool> primes(n + 1, true);

    // 0 and 1 are not prime
    primes[0] = primes[1] = false;

    // precomputing the primes array  // T.C nlog(logn)
    for (int i = 2; (i * i) <= n; i++) //(i * i) <= num is equivalent to i <= sqrt(num)
    {
        if (primes[i] == true)
        {
            int multiple = i * i;
            while (multiple <= n)
            {
                primes[multiple] = false;
                multiple += i;
            }
        }
    }

    vector<int> ans;
    // return all prime numbers from 1 to n   // O(n)
    for (int i = 2; i <= n; i++)
    {
        if (primes[i] == true) // O(1)
            ans.push_back(i);
    }

    return ans;
}

int main()
{
    vector<int> p = getALLPrimesOP(20);
    for (int ele : p)
        cout << ele << " ";

    cout << endl;
    return 0;
}