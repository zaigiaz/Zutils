#ifndef CSV_PARSER
#define CSV_PARSER

#include "strbuf.h"

void csv_rdr_init();
f32 csv_return_from_float();
i32 csv_return_from_int();
char *csv_return_from_str();

// csv_reader assumes that there is no csv_header according the RFC rules
// if there is then just be aware that we will return a line of strings or potentially malformed data otherwise for now

// implement basic dsl_reader so that we can have the schema enforced on api call like in jannson with "s:f:s:i"
// that expands out into schema [string, float, string, integer, newline] 

// delimiter is anything of our choosing, so we could read .dat files as well

// TODO :: if schema breaks then return null or?

// 8 KB init-size
#define MAX_SIZE 8*1024

typedef enum : u8 {
  STRING,
  FLOAT,
  INTEGER,
  COMMA,
  NEWLINE
} csv_type;

// slices into strbuf
typedef struct {
  u16 base[MAX_SIZE];
  u16 offset[MAX_SIZE];
  csv_type type_tok[MAX_SIZE];
  char delim;
} csv_rdr;

typedef struct {
  u8 dsl_string[32];
  // more stuff here
} dsl_rdr;

bool is_delim(char c) {
  switch(c) {
  case ',':
  case '\n':
  case '\r':
    return true;
  }
  return false;
}

f32 csv_return_from_float() {
  return 1.0;
}

i32 csv_return_from_int() {
  return 1;
}

// have function to memcpy from 
char *csv_return_from_str() {
  return "";
}


#endif

