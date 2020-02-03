#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=5;
    char c;
    //condition ? Expression1: Expression2
    c=(a<10)? 'S': 'L';

    //condition ? (condition ? expression1:expression2):expression2
    c=(a<10)?((a<5)? 'S':'L'):('L');

    return 0;


}
