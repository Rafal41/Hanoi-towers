#include <stdio.h>
#include <math.h>
#define HANOISIZE 3

int main(void)
{
    int lt, lb; // limit top, limit bottom
    int num;
    lb = 1;
    lt = pow(2, HANOISIZE) - 1;
    printf("podaj liczbe z przedzialu %d-%d\n",lb,lt);
    scanf("%d", &num);
    int m = 0;
    int val = (lt-lb)/2 + 1; 
    // int counter = -1;
    // do
    // {
    //     val = lt -(lt-lb)/2;
    //     printf("num = %d, val = %d, lt = %d, lb = %d\n", num, val, lt, lb);
    //     if (num < val)
    //         lt = val-1;
    //     else 
    //         lb = val+1;
        
    //     counter++;
    // } while (num != val);


    int counter = 0;
    while (num != val)
    {
        val = lt -(lt-lb)/2;
        printf("num = %d, val = %d, lt = %d, lb = %d\n", num, val, lt, lb);
        if (num < val)
            lt = val-1;
        else if (num > val)
            lb = val+1;
        else 
            break;
        // if (num != val)
        counter++;
    } 
    m = HANOISIZE - counter;

    printf("liczba ktora podales to %d, a jej wartosc to %d\n", num, m);

}
