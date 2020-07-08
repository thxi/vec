#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test.h"
#include "vec/vec.h"

int main() {
  char a = 'a';
  struct vec my_vec = vec_new(10, sizeof(a));

  vec_push(&my_vec, &a, sizeof(a));
  a = 'b';
  vec_push(&my_vec, &a, sizeof(a));
  a = 'd';
  vec_push(&my_vec, &a, sizeof(a));

  printf("%s\n", my_vec.buf);
  vec_pop(&my_vec, sizeof(a));
  printf("%s\n", my_vec.buf);

  struct vec int_vec = vec_new(10, sizeof(int));
  int d = 2147483646;
  vec_push(&int_vec, &d, sizeof(d));
  printf("%d\n", *(int*)int_vec.buf);

  return 0;
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