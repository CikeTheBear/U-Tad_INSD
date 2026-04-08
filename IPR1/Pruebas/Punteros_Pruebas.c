#include <stdio.h>

int increaseAge(int *age);
int suma1(int numero);

int main()
{

	/*int age = 34;
	int *pAge = &age;

	printf("%p\n", &age);
	printf("%p\n", pAge);

	printf("%d\n", age);

	increaseAge(&age);


	printf("%d\n", age);
*/

	int total = 6;

	printf("Antes de suma: %d\n", total);

	total = suma1(total);

	printf("Despues de suma: %d\n", total);




	return 0;
}

int increaseAge(int *age)
{
	(*age)++;
}

int suma1(int numero)
{
	int total = 0;

	total = numero + 1;

	return total;
}



