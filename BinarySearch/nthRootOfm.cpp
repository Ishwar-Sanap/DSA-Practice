#include <bits/stdc++.h>
using namespace std;

int nthRoot(int n, int m)
{
    // Code here.
    int low = 1, high = m;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        long long powr = pow(mid, n);

        if (powr == m)
            return mid;

        if (powr > m)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int main()
{
    cout << nthRoot(3 , 64)<<endl; // 4 * 4 * 4 = 64 
    return 0;
}