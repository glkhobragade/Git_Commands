#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>
#include <unistd.h>

int main(int argc, char **argv) {
	void *handle;
    double *p;
    double *q;
    int (*sqq)(int);
	char *error;

	handle = dlopen ("libsq.so", RTLD_NOW);
	if (!handle) {
		fputs (dlerror(), stderr);
		exit(1);
	}

    p = (double *)dlsym(handle, "PII");
    //sqq  = reinterpret_cast<sqq>(dlsym(handle, "sq"));
    //sqq  = dlsym(handle, "_Z2sqi");  // if you dont provide extern for this function, then the function name will be mangled.
    // This function name is taken using nm command on sqrt.o file. But this is a hack, directly use the extern and make the compiler not to mangle
    // name of the function.
    //pow(5,2);
	if ((error = dlerror()) != NULL)  {
		fputs(error, stderr);
		exit(1);
	}
    sqq  = dlsym(handle, "sq");
	if ((error = dlerror()) != NULL)  {
		fputs(error, stderr);
		exit(1);
	}

	printf ("%f\n", *p);
    *p = 55;
    q = (double *)dlsym(handle, "PII");
	printf ("%f\n", *q);
	printf ("%d\n", (*sqq)(5));
	printf ("%d\n", (*sqq)(25));
	dlclose(handle);
}
