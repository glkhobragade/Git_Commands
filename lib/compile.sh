rm libtestmat.a  # ar command adds objects file to existing library, so multiple definition
# error can be found, so create new library archive file each time.
rm *.o
rm a.out
gcc -c -I. mat.c
gcc -c -I. sin.c
ar -cvq libtestmat.a mat.o sin.o
gcc main.c -I. libtestmat.a
#gcc main.c -I. -L. -ltestmat
./a.out

