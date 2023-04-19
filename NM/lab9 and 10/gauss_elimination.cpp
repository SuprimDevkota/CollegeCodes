#include <iostream>
#include <math.h>
#define size 3
using namespace std;

float a[size][size + 1];
float X[size];

void display_matrix()
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size + 1; ++j)
        {
            cout << a[i][j] << '\t';
        }
        cout << endl;
    }
}

void gauss_elimination()
{
    for (int i = 0; i < size; ++i)
    {
        if (a[i][i] == 0)
        {
            cout << "Mathematical Error" << endl;
            return;
        }

        for (int j = i + 1; j < size; ++j) //
        {
            float ratio = a[j][i] / a[i][i];

            for (int k = 0; k < size + 1; ++k)
            {
                a[j][k] -= ratio * a[i][k];
                if (fabs(a[j][k]) < 0.005)
                {
                    a[j][k] = 0;
                }
            }
        }
    }
}

void get_solution()
{
    X[size-1] = a[size - 1][size] / a[size-1][size-1]; //stores last unknown

    for (int i = size - 2; i >= 0; i--)
    {
        X[i] = a[i][size]; //stores intial coefficient

        for (int j = i + 1; j < size; j++)
        {
            X[i] -= a[i][j] * X[j];
        }

        X[i] = X[i] / a[i][i];
    }
}
int main()
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size + 1; ++j)
        {
            cin >> a[i][j];
        }
    }

    gauss_elimination();

    get_solution();

    cout << "The " << size << " unknowns are: ";
    for (int i = 0; i < size; ++i)
    {
        cout << X[i] << " ";
    }

    return 0;
}