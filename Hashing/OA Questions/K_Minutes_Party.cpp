/*
There are n events from timing [start.end] ; in each even a particular person is doing some action in that time bracket ; we have to find the min timing when everyone mentioned is free so they can have party for k minutes non stop
Return timing in form of "HH:MM" if not possible return "-1"

Ex: { {"00:00","05:00"},{"05:25","10:00"}, {"11:00","12:00"}} k = 30
Output : At 10:01 all are free so you can have 30 min party from 10:01 
*/

#include <bits/stdc++.h>
using namespace std;

string getPartyTime(vector<vector<string>>&Timing , int k)
{
    int cnt = 0 , hr =0 , min = 0 , STime = 0;
    string ans = "";
    vector<int>preFixSum(1440+2, 0);
    // TO simplify convert timing into minutes
    for(vector<string> time: Timing)
    {
        hr = stoi(time[0].substr(0,2));
        min = stoi(time[0].substr(3,2));

        int L = hr*60 + min;

        hr = stoi(time[1].substr(0,2));
        min = stoi(time[1].substr(3,2));

        int R = hr*60 + min;;

        preFixSum[L] = preFixSum[L]+1;
        preFixSum[R+1] = preFixSum[R+1]-1;
    }

    for(int i = 1; i<preFixSum.size(); i++)
    {
        preFixSum[i] = preFixSum[i-1]+preFixSum[i];
        
        if(preFixSum[i] == 0)
        {
            cnt++; // if continuous k times 0 occures then we can have party in that time
            if(cnt == k)
            {
                STime = (i - k + 1);
                break;
            }

        }
        else    
            cnt = 0;
    }

    if(cnt == 0) return "-1";

    hr = STime/60;
    min = STime%60;

    ans = to_string(hr) + ":" + to_string(min);
    return ans;   
}

int main()
{
    vector<vector<string>>Timing = { {"00:00","05:00"},{"05:25","10:00"}, {"11:00","12:00"}};
    int k = 30;
    
    cout<<getPartyTime(Timing , k)<<endl;
    return 0;
}