#include <stdio.h>
#include "dyn_array/array.h"

int main(void) {

  Array items;

  reserve(&items, 20);

  init(&items);
  
  printf("%zu", items.capacity);
  
  /* for(int i=0; i<50; i++) */
  /*   add(&items, i); */

  /* int new_elem = 66666; */
  /* insert(&items, new_elem, 20); */
  
  /* arr_print(&items); */

  freeArray(&items);
}
