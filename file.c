#include<stdio.h>
#include<unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include<fcntl.h>
int main()
{
	FILE *fp;
	fp = fopen("a.txt", "a+");
	if(!fp)
	printf("Opened file successfully");
	sleep(6);
	fclose(fp);
	return 0;
}
