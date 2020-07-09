#include "test.h"

#include <assert.h>
#include <stdio.h>

#include "vec/vec.h"

#define deb(msg, v) printf("%s: size: %ld cap: %ld\n", msg, v.size, v.cap)

void test_vec_macro() {
  vec_type(int) v = vec_new();
  assert(v.size == 0);

  for (int i = 0; i < 10; i++) {
    bool ret = vec_push(v, i + 1);
    assert(ret == true);
    // deb("push", v);
  }
  for_each(v) { printf("%d ", v.buf[i]); }
  printf("\n");

  assert(v.size == 10);
  assert(v.cap == 16);
  for (int i = 0; i < 5; i++) {
    vec_pop(v);
  }
  assert(v.size == 5);

  assert(vec_at(v, 1) == 2);
  assert(vec_front(v) == 1);
  assert(vec_back(v) == 5);

  assert(vec_empty(v) == false);
  vec_shrink_to_fit(v);
  assert(v.cap == 5);
  for (int i = 0; i < 5; i++) {
    vec_pop(v);
  }
  assert(vec_empty(v) == true);

  assert(vec_resize(v, 0) == true);
  deb("resize 0", v);
  assert(v.size == 0);
  assert(v.cap == 0);

  assert(vec_reserve(v, 14) == true);
  deb("reserve 14", v);
  assert(v.size == 0);
  assert(v.cap == 14);

  assert(vec_resize(v, 7) == true);
  deb("resize 7", v);
  assert(v.size == 7);
  assert(v.cap == 14);

  for_each(v) { assert(v.buf[i] == 0); };

  vec_free(v);
}