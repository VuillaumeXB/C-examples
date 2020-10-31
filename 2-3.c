//Exercice 2-3 from K&R. It generates random hex and converts them into decimal

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void random_hex_generator(int, int);
int htoi(int);

char** hexa_nbr;

int main(int argc, char** argv)
{
  extern char** hexa_nbr;
  int n;
  //puts("Enter the numbers to generate");
  //scanf("%d\n", &n);
  n = 8;
  hexa_nbr = (char**)calloc(n, sizeof(char));
  if(hexa_nbr == NULL) {
    perror("Error in memory allocation\n");
    exit(EXIT_FAILURE);
  }
  for(int i = 0; i < n; ++i){
    random_hex_generator(i, rand() % 6);
    printf("Hex: %s ===> ", hexa_nbr[i]);
    printf("Dec: %ul\n", htoi(i));
  }
  return EXIT_SUCCESS;
}

void random_hex_generator(int p, int len)
{
  extern char** hexa_nbr;
  static const char digits[] = "0123456789abcdefABCDEF"; 
  hexa_nbr[p] = (char*)calloc(len, sizeof(char));
  if(hexa_nbr[p] == NULL){
    perror("Error in memory allocation\n");
    exit(EXIT_FAILURE);
  }
  for(int i = 0; i < len; ++i){
    hexa_nbr[p][i] = digits[rand() % (strlen(digits))];
  }
  hexa_nbr[p][len] = '\0';
}

int htoi(int p)
{
  extern char** hexa_nbr;
  int hex = 0;
  int h;
  for(int i = 0; (hexa_nbr[p][i] >= '0' && hexa_nbr[p][i] <= '9')||(hexa_nbr[p][i] >= 'A' && hexa_nbr[p][i] <= 'F')||(hexa_nbr[p][i] >= 'a' && hexa_nbr[p][i] <= 'f'); ++i){
    if(hexa_nbr[p][i] == 'a'||hexa_nbr[p][i] == 'A'){
      h = 0xa;
      hex = 16 * hex + h;
    } else if(hexa_nbr[p][i] == 'b'||hexa_nbr[p][i] == 'B'){
      h = 0xb;
      hex = 16 * hex + h;
    } else if(hexa_nbr[p][i] == 'c'||hexa_nbr[p][i] == 'C'){
      h = 0xc;
      hex = 16 * hex + h;
    } else if(hexa_nbr[p][i] == 'd'||hexa_nbr[p][i] == 'D'){
      h = 0xd;
      hex = 16 * hex + h;
    } else if(hexa_nbr[p][i] == 'e'||hexa_nbr[p][i] == 'E'){
      h = 0xe;
      hex = 16 * hex + h;
    } else if(hexa_nbr[p][i] == 'f'||hexa_nbr[p][i] == 'F'){
      h = 0xf;
      hex = 16 * hex + h;
    } else {
      hex = 16 * hex + (hexa_nbr[p][i] - '0');
    }
  }
  return hex;
}
