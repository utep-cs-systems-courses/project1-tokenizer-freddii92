#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history() {
  struct s_List *head = (struct s_List*)malloc(sizeof(struct s_List));
  head->root = NULL;
  return head;
}

void add_history(List *list, char *str)
{
  
  if (list->root == NULL) {
    list->root = (struct s_Item*)malloc(sizeof(struct s_Item));
    struct s_Item *head = list->root;
    head->id = 0;
    head->str = str;
    head->next = NULL;
  }
  else {
    printf("%s\n",list->root->str);
    struct s_Item *last = list->root;

    while (last->next != NULL) {
      last = last->next;
    }
    last->next = (struct s_Item*)malloc(sizeof(struct s_Item));
    last->next->id = last->id + 1;
    last->next->str = str;
    last->next->next = NULL;
    printf("%s\n",last->str);
    printf("%d\n", last->id);
  }
}

int main()
{
  struct s_List *start = (struct s_List*)malloc(sizeof(struct s_List));;
  //start->root = (struct s_Item*)malloc(sizeof(struct s_Item));
  //start->root->id = 100;
  //printf("%d\n",start->root->id);
  add_history(start,"hello dude");
  add_history(start,"whats up?");
  add_history(start,"guess what");
}
