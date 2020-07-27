#include <iostream>
#include "sortfunctions.h"

int main(int, char**) {
  int aa[] = {1, 3, 45, 10, 34, 30, 4, 8, 33};
  sort_bubble(aa, sizeof(aa) / sizeof(aa[0]));
  std::cout << "Hello, world!\n";
}
