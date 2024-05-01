#include "main.h"


char *_getenv(const char *name)
{
    int i = 0;
    int len = strlen(name);

    while (environ[i])
    {
        if (strncmp(name, environ[i], len) == 0 && environ[i][len] == '=')
        {
            return &environ[i][len + 1];
        }
        i++;
    }
    return NULL;
}

