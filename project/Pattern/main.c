#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j;
    printf("\n the pattern is\n");

    for(i=0;i<=4;i++){
        for(j=0;j<=i;j++){
            printf("*");
        }
    }
    return 0;
}
