#include <stdio.h>

#define MAX_SIZE 100

int main()
{
	char text[MAX_SIZE];
	char *str = text;
	int count = 0;
	char c;


	printf("Introduce una cadena:\n");
	gets(text);

	while((c = *(str++)) != '\0')
	{
		count++;
		printf("Count: %d - Char: %c\n", count, c);
	}

	printf("Longitud de '%s' = %d", text, count);
}