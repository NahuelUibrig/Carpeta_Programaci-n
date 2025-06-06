typedef struct Node Node_t;

typedef struct {
    struct Node* node;
    int dist;
} Conection_t;

struct Node {
    Conection_t connections[3];
    char name;
};

Node_t* createNode(char name);
void createConnection(Node_t* First, Node_t* Second, int dist);
void showgraph(Node_t* primerNodo,int* pasos);
void shortestPath(Node_t* primerNodo,Node_t* ultimoNodo,int* pasos,int* distancia,int* menorDistancia);
void skipNode(Node_t* primerNodo,Node_t*nodoSkip,Node_t*raiz);

