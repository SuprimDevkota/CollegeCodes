#include <iostream>
using namespace std;

float function(float x, float y)
{
    return x + y;
}

void Euler(float x0, float y0, float n, float h, float xn)
{
    for(int i = 0; i < n; ++i)
    {
        y0 = y0 + h * function(x0, y0);
        x0 = x0 + h;

        cout << x0 << '\t' << y0 << endl;
        if(x0 > xn)
        {
            return;
        }
    }
}

void Rk2(float x0, float y0, float n, float h, float xn)
{
    float k1, k2, k;
    float y1;

    for(int i = 0; i < n; ++i)
    {
        k1 = h * function(x0, y0);
        k2 = h * function(x0 + h, y0 + k1);
        k = 0.5 * (k1 + k2);

        y1 = y0 + k;
        x0 = x0 + h;
        y0 = y1;

        cout << x0 << '\t' << y1 << endl;
    }
}

void Rk4(float x0, float y0, float n, float h, float xn)
{
    float k1, k2, k3, k4, k;
    float y1;

    for(int i = 0; i < n; ++i)
    {
        k1 = h * function(x0, y0);
        k2 = h * function(x0 + h/2, y0 + k1/2);
        k3 = h * function(x0 + h/2, y0 + k2/2);
        k4 = h * function(x0 + h, y0 + k3);

        k = (1.0/6.0) * (k1 + 2 * (k2 + k3) + k4); 

        y1 = y0 + k;
        x0 = x0 + h;
        y0 = y1;

        cout << x0 << '\t' << y1 << endl;
    }
}


int main()
{
    float x0, y0, n, xn, h;
    cout << "Enter the value of x0, y0, n and xn: ";
    cin >> x0 >> y0 >> n >> xn;

    h = (xn - x0) / n;

    cout << "x\ty" << endl;

    Euler(x0, y0, n, h, xn);
    //Rk2(x0, y0, n, h, xn); 
    //Rk4(x0, y0, n, h, xn); 

    return 0;

}