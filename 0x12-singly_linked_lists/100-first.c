#include "lists.h"

void cmsbefore(void) __attribute__ ((constructor));

/**
 * cmsbefore - a function that prints before the main function is executed
 */

void cmsbefore(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
