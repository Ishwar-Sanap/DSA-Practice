
#include <bits/stdc++.h>
using namespace std;


/*
Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
Output: 1 2 3 4 5 6 7
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.
*/
vector<int> findUnion(vector<int> &a, vector<int> &b) {
    // Your code here
    // return vector with correct order of elements
    
    vector<int>ans;
    
    int n1 = a.size(), n2 = b.size();
    int i = 0, j = 0;
    
    while(i < n1 && j < n2)
    {
        int sm = 0;
        if(a[i] <= b[j])
        {
            sm = a[i];
            
        }
        else{
            sm = b[j];
        }
        
        ans.push_back(sm);
            
        // ignore duplicates from both arrays of current small element

        while(i < n1 && a[i] == sm)i++;
        
        while( j < n2 && b[j] == sm) j++;
    }
    
    
    while(i < n1)
    {
        int sm = a[i];
        ans.push_back(sm);
        
        while(i < n1 && a[i] == sm)i++;
    }
    while(j < n2)
    {
        int sm = b[j];
        ans.push_back(sm);
        
        while( j < n2 && b[j] == sm) j++;
    }
    
    return ans;
}


int main()
{

    return 0;
}