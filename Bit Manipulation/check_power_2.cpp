#include <bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n)
{
    if (n == 0)
        return false;

        /*
            EX: 8 -> 1 0 0 0
                7 -> 0 1 1 1
                ------------------
              and    0 0 0 0 
        
        */

    long mask = n - 1LL;

    if ((n & mask) == 0)
        return true; // since only 1 bit is set

    return false; // more than 1 bit is set so it's not power of 2
}
int main()
{
    return 0;
}