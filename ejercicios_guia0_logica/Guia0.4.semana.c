#include <stdio.h>

int main() {
    int i,dia=0;
    printf("Ingrese un numero del 1 al 7 para que le muestre el dia correspondiente\n");
    scanf("%d", &dia);
    switch (dia)
    {
    case 1:
        printf("Es el dia lunes\n");
        break;
    case 2:
        printf("Es el dia martes\n");
        break;
    case 3:
        printf("Es el dia miercoles\n");
        break;
    case 4:
        printf("Es el dia jueves\n");
        break;
    case 5:
        printf("Es el dia viernes\n");
        break;
    case 6:
        printf("Es el dia sabado\n");
        break;
    case 7:
        printf("Es el dia domingo\n");
        break;
    default:
        printf("El valor ingresado es incorrecto\n");
        break;
    }
    return 0;
}