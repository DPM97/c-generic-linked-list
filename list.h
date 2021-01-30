#ifndef PROGRAM1_H
#define PROGRAM1_H

#include <stdio.h>
#include <stdlib.h>

struct node {
	void* value;
  struct node* next;
};

struct list {
  struct node* head;
  struct node* tail;
  struct node* cur_node;
  int length;
};

int main(void);

void copy_value(void **ptr1, void **ptr2, size_t sizeof_type);

struct list* create_list();
void delete_list(struct list *the_list);
void add_node(void *value, size_t sizeof_type, struct list *the_list);

void print_list(struct list* the_list, void (*printfunc)(void*));
void print_int(void* value);
void print_str(void* value);

int length(struct list* the_list);
void* last(struct list* the_list);
void* first(struct list* the_list);

void pop(struct list* the_list);
void pop_front(struct list* the_list);

#endif
