#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history() {
  struct s_List *list = (struct s_List*)malloc(sizeof(struct s_List));
  return list;
}

void add_history(List *list, char *str)
{
  if (list->root == NULL) {
    list->root = (struct s_Item*)malloc(sizeof(struct s_Item));
    list->root->id = 0;
    list->root->str = str;
    list->root->next = NULL;
    printf("%s\n", list->root->str);
    printf("%d\n", list->root->id);
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
    printf("%s\n", last->next->str);
    printf("%d\n", last->next->id);
  }
}

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

void print_history(List *list)
{
  struct s_Item *temp = list->root;
  while ( temp != NULL) {
    printf("%s\n", temp->str);
    temp = temp->next;
  }
}

int main()
{
  struct s_List *start = (struct s_List*)malloc(sizeof(struct s_List));
  add_history(start,"hello dude");
  add_history(start,"whats up?");
  add_history(start,"guess what");
  add_history(start,"this must have id 3");
  printf("%s\n",get_history(start,3));
  print_history(start);
}
