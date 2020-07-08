#pragma once

#include <stdio.h>

struct vec {
  int size;
  void* buf;

  size_t el_size;
};

// creates a new vec
struct vec vec_new(size_t num_elements, size_t el_size);

int vec_push(struct vec* v, const void* el);
int vec_pop(struct vec* v);