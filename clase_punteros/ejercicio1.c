#include <stdio.h>
void intercambio(int*x,int*y);
int main() {
    int x=10,y=20;
    printf("Antes del intercambio:   \n x=%d, y=%d",x,y);
    printf("\n\n");
    intercambio(&x,&y);
    printf("Despues del intercambio:   \n x=%d, y=%d",x,y);
    printf("\n\n");
    return 0;
}
void intercambio(int*x,int*y){
    int temp =*x;
    *x=*y;
    *y=temp;

}