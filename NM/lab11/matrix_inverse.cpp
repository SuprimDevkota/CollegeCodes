#include <iostream>
#include <math.h>
#define size 3
using namespace std;

float a[size][2*size];

void inverse()
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

                for(int k = 0; k < 2 * size; ++k)
                {
                    a[j][k] -= ratio * a[i][k];
                    if(fabs(a[j][k]) < 0.005){
                        a[j][k] = 0;
                    }  
                }
            }
        }
    }

    for(int i = 0; i < size; ++i)
    {
        for(int j = size; j < 2 * size; ++j)
        {
            a[i][j] = a[i][j]/a[i][i];
        }
    }

    cout << "Inverse of matrix is: " << endl;
    
    for(int i = 0; i < size; ++i)
    {
        for(int j = size; j < 2 * size ; ++j)
        {
            cout << a[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    for(int i = 0; i < size; ++i)
    {
        int j;
        for(j = 0; j < size; ++j)
        {
            cout << "Enter a" << i << j << ": ";
            cin >> a[i][j];
        }

        while(j < 2 * size)
        {
            if(j - size == i) a[i][j] = 1;
            else a[i][j] = 0;
            j++;
        }
    }

    inverse();

    return 0;
}