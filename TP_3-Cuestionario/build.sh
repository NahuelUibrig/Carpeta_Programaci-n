gcc -c main.c -o main.o
gcc -c Catedra_C3.c -o funcs.o
gcc main.o funcs.o -o programa
./programa