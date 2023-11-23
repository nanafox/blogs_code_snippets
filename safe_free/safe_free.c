#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _free - frees dynamic memory memory in a much safer way
 * @ptr: a pointer to the memory location to free
 */
void _free(void **ptr)
{
	if (*ptr != NULL && ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

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

	printf("Address before _free [%p]\n", (void *)str);

	/*
	 * You can call this function as many times and it's guaranteed not to
	 * cause a double free error. Remember, we check for NULL before freeing.
	 * Also, the original 'free' function peforms no operation when the pointer
	 * is NULL. The '_free' function we are using checks to ensure the memory
	 * pointed by the pointer we give it hasn't been released yet.
	 */
	_free((void **)&str);
	_free((void **)&str);

	printf("Address after  _free [%p]\n", (void *)str);

	return (0);
}
