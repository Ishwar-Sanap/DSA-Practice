/*
Given the string s and t 
t can we obtained by selecting some subset of characters from s
determine maximum number of time target t can be obtained

only lower case english letter

Input : 
s = abacbc t = bca      output : 2
s = bbccbbacc t = cbcb   output : 2
s= abcbc t = ebca       output : 0

*/
#include <bits/stdc++.h>
using namespace std;

int getCount(string s, string t)
{
    int cnt = t.length();

    int freqS[26] ={ 0};
    int freqT[26] ={ 0};
    for(char ch : s)freqS[ch-'a']++;
    for(char ch : t)freqT[ch-'a']++;

   for(char ch : t)
   {
        cnt = min(freqS[ch -'a']/freqT[ch - 'a'] , cnt);
   }
   return cnt;
}

int main()
{
    cout<<getCount("bbccbbacc", "cbcb")<<endl;
    return 0;
}