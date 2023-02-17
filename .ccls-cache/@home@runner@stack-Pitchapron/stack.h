
#ifndef stack_h
#define stack_h
#include "node.h"
typedef struct {
	NodePtr top;
	int size;
}Stack;

typedef Stack * StackPtr;
void push(StackPtr s, char value);
char pop(StackPtr s);
void pop_all(StackPtr s);

void push(StackPtr s, char value){
  Node *new_node=(NodePtr)malloc(sizeof(Node));
  if(new_node){
    new_node->data=value;
    new_node-> nextPtr=s->top;
    s->top=new_node;
    s->size++;
    }
  }
char pop(StackPtr s){
  NodePtr t = s->top;
  if(s->size>0){
    char value;
    value=t->data;
    s->top=t->nextPtr;
    s->size--;
    free(t);
    return value;
  }
  else{
    //printf("Empty Stack  ");
    return 0;
  }
}
void pop_all(StackPtr s){
  while(s->top){
    pop(s);
  }
}
#endif
