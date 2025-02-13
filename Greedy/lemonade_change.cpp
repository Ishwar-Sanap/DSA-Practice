#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/lemonade-change/description/

Input: bills = [5,5,5,10,20]
Output: true
Explanation: 
From the first 3 customers, we collect three $5 bills in order.
From the fourth customer, we collect a $10 bill and give back a $5.
From the fifth customer, we give a $10 bill and a $5 bill.
Since all customers got correct change, we output true.

*/
bool lemonadeChange(vector<int> &bills)
{

    int fiveCnt = 0, tenCnt = 0;
    for (int bill : bills)
    {
        if (bill == 5)
        {
            fiveCnt++;
        }
        else if (bill == 10)
        {
            tenCnt++;
            fiveCnt--;

            if (fiveCnt < 0)
                return false;
        }
        else if (bill == 20)
        {
            // try to give maximum from 10 coins,and then from 5 coins
            if (tenCnt > 0 && fiveCnt > 0)
            {
                tenCnt--;
                fiveCnt--;
            }
            else if (fiveCnt >= 3)
            {
                fiveCnt -= 3;
            }
            else
                return false;
        }
    }

    return true;
}

int main()
{

    return 0;
}