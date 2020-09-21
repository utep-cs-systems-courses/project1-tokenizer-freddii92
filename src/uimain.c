#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  struct s_List *list = (struct s_List*)malloc(sizeof(struct s_List));
  
  puts("Welcome!");

  puts("Please write the sentence you would like tokenized?");

  char str[50];
  char **tokens;
  
  printf("> ");
  scanf(" %[^\n]", str);
  tokens = tokenize(str);
  print_tokens(tokens);
  add_history(list,str);
  free_tokens(tokens);

  char c;
  printf("Would you like to view the history? (y/n)\n>");
  scanf(" %c", &c);
  if (c == 'y') {
    print_history(list);
  }
  
  free_history(list);
}
