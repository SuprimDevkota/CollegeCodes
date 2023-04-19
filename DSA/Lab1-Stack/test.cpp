#include <iostream>
using namespace std;

int main()
{
    int a = 3;
    int* ptr1 = new int(a);
    int* ptr2 = ptr1;

    *ptr2 = 5;
    *ptr1 = 9;

    cout << *ptr1 << " " << *ptr2;
}