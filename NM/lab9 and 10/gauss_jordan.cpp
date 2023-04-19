#include <iostream>
#include <math.h>
#define size 4
using namespace std;

float a[size][size+1];
float X[size];

void gauss_jordan()
{
    for(int i = 0; i < size; ++i)
    {
        if(a[i][i] == 0){
            cout << "Mathematical Error!";
            return;
        }

        for(int j = 0; j < size; ++j)
        {
            if(i != j)
            {
                float ratio = a[j][i] / a[i][i];

                for(int k = 0; k < size + 1; ++k)
                {
                    a[j][k] -= ratio * a[i][k];
                    /*if(fabs(a[j][k]) < 0.005){
                        a[j][k] = 0;
                    }*/
                }
            }
        }
    }
}

int main()
{
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size + 1; ++j)
        {
            cout << "Enter a" << i << j << ": ";
            cin >> a[i][j];
        }
    }

    gauss_jordan();

    cout << "The " << size << " unknowns are: ";
    for(int i = 0; i < size; ++i)
    {
        X[i] = a[i][size] / a[i][i];
        cout << X[i] << " ";
    }

    return 0;
}