//Program to display the arguments sent through the command line

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int isize = sizeof(int);
    int i = 1;
    int *ip = &i;

    int csize = sizeof(char);
    char c = 'a';
    char *cp = &c;

    int vsize = sizeof(void);
    //void v = ;
    void *vp;

    int sip = sizeof(ip);
    int scp = sizeof(cp);
    int svp = sizeof(vp);


    printf("The number of arguments is %d\n", argc);
    for(int i = 0; i < argc; ++i) {
        printf("Argument %d %s\n", i+1, argv[i]);
    }
    return EXIT_SUCCESS;    
}