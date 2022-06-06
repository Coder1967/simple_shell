#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
char **str_to_argv(char *s);
int count_argv(char *s);
int exec(char **argv);
#endif
