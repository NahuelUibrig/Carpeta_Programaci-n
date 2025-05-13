gcc -c main.c -o main.o
gcc -c functions.c -o funcs.o
gcc main.o funcs.o -o programa
./programa