#pragma once

#include <stdio.h>

struct vec {
  int size;
  // todo store element size here
  void* buf;
};

// creates a new vec
struct vec vec_new(size_t num_elements, size_t el_size);

int vec_push(struct vec* v, const void* el, size_t el_size);
int vec_pop(struct vec* v, size_t el_size);