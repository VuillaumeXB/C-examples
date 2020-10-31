//Exercice 1-23 from K&R. It removes all comments in any C/C++ source file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *file;
char *altered_file;
int size;
int altered_size;
FILE *fp;

void open_file(char *file_name);
int file_lenght(FILE *fp);
void mem_allocation(int size);
void read_file(FILE *fp);
void display_file(char *altered_file);
int comments_remover(char *file);
void write_file(char *file_name);

int main(int argc, char *argv[])
{
    extern int size;
    extern int altered_size;
    extern FILE *fp;
    extern char *file;
    open_file(argv[1]);
    size = file_lenght(fp);
    mem_allocation(size);
    read_file(fp);
    altered_size = comments_remover(file);
    // display_file(altered_file);
    write_file(argv[1]);
    fclose(fp);
    return EXIT_SUCCESS;
}

void open_file(char *file_name)
{
    extern FILE *fp;
    fp = fopen(file_name, "r");
    if(ferror(fp)){
        perror("Error opening file or file does not exist");
        exit (EXIT_FAILURE);
    }
}

int file_lenght(FILE *fp)
{
    char c;
    int i = 0;
    while(fgetc(fp) != EOF)
        ++i;   
    return i;
}

void mem_allocation(int size)
{
    extern char *file;
    extern char *altered_file;
    file = (char*)calloc(size, sizeof(char));
    if(file == NULL){
        perror("Error in memory allocation");
        exit (EXIT_FAILURE);
    }
    altered_file = (char*)calloc(size, sizeof(char));
    if(altered_file == NULL){
        perror("Error in memory allocation");
        exit (EXIT_FAILURE);
    }
}

void read_file(FILE *fp)
{
    extern char *file;
    extern int size;
    char c;
    int i = 0;
    rewind(fp);
    while(i < size){
        file[i] = fgetc(fp);
        ++i;
    }
    file[i] = '\0';
}

void display_file(char *altered_file)
{
    extern int altered_size;
    int i = 0;
    while(i <= altered_size){
        putchar(altered_file[i]);
        ++i;
    }
}

int comments_remover(char *file)
{
    extern char *altered_file;
    extern int size;
    int i = 0;
    int j = 0;
    while(i <= size){
        if((file[i] == '/') && ((file[i+1] == '/')
            || (file[i+1] == '*'))) {
            i += 2;
        }
        else if((file[i] == '*') && (file[i+1] == '/')) {
            i += 2;
        }
        else {
            altered_file[j] = file[i];
            ++i;
            ++j;
        }
    }
    altered_file[j] = '\0';
    return j;
}

void write_file(char *file_name)
{
    extern int altered_size;
    extern char *altered_file;
    int i = 0;
    int str_size;
    str_size = strlen(file_name);
    file_name[strlen(file_name) - 1] = '\0';  
    char *new_name = strcat(file_name, ".no_comment.C");
    fp = fopen(new_name, "w");
    if(ferror(fp)){
        perror("Error opening new file");
        exit (EXIT_FAILURE);
    }
    while(i <= altered_size){
        fputc(altered_file[i], fp);
        if(ferror(fp)){
            perror("Error while attempting to write in the new file");
            exit (EXIT_FAILURE);
        }
        ++i;
    }    
}
  
  
