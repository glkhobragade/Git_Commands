g++  -c -Wall -Werror -fpic   sqrt.cpp
g++ -shared -o libsq.so sqrt.o
g++ --std=c++11 -fpermissive -rdynamic -g3 -o test dlopen.c  -ldl
g++ --std=c++11 -fpermissive -rdynamic -g3 -o test1 dlopen1.c  -ldl

