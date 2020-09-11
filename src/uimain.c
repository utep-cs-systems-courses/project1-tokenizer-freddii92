#include <stdio.h>
#include "tokenizer.h"

int main()
{
  char str[100];
  printf("> ");
  scanf("%[^\n]", str);
  printf("%s\n", str);

  printf("%d\n", space_char('c'));
  printf("%d\n", non_space_char('c'));
  printf("%d\n", word_start(str));
  printf("%d\n", *word_terminator(str));
  printf("%d\n", count_words(str));
}
