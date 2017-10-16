#include <stdio.h>
#include <stdlib.h>

//header file
#include "linked_list.h"

void print_list(struct node * node){
  printf("HEAD -> ");
  while(node){
    printf("%d -> ", node -> i);
    node = node -> next;
  }
  printf("null\n");
}

struct node * insert_front(struct node * prev_head, int value){
  struct node * new_head;
  new_head = (struct node *) malloc(sizeof(struct node));

  new_head -> i = value;
  new_head -> next = prev_head;

  return new_head;
}

struct node * free_list(struct node * node){
  struct node * current_node = node;
  struct node * next_node = node;
  while(current_node){
    next_node = current_node -> next;
    free(current_node);
    current_node = next_node;
  }
  return node;
}

int main(){

  struct node* node1 = malloc(sizeof(struct node));
  printf("created empty list\n");
  node1 -> i = 2;
  node1 -> next = NULL;
  print_list(node1);

  printf("adding node2\n");
  struct node* node2 = malloc(sizeof(struct node));
  node2 -> i = 2;
  node2 -> next = NULL;
  node1 -> next = node2;
  print_list(node1);

  printf("adding 5, 4, 3 using insert_front\n");
  struct node* list = insert_front(node1, 5);
  print_list(list);
  list = insert_front(list, 4);
  print_list(list);
  list = insert_front(list, 3);
  print_list(list);

  printf("freeing list\n");
  free(list);
  printf("list: ");
  print_list(list);

  struct node* node3 = malloc(sizeof(struct node));
  node3 -> i = 10;
  node3 -> next = NULL;
  printf("created another node to check if memory freed\nnew node: ");
  print_list(node3);
  printf("link: ");
  print_list(list);
  
  return 0;
}
