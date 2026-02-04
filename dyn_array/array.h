#ifndef ARRAY_H
#define ARRAY_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct {
  int *array;
  size_t capacity;
  size_t count;
} Array;


void arr_print(Array *a) {  
  for(size_t i=0; i < a->count; i++) {
    printf("%d\n", a->array[i]);
  }
}

void init(Array *a) {
  a->count = 0;

  if(a->capacity == 0)
    a->capacity = 256;

  a->array = malloc(a->capacity * sizeof(int));
}

void reserve(Array *a, size_t reserved) {
  a->capacity = reserved;
}

void add(Array *a, int element) {
  
  // if size == capacity realloc by 2
  if(a->count == a->capacity) {
    a->capacity *= 2;
    a->array = realloc(a->array, a->capacity * sizeof(int));
  }
  
  a->array[a->count++] = element;
}

// insert at given index
void insert(Array *a, int element, size_t index) {
  assert(index < a->count);
  a->array[index] = element;
}

void delete(Array *a, size_t index) {

  assert(index <= a->count);
 
  // shift the rest to the left from index
  for(index; index < a->count-1; index++) {
    a->array[index] = a->array[index+1];      
  }
  
  // delete last element in array 
  a->count -= 1;
}


int pop_back(Array *a) {  
  assert(a->count > 0);
  a->count -= 1;
  int result = a->array[a->count];
  return result;
}


int comp_asc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int comp_desc(const void *a, const void *b) {
    return (*(int *)a + *(int *)b);
}

void sort(Array *a) {
  qsort(a->array, a->count, sizeof(int), comp_asc);  
}


void freeArray(Array *a) {
  free(a->array);
  a->array = NULL;
  a->count = a->capacity = 0;
}


#endif
