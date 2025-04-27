#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    int n = strs.size();
    sort(strs.begin(), strs.end());

    // after sorting array will be in alphabetical order
    // [flight flo flow flower]

    int n1 = strs[0].size();
    int n2 = strs[n - 1].size();

    int i = 0, j = 0;
    string ans = "";
    while (i < n1 && j < n2)
    {
        if (strs[0][i] != strs[n - 1][j])
            return ans;

        ans += strs[0][i];
        i++;
        j++;
    }

    return ans;
}
int main()
{

    vector<string> strs = {"flower", "flow", "flight", "flo"};

    // for(string str : strs) cout<<str<<" ";

    cout<<longestCommonPrefix(strs);

    return 0;
}