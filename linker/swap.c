/* swap.c */
int buf[] = {1,2};
double x;
int *bufp0 = &buf[0];
int *bufp1;
void swap()
{
    int temp;
    bufp1 = &buf[1];
    temp = *bufp0;
    *bufp0 = *bufp1;
    *bufp1 = temp;
    printf("==%d", x);
     

    xx();
}
