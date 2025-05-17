#ifndef HEADER_H
#define HEADER_H

#define SHORT_LIST  10
#define LISTA_POSTA 350

typedef struct dnode dnode_t;

typedef struct{
  int dist;
  struct dnode* con;
} connection_t;

struct dnode{
  char name;
  connection_t next;
  connection_t prev;
};

dnode_t *CATEDRA_crear_lista_corta(void);
dnode_t *CATEDRA_crear_lista_POSTA(void);
void sumarDistancias(dnode_t* first,int distanciaTotal);
void distanciaCorta(dnode_t* first,dnode_t* end,int distanciaTotal1,int distanciaTotal2);
#endif