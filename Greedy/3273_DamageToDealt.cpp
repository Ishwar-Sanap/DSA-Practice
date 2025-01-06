#include <bits/stdc++.h>
using namespace std;
/*
        m is amout of time in second required to kill ith enemy
        and d is amout of damge per second when killing ith enemy
        d [10 2 3 7]    m [ 2, 3, 5 ,6 ]  m[i] = health[i]/power
        ex: suppose for 1st case you decide to kill 0 index enemy it will required 2 sec.
        total damage delt to bob while killing  enemy is [10 + 2 + 3+ 4]*2 = 38
        killing 3rd index enemy required 6 second ,damage delt:  [ 2 + 3 + 7]*6 = 72
        .....
        you have to kill all enemy in such order that the total damage delt will be minumum..

        d [10 2 3 7]    m [ 2, 3, 5 ,6 ]  sorted in descending order based on di/mi ,

       d [1 2 3 4]    m [ 2 2 2 2 ] having largest damage kill first is best way

       d [ 1 1 1 1]   m [ 2, 3, 5 ,6] having smallest move kill first is best way

        */

bool static comp(pair<int, int> p1, pair<int, int> p2)
{
    double r1 = (double)p1.first / p1.second;
    double r2 = (double)p2.first / p2.second;

    return r1 > r2;
}
long long minDamage(int power, vector<int> &damage, vector<int> &health)
{

    vector<pair<int, int>> arr;
    int n = damage.size();
    long long ans = 0;
    long long totalDamage = 0;
    for (int i = 0; i < n; i++)
    {
        totalDamage += damage[i];

        int time = 0; // time to kill ith enemy with power
        time = health[i] / power;

        if (health[i] % power != 0)
            time++;

        arr.push_back({damage[i], time});
    }

    sort(arr.begin(), arr.end(), comp);
    // now you have array sorted in decresing order based on d[i]/m[i]

    for (auto it : arr)
    {
        long long delt = totalDamage * it.second;
        ans += delt;
        totalDamage -= it.first; // since curret enemy is dead
    }
    return ans;
}
int main()
{

    return 0;
}