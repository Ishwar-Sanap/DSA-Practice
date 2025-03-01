#include <bits/stdc++.h>
using namespace std;

/*
https://www.geeksforgeeks.org/problems/generate-all-binary-strings/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

n = 4
output : 1010 1001 1000 0101 0100 0010 0001 0000 

*/

void generateAll(int i, int n, string &temp ,vector<string> &res)
{
    if(i >= n)
    {
        res.push_back(temp);
        return;
    }

    // mark 1
    temp[i] = '1';
    generateAll(i+2,n,temp,res); // move to next to next since consequetive one's are not allowed.

    // remove that mark for further call, i.e we have't take the 1 
    temp[i] = '0';
    generateAll(i+1,n,temp,res);
}

vector<string> generateBinaryStrings(int num)
{

    vector<string>res;
    int index = 0;
    string temp(num,'0');
    generateAll(index,num,temp,res);

    return res;
}

int main()
{
    
    generateBinaryStrings(4);

    return 0;
}