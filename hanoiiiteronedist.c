#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define HANOISIZE 5
#define FULLDATA
#define SHOWSTACK

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

    int stepnumber = 1;                     // number of current step
    int limit = pow(2,HANOISIZE) - 1;       // total number of steps

    // variables to calculate number of ring which is currently moved
    int lt, lb;                             // limit top, limit bottom
    lb = 1;                                 // bottom limit set initially as step 1
    lt = pow(2, HANOISIZE) - 1;             // top limit set initially as maximum number of steps
    int rangemid = lt -(lt-lb)/2;           // comparative value represents the midpoint in given range; used for finding current step value; 
    int ringnumber = 0;                     // number of ring which is moved in current step
    int counter = 0;                        // number of times when range is narrowed until the current step is find

    int j = 0;                              // simple counter of while loop
    int totmoves;                                  // could 1 or 2 and tells how many times the tower shall be collectively moved
                                            // - tells whether the target tower is in distance 1 or 2 counting right from current tower

    
    int temp; 

    if (HANOISIZE % 2 == 0)                 // if size of tower is even then interchange the towers straightaway
    {
        temp = wiezatar;
        wiezatar = wiezarem;
        wiezarem = temp;
    }

    if (wiezacur < wiezatar)
    {
    if (abs(wiezacur - wiezatar) == 1)      // if target tower is in distance two from current tower then move the total tower 2 times
        totmoves = 1;
    if (abs(wiezacur - wiezatar) == 2)      // if target tower is in distance one from current tower then move the total tower 1 time
        totmoves = 2;
    }
    else
    {
    if (abs(wiezacur - wiezatar) == 1)      // if target tower is in distance two from current tower then move the total tower 2 times
        totmoves = 2;
    if (abs(wiezacur - wiezatar) == 2)      // if target tower is in distance one from current tower then move the total tower 1 time
        totmoves = 1;
    }

    while (j < totmoves)
    {
        while (stepnumber <= limit)
        {
            if (stepnumber % 2 == 1)        // in each even step the smallest ring is moved
            {
                wiezatar = wiezacur + 1;
                if (wiezatar > 3)
                    wiezatar -= 3;
                wiezarem = 6 - wiezatar - wiezacur;
#ifdef FULLDATA
        printf("loop = %d, stepnumber = %d, n = 1, wiezacur = %d, wiezatar = %d, wiezarem = %d\n",j, stepnumber, wiezacur, wiezatar, wiezarem);
#endif
                pushstack(1, stos1, wiezatar);
                popstack(1, stos1, wiezacur);
            }
            else 
            {
                while (stepnumber != rangemid)
                {
                    rangemid = lt -(lt-lb)/2;
                    printf("num = %d, rangemid = %d, lt = %d, lb = %d\n", stepnumber, rangemid, lt, lb);
                    if (stepnumber < rangemid)                      // changing boundaries of the range
                        lt = rangemid - 1;
                    else if (stepnumber > rangemid)
                        lb = rangemid + 1;
                    else                                            // if new rangemid val is equal stepnumber then break now and do not increase counter
                        break;

                    counter++;
                } 
                ringnumber = HANOISIZE - counter;
                /**************************************************/
                if (ringnumber % 2 == 0)                             // if even move left
                {
                    wiezatar = wiezacur - 1;
                    if (wiezatar < 1)
                        wiezatar += 3;
                    wiezarem = 6 - wiezatar - wiezacur;
#ifdef FULLDATA
        printf("loop = %d, stepnumber = %d, ringnumber = %d, wiezacur = %d, wiezatar = %d, wiezarem = %d\n", j, stepnumber, ringnumber, wiezacur, wiezatar, wiezarem);
#endif
                    pushstack(ringnumber, stos1, wiezatar);
                    popstack(ringnumber, stos1, wiezacur); 

                    wiezacur = wiezacur + 1;
                    if (wiezacur > 3)
                        wiezacur -=3;
                }
                else // ringnumber % 2 != 0                         // if odd move right
                {     
                    wiezacur = wiezacur - 1;
                    if (wiezacur < 1)
                        wiezacur += 3;
                    wiezatar = wiezacur + 1;
                    if (wiezatar > 3)
                        wiezatar -= 3;
                    wiezarem = 6 - wiezatar - wiezacur;
#ifdef FULLDATA
        printf("loop = %d, stepnumber = %d, ringnumber = %d, wiezacur = %d, wiezatar = %d, wiezarem = %d\n", j, stepnumber, ringnumber, wiezacur, wiezatar, wiezarem);
#endif
                    pushstack(ringnumber, stos1, wiezatar);
                    popstack(ringnumber, stos1, wiezacur);

                    wiezacur = wiezacur - 1;
                    if (wiezacur < 1)
                        wiezacur += 3;
                    
                }
            }

            stepnumber++;  

            // resetting the boundaries for the next search
            lb = 1;
            lt = pow(2, HANOISIZE) - 1;             
            rangemid = lt -(lt-lb)/2;
            counter = 0;  
    
#ifdef SHOWSTACK
        puts("in-while stack");
        showstack(stos1);
#endif      
        }
        
        j++;

        wiezacur = wiezacur + 1;
        if (wiezacur > 3)
            wiezacur -= 3;
        wiezatar = wiezacur + 1;
        if (wiezatar > 3)
            wiezatar -= 3;
        wiezarem = 6 - wiezatar - wiezacur;

        // resetting the parameters for moving the total tower second time
        stepnumber = 1;
        lb = 1;
        lt = pow(2, HANOISIZE) - 1;
        rangemid = (lt-lb)/2 + 1;
        counter = 0;  
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

void popstack(int n, int (*stos)[HANOISIZE], int current)
{
    int i = HANOISIZE - 1;
    int k = current - 1;

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
        stos[current-1][i]= 0;
}