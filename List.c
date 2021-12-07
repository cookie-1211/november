#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


struct ListNode {
    int value;
    struct ListNode *next;
};
typedef struct ListNode ListNode;


typedef struct {
    size_t size;
    ListNode* head;
    ListNode* tail;
} List;


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


void listnode_print(ListNode* node) {
    while (node != NULL) {
        printf("%d%s", node->value, node->next == NULL ? "\n" : " -> ");
        node = node->next;
    }
}


void list_push_front(List* l, int value) {
    ListNode* new_head = init_listnode(value, l->head);
    l->head = new_head;
    if (!l->size) l->tail = new_head;
    ++l->size;
}


void list_push_back(List* lst, int value){
	if (lst == NULL) return;
	ListNode* newtail = init_listnode(value, NULL);
	if (!lst->size){
		lst->tail = newtail;
		lst->head = newtail;
		lst->size++;}
	else{
		lst->tail->next = newtail;
		lst->tail = newtail;
		lst->size++;}
}


void list_print(List* l) {
    if (l == NULL) return;
    listnode_print(l->head);
}


int list_pop_front(List* l) {
    if (l == NULL || !l->size) return 0;
    ListNode* current_head = l->head;
    int value = current_head == NULL ? 0 : current_head->value;
    l->head = l->head->next;
    free(current_head);
    if (!--l->size) l->tail = NULL;
    return value;
}


ListNode* list_find(List* l, int value) {
    if (l == NULL) return NULL;
    ListNode* node = l->head;
    while (node != NULL) {
        if (node->value == value) return node;
        node = node->next;
    }
    return NULL;
}


int main() {
    List l = list_init();
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
