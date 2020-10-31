//Exercice 1-16 from K&R book

#include <stdio.h>
#define MAXLENGTH 1000
#define TRUE 1
#define FALSE 0

int getLine(char line[], int maxlength);
void copyLine(char from[], char to[]);

int main()
{
  int i, c, words, newword, len, max;
  char line[MAXLENGTH];
  char maxline[MAXLENGTH];

  max = 0;
  while ((len = getLine(line, MAXLENGTH)) > 0) {
    if (len > max) {
      max = len;
      copyLine(line, maxline);
    }
    i = 0;
    c = 0;
    while (line[i] != '\0') {
      if (line[i] != '\n')
        ++c;
      ++i;
    }
    printf("%d char lenght\n", c);
    i = 0;
    words = 0;
    newword = FALSE;
    while (line[i] != '\0') {
      if (line[i] != '\n' && line[i] != '\t' && line [i] != ' ' && newword == FALSE) {
        ++words;
        newword = TRUE;
      }
      else if (newword == TRUE && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'))
        newword = FALSE;
      ++i;
    }
    printf("%d words lenght\n", words);
  }
  if (max > 0)
    printf("%s\n", maxline);  
}

int getLine(char line[], int maxlength) {
  int i, c;

  for (i = 0; i < maxlength - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

void copyLine(char from[], char to[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}  
