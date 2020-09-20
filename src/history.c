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
    last->next = (struct s_Item*)malloc(sizeof(struct s_Item));
    last->id = last->id + 1;
    last->str = str;
    last->next = NULL;
    printf("%s\n",last->str);
    printf("%d\n", last->id);
  }
}

int main()
{
  struct s_List *start = init_history();
  add_history(start,"hello dude");
  add_history(start,"whats up?");
  add_history(start,"guess what");
  add_history(start,"this must have id 3");
}
