#include <stdio.h>
#include "tokenizer.h"

int main()
{
  char str[100];
  printf("> ");
  scanf("%[^\n]", str);
  printf("%s\n", str);

  printf("%d\n", space_char(str[0]));
  printf("%d\n", non_space_char(str[0]));
  printf("%s\n", word_start(str));
  printf("%c\n", *word_terminator(str));
  printf("%d\n", count_words(str));
  printf("%s\n", copy_str(str,5));
  print_tokens(tokenize(str));
  free_tokens(tokenize(str));
}
