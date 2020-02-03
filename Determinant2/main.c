#include <stdio.h>
#include <stdlib.h>

int main()
{
int a[2][2],i,j;
long deteminant;

printf("Enter the 4 elements of the matrix:\n");
for(i=0;i<2;i++)
    for(j=0;j<2;j++)
    scanf("%d",&a[i][j]);
printf("\nThe matrix is\n");
for(i=0;i<2;i++)
{
    printf("\n");
    for(j=0;j<2;j++)
        printf("%d\t",a[i][j]);
}
deteminant=a[0][0]*a[1][1]-a[1][0]*a[0][1];
printf("\nDeterminant of 2X2 matrix :%ld",deteminant);
    return 0;
}
