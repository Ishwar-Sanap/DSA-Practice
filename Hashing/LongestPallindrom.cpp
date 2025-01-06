#include <bits/stdc++.h>
using namespace std;

// Approach1
int longestPalindrome(vector<string> &words)
{

    int unpaired = 0;
    unordered_map<string, int> mp;
    int n = words.size();

    for (string str : words)
        mp[str]++; // storing each word and it's frequency

    int longestLen = 0;
    for (int i = 0; i < n; i++)
    {
        string str = words[i];
        string req = str;
        reverse(req.begin(), req.end());

        if (mp.find(req) != mp.end())
        {
            int pairs = min(mp[str], mp[req]);
            if (str == req) // string : gg gg gg
            {
                if (mp[str] % 2 == 1)
                {
                    unpaired = 1; // gg
                    pairs--;
                }
                longestLen += 2 * pairs;
            }
            else // in string you found lc cl lc cl (i.e 2 pairs)
                longestLen += 4 * pairs;

            mp.erase(str);
        }
    }

    if (unpaired)
        longestLen += 2;

    return longestLen;
}

// Approch 2
int longestPalindrome2(vector<string> &words)
{
    // As there are only 2 lowercase English letters in each word, we can represent the word using a
    // 2D array, with the row representing the first letter, and column representing the second letter.
    vector<vector<int>> counting(26, vector<int>(26, 0));
    int max = 0;

    for (string word : words)
    {
        int a = word[0] - 'a';
        int b = word[1] - 'a';
        // We can flip the letters by using counting[b][a], while counting[a][b] represents the original lettering.
        // If we found the pair corresponding to the flipped word, then we can increase the max by 4 and update
        // the frequency of the flipped word.
        // For Example: If "ab" is previously stored in counting[0][1], when the word "ba" came up later,
        //              the flipped word of "ba" which is "ab" in counting[0][1] is found.
        // This is also why it is a greedy algorithm, as we count pair in the final result as soon as it is found,
        // since the position of the pair in a palindrome is not important, as long as they are placed opposite of
        // each other.
        if (counting[b][a] > 0)
        {
            max += 4;
            counting[b][a]--;
        }
        // If no pair is found, store the occurrence of the word.
        else
        {
            counting[a][b]++;
        }
    }
    // For the odd word in the center of the palindrome (e.g. "aa", "bb", "cc", etc.),
    // Check for all 26 possible pairs, if any is found, increase the max by 2.
    // For Example: words = ["ab","ba","zz","yy"]
    //              With "ab" and "ba" form a pair, with max = 4,
    //              either "zz" or "yy" can fit in the center to expand the palindrome, forming "abzzba" or "abyyba".
    // Do note that the valid pairs formed previously is already counted, since a == b, counting[a][b] == counting[b][a].
    for (int i = 0; i < 26; i++)
    {
        if (counting[i][i] > 0)
        {
            max += 2;
            break;
        }
    }
    return max;
}

int main()
{

    return 0;
}