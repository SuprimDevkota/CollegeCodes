#include <iostream>
using namespace std;

float f(float x, float y, float z)
{
    return 1 + x * z;
}

float g(float x, float y, float z)
{
    return - x * y;
}

int main()
{
    float x0, y0, z0, h, xn;
    float k, k1, k2, k3, k4, l, l1, l2, l3, l4;
    cout << "Enter the values of x0, y0, z0, h and xn: ";
    cin >> x0 >> y0 >> z0 >> h >> xn;

    while (x0 < xn)
    {
        k1 = h * f(x0, y0, z0);
        l1 = h * g(x0, y0, z0);
        k2 = h * f(x0 + h / 2, y0 + k1 / 2, z0 + l1 / 2);
        l2 = h * g(x0 + h / 2, y0 + k1 / 2, z0 + l1 / 2);
        k3 = h * f(x0 + h / 2, y0 + k2 / 2, z0 + l2 / 2);
        l3 = h * g(x0 + h / 2, y0 + k2 / 2, z0 + l2 / 2);
        k4 = h * f(x0 + h, y0 + k3, z0 + l3);
        l4 = h * g(x0 + h, y0 + k3, z0 + l3);

        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        l = (l1 + 2 * l2 + 2 * l3 + l4) / 6;

        x0 = x0 + h;
        y0 = y0 + k;
        z0 = z0 + l;
    }

    cout << "x0 = " << x0 << " y0= " << y0 << " z0= " << z0 << endl;
    return 0;
}