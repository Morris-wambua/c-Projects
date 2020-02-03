#include <stdio.h>
#include <stdlib.h>

long fact(int);
int main()
{

   int line,j,i;
   printf("Enter the number of lines:");
   scanf("%d",&line);

   for (i=0;i<line;i++){
    for (j=0;j<line-i-1;j++){
        printf(" ");

    }
    for (j=0;j<=i;j++){
        printf("%ld",fact(i)/(fact(j)*fact(i-j)));
    }
    printf("\n");
   }
    return 0;
}
long fact(int num){
    long f=1;
    int i=1;

    while (i<=num){
        f=f*i;
        i++;
    }
    return f;

}
