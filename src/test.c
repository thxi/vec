#include "test.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "vec/vec.h"

void pint(void* v) {
  printf("%d ", *(int*)v);
  return;
}

void test_vec_int() {
  printf("Test vec int:\n");
  struct vec v = vec_new(10, sizeof(int));
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
  printf("at(2): %d\n", *(int*)vec_at(v, 3));
  printf("front: %d\n", *(int*)vec_front(v));
  printf("back: %d\n", *(int*)vec_back(v));

  vec_free(v);
}

void pchar(void* v) {
  printf("%c ", *(char*)v);
  return;
}

void test_vec_char() {
  printf("Test vec char:\n");
  char a = 'a';
  struct vec my_vec = vec_new(10, sizeof(a));

  v_push(my_vec, a);
  a = 'b';
  v_push(my_vec, a);
  a = 'c';
  v_push(my_vec, a);

  printf("%s\n", (char*)my_vec.buf);
  vec_pop(&my_vec);
  printf("%s\n", (char*)my_vec.buf);

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