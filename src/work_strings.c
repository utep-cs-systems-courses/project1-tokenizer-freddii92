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
    str++;
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
  for (int i = 0; *inStr != '\0'; i++) {
    copy[i] = *inStr;
    inStr++;
  }
  copy[i] = '\0';
  return copy;
}

char **tokenize(char *str)
{
  char **token = malloc((count_words(str) + 1) * sizeof(char*));
  int i, j;
  char *start = str;
  char *end = word_terminator(str);

  for (i = 0; i < count_words(str); i++) {
    if (i == 0) {
      token[i] = malloc((end - start) * sizeof(char));
    }
    else {
      start = word_start(end);
      end = word_terminator(start);
      token[i] = malloc((end - start) * sizeof(char));
    }
    for (j = 0; j < end - start; j++) {
      token[i][j] = start[j];
    }
  }
  return token;
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
