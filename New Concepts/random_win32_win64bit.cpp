#include <iostream>
using namespace std;
#include <iomanip> // for std::setprecision

/*
Win32 bit and Win64 the internal implementations of srand() 
and rand() functino is different so due to which they generates different
random numberes, even though same seed is provided to srand()

But if we want to generate similar random number like win32 bit on win64
bit platfrom then we have to mimic the internal algo of srand() & rand()
function, so we get consistent numbers... 
*/


static unsigned long my_next = 1;
void mysrand(unsigned int seed)
{
    my_next = seed;
}

int myrand()
{
    my_next = my_next * 214013L + 2531011L;
    return (my_next >> 16) & 0x7FFF;
}

int main()
{
    // CUSTOM Functinos
    mysrand(1000); // seed

    for (int i = 0; i < 6; ++i)
    {
        double normalized = (double)myrand() / 32767;
        // std::cout << std::fixed << std::setprecision(17) << normalized << std::endl;
        std::cout << std::fixed << std::setprecision << normalized << std::endl;
    }

    cout << "--------------------------------\n";

    // Inbuilt srand() and rand() functions
    srand(1000);
    for (int i = 0; i < 6; ++i)
    {
        double normalized = (double)rand() / 32767;
        std::cout << std::fixed << std::setprecision(17) << normalized << std::endl;
    }

    return 0;
}