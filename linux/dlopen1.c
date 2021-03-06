#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h>

int main(int argc, char **argv) {
	void *handle;
    double *p;
    typedef int(*sqq)(int);
	char *error;

	handle = dlopen ("libsq.so", RTLD_NOW);
	if (!handle) {
		fputs (dlerror(), stderr);
		exit(1);
	}

    p = (double *)dlsym(handle, "PII");
    //sqq sqr = reinterpret_cast<sqq>(dlsym(handle, "sq"));
    //pow(5,2);
	if ((error = dlerror()) != NULL)  {
		fputs(error, stderr);
		exit(1);
	}

	printf ("%f\n", *p);
	//printf ("%f\n", sqr(2));
	dlclose(handle);

}
