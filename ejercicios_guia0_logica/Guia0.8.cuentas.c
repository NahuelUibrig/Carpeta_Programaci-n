#include <stdio.h>

int main() {
    int valor1=0,valor2=0,resultado=0;
    char simbolo;

    printf("Se realizara una cuenta entre dos numeros, ingrese el primero\n");
    scanf(" %d",&valor1);
    printf("ingrese el segundo\n");
    scanf(" %d",&valor2);
    printf("ahora digite el tipo de operacion entre los dos valores, las opciones son:\n+ (suma)\n- (resta)\n* (multiplicar)\n/ (dividir)\n");
    scanf(" %c",&simbolo);
    switch (simbolo)
    {
    case '+':
        resultado=valor1+valor2;
        break;
    case '-':
        resultado=valor1-valor2;
        break;
    case '/':
        resultado=valor1/valor2;
        break;
    case '*':
        resultado=valor1*valor2;
        break;
    default:
        printf("simbolo invalido\n");
        break;
    }
    printf("El resultado es: %d\n",resultado);
    printf("\n");
    return 0;
}