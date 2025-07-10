#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/word-ladder/

// Approach2 :
//Time Complexity: O(N * M * 26)
// Where N = size of wordList Array and M = word length of words present in the wordList..

int ladderLength2(string beginWord, string endWord, vector<string> &wordList)
{
    // Exploring all the wordlist from begin word , we will trying to place a-z characters sequecne
    //  since we have to get min length, we can use BFS..

    unordered_set<string> setWords(wordList.begin(), wordList.end());

    queue<pair<string, int>> qNodes;
    qNodes.push({beginWord, 0}); // level 0
    setWords.erase(beginWord);

    while (!qNodes.empty())
    {
        string currWord = qNodes.front().first;
        int steps = qNodes.front().second;
        qNodes.pop();

        if (currWord == endWord)
            return steps + 1;

        // For each character from word, try replacing any one charater
        for (int i = 0; i < currWord.size(); i++)
        {
            char originalChar = currWord[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                currWord[i] = ch;

                if (setWords.count(currWord))
                {
                    qNodes.push({currWord, steps + 1}); // added to next level
                    setWords.erase(currWord); // to avoid repeted adding same word
                }

                // reseting to original
                currWord[i] = originalChar;
            }
        }
    }

    return 0;
}

// Approach1 : O(N^2)
class Solution
{
public:
    int getDifferBy(string str1, string str2)
    {
        int n1 = str1.length(), n2 = str2.length();
        if (n1 != n2)
            return 0;

        int cnt = 0;
        int i = 0, j = 0;
        while (i < n1)
        {
            if (str1[i] != str2[j])
                cnt++;

            i++;
            j++;
        }

        return cnt;
    }

    int bfs(int node, string endWord, vector<vector<int>> adjList,
            vector<int> &visited, vector<string> &wordList)
    {

        queue<pair<int, int>> qNodes;
        qNodes.push({node, 0});
        visited[node] = 1;

        int ans = 0;
        while (!qNodes.empty())
        {
            int currNode = qNodes.front().first;
            int steps = qNodes.front().second;
            qNodes.pop();

            if (currNode > 0 && wordList[currNode - 1] == endWord)
                return steps + 1;

            // Explore it's neighbors
            for (int neighbor : adjList[currNode])
            {
                if (!visited[neighbor])
                {
                    qNodes.push({neighbor, steps + 1});
                    visited[neighbor] = 1;
                }
            }
        }

        return ans;
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {

        int dLen = wordList.size();
        vector<vector<int>> adjList(dLen + 1, vector<int>());
        vector<int> visited(dLen + 1, 0);

        if (beginWord == endWord)
            return 1;

        for (int j = 1; j <= dLen; j++)
        {
            int diff = getDifferBy(beginWord, wordList[j - 1]);
            if (diff == 1)
                adjList[0].push_back(j);
        }

        for (int i = 1; i <= dLen; i++)
        {
            for (int j = 1; j <= dLen; j++)
            {
                if (i != j)
                {
                    int diff = getDifferBy(wordList[i - 1], wordList[j - 1]);
                    if (diff == 1) // then there wordList[i] and wordList[j] are neighbors
                    {
                        adjList[i].push_back(j);
                        adjList[j].push_back(i);
                    }
                }
            }
        }

        return bfs(0, endWord, adjList, visited, wordList);
    }
};
