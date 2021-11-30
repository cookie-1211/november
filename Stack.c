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
	return *st;
}

int pop_stack(Stack *st){
	int n = st->data[st->size - 1];
	st->size--;
	if (st->capacity > 4 && 4 * st->size < st->capacity){
		st->capacity = st->capacity / 2;
		st->data = realloc(st->data, st->capacity * sizeof(int));}
	return n;
}

void put_stack(Stack *st, int value){
	st->data[st->size] = value;
	st->size++;
	if (st->size == st->capacity){
		st->capacity = st->capacity * 2;
		st->data = realloc(st->data, st->capacity * sizeof(int));}
}
