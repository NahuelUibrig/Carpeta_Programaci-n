#include <stdio.h>
#include <stdlib.h>

// Structs

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct dNode {
    int data;
    struct dNode *next;
    struct dNode *prev;
} dNode;



// Funciones utiles : mem dinamica

unsigned int leer_archivo(unsigned int** lista){   //lee un archivo dado, lo vuelca en una lista dinamica y devuelve el largo de la misma
    unsigned int i = 0;
    FILE*file;
    const char*filename = "archivo.bin";
    file = fopen(filename,"rb");  
    if (file == NULL) {
        perror ("Error al abrir");
        return 0;
    }
    printf("Lista = ");
    while (fread(*lista + i, sizeof(unsigned int), 1, file) == 1) {
        printf("|%u", (*lista)[i]);
        i++;
        unsigned int* temp = realloc(*lista, (i + 1) * sizeof(unsigned int));
        if (temp == NULL) {                                                   // Flag por si falla realloc (no pierdo lo acumulado)
            perror("Error de realloc");
            fclose(file);
            return 0;
        }
        *lista = temp;
    }
    printf("|\n");
    
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

float promedio(unsigned int *lista,unsigned int size){ // Calcula y devuelve el promedio de los valores tomados de una lista
    float suma = 0;
    for (int i=0;i<size;i++){
        suma = suma + *(lista+i);
    }
    suma = suma/size;

return suma;
}

void chequeo_bits(int* lista,unsigned int length){
    for (int i = 0 ; i<(int)length ; i++){
        if (i == 0 || i % 2 == 0){
            printf("\n");
        }
        printf("\n%b = %d",lista[i],lista[i]);
    }
}

// Funciones utiles : listas simples

void printLS(Node* head){                   //imprime una lista simple
    while (head != NULL){
        printf("|%d|->",head->data);
        head = head->next; 
    }
    printf("|NULL|\n");
}

int localizar_min(Node*head){               //Busca el nodo con el valor mas chico (int) y lo devuelve
    Node*curr = head;
    int aux_data = curr->data;
    while (curr != NULL){
        if (aux_data > curr->data){
            aux_data = curr->data;
        }
        curr= curr->next;
    }
    return aux_data;
}

void borrar_min(Node**head,int min){        //Borra un valor dado (dice minimo pero puede ser cualquiera)
    Node*curr = *head,*aux;
    if ((*head)->data == min){
        (*head) = (*head)->next;
        free (curr);
        return;
    }
    while (curr->next != NULL){
        if (curr->next->data == min){
            aux = curr->next;
            curr->next = aux->next;
            free(aux);
            return; 
        }
        curr=curr->next;
    }


}

Node* ordenar_lista(Node**head){            //Crea una nueva lista ordenada de menor a mayor y borra la dada usando las 2 de arriba 
    Node*curr = *head,*nuevo = NULL;
    int min = localizar_min(curr);
    while (*head != NULL){
        borrar_min(head,min);
        nuevo = insercion_final(nuevo,min);
        curr = *head;
        if (*head != NULL){
            min = localizar_min(curr);
        }
       
    }
    return nuevo;
}

Node* insercion_final(Node*head,int data){  //Engancha un nodo al final (necesita la funcion de creacion de nodo)
    Node* nuevo = crear_NodoS(data);
    if (head == NULL){
        return nuevo;
    }
    Node* current = head;
    while (current->next != NULL){
        current = current-> next; 
    }
    current->next = nuevo;
    return head;
}

Node* delfirst(Node*head){                  //Borra el primer nodo de la lista
    if (head == NULL){
        return NULL;
    }
    Node* aux = head;
    aux = aux->next;
    free (head);
    return aux;
}

Node* extaerN_Node(Node*head,int n){        //Borra el nodo "n" de una lista aplicando la funcion anterior y las imprime
    Node*aux1 = head;
    Node*aux2 = head;
    int cont = 1;
    while (cont != n){
        aux2 = aux1;
        aux1 = aux1->next;
        cont++;
        
    }
    printf ("\nLista sin tocar:\n");
    printLS(head);
    aux2->next = aux1->next;
    printf("___________________________________\n");
    printf("\n Nodo extraido: \tn°%d\n Data: \t\t\t%d\n",n,aux1->data);
    printf("___________________________________\n");
    aux1 = delfirst(aux1);
    printf("\nLista sin el nodo n°%d:\n",n);
    printLS(head);
    return head;
}

void borrar_LS(Node**head){                 //Libera una lista simple
    Node *curr = *head;
    while ((*head) != NULL){
        (*head) = (*head)->next;
        free(curr);
        curr = *head;
    }
    printf("Lista borrada\n\n");
}

// Funciones utiles : Listas dobles

// Caso ciclo

int buscaCiclo(dNode* primero,dNode* ultimo){                   //Busca un ciclo infinito en una lista

    dNode*head=primero;
    dNode*tail=ultimo;
    printf("|HEAD|->");
    while (head->next != NULL){
        printf("|%d|->",head->data);
        head = head->next; 
        if (head->next == head->prev && head->next != NULL){
            printf("|!!!|");
            printf ("\n\nEl nodo que tiene problemas es %d y entra por head\n",head->data);
            printf("|%d|<-|%d|->|%d|\n\n",head->prev->data, head->data, head->next->data);
            return head->data;
        }
    }
    printf("|%d|->",head->data);
    printf("|NULL|\n\n");
    printf("|TAIL|");
    while (tail->prev != NULL ){
        printf("->|%d|",tail->data);
        tail = tail->prev;
        if (tail->prev == tail->next && tail->prev != NULL){
            printf ("\n\nEl nodo que tiene problemas es %d y entra por tail:\n",tail->data);
            printf("|%d|<-|%d|->|%d|\n\n",tail->prev->data, tail->data, tail->next->data);
            return tail->data;
        }
    }
    printf("->|%d|",tail->data);
    printf("->|NULL|\n\n");
    
   return 0;    
}

void borraCiclo(dNode** head,dNode** tail,int data){            //Borra dicho ciclo
    dNode* primero = *head,*ultimo = *tail;
   
    while (((primero))->next->data != data ){
        primero = (primero)->next;
    }
    while (((ultimo))->prev->data != data ){
        ultimo = (ultimo)->prev;
    }
    if (((ultimo))->prev->prev == ((primero)) ){
        ((primero))->next->next = ((ultimo));
    }
    else{
        ((ultimo))->prev->prev = ((primero));
    }
    
    return;
}

void crearCircular(dNode** head,dNode** tail){                  //Modifica lista para hacerla circular
    (*(head))->prev = (*(tail));
    (*(tail))->next = (*(head));
    dNode* aux = *head;
    printf("Voy a probar si funciona ciclicamente:\n\n");
    while (aux != (*head)->prev){
        printf ("|%d|->",aux->data);
        aux = aux->next;
    }
    printf ("|%d|->|Nuevamente se repite|\n\n",aux->data);
}

// Caso lista con un corte

int buscaCorte(dNode* primero,dNode* ultimo){      // Busca un Corte por valor (solo sirve si alguno en el medio apunta a NULL)

    int vh = 0,vt = 0;
    dNode*head = primero;
    dNode*tail = ultimo;
    printf("|HEAD|->");
    while (head != NULL){
        printf("|%d|->",head->data);
        vh = head->data;
        head = head->next; 
    }
    printf("|NULL|\n\n");
    printf("|TAIL|");
    while (tail != NULL ){
        vt = tail->data;
        printf("->|%d|",tail->data);
        tail = tail->prev;
    }
    printf("->|NULL|\n\n");
    if (vt != primero->data){
        printf("se corto por Tail en el nodo de valor %d\n",vt);
        return vt;
    }
    else if (vh != ultimo->data){
        printf("se corto por Head en el nodo de valor %d\n",vh);
        return vh;
    }
    else if (vh == vt){
        printf ("Se corto en el medio en el nodo de valor %d\n",vh);
        return vh;
    }
   return 0;    
}

// Caso lista que skippea nodos

void arreglaporTail(dNode* primero,dNode* ultimo,int ct,int ch){        //Arregla la lista cuando se jodio en tail
    int* array = (int* )malloc ((ch-1)*sizeof(int));
    dNode *head = primero,*tail = ultimo;
    int i = 0;

    for (i = 0 ; i<ch ; i++){
        array[i] = head->data;
        head = head->next; 
    }
    head = primero;

    while (tail != NULL ){
        if (array [i-2] != tail->prev->data && i!=0){
            for (int j = 0 ; j<i-2 ; j++){
                head = head->next; 
                }
            tail->prev = head;
            return;
        }
        i--;
        tail = tail->prev;
        }
    }

void arreglaporHead(dNode* primero,dNode* ultimo,int ct,int ch){        //Arregla la lista cuando se jodio por Head
        int* array = (int* )malloc ((ct-1)*sizeof(int));
        dNode* tail = ultimo,*head = primero;
        int i = 0;
        
        for (i = 0 ; i<ct ; i++){
            array[i] = tail->data;
            tail = tail->prev; 
        }

        tail = ultimo;
        while (head != NULL ){
            if (array [i-2] != head->next->data && i!=0){
                for (int j = 0 ; j<i-2 ; j++){
                    tail = tail->prev; 
                    }
                head->next = tail;
                return;
            }
            i--;
            head = head->next;
        }
}

void buscaSkip(dNode* primero,dNode* ultimo){                           //Printea, busca error, llama la corresp, printea arreglado
    int ch = 0,ct = 0,i=0;
    dNode*head = primero;
    dNode*tail = ultimo;
    printf("|HEAD|->");
    while (head != NULL){
        printf("|%d|->",head->data);
        ch ++;
        head = head->next; 
    }
    printf("|NULL|\n\n");
    printf("|TAIL|");
    while (tail != NULL ){
        ct ++;
        printf("->|%d|",tail->data);
        tail = tail->prev;
    }
    printf("->|NULL|\n\n");
    if (ct < ch ){
        printf("Se corto por Tail y se skippearon %d valores\n\n",(ch-ct));
        arreglaporTail(primero,ultimo,ct,ch);
        tail = ultimo;
        printf("LISTA ARREGLADA:\n\n");
        printf("|TAIL|");
        while (tail != NULL ){
            ct ++;
            printf("->|%d|",tail->data);
            tail = tail->prev;
        }
        printf("->|NULL|\n\n");
        
    }
    else if (ch < ct){
        printf("Se corto por Head y se skippearon %d valores\n\n",(ct-ch));
        arreglaporHead(primero,ultimo,ct,ch);
        head = primero;
        printf("LISTA ARREGLADA:\n\n");
        printf("|HEAD|->");
        while (head != NULL){
            printf("|%d|->",head->data);
            ch ++;
            head = head->next; 
        }
        printf("|NULL|\n\n"); 
    }
           
   return ;    
}