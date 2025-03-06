#include <bits/stdc++.h>
using namespace std;

/*
 x = 2 , n = 10  2^10 = 1024
 x = 2 , n = -2 , 2^-2 = 1/2^2 = 0.25
*/

/*
By applying modulo mod (in this case, 1e9 + 7), you ensure that all intermediate results remain within the bounds of the
variable's size, preventing overflow.

Mathematical Properties (Modulo Arithmetic):
Modular arithmetic is a way of working with numbers within a fixed range (in this case, modulo mod = 1e9 + 7).
This allows us to safely perform operations such as:

(a * b) % mod = ((a % mod) * (b % mod)) % mod — ensuring the result stays within the range.

(a + b) % mod = ((a % mod) + (b % mod)) % mod — same for addition.

How It Works (Step by Step)
When calculating:
(a * b) % mod
 
instead of directly computing a*b
a×b (which can be large), you first reduce each number:

Step 1: Compute
a % mod --> reduces a

Step 2: Compute
b % mod --> reduces b

Step 3: Multiply the reduced values.

Step 4: Take modulo again after multiplication. (a' * b') % mod

This prevents integer overflow and keeps values within a safe range.
*/

int mod = 1e9 + 7;
long long getPower(long long x, long long y) // power = x ^ y
{
    if (y == 0)
        return 1;

    long long halfPow = 1;

    halfPow = getPower(x, y / 2);

    halfPow = (halfPow * halfPow) % mod; // make the squre , (x ^ y) * (x ^ y)

    if (y % 2 != 0) // y is odd, multiply x also
        halfPow = (x * halfPow) % mod;

    return halfPow;
}
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