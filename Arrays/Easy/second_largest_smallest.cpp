#include <bits/stdc++.h>
using namespace std;

// 4 6 6
// --> Largest1 = 6 Largest2 = 4
int getSecondLargest(vector<int> &arr)
{
    // Code Here

    int l1 = INT_MIN, l2 = INT_MIN;

    for (int ele : arr)
    {
        if (ele > l1)
        {
            l2 = l1;
            l1 = ele;
        }

        else if (ele > l2 && ele != l1)
        {
            l2 = ele;
        }
    }

    return l2 == INT_MIN ? -1 : l2;
}

// 4 6 4
// --> Smallest1 = 4 Smallest2 = 6
int getSecondSmallest(vector<int> &arr)
{
    // Code Here

    int s1 = INT_MAX, s2 = INT_MAX;

    for (int ele : arr)
    {
        if (ele < s1)
        {
            s2 = s1;
            s1 = ele;
        }

        else if (ele < s2 && ele != s1)
        {
            s2 = ele;
        }
    }

    return s2 == INT_MAX ? -1 : s2;
}

int main()
{

    return 0;
}