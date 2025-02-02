#include <bits/stdc++.h>
using namespace std;

/*
Design and implement a data structure for a Least Frequently Used (LFU) cache.

Implement the LFUCache class:

LFUCache(int capacity) Initializes the object with the capacity of the data structure.
int get(int key) Gets the value of the key if the key exists in the cache. Otherwise, returns -1.
void put(int key, int value) Update the value of the key if present, or inserts the key if not already present. When the cache reaches its capacity, it should invalidate and remove the least frequently used key before inserting a new item. For this problem, when there is a tie (i.e., two or more keys with the same frequency), the least recently used key would be invalidated.
To determine the least frequently used key, a use counter is maintained for each key in the cache. The key with the smallest use counter is the least frequently used key.

When a key is first inserted into the cache, its use counter is set to 1 (due to the put operation). The use counter for a key in the cache is incremented either a get or put operation is called on it.

The functions get and put must each run in O(1) average time complexity.
*/

class LFUCache
{
public:
    unordered_map<int, list<vector<int>>::iterator> mpkeyToNode;
    map<int, list<vector<int>>> mpFreqToList; // {key,value,cnt}

    int maxCap{0};
    LFUCache(int capacity)
    {
        maxCap = capacity;
    }

    void updateMostFrequentlyUsed(int key, int value)
    {
        vector<int> listNode = *(mpkeyToNode[key]); // getting value of node from iterator
        int freq = listNode[2];

        // update the frequency count of ListNode since we have access the key
        // remove list node from current frequency since it's frequecny is incrsed add into new frequency
        mpFreqToList[freq].erase(mpkeyToNode[key]);

        if (mpFreqToList[freq].empty()) // all list becomes empty
            mpFreqToList.erase(freq);

        freq++;

        mpFreqToList[freq].push_back({key, value, freq});

        // updating keytoNod with new address
        // end() points to one position after the last element, so accessing it is undefined behavior.
        mpkeyToNode[key] = prev(mpFreqToList[freq].end());
    }

    void removeLestFrequentlyUsed()
    {
        auto &removeFromList = mpFreqToList.begin()->second; // getting access of first ListNode from freq
        vector<int> listNode = *removeFromList.begin();

        int key = listNode[0], freq = listNode[2];

        // in front of each List there is LeastFrequently used key
        removeFromList.pop_front();

        if (removeFromList.empty())
            mpFreqToList.erase(freq);

        mpkeyToNode.erase(key);
    }
    int get(int key)
    {
        if (mpkeyToNode.find(key) != mpkeyToNode.end())
        {
            // each list node have {key,value,cnt}
            vector<int> listNode = *(mpkeyToNode[key]); // getting value of node from iterator
            int val = listNode[1];

            updateMostFrequentlyUsed(key, val);

            return val;
        }

        return -1;
    }

    void put(int key, int value)
    {
        if (mpkeyToNode.find(key) != mpkeyToNode.end())
        {
            // update the frequency and value
            vector<int> listNode = *(mpkeyToNode[key]); // getting value of node from iterator
            int k = listNode[0], val = listNode[1];

            updateMostFrequentlyUsed(key, value);
        }

        else if (mpkeyToNode.size() < maxCap)
        {
            // Inserting newNode
            vector<int> newNode = {key, value, 1};
            mpFreqToList[1].push_back(newNode);

            mpkeyToNode[key] = prev(mpFreqToList[1].end());
        }
        else
        {
            // Remove lest frequently used and insert new one
            removeLestFrequentlyUsed();

            // Inserting newNode
            vector<int> newNode = {key, value, 1};
            mpFreqToList[1].push_back(newNode);

            mpkeyToNode[key] = prev(mpFreqToList[1].end());
        }
    }
};
int main()
{

    return 0;
}