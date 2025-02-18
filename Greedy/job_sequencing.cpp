#include <bits/stdc++.h>
using namespace std;
/*
https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

Input: id = [1, 2, 3, 4], deadline = [4, 1, 1, 1], profit = [20, 1, 40, 30]
Output: [2, 60]
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).

*/

class Job
{
public:
    int m_iId, m_iDeadline, m_iProfit;

    Job(int i, int d, int p)
    {
        m_iId = i;
        m_iDeadline = d;
        m_iProfit = p;
    }
};

class Solution
{
public:
    static bool comp(Job *pt1, Job *pt2)
    {
        return pt1->m_iProfit > pt2->m_iProfit;
    }
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit)
    {
        // code here
        int n = id.size();

        vector<Job *> jobs;
        int maxDeadline = 0;
        for (int i = 0; i < n; i++)
        {
            maxDeadline = max(maxDeadline, deadline[i]);
            jobs.push_back(new Job(id[i], deadline[i], profit[i]));
        }

        // array to store the maximum deadline, and using it for any single job
        vector<int> arr(maxDeadline + 1, -1);

        // sorting jobs based on max profit
        sort(jobs.begin(), jobs.end(), comp);

        int maxProfit = 0, maxJobCnt = 0;
        for (auto pt : jobs)
        {
            int currDay = pt->m_iDeadline;
            while (currDay > 0 && arr[currDay] != -1)
            {

                currDay--;
            }

            // peforming the job on the last possible day
            // so remaining days can be available for those jobs having least deadline
            if (currDay > 0)
            {

                arr[currDay] = pt->m_iId;
                maxJobCnt++;

                maxProfit += pt->m_iProfit;
            }
        }

        // deallocating the memory of jobs.
        for(Job* ptJob : jobs)
        {
            delete ptJob;
            ptJob = nullptr;
        }

        return {maxJobCnt, maxProfit};
    }
};

int main()
{

    return 0;
}