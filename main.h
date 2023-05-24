#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define LINESIZE 1024


void execmd(char **argv);
char *get_location(char *command);
char *_strcpy(char *dest, char *src);

extern char **environ;

#endif
