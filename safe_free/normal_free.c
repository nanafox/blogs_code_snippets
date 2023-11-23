#include <stdio.h>
#include <stdlib.h>

/**
 * main - a driver code to test memory deallocation functions
 *
 * Return: 0
 */
int main(void)
{
	char *line = malloc(sizeof("Hello, world!"));

	strcpy(line, "Hello, world!");

	/* print the result */
	printf("Output: %s\n", line);

	printf("Address before free [%p]\n", (void *)line);

	free(line);

	printf("Address after  free [%p]\n", (void *)line);
	/*
	 * this will cause double free error since the memory has been previously
	 * deallocated and we are trying to free again. This is because the
	 * original 'free' function doesn't check the validity of the pointer
	 * passed to it before freeing it.
	 */
	free(line);

	return (0);
}
