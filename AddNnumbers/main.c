#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,sum=0,c,value;
    printf("Enter the number of integers you want to add:\n");
    scanf("%d",&n);
    printf("Enter %d integers\n",n);

    printf("Enter %d numbers of integers\n",n);

    for(c=1;c<=n;c++){
        scanf("%d",&value);
        sum=sum+value;
    }
    printf("The sum of the %d integers is:%d",n,sum);

    return 0;

}
