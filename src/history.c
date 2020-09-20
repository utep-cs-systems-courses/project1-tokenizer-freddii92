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
    struct s_Item *head = list->root;
    head->id = 0;
    head->str = str;
    head->next = NULL;
    printf("%s\n",head->str);
    printf("%d\n",head->id);
  }
  else {
    struct s_Item *last = list->root;

    while (last->next != NULL) {
      last = last->next;
    }
    last->id = last->id + 1;
    last->str = str;
    last->next = NULL;
    printf("%s\n",last->str);
    printf("%d\n", last->id);
  }
}

char *get_history(List *list, int id)
{
  struct s_Item *temp = list->root;
  printf("%s\n", temp->str);
  printf("%d\n", temp->id);
  while (temp->next != NULL) {
    if (temp->id == id) {
      return temp->str;
    }
    temp = temp->next;
  }
  return "Not found";
}

int main()
{
  struct s_List *start = (struct s_List*)malloc(sizeof(struct s_List));
  add_history(start,"hello dude");
  add_history(start,"whats up?");
  add_history(start,"guess what");
  add_history(start,"this must have id 3");
  printf("%s\n",get_history(start,3));
}
