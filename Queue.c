#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include <Stack.c>



struct Queue{
    Stack s1;
    Stack s2;
};

typedef struct Queue Queue;

Queue queue_init(){
	Stack s1 = init_stack();
	Stack s2 = init_stack();
	Queue q = {s1, s2};
	return q;
}

void enqueue(Queue* q, int value){	
	put_stack(&q->s1, value);
}

int dequeue(Queue* q){	
	return pop_stack(&q->s2);
	if (!q->s2.capacity) {
		for(size_t i = 0; i < q->s1.capacity; i++){
			put_stack(&q->s2, pop_stack(&q->s1));}}
	return pop_stack(&q->s2);
}



int main() {
    Queue q = queue_init();
    for (int i = 1; i < 10; ++i) enqueue(&q, i * i);
    for (int i = 1; i < 10; ++i) printf("%d ", dequeue(&q));
    putchar('\n');
    return 0;
}
