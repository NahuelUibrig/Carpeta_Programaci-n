#include <stdio.h>

int main() {
    int i,numero=0,memoria=0,suma=0;
    printf("Ingrese numero a sumar, con 0 se termina la suma \n");
    scanf("%d", &numero);
    suma=numero;
    if(numero!=0){
        for(i=0;numero!=0;i++){
        if(numero>memoria)
            memoria=numero;
        printf("Ingrese numeros a sumar, con 0 se termina la suma \n");
        scanf("%d", &numero);  
        suma=suma+numero; 
        }             
        printf("El numero mas grande es: %d \n",memoria); 
        printf("La suma de todos los numeros es: %d \n",suma);
    } 
    return 0;
}