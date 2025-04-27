#include <bits/stdc++.h>
using namespace std;

/*
Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

https://leetcode.com/problems/isomorphic-strings/description/ 
*/

// Ex: s = paper
//     t = title  output true
bool isIsomorphic(string s, string t)
{

    int n1 = s.length(), n2 = t.length();

    if (n1 != n2)
        return false;

    unordered_map<char, char> mp1; // map s->t
    unordered_map<char, char> mp2; // map t->s

    for (int i = 0; i < n1; i++)
    {
        if (mp1.find(s[i]) != mp1.end())
        {

            if (mp1[s[i]] != t[i])
                return false;
        }

        else if (mp2.find(t[i]) != mp2.end())
        {

            if (mp2[t[i]] != s[i])
                return false;
        }

        else
        {
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
    }

    return true;
}

int main()
{

    return 0;
}