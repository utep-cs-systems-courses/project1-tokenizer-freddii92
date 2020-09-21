#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace character
   ('\t' or ' ').
   Zero terminators are not printable (therefore false) */
int space_char(char c)
{
  if ((c == '\t' || c == ' ') && c != 0) {
    return 1;
  }
  return 0;
}

/* Return true (non-zero) if c is a non-whitespace
   character (not tab or space).
   Zero terminators are not printable (therefore false) */
int non_space_char(char c)
{
  if ((c != '\t' && c != ' ') && c != 0) {
    return 1;
  }
  return 0;
}

/* Returns a pointer to the first character of the nexr
   space-seperated word in zero-terminated str. Return a zero pointer if
   str does not contain any words. */
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

/* Returns a pointer terminator char following *word */
char *word_terminator(char *word)
{
  while (non_space_char(*word)) {
    word++;
  }
  return word;
}

/* Counts the number of words in the string argument. */
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

/* Returns a freshly allocated new zero-terminated string
   containing <len> chars from <inStr> */
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

/* Returns a freshly allocated zero-terminated vector of freshly allocated
   space-serated tokens from zero-terminated str. */
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

/* Prints all tokens. */
void print_tokens(char **tokens)
{
  for (int i = 0; tokens[i] != 0; i++) {
    printf("%s\n", tokens[i]);
  }
}

/* Frees all otkens and the vector containing them. */
void free_tokens(char **tokens)
{
  for (int i = 0; tokens[i] != 0; i++) {
    free(tokens[i]);
  }
  free(tokens);
}
