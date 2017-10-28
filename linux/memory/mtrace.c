#include <stdio.h>
#include <stdlib.h>
#include <mcheck.h>
int main() {
	char *string;
	mtrace();
	string = malloc(100 * sizeof(char));
	return 0;
}
