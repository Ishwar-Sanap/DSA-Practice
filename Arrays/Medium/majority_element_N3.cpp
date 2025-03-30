#include <bits/stdc++.h>
using namespace std;

// moore's voting algorithm :
vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();
    int ele1 = INT_MAX, cnt1 = 0, ele2 = INT_MAX, cnt2 = 0;

    // There will be maximum 2 majority element possible whose occuraces > n/3

    for (int num : nums)
    {
        if (cnt1 == 0 && num != ele2)
        {
            ele1 = num;
            cnt1++;
        }
        else if (cnt2 == 0 && num != ele1)
        {
            ele2 = num;
            cnt2++;
        }

        else if (num == ele1)
            cnt1++;
        else if (num == ele2)
            cnt2++;
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    // Verificationsss
    cnt1 = 0, cnt2 = 0;
    for (int num : nums)
    {
        if (num == ele1)
            cnt1++;
        else if (num == ele2)
            cnt2++;
    }

    vector<int> res;
    if (cnt1 > (n / 3))
        res.push_back(ele1);
    if (cnt2 > (n / 3))
        res.push_back(ele2);

    return res;
}
int main()
{

    return 0;
}