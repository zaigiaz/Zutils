#ifndef NEW_STRLIB_H
#define NEW_STRLIB_H

#include <string.h>
#include <stdbool.h>
#include "types.h"

#define MAX_SIZE 256

// TODO :: fix this or think about semantics of views/slicing later
typedef struct {
  u8 * data;
  usize len;
} str_view;

// static buffer of medium size for path or basic string manipulation tasks
typedef struct {
  u8 data[MAX_SIZE+1];
  usize len;
  usize capacity;
} strbuf;

void strbuf_init(strbuf * buf) {
  buf.len = 0;
  buf.capacity = MAX_SIZE;
  buf.data[0] = '\0';
}

void strbuf_clear(strbuf * buf) {
  memset(buf->data, 0, MAX_SIZE);
}

bool strbuf_append(strbuf * buf, char * txt) {
  usize n = strlen(txt);
  
  if(n > (buf->capacity - buf->len)) {
    return false;
  }

  memcpy(buf->data + buf->len, txt, n+1);
  buf.len += n;
  return true;
}



#endif



