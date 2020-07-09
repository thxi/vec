#pragma once

#include <stdbool.h>
#include <stdio.h>

struct vec {
  size_t size;
  size_t cap;
  void* buf;

  size_t el_size;
};

// creates a new vec
struct vec vec_new(size_t el_size);
void vec_free(struct vec v);

/* Element access */

// Returns the element at position pos.
// Vector index is 0 based.
void* vec_at(struct vec v, size_t pos);

// Returns the first element
void* vec_front(struct vec v);
// Returns the last element
void* vec_back(struct vec v);

/* Capacity */

bool vec_empty(struct vec v);
size_t vec_size(struct vec v);
size_t vec_cap(struct vec v);
// Increase the capacity of the vector to a value that's greater or equal to
// new_cap. If new_cap is greater than the current vec_cap(), new storage
// is allocated, otherwise the function does nothing.
// Returns true on success
// Returns false if allocation fails
bool vec_reserve(struct vec* v, size_t new_cap);
// Requests the removal of unused capacity
// equivalent to realloc(v.buf, v.size * v.el_size)
void vec_shrink_to_fit(struct vec* v);

/* Modifiers */

// Erases all elements from the vector. Sets the size to 0
// Sets the memory that the buffer points to to 0
// Leaves the capacity unchanged
void vec_clear(struct vec* v);

// Inserts value before pos
// Returns pointer to the inserted value
void* vec_insert(struct vec* v, size_t pos, const void* value);

#define v_push(v, el) vec_push(&v, &el);
// TODO handle error when shrinking
int vec_push(struct vec* v, const void* value);
int vec_pop(struct vec* v);
// Resizes the container to contain count elements.If the current size is
// greater than count, the vector is reduced to its first count elements.
// If the current size is less than count, new memory is allocated and set to 0
// Returns true on success
// Returns false on memory allocation error
bool vec_resize(struct vec* v, size_t count);

/* Helpers */

// TODO helper to nth byte in buffer

#define forEach(v, f)                     \
  {                                       \
    char* ptr = ((char*)v.buf);           \
    for (size_t i = 0; i < v.size; i++) { \
      f(ptr);                             \
      ptr += v.el_size;                   \
    }                                     \
  }
