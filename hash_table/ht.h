#ifndef HT_H
#define HT_H

// implemented with help and inspiration from:
// https://github.com/benhoyt/ht/blob/master/ht.c

// TODO: finish the rest of these methods for Hash Tables
#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define INIT_COUNT 64

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME  1099511628211UL

typedef struct {
  char* key;
  int value;
} ht_entry;

typedef struct {
  ht_entry* entries;
  size_t capacity;
  size_t count; 
} ht;


uint64_t hash_key(const char* key) {
  uint64_t hash = FNV_OFFSET;
    for (const char* p = key; *p; p++) {
        hash ^= (uint64_t)(unsigned char)(*p);
        hash *= FNV_PRIME;
    }
    return hash;
}


void init_ht(ht *Table) {
  Table->count    = 0;
  Table->capacity = INIT_COUNT;
  Table->entries  = calloc(Table->capacity, sizeof(ht_entry));    
}


// TODO: finish this function
int get_ht(ht *Table, const char* key) {
  uint64_t hash = hash_key(key);
  size_t index  = (size_t)(hash & (uint64_t)(Table->capacity - 1));

  while((Table->entries[index].key) == NULL) {
    if(strcmp(key, Table->entries[index].key)) {     
      return Table->entries[index].value;
    }

    index++;

    if(index >= Table->capacity) {
      index = 0;
    }

  }

  perror("failed to get value from the hash_table | get_ht()");
  return 0;
}

// destroy and free table
void free_ht(ht *Table) {

  // free all the keys that were allocated 
  for(size_t i=0; i<Table->capacity; i++) {
    free((void*) Table->entries[i].key);    
  }
  
  // free everythihgn else after
  free(Table->entries);
  free(Table);
}


static const char* ht_set_entry(ht_entry* entries, size_t capacity, const char* key, 
				int value, size_t* plength) 
{
  uint64_t hash = hash_key(key);
  size_t index = (size_t)(hash & (uint64_t)(capacity-1));

  while(entries[index].key != NULL) { 
    if(strcmp(key, entries[index].key) == 0) {
      entries[index].value = value;
      return entries[index].key;
    }

    index++;
    if(index >= capacity) {
      index = 0;
    }

  }

  if(plength != NULL) {
    key = strdup(key);
    if(key == NULL) {
      return NULL;
    }
    (*plength)++;
  }
    
  entries[index].key   = key;
  entries[index].value = value;
  return key;
}

static bool expand_ht(ht *Table) {
  size_t new_capacity = 2 * Table->capacity;
  if(new_capacity < Table->capacity) {
    return false;
  }

  ht_entry* new_entries = calloc(new_capacity, sizeof(ht_entry));
  if(new_entries == NULL) {
    return false;
  }

  for(size_t i=0; i<Table->capacity; i++) {
    ht_entry entry = Table->entries[i];
    if(entry.key != NULL) {
      ht_set_entry(new_entries, new_capacity, entry.key, entry.value, NULL);
    }
  }

  free(Table->entries);
  Table->entries = new_entries;
  Table->capacity = new_capacity;
  return true;
}


const char* insert_ht(ht* table, const char* key, int value) {

    // If length will exceed half of current capacity, expand it.
    if (table->count >= table->capacity / 2) {
        if (!expand_ht(table)) {
            return NULL;
        }
    }

    // Set entry and update length.
    return ht_set_entry(table->entries, table->capacity, key, value,
                        &table->count);
}


#endif

