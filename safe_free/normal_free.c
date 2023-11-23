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

	printf("Address after  free [%p]\n", (void *)str);
	/*
	 * this will cause double free error since the memory has been previously
	 * deallocated and we are trying to free again. This is because the
	 * original 'free' function doesn't check the validity of the pointer
	 * passed to it before freeing it.
	 */
	free(str);

	return (0);
}
