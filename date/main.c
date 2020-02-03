#include <stdio.h>
#include <stdlib.h>

int main()
{
   time_t t;
   time(&t);
   printf("Today's date and time :%s",ctime(&t));
    return 0;
}
