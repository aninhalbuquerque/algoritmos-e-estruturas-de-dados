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

typedef struct list{
    Link *head;
    Link *tail;
    Link *curr;
    int tam;
}List;

List *create_list(){
    List *l = (List *) malloc(sizeof(List));
    l->curr = create_link(NULL);
    l->tail = l->curr;
    l->head = l->curr;
    l->tam = 0;
    return l;
}

void clear(List *l){
    l->curr = create_link(NULL);
    l->tail = create_link(NULL);
    l->head = create_link(NULL);
    l->tam = 0;
}

void insert(List *l, int c){
    l->curr->next = create_link(c, (l->curr)->next);
    if(l->tail == l->curr){
        l->tail = (l->curr)->next;
    }
    (l->tam)++;
}

void append(List *l, int c){
    l->tail->next = create_link(c, NULL);
    l->tail = l->tail->next;
    (l->tam)++;
}

void moveToStart(List *l){
    l->curr = l->head;
}

void moveToEnd(List *l){
    l->curr = l->tail;
}

void prev(List *l){
    if(l->curr == l->head) return;
    Link *temp = l->head;
    while(temp->next != l->curr){
        temp = temp->next;
    }
    l->curr = temp;
}

void next(List *l){
    if(l->curr != l->tail){
        l->curr = l->curr->next;
    }
}

int remove(List *l){
    if(l->curr->next == NULL) return -1;
    int c = l->curr->next->element;
    if(l->tail == l->curr->next){
        l->tail = l->curr;
    }
    l->curr->next = l->curr->next->next;
    l->tam--;
    return c;
}

int getValue(List *l){
    if(l->curr->next == NULL){
        return (int)NULL;
    }
    return l->curr->next->element;
}

int length(List *l){
    return l->tam;
}

int currPos(List *l){
    Link *temp = l->head;
    int i = 0;
    while(l->curr != temp){
        temp = temp->next;
        i++;
    }
    return i;
}

int main(){
    List *l = create_list();
    insert(l, 1);
    insert(l, 2);
    insert(l, 3);
    int x = getValue(l);
    printf("x = %d\n", x);
    next(l);
    x = getValue(l);
    printf("x = %d\n", x);
    remove(l);
    x = getValue(l);
    printf("x = %d\n", x);
    prev(l);
    x = getValue(l);
    printf("x = %d\n", x);
    
    return 0;
}