/* Utilice este archivo para escribir sus funciones */

#include "definiciones.h"
#include <stdio.h>
#include <string.h>


void sumarMultiplo(){
    FILE* file;
    int i = 0,j=0,fin=0,sumaMultiplo=0;
    

    file = fopen("lista.bin", "rb+");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    int* lista = malloc(sizeof(int));
    if (lista == NULL) {
        perror("Error de asignación de memoria");
        return;
    }

    while (fread(&lista[i], sizeof(int), 1, file)) {
        i++;
        lista = realloc(lista, (i + 1) * sizeof(int));
       
    }

    ////////////////////////////////////////////////////
    fin=lista[i-1];
    for(j=0;j<i-1;j++){
        if(lista[j]%fin==0){
            sumaMultiplo+=lista[j];
        }
    }
    printf("\nSuma de multiplos: %d \n", sumaMultiplo);
    //////////////////////////////////////////////////// 
    
   
    fclose(file);
    free(lista);
    
}




void buscoNumero() {
    int i = 0, encontrado = 0, suma = 0, promedio = 0, 
    numeroOriginal = 0, numeroModificado = 0, repeticiones = 0;
    
    FILE* file = fopen("lista.bin", "rb");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    // Leer todos los números del archivo
    int* lista = malloc(sizeof(int));
    if (lista == NULL) {
        perror("Error de asignación de memoria");
        fclose(file);
        return;
    }

    
    while (fread(&lista[i], sizeof(int), 1, file) == 1) {
        i++;
        int* temp = realloc(lista, (i + 1) * sizeof(int));
        if (temp == NULL) {
            perror("Error de realloc");
            free(lista);
            fclose(file);
            return;
        }
        lista = temp;
    }
    fclose(file);

    // Buscar el primer número que cumpla la condición
    for (int j = 10; j < i; j++) {
        suma = 0;
        for (int k = 0; k < j; k++) {
            suma += lista[k];
        }

        if (suma % j == 0) {
            promedio = suma / j;
            numeroOriginal = lista[j];

            // Mostrar número original
            printf("Número original: %d\nBinario: ", numeroOriginal);
            for (int i = 7; i >= 0; i--) {
                printf("%d", (numeroOriginal >> i) & 1);
            }     
            printf("\n");

            // Modificar el 4to bit para que sea igual al 5to
            int bit5 = (numeroOriginal >> 4) & 1;

            if (bit5 == 1)
                numeroModificado = numeroOriginal | (1 << 3); // poner bit 4 en 1
            else
                numeroModificado = numeroOriginal & ~(1 << 3); // poner bit 4 en 0

            // Mostrar número modificado
            printf("Número modificado: %d\nBinario: ", numeroModificado);
            for (int i = 7; i >= 0; i--) {
                printf("%d", (numeroModificado >> i) & 1);
            }       
    
            printf("\n");

            // Contar repeticiones del número original en la lista
            
            for (int m = 0; m < i; m++) {
                if (lista[m] == numeroOriginal)
                    repeticiones++;
            }
            printf("El número %d se repite %d veces en la lista.\n", numeroOriginal, repeticiones);

            encontrado = 1;
            break; // solo el primero
        }
    }

    if (!encontrado) {
        printf("No se encontró ningún número que cumpla la condición.\n");
    }

    free(lista);
}


void imprimoLista(Node*primerNodo,Node *ultimoNodo){
Node* actual=primerNodo;
int i=0,temperatura=0,humedad=0;
if (actual == NULL){
        return;
    }
printf("\nLista en orden normal\n");
while (1) {
        i++;
        temperatura=actual->data.temp;
        humedad=actual->data.humedad;
        printf("\nNodo: %d\nTemperatura:%d\nHumedad:%d\n",i,temperatura,humedad);
        if(actual!=ultimoNodo){    
        actual = actual->next;
        }
        else break;
        
    }
printf("\nLista en orden inverso\n");
while (1) {
        temperatura=actual->data.temp;
        humedad=actual->data.humedad;
        printf("\nNodo: %d\nTemperatura:%d\nHumedad:%d\n",i,temperatura,humedad);
        i--;
        if(actual!=primerNodo){
        actual = actual->prev;
        }
        else break;
        
    }
}







void eliminarHumedad(Node **primerNodo, Node **ultimoNodo){
    Node* actual=*primerNodo;
    Node* siguiente;
    if (actual == NULL){
        return;
    }
    
    while (actual!=NULL) {
        siguiente = actual->next; 
        if(actual->data.humedad<0){
            if (actual->prev!= NULL){ 
                    actual->prev->next=actual->next;
                    
            }else{                //Es el primero
                    *primerNodo=actual->next;   
                 }
            
            if (actual->next!= NULL){ 
                    actual->next->prev=actual->prev;
            }else{                //Es el ultimo
                    *ultimoNodo=actual->prev;   
                 }
            free(actual);    
            }
            actual = siguiente;    
        }
}

void imprimoListaCondicionada(Node*primerNodo,Node *ultimoNodo){
Node* actual=primerNodo;
int i=0,temperatura=0,humedad=0;
if (actual == NULL){
        return;
    }
printf("\nLista condicionada:\n");
while (1) {
        i++;
        temperatura=actual->data.temp;
        humedad=actual->data.humedad;
        if(humedad>80&&temperatura<2){
            printf("\nNodo: %d\nTemperatura:%d\nHumedad:%d\n",i,temperatura,humedad);
        }
        if(actual!=ultimoNodo){    
        actual = actual->next;
        }
        else break;
        
    }
}




void crearListaSimple(Node*primerNodo,Node *ultimoNodo,Nodo **primerNodoSimple){
    Node* actual=primerNodo;
    Nodo* ultimo=NULL;
    int* temp;
    int* lista=NULL;
    int i=0;
    if (actual == NULL){
        return;
    }
    while (1) {
        
        temp = realloc(lista, (i + 1) * sizeof(int));
        if (temp == NULL) {
            perror("Error de realloc");
            free(lista);
            return;
        }
        lista = temp;
        lista[i]=actual->data.temp;
        i++;
        if(actual!=ultimoNodo){    
        actual = actual->next;
        }
        else break;
        
    }
    BubbleSort(lista,i);

    for (int j = 0; j < i; j++) {
        Nodo* nuevo = malloc(sizeof(Nodo));
        if (nuevo == NULL) {
            perror("malloc");
            return;
        }
        nuevo->temperatura = lista[j];
        nuevo->next = NULL;

        if (*primerNodoSimple == NULL) {
            *primerNodoSimple = nuevo;
        } else {
            ultimo->next = nuevo;
        }
        ultimo = nuevo;
    }
    
    mostrarLista(lista,i);
    free(lista);

}
void Intercambio(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void BubbleSort(int* lista, int temp) {
    for (int j = 0; j < temp - 1; j++) {
        for (int i = 0; i < temp - j - 1; i++) {
            if (lista[i] > lista[i + 1]) {
                Intercambio(&lista[i], &lista[i + 1]);
            }
        }
    }
}
void mostrarLista(int* lista, int longitud) {
    for (int i = 0; i < longitud; i++) {
        printf("%d  ", lista[i]);
    }
    printf("\n");
}
void freeListdoble(Node** primerNodo, Node** ultimoNodo){
    Node* actual = *primerNodo;
    Node* siguiente;

    while (actual != NULL) {
        siguiente = actual->next;
        free(actual);
        actual = siguiente;
    }

    *primerNodo = NULL;
    *ultimoNodo = NULL;
}

    
   
