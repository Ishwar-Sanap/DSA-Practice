
#include <bits/stdc++.h>
using namespace std;

/*
A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people.
A square matrix mat (n*n) is used to represent people at the party such that if an element of row i and column j is set to 1
it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist,
return -1.

Note: Follow 0-based indexing.
*/

// Using stack
int celebrityUsingStack(vector<vector<int>> &mat)
{
    // code here

    int n = mat.size();
    stack<int> st;

    for (int i = 0; i < n; i++)
        st.push(i);

    while (st.size() > 1)
    {
        // Eliminating the persons
        int i = st.top(); st.pop();
        int j = st.top(); st.pop();

        if (mat[i][j] == 1) // ith person knows jth person so i can't be celebrity
           st.push(j);

        else if(mat[j][i] == 1) // jth person knows ith person so j can't be celebrity
            st.push(i);
    }

    int i = st.top(); // the ith person may be celibrity
    // For celebrity 2 conditins to follow:
    // 1) person ith don't no anyone
    // 2) every other person should know  the ith person

    for (int k = 0; k < n; k++)
    {
        if (i == k || (mat[i][k] == 0 && mat[k][i] == 1))
            continue;
        else
            return -1;
    }

    return i;
}

// without stack using 2 pointers
int celebrity(vector<vector<int>> &mat)
{
    // code here

    int n = mat.size();

    int i = 0, j = n - 1;
    while (i < j)
    {
        // Eliminating the persons
        if (mat[i][j] == 1) // ith person knows jth person so i can't be celebrity
            i++;

        else // jth person knows ith person so j can't be celebrity
            j--;
    }

    int person = i; // the ith person may be celibrity
    // For celebrity 2 conditins to follow:
    // 1) person ith don't no anyone
    // 2) every other person should know  the ith person

    for (int k = 0; k < n; k++)
    {
        if (i == k || (mat[i][k] == 0 && mat[k][i] == 1))
            continue;
        else
            return -1;
    }

    return i;
}

int main()
{

    return 0;
}