#include <stdio.h>
#include <stdlib.h>
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
  if ((c != '\t' && c != ' ') && c != 0) {
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
  if (*word_start(str)) {
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

char *copy_str(char *inStr, short len)
{
  char *copy = malloc(len + 1);
  int i;
  for (i = 0; *inStr != '\0'; i++) {
    copy[i] = *inStr;
    inStr++;
  }
  copy[i] = '\0';
  return copy;
}

char **tokenize(char *str)
{
  
}

void print_tokens(char **tokens)
{
  for (int i = 0; tokens[i] != 0; i++) {
    printf("%s\n", tokens[i]);
  }
}

void free_tokens(char **tokens)
{
  
}
