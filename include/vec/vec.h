#pragma once

#include <stdbool.h>
#include <stdlib.h>

#define vec_type(type) \
  struct vec {         \
    size_t size;       \
    size_t cap;        \
    type* buf;         \
  }

// Creates a new vec
#define vec_new() \
  { 0, 0, NULL }

// Frees the memory owned by vec
#define vec_free(v) free(v.buf)

// Push value to the end of the vector
// Allocates memory if size == capacity
// Returns true on success
// Returns false if allocation fails
#define vec_push(v, val)                                      \
  _vec_extend(&v.size, &v.cap, (void*)&v.buf, sizeof(*v.buf)) \
      ? (v.buf[v.size] = val, v.size++, true)                 \
      : false;

// Removes the last value in the array
#define vec_pop(v) v.size--

// Returns the element at position pos.
// Use 0 based indexing
#define vec_at(v, pos) v.buf[pos]

// Returns the first element
#define vec_front(v) v.buf[0]

// Returns the last element
#define vec_back(v) v.buf[v.size - 1]

// Returns true if the vector is empty.
#define vec_empty(v) (v.size == 0)

// Requests the removal of unused capacity
#define vec_shrink_to_fit(v) v.cap = v.size

// Increase the capacity of the vector to a value that's greater or equal to
// new_cap. If new_cap is greater than the current vec_cap(), new storage
// is allocated, otherwise the function does nothing.
// Returns true on success
// Returns false if allocation fails
#define vec_reserve(v, new_cap) \
  _vec_reserve(&v.cap, (void*)&v.buf, sizeof(*v.buf), new_cap)

// Resizes the container to contain count elements.
// If the current size is greater than count, the vector is reduced to its first
// count elements.
// If the current size is less than count, new memory is allocated and set to 0
// Returns true on success
// Returns false on memory allocation error
#define vec_resize(v, count) \
  _vec_resize(&v.size, &v.cap, (void*)&v.buf, sizeof(*v.buf), count)

#define for_each(v) for (size_t i = 0; i < v.size; i++)

// low-level functions

bool _vec_reserve(size_t* cap, void** buf, size_t val_size, size_t new_cap);

// Returns true on success
bool _vec_extend(size_t* size, size_t* cap, void** buf, size_t val_size);

// Returns true on success
bool _vec_resize(size_t* size, size_t* cap, void** buf, size_t val_size,
                 size_t count);