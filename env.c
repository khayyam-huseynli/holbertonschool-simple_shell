#include <stdio.h>
#include <stdlib.h>

void print_environment(char * envp[])
{
    int i;
 
    for (i = 0; envp[i] != NULL; i++)
    {    
        printf("\n%s", envp[i]);
    }
}
