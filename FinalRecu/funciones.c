/* Utilice este archivo para escribir sus funciones */

#include "definiciones.h"
#include <stdio.h>
#include <stdlib.h>



unsigned int leer_archivo(unsigned int** lista){   //lee un archivo dado, lo vuelca en una lista dinamica y devuelve el largo de la misma
    
    unsigned int i = 0;
    FILE*file;
    file_struct numero;
    file = fopen("lista.dat", "rb"); 
    if (file == NULL) {
        perror ("Error al abrir");
        return 0;
    }
    
    printf("Lista = ");
    
    while (fread(&numero, sizeof(file_struct), 1, file) == 1) {
        if(numero.num2==~(numero.num1)){
            unsigned int* temp = realloc(*lista, (i + 1) * sizeof(unsigned int));
            i++;
            if (temp == NULL) {                                                   // Flag por si falla realloc (no pierdo lo acumulado)
            perror("Error de realloc");
            fclose(file);
            return 0;
            
            }
            *lista = temp;
            
        } 
        
    }
    
    if (!feof(file)) {                                      // Flag para saber si la lectura de todo el archivo no fue exitosa 
        perror("\nError de lectura");
        return 0;
      }
      if (fclose(file) != 0) {                              // Flag para cierre de archivo 
        perror ("\nError al cerrar archivo");
        return 0;
      }       
    return i;                                               // Retorna el Length de la lista dinamica
}
void imprimirLista(unsigned int* lista, unsigned int longitud){
    unsigned int i=0;
    printf("Lista = ");
    for(i=0;i<longitud;i++){
        printf("%d ",lista[i]);
    }
}

void encuentroLista(superNode_t* first){
superNode_t* nodoMaestro=first;
node_t* lista1=nodoMaestro->nodoLista1;
node_t* lista2=nodoMaestro->nodoLista2;
node_t* lista3=nodoMaestro->nodoLista3;

lista1=lista1->next;
lista2=lista2->next;
lista3=lista3->next;
printf("\n");
while (1) {
    if(lista1==NULL){
        printf("Lista 1 no circular\n\n");
        break;
    }

    if(lista1!=nodoMaestro->nodoLista1){
    lista1 = lista1->next;
    
    }else{
       break; 
    }

    
}
while (1) {
    if(lista2==NULL){
        printf("Lista 2 no circular\n\n");
        break;
    }
    if(lista2!=nodoMaestro->nodoLista2){
    lista2 = lista2->next;
    
    }else{
       break; 
    }
    
    
}
while (1) {
    
    if(lista3==NULL){
        printf("Lista 3 no circular\n\n");
        break;
    }
    if(lista3!=nodoMaestro->nodoLista3){
        lista3 = lista3->next;
    }else{
       break; 
    }
    
    
}


}

int listasNoCirculares(superNode_t* first){
superNode_t* nodoMaestro=first;
node_t* lista1=nodoMaestro->nodoLista1;
node_t* lista2=nodoMaestro->nodoLista2;
node_t* lista3=nodoMaestro->nodoLista3;
int items1=1,items2=1,items3=1;
lista1=lista1->next;
lista2=lista2->next;
lista3=lista3->next;
printf("\n");
while (1) {
    if(lista1==NULL){
        break;
    }
    if(lista1->next==nodoMaestro->nodoLista1){
        lista1->next=NULL;
    }
    if(lista1!=nodoMaestro->nodoLista1){
    lista1 = lista1->next;
    items1++;
    
    }else{
        break; 
    }
    
}
while (1) {
    if(lista2==NULL){
        break;
    }
    if(lista2->next==nodoMaestro->nodoLista2){
        lista2->next=NULL;
    }
    if(lista2!=nodoMaestro->nodoLista2){
    lista2 = lista2->next;
    items2++;
    
    }else{
       break; 
    }
    
    
}
while (1) {
    if(lista3==NULL){
        
        break;
    }
    if(lista3!=nodoMaestro->nodoLista3){
    lista3 = lista3->next;
    items3++;
    
    }else{
       break; 
    }
    
    
}
printf("Listas circulares desarmadas\n\n");
if(items1>items2&items3){
printf("La lista 1 es mas larga, tiene %d items\n\n",items1);
}
if(items2>items1&items3){
printf("La lista 2 es mas larga, tiene %d items\n\n",items2);
}
if(items3>items1&items2){
printf("La lista 3 es mas larga, tiene %d items\n\n",items3);
}


}
/*
void borrar_LS(Node*head){                 //Libera una lista simple
    node_t* lista3=nodoMaestro->nodoLista3;
    while ((*head) != NULL){
        (*head) = (*head)->next;
        free(nodoMaestro->nodoLista3);
        nodoMaestro->nodoLista3= *head;
    }
    printf("Lista borrada\n\n");
}
    */