
#include <bits/stdc++.h>
using namespace std;

/*

Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

 

Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
*/

bool isNStraightHand(vector<int> &hand, int groupSize)
{

    int n = hand.size();

    if (n % groupSize != 0)
        return false;

    map<int, int> mp;
    for (int ele : hand)
        mp[ele]++;

    while (!mp.empty())
    {
        // map begin element will always be the smallest one
        int curr = mp.begin()->first;
        mp[curr]--;

        if (mp[curr] == 0)
            mp.erase(curr);

        int currGrpSize = 1;
        while (currGrpSize < groupSize)
        {
            curr++;
            currGrpSize++;

            if (mp.find(curr) != mp.end()) // if found reduce it's frequency.
            {
                mp[curr]--;
                if (mp[curr] == 0)
                    mp.erase(curr);
                continue;
            }

            else // next consequetive element not found.
                return false;
        }
    }

    return true;
}

int main()
{

    
    return 0;
}