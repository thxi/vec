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
mkdir external && cd external && git submodule add git@github.com:thxi/vec.git

- Make a CMakeLists.txt in external directory
echo "add_subdirectory(vec)" > CmakeLists.txt

- add the following lines to your main CMakeLists (which resides in the project root)
add_subdirectory(vec) 
target_link_libraries(${YOUR_TARGET} vec) # do not forget to set the target

- now you can use the lib


USE

After installing as described above:

#include "vec/vec.h"
int main() {
  struct vec v =
      vec_new(sizeof(int));  // size of the element type should be specified
  int d = 1337;
  vec_push(&v, &d);
  printf("First element: %d\n", vec_at(v, 0));
}

TODO:
[X] implement core methods as in https://en.cppreference.com/w/cpp/container/vector
[X] add sanitizer to test binary
[~] add tests
[X] add install