#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_CMD_LEN 256

int execute_cmd(char *cmd);
int process_line(char *line);
char *get_file_loc(char *path, char *file_name);
int slash_checker(const char *str);
char *get_file_path(char *file_name);
void print_environment(char * envp[]);

#endif
