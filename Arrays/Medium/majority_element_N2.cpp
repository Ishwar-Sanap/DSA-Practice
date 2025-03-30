#include <bits/stdc++.h>
using namespace std;
  // moore's voting algorithm : 
int majorityElement(vector<int> &nums)
{

    int ele = 0, cnt = 0;

    // There will be only one majority element possible whose occurace > n/2
    for (int num : nums)
    {
        // current num can be the majority element
        if (cnt == 0)
        {
            ele = num;
            cnt++;
        }
        else
        {

            if (num == ele)
                cnt++;
            else
                cnt--; // since num is not equals to ele, so it's frequency got cancel out with another number..
        }
    }

    // by using above algo if any elements appers more than n/2 time will be store into ele
    // now verify the ele, is majority or not, as question say it's gurantee that majority alway exist so no need to verify

    return ele;
}
int main()
{

    return 0;
}