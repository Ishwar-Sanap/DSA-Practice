#include <bits/stdc++.h>
using namespace std;

/*
    What is Smart pointers ???

Smart pointers in C++ are wrapper classes around raw pointers that manage memory automatically.
They help prevent memory leaks and dangling pointers by ensuring proper deallocation of dynamically allocated memory.

Types of Smart Pointers
C++ provides three types of smart pointers in the <memory> header:

1) std::unique_ptr – Exclusive ownership (cannot be copied)
2) std::shared_ptr – Shared ownership (reference counting)
3) std::weak_ptr – Non-owning reference (used with shared_ptr to prevent cyclic references)

*/

// With Smart pointer
int fun2()
{
    // creating the object of unique_ptr class, this class is wrapper class for raw pointer.
    // iptrArr it is object, but it work like normal pointers, all opertor are overloaded by unique_ptr class

    unique_ptr<int> iptr(new int(51));
    cout<<"owener 1 : " <<*iptr<<endl;

     /* If we want to get the stored raw pointer from class object*/
     // int* ptr = iptr.get();

     /*as name suggest unique_ptr, no any other pointer can points to the same memory location
        - Ensures that only one smart pointer owns a resource
        - Automatically deletes the resource when it goes out of scope.
        - Cannot be copied, but can be moved.

     */

    // unique_ptr<int>iptr2 = iptr;  copy not allowed
    unique_ptr<int>iptr2 =  move(iptr);  // owernership moved to iptr2, now so iptr will be null..
    cout<<"owener 2 : " <<*iptr2<<endl;

//    iptr2.reset(new int(101)); // The deleter will be invoked if a pointer is already owned. and
//   // replace the stored pointer with new given address 

    
  cout<<"owener 2 new value : " <<*iptr2<<endl;

    if (true)
    {
        return 1;
    }

    // no need for manual memory deletion,
    // since we have created local object of class, when funciton finishes execution,
    // automatically unique_ptr destructor is called, and it will free the allocated resources
}

// Without Smart pointer
int fun1()
{
    int *iptr = new int(11); // creating the integer dynamically

    cout << *iptr << endl;

    // if there is some conditon that end's the function
    if (true)
    {
        // if this condition is executed then, there will be memory leak
        // since below part of memory deletation will not work..
        return 1;
    }

    delete iptr;
    iptr = nullptr;
}
int main()
{
    fun1();

    fun2();

    return 0;
}