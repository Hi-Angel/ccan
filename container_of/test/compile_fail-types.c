#include "container_of/container_of.h"
#include <stdlib.h>

struct foo {
	int a;
	char b;
};

int main(int argc, char *argv[])
{
	struct foo foo = { .a = 1, .b = 2 }, *foop;
	int *intp = &foo.a;

#ifdef FAIL
	/* b is a char, but intp is an int * */
	foop = container_of(intp, struct foo, b);
#else
	foop = NULL;
#endif
	return intp == NULL;
}
