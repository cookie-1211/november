#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct ListNode{
    int value;
    struct ListNode* next;
};

typedef struct ListNode ListNode;

struct List{
    size_t size;
    ListNode* head;
    ListNode* tail;
};

typedef struct List Queue;	

Queue queue_init() {
    Queue q = {0, NULL, NULL};
    return q;
}

ListNode* init_listnode(int value, ListNode* next) {
    ListNode* newnode = malloc(sizeof(ListNode));
    newnode->value = value;
    newnode->next = next;
    return newnode;
}

void enqueue(Queue* q, int value){
	if (q == NULL) return;
	ListNode* newtail = init_listnode(value, NULL);
	q->tail->next = newtail;
	q->tail = newtail;
	if (!q->size) q->head = newtail;
	++q->size;
}

int dequeue(Queue* q) {
    if (q == NULL || !q->size) return 0;
    ListNode* current_head = q->head;
    int value = current_head == NULL ? 0 : current_head->value;
    q->head = q->head->next;
    free(current_head);
    if (!--q->size) q->tail = NULL;
    return value;
}

int main() {
    Queue q = queue_init();
    for (int i = 1; i < 10; ++i) enqueue(&q, i * i);
    for (int i = 1; i < 10; ++i) printf("%d ", dequeue(&q));
    putchar('\n');
    return 0;
}
