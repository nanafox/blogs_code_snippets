#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _free - frees dynamic memory allocated through a pointer to a pointer,
 * providing a safer and more convenient approach.
 *
 * @ptr: a pointer to the pointer pointing to the memory location to be freed.
 *
 * Description: This function takes a pointer to a pointer pointing to a
 * dynamically allocated memory location and frees the memory.
 * It also sets the original pointer to NULL to prevent potential dangling
 * pointers.
 *
 * Note: It is recommended to pass the address of the pointer to ensure proper
 * behavior and avoid undefined behavior when attempting to free an already
 * freed memory block.
 *
 * Example usage: `_free(&my_pointer);`
 */
void _free(void **ptr)
{
	/*
	 * check if the pointer and the memory it points to are not NULL
	 * before attempting to free
	 */
	if (*ptr != NULL && ptr != NULL)
	{
		/* free the memory and set the original pointer to NULL */
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
