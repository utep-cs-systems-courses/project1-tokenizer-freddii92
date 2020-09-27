#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  struct s_List *list = (struct s_List*)malloc(sizeof(struct s_List));
  
  puts("Welcome!");

  puts("Please write 3 sentences you would like tokenized.");

  int i = 0;
  char str[50];
  char **tokens;
  char copy[50];
  while (i < 3) {
    printf("> ");
    scanf(" %[^\n]", str);
    tokens = tokenize(str);
    print_tokens(tokens);
    add_history(list,copy_str(str, count_words(str)));
    free_tokens(tokens);
    i++;
  }
  
  char c;
  printf("Would you like to view the history? (y/n)\n>");
  scanf(" %c", &c);
  if (c == 'y') {
    char s[2];
    printf("Entire history = h or Item in history =  !<number>\n>");
    scanf(" %[^\n]", s);
    if (s[0] == 'h') {
      print_history(list);
    }
    if (s[0] == '!') {
      int x = s[1] - '0';
      printf("%s\n", get_history(list, x - 1));
    }
  }
  
  free_history(list);
}
