#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct node {
    int data;
    struct node * prev;
    struct node* next;
} Node;

void create_list();
int length();
void insert_at_begn();
void insert_at_end();
void insert_at_pos();
void insert_node();
void delete_at_begn();
void delete_at_end();
void delete_at_pos();
void delete_node();
void update();
void sort_list();
void reverse_list();
void delete_list();
void display_list();


#endif
