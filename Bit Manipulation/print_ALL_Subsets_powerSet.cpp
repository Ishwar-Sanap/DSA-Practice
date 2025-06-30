#include <bits/stdc++.h>
using namespace std;

bool isSetBit(int num, int j)
{
    int mask = 1 << j;

    if ((num & mask) == 0)
        return false;

    return true;
}

vector<vector<int>> getAllSubsets(vector<int> &arr)
{

    // EX: arr [4,5,6] - take not take approach using bits  1 -> take 0-> not take
    //          1 1 1 --> all are taken in subset [4,5,6]
    //          1 0 1 --> 0th and 2nd bit is ON so,element is taken in subset [4,6]

    // when all are taken means in decimal num(7) = 2^n - 1   which equivalent to [1 1 1]
    int n = arr.size();

    int maxNum = pow(2, n) - 1;

    vector<vector<int>> ans;
    for (int num = 0; num <= maxNum; num++)
    {
        vector<int> subset;
        for (int j = 0; j < n; j++) // represent array index
        {
            if (isSetBit(num, j))
                subset.push_back(arr[j]);
            
        }

        ans.push_back(subset);
    }

    return ans;
}
int main()
{
    vector<int> arr = {4, 5, 6};
    vector<vector<int>> subsets = getAllSubsets(arr);

    for (auto subset : subsets)
    { 
        cout<< "[ ";
        for (int ele : subset)
            cout << ele << " ";
        
        cout<<"]" << endl;
    }
    return 0;
}