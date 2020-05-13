#include <stdio.h>
#include <stdlib.h>
# define elemtype char
#define MAXSIZE 1024

typedef struct{
	elemtype *bt[MAXSIZE];
	int top;
}STACK;

int isEmpty(STACK *stack){
	if(stack->top==-1)
	return 1;
	return 0;
}

void push(STACK *stack,elemtype *c){
	if(stack->top<MAXSIZE-1)
		stack->bt[++(stack->top)]=c;
}

elemtype *pop(STACK *stack){
	elemtype *c = NULL;
	if(!isEmpty(stack))
		c=stack->bt[(stack->top)--];
	return c;
}

STACK *initstack(){
	STACK *stack=(STACK *)malloc(sizeof(STACK));
	stack->top=-1;
	return stack;
}

void PrintLastElement(LNode *head){  //利用栈输出链表最后一个结点 
	LNode p;
	int result;
	STACK s;
	initstack(s);
	p = head->next;
	while(p){
		push(s,p->data);
		p = p->next;
	}
	result = pop(s);
	printf("%d",result);
}

void RePrintLastElement(LNode *head){  //利用栈反向输出单链表 
	Lnode p;
	STACK s;
	initstack(s);
	p = head->next;
	while(p){
		push(s,p->data);
		p = p->next;
	}
	while(1){
		printf("%d",pop(s));
		if(isEmpty(s))
			break;
	}
}



int main(){
	return 0;
} 
