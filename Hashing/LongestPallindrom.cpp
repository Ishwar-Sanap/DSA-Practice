#include <bits/stdc++.h>
using namespace std;

// Approach1 using map
int longestPalindrome(vector<string> &words)
{
    int ans = 0;
    unordered_map<string, int> mp;
    for (string word : words)
    {
        string flipped = {word[1], word[0]};

        if (mp.find(flipped) != mp.end())
        {
            ans += 4;

            mp[flipped]--;

            if (mp[flipped] == 0)
                mp.erase(flipped);
        }
        else
        {
            mp[word]++;
        }
    }

    // For the odd word in the center of the palindrome (e.g. "aa", "bb", "cc", etc.),
    for (auto it : mp)
    {
        string word = it.first;
        if (word[0] == word[1])
        {
            ans += 2;
            break;
        }
    }

    return ans;
}

// Approch 2 using, 2D array to store frequencies
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