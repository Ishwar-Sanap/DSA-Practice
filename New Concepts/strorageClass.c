#include<stdio.h>

extern int no; // can't access the external static golbal varible

//declaration
extern int value;
void func()
{
    register int cnt = 1;

    // no -- ;
    value--;
    cnt++;

    printf("%d\n",cnt);
}

int main()
{   
    func();

    printf("%d",value);


    return 0 ;
}