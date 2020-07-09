#include "test.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "vec/vec.h"

void test_big_reserve() {}

void pint(void* v) {
  printf("%d ", *(int*)v);
  return;
}

void test_vec_int() {
  printf("\nTest vec int:\n");
  struct vec v = vec_new(sizeof(int));
  int d = 2147483646;
  v_push(v, d);
  d = 2147483645;
  v_push(v, d);
  d = 2147483644;
  v_push(v, d);
  d = 228;
  v_push(v, d);

  forEach(v, pint);
  printf("\n");
  printf("at(0): %d\n", *(int*)vec_at(v, 0));
  printf("at(2): %d\n", *(int*)vec_at(v, 2));
  printf("front: %d\n", *(int*)vec_front(v));
  printf("back: %d\n", *(int*)vec_back(v));
  printf("size %ld, cap: %ld\n", vec_size(v), vec_cap(v));

  vec_pop(&v);

  printf("After pop\n");
  forEach(v, pint);
  printf("\n");
  printf("at(0): %d\n", *(int*)vec_at(v, 0));
  printf("at(2): %d\n", *(int*)vec_at(v, 2));
  printf("front: %d\n", *(int*)vec_front(v));
  printf("back: %d\n", *(int*)vec_back(v));
  printf("size %ld, cap: %ld\n", vec_size(v), vec_cap(v));

  vec_free(v);
}

void test_vec_capacity() {
  printf("\nTest vec capacity:\n");
  struct vec v = vec_new(sizeof(int));
  printf("Initial size: %ld, cap: %ld, empty: %d\n", vec_size(v), vec_cap(v),
         vec_empty(v));
  vec_reserve(&v, 10);
  printf("After reserve: size: %ld, cap: %ld, empty: %d\n", vec_size(v),
         vec_cap(v), vec_empty(v));
  for (int i = 0; i < 400; i++) {
    vec_push(&v, &i);
  }
  printf("After push: size: %ld, cap: %ld, empty: %d\n", vec_size(v),
         vec_cap(v), vec_empty(v));
  forEach(v, pint);
  printf("\n");
  vec_shrink_to_fit(&v);
  printf("After shrink: size: %ld, cap: %ld, empty: %d\n", vec_size(v),
         vec_cap(v), vec_empty(v));

  vec_free(v);
}

void pchar(void* v) {
  printf("%c ", *(char*)v);
  return;
}

void test_vec_char() {
  printf("\nTest vec char:\n");
  char a = 'a';
  struct vec my_vec = vec_new(sizeof(a));
  vec_reserve(&my_vec, 10);

  v_push(my_vec, a);
  a = 'b';
  v_push(my_vec, a);
  a = 'c';
  v_push(my_vec, a);

  forEach(my_vec, pchar);
  printf("\n");
  vec_pop(&my_vec);

  printf("forEach: \n");
  forEach(my_vec, pchar);
  printf("\n");

  vec_free(my_vec);
}

void void_ptr_example() {
  printf("%ld\n", sizeof(char));
  printf("%ld\n", sizeof(int));
  void* buf = malloc(12);
  printf("%-10s %p\n", "first", buf);
  printf("%-10s %p\n", "", ((char*)buf));
  printf("%-10s %p\n", "char", ((char*)buf) + 1);
  printf("%-10s %p\n", "int", ((int*)buf) + 1);
  printf("%-10s %p\n", "int64", ((int64_t*)buf) + 1);
  printf("Char at 0: `%c`\n", ((char*)buf)[0]);
  printf("Char at 1: `%c`\n", ((char*)buf)[1]);
  strcpy(buf, "xd");
  printf("Char at 0: `%c`\n", ((char*)buf)[0]);
  printf("Char at 1: `%c`\n", ((char*)buf)[1]);
  memset(buf, '$', 7);
  printf("Char at 0: `%c`\n", ((char*)buf)[0]);
  printf("%s\n", ((char*)buf));  // unsafe

  free(buf);
}