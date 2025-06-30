#include <bits/stdc++.h>
using namespace std;

/*
Input: start = 10, goal = 7
Output: 3
Explanation: The binary representation of 10 and 7 are 1010 and 0111 respectively. We can convert 10 to 7 in 3 steps:
- Flip the first bit from the right: 1010 -> 1011.
- Flip the third bit from the right: 1011 -> 1111.
- Flip the fourth bit from the right: 1111 -> 0111.
It can be shown we cannot convert 10 to 7 in less than 3 steps. Hence, we return 3.

https://leetcode.com/problems/minimum-bit-flips-to-convert-number/description/ 
*/

int getSetBitsCount(int num)
{
    int cnt = 0;
    while (num != 0)
    {
        num = num & (num - 1);
        cnt++;
    }

    return cnt;
}
int minBitFlips(int start, int goal)
{

    // XOR will make's the same bits's 0 i.e 0 ^ 0 = 0 ,  1 ^ 1 = 0
    // 0 ^ 1 = 1 , 1 ^ 0 = 1
    int num = start ^ goal;

    return getSetBitsCount(num);
}
int main()
{
    return 0;
}