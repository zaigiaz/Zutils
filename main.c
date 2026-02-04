#include <stdio.h>
#include "dyn_array/array.h"
#include "hash_table/ht.h"

int main(void) {

  // create the dyn_array and hash_table data structures
  Array items;
  ht Table;


  // init and insert value into hash_table
  int x = 5;
  init_ht(&Table);
  insert_ht(&Table, "Hi", x);
 
  // reserve items
  reserve(&items, 70);

  // init array
  init(&items);
  
  for(int i=0; i<50; i++)
    add(&items, i*i);

  // insert element at index
  insert(&items, (int)600, 3);
  
  delete(&items, 3);

  // sort items
  sort(&items);
  
  // print all items in newline order
  arr_print(&items);

  // pop the last item from end of array
  int item = pop_back(&items);

  // free the memory from the array
  freeArray(&items);
}
