#include <stdio.h>
#include <stdlib.h>
#define HANOISIZE 3


void hanoi(int n, char A, char B, char C);

int main(void)
{
    hanoi(3, 'C', 'A', 'B');

    return 0;
}

void hanoi(int n, char A, char B, char C)
{
    if (n > 0)
    {
        hanoi(n-1, A, C, B);
        printf("%c -> %c\n", A, C);
        hanoi(n-1, B, A, C);
    }
}
