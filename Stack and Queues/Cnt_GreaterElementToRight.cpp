#include <bits/stdc++.h>
using namespace std;

// Using stack we can't improve T.C, we must have to traverse all elements to check the count :(
vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices)
{
    // write your code here

    vector<int> res;
    for (int i : indices)
    {
        int cnt = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
                cnt++;
        }

        res.push_back(cnt);
    }
    return res;
}


int main()
{

    return 0;
}

