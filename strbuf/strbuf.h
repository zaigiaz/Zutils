#ifndef NEW_STRLIB_H
#define NEW_STRLIB_H

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../types.h"

#define MAX_SIZE 256

// TODO :: some type of strtok() like function that uses the strview
// TOOD :: reverse the string-buffer with two-pointers (for-fun?)

// static buffer of medium size for path or basic string manipulation tasks
typedef struct {
  u8 data[MAX_SIZE+1];
  size_t len;
  size_t capacity;
} strbuf;

// pointer into the string buffer with a length
typedef struct {
  const u8 * data;
  size_t len;
} strview;

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
// NOTE :: for now there is no safety with this function, will need to change in the future
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

// get slice of data from the buffer
strview strbuf_slice(const strbuf *s, size_t start, size_t end) {

  // invalid range
  if (start > s->len || end > s->len - start) {
    return (strview){ .data = NULL, .len = 0 };
  }

  return (strview){ .data = s->data + start, .len = end };
}

#endif
