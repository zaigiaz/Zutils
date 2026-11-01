#ifndef NEW_STRLIB_H
#define NEW_STRLIB_H

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"

#define MAX_SIZE 256

// TODO :: fix this or think about semantics of views/slicing later
typedef struct {
  u8 * data;
  size_t len;
} str_view;

// static buffer of medium size for path or basic string manipulation tasks
typedef struct {
  u8 data[MAX_SIZE+1];
  size_t len;
  size_t capacity;
} strbuf;

void strbuf_init(strbuf * buf) {
  buf->len = 0;
  buf->capacity = MAX_SIZE;
  buf->data[0] = '\0';
}

void strbuf_clear(strbuf * buf) {
  buf->data[0] = '\0';
  buf->len = 0;
}

void strbuf_append(strbuf * buf, const char *txt) {

  if(buf->len > buf->capacity) {
    fprintf(stderr, "len is greater than the capacity");
    exit(1);
  }
  
  size_t n = strlen(txt);
  if(n > (buf->capacity - buf->len)) {
    printf("\nsize is greater than the amount that is left in the strbuffer");
    exit(1);
  }

  memcpy(buf->data + buf->len, txt, n+1);
  buf->len += n;
}

// pop amount of top of buffer
void strbuf_pop_right(strbuf* buf, size_t amt) {

  if(amt > buf->len) {
    fprintf(stderr, "cant pop more than the entire buffer");
    exit(1);
  }

  buf->len -= (amt-1);
  buf->data[buf->len] = '\0';
}

// pop the last dir/file in path and go up directory
void strbuf_pop_dir(strbuf* buf) {
  if(buf->len == 0) {
    fprintf(stderr, "buffer is empty");
  }

  for(size_t i=buf->len; i>0; i--) {
    if(buf->data[i] == '/') {
      strbuf_pop_right(buf, buf->len - (i-1));
      return;
    }
  }
  
  fprintf(stderr, "\ncould not find directory delimiter, no work done");
}


#endif
