#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history() {
  struct s_List* list = (struct s_List*)malloc(sizeof(struct s_List));
}

void add_history(List *list, char *str)
{
  struct s_Item* t = (struct s_Item*)malloc(sizeof(struct s_Item));
  struct s_Item* temp = (struct s_Item*)malloc(sizeof(struct s_Item));
  //struct s_Item* t = list->root;
  
  if (t->str == NULL) {
    puts("This is the root.");
    t->id = 0;
    t->str = str;
    t->next = NULL;
    printf("%s\n", t->str);
    return;
  }
  while (t->next != NULL) {
    t = t->next;
  }
  t->next = temp;
  temp
}

int main()
{
  struct s_List *start = (struct s_List*)malloc(sizeof(struct s_List));;
  //start->root = (struct s_Item*)malloc(sizeof(struct s_Item));
  //start->root->id = 100;
  //printf("%d\n",start->root->id);
  add_history(start,"hello dude");
}
