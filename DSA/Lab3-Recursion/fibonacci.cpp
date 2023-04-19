#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if(n == 1 || n == 2) return 1;

    return fibonacci(n-1) + fibonacci(n-2);

}

int tail_fibonacci(int n, int a = 1, int b = 1)
{
    if(n == 1) return a;
    else if(n == 2) return b;

    else return tail_fibonacci(n - 1, b, a + b);

}

int main()
{
    int n;
    cout << "Enter the number to calculate fibonacci: ";
    cin >> n;
    cout << fibonacci(n) << endl;
    cout << tail_fibonacci(n)<< endl;
}