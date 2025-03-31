#include <stdio.h>

int main() {
    int i,j,vector[5];
    printf("Ingrese 5 numeros que luego se imprimiran en pantalla\n");
    for(i=0;i<5;i++){
    scanf("%d",&vector[i]);
    }
    for(j=0;j<5;j++){
    printf("%d",vector[j]);
    }
    printf("\n");
    return 0;
}