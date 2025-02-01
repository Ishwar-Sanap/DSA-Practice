#include <bits/stdc++.h>
using namespace std;


/*
Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for which the stock price was less than or equal to the price of that day.

For example, if the prices of the stock in the last four days is [7,2,1,2] and the price of the stock today is 2, then the span of today is 4 because starting from today, the price of the stock was less than or equal 2 for 4 consecutive days.
*/

/* 			One price will be pushed once and popped once.
			So 2 * N times stack operations and N times calls. For all next() calls 
			For individual next() call T.C will be O(1)
*/
class StockSpanner {
public:
    // stack will store the pair of elements
    // first will store the price and second in how many elements previosly occured less than or equal to price
    stack<pair<int,int>>st; 
    StockSpanner() {
        
    }
    int next(int price) {
        
        int cnt = 1;
        while(!st.empty() && st.top().first <= price)
        {
            cnt += st.top().second;
            st.pop();
        }
        
        st.push({price, cnt});
        return cnt;
    }
};

int main()
{

    return 0;
}
