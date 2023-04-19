#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of data: ";
    cin >> n;

    float x[n], y[n];

    for(int i = 0; i < n; ++i)
    {
        cout << "Enter the value of x[" << i << "] and y[" << i << "]: ";
        cin >> x[i] >> y[i];
    }

    float xp;
    cout << "Enter the interpolating value: ";
    cin >> xp;

    float sum = 0, product = 1;

    for(int i = 0; i < n; ++i)
    {
        product = 1;

        for(int j = 0; j < n; ++j)
        {
            if(i != j)
            {
                product *= (xp - x[j])/(x[i] - x[j]);
            }
        }

        sum += product * y[i];
    }

    cout << "The interpolated value is: " << sum << endl;
    return 0;
}