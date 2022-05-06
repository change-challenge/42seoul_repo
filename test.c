#include <stdio.h>

int main()
{
	char *a = "2457";
	char *b = a+2;



	printf("%p |%s|\n", a, a);
	printf("%p |%s|\n", b, b);
	printf("%ld\n", b-a);
	// printf("%s\n", b-a);
	// printf("%s\n", (char*)c);
	// printf("%zu\n", c);
	// printf("%zx\n", c);
	// printf("%zd\n", c);
}