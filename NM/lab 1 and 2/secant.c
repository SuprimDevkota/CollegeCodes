#include <stdio.h>
#include <math.h>

float a, b, c;

float func(float x)
{
    return x * x - 3;
}

void secant()
{
    c = (a * func(b) - b * func(a)) / (func(b) - func(a));
    a = b;
    b = c;
}

int main()
{
    int cnt = 0;
    printf("Enter the start of the interval: ");
    scanf("%f", &a);
    printf("Enter the end of the interval: ");
    scanf("%f", &b);

    do
    {
        secant();
        cnt++;
    } while (fabs(func(c)) > 0.0005 && ((func(b) - func(a)) != 0) && cnt < 100);

    if (fabs(func(c)) <= 0.0005 && cnt < 100)
    {
        printf("\nRoot is: %f", c);
    }

    else if (cnt >= 100)
    {
        printf("Root is not found");
    }

    return 0;
}