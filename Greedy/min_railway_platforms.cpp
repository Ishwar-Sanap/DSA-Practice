#include <bits/stdc++.h>
using namespace std;

int findPlatform(vector<int> &arr, vector<int> &dep)
{
    // check what is happening as time passes
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int i = 0, j = 0, n = arr.size();
    int platFormReq = 0, platformCnt = 0;
    while (i < n && j < n)
    {
        //A new train arrives before the previous train departs, so we need an extra platform.)
        if (arr[i] <= dep[j])
        {
            platformCnt++;
            i++;

            // how much plafrom required maintain the cont
            platFormReq = max(platFormReq, platformCnt);
        }
        else
        { //A train departs, so we can free a platform.
            // departure of the train
            platformCnt--;
            j++;
        }
    }

    return platFormReq;
}
int main()
{
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};

    cout << findPlatform(arr, dep) << endl;
    return 0;
}