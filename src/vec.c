#include "vec/vec.h"

#include <stdlib.h>
#include <string.h>

bool _vec_reserve(size_t* cap, void** buf, size_t val_size, size_t new_cap) {
  if (*cap >= new_cap) {
    return true;
  }
  void* new_ptr = realloc(*buf, new_cap * val_size);
  if (new_ptr == NULL) {
    return false;
  }
  *buf = new_ptr;
  *cap = new_cap;
  return true;
}

bool _vec_extend(size_t* size, size_t* cap, void** buf, size_t val_size) {
  if (*cap == 0) {
    bool s = _vec_reserve(cap, buf, val_size, 2);
    if (!s) {
      return false;
    }
  }
  if (*cap == *size) {
    bool s = _vec_reserve(cap, buf, val_size, (*cap) * 2);
    if (!s) {
      return false;
    }
  }
  return true;
}

bool _vec_resize(size_t* size, size_t* cap, void** buf, size_t val_size,
                 size_t count) {
  if (count == 0) {
    free(*buf);
    *buf = NULL;
    *cap = 0;
    *size = 0;
  }
  if (count == *size) {
    return true;
  }
  if (count > *size) {
    bool s = _vec_reserve(cap, buf, val_size, count);
    if (!s) {
      // could not allocate more memory
      return false;
    }
    char* ptr = ((char*)*buf) + val_size * (*size);
    memset(ptr, 0, val_size * (count - (*size)));
    *size = count;
    return true;
  }

  void* new_ptr = realloc(*buf, count * val_size);
  if (new_ptr == NULL) {
    return false;
  }
  *buf = new_ptr;
  *size = count;
  *cap = count;
  return true;
}