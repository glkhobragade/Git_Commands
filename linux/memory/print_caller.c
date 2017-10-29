/* print_caller.c */
#include <stdio.h>
void
print_function(void *p) {
    char cmd[128];
    FILE *fp;
    /* syntax to convert address into file name and line number, -f option to get caller name*/
    snprintf(cmd, sizeof(cmd), "addr2line -e %s -f %p", "print_caller", p);
    fp = popen(cmd, "r");
    if (fp) {
        char buf[128];
        while (fgets(buf, sizeof(buf), fp)) {
            printf("%s", buf); 
        }
    }
}
void
f2(void) {
    print_function(__builtin_return_address(0));
}
void
f1(void) {
    f2();
}
int
main(int argc, char *argv[]) {
    f1();
    return(0);
}
