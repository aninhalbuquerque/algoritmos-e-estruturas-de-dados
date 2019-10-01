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

typedef struct stack{
    Link *top;
    int tam;
}Stack;

Stack *create_stack(){
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->top = create_link(NULL);
    s->tam = 0;
    return s;
}

void clear(Stack *s){
    s->top = create_link(NULL);
    s->tam = 0;
}

void push(Stack *s, int it){
    s->top = create_link(it, s->top);
    s->tam++;
}

void pop(Stack *s){
    if(s->top == NULL) return;
    int it = s->top->element;
    s->top = s->top->next;
    s->tam--;
}

int topValue(Stack *s){
    if(s->top == NULL){
        return (int)NULL;
    }
    return s->top->element;
}

int length(Stack *s){
    return s->tam;
}

int main(){
    Stack *s = create_stack();
    push(s, 1);
    push(s, 2);
    int x = topValue(s);
    printf("x = %d\n", x);
    pop(s);
    x = topValue(s);
    printf("x = %d\n", x);
    pop(s);
    x = topValue(s);
    printf("x = %d\n", x);
    
    return 0;
}