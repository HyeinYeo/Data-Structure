// 후위표기법
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100 // 스택 최대 크기

// 스택 구조체
typedef struct {
	int stack[MAX_SIZE];
	int top;
}StackType;
// init
void init(StackType *s){
	s->top = -1;
}

// is_empty
int is_empty(StackType *s){
	if ((s->top) == -1) return 1;
}

// is_full
int is_full(StackType *s){
	if ((s->top) == MAX_SIZE - 1) return 1;
}

// push
void push(StackType *s, int data){
	if (is_full(s)) return;
	(s->top)++;
	s->stack[top] = data;
}

// pop
int pop(StackType *s){
	if (is_empty(s)) exit(1);
	else return (s->stack)[(s->top)--];
}

// top 
int top(StackType *s){
	if (is_empty(s)) exit(1);
	else return (s->stack)[s->top];
}

int eval_postfix(char exp[]){
	int i;
	StackType s;
	int val;
	int op1, op2;
	int len = strlen()
}


















