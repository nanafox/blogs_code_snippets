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
	char *line = malloc(sizeof("Hello, world!"));

	strcpy(line, "Hello, world!");

	/* print the result */
	printf("Output: %s\n", line);

	printf("Address before free [%p]\n", (void *)line);
	free(line);

	/*
	 * in this version we take care of setting the pointer to NULL right after
	 * freeing it to avoid the issue of dangling pointers. This way we are
	 * avoiding the issue of double frees when we try to free again. This is
	 * line with how the the 'free' function works. Quoting from the man page
	 * "If ptr is NULL, no operation is performed."
	 */
	line = NULL;

	printf("Address before free [%p]\n", (void *)line);

	/*
	 * this won't cause a double free error because the pointer is already NULL
	 * and the 'free' function performs no operation on NULL pointers
	 */
	free(line);

	return (0);
}
