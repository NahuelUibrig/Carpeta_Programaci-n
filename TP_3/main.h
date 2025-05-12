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
void findPath(Node_t* Node, Node_t* Target, int currDist, int branch);
void showgraph(Node_t* primerNodo,Node_t* ultimoNodo,int pasos);
