#include <bits/stdc++.h>
using namespace std;

void getAllParanthesis(int openCnt, int closeCnt, vector<string> &res, string temp, int n)
{

    if((openCnt + closeCnt ) == 2*n)
    {
        res.push_back(temp);
        return;
    }

    // take opening bracket
    if(openCnt < n )
    {
        temp.push_back('(');
        getAllParanthesis(openCnt+1,closeCnt,res,temp,n);
        temp.pop_back();
    }
    
    // take closing bracket when only the paranthesis is valid.
    if(closeCnt < openCnt )
    {
        temp.push_back(')');
        getAllParanthesis(openCnt,closeCnt+1,res,temp,n);
        temp.pop_back();
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> res;
    string temp = "";
    int openCnt = 0, closeCnt = 0;

    getAllParanthesis(openCnt, closeCnt, res, temp, n);

    return res;
}

int main()
{
    vector<string> parm = generateParenthesis(3);
    for(string str: parm)
        cout<<str<<endl;

    return 0;
}