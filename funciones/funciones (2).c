/* Declaracion de autoria
 * Fecha :
 * Autor :
 */

/* Utilice este archivo para escribir sus funciones */

#include "definiciones.h"

/*================== Funciones Ejercicio 1 ==================*/

/*================== Funciones Ejercicio 2 ==================*/

/*================== Funciones Ejercicio 3 ==================*/

/* Creo mi nodo */

dNode *crearNodo(int nuevoDato)
{
    dNode *nuevoNodo = (dNode *)malloc(sizeof(dNode)); // Con malloc le damos el espacio a mi nuevo nodo
                                                    //  asu vez me devuelve la posicion donde me reservo y esa posicion es donde va a estar
                                                    //  mi nuevo nodo.
    if (!nuevoNodo) // No hay nuevo nodo , es lo mismo que poner nuevoNodo = NULL
    {
        printf("No se pudo crear nuevo nodo");
        exit(1);
    }
    // Ya tengo creado  mi nuevo nodo

    nuevoNodo->next = NULL;
    nuevoNodo->data = nuevoDato;

    return nuevoNodo; // me devuelva la direccion del puntero
}

/* Creo mi lista simple , lo cual me crea una lista entera de nodos */

dNode *creaListaSimple(int vector[], int largo)
{

    dNode *primero = crearNodo(vector[0]); // crea mi primer nodo , obligatoriamente 
    dNode *current = primero;

    for (int i = 1; i < largo; i++)
    {
        current->next = crearNodo(vector[i]);
        current = current->next;
    }

    return primero;
}

// Como tengo el vector que me da el ejercicio , creo una funcion para que me cuente el largo del vector , para crear la lista

int calcularLargo_vector(int *vector)

{
    int i = 0;
    while (vector[i] != 0 )
    {
        i++;
    }
    return i;
    
}
/* creo mi funcion para poder imprimir la lista */
void imprimeListaSimple(dNode *primerNodo)
{
    dNode *current = primerNodo;
    while (current != NULL)
    {
        printf("Imprimo data: %d\n", current->data);
        current = current->next;
    }
}

/* punto B) 
 * Grupo 1 
*/

void imprimeCondicion(dNode *primerNodo , int x)
{
    dNode *current = primerNodo;
    int masgrande = 0;
    while (current != NULL)
    {
        if (current->data < x )
        {
            if (current->data > masgrande)
            {
                masgrande=current->data;
            }

        }
        
        current = current->next;
    }
    borrarNodo(&primerNodo,masgrande);
}


/*Borrrar nodo , pasandole data y nombre lista*/

void borrarNodo(dNode **head, int data)
{
    dNode *actual = *head;
    dNode *anterior = NULL;

    // Buscar nodo con el dato
    while (actual != NULL && actual->data != data)
    {
        anterior = actual;
        actual = actual->next;
    }

    // Si no encontró el nodo, salir
    if (actual == NULL)
    {
        printf("Nodo con data %d no encontrado.\n", data);
        return;
    }

    // Si el nodo a borrar es la cabeza
    if (anterior == NULL)
    {
        *head = actual->next;
    }
    else
    {
        anterior->next = actual->next;
    }

    free(actual);
    printf("Nodo con data %d eliminado.\n",data);
}

/* punto B)
 * Grupo 2
 */

void intercambiarNodosPorValor(dNode **head, int data1, int data2)
{
    if (data1 == data2)
        return; // Si son iguales no hace nada

    dNode *prev1 = NULL, *prev2 = NULL;
    dNode *node1 = *head, *node2 = *head;

    // Buscar node1 y su anterior
    while (node1 && node1->data != data1)
    {
        prev1 = node1;
        node1 = node1->next;
    }
    // Buscar node2 y su anterior
    while (node2 && node2->data != data2)
    {
        prev2 = node2;
        node2 = node2->next;
    }

    // Si alguno no existe, salimos
    if (!node1 || !node2)
        return;

    // Si node1 no es cabeza, prev1->next apunta a node2
    if (prev1)
    {
        prev1->next = node2;
    }
    else
    {
        *head = node2;
    }

    // Si node2 no es cabeza, prev2->next apunta a node1
    if (prev2)
    {
        prev2->next = node1;
    }
    else
    {
        *head = node1;
    }

    // Intercambiar sus next
    dNode *temp = node1->next;
    node1->next = node2->next;
    node2->next =temp;
}
