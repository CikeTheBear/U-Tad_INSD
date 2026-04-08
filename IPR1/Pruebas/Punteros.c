#include <stdio.h>

int main(void)

{

   int a;

   int *punt1;

   int *punt2; 

 

   a = 10;

   punt1 = &a;            /* (1) */

   punt2 = punt1;         /* (2) */

   printf(" El valor %d está en la posición %x ", *punt2, punt2);

   return 0;

}