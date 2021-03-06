#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <math.h>

int main(int argc, char **argv) {
	void *handle;
	double (*cosine)(double);
    double *p;
	char *error;

	handle = dlopen ("/lib/x86_64-linux-gnu/libm.so.6", RTLD_DEEPBIND);
	if (!handle) {
		fputs (dlerror(), stderr);
		exit(1);
	}

    cosine = dlsym(handle, "cos");
    p = (double *)dlsym(handle, "M_PI");
    //pow(5,2);
	if ((error = dlerror()) != NULL)  {
		fputs(error, stderr);
		exit(1);
	}

	printf ("%f\n", (*cosine)(2.0));
	printf ("%f\n", *p);
	dlclose(handle);

    printf("\nForcing a segmentation fault: \n");
    *(char *)0 = 0;
}
