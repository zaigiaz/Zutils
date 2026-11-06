#include <stdio.h>
#include "lexopt.h"

int main(int argc, char *argv[]) {

  const char *usage = "[-f file] [-b true|false] ...";

  for (char opt = argv_opt(argv); opt; opt = argv_opt(NULL)) {
    switch (opt) {
    case 'f': {
      char *file = argv_val();
      if (file == NULL) argv_err(usage, opt, "requires a file");
      printf("\n-got f: %s", file);
      break;
    }
    case 'b': {
      char *value = argv_val();
      if (value == NULL) argv_err(usage, opt, "requires true or false");
      printf("\n-got b: %s", value);
      break;
    }
    default:
      argv_err(usage, opt, "not working");
    }
  }

  printf("\nfinished");

}

