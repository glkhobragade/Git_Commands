g++  -c -Wall -Werror -fpic   sqrt.cpp
g++ -shared -o libsq.so sqrt.o
g++ -o test dlopen.c  -ldl
g++ -o test1 dlopen1.c  -ldl

