#pragma once

#include <stdio.h>

struct vec {
  int size;
  void* buf;

  size_t el_size;
};

// creates a new vec
struct vec vec_new(size_t num_elements, size_t el_size);
void vec_free(struct vec v);

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
// int forEach(struct vec* v, void* f);