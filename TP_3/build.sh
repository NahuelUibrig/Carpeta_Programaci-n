gcc -c Tp3_Nahuel_Uibrig.c -o main.o
gcc -c functions.c -o funcs.o
gcc main.o funcs.o -o programa
./programa