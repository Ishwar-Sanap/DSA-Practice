#include <bits/stdc++.h>
using namespace std;

// Input: num = "35474"
// Output: "3547"
//https://leetcode.com/problems/largest-odd-number-in-string/description/ 

string largestOddNumber(string num)
{

    int n = num.size();

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = num[i] - '0';

        if (digit & 1 == 1) // odd
        {
            int len = i + 1;
            return num.substr(0, len);
        }
    }

    return "";
}

int main()
{

    return 0;
}
