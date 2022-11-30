/*Queue ADT
Data : 
1.Spaces for sorting element
2.Front for deletion
3.Rear for insertion

Operations :
1.enqueue(x)
2.dequeue()
3.isEmpty()
4.isFull()
5.first
6.last
*/

#include <iostream>
#include<stdio.h>
#include<stdlib.h>

struct queue
{
	int size;
	int front;
	int rear;
	int *Q;
};

void create(struct queue *q, int size)
{
	q->size = size;
	q->front=q->rear=-1;
	q->Q=(int *)malloc(q->size *(sizeof(int)));
}

void enqueue(struct queue *q, int x)
{
	if(q->rear==q->size-1)
		printf("queue is full\n");
	else
	{
		q->rear++;
		q->Q[q->rear]=x;
	}
}

int dequeue(struct queue *q)
{
	int x=-1;
	if(q->rear==q->front)
		printf("queue is empty\n");
	else
	{
		q->front++;
		x=q->Q[q->front];
	}
	return x;
}

void display(struct queue q)
{
	int i;
	for(i=q.front+1; i<=q.rear; i++)
	{
		printf("%d ", q.Q[i]);
	}
	printf("\n");
}

int main(int argc, char** argv) {
	
	struct queue q;
	create(&q, 2);
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q,7);
	display(q);
	return 0;
}
