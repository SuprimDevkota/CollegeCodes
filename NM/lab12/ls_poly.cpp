#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int d, n;
    cout << "Enter the degree of polynomial and number of data pair: ";
    cin >> d >> n;

    float x[n], y[n];
    float coefficients[d + 1][d + 2];
    float constants[d + 1];

    // Enter data pairs
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter the value for x[" << i << "]: ";
        cin >> x[i];
        cout << "Enter the value for y[" << i << "]: ";
        cin >> y[i];
    }

    //Make augumented matrix
    for(int i = 0; i < d + 1; ++i)
    {
        for(int j = 0; j < d + 1; ++j)
        {
            coefficients[i][j] = 0;
            for(int k = 0; k < n; ++k)
            {
                coefficients[i][j] += pow(x[k], i + j);
            }
        }
    }
    for(int i = 0; i < d + 1; ++i)
    {
        coefficients[i][d+1] = 0;
        for(int j = 0; j < n; ++j)
        {
            coefficients[i][d+1] += pow(x[j], i) * y[j];
        }
    }


    //Gauss Jordan
    for(int i = 0; i < d + 1; ++i)
    {
        if(coefficients[i][i] == 0)
        {
            cout << "Mathematical error! " << endl;
            return -1;
        }

        for(int j = 0 ; j < d + 1; ++j)
        {
            if(i != j)
            {
                float ratio = coefficients[j][i] / coefficients[i][i];

                for(int k = 0; k < d + 2; ++k)
                {
                    coefficients[j][k] -= ratio * coefficients[i][k];
                    if(fabs(coefficients[j][k]) < 0.005) {coefficients[j][k] = 0;}
                }
            }
        }
    }


    //Calculate constants
    for(int i = 0; i < d + 1; ++i)
    {
        constants[i] = coefficients[i][d+1] / coefficients[i][i];
    }

    cout << "The constants are: " << endl;
    for(int i = 0; i <= d; ++i)
    {
        char cons = 'a' + i;
        cout << cons << ": " << constants[i] << endl;
    }

    return 0;

}