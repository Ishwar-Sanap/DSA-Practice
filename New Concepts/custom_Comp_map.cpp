#include <bits/stdc++.h>
using namespace std;

/*
std::unordered_map does not support a custom comparator in the same way as std::map. This is because:

std::map is implemented as a balanced binary search tree (RB-tree), which requires ordering.

std::unordered_map is implemented as a hash table, which does not use key ordering but instead relies on:
    A hash function to map keys to buckets.
    An equality function to check if two keys are the same.
*/
struct comp
{
    /*

    The operator() function must take two parameters, representing two keys being compared. It should return:

    true → if the first key should be placed before the second key.
    false → otherwise.
    */
    bool operator()(int ele1, int ele2)
    {
        return ele1 > ele2; // then you want ele1 at first 
    }
};

int main()
{
    vector<int> arr = {5, 2, 3, 4, 2, 3, 1};

    // incresing order based on elements
    map<int, int> mp;
    for (int ele : arr)
        mp[ele]++;

    while (!mp.empty())
    {
        int curr = mp.begin()->first;
        cout << curr << " ";

        mp[curr]--;
        if (mp[curr] == 0)
            mp.erase(curr);
    }

    cout << " \n";
    // out : 1 2 2 3 3 4 5

    // decresing order elements
    map<int, int, comp> mp2;
    for (int ele : arr)
        mp2[ele]++;

    while (!mp2.empty())
    {
        int curr = mp2.begin()->first;
        cout << curr << " ";

        mp2[curr]--;
        if (mp2[curr] == 0)
            mp2.erase(curr);
    }
    // out: 5 4 3 3 2 2 1

    return 0;
}