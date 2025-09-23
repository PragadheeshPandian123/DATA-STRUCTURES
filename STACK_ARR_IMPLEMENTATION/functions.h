#ifndef FUNCTIONS_H
#define FUNCTIONS_H
int * stack=NULL;
int top=-1;
int max;
void create_stack();
void push();
void pop();
void peek();
void display();
void delete_stack();
int parantheses_checker();
#endif