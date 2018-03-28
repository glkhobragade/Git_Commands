#include<stdio.h>
#include<math.h>
#include<sin.h>


extern int a;

int main()
{
    int b;
    b = 10;

    sq(b);
    cube(b);

    printf("\nThe value of extern int is %d", a);

    return 0;
}
