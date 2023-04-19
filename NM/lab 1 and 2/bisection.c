#include <stdio.h>
#include <math.h>

float a, b, c;

float func(float x){
    return cos(x) - x * exp(x);
}

int checkInterval(float a, float b)
{
    if(func(a) * func(b) < 0){
        return 1;
    }

    else{
        return 0;
    }
}

void bisection()
{
    c = (a + b) / 2;

    if(checkInterval(a, c) == 1){
        b = c;
    }

    else{
        a = c;
    }
}

int main()
{
    int cnt = 0;
    do
    {
        printf("Enter the start of the interval: ");
        scanf("%f", &a);
        printf("Enter the end of the interval: ");
        scanf("%f", &b);
    } while (checkInterval(a, b) == 0);
    
    do
    {
        bisection();
        cnt++;
    } while (fabs(func(c)) > 0.0005 && cnt < 100);
    

    if(fabs(func(c)) <= 0.0005 && cnt < 100){
        printf("\nRoot is: %f", c);
    }

    else if(cnt >= 100){
        printf("Root is not found");
    }

    return 0;
}