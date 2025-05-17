#include "header.h"

#include <stdio.h>
#include <stdlib.h>

static dnode_t *create_dnode(char name)
{
  dnode_t *new_node = malloc(sizeof(dnode_t));
  if (new_node == NULL)
  {
    perror("Memory allocation failed!");
    return NULL;
  }
  new_node->name = name;
  new_node->prev.con = NULL;
  new_node->prev.dist = 0;
  new_node->next.con = NULL;
  new_node->next.dist = 0;
  return new_node;
}

static void create_next_connection(dnode_t *first, dnode_t *second, int dist)
{

  first->next.con = second;
  first->next.dist = dist;

  second->prev.con = first;
  second->prev.dist = dist;
}

dnode_t *CATEDRA_crear_lista_corta(void)
{

  char list[] = {'A', 'b', '3', '#', ' ', 'z', '0', '%', 'x', '!'};
  int dists[] = {6, 12, 1, 19, 7, 9, 2, 19, 20, 30};

  int list_size = sizeof(list) / sizeof(list[0]);

  dnode_t *list_of_nodes[SHORT_LIST];

  list_of_nodes[0] = create_dnode(list[0]);
  for (int i = 1; i < list_size; ++i)
  {
    list_of_nodes[i] = create_dnode(list[i]);
    create_next_connection(list_of_nodes[i - 1], list_of_nodes[i], dists[i - 1]);
  }
  create_next_connection(list_of_nodes[list_size - 1], list_of_nodes[0], dists[list_size - 1]);

  return list_of_nodes[0];
}

dnode_t *CATEDRA_crear_lista_POSTA(void)
{
  char list[] = {
      'C', 'k', 'V', 'v', 'i', 'H', 'j', 'm', 'Z', 'e', 'l', 'A', 'q', 'U', 'K', 'F', 'J', 'Y', 'M', 'x',
      'r', 'W', 'I', 'y', 'R', 'X', 'd', 'P', 'g', 'Q', 't', 'E', 'n', 'B', 'S', 'N', 'G', 'L', 's', 'm',
      'o', 'D', 'f', 'h', 'b', 'a', 'T', 'z', 'u', 'O', '3', '5', '6', '8', '9', '7', '2', '0', '4', '1',
      'A', 'B', 'P', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
      'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'm', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
      'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7',
      '8', '9', 'A', 'B', 'P', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
      'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'm', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
      'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5',
      '6', '7', '8', '9', 'A', 'B', 'P', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
      'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'm', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
      'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3',
      '4', '5', '6', '7', '8', '9', 'A', 'B', 'c', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
      'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'f', 'd', 'e', 'f', 'g', 'h',
      'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1',
      '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'P', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
      'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'f', 'd', 'e', 'f',
      'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
      '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'P', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
      'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T'};

  int dists[] = {
      1, 1, 2, 3, 3, 1, 1, 2, 2, 2, 7, 1, 4, 3, 2,
      1, 5, 2, 2, 3, 2, 1, 10, 8, 5, 3, 2, 2, 1, 2,
      1, 1, 3, 1, 3, 3, 4, 2, 2, 6, 2, 3, 2, 1, 1,
      2, 1, 1, 2, 3, 5, 5, 13, 10, 3, 9, 3, 1, 1, 5,
      2, 1, 2, 1, 5, 5, 1, 2, 5, 2, 2, 6, 4, 5, 1, 1,
      1, 4, 2, 8, 5, 1, 1, 3, 1, 1, 10, 3, 10, 1, 1, 1,
      3, 3, 3, 1, 3, 2, 4, 1, 2, 1, 5, 3, 4, 1, 3, 1, 2,
      1, 1, 12, 4, 1, 1, 1, 1, 1, 1, 3, 1, 2, 1, 3, 2, 2,
      3, 1, 3, 4, 8, 1, 3, 5, 1, 7, 4, 1, 1, 1, 6, 1, 2, 4,
      8, 4, 6, 3, 1, 1, 1, 4, 2, 5, 6, 5, 4, 1, 1, 3, 1, 4,
      3, 1, 2, 3, 5, 2, 6, 2, 1, 1, 3, 7, 1, 2, 1, 1, 1, 1,
      3, 6, 2, 1, 1, 2, 4, 1, 1, 2, 2, 8, 6, 6, 2, 1, 9, 2,
      5, 1, 3, 1, 3, 2, 3, 1, 3, 1, 3, 2, 8, 2, 3, 6, 4, 7,
      2, 2, 2, 2, 1, 1, 4, 2, 8, 6, 1, 2, 1, 1, 4, 5, 1, 1,
      2, 1, 5, 13, 3, 3, 3, 1, 1, 1, 11, 1, 1, 2, 1, 1, 1,
      4, 6, 2, 5, 5, 2, 1, 6, 1, 9, 1, 3, 6, 2, 3, 1, 5, 1,
      2, 2, 2, 2, 2, 3, 1, 2, 3, 3, 2, 2, 1, 1, 3, 6, 5, 2,
      2, 2, 2, 1, 3, 3, 1, 2, 3, 3, 1, 11, 3, 1, 1, 1, 1, 2,
      1, 2, 3, 2, 1, 3, 2, 1, 3, 7, 1, 1, 2, 4, 2, 3, 3, 1,
      2, 2, 2, 1, 10, 2, 1, 2, 1, 4, 1, 5, 2, 1, 3, 3, 3, 1,
      1, 1, 8, 1, 2, 2, 3, 9, 1};

  dnode_t *list_of_nodes[LISTA_POSTA];

  list_of_nodes[0] = create_dnode(list[0]);
  for (int i = 1; i < LISTA_POSTA; ++i)
  {
    list_of_nodes[i] = create_dnode(list[i]);
    create_next_connection(list_of_nodes[i - 1], list_of_nodes[i], dists[i - 1]);
  }

  create_next_connection(list_of_nodes[LISTA_POSTA - 1], list_of_nodes[0], dists[LISTA_POSTA - 1]);

  return list_of_nodes[0];
}

void sumarDistancias(dnode_t* first,int distanciaTotal){
dnode_t* actual=first;
if (actual == NULL){
        return;
    }
distanciaTotal+=actual->next.dist;
actual = actual->next.con;
while (1) {
        if(actual!=first){
        distanciaTotal+=actual->next.dist;
        actual = actual->next.con;
        
        }
        if(actual==first){
        break;
        }
    }
    printf("\nDistancia total: %d\n",distanciaTotal);

}
void distanciaCorta(dnode_t* first,dnode_t* end,int distanciaTotal1,int distanciaTotal2){
dnode_t* actual=first;
dnode_t* actual2=first;
dnode_t* final=end;


if (actual == NULL){
        return;
    }
    if (actual2 == NULL){
        return;
    }
distanciaTotal1+=actual->next.dist;
actual = actual->next.con;
distanciaTotal2+=actual2->prev.dist;
actual2 = actual2->next.con;
while (1) {
        if(actual->name!=end->name){
        distanciaTotal1+=actual->next.dist;
        actual = actual->next.con;
        
        }
        if(actual->name==end->name){
        break;
        }
    }
    printf("\nDistancia total next: %d\n",distanciaTotal1);
    while (1) {
        if(actual2->name!=end->name){
        distanciaTotal2+=actual2->prev.dist;
        actual2 = actual2->prev.con;
        
        }
        if(actual2->name==end->name){
        break;
        }
    }
    printf("\nDistancia total prev: %d\n",distanciaTotal2);
    

}


