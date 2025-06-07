gcc -c Tp2_Nahuel_Uibrig.c -o main.o
gcc -c funciones.c -o funcs.o
gcc main.o funcs.o -o programa
./programa