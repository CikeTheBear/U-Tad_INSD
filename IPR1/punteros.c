#include <stdio.h>

void changeValue(char *letter) {
    *letter = 'b';
}



int main () {
char l;
l = 'a';

changeValue(&l);

printf("%c\n", l);

return 0;



}