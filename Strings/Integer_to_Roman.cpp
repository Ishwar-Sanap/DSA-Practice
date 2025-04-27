#include <bits/stdc++.h>
using namespace std;

// Example:
//  33 -> XXXIII 34-> XXXIV
//  43 -> XLIII 44-> XLIV 47 -> XLVII

    string getValue(int num)
{
    if (num == 1)
        return "I";
    else if (num == 4)
        return "IV";
    else if (num == 5)
        return "V";
    else if (num == 9)
        return "IX";
    else if (num == 10)
        return "X";
    else if (num == 40)
        return "XL";
    else if (num == 50)
        return "L";
    else if (num == 90)
        return "XC";
    else if (num == 100)
        return "C";
    else if (num == 400)
        return "CD";
    else if (num == 500)
        return "D";
    else if (num == 900)
        return "CM";
    else if (num == 1000)
        return "M";

    return "";
}
string intToRoman(int num)
{
    string ans = "";

    vector<int> arr = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

   int i = arr.size()-1;
   while(num > 0)
   {
        if(num >= arr[i])
        {
            ans += getValue(arr[i]);
            num -= arr[i];

            continue;
        }
        i--;
    }

    return ans;
}

int main()
{

    return 0;
}