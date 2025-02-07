#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Demo
{
    public:
        int x;
        int y;

        Demo(): x(0) , y(0){};
        Demo(int x,int y)
        {
            this->x = x;
            this->y = y;
        }

};
int main()
{
    Demo obj;
    cout<<obj.x<<endl;
    return 0;
}