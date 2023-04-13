#include <stdio.h>
#include <stdlib.h>
#define HANOISIZE 3
// #define FULLDATA
#define SHOWSTACK

void fun(int n, int current, int target, int remaining, int (*stos)[HANOISIZE]);
void pushstack(int n, int (*stos)[HANOISIZE], int target);
void popstack(int n, int (*stos)[HANOISIZE], int current);
void showstack(int stos[][HANOISIZE]);

int main(void)
{
    int stos1[3][HANOISIZE];
    for (int i = 0; i < 3 ; i++)
        for (int j = 0; j < HANOISIZE; j++)
            stos1[i][j] = 0;
    int elem = HANOISIZE;
    int wiezatar, wiezacur, wiezarem = 6;

    puts("Podaj na ktorej wiezy znajduja sie klocki (1-2-3)");
   
    while (scanf("%d", &wiezacur) && (wiezacur < 1 && wiezacur > 3))
    {
       puts("Podano niepoprawny numer wiezy");
       puts("Podaj na ktorej wiezy znajduja sie klocki (1-2-3)"); 
    }
    wiezarem -= wiezacur;
    puts("Podaj na ktora wieze maja byc przeniesione klocki (1-2-3)");
   
    while (scanf("%d", &wiezatar) && (wiezatar < 1 && wiezatar > 3))
    {
       puts("Podano niepoprawny numer wiezy");
       puts("Podaj na ktora wieze maja byc przeniesione klocki (1-2-3)"); 
    } 
    wiezarem -= wiezatar;

    for (int i = 0; i < HANOISIZE; i++)
        stos1[wiezacur-1][i] = HANOISIZE-i;


    puts("entry stack");
    showstack(stos1);

    fun(elem, wiezacur, wiezatar, wiezarem, stos1);

    puts("final stack");
    showstack(stos1);

    return 0;
}


void showstack(int (*stos)[HANOISIZE])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < HANOISIZE; j++)
            printf("%d  ", stos[i][j]);
        putchar('\n');
    }
    putchar('\n');
}

void fun(int n, int current, int target, int remaining, int (*stos)[HANOISIZE])
{
    int temp;
    
#ifdef FULLDATA
    printf("n = %d, current = %d, target = %d, remaining = %d\n", n, current, target, remaining);
#endif

    if (n > 1)
    {
        temp = target;
        target = remaining;
        remaining = temp;
        fun(n-1, current, target, remaining, stos);
        temp = remaining;
        remaining = target;
        target = temp;

    }

#ifdef FULLDATA
    printf("n = %d, current = %d, target = %d, remaining = %d\n",n, current, target, remaining);
#endif

    pushstack(n, stos, target); 
    popstack(n, stos, current);

#ifdef SHOWSTACK
    puts("in-function stack");
    showstack(stos);
#endif

    if (n > 1)
    {
        temp = remaining;
        remaining = current;
        current = temp;
        fun(n-1, current, target, remaining, stos);
        temp = current;
        current =  remaining;
        remaining = temp;
    }

}

void pushstack(int n, int (*stos)[HANOISIZE], int target)
{
    int i = 0;

#ifdef FULLDATA
    printf("pushstack target = %d\n", target);
    puts("pushstack");
    showstack(stos);
#endif

    while (stos[target-1][i] != 0 && i < HANOISIZE)
        i++;
        
    if (i == HANOISIZE)
    {
        puts("blad programu w pushstack");
        exit(EXIT_FAILURE);
    }
    else   
        stos[target-1][i]= n;

#ifdef FULLDATA
    puts("pushstack koniec");
    showstack(stos);
#endif
}

void popstack(int n, int (*stos)[HANOISIZE], int current)
{
    int i = HANOISIZE - 1;
    int k = current - 1;

#ifdef FULLDATA
    printf("popstack current = %d\n", current);
    puts("popstack");
    showstack(stos);
#endif    

    while (stos[k][i] == 0 && i >= 0)
        i--;
    
    if (i == -1)
    {
        puts("blad programu w popstack");
        exit(EXIT_FAILURE);
    }
    else   
        stos[current-1][i]= 0;

#ifdef FULLDATA
    puts("popstack koniec");
    showstack(stos);
#endif
}