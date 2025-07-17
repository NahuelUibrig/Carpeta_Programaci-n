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
    
    
    while (fread(&numero, sizeof(file_struct), 1, file) == 1) {
        if(numero.num2==~(numero.num1)){
            unsigned int* temp = realloc(*lista, (i+1) * sizeof(unsigned int));
            if (temp == NULL) {                                                   // Flag por si falla realloc (no pierdo lo acumulado)
            perror("Error de realloc");
            fclose(file);
            return 0;
            
            }
            *lista = temp;
            (*lista)[i] = numero.num3; // falto asignarle valor a cada miembro de la lista.//
            i++;   // Se debe aumentar luego de asignar memoria.//
            
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
    return i;                                               // Retorna el largo de la lista dinamica
}
/*
//////////////Tiene bugs cuando el numero se repite mas de dos veces///////////////////////////////////////////////////////////
void modificarLista(unsigned int* lista,unsigned int longitud){
    unsigned int i=0,j=0,repetido=0;
    for(i=0;i<longitud;i++){
        for(j=0;j<longitud;j++){
            if(lista[j]==lista[i]){
                repetido++;
            }
            if(repetido>2){
                
                printf("%d - ",lista[i]);
                lista[i]=200;
                repetido=0;
            }
        }
        
        repetido=0;
    }
    printf("\n\n");

}
*/
void modificarLista(unsigned int* lista, unsigned int longitud) {
    //La lista de números va de 0 a 100 según el enunciado.
    int conteo[101] = {0};

    //Contar las repeticiones sin modificar nada.
    for (unsigned int i = 0; i < longitud; i++) {
        if (lista[i] <= 100) {
            conteo[lista[i]]++;
        }
    }

    //Imprimir numeros repetidos
    printf("Numeros repetidos mas de 2 veces:\n");
    for (int i = 0; i <= 100; i++) {
        if (conteo[i] > 2) {
            printf("%d - ", i);
        }
    }
    printf("\n\n");

    //Modificar la lista.
    for (unsigned int i = 0; i < longitud; i++) {
        if (lista[i] <= 100 && conteo[lista[i]] > 2) {
            lista[i] = 200;
        }
    }
}




void EliminoUltimo(unsigned int** lista, unsigned int* longitud) {
    unsigned int* temp=NULL;

    if (*longitud == 0){
        return;
    }
    (*longitud)--;
    temp = realloc(*lista, (*longitud) * sizeof(unsigned int));
    
    if (temp == NULL) {
        perror("Error en realloc");
        (*longitud)++;
        return;
    }

    *lista = temp;
}

void EliminoPrimero(unsigned int** lista, unsigned int* longitud) {
    unsigned int* temp=NULL;

    if (*longitud == 0){
        return;
    }
    // Mover todos los elementos una posición a la izquierda
    for (unsigned int i = 1; i < *longitud; i++) {
        (*lista)[i - 1] = (*lista)[i];
    }
    
    (*longitud)--;
    temp = realloc(*lista, (*longitud) * sizeof(unsigned int));
    
    if (temp == NULL) {
        perror("Error en realloc");
        (*longitud)++;
        return;
    }

    *lista = temp;
}

/////////////////////////////////////////////////////////////////////////
void imprimirLista(unsigned int* lista, unsigned int longitud){
    unsigned int i=0;
    for(i=0;i<longitud;i++){
        printf("%d - ",lista[i]);
    }
}

/* 
//////////////////////Funciona pero no es generico/////////////////////////////////////////
void encuentroLista(superNode_t* first){
if (first == NULL) {
    printf("El supernodo es nulo.\n");
    return;
}
superNode_t* nodoMaestro=first;
node_t* lista1=nodoMaestro->nodoLista1;
node_t* lista2=nodoMaestro->nodoLista2;
node_t* lista3=nodoMaestro->nodoLista3;

if (lista1 == NULL) {
    printf("Lista 1 está vacía.\n");
} else {
    lista1=lista1->next;
}

if (lista2 == NULL) {
    printf("Lista 2 está vacía.\n");
} else {
    lista2=lista2->next;
}
if (lista3 == NULL) {
    printf("Lista 3 está vacía.\n");
} else {
    lista3=lista3->next;
}

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


// Función tortuga vs liebre que devuelve 1 si la lista tiene un ciclo, 0 si no lo es. Es reutilizable.
int es_circular(node_t* first) {
    // Una lista vacía o de un solo nodo sin ciclo no es circular.
    if (first == NULL || first->next == NULL) {
        return 0;
    }

    node_t* lento = first;
    node_t* rapido = first;

    // El bucle se detiene si la liebre llega al final
    while (rapido != NULL && rapido->next != NULL) {
        lento = lento->next;          // La tortuga avanza 1
        rapido = rapido->next->next;  // La liebre avanza 2

        // Si se encuentran, hay un ciclo
        if (lento == rapido) {
            return 1; // Es circular
        }
    }

    // Si el bucle termina, la liebre llegó al final.
    return 0; // Es lineal
}
*/
///////////////////////////
int es_puramente_circular(node_t* first) {
    int lista_circular = 0,ciclo_detectado = 0;
    // --- Comprobación de casos base ---
    // Una lista vacía o de un solo nodo sin ciclo no es circular.
    if (first == NULL || first->next == NULL) {
        return 0;
    }
    // Se utilizan dos punteros: 'lento' (tortuga) y 'rapido' (liebre).
    node_t* lento = first;
    node_t* rapido = first;
    
    // El bucle se detiene si la liebre llega al final.
    while (rapido != NULL && rapido->next != NULL) {
        lento = lento->next;          // La tortuga avanza un paso.
        rapido = rapido->next->next;  // La liebre avanza dos pasos.

        // Si se encuentran, hay un ciclo
        if (lento == rapido) {
            ciclo_detectado = 1;
            break;
        }
    }
    // Si el bucle terminó porque la liebre llegó al final, la lista es lineal.
    if (ciclo_detectado!=1) {
        return 0;
    }
    // Busco en el bucle el primer nodo para verificar si la lista es circular completa
    // o solo tiene un ciclo, lento es el punto de referencia para el encuentro.
    node_t* actual = lento;

    // Usamos un bucle while que se ejecutará hasta que demos una vuelta completa en el ciclo.
    while (1) {
        // Si el nodo actual es la cabeza, activamos la bandera y salimos.
        if (actual == first) {
            lista_circular = 1;
            break;
        }
        
        // Avanzamos al siguiente nodo del ciclo.
        actual = actual->next;

        // Si hemos vuelto al punto de partida (lento) sin encontrar la cabeza,
        // significa que hemos completado una vuelta. Salimos del bucle.
        if (actual == lento) {
            break;
        }
    }
    // El valor de la bandera nos dice si la lista es circular o no.
    return lista_circular;
}
/////////////////////////





void encuentroLista(superNode_t* first) {
    if (first == NULL) return;

    printf("\n--- Analizando circularidad de listas ---\n");
    if (es_puramente_circular(first->nodoLista1)==1) {
        printf("Lista 1 es circular.\n");
    } else {
        printf("Lista 1 NO es circular (es lineal).\n");
    }

    if (es_puramente_circular(first->nodoLista2)==1) {
        printf("Lista 2 es circular.\n");
    } else {
        printf("Lista 2 NO es circular (es lineal).\n");
    }

    if (es_puramente_circular(first->nodoLista3)==1) {
        printf("Lista 3 es circular.\n");
    } else {
        printf("Lista 3 NO es circular (es lineal).\n");
    }
    printf("\n");
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
    if(lista3->next==nodoMaestro->nodoLista3){
        lista3->next=NULL;
    }
    if(lista3!=nodoMaestro->nodoLista3){
    lista3 = lista3->next;
    items3++;
    
    }else{
       break; 
    }
    
    
}
printf("Listas circulares desarmadas\n\n");
if(items1>items2&&items1>items3){
printf("La lista 1 es mas larga, tiene %d items\n\n",items1);
}
if(items2>items1&&items2>items3){
printf("La lista 2 es mas larga, tiene %d items\n\n",items2);
}
if(items3>items1&&items3>items2){
printf("La lista 3 es mas larga, tiene %d items\n\n",items3);
}


}
void ordenarLiberar(superNode_t* first){
superNode_t* nodoMaestro=first;
node_t* lista1=nodoMaestro->nodoLista1;
node_t* lista2=nodoMaestro->nodoLista2;

bubbleSortLista(lista1);
bubbleSortListaInverso(lista2);
borrarListaSimple(&nodoMaestro->nodoLista3);

}

void intercambioData(node_t* a, node_t* b) {
    int tmp = a->data;
    a->data = b->data;
    b->data = tmp;
}

void bubbleSortLista(node_t* primero) {
    if (!primero) return;  // Si la lista está vacía, no hay nada que hacer

    int huboCambios;
    node_t *actual, *ordenadoHasta = NULL;

    do {
        huboCambios = 0;
        actual = primero;

        // Recorremos hasta el último que ya está en su lugar
        while (actual->next != ordenadoHasta) {
            if (actual->data > actual->next->data) {
                intercambioData(actual, actual->next); // Si están desordenados, los cambio
                huboCambios = 1;  // Marcamos que hicimos un cambio
            }
            actual = actual->next; // Seguimos con el que sigue
        }

        ordenadoHasta = actual; // Este ya quedó ordenado, no lo miramos más
    } while (huboCambios); // Seguimos mientras sigan habiendo cambios
}

void bubbleSortListaInverso(node_t* primero) {
    if (!primero) return;  // Si la lista está vacía, no hay nada que hacer

    int huboCambios;
    node_t *actual, *ordenadoHasta = NULL;

    do {
        huboCambios = 0;
        actual = primero;

        // Recorremos hasta el último que ya está en su lugar
        while (actual->next != ordenadoHasta) {
            if (actual->data < actual->next->data) {
                intercambioData(actual, actual->next); // Si están desordenados, los cambio
                huboCambios = 1;  // Marcamos que hicimos un cambio
            }
            actual = actual->next; // Seguimos con el que sigue
        }

        ordenadoHasta = actual; // Este ya quedó ordenado, no lo miramos más
    } while (huboCambios); // Seguimos mientras sigan habiendo cambios
}





void imprimeListaSimple(node_t *primerNodo)
{
    node_t *current = primerNodo;
    while (current != NULL)
    {
        printf("Imprimo data: %d\n", current->data);
        current = current->next;
    }
}

void borrarListaSimple(node_t** PrimerNodo) {
    node_t* current = *PrimerNodo;
    node_t* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *PrimerNodo = NULL;
}

    