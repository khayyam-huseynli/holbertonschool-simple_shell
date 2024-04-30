#include <stdio.h>
#include <stdlib.h>

void print_environment(void) {
    extern char **environ;
    for (char **env = environ; *env != NULL; env++) {
        printf("%s\n", *env);
    }
}
