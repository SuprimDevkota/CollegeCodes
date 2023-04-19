#include <iostream>
#include <math.h>
using namespace std;

float function (float x)
{
    //return x * x * x - 2;
    return 3*x - cos(x) - 1;
    //return exp(x) - 2;
    //return log(x) - 2;
}


float derivative(float x)
{
    return 3 + sin(x);
}


float newton_rhapson(float x)
{
    return (x - (function(x) / derivative(x)));
}


int main()
{
    float x, x_new;
    int cnt = 0;
    cout << "Enter the value of x: ";
    cin >> x;

    x_new = newton_rhapson(x);

    while(cnt < 100 && derivative(x_new) > 0)
    {
        x = x_new;
        x_new = newton_rhapson(x);
        cnt++;
    }

    if(fabs(x_new - x) < 0.005)
    {
        cout << "Root is: " << x_new << endl;
    }

    else{
        cout << "Root not found" << endl;
    }
}