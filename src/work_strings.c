#include <stdio.h>
#include "tokenizer.h"

int space_char(char c)
{
  if ((c == '\t' || c == ' ') && c != 0) {
    return 1;
  }
  return 0;
}

int non_space_char(char c)
{
  if ((c != '\t' || c != ' ') && c != 0) {
    return 1;
  }
  return 0;
}

char *word_start(char *str)
{
  if (*str == '\0') {
    return 0;
  }
  while (space_char(*str)) {
    *str++;
  }
  return str;
}

char *word_terminator(char *word)
{
  while (non_space_char(*word)) {
    word++;
  }
  return word;
}

int count_words(char *str)
{
  int count = 0;
  if (non_space_char(*str)) {
    count++;
    str++;
  }
  for (     ; *str != '\0'; str++) {
    if (space_char(*str) && non_space_char(*str+1)) {
      count++;
    }
  }
  return count;
}
