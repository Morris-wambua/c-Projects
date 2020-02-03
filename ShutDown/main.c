#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    printf("Do you want to restart your computer now(y/n):");
    scanf("%c",&ch);

    if (ch=='y'|| ch=='Y')
        system("C:\\WINDOWS\\System32\\shutdown /r");
    return 0;
}
