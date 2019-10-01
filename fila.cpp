#include <iostream>
using namespace std;

typedef struct link {
	int element;
	struct link *next;
}Link;

Link *create_link(int c, Link *nextVal){
    Link *n = (Link *)malloc(sizeof(Link));
    n->element = c;
    n->next = nextVal;
    return n;
}
//sem o próximo elementos, pra inicializar como NULL
Link *create_link(Link *nextVal){
    Link *n = (Link *)malloc(sizeof(Link));
    n->next = nextVal;
    return n;
}

typedef struct queue{
    Link *front;
    Link *rear;
    int tam;
}Queue;

Queue *create_queue(){
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->front = create_link(NULL);
    q->rear = q->front;
    q->tam = 0;
    return q;
}

void clear(Queue *q){
    q->front = create_link(NULL);
    q->rear = create_link(NULL);
    q->tam = 0;
}

void enqueue(Queue *q, int it){
    q->rear->next = create_link(it, NULL);
    q->rear = q->rear->next;
    q->tam++;
}

int dequeue(Queue *q){
    if(q->tam==0) return -1;
    int it = q->front->next->element;
    q->front->next = q->front->next->next;
    if(q->front->next==NULL){
        q->rear = q->front;
    }
    q->tam--;
    return it;
}

int frontValue(Queue *q){
    if(q->tam == 0){
        return (int)NULL;
    }
    return q->front->next->element;
}

int length(Queue *q){
    return q->tam;
}

int main(){
    Queue *q = create_queue();
    enqueue(q, 1);
    enqueue(q, 2);
    int x = frontValue(q);
    printf("x = %d\n", x);
    dequeue(q);
    x = frontValue(q);
    printf("X = %d\n", x);
    dequeue(q);
    x = frontValue(q);
    printf("X = %d\n", x);
    
    return 0;
}