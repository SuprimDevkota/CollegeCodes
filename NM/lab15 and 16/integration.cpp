#include <iostream>
using namespace std;

float function(float x)
{
    return (1 / (1 + x * x));
}

float trapezodial(float a, float b, int n)
{
    float h = (b - a) / n;

    float x[n], y[n];

    for (int i = 0; i < n + 1; i++)
    {
        x[i] = a + i * h;
        y[i] = function(x[i]);
    }

    float s = 0;

    for (int i = 1; i < n; ++i)
    {
        s += 2 * y[i];
    }

    return 0.5 * (y[0] + y[n] + s);
}

float onethird(float a, float b, int n)
{
    float h = (b - a) / n;

    float x[n], y[n];

    for (int i = 0; i < n + 1; i++)
    {
        x[i] = a + i * h;
        y[i] = function(x[i]);
    }

    float se = 0, so = 0;

    for (int i = 1; i < n; ++i)
    {
        if(i % 2 == 0)
        {
            se += y[i];
        }
        
        else
        {
            so += y[i]; 
        }
    }

    return (1/3.0) * (y[0] + y[n] + 4 * so + 2 * se);
}

float threeeight(float a, float b, int n)
{
    
}

int main()
{
    float a, b;
    int n;
    cout << "Enter the starting value, ending value and n: ";
    cin >> a >> b >> n;
    // cout << "The calcuated value is: " << trapezodial(a, b, n);
    cout << "The calcuated value is: " << onethird(a, b, n);
}