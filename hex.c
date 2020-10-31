//This pgm creates as random dec numbers as input by user and converts them into hex

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int n;
  int *hex;
  puts("Number of samples:");
  scanf("%d\n", &n);

  hex = (int*)calloc(n, sizeof(int));
  if(hex == NULL) {
    perror("Error in memory allocation\n");
    exit(EXIT_FAILURE);
  }
  
  for(int i = 0; i < n; ++i){
    hex[i] = rand();
    printf("Random %d dec number: %d", i, hex[i]);
    printf("---> to hex: %x\n", hex[i]);
  }
  return EXIT_SUCCESS;
} 
