#include <bits/stdc++.h>
using namespace std;

/*
We are given an array asteroids of integers representing asteroids in a row. The indices of the
asteriod in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction
(positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will
explode. If both are the same size, both will explode. Two asteroids moving in the same direction
will never meet.

asteroids = [-4 ,5,10,-5,-10]
Output: [-4, 5]

*/
vector<int> asteroidCollision(vector<int> &asteroids)
{
    int n = asteroids.size();

    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (asteroids[i] > 0)
            st.push(asteroids[i]);
        else
        {
            // collision happens
            while (!st.empty() && st.top() > 0)
            {
                // asteriod destroyed smaller element..
                if (st.top() < abs(asteroids[i]))
                    st.pop();

                else // astroid destroyed since got larger or equal element
                    break;
            }

            if ((!st.empty() && st.top() == abs(asteroids[i])))
                st.pop(); // after collision both will destroy

            else if (st.empty() || (!st.empty() && st.top() < 0))
                st.push(asteroids[i]);
        }
    }

    // remove and add elements into vector from stack.
    vector<int> res(st.size(), 0);
    for (int i = st.size() - 1; i >= 0; i--)
    {
        res[i] = st.top();
        st.pop();
    }

    return res;
}

int main()
{

    return 0;
}
