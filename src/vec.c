#include "vec/vec.h"

#include <stdlib.h>
#include <string.h>

struct vec vec_new(size_t num_elements, size_t el_size) {
  struct vec v;
  v.size = 0;
  v.buf = calloc(num_elements, el_size);

  return v;
}

int vec_push(struct vec* v, const void* el, size_t el_size) {
  char* ptr = ((char*)v->buf) + el_size * v->size;
  memcpy(ptr, el, el_size);
  v->size++;
  return 0;
}

int vec_pop(struct vec* v, size_t el_size) {
  v->size--;
  char* ptr = ((char*)v->buf) + el_size * v->size;
  memset(ptr, 0, el_size);
  return 0;
}