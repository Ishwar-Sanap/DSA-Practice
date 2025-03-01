#include <bits/stdc++.h>
using namespace std;

/*
 x = 2 , n = 10  2^10 = 1024
 x = 2 , n = -2 , 2^-2 = 1/2^2 = 0.25
*/

// Binary Exponent
double getPow(double x, int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return x;

    // ex : n = 10
    if (n % 2 == 0)
        // ex: insted of : getPow(2,5) * getPow(2,5) we can optimized the function call
        // using : getPow(4,5);
        return getPow(x * x, n / 2);

    else
        return x * getPow(x * x, n / 2);
}

double myPow(double x, int n)
{

    double ans = 0.0;
    if (n < 0)
    {
        ans = getPow(x, (long)n * -1);
        return 1 / ans;
    }

    ans = getPow(x, n);
    return ans;
}
int main()
{
    double ans = myPow(2, 3);
    cout << ans << endl;

    return 0;
}