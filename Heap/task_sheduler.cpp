#include <bits/stdc++.h>
using namespace std;
/*
You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be
idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to
be a gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.
Input: tasks = ['A','A','A','B','B','B'], n = 2
Output: 8

Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.
*/

/*
tasks : A B C A , n = 3
A->B->C->idle->A

*/
int leastInterval(vector<char> &tasks, int n)
{
    int ans = 0;

    unordered_map<char, int> mp;
    for (char ch : tasks)
        mp[ch]++;

    // priority queue will store the maximm frequency at top
    // so we can pick the maxFrequency label at first, and it will help to minimize the ideal time further
    priority_queue<int> pq;

    for (auto it : mp)
        pq.push(it.second);

    while (!pq.empty())
    {

        // If we can perform n+1 task in sequence then, don't need to add ideal time in interval.
        vector<int> temp;
        int Taskcnt = 1;
        while (!pq.empty() && Taskcnt <= n + 1)
        {
            int maxFreq = pq.top();
            pq.pop();
            maxFreq--;
            // after considering one task from one lable, reduce it's frequency for next cycle.
            temp.push_back(maxFreq);

            Taskcnt++;
        }

        for (int ele : temp)
        {
            if (ele > 0)
                pq.push(ele);
        }

        if (pq.empty())
            ans += temp.size();

        else // for using the top item from pq, again for next cycle you have to wait for (n+1) time interval
            ans += (n + 1);
    }

    return ans;
}

int main()
{
    // vector<char> task = {'A', 'A', 'B', 'B', 'B', 'B', 'C', 'C', 'C', 'C', 'C', 'C'};
    vector<char> task = {'A', 'A', 'B', 'C'};
    cout << leastInterval(task, 3) << endl;

    return 0;
}