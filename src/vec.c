#include "vec/vec.h"

#include <stdlib.h>
#include <string.h>

struct vec vec_new(size_t el_size) {
  struct vec v;
  v.size = 0;
  v.cap = 0;
  v.buf = NULL;

  v.el_size = el_size;

  return v;
}

void vec_free(struct vec v) { free(v.buf); }

void* vec_at(struct vec v, size_t pos) {
  char* ptr = ((char*)v.buf) + v.el_size * pos;
  return ptr;
}

void* vec_front(struct vec v) { return vec_at(v, 0); }
void* vec_back(struct vec v) { return vec_at(v, v.size - 1); }

bool vec_empty(struct vec v) { return v.size == 0; }

size_t vec_size(struct vec v) { return v.size; }

size_t vec_cap(struct vec v) { return v.cap; }

bool vec_reserve(struct vec* v, size_t new_cap) {
  if (v->cap >= new_cap) {
    return true;
  }
  // printf("reserving %ld bytes\n", new_cap * v->el_size);
  void* new_ptr = realloc(v->buf, new_cap * v->el_size);
  if (new_ptr == NULL) {
    return false;
  }
  v->buf = new_ptr;
  v->cap = new_cap;
  return true;
}

void vec_shrink_to_fit(struct vec* v) { v->cap = v->size; }

int vec_push(struct vec* v, const void* el) {
  if (v->cap == 0) {
    vec_reserve(v, 2);
  }
  if (v->cap == v->size) {
    vec_reserve(v, v->cap * 2);
  }
  char* ptr = ((char*)v->buf) + v->el_size * v->size;
  memcpy(ptr, el, v->el_size);
  v->size++;
  return 0;
}

int vec_pop(struct vec* v) {
  v->size--;
  // char* ptr = ((char*)v->buf) + v->el_size * v->size;
  // memset(ptr, 0, v->el_size);
  return 0;
}
