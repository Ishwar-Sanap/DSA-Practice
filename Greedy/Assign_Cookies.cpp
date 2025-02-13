#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/assign-cookies/description/

g = [2,3,1,6,5]
s = [8,4,3,2]

output : 4

*/

int findContentChildren(vector<int> &g, vector<int> &s)
{

    
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    
    // Greedily we are assigning cookies to children.
    //ie. for any children with greed factor x ,we give cookies nearest greter or equal to x
    // so that, higher cookies will be applicable to other children having larger greed factor.

    
    int n = g.size();
    int i = 0, j = 0, m = s.size(), cnt = 0;
    while (i < n && j < m)
    {
        if (s[j] >= g[i])
        {
            i++;
            j++;
            cnt++;
        }
        else
            j++;
    }

    return cnt;
}
int main()
{

    return 0;
}