#include <bits/stdc++.h>
using namespace std;

// (1 1 0 1) base2    (13) base10
int binaryToDecimal(string str)
{
    int num = 0;
    int n = str.length();
    int i = n - 1;

    while (i >= 0)
    {
        int val = (str[i] - '0') * pow(2, n - i - 1);
        num += val;

        i--;
    }

    return num;
}

string decimalToBinary(int num)
{
    if (num == 0)
        return "0";

    string str = "";

    while (num > 0)
    {
        int bit = num % 2;
        str.push_back((bit + '0'));

        num = num / 2;
    }

    reverse(str.begin(), str.end());

    return str;
}

int main()
{

    int num = binaryToDecimal("1101");
    cout << num << endl;

    cout << decimalToBinary(13) << endl;
    return 0;
}