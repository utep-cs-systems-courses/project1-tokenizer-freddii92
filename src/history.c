#include <stdio.h>
#include <stdlib.h>
#include "history.h"

/* Initialize the linked list to keep the history. */
List* init_history() {
  struct s_List *list = (struct s_List*)malloc(sizeof(struct s_List));
  return list;
}

/* Add a history item to the end of the list. */
void add_history(List *list, char *str)
{
  if (list->root == NULL) {
    list->root = (struct s_Item*)malloc(sizeof(struct s_Item));
    list->root->id = 0;
    list->root->str = str;
    list->root->next = NULL;
  }
  else {
    struct s_Item *last = list->root;

    while (last->next != NULL) {
      last = last->next;
    }
    last->next = (struct s_Item*)malloc(sizeof(struct s_Item));
    last->next->id = last->id + 1;
    last->next->str = str;
    last->next->next = NULL;
  }
}

/* Retrieve the string stored in the node where Item->id == id. */
char *get_history(List *list, int id)
{
  struct s_Item *temp = list->root;
  
  while (temp != NULL) {
    if (temp->id == id) {
      return temp->str;
    }
    temp = temp->next;
  }
  return "Not found";
}

/* Print the entire contents of the list. */
void print_history(List *list)
{
  struct s_Item *temp = list->root;
  while (temp != NULL) {
    printf("%s\n", temp->str);
    temp = temp->next;
  }
}

/* Free the history list and the strings it references. */
void free_history(List *list)
{
  struct s_Item *temp = list->root;
  while ((temp = list->root) != NULL) {
    list->root = list->root->next;
    free(temp);
  }
}
