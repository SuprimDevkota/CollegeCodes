#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 1) return 1;

    return n * factorial(n - 1);
}

int tail_factorial(int n, int result = 1)
{
    if(n == 1) return result;

    return tail_factorial(n - 1, result * n);
}

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << factorial(n) << endl;
    //cout << tail_factorial(n) << endl;
}
