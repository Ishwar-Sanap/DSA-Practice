#include <bits/stdc++.h>
using namespace std;

// implement the pow(x, y) function which return x raise to y
//  EX: pow(3,5) -->  3^5 --> 243

// T.C O(log y)

double power(int x, int y)
{
    int ans = 1.0;

    int tempY = y;
    y = abs(y);

    while (y > 0)
    {
        if (y % 2 != 0)
        {
            ans = ans * x;
            y--;
        }

        else
        {
            y = y / 2;
            x = x * x;
        }
    }

    if(tempY < 0) 
        return 1.0/ans;


    return ans;
}
int main()
{

    cout << power(3, -5) << endl;
    return 0;
}