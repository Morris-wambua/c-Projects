#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    printf("Enter the three numbers: ");
    scanf("%d%d%d",&a,&b,&c);
    if(b<c)
    {
        printf("Largest number is: %d ",c );

    }
    else
        if(b>c)
    {
        printf("Largest number is: %d ",b );
    }
    else
    {
        printf("Largest number is: %d" ,a);
    }

}
