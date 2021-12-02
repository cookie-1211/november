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

typedef struct List List;

List list_init() {
    List l = {0, NULL, NULL};
    return l;
}

ListNode* init_listnode(int value, ListNode* next) {
    ListNode* newnode = malloc(sizeof(ListNode));
    newnode->value = value;
    newnode->next = next;
    return newnode;
}

void listnode_insert_next(ListNode* node, int value) {
    ListNode* current_next = node->next;
    ListNode* newnode = init_listnode(value, current_next);
    node->next = newnode;
}

void listnode_remove_next(ListNode* node) {
    if (node == NULL || node->next == NULL) return;
    ListNode* current_next = node->next;
    node->next = node->next->next;
    free(current_next);
}

void list_push_front(List* lst, int value) {
    ListNode* new_head = init_listnode(value, lst->head);
    lst->head = new_head;
    if (!lst->size) {
	    lst->tail = new_head;
    }
    l->size++;
}

void list_push_back(List* lst, int value){
	if (lst == NULL) return;
	ListNode* newtail = init_listnode(value, NULL);
	if (!lst->size){
		lst->tail = newtail;
		lst->head = newtail;
		lst->size++;}
	else{
		list->tail->next = newtail;
		list->tail = newtail;
		list->size++;}
}

int list_pop_front(List* lst) {
    if (lst == NULL || !lst->size) return 0;
    ListNode* current_head = lst->head;
    int value = current_head == NULL ? 0 : current_head->value;
    lst->head = lst->head->next;
    free(current_head);
    if (!--lst->size) lst->tail = NULL;
    return value;
}

void listnode_print(ListNode* node){
	if (node == NULL) return;
	while(node != NULL){
		printf("%d%s", node->value, node->next == NULL ? "\n" : " -> ");
		node = node->next;}
}

void list_print(List* lst) {
        if (lst == NULL) return;
        listnode_print(lst->head);
}

ListNode* list_find(List* lst, int value){
	if (lst == NULL) return NULL;
	ListNode* node = lst->head;
	while(node != NULL){
		if (node->value == value) return node;
		node = node->next;}
	return NULL;
}


typedef struct List Queue;

Queue queue_init() {
    return list_init();
}

void enqueue(Queue* q, int value){
	list_push_back(q, value);
}

int dequeue(Queue* q){
	return list_pop_front(q);
}




int main() {
        LinkedList l = list_init();
	for (int i = 1; i < 5; ++i) {
		list_push_front(&l, i * i);
		list_push_back(&l, i * i);
	}
	list_print(&l);
	
	while (l.size) {
		list_pop_front(&l);
		list_print(&l);
	}
	list_print(&l);
	return 0;
}
