#include <iostream>
using namespace std;

void tower_of_hanoi(int n, char source, char dest, char aux)
{
    if(n == 1)
    {
        cout << "Move disc 1 from " << source << " to " << dest << endl;
        return;
    }

    tower_of_hanoi(n - 1, source, aux, dest);
    cout << "Move disk " << n << " from " << source << " to " << dest << endl;
    tower_of_hanoi(n - 1, aux, dest, source);
}

int main()
{
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    tower_of_hanoi(n, 'A', 'C', 'B');
}