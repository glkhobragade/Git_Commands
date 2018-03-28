/* main.c */
void swap();

extern int buf[]; 
int x  =1;

void xx()
{
    int l = 0;
}
int main()
{
    printf("\n%d %d", buf[0], buf[1]);
    swap();
    printf("\n%d %d", buf[0], buf[1]);
    return 0;
}
