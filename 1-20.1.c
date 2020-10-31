//Exercice 1-20 from K&R book

#include <stdio.h>
#define TABSIZE 8
#define MAXLINE 2048
#define TRUE 1
#define FALSE 0

char line[MAXLINE];
char tabLine[MAXLINE];
char ntabLine[MAXLINE];
int getLine(void);

int main() 
{
  int len, i, j, k, l, n;
	extern char tabLine[];
  extern char ntabLine[];

  printf("Tab size %d\n", TABSIZE);

  len = 0;
  while ((len = getLine()) > 0) {
    for (i = 0, j = 0; i <= len; ++i, ++j) {
      if (line[i] != '\t') {
        tabLine[j] = line[i];
        putchar(tabLine[j]);
      }
      else {
        for (k = j, l = 0; l < TABSIZE; ++l) {
          tabLine[k+l] = '.'; //this marks a std tab size
          putchar(tabLine[k+l]);
        }
        j += l -1;
      }
    }
    i = 0;
    j = 0;
    n = 0;
    while (tabLine[i] != '\0') {
      if (tabLine[i] !=   '.') {
        ntabLine[j] = tabLine[i];
        putchar(ntabLine[j]);
        ++n;
        if (n == TABSIZE)
          n = 0;
      }
      else {
        for (k = j, l = 0; l < (TABSIZE - n); ++l) {
          ntabLine[k+l] = '_'; //this marks the blanks in the stout
          putchar(ntabLine[k+l]);
        }
        j += l -1;
        n = 0;
        while (tabLine[i] == '.')
          ++i;
        i = i - 1;
      }
      ++i;
      ++j;
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
