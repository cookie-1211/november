#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>



typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} Stack;


Stack init_stack(){
	Stack* st = malloc(sizeof(Stack));
	st->data = malloc(4 * sizeof(int));
	st->size = 0;
	st->capacity = 4;
	return *st;}


void put_stack(Stack *st, int value){	
	st->data[st->size] = value;
	st->size++;
	if (st->size == st->capacity){
		st->capacity = st->capacity * 2;
		st->data = realloc(st->data, st->capacity * sizeof(int));}}

int pop_stack(Stack *st){	
	int n = st->data[st->size - 1];
	st->size--;
	if (st->capacity > 4 && 4 * st->size < st->capacity){
		st->capacity = st->capacity / 2;
		st->data = realloc(st->data, st->capacity * sizeof(int));}
	return n;}



struct Queue{
    Stack s1;
    Stack s2;
};


typedef struct Queue Queue;


Queue queue_init(){
	Stack s1 = init_stack();
	Stack s2 = init_stack();
	Queue q = {s1, s2};
	return q;}


int dequeue(Queue* q){	
	if (!q->s2.size){
		size_t size = q->s1.size;
		for(size_t i = 0; i < size; i++){
			put_stack(&q->s2, pop_stack(&q->s1));}}
	return pop_stack(&q->s2);}


void enqueue(Queue* q, int value){	
	put_stack(&q->s1, value);}



int main() {
    Queue q = queue_init();
    for (int i = 1; i < 10; ++i) enqueue(&q, i * i);
    for (int i = 1; i < 10; ++i) printf("%d ", dequeue(&q));
    putchar('\n');
    
    return 0;
}
