#include <bits/stdc++.h>
using namespace std;

/*
https://www.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

Input: start[] = [1, 3, 0, 5, 8, 5], end[] =  [2, 4, 6, 7, 9, 9]
Output: 4
Explanation: Maximum four meetings can be held with given start and end timings. The meetings are - (1, 2), (3, 4), (5,7) and (8,9)

*/

bool comp(pair<int, int> &m1, pair<int, int> &m2)
{
    // sorting meeting based on the end time in incresing order
    // so room will be available for another meeting as early as possible

    if (m2.second < m1.second)
        return false;
    else if (m2.second == m1.second)
    {
        // sort decresing order for shorter meeting
        return m2.first <= m1.first;
    }

    return true;
}
int maxMeetings(vector<int> &start, vector<int> &end)
{
    // Your code here

    int n = start.size();

    vector<pair<int, int>> meetings;

    for (int i = 0; i < n; i++)
    {
        meetings.push_back({start[i], end[i]});
    }

    sort(meetings.begin(), meetings.end(), comp);

    int freeTime = -1, cnt = 0;
    for (auto meet : meetings)
    {
        if (meet.first > freeTime)
        {
            freeTime = meet.second;
            cnt++;
        }
    }

    return cnt;
}

// What will you do if you also want the meeting ID sequecne you choosen for maximum meetings?
class Meeting
{
public:
    int startTime, endTime, ID;
    Meeting(int st, int et, int id)
    {
        startTime = st, endTime = et, ID = id;
    }
};

bool comp2(Meeting *ptr1, Meeting *ptr2)
{
    // sorting meeting based on the end time in incresing order
    // so room will be available for another meeting as early as possible

    if (ptr2->endTime < ptr1->endTime)
        return false; // move smaller end time to begining

    else if (ptr2->endTime == ptr1->endTime)
    {
        // sort decresing order of start time for shorter meeting
        return ptr2->startTime <= ptr1->startTime;
    }

    return true;
}
int maxMeetings2(vector<int> &start, vector<int> &end)
{
    // Your code here

    int n = start.size();

    vector<int> meetingSequence;
    // array of pointers
    vector<Meeting *> meetings;

    for (int i = 0; i < n; i++)
    {
        meetings.push_back(new Meeting(start[i], end[i], i + 1));
    }

    sort(meetings.begin(), meetings.end(), comp2);

    int freeTime = -1, cnt = 0;
    for (auto meet : meetings)
    {
        if (meet->startTime > freeTime)
        {
            meetingSequence.push_back(meet->ID);
            freeTime = meet->endTime;
            cnt++;
        }
    }

    for (int id : meetingSequence)
        cout << id << " ";
    cout << endl;

    return cnt;
}
int main()
{

    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout << maxMeetings2(start, end) << endl;

    return 0;
}