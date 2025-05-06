#include <bits/stdc++.h>
using namespace std;

/*

Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees

Example 2:

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].

https://leetcode.com/problems/fruit-into-baskets/
*/
int totalFruit(vector<int> &fruits)
{
    // Same as
    // length of longest subarray which contains 2 unique elements

    int n = fruits.size();
    unordered_map<int, int> mp;
    int i = 0, j = 0, maxPicked = 0;

    while (j < n)
    {
        mp[fruits[j]]++;

        if (mp.size() <= 2)
        {
            maxPicked = max(maxPicked, j - i + 1);
            j++;
        }
        else
        {

            while (mp.size() > 2)
            {
                mp[fruits[i]]--;

                if (mp[fruits[i]] == 0)
                    mp.erase(fruits[i]);
                i++;
            }

            maxPicked = max(maxPicked, j - i + 1);
            j++;
        }
    }

    return maxPicked;
}

int main()
{

    return 0;
}