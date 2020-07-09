vec

A simple vector implementation in C.
Interface (thoroughly documented) can be found in include/vec/vec.h
Core methods resemble the ones of https://en.cppreference.com/w/cpp/container/vector

I made this to see CMake and C in action.


INSTALL

To use the library I recommend you not to use find_package.
Instead use git submodules to checkout the repository and then add it to the project as a directory

For example,
suppose you have the following directory structure:
├── CMakeLists.txt
├── readme.txt
└── src
    └── main.c

- Checkout the repository as a submodule
mkdir external && cd external && git submodule add git@github.com:thxi/vec.git && cd ..

- Make a CMakeLists.txt in the external directory
echo "add_subdirectory(vec)" > external/CmakeLists.txt

- add the following lines to your main CMakeLists (which resides in the project root)
add_subdirectory(vec) 
target_link_libraries(${YOUR_TARGET} vec) # do not forget to set the target

- now you can use the lib


USE

After installing as described above:

#include <stdio.h>
#include "vec/vec.h"
int main() {
  vec_type(int) v = vec_new();
  for (int i = 0; i < 10; i++) {
    bool ret = vec_push(v, i + 1);
    if (ret != true) {
        return 1; // error allocating memory
    }
  }
  for_each(v) { printf("%d ", v.buf[i]); }
  printf("\n");
  for (int i = 0; i < 5; i++) {
    vec_pop(v);
  }
  vec_shrink_to_fit(v);
  assert(v.size == 5);
  assert(v.cap == 5);
  for (int i = 0; i < 5; i++) {
    vec_pop(v);
  }
  assert(vec_empty(v) == true);

  vec_free(v); // do not forget to free
}


TODO:

[X] implement core methods as in https://en.cppreference.com/w/cpp/container/vector
[X] add sanitizer to test binary
[X] add tests
[X] add install
[ ] add example to a different directory
[ ] structure tests