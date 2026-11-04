#include <stdio.h>
#include "strbuf.h"
#include "csv-parser.h"


int main() {

  const char* big_str = "some/path/here/again";
  const char* small_str = "/new/path";

  strbuf path;
  strbuf_init(&path);

  strbuf_append(&path, "home/");
  printf("%s\n", path.data);

  strbuf_append(&path, big_str);
  printf("\n%s and size %zu", path.data, path.len);

  strbuf_pop_right(&path, sizeof("/again"));
  printf("\n%s", path.data);
  
  strbuf_append(&path, small_str);
  printf("\n%s and %zu", path.data, path.len);

  strbuf_pop_dir(&path);
  printf("\n%s", path.data);

  strview s = strbuf_slice(&path, 4, 9);
  printf("\n%*s", s.len, s.data);
}
