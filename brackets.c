#include <stdio.h>
#include <stdlib.h>

	
typedef struct {
    char* data;
    size_t size;
    size_t capacity;
} Stack;


Stack init_stack() {
	Stack st;
	st.data = malloc(4 * sizeof(char));
	st.size = 0;
	st.capacity = 4;
	return st;
}


char pop_stack(Stack *st) {
	int elem = st->data[st->size - 1];
	st->size--;
	if (st->capacity > 4 && 4 * st->size < st->capacity) {
		st->capacity /= 2;
		st->data = realloc(st->data, st->capacity * sizeof(char));}
	return elem;
	}
	
	
void put_stack(Stack *st, char value){
	st->data[st->size] = value;
	st->size++;
	if (st->size == st->capacity) {
		st->capacity *= 2;
		st->data = realloc(st->data, st->capacity * sizeof(char));
	}
}


int top_stack(Stack *st){
	return(st->data[st->size - 1]);
	}
	
	
int brackets(char* str, size_t size){
	Stack st = init_stack();
	for (size_t i = 0; i < size; i ++){
		if (str[i] == '(' || str[i] == '['){
			put_stack(&st, str[i]);}
		if (str[i] == ')' || str[i] == ']'){
			if (st.size == 0){return 1;}
			if ((str[i] == ')' && top_stack(&st) == '(') || (str[i] == ']' && top_stack(&st) == '[')){
				char s = pop_stack(&st);}
			else{
				free(st.data);
				return 1;}}} 
	free(st.data);
	if (st.size == 0) return 0;
	else return 1;}



int main(){	
	FILE* fptr = fopen("data.txt", "r");
	if (fptr == NULL) {
		puts("Can't open file");
		return 1;}
	
	char* str = (char*)malloc(100 * sizeof(char));
	size_t bufsize = 100;
	while (!feof(fptr)){
		size_t size = getline(&str, &bufsize, fptr);
		if (feof(fptr)) break;
		int n = brackets(str, size);
		if (n == 0) {printf ("Yes\n");}
		else {printf ("No\n");}}
	return 0;
}
