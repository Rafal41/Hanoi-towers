#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define HANOISIZE 3
#define FULLDATA
#define SHOWSTACK

void pushstack(int n, int (*stos)[HANOISIZE], int target);
int popstack(int (*stos)[HANOISIZE], int current);
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
    int temp;
    int count = 1;
    int limit = pow(2,HANOISIZE)-1;
    int elnr;

    if (HANOISIZE % 2 == 0)
    {
        temp = wiezatar;
        wiezatar = wiezarem;
        wiezarem = temp;
    }

    while (count <= limit)
    {
        
#ifdef FULLDATA
        printf("count = %d, wiezacur = %d, wiezatar = %d, wiezarem = %d\n", count, wiezacur, wiezatar, wiezarem);
#endif

        if (count % 3 == 1)
        {
            elnr = popstack(stos1, wiezacur);
            pushstack(elnr, stos1, wiezatar);
            // temp = wiezatar;
            // wiezatar = wiezarem;
            // wiezarem = temp;
        }
        else if (count % 3 == 2)
        {
       
            elnr = popstack(stos1, wiezacur);
            pushstack(elnr, stos1, wiezarem);
            // elnr = popstack(stos1, wiezacur);
            // pushstack(elnr, stos1, wiezatar);
            // temp = wiezacur;
            // wiezacur = wiezarem;
            // wiezarem = temp;
          
        }
        else // count % 3 == 0
        {
   
            elnr = popstack(stos1, wiezatar);
            pushstack(elnr, stos1, wiezarem);
            // elnr = popstack(stos1, wiezacur);
            // pushstack(elnr, stos1, wiezatar);
            // temp = wiezacur;
            // wiezacur = wiezarem;
            // wiezatar = temp;
            // wiezarem = 6 - wiezacur - wiezatar;
            
        }

        // if (count == (limit/2 + 1))
        // {
        //     temp = wiezacur;
        //     wiezacur = wiezatar;
        //     wiezatar = temp;

        // }

        count++;

        

#ifdef SHOWSTACK
    puts("in-while stack");
    showstack(stos1);
#endif      
    }


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


void pushstack(int n, int (*stos)[HANOISIZE], int target)
{
    int i = 0;

#ifdef FULLDATA
    printf("pushstack target = %d\n", target);
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
}

int popstack(int (*stos)[HANOISIZE], int current)
{
    int i = HANOISIZE - 1;
    int k = current - 1;
    int elnr;
#ifdef FULLDATA
    printf("popstack current = %d\n", current);
#endif    

    while (stos[k][i] == 0 && i >= 0)
        i--;
    
    if (i == -1)
    {
        puts("blad programu w popstack");
        exit(EXIT_FAILURE);
    }
    else  
    {
        elnr = stos[current-1][i];
        stos[current-1][i]= 0;
    } 
        
    return elnr;
}