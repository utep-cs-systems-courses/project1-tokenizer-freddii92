#include <stdio.h>
#include "tokenizer.h"

int main()
{
  char str[100];
  printf("> ");
  scanf("%[^\n]", str);
  printf("%s\n", str);
  print_tokens(tokenize(str));
  free_tokens(tokenize(str));
}
