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

// T.C O(sqrt(n) * sqrt(n))
vector<int> getALLPrimeFactors(int n)
{
    vector<int> ans;

    // (i * i) <= num is equivalent to i <= sqrt(num)
    for (int i = 2; (i * i) <= n; i++)
    {
        if (n % i == 0)
        {
            if (isPrime(i))
                ans.push_back(i);

            if (n / i != i && isPrime(n / i))
                ans.push_back(i);
        }
    }

    return ans;
}

// Optimized  T.C O(sqrt(n) * log(n))
vector<int> getALLPrimeFactors_OP(int n)
{  
    vector<int> ans;

    // (i * i) <= num is equivalent to i <= sqrt(num)
    for (int i = 2; (i * i) <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);

            // Factorization, and it reduces the number till i divides the n
            while (n % i == 0)
            {
                n = n / i;
            }
        }
    }

    if(n > 1) ans.push_back(n);

    return ans;
}
int main()
{
    vector<int> pf = getALLPrimeFactors_OP(37);

    for (int f : pf)
        cout << f << " ";

    return 0;
}