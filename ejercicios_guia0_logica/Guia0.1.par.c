#include <stdio.h>

int main() {
    int numero;

    printf("Ingrese un numero\n");
    scanf("%d", &numero);
    if(numero%2==0)
    printf("El numero ingresado es par\n");
    else
    printf("El numero ingresado es impar\n");

    return 0;
}