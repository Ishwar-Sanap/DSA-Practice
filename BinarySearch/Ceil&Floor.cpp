#include <bits/stdc++.h>
using namespace std;

/*
Floor of 'x' is the largest element in the array which is smaller than or equal to 'x'.
Ceiling of 'x' is the smallest element in the array greater than or equal to 'x'.

x=5, a=[3, 4, 7, 8, 8, 10]   

Output:
Floor --> 2nd Index arr[2] = 4
Ceil --> 3nd Index arr[3] = 7

*/

int getFloor(vector<int> &arr, int x)
{
    int n = arr.size();
    int s = 0, e = n - 1, ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (arr[mid] <= x)
        {
            //(current array element arr[mid] <= x)
            //Since we want largest element less or equal to x ,store current element and increment start for better ans
            ans = mid;
            s = mid + 1; 
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans == -1 ? ans : arr[ans];
}
int getCeil(vector<int> &arr, int x)
{
    int n = arr.size();
    int s = 0, e = n - 1, ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (arr[mid] >= x)
        {
            // current elemnet arr[mid] >= x
            // we want smallest elment greter or equal to x, store current ans and decrement end for better result.
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans == -1 ? ans : arr[ans];
}
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    // Write your code here.

    return {getFloor(a, x), getCeil(a, x)};
}



int main()
{

    return 0;
}