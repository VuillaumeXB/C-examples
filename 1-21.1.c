//Exercice 1-21 from K&R book

#include <stdio.h>
#define TABSIZE 8
#define MAXLINE 2048
#define TRUE 1
#define FALSE 0

char line[MAXLINE];
char blankTabLine[MAXLINE];
int getLine(void);

int main() 
{
  int len, i, j, k, l, n, n1;
  extern char blankTabLine[];

  printf("Tab size %d\n", TABSIZE);

  len = 0;
  while ((len = getLine()) > 0) {
    for (i = 0; i <= len; ++i) {
      if (line[i] != ' ')
        putchar(line[i]);
      else {
        line[i] = '.';
        putchar(line[i]);
      }
    }
    for (i = 0, k = 0; i <= len; i += TABSIZE) {
      n = 0;
      for (j = 0; j < TABSIZE; ++j) {
        if (line[i+j] == '.')
          ++n;
        else if (line[i+j] == '\0')
          break;
      }
      if (n == TABSIZE) {
        blankTabLine[k] = '\t';
        putchar(blankTabLine[k]);
        ++k;
      }
      else {
        for (j = 0; j < TABSIZE; ++j) {
          if (line[i+j] == '.') {
            blankTabLine[k+j] = '_';
            putchar(blankTabLine[k+j]);
          }
          else if (line[i+j] == '\0') {
            blankTabLine[k+j] = '\0';
            putchar(blankTabLine[k+j]);
            break;
          }
          else {
            blankTabLine[k+j] = line[i+j];
            putchar(blankTabLine[k+j]);
          }
        }
      }
    }
  }
  return 0;
}

int getLine(void)
{
  int c, i;
  extern char line[];

  for (i = 0; (c = getchar()) != EOF && c != '\n' && i < MAXLINE-1; i++)
    line[i] = c;
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}
