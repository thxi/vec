#include "vec/vec.h"

int keepo() {
  printf("hello from keepo\n");
  return 1;
}

int vec_push(struct vec vv) {
  vv.a = 3;
  return 0;
}