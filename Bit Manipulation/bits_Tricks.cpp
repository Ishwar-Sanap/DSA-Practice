#include <bits/stdc++.h>
using namespace std;

// Give the number n and perform the following operations on the bits
// Make sure while chaning the bit, only given ith bit shoud be modify other must be remains as it is..

// Set the ith bit : i.e In num if ith bit is 1 -> 1, 0 -> 1
int setTheBit(int num, int i)
{
   /*
   //Ex: set the 3rd bit
   // int num 7 :    0 1 1 1
   //mask :       or 1 0 0 0
                 ------------
                     1 1 1 1

   */

   int mask = 1 << i;
   int ans = (num | mask);

   return ans;
}

// if ith bit is ON, then only make it to 0 OFF
int clearTheBit(int num, int i)
{
   /*
      EX: clear the 2nd bit
      int num 7 :  0 1 1 1
      mask :  and  1 0 1 1
               --------------
                   0 0 1 1
   */

   int mask = 1 << i; // 0 1 0 0
   mask = ~mask;      // toggle all the bits

   int ans = (num & mask);
   return ans;
}

// if ith Bit ON --> OFF   if OFF --> ON
int toggleTheBit(int num, int i)
{
   /*
     EX: toggle the 3rd bit
     int num 7 :  0 1 1 1
     mask :  xor  1 0 0 0
              --------------
                  1 1 1 1
  */

   int mask = 1 << i;

   int ans = num ^ mask;

   return ans;
}

// if ith bit is ON -> True, elese Return false
bool isBitOn(int num, int i)
{
   /*
     EX: check 2nd bit
     int num 7 :  0 1 1 1
     mask :  and  0 1 0 0
              --------------
                  0 1 0 0

      EX: check 3rd bit
     int num 7 :  0 1 1 1
     mask :  and  1 0 0 0
              --------------
                  0 0 0 0

  */

   int mask = 1 << i;

   int ans = num & mask;

   if (ans == 0)
      return false;

   return true;
}

int clearRightMostSetBit(int num)
{
   // Approach1 :  TO solve it we can may be find the Right most set bit by using loop

   if (num == 0)
      return 0;

   // int i = 0;
   // int temp = num;
   // while (num & 1 != 1)
   // {
   //    num = num >> 1;
   //    i++;
   // }

   // return clearTheBit(temp, i);

   // Approach 2 : Optimized
   /*
      If we observe : 16 -->  1 0 0 0
                      15 -->  0 1 1 1

      if n = 16, it's right most set bit is 3 and for 15 0,1,2 bits becomes 1
      so we can take & of both

      Ex: 2:     20 -->  1 0 1 0 0      // Right most i.e 2nd bit we have to OFF
                 19 -->  1 0 0 1 1

     As 19 is 1 less than 20 it’s 0 , 1 bits becoms 1 and 2nd bit becomes 0, and rest of the bits remains same…
   */

   int mask = (num - 1);

   return num & mask;
}

int getCountOfSetBits(int num)
{
   // int setBitCount = __builtin_popcount(num);

   int cnt = 0;
   // T.C  O(log n)
   // while (num != 0)
   // {
   //    if ((num & 1) == 1)
   //       cnt++;

   //    num = num >> 1;
   // }

   // return cnt;

   // Optimized approch using , counting & clearing Right most set bit..
   // T.C O(no. of set bits)
   while(num  != 0)
   {
      num = (num & num -1);
      cnt++;
   }

   return cnt;
}
int main()
{

   int num = 7;
   cout << setTheBit(num, 3) << endl;
   cout << clearTheBit(num, 2) << endl;
   cout << toggleTheBit(num, 0) << endl;
   cout << isBitOn(num, 4) << endl;
   cout << getCountOfSetBits(15) << endl;

   return 0;
}