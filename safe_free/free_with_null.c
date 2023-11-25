#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - a driver code to test memory deallocation functions
 *
 * Return: 0
 */
int main(void)
{
	char *str = malloc(sizeof("Hello, world!"));

	strcpy(str, "Hello, world!");

	/* print the result */
	printf("Output: %s\n", str);

	printf("Address before free [%p]\n", (void *)str);

	free(str);

	/*
	 * in this version we take care of setting the pointer to NULL right after
	 * freeing it to avoid the issue of dangling pointers. This way we are
	 * avoiding the issue of double frees when we try to free again. This is
	 * str with how the the 'free' function works. Quoting from the man page
	 * "If ptr is NULL, no operation is performed."
	 */
	str = NULL;

	printf("Address after  free [%p]\n", (void *)str);

	/*
	 * this won't cause a double free error because the pointer is already NULL
	 * and the 'free' function performs no operation on NULL pointers
	 */
	free(str);

	return (0);
}
