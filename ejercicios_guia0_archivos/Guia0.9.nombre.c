#include <stdio.h>
#include <string.h>

int main() {
    int i,suma_vocales=0;
    char palabra[50];

    printf("una frase que luego se imprimira\n");
    fgets(palabra, sizeof(palabra), stdin);
    for(i=0;i<50;i++){
        if(palabra[i]=='a'||palabra[i]=='e'||palabra[i]=='i'||palabra[i]=='o'||palabra[i]=='u'& palabra[i] != '\0'){
        suma_vocales++;
        }
    }
    printf("La frase utilizada cuenta con %d vocales\n",suma_vocales);
    
    printf("\n");
    return 0;
}