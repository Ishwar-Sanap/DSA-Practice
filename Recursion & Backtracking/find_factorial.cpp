#include <bits/stdc++.h>
using namespace std;

/*
5! = 5 * 4 * 3 * 2 * 1 = 120
   = 5 * 4!
   = 5 * 4 * 3!
   = 5 * 4 * 3 * 2!
   = 5 * 4 * 3 * 2 * 1!
   = 120
*/
int getFactorial(int n)
{
    //we know the answer of 1! and 0!  = 1
    //base case
    if(n <= 1) return 1;

    return n * getFactorial(n-1);
}

int main()
{

    cout<<getFactorial(5)<<endl;

    return 0;
}