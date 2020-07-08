#pragma once

#include <stdio.h>

int keepo();

struct vec {
  int a;
  void* buf;
};

int vec_push(struct vec vv);