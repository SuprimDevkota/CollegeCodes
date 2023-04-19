#include <iostream>
#define SIZE 5
using namespace std;

int main()
{
    float x[SIZE], y[SIZE], xy[SIZE], x_2[SIZE];
    float sum_x = 0, sum_y = 0, sum_xy = 0, sum_x_2 = 0;
    float a, b;

    for(int i = 0; i < SIZE; ++i)
    {
        printf("Enter the value for x[%d] and y[%d]: ", i, i);
        cin >> x[i];
        sum_x += x[i];
        cin >> y[i];
        sum_y += y[i];
        xy[i] = x[i] * y[i];
        sum_xy += xy[i];
        x_2[i] = x[i] * x[i];
        sum_x_2 += x_2[i];
    }

    a = (sum_y * sum_x_2 - sum_xy * sum_x) / (SIZE * sum_x_2 - sum_x * sum_x);
    b = (SIZE * sum_xy - sum_y * sum_x) / (SIZE * sum_x_2 - sum_x * sum_x);

    cout << "The best fit linear function is: y = " << a << " + " << b << " x" << endl; 
}