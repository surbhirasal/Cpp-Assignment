#include <iostream>
using namespace std;

struct LayoutA
{
    char c1;
    int i;
    char c2;
};

struct LayoutB
{
    int i;
    char c1;
    char c2;
};

int main()
{
    cout << "Size of LayoutA: " << sizeof(LayoutA) << endl;
    cout << "Size of LayoutB: " << sizeof(LayoutB) << endl;

    return 0;
}


/*
This program shows structure padding and member order. The compiler adds extra memory called padding for proper memory alignment.
Although both structures have the same members, their order can change their size. sizeof() is used to find the total memory occupied by each structure.
*/