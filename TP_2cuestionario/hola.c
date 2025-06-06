
#include <stdio.h>

int main(void){
    int a = 10, b = 20;
    int* ptr_a = &a;
    int** ptrptr_a = &ptr_a;

    printf("%p\n", &(*(&(*ptrptr_a))));
    printf("%p\n", &ptr_a);
    return 0;
}