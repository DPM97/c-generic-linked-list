#include "list.h"

/* non-strict linkedlist */

void copy_value(void **ptr1, void **ptr2, size_t sizeof_type) {
  *ptr2 = (void*) malloc(sizeof_type);
  for (int i = 0; i < (int) sizeof_type; i++) {
     ((char *)*ptr2)[i] = ((char *)*ptr1)[i];
  }
}

struct list* create_list() {
  struct list* new_list = (struct list*) malloc(sizeof(struct list)); 
  new_list->head = NULL;
  new_list->tail = NULL;
  new_list->cur_node = NULL;
  new_list->length = 0;
  return new_list;
} 

void delete_list(struct list* the_list) {
  struct node *temp;
  while (the_list->head) {
    temp = the_list->head;
    the_list->head = the_list->head->next;
    free(temp->value);
    free(temp);
  }
  free(the_list);
}

void add_node(void* value, size_t sizeof_type, struct list* the_list) {
  
  if (the_list->head == NULL) {
    the_list->head = (struct node*) malloc(sizeof(struct node));
    the_list->tail = the_list->head;
  } else {
    the_list->tail->next = (struct node*) malloc(sizeof(struct node));
    the_list->tail = the_list->tail->next;
  }
  // copy void ptr contents into value void ptr
  copy_value(&value, &the_list->tail->value, sizeof_type);
  the_list->length++;
}

void print_int(void* value) {
  printf("%d", *(int*)(value));  
}

void print_str(void* value) {
  printf("%c", *(char*)(value));
}


void print_list(struct list* the_list, void (*printfunc)(void*)) {
  the_list->cur_node = the_list->head;
  (*printfunc)(the_list->cur_node->value);
  the_list->cur_node = the_list->cur_node->next;
  while (the_list->cur_node) {
      printf(" --> ");
      (*printfunc)(the_list->cur_node->value);
      the_list->cur_node = the_list->cur_node->next; // iterate to the next node;
  }
  printf("\n");
  the_list->cur_node = the_list->head;
}

int length(struct list* the_list) {
  return the_list->length;
}

void* last(struct list* the_list) {
  return the_list->tail;
}

void* first(struct list* the_list) {
    return the_list->head;
}

void pop(struct list* the_list) {
  if (the_list->length == 0) return;
  if (the_list->length == 1) {
    free(the_list->head->value);
    free(the_list->head);
    return;
  }

  the_list->cur_node = the_list->head;
  while(the_list->cur_node->next != the_list->tail) the_list->cur_node = the_list->cur_node->next;
  the_list->tail = the_list->cur_node;
  free(the_list->tail->next->value);
  free(the_list->tail->next);
  the_list->tail->next = NULL;
  return;
}

void pop_front(struct list* the_list) {
  the_list->cur_node = the_list->head;
  the_list->head = the_list->head->next;

  free(the_list->cur_node->value);
  free(the_list->cur_node);

  the_list->cur_node = the_list->head;
}

int main(void) {
  struct list* test_list_char = create_list();
  printf("Testing char:\n");
  for(int i = 65; i < 91; i++) {
    add_node(&i, sizeof(char), test_list_char);
  }
  print_list(test_list_char, &print_str);
  pop(test_list_char);
  print_list(test_list_char, &print_str);
  pop_front(test_list_char);
  print_list(test_list_char, &print_str);
  delete_list(test_list_char);

  struct list* test_list_int = create_list();
  printf("Testing int:\n");
  for(int i = 65; i < 91; i++) {
    add_node(&i, sizeof(int), test_list_int);
  }
  print_list(test_list_int, &print_int);
  pop(test_list_int);
  print_list(test_list_int, &print_int);
  pop_front(test_list_int);
  print_list(test_list_int, &print_int);
  delete_list(test_list_int);
}


