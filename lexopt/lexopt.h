#ifndef LEXOPT_H
#define LEXOPT_H

#include <stdlib.h>
#include <stdio.h>

// Liscensed under MIT

// Code from this blogpost
// https://dotat.at/@/2024-11-06-getopt.html
// all rights to respective owners

static char **vec;
static int arg, pos;

char argv_opt(char *argv[]) {
  if(argv != NULL) {
    vec = argv;
    arg = vec[0] ? 1 : 0;
    pos = 0;
  }

  if(pos > 0 && vec[arg][pos + 1] == '\0') {
    arg++;
    pos = 0;
  }

  if(pos < 0 || vec[arg] == NULL ||
     vec[arg][0] != '-' || vec[arg][1] == '\0') {
    pos = -1;
    return('\0');
  }

  if(vec[arg][1] == '-' && vec[arg][2] == '\0') {
    arg++;
    pos = -1;
    return('\0');
  }

  return(vec[arg][++pos]);
}

char *argv_optval(void) {
  char *val = &vec[arg][pos + 1];
  arg++;
  pos = 0;
  return(val);
}

char *argv_val(void) {
  char *val = (pos > 0) ? argv_optval() : "";
  return(val[0] ? val : vec[arg] ? vec[arg++] : NULL);
}

void argv_err(const char *usage, char opt, const char *err) {
  if(err) fprintf(stderr, "option '-%c' %s\n", opt, err);
  fprintf(err ? stderr : stdout, "usage: %s\n", usage);
  exit(err ? 1 : 0);
}

#endif
