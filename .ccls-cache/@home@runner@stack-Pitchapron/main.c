#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "node.h"
#include "stack.h"

int main(int argc, char **argv){
  
  int i,N,j,a;
  //NodePtr top=NULL;
  
  /*for(i=1;i<argc;i++){
    push(&top,atoi(argv[i]));
  }
  while(top){
    printf("%d\n",pop(&top));
  }*/
  /*push(&top,5);
  printf("%d\n",pop(&top));
  push(&top,7);
  push(&top,8);
  printf("%d\n",pop(&top));
  printf("%d\n",pop(&top));
  printf("%d\n",pop(&top));*/
 
Stack s;
s.top=NULL;
s.size=0;
printf("Checking the parentheses in argv arguments\n");
for(i=1;i<argc;i++){
  //push(&s,atoi(argv[i]));

  //pop_all(&s);
  N=0;a=0;
  for(j=0;j<strlen(argv[i]);j++){
  /* Use stack to help with the parentheses*/
    switch(argv[i][j]){
      case'{':
      case'[': push(&s,argv[i][j]);break;
      case']': if(s.size==0) a=1; else if(pop(&s)!='[') N=1; break;
      case'}': if(s.size==0) a=1; else if(pop(&s)!='{') N=1;
               break;
    }
    if(N==1) break;
  }
  if(s.size>0){
    printf("argv %d : Incorrect too many open parenthesis\n",i);
    pop_all(&s);
  }
  else if(a==1){
    printf("argv %d : Incorrect too many closed parenthesis\n",i);
  } 
  else if(N==1) printf("argv %d : incorrect mismatch\n",i);
  else if(N==0){
    printf("argv %d : Correct \n",i);
  }
}
return 0;
}

