

#include <bits/stdc++.h>
using namespace std;

/*
// Given a positive integer n, find the square root of n. If n is not a perfect square, then return the floor value.
// Floor value of any number is the greatest Integer which is less than or equal to that number

Ex: n = 49 --> 7
    n = 50 --> 7
*/
int floorSqrt(int n)
{
    int low = 1, high = n, ans = 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        long squre = (long)mid * (long)mid;
        if (squre == n)
            return mid;

        else if (squre < n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return high; // as we 
    // return ans;
}
int main()
{
    cout<<floorSqrt(50)<<endl;
    return 0;
}