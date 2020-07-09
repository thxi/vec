#pragma once

#include <stdbool.h>
#include <stdio.h>

struct vec {
  int size;
  void* buf;

  size_t el_size;
};

// creates a new vec
struct vec vec_new(size_t num_elements, size_t el_size);
void vec_free(struct vec v);

/* Element access */

// Returns the element at position pos.
// Vector index is 0 based.
void* vec_at(struct vec v, size_t pos);

// Returns the first element
void* vec_front(struct vec v);
// Returns the last element
void* vec_back(struct vec v);

#define v_push(v, el) vec_push(&v, &el);
int vec_push(struct vec* v, const void* el);
int vec_pop(struct vec* v);

#define forEach(v, f)                  \
  {                                    \
    char* ptr = ((char*)v.buf);        \
    for (int i = 0; i < v.size; i++) { \
      f(ptr);                          \
      ptr += v.el_size;                \
    }                                  \
  }
