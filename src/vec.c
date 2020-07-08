#include "vec/vec.h"

#include <stdlib.h>
#include <string.h>

struct vec vec_new(size_t num_elements, size_t el_size) {
  struct vec v;
  v.size = 0;
  v.buf = calloc(num_elements, el_size);
  v.el_size = el_size;

  return v;
}

int vec_push(struct vec* v, const void* el) {
  char* ptr = ((char*)v->buf) + v->el_size * v->size;
  memcpy(ptr, el, v->el_size);
  v->size++;
  return 0;
}

int vec_pop(struct vec* v) {
  v->size--;
  char* ptr = ((char*)v->buf) + v->el_size * v->size;
  memset(ptr, 0, v->el_size);
  return 0;
}